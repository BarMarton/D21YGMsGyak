#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int status;

	if ( ( pid = fork()) < 0) perror("fork error");
	else if (pid == 0) exit(11);
	if (wait(&status) != pid) perror("wait error");
	if (WIFEXITED(status)) printf("Normális befejezés %d\n", WEXITSTATUS(status));

	if ( ( pid = fork()) < 0) perror("fork error");
        else if (pid == 0) abort();
        if (wait(&status) != pid) perror("wait error");
        if (WIFSIGNALED(status)) printf("Nem normális befejezés %d\n", WTERMSIG(status));

	if ( ( pid = fork()) < 0) perror("fork error");
        else if (pid == 0) {int a; int b = 0; a = 10 / b;}
        if (wait(&status) != pid) perror("wait error");
        if (WIFSIGNALED(status)) printf("Nem normális befejezés %d\n", WTERMSIG(status));


	exit(0);
}

