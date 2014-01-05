/*
This file is part of the TCPRobotControl library.
In general, you do not need to modify it.
*/

#include "RPCCallerAHRS.h"

#include <string.h>

RPCCallerAHRS::RPCCallerAHRS(const char* host, int port)
{
    strcpy(this->host, host);
    this->port = port;
    socketDescriptor = 0;
    rqd = reqf.data;
    rsd = resf.data;
}

RPCCallerAHRS::~RPCCallerAHRS()
{
    if(socketDescriptor) {
        close_socketAHRS(socketDescriptor);
    }
}

ERR RPCCallerAHRS::Run()
{
    struct hostent *server;
    // PF_INET - domena (Protocol Family)
    // SOCK_STREAM - typ gniazda (strumieniowe)
    // IPPROTO_TCP - protokół TCP
    // Zwraca -1 w przypadku błędu
    socketDescriptor = socket(PF_INET, SOCK_STREAM, 0);
    if(socketDescriptor < 0) {
        perror("Socket failed:");
        return 1;
    }
    struct sockaddr_in srv;
    memset(&srv,0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
    server = gethostbyname(host);
    if(!server) {
        perror("GetHostByName failed:");
        return 2;
    }
    srv.sin_addr.s_addr = *((unsigned long int*)server->h_addr);
    if(connect(socketDescriptor, (struct sockaddr*)&srv, sizeof(srv)) < 0) {
        perror("Connect failed:");
        return 3;
    }
    return 0;
}

ERR RPCCallerAHRS::call(float* res, int nres)
{
    int n = send(socketDescriptor, (char*)&reqf, sizeof(ReqFrameAHRS), 0);
    if(n != sizeof(ReqFrameAHRS)) {
        perror("Call error:");
        return cerr = 55;
    }
        int explen = ResFrameSizeAHRS(nres);
        int len = recv(socketDescriptor, (char*)&resf, explen, 0);
    if(len != explen) {
        return 23;
    }
    
    for(int i=0; i<nres; i++) {
        // printf("%f\n", resf.data[i]);
        res[i]=rsd[i];
    }
    return cerr = 0;
}

ERR RPCCallerAHRS::Stop()
{
    reqf.req_id = STOP_REQ_ID_AHRS;
    if(call()) {
        return cerr;
    }
    return resf.err;
}

///  1. odczytuje pozycje i orientacje
ERR RPCCallerAHRS::readPosition(float res[6])
{
    reqf.req_id = 1;
    if(call(res, 6)) {
        return cerr;
    }
    return resf.err; 
}

///  2. odczytuje orientacje -- macierz
ERR RPCCallerAHRS::readMatrix(float res[9])
{
    reqf.req_id = 2;
    if(call(res, 9)) {
        return cerr;
    }
    return resf.err; 
}

///  3. odczytuje predkosc katowa i liniowa
ERR RPCCallerAHRS::readVelocity(float res[6])
{
    reqf.req_id = 3;
    if(call(res, 6)) {
        return cerr;
    }
    return resf.err; 
}

///  4. odczytuje predkosc katowa i liniowa
ERR RPCCallerAHRS::readAcceleration(float res[6])
{
    reqf.req_id = 4;
    if(call(res, 6)) {
        return cerr;
    }
    return resf.err; 
}

///  101. konfiguracja AHRS
ERR RPCCallerAHRS::setParameters(float reset_delta_angle)
{
    reqf.req_id = 101;
    rqd[0] = reset_delta_angle;
    if(call()) {
        return cerr;
    }
    return resf.err;
}
