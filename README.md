# 0x16. C - Simple Shell
 Project done by teams of 2 people (Team Members: Kassahun.S, Yakob.B)

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

## List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
-_exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## files
- [shell.h](https://github.com/Yakob72119/simple_shell/blob/master/shell.h) - is the header file which contains the standared header file and prototype of o function used in the program.
- [main.c](https://github.com/Yakob72119/simple_shell/blob/master/main.c) - initialize the program with infinite loop by call the prompt function
- [README.md](https://github.com/Yakob72119/simple_shell/blob/master/README.md) - description about the project repo
- [AUTHORS](https://github.com/Yakob72119/simple_shell/blob/master/AUTHORS) - file at the  root of your repository, listing all individuals having contributed content to the repository. 
- [builtins.c](https://github.com/Yakob72119/simple_shell/blob/master/builtins.c) - These functions are part of a shell program and handle the env (environment variables) and quit (exit the shell) commands. The behavior of quit depends on the number of arguments provided.
- [helpers.c](https://github.com/Yakob72119/simple_shell/blob/master/helpers.c) - These functions provide basic string manipulation and text processing capabilities that are often used in shell programs or other applications that work with character data.
- [helpers_one.c](https://github.com/Yakob72119/simple_shell/blob/master/helpers_one.c) - These functions provide basic string manipulation operations like comparison, concatenation, and searching for characters within strings. They can be used in various string processing tasks within a C program.
- [helpers_two.c](https://github.com/Yakob72119/simple_shell/blob/master/helpers_two.c) - These functions provide various utility operations, including string tokenization, integer conversion, memory reallocation, signal handling, and comment removal, which can be used in different parts of a C program, such as a shell or text processing application.
- [init_function.c](https://github.com/Yakob72119/simple_shell/blob/master/init_function.c) - This function appears to be part of a shell program or a similar application where it handles the execution of different types of commands, either in a separate child process or in the current process, based on the command type.
- [non_interact_function.c](https://github.com/Yakob72119/simple_shell/blob/master/non_interact_function.c) - This function is designed to handle the execution of commands when the shell is running in a non-interactive mode, allowing it to process commands from scripts or input sources other than a terminal.
- [utils.c](https://github.com/Yakob72119/simple_shell/blob/master/utils.c) - These functions collectively provide essential functionality for parsing, executing and handling various types of shell commands, making them suitable for use in a shell program or similar applications.

