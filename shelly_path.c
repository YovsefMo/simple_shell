#include "shelly.h"

/**
 * get_command_path - Get the full path to a command
 * @command: The command to search for
 *
 * Return: The full path of the command or NULL
 */
char *get_command_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy;
	char *token;
	char *command_path;

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		command_path = malloc(strlen(token) + strlen(command) + 2);
		if (command_path == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		sprintf(command_path, "%s/%s", token, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

