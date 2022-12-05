#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t sem_client;
sem_t sem_server;

// Client thread that will send messages to the server thread 
void* client(void *arg)
{
    
        sem_wait(&sem_client); // Wait for signal from the server thread 
        printf("I would like to speak with an agent\n");
        sem_post(&sem_server); // Signal the server thread 
        sleep(1);
}

// Server thread that will receive messages from the client thread 
void* server(void *arg)
{
        sem_wait(&sem_server); // Wait for signal from the client thread 
        printf("Hello, how can we help you today?\n");
        sem_post(&sem_client); // Signal the client thread 
        sleep(1);
}

int main()
{
    pthread_t thread_client, thread_server;
    sem_init(&sem_client, 0, 1);
    sem_init(&sem_server, 0, 1);
    
    //Create the client and server threads
    for(int i = 0; i<2; i++){
    pthread_create(&thread_client, NULL, client, NULL);
    sleep(1);
    pthread_create(&thread_server, NULL, server, NULL);
    }
    
    // Wait for the threads to finish 
    pthread_join(thread_client, NULL);
    pthread_join(thread_server, NULL);
    
    // Destroy the semaphores 
    sem_destroy(&sem_client);
    sem_destroy(&sem_server);
    
    return 0;
}

