#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void TermHandler(int sig);
int main(void){
    if (signal(SIGTERM, TermHandler) == SIG_ERR){
        printf("nem tud \"SIGTERM\" jelre állítani\n");
        return 0;
    }
    while(1){
        printf("vár\n");
        sleep(3);
    }
    return 0;
}
void TermHandler(int sig){
    signal(sig, SIG_IGN);
    printf("SIGTERM: %d\n", sig);
}
