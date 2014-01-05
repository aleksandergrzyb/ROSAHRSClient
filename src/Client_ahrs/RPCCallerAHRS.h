/*
* primary authors: Tomasz Blajek, Jakub Frankowski, Dominik Belter
This file is part of the TCPRobotControl library.
In general, you do not need to modify it.
*/

#ifndef RPCCallerAHRSH
#define RPCCallerAHRSH

#include "../Common_ahrs/RPCInterface.h"

/*
This is the client-side implementation of the RPC mechanism.
This class overrides all the remote procedures declared in RPCInterface
as remote calls to the server. As a result, an instance of this class
behaves just like the request handler currently used on the server side.

Note that a one-time to Run() is necessary before calling any of the
remote procedures. See the ClientTest file for an example of use.
This class has also the method Stop() that causes the server to close. 
*/

class RPCCallerAHRS: public RPCInterfaceAHRS
{
    public:
        RPCCallerAHRS(const char* host,int port);
        ~RPCCallerAHRS();
    public:
        ERR Run();
        ///  1. odczytuje pozycje i orientacje
        ERR readPosition(float res[6]);
        ///  2. odczytuje orientacje -- macierz
        ERR readMatrix(float res[9]);
        ///  3. odczytuje predkosc katowa i liniowa
        ERR readVelocity(float res[6]);
        ///  4. odczytuje predkosc katowa i liniowa
        ERR readAcceleration(float res[6]);
        ///  101. konfiguracja AHRS
        ERR setParameters(float reset_delta_angle);
        ERR Stop();
    private:
        ERR call(float* res = 0, int nres = 0);
        void copyres(float* res, int nres);
    private:
        char host[200];
        int port;
        int socketDescriptor;
        ReqFrameAHRS reqf;
        ResFrameAHRS resf;
        ERR cerr;
        float* rqd;
        float* rsd;
};

#endif

