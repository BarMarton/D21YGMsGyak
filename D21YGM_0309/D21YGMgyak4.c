#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	if ( ( pid = fork()) < 0) perror("fork error");
	else if (pid == 0) execlp("date", "child", NULL);

	if (waitpid(pid, NULL, 0) < 0) perror("wait error");
	exit(0);
}

