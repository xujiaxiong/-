/* MIO.h  - MIO driver extern head file for windows */

/* modification history
-----------------------

01a 2017/2/28 14:50:55  create by frank
*/



#ifndef MIO_WIN_H
#define MIO_WIN_H


#ifdef __cplusplus
extern "C" {
#endif


#include "golytec.h"


//#define    MIO_BASE_ERROR                      0x4D490100
#define    MIO_BASE_ERROR                      0x4
#define    MIO_PARAMETER_ERROR                  ( MIO_BASE_ERROR + 0x01 )
#define    MIO_INITIALIZED_ERROR                ( MIO_BASE_ERROR + 0x02 )
#define    MIO_RS485_WRITE_ERROR                ( MIO_BASE_ERROR + 0x03 )
#define    MIO_RS485_READ_ERROR                 ( MIO_BASE_ERROR + 0x04 )




#ifdef __cplusplus
}
#endif

#endif  // end of MIO_WIN_H


