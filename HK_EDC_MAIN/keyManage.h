/*
*===========================================================================
*              PAX CORPORATION PROPRIETARY INFORMATION
*  This software is supplied under the terms of a license agreement or
*  nondisclosure agreement with PAX Corporation and may not be copied
*  or disclosed except in accordance with the terms in that agreement.
*      Copyright(c) 2016? PAX Corporation. All rights reserved.
*
*  Description: implement UnionPay International key management function.
*               KeyDownload() - TMK download
*               TerminalSignOn() -sign on, TPK download
*
*  Revision History:
*  Date                  Author            Action
*  20161104              Richard           Created
*===========================================================================
*/




#ifndef _KEY_MANAGE_H_
#define _KEY_MANAGE_H_

#include "global.h"


#define CUP_TMK_ID  7
#define CUP_TPK_ID  7

#define KEY_TYPE_RSA   0
#define KEY_TYPE_TMK1  1  //down TMK
#define KEY_TYPE_TMK2  2  //active TMK
#define KEY_TYPE_TPK   3 



/************************************************************************/
/* RSA��Կ���ز�����Ϣ                                                  */
/* ken add for key download for HK CUP                                  */
/************************************************************************/
typedef struct
{
    unsigned char PubKeyRID[5 + 1];                             //��ԿRID
    unsigned char PubKeyIndex;                                  //��Կ����
    unsigned char PubKeyModule[248 + 1];                //��Կģ
    unsigned char PubKeyExponential[3 + 1];             //��Կָ��
    unsigned char EncryptTMK[128 + 1];                          //TMK����
    unsigned char TMKCheckValue[4 + 1];                         //TMKУ��ֵ
    unsigned char RadomEncryptKey[128 + 1];             //�����Կ����
    unsigned char RadomEncryptKeyCheck[4 + 1];          //�����ԿУ��ֵ
} RSA_KEY_DOWN_INFO;


extern void KeyDownload(void);
extern void TerminalSignOn(void);



#endif





