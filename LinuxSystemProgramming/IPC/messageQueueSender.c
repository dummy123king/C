#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdbool.h>

#define MAX_MESSAGE_SIZE 256

struct messageQueueDemo
{
    long int messageType;
    char messgage[MAX_MESSAGE_SIZE];
};

int main()
{
    key_t messageID;
    struct messageQueueDemo message;
    
    char buff[100];
    int data = 0;
    
    messageID = msgget(1234, IPC_CREAT|0777);
    if (messageID == -1)
    {
        printf("Unable to create message Queue\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        sprintf(message.messgage, "data = %d", data);
        message.messageType = 1;
        if(msgsnd(messageID, &message, MAX_MESSAGE_SIZE, 0) == -1)
        {
            printf("Unable to send the data\n");
        }
        data++;
        sleep(1);
    }
    
    return 0;
}