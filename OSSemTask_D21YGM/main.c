#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define EXIT_STATUS 123
int main()
{
	int tmp, status;
	tmp=fork();
	if(tmp==0){	
		system("/bin/ls -R");
		exit(EXIT_STATUS);
		}
	else{
		wait(&status);
		if (WIFEXITED(status)) printf("Child visszatért: %d\n", WEXITSTATUS(status));
  		else if (WIFSIGNALED(status)) printf("Nem normális befejezés: %d\n", WTERMSIG(status));
		}
	return 0;
}
