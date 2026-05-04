/**
 * @file message_queue_sender.c
 * @brief Demonstrates sending data to a System V message queue.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdbool.h>

#define MAX_MESSAGE_SIZE 256

/**
 * @brief Structure for the message queue buffer.
 */
struct message_queue_demo
{
    long int message_type;
    char messgage[MAX_MESSAGE_SIZE];
};

/**
 * @brief Main function to send messages to the queue.
 *
 * Connects to or creates the message queue with key 1234 and continuously
 * writes messages containing incrementing integers to it.
 *
 * @return 0 on successful execution.
 */
int main()
{
    key_t message_id;
    struct message_queue_demo message;
    
    char buff[100];
    int data = 0;
    
    message_id = msgget(1234, IPC_CREAT|0777);
    if (message_id == -1)
    {
        printf("Unable to create message Queue\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        sprintf(message.messgage, "data = %d", data);
        message.message_type = 1;
        if(msgsnd(message_id, &message, MAX_MESSAGE_SIZE, 0) == -1)
        {
            printf("Unable to send the data\n");
        }
        data++;
        sleep(1);
    }
    
    return 0;
}

/*
Expected Output:
(Program runs continuously without output on successful send)
*/