#include <unistd.h>
#include <signal.h>
void do_nothing();
main ()
{


    signal(SIGALRM, do_nothing);
    printf("%d Várok\n");
    pause();
        printf("Végre, itt az alarm \n");
}
void do_nothing(){ ;}
