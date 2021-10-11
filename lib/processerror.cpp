#include "processerror.h"

void ProcessError::errorProc(const long& res, const char* msg)
{
    if(res == ERROR_CODE) // ERROR_CODE = -1
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

void ProcessError::errorZero(const long& res, const char* msg, bool Exit)
{
    if(res == ERROR_ZERO_CODE) // ERROR_ZERO_CODE = 0
    {
        std::cout << msg << std::endl;
        if(Exit)
            exit(EXIT_FAILURE);
    }
}