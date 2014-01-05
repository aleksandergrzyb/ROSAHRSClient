/*
* primary authors: Tomasz Blajek, Jakub Frankowski, Dominik Belter
This file is part of the TCPRobotControl library.
In general, you do not need to modify it.
*/

#ifndef RPCInterfaceAHRSH
#define RPCInterfaceAHRSH

#include "Frames.h"

/*
Remote Procedure Call Interface.
See RequestHandler and RPCCaller for detailed information.
*/
class RPCInterfaceAHRS
{

  public:
    ///  1. odczytuje pozycje i orientacje
    virtual ERR readPosition(float res[6]){return -66;}
    ///  2. odczytuje orientacje -- macierz
    virtual ERR readMatrix(float res[9]){return -66;}
    ///  3. odczytuje predkosc katowa i liniowa
    virtual ERR readVelocity(float res[6]){return -66;}
    ///  4. odczytuje predkosc katowa i liniowa
    virtual ERR readAcceleration(float res[6]){return -66;}
    ///  101. konfiguracja AHRS
    virtual ERR setParameters(float reset_delta_angle){return -66;}
};

#endif

