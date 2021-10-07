#ifndef CLIENT_SERVER_PROCESSERROR_H
#define CLIENT_SERVER_PROCESSERROR_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class ProcessError
{
    static inline int ERROR_CODE = -1;
    static inline int ERROR_ZERO_CODE = 0;

public:

    static void errorProc(const long& res, const char* msg);

    static void errorZero(const long& res, const char* msg, bool Exit);
};


#endif //CLIENT_SERVER_PROCESSERROR_H
