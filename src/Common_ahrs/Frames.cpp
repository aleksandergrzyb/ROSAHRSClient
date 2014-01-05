/*
This file is part of the TCPRobotControl library.
In general, you do not need to modify it.
*/

#include "Frames.h"

int ResFrameSizeAHRS(int nres)
{
  // Note that this formula is correct. Do not change.
  return (nres+1)*sizeof(float);
}

ERR InitAHRS()
{
#ifdef WIN32
  WSADATA d;
  if(WSAStartup(0x0202,&d))
  {
    perror("WSAStartup failed:");
    return 56;
  }
#endif
  return 0;
}

ERR CloseAHRS()
{
#ifdef WIN32
  if(WSACleanup())
  {
    perror("WSACleanup failed:");
    return 65;
  }
#endif
  return 0;
}

void close_socketAHRS(int s)
{
#ifdef WIN32
  closesocket(s);
#else
  close(s);
#endif
}

