#include "shelly.h"

/**
 * get_command_args - Split the user input into arguments
 * @user_input: The input string from the user
 *
 * Return: An array of arguments
 */
char **get_command_args(char *user_input)
{
	char **args = NULL;
	char *token;
	int arg_count = 0;

	token = strtok(user_input, " ");
	while (token != NULL)
	{
		args = realloc(args, (arg_count + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		args[arg_count] = strdup(token);
		if (args[arg_count] == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		arg_count++;
		token = strtok(NULL, " ");
	}
	args = realloc(args, (arg_count + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	args[arg_count] = NULL;
	return (args);
}

/**
 * shelly_builtin - Check if a command is a built-in command
 * @command: The command to check
 *
 * Return: 1 if built-in, 0 if not
 */
int shelly_builtin(char *command)
{
	if (command != NULL)
	{
		if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
		{
			return (1);
		}
	}
	return (0);
}
