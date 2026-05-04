/**
 * @file message_queue_receiver.c
 * @brief Demonstrates receiving data from a System V message queue.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdbool.h>

/**
 * @brief Structure for the message queue buffer.
 */
struct message_queue_demo
{
    long int message_type;
    char messgage[BUFSIZ];
};

/**
 * @brief Main function to receive messages from the queue.
 *
 * Connects to the message queue with key 1234 and continuously reads
 * messages from it, printing the received data to the standard output.
 *
 * @return 0 on successful execution.
 */
int main()
{
    key_t message_id;
    struct message_queue_demo message;
    char buff[100];
    int long message_to_receive = 0;

    message_id = msgget(1234, IPC_CREAT | 0777);
    if (message_id == -1)
    {
        printf("Unable to create message Queue\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        if (msgrcv(message_id, &message, BUFSIZ, message_to_receive, 0) == -1)
        {
            printf("Unable to Read the data\n");
        }
        printf("RxData = %s\n", message.messgage);
        sleep(1);
    }
    
    msgctl(message_id, IPC_RMID, 0);

    return 0;
}

/*
Expected Output:
RxData = data = 0
RxData = data = 1
RxData = data = 2
...
*/