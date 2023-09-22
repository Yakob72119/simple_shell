# 0x16. C - Simple Shell
 Project done by teams of 2 people (Team Members: Kassahun.S, Yakob.B)

# List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

# Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# files
- [shell.h](https://github.com/Yakob72119/simple_shell/blob/master/shell.h) - is the header file which contains the standared header file and prototype of o function used in the program.
- main.c - initialize the program with infinite loop by call the prompt function
- README.md - description about the project repo
- helper
- man_1_simple_shell - is the man page for the shell we are going to write.
- AUTHORS - file at the  root of your repository, listing all individuals having contributed content to the repository. 
- special_character - It identiies if the special inputs such as if the frist input is slash,the user typed exit or env...
- string.c -it handles the strings(string length, write string,find string in directory,concatane strings....)
- cmd.c - it finds the command the user entered.
- execute.c - execute the command.
- prompt.c - it use getline system call to read the input from the user and run infinite loop with fork to keep prompt going.

# Tasks

# 0. Betty would be proud 
# 1. Simple shell 0.1
# 2. Simple shell 0.2
# 3. Simple shell 0.3
# 4. Simple shell 0.4
# 5. Simple shell 1.0
# 6. Simple shell 0.1.1
# 7. Simple shell 0.2.1
# 8. Simple shell 0.4.1
# 9. setenv, unsetenv
# 10. cd
# 11. ;
# 12. && and ||
# 13. alias
# 14. Variables
# 15. Comments
# 16. File as input
