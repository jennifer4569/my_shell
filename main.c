#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int main() {
	
	printf("\n\nWelcome to Jennifer and Yedoh's shell!\n");
	printf("\nNote: MUST use whitespace when using ; or | OR the shell will NOT work properly.\n");
	printf("Note: At this moment, piping, or using |, does not work.\n");
	printf("Ex: ls ; echo hello\n\n");
	run();
	return 0;
	
}