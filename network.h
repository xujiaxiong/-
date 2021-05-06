/* network.h  - UDP network Communication extern head file for windows */

/* modification history
-----------------------

03A 2020/04/19 20:33:00  ��RS485.h�޸Ķ���
02a 2019/6/27  11:37:25  �޸�ΪUDPͨ�ŷ�ʽ
01b 2016/08/09 13:31:23 ֡��ʽ�޸ĺ���Ӧ�޸�
01a 2016/6/22 10:42:02  create by frank
*/

/* ����ͨ��Э��ͷ�ļ� */


/*  its������̫��ͨ��Э���ʽ
master send : 
    msg_len | protocol | seq | nc_code | func_code | reply | addr | size | data 

slave reply:
    msg_len | protocol | seq | nc_code | func_code | error | addr | size | data

����dataΪ���ݾ��������n�ֽ���, ÿ���ֶζ���4�ֽڡ�

����:
protocol:  0x474f4c59
seq: 0x54454300
nc_code: 0x4a494e59

func_code: 
    0x0001	��ȡ�����ַ����
    0x1001	д�����ַ����
*/



#ifndef ITS_NETWORK_WIN_H
#define ITS_NETWORK_WIN_H


#ifdef __cplusplus
extern "C" {
#endif


#include "golytec.h"


#define      DEFAULT_TIMEOUT		5000		
#define      MAX_FRAME_SIZE         1024            // ����һ֡���ֽ���

#define      NET_SOCKET_MAX_NUM        8            // ʹ�õ�socketͨ�Ÿ���



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
                            IN int addr,                // ��ȡ���������������ĵ�ַ
                            IN int int32_size,         // ��ȡ�����ݴ�С��32bitΪ��λ
                            OUT UINT8 *data,              // ��ȡ�����ݻ���, ��С INT32_size * 4
                            OUT int *act_len            // ʵ�ʶ�ȡ�����ֽ���
                            );

extern int network_write_data_s
                            (
                            IN int addr,                // д����������������ĵ�ַ
                            IN int int32_size,         // д������ݴ�С��32bitΪ��λ
                            IN UINT8 *data               // д������ݻ���, ��Сint32_size * 4
                            );



#endif // end of ITS_NETWORK_C


#ifdef __cplusplus
}
#endif

#endif  // end of RS485_WIN_H


