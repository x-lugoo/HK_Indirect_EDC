/****************************************************************************
NAME
	SxxCom.h - ����ģ���װ����

DESCRIPTION

REFERENCE

MODIFICATION SHEET:
	MODIFIED   (YYYY.MM.DD)

****************************************************************************/

#ifndef _SWIRELESS_H
#define _SWIRELESS_H

#ifndef uchar
#define uchar   unsigned char
#endif
#ifndef uint
#define uint    unsigned int
#endif
#ifndef ushort
#define ushort  unsigned short
#endif
#ifndef ulong
#define ulong   unsigned long
#endif

#ifndef TRUE
	#define TRUE	1
	#define FALSE	0
#endif



/****************************************************************************
 ��    �ܣ�	TCP/IP �������ݡ�GPRS/CDMA/PPP/LAN/WIFI ����ʹ�á�
 ���������
			psTxdData��ָ�����ݻ�����
			uiDataLen�����ݳ���
			iTimeout�����ͳ�ʱʱ�䡣����3�밴3������
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SxxTcpTxd(uchar *psTxdData, ushort uiDataLen, ushort uiTimeOutSec);


/****************************************************************************
 ��    �ܣ�	TCP/IP �������ݡ�GPRS/CDMA/PPP/LAN/WIFI ����ʹ�á�
 ���������
			psRxdData��ָ�����ݽ��ջ�����
			uiExpLen���������ɽ��յ�������ݳ���
			iTimeout�����ճ�ʱʱ�䡣����3�밴3������
			puiOutLen��ʵ���յ����ݵĳ���
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SxxTcpRxd(uchar *psRxdData, ushort uiExpLen, ushort uiTimeOutSec, ushort *puiOutLen);


/****************************************************************************
 ��    �ܣ�	TCP/IP �ر�socket��GPRS/CDMA/PPP/LAN/WIFI ����ʹ�á�
 ���������
			��
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SxxTcpOnHook(void);


/****************************************************************************
 Function:		Sϵ�е�DHCPִ��
 Param In:
	ucForceStart	bool,�Ƿ�ǿ��ִ��
	ucTimeOutSec	��ʱʱ��
 Param Out:		none
 Return Code:
	0			OK
	other		fail
****************************************************************************/
int SxxDhcpStart(uchar ucForceStart, uchar ucTimeOutSec);


/****************************************************************************
 Function:		Sϵ��LAN��TCP����
 Param In:
	pstTcpPara����ʹ�õ�TCPIP����
 Param Out:		none
 Return Code:
	0			OK
	other		fail
****************************************************************************/
int SxxLANTcpDial(TCPIP_PARA *pstTcpPara);


/****************************************************************************
 ��    �ܣ�	��ʼ������ģ�飬������ֻ�����һ�Ρ�
 ���������
			pstWlPara�����ڳ�ʼ���Ĳ���  
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SXXWlInit(WIRELESS_PARAM *pstWlPara);


/****************************************************************************
 ��    �ܣ�	���ж�PPP��·�Ƿ���ͨ����û����ͨ�Ƚ���PPP���ӣ��ɹ����ٽ���TCP��
            �ӣ�������ͨ��ֱ�ӽ���TCP���ӡ�
 ���������
			pstWlPara�����ڳ�ʼ���Ĳ���
 			iTimeOut������PPP����ʱ�ĳ�ʱʱ�䣬����TCP����ʱ���ã���λ���롣
			iAliveInterval��PPP��·���ּ����ʱ�䣬��λ���롣
			ucPredial���Ƿ�Ԥ����
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SXXWlDial(WIRELESS_PARAM *pstWlPara, int iTimeOut, int iAliveInterval, uchar ucPredial);


/****************************************************************************
 ��    �ܣ�	�������ݡ�
 ���������
			psTxdData�������͵����ݡ�
			uiDataLen�����������ݵĳ��ȡ�
			usTimeOut���������ݳ�ʱʱ�䣬��λ���롣
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SXXWlSend(uchar *psTxdData, ushort usDataLen, ushort usTimeOut);


/****************************************************************************
 ��    �ܣ�	�������ݡ�
 ���������
			uiExpLen���������յ�������ݳ��ȡ�
			uiTimeOut���ȴ��������ݵĳ�ʱʱ�䣬��λ���롣
 ����������
			psRxdData�����յ������ݡ�
			puiOutLen�����յ����ݵĳ��ȡ�
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SXXWlRecv(uchar *psRxdData, ushort usExpLen, ushort usTimeOut, ushort *pusOutLen);


/****************************************************************************
 ��    �ܣ�	�ر�TCP���ӡ�
 ���������
			��  
 ����������
			��
 �� �� �룺	0   �ɹ�
            <0  ʧ��
****************************************************************************/
int SXXWlCloseTcp(void);


/****************************************************************************
 ��    �ܣ�	�ر�PPP��·��
 ���������
			��  
 ����������
			��
 �� �� �룺	��
****************************************************************************/
void SXXWlClosePPP(void);


/****************************************************************************
 ��    �ܣ�	��ʾ�ź�ǿ�ȡ�
 ���������
			��  
 ����������
			��
 �� �� �룺	��
****************************************************************************/
void SXXWlDispSignal(void);
void InitSSL(void);  //Gillian 2016-8-29 
//Gillian 2016-8-19 

#ifdef PP_SSL
#define CONNECTONE_FILE "TCPIP"     //V8.03.15 jiaxf added ssl connect // 8.03.15 Build111

int SSL_LANTcpDial(TCPIP_PARA *pstTcpPara, char* hostCN);
//static int net_open(char *remote_addr, unsigned short remote_port, unsigned short local_port, long flag);
//static int net_send(int socket, uchar *psTxdData, int uiDataLen);
//static int net_recv(int socket, uchar *psRxdData, int uiExpLen);
//static int net_close(int net_hd);
#endif
#define NET_ERR_CA_MISS         -202    //HASE GENERIC BUILD111
#define NET_ERR_CN_NOT_MATCH		-150

#endif
