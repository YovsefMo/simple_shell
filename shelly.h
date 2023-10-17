#ifndef SHELLY_H
#define SHELLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char **get_command_args(char *user_input);
int is_builtin(char *command);
char *get_command_path(char *command);
char *get_user_input(void);
void show_shelly_prompt(void);
void execute_builtin_command(char *command);
void execute_external_command(char *command, char **args);
void execute_external_helper(char *command, char **args);
void execute_shelly_command(char *user_input);
void execute_child_process(char *command_path, char **args);
void free_args(char **args);


#endif /* SHELLY_H */
