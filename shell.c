#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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

void execute_commands(char ** args){
  //if the args are separated by ;
  char *** sep_args;
  int args_i = 0;
  int sep_args_i = 0;
  while(args[i]){
    if(args[i] == ";"){
      sep_args[sep_args_i] = //args[0] to args[i]
	sep_args_i++;
    }
    args_i++;
  }

  execvp(args[0], args);
}

void print_args(char ** args){
  int i = 0;
  while(args[i]){
    printf("%s\n", args[i]);
    i++;
  }
}

int main(){
  while(1){
    printf(">");
    char line[256];
    fgets(line, 256, stdin );

    int f = fork();
    //if child
    if(f == 0){
      char** args = parse_args(line);
      execute_commands(args);
      return 0;
    }
    //if parent
    else{
      int status;
      wait(&status);
    }
  }
}
