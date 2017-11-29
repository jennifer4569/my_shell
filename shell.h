void run(); // run

char** parse_args(char* line); // parse whitespace and newline

void execute_commands(); // execute

void print_args(char** args); // prints out single command

void parse_pipe(char *command); // parse the simple pipe

void parse_redir(char *redir); // parse the simple redirection