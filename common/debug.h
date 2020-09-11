#ifndef __DEBUG_H__

#define __DEBUG_H__
#include "config.h"


#if (DEBUG_PRINT == 1)
#define debug   printf
#else
#define debug(x) 
#endif

#endif // !DEBUG_H__