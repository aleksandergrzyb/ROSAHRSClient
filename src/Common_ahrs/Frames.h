/*
This file is part of the TCPRobotControl library.
In general, you do not need to modify it.
*/

#ifndef FramesAHRSH
#define FramesAHRSH

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#endif

/*
Type for holding an error code (zero means no error).
*/
typedef signed char ERR;

/*
Request frame, with request identifier and arguments.
*/
struct ReqFrameAHRS
{
  signed char req_id;
  float data[1];
};

/*
Artificial request identifier that causes the server to stop.
*/
const signed char STOP_REQ_ID_AHRS=-9;

/*
Response frame, with remote procedure error code, and returned values.
Only part of this frame is really sent, as some procedures do not return values.
*/
struct ResFrameAHRS
{
  ERR err;
  float data[9];
};

/*
Return how many bytes of ResFrame should be sent in response, if the procedure returns
nres values.
*/
int ResFrameSizeAHRS(int nres);

/*
Initialisation and finalisation of the TCP functions. Might not be needed on Linux.
*/
ERR InitAHRS();
ERR CloseAHRS();

/*
The function for closing socket will have separate implementations for Windows and Linux.
*/
void close_socketAHRS(int s);

#endif

