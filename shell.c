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
	char** args = parse_args(line);
	
	if (strcmp(args[0], "exit") == 0){
		exit(0);
	}
	
	if (strcmp(args[0], "cd") == 0) {
		if (args[1]) {
			if (chdir(args[1]) == -1) {
				printf("whomst such directory.\n");
			}
			return;
		}
		else {
			chdir(getenv("HOME"));
			return;
		}
	}
	printf("args: %s\n", args[1]);
	if (args[1] && strcmp(args[1], ">") == 0) {
		parse_redir(args);
		return;
	}	
	int f = fork();
	if (f == 0) {
		execvp(args[0], args);
		printf("invalid command\n");
		exit(1);
	}
	else {
		int status;
		wait(&status);
	}
}

void parse_pipe(char *command){
	
} // parse the simple pipe

void parse_redir(char **redirlist) {
	int i = 0;
	char ** prev_cmd;
	while(redirlist[i]){
		printf("i: %d\n", i);
		if(strcmp(redirlist[i], ">") != 0){
			prev_cmd[i] = redirlist[i];
			printf("prev_cmd[%d]: %s\n", i, prev_cmd[i]);
		}
		else{
			printf("donzo\n");
			exit(1);
		}
		i++;
	}
	printf("prev_cmd");
		int fd = open("commands.txt", O_CREAT | O_TRUNC, 0644);
		int stdout_fd = dup(1);
		dup2(fd, 1);	
		
		
		execvp(prev_cmd[0], prev_cmd);
		
		dup2(stdout_fd, 1);
		close(stdout_fd);
	
}