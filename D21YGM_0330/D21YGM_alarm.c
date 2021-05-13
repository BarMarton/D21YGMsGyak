#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#define SECOND 1
void do_nothing();
void do_int();

void main () {
	int i;
	unsigned int sec = 1;
	signal(SIGINT, do_int);
	for (i = 1; i < 8; i++) {
		alarm(sec);
		signal(SIGALRM, do_nothing);
		printf("%d Várok\n",i);
		pause();
	}
}	
void do_nothing(){ ;}
void do_int() {
    printf("int jött");
    signal(SIGINT,SIG_IGN);
}
