/* network.h  - UDP network Communication extern head file for windows */

/* modification history
-----------------------

03A 2020/04/19 20:33:00  由RS485.h修改而来
02a 2019/6/27  11:37:25  修改为UDP通信方式
01b 2016/08/09 13:31:23 帧格式修改后相应修改
01a 2016/6/22 10:42:02  create by frank
*/

/* 网络通信协议头文件 */


/*  its对外以太网通信协议格式
master send : 
    msg_len | protocol | seq | nc_code | func_code | reply | addr | size | data 

slave reply:
    msg_len | protocol | seq | nc_code | func_code | error | addr | size | data

除了data为根据具体情况的n字节数, 每个字段都是4字节。

其中:
protocol:  0x474f4c59
seq: 0x54454300
nc_code: 0x4a494e59

func_code: 
    0x0001	读取任意地址内容
    0x1001	写任意地址内容
*/



#ifndef ITS_NETWORK_WIN_H
#define ITS_NETWORK_WIN_H


#ifdef __cplusplus
extern "C" {
#endif


#include "golytec.h"


#define      DEFAULT_TIMEOUT		5000		
#define      MAX_FRAME_SIZE         1024            // 最大的一帧的字节数

#define      NET_SOCKET_MAX_NUM        8            // 使用的socket通信个数



// errno number define
//#define		LMXA_ERROR_BASE					0x4E540100
#define		LMXA_ERROR_BASE					0x8
#define  	    LMXA_INIT_SOCKET_SERVICE_ERROR		( LMXA_ERROR_BASE + 0x1 )
#define     	LMXA_CREATE_SOCKET_ERROR			    ( LMXA_ERROR_BASE + 0x2 )
#define       LMXA_SET_SOCKET_PARAMETER_ERROR		    ( LMXA_ERROR_BASE + 0x3 )
#define		LMXA_SERVER_NOT_LISTENING_ERROR		( LMXA_ERROR_BASE + 0x4 )
#define      LMXA_SYSTEM_ERROR					( LMXA_ERROR_BASE + 0x5 )
#define		LMXA_NOT_INIT_ERROR					( LMXA_ERROR_BASE + 0x6 )
#define     LMXA_CONNECTION_RESET_ERROR            ( LMXA_ERROR_BASE + 0x7 )
#define     LMXA_RECV_TIMOUT                     ( LMXA_ERROR_BASE + 0x8 )
#define     LMXA_PARAMETER_ERROR                 ( LMXA_ERROR_BASE + 0x9 )

#define    LMXA_BEGIN_PORT                  2900


typedef struct
{
    UINT32 tid;
    int fd;
    int port;
} NET_PORT_ADMIN_STRUCT;



#ifndef ITS_NETWORK_C


extern int network_initialize_s(void);

extern int network_terminate_s(void);

extern int network_read_data_s
                            (
                            IN int addr,                // 读取的数据在数据区的地址
                            IN int int32_size,         // 读取的数据大小，32bit为单位
                            OUT UINT8 *data,              // 读取的数据缓存, 大小 INT32_size * 4
                            OUT int *act_len            // 实际读取到的字节数
                            );

extern int network_write_data_s
                            (
                            IN int addr,                // 写入的数据在数据区的地址
                            IN int int32_size,         // 写入的数据大小，32bit为单位
                            IN UINT8 *data               // 写入的数据缓存, 大小int32_size * 4
                            );



#endif // end of ITS_NETWORK_C


#ifdef __cplusplus
}
#endif

#endif  // end of RS485_WIN_H


