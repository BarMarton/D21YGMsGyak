#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	while(1){
		char cmnd[256];
		scanf("%s", cmnd);
		if(strcmp(cmnd, "EXIT") == 0) exit(0);
		int status;
		if((status = system(cmnd)) < 0) perror("system() error");
		if(WIFEXITED(status)) printf("Normál befejezés, érték = %d\n", WEXITSTATUS(status));
	}
}
