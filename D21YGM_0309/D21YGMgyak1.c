#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int status;
	if((status = system("ls -al")) < 0) perror("system() error");
	if(WIFEXITED(status)) printf("Normál befejezés, érték = %d\n", WEXITSTATUS(status));
	exit(0);
}
