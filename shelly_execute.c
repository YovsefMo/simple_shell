#include "shelly.h"

/**
 * execute_builtin_command - Execute a built-in shell command
 * @command: The command to execute
 * @args: Array of command arguments
 *
 * This function executes built-in shell commands like "exit" and "env".
 */
void execute_builtin_command(char *command, char **args)
{
	if (strcmp(command, "exit") == 0)
	{
		int exstatus = 0;

		if (args[1] != NULL)
			exstatus = atoi(args[1]);

		free_shelly_args(args);
		exit(exstatus);
	}
	else if (strcmp(command, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		free_shelly_args(args);
	}
}

/**
 * execute_child_process - Execute a child process
 * @command_path: The path to the command to execute
 * @args: The arguments for the command
 *
 * This function handles the execution of a child process.
 */
void execute_child_process(char *command_path, char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free_shelly_args(args);
		return;
	}

	if (child_pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

/**
 * execute_external_helper - Execute an external shell command
 * @command: The command to execute
 * @args: The arguments for the command
 *
 * This helper function executes external shell commands.
 */
void execute_external_helper(char *command, char **args)
{
	char *original_path, *new_path, *command_path;

	original_path = getenv("PATH");
	new_path = malloc(strlen(original_path) + 3);

	if (new_path == NULL)
	{
		perror("malloc");
		free_shelly_args(args);
		return;
	}

	sprintf(new_path, ".:%s", original_path);
	setenv("PATH", new_path, 1);
	command_path = get_command_path(command);
	setenv("PATH", original_path, 1);
	free(new_path);

	if (command_path != NULL)
	{
		execute_child_process(command_path, args);
		free(command_path);
	}
	else
		printf("%s: command not found\n", command);
}

/**
 * execute_external_command - Execute an external shell command
 * @command: The command to execute
 * @args: The arguments for the command
 *
 * This function executes external shell commands.
 */
void execute_external_command(char *command, char **args)
{
	if (command[0] == '/')
	{
		execute_child_process(command, args);
	}
	else
	{
		execute_external_helper(command, args);
	}
}

/**
 * execute_shelly_command - Execute a shell command
 * @user_input: The user-provided input string
 *
 * This function executes a shell command based on user input.
 */
void execute_shelly_command(char *user_input)
{
	char **args;
	char *command;

	if (user_input == NULL)
	{
		return;
	}

	args = get_command_args(user_input);
	if (args == NULL)
	{
		return;
	}

	command = args[0];

	if (shelly_builtin(command))
	{
		execute_builtin_command(command, args);
	}
	else
	{
		execute_external_command(command, args);
	}

	free_shelly_args(args);
}
