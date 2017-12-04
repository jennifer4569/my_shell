# my_shell
## by Jennifer Zhang and Yedoh Kang, period 4

### Features:
  * Forks and executes commands.
  * Parses up to two commands on one line.
  * Redirects using >, <.

### Attempted:
  * Pipes

### Bugs:
  * Sometimes, running commands such as ```cat``` breaks everything -- functions that work otherwise, such as ```ls```, will not run after cat crashes.
  * If commands are not separated with spaces, they will not run properly.

### Files & Function Headers:
main.c
  * Runs the shell running command.

shell.c
  * Contains all the functions for shell.
    ```
    /*======== void run() ==========
    Inputs: None
    Returns: void

    Gets the command the user has imputted, parses that line, 
    and runs the execute_commands() function on the parsed
    arguments, including semicolons.
    ====================*/

    /*======== void print_args() ==========
    Inputs: char **args
    Returns: void

    Prints the arguments given, args.
    ====================*/

    /*======== char **parse_args() ==========
    Inputs: char *line
    Returns: char **args

    Takes in a line that the user inputted, and breaks it 
    into a char **, args. It also getss rid of new lines at 
    the end.
    ====================*/

    /*======== void execute_commands() ==========
    Inputs: char *args[256]
    Returns: void

    Executes the inputted command by forking, and deals with 
    cd, exit, and redirection.
    ====================*/

    /*======== void parse_redir_out() ==========
    Inputs: char **redirlist
    Returns: void

    Given the user-inputted command, check to see if it needs 
    to redirect stdout -- if so, it executes the given command, 
    and redirects stdout to the given file. (Creates a new file 
    if it does not already exist).
    ====================*/

    /*======== void parse_redir_in() ==========
    Inputs: char **redirlist
    Returns: void

    Given the user-inputted command, check to see if it needs 
    to redirect stdin -- if so, it reads the given file, and 
    executes the command in the shell.
    ====================*/
    ```
shell.h
  * Contains all the headers for shell.c