#include <unistd.h>
#include <signal.h>
#include <stdio.h>
void do_nothing();
void main ()
{
    signal(SIGALRM, do_nothing);
    printf("%d Várok\n", getpid());
    pause();
        printf("Végre, itt az alarm \n");
}
void do_nothing(){ ;}
