#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#define KEY 12345678
typedef struct msgbuf1 {
    long mtype; 
    char mtext[256];
} messageBuffer;
void main() {
    messageBuffer sendBuffer;
    messageBuffer *messagePointer;
    key_t key = KEY;
    int messageID;
    int messageFlag;
    int messageReturn;
    int messageLength;
    messageFlag = 0666 | IPC_CREAT;
    messageID = msgget(key, messageFlag);
    if (messageID == -1) {
        perror("Létrehozás sikertelen\n");
        exit(-1);
    }
    messagePointer = &sendBuffer;
    messagePointer->mtype = 1;
    strcpy(messagePointer->mtext, "Sample Text");
    messageLength = strlen(messagePointer->mtext) + 1;
    messageReturn = msgsnd(messageID, (messageBuffer*)messagePointer, messageLength, messageFlag);
    if (messageReturn == -1) {
        perror("Küldés sikertelen\n");
        exit(-1);
    }
    printf("Küldés sikeres\n");
}
