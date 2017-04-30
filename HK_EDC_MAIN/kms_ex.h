/****************************************************************************
ProTimsLib

�ٸ����������(����)���޹�˾

�޸���ʷ��
v1.0.0.0_120611    2012��6��11��    Ф����

�ļ�����:
ProTimsDef.h					 ProTimsLib��Ҫ���壬�������ݽṹ�������룬ȫ�ֱ��������
ProTims_SXX_COMM.h				 Sϵ�е�ͨѶʵ��
ProTims_PXX_COMM.h				 Pϵ�е�ͨѶʵ��
ProTims_comm.h			    	 ��Ҫʵ�ִ���
ProTimsEx.h				         ProTimsLib����ӿ����߼����̣�include���ļ�����ʹ��
appLib.h                         Ӧ�ñ�׼�⣬����������Ĳ��ֺ�����PubGetString
****************************************************************************/

#ifndef PROTIMS_H_
#define PROTIMS_H_

#include "kms_comm.h"


int KmsRemoteLoadApp(const T_INCOMMPARA *ptCommPara);   

//////////////////////////////////////////////////////////////////////////
// New API

/****************************************************************************
���ܣ� 	    ��ʼ��ProTimsԶ�����صĵ��ã����ù��ܲ���
�������	crtlBit
				PROTIMS_RESUME_DOWNLOAD		0x0001	// �Ƿ�֧�ֶϵ�����
				PROTIMS_UPDATE_INSTANT		0x0002	// �Ƿ����̸������ص��ļ�
				PROTIMS_SET_TIME			0x0004	// �Ƿ�����POSʱ��ΪProTimsϵͳʱ��
				PROTIMS_LOADTYPE_NEWVER		0x0008	// 1, T_INCOMMPARA->bLoadTypeȫ�������ã� 0��ֻ�к���λ������   ��Ϊ�����ϰ汾��RemoteLoadApp��											
�������	��
���أ�  	0 �ɹ�  ����ʧ��
****************************************************************************/
int KmsInit();

/****************************************************************************
���ܣ� 	    ProTimsԶ������
�������	ptInPara
�������	��
���أ�  	0 �ɹ�  ����ʧ��
****************************************************************************/
int KmsDownload(T_INCOMMPARA *ptInPara);


/****************************************************************************
���ܣ� 	    ��ȡProTims�������ϸ��Ϣ
�������	��
�������	pLastError����������Ϊ2��int���飬����
            pLastError[0]Ϊ����ĺ�������ϸ���������PROTIMS_ERROR_CODE����
			pLastError[1]Ϊ�ĺ����ķ����룬��ϸ���������API����ֲ�
���أ�  	��
****************************************************************************/

void KmsGetLastErr(int* pLastError);						// Get last error code

/****************************************************************************
���ܣ� 	    ����ProTims��ʾ���Ե�����
�������	
	KindOfLang
		PROTIMS_PROMPT_EN,   
		PROTIMS_PROMPT_CN,

�������	��
���أ�  	0 success -1 failed
****************************************************************************/

int KmsSetLanguage(int LangType);

/****************************************************************************
���ܣ� 	   ����������Դ
�������	��

�������	��
���أ�  	0 success -1 failed
****************************************************************************/

int KmsLoadLanguage(); 


/****************************************************************************
���ܣ� 	    �õ�key��Ӧ��value
�������	pszKey 
�������	iSize 	pszValue ��Ӧ�ڴ��С
�������	pszValue
���أ�  	0 success
****************************************************************************/

int KmsReadVar( const char *InKey, char *OutValue,int iLen);

/****************************************************************************
���ܣ� 	    ����key value ��ֵ��
�������	pszKey,pszValue
�������	��
���أ�  	0 success
****************************************************************************/

int KmsWriteVar(const char *InKey, const char *InValue);

/****************************************************************************
���ܣ� 	    ����ȱʡ����
�������	��
�������	��
���أ�  	0 success
****************************************************************************/
static int ParaTransformers(T_CSCOMMPARA *pComPara, T_INCOMMPARA *ptOutPara);
static int LoadDownloadPara(T_CSCOMMPARA *pComPara);
static int DisplayErrorMessage(int errCode);
static void DispTitle(void *pTitle);
static int GetRemoteLoadVer(unsigned char *Ver);

int KmsSetDefaultCfg(void);
int KmsRemoteLoadApp(const T_INCOMMPARA *ptCommPara);   

int KmsMain();
#endif








