#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MSIZE 256
int main(){
	char inBuffer[MSIZE];
	int pid, fileDesc;
	char input[] = "Barabás Márton";
	char * fifo = "/tmp/D21YGM";
	mkfifo(fifo, 0666);
	pid = fork();
	if (pid < 0){
		exit(2);
	}
	if (pid == 0){
		printf("Child megpróbál beleírni a fifo pipe-ba\n");
		fileDesc = open(fifo, O_WRONLY);
		write(fileDesc, input, strlen(input)+1);
		printf("Siker\n");
	}
	else if (pid > 0 ){
		fileDesc = open(fifo, O_RDONLY);
		read(fileDesc, inBuffer, strlen(input)+1);
		printf("Parent: %s\n", inBuffer);
		close(fileDesc);
	}
	return 0;
}
