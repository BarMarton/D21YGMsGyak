#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MSIZE 256
int main(){
	char inBuffer[MSIZE];
	int p[2], nbytes, pid;
	if (pipe(p) < 0){
		perror("Hiba\n");
		exit(1);
	}
	pid = fork();
	if (pid < 0) exit(2);
	if (pid == 0){
		printf("child ír\n");
		write(p[1], "BM D21YGM", MSIZE);
		printf("child kész\n");
	}
	else if (pid > 0 ){
		wait(NULL);
		printf("parent olvas\n");
		read(p[0], inBuffer, MSIZE);
		printf("parent: %s\n", inBuffer);
	}
	return 0;
}
