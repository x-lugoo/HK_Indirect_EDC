
/****************************************************************************
NAME
    manage.h - ��������ཻ��ģ��

DESCRIPTION

REFERENCE

MODIFICATION SHEET:
    MODIFIED   (YYYY.MM.DD)
    shengjx     2006.10.25      - created
****************************************************************************/

#ifndef _MANAGE_H
#define _MANAGE_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
int SelectAppNum(uchar ucIncluMngr, uchar ucForEventMode, uchar *pucAppNum);
void UnLockTerminal(void);
void LockTerm(void);
void ClearAllRecord(void);
void ClearConfig(void);
void ClearPassword(void);
void ClearReversal(void);
void ClearRecord(uchar ucAcqKey);
#ifdef SUPPORT_TABBATCH
void ClearTabBatchRecord(uchar ucAcqKey); 
void AutoRemoveExpiredAuth(void); 
void ViewAuthList(void);
void RePrnSpecAuth(void);
#endif
void EnableProc(void);
void DoClear(void);
void ViewTotal(void);
void ViewTranList(void);
void ViewSpecList(void);
void PrnLastTrans(void);
void RePrnSpecTrans(void);
void PrnTotal(void);
void RePrnSettle(void);
void PrintEmvErrLog(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	// _MANAGE_H

// end of file
