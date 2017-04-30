#include <posapi.h>

typedef int (*cTMSStart)(T_INCOMMPARA *ptInPara, int *handle);	    // 3?��??����?��?��?����????����
typedef int (*cTMSReset)(int handle);	//
typedef int (*cTMSSendPack) (int handle, unsigned char *buff, int SndLen);	// ����?��
typedef int (*cTMSRecvByte) (int handle, unsigned char *ch, int usTimeOut);	// ��??��?����?
typedef int (*cTMSExitClose)(int handle);				            // ��?3?
typedef int (*cTMSNetRecv)(int socket, void *buf, int size, int flags);	// ?����??��?����?

extern cTMSStart     pcTMSStart    ;
extern cTMSReset     pcTMSReset    ;
extern cTMSSendPack  pcTMSSendPack ;
extern cTMSRecvByte  pcTMSRecvByte ;
extern cTMSExitClose pcTMSExitClose;
extern cTMSNetRecv   pcTMSNetRecv  ;
