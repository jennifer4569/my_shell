#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "shell.h"

char** parse_args(char* line){
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

int execute_commands(char ** args){
  //if the args are separated by ;
  /*
    char *** sep_args;
    int args_i = 0;
    int sep_args_i = 0;
    while (args[args_i]) {
    if(args[args_i] == ";"){
    sep_args[sep_args_i] = args[0]; //args[0] to args[i]
    sep_args_i++;
    }
    args_i++;
    }
  */
  int prev = 0;
  int curr = 0;
  while(args[curr]){
    if(strcmp(args[curr], ";") == 0){
      char ** this_arg;
      int i = 0;
      while(curr != i + prev){ //????
	this_arg[i] = args[prev + i];
	i++;
      }
      
      if(strcmp(args[0], "cd") == 0){
	return 1;
      }
      if (execvp(args[0], args) == -1){
	printf("%s: command not found\n", args[0]);
	return -1;
      }
      prev = curr + 1;
    }
    curr++;
    
  }
}

void print_args(char ** args){
  int i = 0;
  while(args[i]){
    printf("%s\n", args[i]);
    i++;
  }
}

int parse_params() {
  char line[256];
  fgets(line, 256, stdin);

  int f = fork();
  char** args = parse_args(line);
  //if child
  if(f == 0){
    return execute_commands(args);
  }
  //if parent
  else{
    int status;
    wait(&status);
    //cd
    if(status == 1){
      if(chdir(args[1]) != 1){
	printf("Current directory is now: %s\n", args[1]);
      }
      else{
	printf("%s: directory not found\n", args[1]);
      }
    }
    
  }
}

void run(){
  while(1){
    printf("> ");
    parse_params();
  }
}
