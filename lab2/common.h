#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include <netdb.h>
#include <netinet/in.h>
#include <stdint.h>

#define FNAME_LEN 20
#define MSS 1000 //bytes
#define WINSIZE 20000 //bytes
#define BUFFER_SIZE 64000 //bytes

#define LOCAL_PORT_RECEIVER 6660
#define LOCAL_PORT_SENDER 6663
#define TCPD_PORT_RECEIVER 6661
#define TCPD_PORT_SENDER 6664
#define TROLL_PORT_RECEIVER 6662
#define TROLL_PORT_SENDER 6665
#define TIMER_PORT 6666

#define CLIENT_ACK_MSG "ack"
#define CLIENT_ACK_MSG_LEN 4
#define CLIENT_START_MSG "start"
#define CLIENT_START_MSG_LEN 6

/*
 * Returns bound socket, or negative on fail
 */
int bindUdpSocket(char *host, char *port);

/*
 * Gets incoming address string and puts it in dst, size is length of dst
 */
void getInAddrString(int af, struct sockaddr *sa, char *dst, socklen_t size);

/*
 * Returns 32bit timestamp in microseconds, expect overflow
 */
uint32_t getTimestamp();

/*
 * Fills servinfo, or returns negative on fail
 */
int fillServInfo(char *host, char *port, struct addrinfo **servinfo);

/*
 * Calls send repeatedly until len bytes have been sent from buf, or returns -1
 * on failure and sets len to number of bytes sent.
 */
int sendAll(int sockfd, const void *buf, int *len);

/*
 * Calls sendto repeatedly until len bytes have been sent from buf, or returns
 * -1 on failure and sets len to number of bytes sent.
 */
int sendAllTo(int sockfd, const void *buf, int *len,
              const struct sockaddr *dest_addr, socklen_t dest_len);

/*
 * Returns a random int between 1024 and 65535 inclusive
 */
int randomPort();

#endif