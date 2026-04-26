#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdbool.h>

struct messageQueueDemo
{
    long int messageType;
    char messgage[BUFSIZ];
};

int main()
{
    key_t messageID;
    struct messageQueueDemo message;
    char buff[100];
    int long messageToReceive = 0;

    messageID = msgget(1234, IPC_CREAT | 0777);
    if (messageID == -1)
    {
        printf("Unable to create message Queue\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        if (msgrcv(messageID, &message, BUFSIZ, messageToReceive, 0) == -1)
        {
            printf("Unable to Read the data\n");
        }
        printf("RxData = %s\n", message.messgage);
        sleep(1);
    }
    
    msgctl(messageID, IPC_RMID, 0);

    return 0;
}