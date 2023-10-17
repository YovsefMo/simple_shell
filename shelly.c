#include "shelly.h"

/**
 * free_args - Free memory allocated for command arguments
 * @args: Array of command arguments
 *
 * This function frees memory allocated for command arguments.
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * main - Entry point for the program
 * @argc: The number of command-line arguments passed to the program.
 * @argv: An array of strings containing the actual command-line arguments.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i;

		for (i = 1; i < argc; i++)
		{
			execute_shelly_command(argv[i]);
		}
	}
	else
	{
		char *user_input;

		do
		{
			show_shelly_prompt();
			user_input = get_user_input();

			if (user_input != NULL)
			{
				if (strlen(user_input) == 0)
				{
					free(user_input);
					continue;
				}
				execute_shelly_command(user_input);
				free(user_input);
			}
			else
			{
				if (isatty(fileno(stdin)))
				{
					printf("\n");
				}
				exit(EXIT_SUCCESS);
			}
		} while (1);
	}
	return (0);
}
