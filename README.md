# Pipex
The pipex project is a program that simulates the functionality of the shell pipeline by redirecting the output of one
command as the input of another command.

### Discription of mandatory part
The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
All errors like: wrong commands,  permission to files and etc, need be handle.

### Discription of bonus part
Program need handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Support `<<` and `>>`, when instead of `file1` is`here_doc`.
```bash
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```

## Algorithm
To implement pipex, we can use the `fork`, `execve`, `pipe`, and `dup2` system calls. We can create multiple child processes, one for each command, and then connect them with a pipe. The first child process will execute **cmd1** and redirect its output to the write end of the pipe. The second child process will execute **cmd2** and read its input from the read end of the pipe and redirect its output to the write end of another pipe. This will continue until all commands are executed. Finally, the parent process will wait for all child processes to complete and then exit.
