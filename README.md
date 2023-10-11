# minitalk
This project implements a data exchange program using Unix signals.  

## Usage
the makefile will create a server and a client executable file. first run the server: 

    ./server

Open another terminal window and run:

    ./client <server_pid> <message_str>
