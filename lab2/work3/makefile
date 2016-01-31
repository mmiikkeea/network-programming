CC = gcc
OBJCLI = client.c 
OBJSRV = server.c
CFLAGS = 
# setup for system
LIBS =

all: client server 

client:	$(OBJCLI)
	$(CC) $(CFLAGS) -o $@ $(OBJCLI) $(LIBS)

server:	$(OBJSRV)
	$(CC) $(CFLAGS) -o $@ $(OBJSRV) $(LIBS)

clean:
	rm server client