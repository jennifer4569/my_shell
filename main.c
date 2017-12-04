#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int main() {
	
	printf("Note: MUST use whitespace when using ; or | OR the shell will NOT work properly.\n");
	printf("Ex: ls ; echo hello\n");
	printf("Ex: ls | wc\n");
	run();
	return 0;
	
}