#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#define KEY 12345678
void main() {
    key_t key = KEY;
    int messageID = msgget(key, 0);
    int messageReturn = msgctl(messageID, IPC_RMID, NULL);
    if (messageID == -1) {
        perror("Törlés sikertelen\n");
        exit(-1);
    }
    printf("Törlés sikeres\n");
}
