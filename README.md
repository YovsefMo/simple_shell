# Simple Shell Project

This project is a basic implementation of a Unix shell, also known as a command-line interpreter. The shell supports executing both built-in commands and external commands located in the system's PATH.

## Features

- Interactive mode: Users can enter commands one by one.
- Non-interactive mode: Commands can be read and executed from a file.
- Built-in commands: Supports built-in commands like `cd`, `env`, `help`, `echo`, and `history`.
- External commands: Can execute external commands from the system's PATH.
- History: Keeps track of previously executed commands.
- Signal handling: Handles Ctrl+C to interrupt and return to the prompt.

## Usage

To compile the shell program, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shelly
```

## Learning Objectives
By the end of this project, you should be able to explain the following concepts without needing external resources:

**General**
- Understanding the design and implementation of the original Unix operating system.
- Identifying the first version of the UNIX shell.
- Recognizing who invented the B programming language (the direct predecessor to the C programming language).
- Knowledge of Ken Thompson and his contributions to computing.
- Understanding how a shell works.
- Defining a PID (Process ID) and a PPID (Parent Process ID).
- Manipulating the environment of the current process.
- Differentiating between a function and a system call.
- Creating processes.
- Identifying the three prototypes of the `main` function.
- Explaining how the shell uses the PATH environment variable to find programs.
- Using the `execve` system call to execute another program.
- Understanding how to suspend the execution of a process until one of its children terminates.
- Defining EOF ("end-of-file").

## Requirements
- Allowed editors: vi, vim, emacs
- All files must be compiled on Ubuntu 20.04 LTS using gcc with the following options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All code files must end with a new line.
- A `README.md` file at the root of the project folder is mandatory.
- Your code should follow the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`.
- The shell should not have any memory leaks.
- Each file should contain no more than 5 functions.
- All header files should be include guarded.
- Use system calls only when necessary.
- Write a README with a description of your project.
- There should be an AUTHORS file at the root of your repository, listing all individuals who contributed to the repository.

## Authors
- Noah: GitHub - [noooaah](https://github.com/noooaah)
- Yousef: GitHub - [YovsefMo](https://github.com/YovsefMo)
