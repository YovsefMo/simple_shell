#include "shelly.h"

/**
 * get_user_input - Read input from the user
 *
 * Return: A dynamically allocated user input string
 */
char *get_user_input(void)
{
	char *user_input = NULL;
	ssize_t bytes_read;
	size_t len = 0;

	bytes_read = getline(&user_input, &len, stdin);
	if (bytes_read == -1)
	{
		printf("Exiting shell....");
		free(user_input);
		return (NULL);
	}

	if (user_input[bytes_read - 1] == '\n')
	{
		user_input[bytes_read - 1] = '\0';
	}
	return (user_input);
}

/**
 * show_shelly_prompt - Display the shell prompt
 */
void show_shelly_prompt(void)
{
	if (isatty(fileno(stdin)))
	{
		printf("$ ");
		fflush(stdout);
	}
}
