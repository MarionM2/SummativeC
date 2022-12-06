# SummativeC
It contains c projects 
Thought Process
● Implement a server program to listen for incoming connections from clients. This program should also be responsible for exchanging messages with clients based on the communication protocol. 
● Implement a client program to connect to the server. This program should be able to send messages to the server according to the communication protocol.
● Implement a thread pool to handle incoming connections from clients. This will allow the server to handle multiple connections simultaneously.
● Implement interprocess communication between the client and the server. This is done using sockets. This will allow the client and the server to exchange messages. 
● Implement a mechanism for synchronization between the client and the server. This can be done using locks or semaphores. This will ensure that only one thread is accessing a shared resource at a time. 
● Implement a logging system for the server. This will allow the server to record messages sent between the client and the server and any errors that may occur. 
● Test the application to make sure that it 


Command to Compiling the program 
gcc -o a.out exit.c -lpthread -lrt


Running the program 
./a.out
