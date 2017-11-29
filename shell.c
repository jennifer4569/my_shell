#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "shell.h"

void run() {
	while (1) {
		printf("$ ");
		execute_commands();
	}
}

void print_args(char** args) {
	int i = 0;
	while(args[i]){
		printf("%s\n", args[i]);
		i++;
	}
}

char** parse_args(char* line) {
	char** args = (char**)calloc(6, sizeof(char*));
	int i = 0;
	char * tp;
	while(line){
		tp = strsep(&line, " ");
		args[i] = tp;
		//checks for new line
		tp = strsep(&tp, "\n");
		if(!tp){
			args[i] = 0;
		}
		i++;
	}
	return args;
}

void execute_commands(){
	char line[256];
	fgets(line, 256, stdin);
	
	int f = fork();
	if (f == 0) {
		char** args = parse_args(line);
		execvp(args[0], args);
	}
	else {
		int status;
		wait(&status);
	}
}

void parse_pipe(char *command){
	
} // parse the simple pipe

void parse_redir(char *redir){
	
} // parse the simple redirection