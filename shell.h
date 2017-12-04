void run(); // run

char** parse_args(char* line); // parse whitespace and newline

void execute_commands(); // execute

void print_args(char** args); // prints out single command

int parse_pipe(char** command); // parse the simple pipe

void parse_redir_in(char** redir); // parse the simple redirection

void parse_redir_out(char** redir); // parse the simple redirection