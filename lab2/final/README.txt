There are 2 scource files:
1. ftpc.c The client is for sending file.
2. ftps.c The server is for receiving file.

To run the program:

Step 1, please run ‘make’ to compile the source files.

Step 2, run server,type:
./ftps <local-port>
For example:
./ftps <4001>

step 3 run client,type:
./ftpc <remote-IP> <remote-port> <local-file-to-transfer>
For example:
./ftpc 192.168.0.17 4000 1.jpg


ftps
1. Using stdio.h,sodlib.h, types.h, socket.h, netdb.h, inet.h, unistd,h library.
2. Store the server information and make it connect to client.
3. Send a test message to client to see if the connection is success.
4. Get the file size and file name.

ftpc
1. Using stdio.h,sodlib.h, types.h, socket.h, netdb.h, inet.h, unistd,h library.
2. Store the client information.
3. Once connection success, receive the test message from server.
4. Get the file size and send it to the server.






Author Yu Hsiaung Mike Chen, Yi Fei Zhang