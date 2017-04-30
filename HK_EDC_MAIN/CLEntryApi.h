/*****************************************************/
/* ClEntryApi.h                                      */
/* Define the Application Program Interface          */
/* of Entry Point for all PAX Readers                */
/* Created by Liuxl at July 30, 2009                 */
/*****************************************************/

#ifndef _CLSS_ENTRY_LIB_H
#define _CLSS_ENTRY_LIB_H
 
#include "cl_common.h"

 

// ÿ��AID��Ӧ�Ĳ���,���ڽ���Ԥ����
typedef struct CLSS_PREPROCINFO
{
	ulong ulTermFLmt;// 0xDF85
	ulong ulRdClssTxnLmt;// 0xDF00
	ulong ulRdCVMLmt;// 0xDF01 -vis 0xDF61 -jcb
	ulong ulRdClssFLmt;// 0xDF02 -vis 0xDF62 -jcb

	uchar aucAID[17];  //     
	uchar ucAidLen; //
	
	uchar ucKernType; // 0xDF87 ���������AID ����ѭ���ں�����

	// payWave
	uchar  ucCrypto17Flg;// 0xDF82
	uchar   ucZeroAmtNoAllowed;// 0xDF83      // 0-����Ȩ���=0,��TTQҪ����������, 1-����Ȩ���=0, ���ڲ�qVSDC��֧�ֱ�־��λ
	uchar   ucStatusCheckFlg;// 0xDF81   // �������Ƿ�֧��״̬���
    uchar   aucReaderTTQ[5]; // 9F66     // �ն˽������ܣ�����VISA/PBOC�У�tag =9F66
	
	// common
	uchar ucTermFLmtFlg; 
	uchar ucRdClssTxnLmtFlg; 
	uchar ucRdCVMLmtFlg;   
	uchar ucRdClssFLmtFlg; 	 
	
	uchar aucRFU[2];
}Clss_PreProcInfo;


int  Clss_ReadVerInfo_Entry(char *paucVerOut);
int Clss_CoreInit_Entry(void);
void Clss_GetICCStatus_Entry(unsigned char *SWA, unsigned char *SWB);
void Clss_SetDebug_Entry(int EnableFlag);

int Clss_SetPreProcInfo_Entry(Clss_PreProcInfo *ptPreProcInfoIn);
int Clss_PreTransProc_Entry(Clss_TransParam *pstTransParam);
int Clss_AppSlt_Entry(int Slot, int ReadLogFlag);
int Clss_FinalSelect_Entry(uchar *pucKernType, uchar *pucDtOut, int *pnDtLen);

int Clss_GetPreProcInterFlg_Entry(Clss_PreProcInterInfo *ptInfo);

// 20090721 
void Clss_DelAllAidList_Entry(void);
int Clss_DelAidList_Entry(uchar  *pucAID, uchar  ucAidLen);
int Clss_AddAidList_Entry(uchar *pucAID, uchar ucAidLen, uchar ucSelFlg, uchar ucKernType); 
int Clss_DelCurCandApp_Entry(void);
int Clss_GetFinalSelectData_Entry(uchar *paucDtOut, int *pnDtLen);

// 20090902
void Clss_DelAllPreProcInfo(void);
int Clss_DelPreProcInfo_Entry(uchar  *pucAID, uchar  ucAidLen);
#endif


