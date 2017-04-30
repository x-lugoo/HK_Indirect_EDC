/*****************************************************/
/* ClssApi_Wave.h                                    */
/* Define the Application Program Interface          */
/* of VISA payWave for all PAX Readers               */
/* Created by Liuxl at July 30, 2009                 */
/*****************************************************/

#ifndef _CLSS_PAYWAVE_LIB_H
#define _CLSS_PAYWAVE_LIB_H

#include "CL_common.h"



//��Կ��Ӧ�ù���������
int  Clss_CoreInit_Wave(void);
int Clss_ReadVerInfo_Wave(char *paucVer);
int  Clss_GetTLVData_Wave(ushort Tag, uchar *DtOut, int *nDtLen);
int  Clss_SetTLVData_Wave(ushort usTag, uchar *pucDtIn, int nDtLen);
 
//��Կ��Ӧ�ù��������� 
int  Clss_AddCAPK_Wave(EMV_CAPK  *capk );
int  Clss_GetCAPK_Wave(int Index, EMV_CAPK  *capk );
int  Clss_DelCAPK_Wave(unsigned char KeyID, unsigned char *RID);
void Clss_DelAllCAPK_Wave(void);

// added by liuxl 20070710 ���޷���Ӧ�ó����ƹ�֤���б���������ӽӿ�
int  Clss_AddRevocList_Wave(EMV_REVOCLIST *pRevocList);
int  Clss_DelRevocList_Wave(unsigned char ucIndex, unsigned char *pucRID);
void Clss_DelAllRevocList_Wave(void);


// �����������
int Clss_SetReaderParam_Wave(Clss_ReaderParam *ptParam);
int Clss_GetReaderParam_Wave(Clss_ReaderParam *ptParam);

void Clss_SetRdSchemeInfo_Wave(uchar ucNum, Clss_SchemeID_Info *pInfo);
void Clss_GetSchemeInfo_Wave(uchar *pNum, Clss_SchemeID_Info *pInfo);

// �Զ�������������
int  Clss_SetEMVUnknowTLVData_Wave(unsigned short usTag, unsigned char *pDatIn, int nLen);

//����(�ر�)EMV��CORE�ĵ���״̬
void Clss_SetDebug_Wave(int EnableFlag);
void Clss_GetICCStatus_Wave(unsigned char *SWA, unsigned char *SWB);

 
//���״���������
int Clss_SetVisaAidParam_Wave(Clss_VisaAidParam *ptParam);
int Clss_SetTransData_Wave(Clss_TransParam *ptTransParam, Clss_PreProcInterInfo *ptInfo);
int Clss_SetFinalSelectData_Wave(uchar *paucDtIn, int nDtLen);
int Clss_Proctrans_Wave(uchar *pucTransPath, uchar *pucACType);


// only for qVSDC and wave2
int Clss_CardAuth_Wave(uchar *pucACType, uchar *pucDDAFailFlg);

// all schemeid
int Clss_GetCvmType_Wave(uchar *pucType);


// MSD track data
int Clss_nGetTrack1MapData_Wave(uchar *pTrackData, int *pLen); // for MSD and wave2
int Clss_nGetTrack2MapData_Wave(uchar *pTrackData, int *pLen); // only for MSD

#endif


