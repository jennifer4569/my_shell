void run();
char** parse_args(char* line);
int execute_commands(char** args);
void print_args(char** args);
int parse_params();
void parse_pipe(char *command);
void parse_redir(char *redir);