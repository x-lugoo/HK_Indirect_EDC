
#include "global.h"

/********************** Internal macros declaration ************************/
/********************** Internal structure declaration *********************/
/********************** Internal functions declaration *********************/
/********************** Internal variables declaration *********************/
static uchar FILE_SYS_PARAM[]  = "SysParam.dat";		// ϵͳ���ò����ļ�
static uchar FILE_SYS_CTRL[]   = "SysCtrl.dat";			// ϵͳ���п��Ʋ����ļ�
static uchar FILE_TRAN_LOG[]   = "TranLog.dat";			// ������־�ļ�
static uchar FILE_EMV_STATUS[] = "EmvStatus.dat";		// ���һ��EMV����״̬
static uchar FILE_ERR_LOG[]    = "EmvErrLog.dat";		// ������־�ļ�
static uchar FILE_PASSWORD[]   = "PASSWORD";			/* �����ļ� */
static uchar EPS_EPSPARAM_FILE[] = "EPSHKPARAM";		// EPS�����ļ�

#ifdef SUPPORT_TABBATCH
static uchar FILE_TAB_BATCH[]  = "TabBatch.dat";
#endif
/********************** external reference declaration *********************/

/******************>>>>>>>>>>>>>Implementations<<<<<<<<<<<<*****************/

// ��ʼ��������־�ļ�
// Init transaction log file.
// The management of transaction log is quite different with old style.
int InitTranLogFile(void)
{
	int			fd, iWriteBytes, iCnt;
	TRAN_LOG	stTranLog;
#ifdef ENABLE_EMV
	EMV_ERR_LOG	stErrLog;
#endif

	fd = open((char *)FILE_TRAN_LOG, O_CREATE|O_RDWR);
	if( fd<0 )
	{
		PubTRACE0("InitTranLogFile");
		return ERR_FILEOPER;
	}

	memset(&stTranLog, 0, sizeof(stTranLog));
	for(iCnt=0; iCnt<MAX_TRANLOG; iCnt++)
	{
		iWriteBytes = PubFWriteN(fd, &stTranLog, sizeof(stTranLog));
		if( iWriteBytes!=(int)sizeof(stTranLog) )
		{
			PubTRACE0("InitTranLogFile");
			close(fd);
			return ERR_FILEOPER;
		}
	}
	close(fd);

	// init error log file
	fd = open((char *)FILE_ERR_LOG, O_CREATE|O_RDWR);
	if( fd<0 )
	{
		PubTRACE0("InitTranLogFile");
		return ERR_FILEOPER;
	}

#ifdef ENABLE_EMV
	memset(&stErrLog, 0, sizeof(stErrLog));
	for(iCnt=0; iCnt<MAX_ERR_LOG; iCnt++)
	{
		iWriteBytes = PubFWriteN(fd, &stErrLog, sizeof(stErrLog));
		if( iWriteBytes!=(int)sizeof(stErrLog) )
		{
			PubTRACE0("InitTranLogFile");
			close(fd);
			return ERR_FILEOPER;
		}
	}
	close(fd);
#endif

	return 0;
}


#ifdef SUPPORT_TABBATCH
int MS_InitTabBatchLogFile(void)
{
	int			fd, iWriteBytes, iCnt;
	TRAN_LOG	stTranLog;

    if (filesize((char *)FILE_TAB_BATCH)==MAX_TRANLOG*sizeof(stTranLog))
    {
        return 0;
    }

	fd = open((char *)FILE_TAB_BATCH, O_CREATE|O_RDWR);
	if( fd<0 )
	{
		PubTRACE0("MSSCB_InitTabBatchLogFile_1");
		return ERR_FILEOPER;
	}

	memset(&stTranLog, 0, sizeof(stTranLog));
	for(iCnt=0; iCnt<MAX_TRANLOG; iCnt++)
	{
		iWriteBytes = PubFWriteN(fd, &stTranLog, sizeof(stTranLog));
		if( iWriteBytes!=(int)sizeof(stTranLog) )
		{
			PubTRACE0("MSSCB_InitTabBatchLogFile_2");
			close(fd);
			return ERR_FILEOPER;
		}
	}
	close(fd);

	return 0;
}
#endif

// ��ȡϵͳ����
int LoadSysParam(void)
{
	int		iRet;

	iRet = PubFileRead(FILE_SYS_PARAM, 0L, &glSysParam, sizeof(SYS_PARAM));
	if( iRet!=0 )
	{
		PubTRACE0("LoadSysParam()");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����ϵͳ����
int SaveSysParam(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_SYS_PARAM, 0L, &glSysParam, sizeof(SYS_PARAM));
	if( iRet!=0 )
	{
		PubTRACE0("SaveSysParam");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����EDC����
int SaveEdcParam(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_SYS_PARAM,
						OFFSET(SYS_PARAM, stEdcInfo),
						&glSysParam.stEdcInfo,
						sizeof(glSysParam.stEdcInfo));
	if( iRet!=0 )
	{
		PubTRACE0("SaveSysParam");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����ϵͳ����
int SavePassword(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_SYS_PARAM,
						OFFSET(SYS_PARAM, sPassword),
						glSysParam.sPassword,
						sizeof(glSysParam.sPassword));
	if( iRet!=0 )
	{
		PubTRACE0("SavePassword");
		SysHalt();
		return ERR_FILEOPER;
	}

	return SyncPassword();
}

// �ж�ϵͳ�����ļ��Ƿ����
int ExistSysFiles(void)
{
	if ((fexist((char *)FILE_SYS_PARAM)<0) ||
		(fexist((char *)FILE_SYS_CTRL)<0) ||
		(fexist((char *)FILE_TRAN_LOG)<0) )
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

// �ж�ϵͳ�����ļ���С
int ValidSysFiles(void)
{
	if ((fexist((char *)FILE_SYS_PARAM)<0) ||
		(filesize((char *)FILE_SYS_PARAM)!=sizeof(SYS_PARAM)) )
	{
		return FALSE;
	}
	if ((fexist((char *)FILE_SYS_CTRL)<0) ||
		(filesize((char *)FILE_SYS_CTRL)!=sizeof(SYS_CONTROL)) )
	{
		return FALSE;
	}
	if ((fexist((char *)FILE_TRAN_LOG)<0) ||
		(filesize((char *)FILE_TRAN_LOG)!=MAX_TRANLOG*sizeof(TRAN_LOG)) )
	{
		return FALSE;
	}
	return TRUE;
}

void RemoveSysFiles(void)
{
	remove((char *)FILE_SYS_PARAM);
	remove((char *)FILE_SYS_CTRL);
	remove((char *)FILE_TRAN_LOG);
}

// ��ȡȫ�����п��Ʋ���
// Load the whole "glSysCtrl"
int LoadSysCtrlAll(void)
{
	int		iRet;

	iRet = PubFileRead(FILE_SYS_CTRL, 0L, &glSysCtrl, sizeof(SYS_CONTROL));
	if( iRet!=0 )
	{
		PubTRACE0("LoadSysCtrlAll");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����ȫ�����п��Ʋ���(����ʹ��,�ȽϺ�ʱ)
// Save the whole "glSysCtrl" to file (very time consuming.)
int SaveSysCtrlAll(void)
{
	int		iRet;

	// about 60K bytes
	iRet = PubFileWrite(FILE_SYS_CTRL, 0L, &glSysCtrl, sizeof(SYS_CONTROL));
	if( iRet!=0 )
	{
		PubTRACE0("SaveSysCtrlAll");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����������п��Ʋ���(STAN/Invoice No/....)
// Save most basic system-control parameter. part of "glSysCtrl"
int SaveSysCtrlBase(void)
{
	int		iRet;

	// about 1.5K bytes
	iRet = PubFileWrite(FILE_SYS_CTRL, 0L, &glSysCtrl, LEN_SYSCTRL_BASE);
	if( iRet!=0 )
	{
		PubTRACE0("SaveSysCtrlBase");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// save basic information & reversal information
int SaveSysCtrlNormal(void)
{
	int		iRet;

	// about 20K bytes
	iRet = PubFileWrite(FILE_SYS_CTRL, 0L, &glSysCtrl, LEN_SYSCTRL_NORMAL);
	if( iRet!=0 )
	{
		PubTRACE0("SaveSysCtrlNormal");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����56��(ֻ�洢��ǰ�յ��ж�Ӧ��)
// Save bit56. (for HongKong only)
int SaveField56(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_SYS_CTRL,
						OFFSET(SYS_CONTROL, stField56[glCurAcq.ucIndex]),
						&glSysCtrl.stField56[glCurAcq.ucIndex],
						sizeof(EMV_FIELD56));
	if( iRet!=0 )
	{
		PubTRACE0("SaveField56");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ���������Ϣ(ֻ�洢��ǰ�յ��ж�Ӧ��)
// Save reversal data of current acquirer.
int SaveRevInfo(uchar bSaveRevInfo)
{
	int			iRet;
	STISO8583	*pstRevPack;

	if( bSaveRevInfo )	// ���������Ϣ
	{
		if( !ChkIfNeedReversal() )
		{
			return 0;
		}

		glSysCtrl.stRevInfo[glCurAcq.ucIndex].bNeedReversal = TRUE;
		pstRevPack = &glSysCtrl.stRevInfo[glCurAcq.ucIndex].stRevPack;
		glSysCtrl.stRevInfo[glCurAcq.ucIndex].uiEntryMode = glProcInfo.stTranLog.uiEntryMode;
		memcpy(pstRevPack, &glSendPack, sizeof(STISO8583));

		// �������ײ�������ŵ���Ϣ
		memset(pstRevPack->szTrack1, 0, sizeof(pstRevPack->szTrack1));
		//Build 1.00.0110
		if (ChkIfICBC() || ChkIfWLB())
		{
			;
		}
		else
			memset(pstRevPack->szTrack2, 0, sizeof(pstRevPack->szTrack2));
		memset(pstRevPack->szTrack3, 0, sizeof(pstRevPack->szTrack3));
		sprintf((char *)pstRevPack->szPan,     "%.*s", LEN_PAN,      glProcInfo.stTranLog.szPan);
		sprintf((char *)pstRevPack->szExpDate, "%.*s", LEN_EXP_DATE, glProcInfo.stTranLog.szExpDate);
		iRet = PubFileWrite(FILE_SYS_CTRL,
							OFFSET(SYS_CONTROL, stRevInfo[glCurAcq.ucIndex]),
							&glSysCtrl.stRevInfo[glCurAcq.ucIndex],
							sizeof(REVERSAL_INFO));
	}
	else	// ���������Ϣ
	{
		if( !glSysCtrl.stRevInfo[glCurAcq.ucIndex].bNeedReversal )
		{
			return 0;
		}
		glSysCtrl.stRevInfo[glCurAcq.ucIndex].bNeedReversal = FALSE;
		iRet = PubFileWrite(FILE_SYS_CTRL,
							OFFSET(SYS_CONTROL, stRevInfo[glCurAcq.ucIndex].bNeedReversal),
							&glSysCtrl.stRevInfo[glCurAcq.ucIndex].bNeedReversal,
							1);
	}
	if( iRet!=0 )
	{
		PubTRACE0("SaveRevInfo");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// save reprint settle information
int SaveRePrnStlInfo(void)
{
	int		iRet;

	// about 40K bytes
	iRet = PubFileWrite(FILE_SYS_CTRL,
						OFFSET(SYS_CONTROL, stRePrnStlInfo),
						&glSysCtrl.stRePrnStlInfo,
						sizeof(REPRN_STL_INFO));
	if( iRet!=0 )
	{
		PubTRACE0("SaveStlInfo");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ��ȡһ��������־
// Load one transaction log from file
int LoadTranLog(void *pstLog, ushort uiIndex)
{
	int		iRet;

	PubASSERT( glSysCtrl.sAcqKeyList[uiIndex]!=INV_ACQ_KEY );
	iRet = PubFileRead(FILE_TRAN_LOG, (long)(sizeof(TRAN_LOG)*uiIndex),
						pstLog, sizeof(TRAN_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("LoadTranLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// ����һ��������־
// update one transaction log
int UpdateTranLog(void *pstLog, ushort uiIndex)
{
	int		iRet;

	PubASSERT( glSysCtrl.sAcqKeyList[uiIndex]!=INV_ACQ_KEY );
	iRet = PubFileWrite(FILE_TRAN_LOG, (long)(sizeof(TRAN_LOG)*uiIndex),
						pstLog, sizeof(TRAN_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("UpdateTranLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

#ifdef SUPPORT_TABBATCH
int LoadTabBatchLog(void *pstLog, ushort uiIndex)
{
	int		iRet;

	PubASSERT( glSysCtrl.astAuthRecProf[uiIndex].ucAcqKey!=INV_ACQ_KEY );
	iRet = PubFileRead(FILE_TAB_BATCH, (long)(sizeof(TRAN_LOG)*uiIndex),
						pstLog, sizeof(TRAN_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("LoadTabBatchLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}
#endif


#ifdef SUPPORT_TABBATCH
int UpdateTabBatchLog(void *pstLog, ushort uiIndex)
{
	int		iRet;

	PubASSERT( glSysCtrl.astAuthRecProf[uiIndex].ucAcqKey!=INV_ACQ_KEY );
	iRet = PubFileWrite(FILE_TAB_BATCH, (long)(sizeof(TRAN_LOG)*uiIndex),
						pstLog, sizeof(TRAN_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("UpdateTabBatchLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}
#endif

// �洢������־�㷨(�������ʱ������������ɾ�����׼�¼Ҳֻ���޸�������)
// ������־�ļ��Ĵ洢����: 1.�洢ACQ/Issuer Key������ 2.���׼�¼
// ����ϵͳ��Ҫ���������ļ�ϵͳ��������������������ݿ�������ύ��ʽ:
// Step 1: ��¼��Ҫ��¼����Ϣ����������Ϣ�����׼�¼�ȣ�
// Step 2: �������ʵ�ʵ���־��Ϣ��¼
// ����һ��������־

// Algorithm of storing log
// There are 3 places to be store/update when save/update/delete a transaction:
//   1. log data            : saved in log file
//   2. Acq key of each log : saved in glSysCtrl.stAcqKeyList[]
//   3. Iss key of each log : saved in glSysCtrl.sIssuerKeyList[]
// These require to modify 2 files. To avoid exception when writing, it will divided to 3 steps:
//   step 1: write data to "glSysCtrl.stWriteInfo", and set "glSysCtrl.stWriteInfo.bNeedSave" to "TRUE"
//   step 2: write data to 2 files accordingly.
//   step 3: reset the "glSysCtrl.stWriteInfo.bNeedSave" to "FALSE".
// Unless the flag is reset, the applicaion will retry the step 2 and step 3 above.
int SaveTranLog(void *pstLog)
{
	int		iRet, iCnt;

	for(iCnt=0; iCnt<MAX_TRANLOG; iCnt++)
	{
		if( glSysCtrl.sAcqKeyList[iCnt]==INV_ACQ_KEY )
		{
			break;
		}
	}
	if( iCnt>=MAX_TRANLOG )
	{
		PubTRACE0("SaveTranLog");
		return ERR_FILEOPER;
	}

	glSysCtrl.sAcqKeyList[iCnt]      = glCurAcq.ucKey;
	glSysCtrl.sIssuerKeyList[iCnt]   = glCurIssuer.ucKey;

	glSysCtrl.uiLastRecNoList[glCurAcq.ucIndex] = (ushort)iCnt;

	glSysCtrl.stWriteInfo.bNeedSave  = TRUE;
	glSysCtrl.stWriteInfo.ucAcqIndex = glCurAcq.ucIndex;
	glSysCtrl.stWriteInfo.uiRecNo    = (ushort)iCnt;
	memcpy(&glSysCtrl.stWriteInfo.stTranLog, pstLog, sizeof(TRAN_LOG));

	// Step 1: ��¼��Ҫ��¼����Ϣ����������Ϣ�����׼�¼�ȣ�
	// Save necessary data
	iRet = SaveSysCtrlBase();
	if( iRet<0 )
	{
		return iRet;
	}

	// Step 2: �������ʵ�ʵ���־��Ϣ��¼
	// Finish the record, and reset the flag to indicate finish.
	return RecoverTranLog();
}


#ifdef SUPPORT_TABBATCH
int SaveTabBatchLog(void *pstLog)
{
	int		iRet, iCnt;

	for(iCnt=0; iCnt<MAX_TRANLOG; iCnt++)
	{
		if( glSysCtrl.astAuthRecProf[iCnt].ucAcqKey==INV_ACQ_KEY )
		{
			break;
		}
	}
	if( iCnt>=MAX_TRANLOG )
	{
		PubTRACE0("SaveTabBatchLog");
		return ERR_FILEOPER;
	}

	glSysCtrl.astAuthRecProf[iCnt].ucAcqKey = glCurAcq.ucKey;
	PubAsc2Bcd(((TRAN_LOG *)pstLog)->szDateTime, 14, glSysCtrl.astAuthRecProf[iCnt].sDateBCD);

	glSysCtrl.stWriteInfo_TabBatch.bNeedSave  = TRUE;
	glSysCtrl.stWriteInfo_TabBatch.ucAcqIndex = glCurAcq.ucIndex;
	glSysCtrl.stWriteInfo_TabBatch.uiRecNo    = (ushort)iCnt;
	memcpy(&glSysCtrl.stWriteInfo_TabBatch.stTranLog, pstLog, sizeof(TRAN_LOG));

	// Step 1: ��¼��Ҫ��¼����Ϣ����������Ϣ�����׼�¼�ȣ�
	// Save necessary data
	iRet = SaveSysCtrlBase();
	if( iRet<0 )
	{
		return iRet;
	}

	// Step 2: �������ʵ�ʵ���־��Ϣ��¼
	// Finish the record, and reset the flag to indicate finish.
	return RecoverTabBatchLog();
}
#endif

// �ָ���־��¼�Ĳ�һ����
// Finish the save steps.
int RecoverTranLog(void)
{
	int		fd, iRet;

	if( !glSysCtrl.stWriteInfo.bNeedSave )
	{
		return 0;
	}

	fd = open((char *)FILE_TRAN_LOG, O_RDWR|O_CREATE);
	if( fd<0 )
	{
		PubTRACE0("RecoverTranLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	iRet = seek(fd, (long)(glSysCtrl.stWriteInfo.uiRecNo*sizeof(TRAN_LOG)), SEEK_SET);
	if( iRet<0 )
	{
		close(fd);
		SysHalt();
		return ERR_FILEOPER;
	}

	iRet = PubFWriteN(fd, &glSysCtrl.stWriteInfo.stTranLog, sizeof(TRAN_LOG));
	close(fd);
	if( iRet!=(int)sizeof(TRAN_LOG) )
	{
		PubTRACE0("RecoverTranLog");
		SysHalt();
		return iRet;
	}

	glCurAcq.ucIndex = glSysCtrl.stWriteInfo.ucAcqIndex;
	if( !(glSysCtrl.stWriteInfo.stTranLog.uiStatus & TS_NOSEND) )
	{
		SaveRevInfo(FALSE);
	}

	glSysCtrl.stWriteInfo.bNeedSave = FALSE;
	glSysCtrl.uiLastRecNo = glSysCtrl.stWriteInfo.uiRecNo;

  //build88S: bug fix reprint last trans
  glSysCtrl.uiRePrnRecNo = glSysCtrl.stWriteInfo.uiRecNo;
  //end 88S

	return SaveSysCtrlBase();
}


#ifdef SUPPORT_TABBATCH
int RecoverTabBatchLog(void)
{
	int		fd, iRet;

	if( !glSysCtrl.stWriteInfo_TabBatch.bNeedSave )
	{
		return 0;
	}

	fd = open((char *)FILE_TAB_BATCH, O_RDWR|O_CREATE);
	if( fd<0 )
	{
		PubTRACE0("RecoverTabBatchLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	iRet = seek(fd, (long)(glSysCtrl.stWriteInfo_TabBatch.uiRecNo*sizeof(TRAN_LOG)), SEEK_SET);
	if( iRet<0 )
	{
		close(fd);
		SysHalt();
		return ERR_FILEOPER;
	}

	iRet = PubFWriteN(fd, &glSysCtrl.stWriteInfo_TabBatch.stTranLog, sizeof(TRAN_LOG));
	close(fd);
	if( iRet!=(int)sizeof(TRAN_LOG) )
	{
		PubTRACE0("RecoverTabBatchLog");
		SysHalt();
		return iRet;
	}

	glCurAcq.ucIndex = glSysCtrl.stWriteInfo_TabBatch.ucAcqIndex;
	if( !(glSysCtrl.stWriteInfo_TabBatch.stTranLog.uiStatus & TS_NOSEND) )
	{
		SaveRevInfo(FALSE);
	}

	glSysCtrl.stWriteInfo_TabBatch.bNeedSave = FALSE;

	return SaveSysCtrlBase();
}
#endif

// ��ȡ���׼�¼����
// Retrieve total transaction record number.
ushort GetTranLogNum(uchar ucAcqKey)
{
	ushort	uiCnt, uiTranNum;

	if( ucAcqKey==ACQ_ALL )
	{
		for(uiTranNum=uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.sAcqKeyList[uiCnt]!=INV_ACQ_KEY )
			{
				uiTranNum++;
			}
		}
	}
	else
	{
		for(uiTranNum=uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.sAcqKeyList[uiCnt]==ucAcqKey )
			{
				uiTranNum++;
			}
		}
	}

	return uiTranNum;
}


#ifdef SUPPORT_TABBATCH
ushort GetTabBatchLogNum(uchar ucAcqKey)
{
	ushort	uiCnt, uiTranNum;

	if( ucAcqKey==ACQ_ALL )
	{
		for(uiTranNum=uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.astAuthRecProf[uiCnt].ucAcqKey!=INV_ACQ_KEY )
			{
				uiTranNum++;
			}
		}
	}
	else
	{
		for(uiTranNum=uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.astAuthRecProf[uiCnt].ucAcqKey==ucAcqKey )
			{
				uiTranNum++;
			}
		}
	}

	return uiTranNum;
}
#endif

// ������һ�ʽ����Ƿ��뵱ǰ�����ظ�,��������ʾ
// Check whether the last transaction is duplicated with current going-on one.
uchar AllowDuplicateTran(void)
{
	TRAN_LOG	stTranLog;
	ushort		uiTranNum;

	uiTranNum = GetTranLogNum(ACQ_ALL);
	if( uiTranNum==0 || glSysCtrl.uiLastRecNo>=MAX_TRANLOG )
	{
		return TRUE;
	}
	if( glSysCtrl.sAcqKeyList[glSysCtrl.uiLastRecNo]==INV_ACQ_KEY )
	{
		return TRUE;
	}

	memset(&stTranLog, 0, sizeof(TRAN_LOG));
	LoadTranLog(&stTranLog, glSysCtrl.uiLastRecNo);

	if( stTranLog.ucTranType!=glProcInfo.stTranLog.ucTranType                       ||
		strncmp((char *)stTranLog.szPan, (char *)glProcInfo.stTranLog.szPan, 19)!=0 ||
		memcmp(stTranLog.szAmount,       glProcInfo.stTranLog.szAmount,      12)!=0 ||
		memcmp(stTranLog.szTipAmount,    glProcInfo.stTranLog.szTipAmount,   12)!=0
		)
	{
		return TRUE;
	}

	ScrCls();
	DispTransName();
	PubDispString(_T("DUPLICATE? Y/N"), 4|DISP_LINE_LEFT);

	return !PubYesNo(USER_OPER_TIMEOUT);
}


// ���뽻����ˮ���Ի�ȡ�ý�������
// ��ڣ� ���ƵĽ���״̬
// ���ڣ� 0 ��ȡ�ɹ�
// Get invoice to retrieve the transaction record
int GetRecord(ushort uiStatus, void *pstOutTranLog)
{
	int			iRet;
	ushort		uiCnt;
	ulong		ulInvoiceNo;
	TRAN_LOG	*pstLog;

	pstLog = (TRAN_LOG *)pstOutTranLog;
	while( 1 )
	{
		iRet = InputInvoiceNo(&ulInvoiceNo);
		if( iRet!=0 )
		{
			return iRet;
		}

		for(uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.sAcqKeyList[uiCnt]==INV_ACQ_KEY )
			{
				continue;
			}

			memset(pstLog, 0, sizeof(TRAN_LOG));
			iRet = LoadTranLog(pstLog, uiCnt);
			if( iRet!=0 )
			{
				return iRet;
			}
			if( pstLog->ulInvoiceNo!=ulInvoiceNo )
			{
				continue;
			}
			if( ((pstLog->uiStatus) & 0x0F)<=uiStatus )
			{
				glProcInfo.uiRecNo = uiCnt;
				return 0;
			}
			else
			{
				DispStateText(pstLog->uiStatus);
				break;
			}
		}
		if( uiCnt>=MAX_TRANLOG )
		{
			ScrClrLine(2, 7);
			PubDispString(_T("INVALID TRACE"), 4|DISP_LINE_LEFT);
		}
		PubBeepErr();
		PubWaitKey(2);
	}
}
// ���뽻����ˮ���Ի�ȡ�ý�������
// ��ڣ� ���ƵĽ���״̬
// ���ڣ� 0 ��ȡ�ɹ�
// Get invoice to retrieve the transaction record
int GetRecordByInvoice(ulong ulInvoiceNo, ushort uiStatus, void *pstOutTranLog)
{
	int			iRet;
	ushort		uiCnt;
	TRAN_LOG	*pstLog;
	
	pstLog = (TRAN_LOG *)pstOutTranLog;
	for(uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
	{
		if( glSysCtrl.sAcqKeyList[uiCnt]==INV_ACQ_KEY )
		{
			continue;
		}
		
		memset(pstLog, 0, sizeof(TRAN_LOG));
		iRet = LoadTranLog(pstLog, uiCnt);
		if( iRet!=0 )
		{
			return iRet;
		}
		if( pstLog->ulInvoiceNo!=ulInvoiceNo )
		{
			continue;
		}
		if( ((pstLog->uiStatus) & 0x0F)<=uiStatus )
		{
			glProcInfo.uiRecNo = uiCnt;
			return 0;
		}
		else
		{
            ScrClrLine(2, 7);
            ScrPrint(0, 2, CFONT, "TRACE: %lu", ulInvoiceNo);
			DispStateText(pstLog->uiStatus);
			break;
		}
	}
	
	if( uiCnt>=MAX_TRANLOG )
	{
		ScrClrLine(2, 7);
		PubDispString(_T("INVALID TRACE"), 4|DISP_LINE_LEFT);
	}
	PubBeepErr();
	PubWaitKey(2);
    return ERR_NO_DISP;
}


#ifdef SUPPORT_TABBATCH
int GetAuthRecord(ushort uiStatus, void *pstOutTranLog)
{
	int			iRet;
	ushort		uiCnt;
	ulong		ulInvoiceNo;
	TRAN_LOG	*pstLog;

	pstLog = (TRAN_LOG *)pstOutTranLog;
	while( 1 )
	{
		iRet = InputInvoiceNo(&ulInvoiceNo);
		if( iRet!=0 )
		{
			return iRet;
		}

		for(uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.astAuthRecProf[uiCnt].ucAcqKey==INV_ACQ_KEY )
			{
				continue;
			}

			memset(pstLog, 0, sizeof(TRAN_LOG));
			iRet = LoadTabBatchLog(pstLog, uiCnt);
			if( iRet!=0 )
			{
				return iRet;
			}
			if( pstLog->ulInvoiceNo!=ulInvoiceNo )
			{
				continue;
			}
			if( ((pstLog->uiStatus) & 0x0F)<=uiStatus )
			{
				glProcInfo.uiRecNo = uiCnt;
				return 0;
			}
			else
			{
				DispStateText(pstLog->uiStatus);
				break;
			}
		}
		if( uiCnt>=MAX_TRANLOG )
		{
			ScrClrLine(2, 7);
			PubDispString(_T("INVALID TRACE"), 4|DISP_LINE_LEFT);
		}
		PubBeepErr();
		PubWaitKey(2);
	}
}

int GetAuthRecordByInvoice(ushort uiStatus, ulong ulInvoiceNo, void *pstOutTranLog)
{
	int			iRet;
	ushort		uiCnt;
	TRAN_LOG	*pstLog;

	pstLog = (TRAN_LOG *)pstOutTranLog;

	while( 1 )
	{
		for(uiCnt=0; uiCnt<MAX_TRANLOG; uiCnt++)
		{
			if( glSysCtrl.astAuthRecProf[uiCnt].ucAcqKey==INV_ACQ_KEY )
			{
				continue;
			}

			memset(pstLog, 0, sizeof(TRAN_LOG));
			iRet = LoadTabBatchLog(pstLog, uiCnt);

			if( iRet!=0 )
			{
				return iRet;
			}

			if( pstLog->ulInvoiceNo!=ulInvoiceNo )
			{
				continue;
			}

			if( ((pstLog->uiStatus) & 0x0F)<=uiStatus )
			{
				glProcInfo.uiRecNo = uiCnt;
				return 0;
			}
			else
			{
				DispStateText(pstLog->uiStatus);
				break;
			}
		}

		if( uiCnt>=MAX_TRANLOG )
		{
			ScrClrLine(2, 7);
			PubDispString(_T("INVALID TRACE"), 4|DISP_LINE_LEFT);
		}

		PubBeepErr();
		PubWaitKey(2);
	}
}
#endif

int WriteEPSPara(void *pPara)
{
	int		fd, iRet;

	fd = open((char *)EPS_EPSPARAM_FILE, O_RDWR|O_CREATE);
	if( fd<0 )
	{
		SysHalt();
		return ERR_FILEOPER;
	}

	iRet = write(fd, pPara, sizeof(EPS_MULTISYS_PARAM));
	close(fd);
	if( iRet!=sizeof(EPS_MULTISYS_PARAM) )
	{
		SysHalt();
		return ERR_FILEOPER;
	}
	return 0;
}

void CalcTotal(uchar ucAcqKey)
{
	uchar		ucAcqIndex, ucIssIndex, ucTranAct;
	uchar		szTotalAmt[12+1];
	ushort		uiIndex;
	TRAN_LOG	stLog;
	uchar szCurAcqIndex;//2015-1-8 save current acq index

	// clear all total information
	ClearTotalInfo(&glTransTotal);
	ClearTotalInfo(&glEdcTotal);
	for(ucAcqIndex=0; ucAcqIndex<glSysParam.ucAcqNum; ucAcqIndex++)
	{
		ClearTotalInfo(&glAcqTotal[ucAcqIndex]);
	}
	for(ucIssIndex=0; ucIssIndex<glSysParam.ucIssuerNum; ucIssIndex++)
	{
		ClearTotalInfo(&glIssuerTotal[ucIssIndex]);
	}

	// ���������acquirer��issuer,�Լ�edc��ͳ��
	// Calculate totals in terms of EDC, acquirer ans issuer.
	for(uiIndex=0; uiIndex<MAX_TRANLOG; uiIndex++)
	{
		if( glSysCtrl.sAcqKeyList[uiIndex]==INV_ACQ_KEY )
		{
			continue;
		}

		memset(&stLog, 0, sizeof(TRAN_LOG));
		LoadTranLog(&stLog, uiIndex);

		for(ucAcqIndex=0; ucAcqIndex<glSysParam.ucAcqNum; ucAcqIndex++)
		{
			if( glSysParam.stAcqList[ucAcqIndex].ucKey==stLog.ucAcqKey )
			{
				break;
			}
		}
		PubASSERT( ucAcqIndex<glSysParam.ucAcqNum );

		for(ucIssIndex=0; ucIssIndex<glSysParam.ucIssuerNum; ucIssIndex++)
		{
			if( glSysParam.stIssuerList[ucIssIndex].ucKey==stLog.ucIssuerKey )
			{
				break;
			}
		}
		PubASSERT( ucIssIndex<glSysParam.ucIssuerNum );

		PubAscAdd(stLog.szAmount, stLog.szTipAmount, 12, szTotalAmt);
		//PubAddHeadChars(szTotalAmt, 12, '0');		no need: already 12 digits
		//2015-1-23 for AMEX if( ChkIfAmex() ) stLog.ucTranType==SALE*/
		if( ChkIfAmex() )
		{
			//............
		}
		if( stLog.uiStatus & TS_ADJ )
		{
			glEdcTotal.uiAdjustCnt++;
			glAcqTotal[ucAcqIndex].uiAdjustCnt++;
			glIssuerTotal[ucIssIndex].uiAdjustCnt++;
		}
		if( stLog.ucReversalFlag == 1 )
		{
			glEdcTotal.uiReversalCnt++;
			glAcqTotal[ucAcqIndex].uiReversalCnt++;
			glIssuerTotal[ucIssIndex].uiReversalCnt++;
		}


		if( stLog.ucTranType==VOID || (stLog.uiStatus & TS_VOID) )
		{
			ucTranAct = glTranConfig[stLog.ucOrgTranType].ucTranAct;
		}
		else
		{
			ucTranAct = glTranConfig[stLog.ucTranType].ucTranAct;
		}
		if( ucTranAct & IN_SALE_TOTAL )
		{
			if( stLog.uiStatus & TS_VOID )
			{
				glEdcTotal.uiVoidSaleCnt++;
				SafeAscAdd(glEdcTotal.szVoidSaleAmt, szTotalAmt, 12);

				glAcqTotal[ucAcqIndex].uiVoidSaleCnt++;
				SafeAscAdd(glAcqTotal[ucAcqIndex].szVoidSaleAmt, szTotalAmt, 12);

				glIssuerTotal[ucIssIndex].uiVoidSaleCnt++;
				SafeAscAdd(glIssuerTotal[ucIssIndex].szVoidSaleAmt, szTotalAmt, 12);
			}
			else
			{   
				if (!ChkIfZeroAmt(szTotalAmt))                
				{
					glEdcTotal.uiSaleCnt++;
					SafeAscAdd(glEdcTotal.szSaleAmt, szTotalAmt, 12);
					
					glAcqTotal[ucAcqIndex].uiSaleCnt++;
					SafeAscAdd(glAcqTotal[ucAcqIndex].szSaleAmt, szTotalAmt, 12);

					glIssuerTotal[ucIssIndex].uiSaleCnt++;
					SafeAscAdd(glIssuerTotal[ucIssIndex].szSaleAmt, szTotalAmt, 12);                
				}
				else               
				{
					szCurAcqIndex = glCurAcq.ucIndex;//2015-1-8 
					SetCurAcq(ucAcqIndex);//2014-11-3 if not set acq, won't know if it is DCC or not
					if (PPDCC_ChkIfDccAcq())
					{
						glEdcTotal.uiZeroCount++;
						glAcqTotal[ucAcqIndex].uiZeroCount++;
						glIssuerTotal[ucIssIndex].uiZeroCount++;                
					}
					glCurAcq.ucIndex = szCurAcqIndex;
					SetCurAcq(szCurAcqIndex);//2015-1-28 set back to required ACQ
				}
				/*else if (PPDCC_ChkIfDccAcq())                
				{
					glEdcTotal.uiZeroCount++;
					glAcqTotal[ucAcqIndex].uiZeroCount++;
					glIssuerTotal[ucIssIndex].uiZeroCount++;                
				}*/

				if( !ChkIfZeroAmt(stLog.szTipAmount) )
				{
					glEdcTotal.uiTipCnt++;
					SafeAscAdd(glEdcTotal.szTipAmt, stLog.szTipAmount, 12);

					glAcqTotal[ucAcqIndex].uiTipCnt++;
					SafeAscAdd(glAcqTotal[ucAcqIndex].szTipAmt, stLog.szTipAmount, 12);

					glIssuerTotal[ucIssIndex].uiTipCnt++;
					SafeAscAdd(glIssuerTotal[ucIssIndex].szTipAmt, stLog.szTipAmount, 12);
				}
			}
		}

		if( ucTranAct& IN_REFUND_TOTAL )
		{
			if( stLog.uiStatus & TS_VOID )
			{
				glEdcTotal.uiVoidRefundCnt++;
				SafeAscAdd(glEdcTotal.szVoidRefundAmt, szTotalAmt, 12);

				glAcqTotal[ucAcqIndex].uiVoidRefundCnt++;
				SafeAscAdd(glAcqTotal[ucAcqIndex].szVoidRefundAmt, szTotalAmt, 12);

				glIssuerTotal[ucIssIndex].uiVoidRefundCnt++;
				SafeAscAdd(glIssuerTotal[ucIssIndex].szVoidRefundAmt, szTotalAmt, 12);
			}
			else
			{
				glEdcTotal.uiRefundCnt++;
				SafeAscAdd(glEdcTotal.szRefundAmt, szTotalAmt, 12);

				glAcqTotal[ucAcqIndex].uiRefundCnt++;
				SafeAscAdd(glAcqTotal[ucAcqIndex].szRefundAmt, szTotalAmt, 12);

				glIssuerTotal[ucIssIndex].uiRefundCnt++;
				SafeAscAdd(glIssuerTotal[ucIssIndex].szRefundAmt, szTotalAmt, 12);
			}
		}
	}

	if( ucAcqKey==ACQ_ALL )
	{
		memcpy(&glTransTotal, &glEdcTotal, sizeof(TOTAL_INFO));
		return;
	}

	for(ucAcqIndex=0; ucAcqIndex<glSysParam.ucAcqNum; ucAcqIndex++)
	{
		if( glSysParam.stAcqList[ucAcqIndex].ucKey==ucAcqKey )
		{
			break;
		}
	}
	memcpy(&glTransTotal, &glAcqTotal[ucAcqIndex], sizeof(TOTAL_INFO));
}

#ifdef ENABLE_EMV
// save last emv status
int SaveEmvStatus(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_EMV_STATUS, 0L, &glEmvStatus, sizeof(EMV_STATUS));
	if( iRet!=0 )
	{
		PubTRACE0("SaveEmvStatus");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}
#endif

#ifdef ENABLE_EMV
// save last emv status
int LoadEmvStatus(void)
{
	int		iRet;

	iRet = PubFileRead(FILE_EMV_STATUS, 0L, &glEmvStatus, sizeof(EMV_STATUS));
	if( iRet!=0 )
	{
		PubTRACE0("LoadEmvStatus");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}
#endif

#ifdef ENABLE_EMV
// save EMV error log message
int SaveEmvErrLog(void)
{
	int			iRet, iLength;
	EMV_ERR_LOG	stErrLog;

	// collect message for log
	memset(&stErrLog, 0, sizeof(EMV_ERR_LOG));
	stErrLog.bValid = TRUE;
	stErrLog.ucAidLen = glProcInfo.stTranLog.ucAidLen;
	memcpy(stErrLog.sAID, glProcInfo.stTranLog.sAID, stErrLog.ucAidLen);
	sprintf((char *)stErrLog.szPAN, "%.19s", glProcInfo.stTranLog.szPan);
	stErrLog.ucPANSeqNo = glProcInfo.stTranLog.bPanSeqOK ? glProcInfo.stTranLog.ucPanSeqNo : 0xFF;
	sprintf((char *)stErrLog.szAmount, "%.12s", glSendPack.szTranAmt);
	sprintf((char *)stErrLog.szTipAmt, "%.12s", glSendPack.szExtAmount);
	sprintf((char *)stErrLog.szRspCode, "%.2s", glProcInfo.stTranLog.szRspCode);
	PubGetDateTime(stErrLog.szDateTime);
	sprintf((char *)stErrLog.szRRN, "%.12s",    glProcInfo.stTranLog.szRRN);
	sprintf((char *)stErrLog.szAuthCode, "%.6s", glProcInfo.stTranLog.szAuthCode);

	EMVGetTLVData(0x95, stErrLog.sTVR, &iLength);
	EMVGetTLVData(0x9B, stErrLog.sTSI, &iLength);

	stErrLog.uiReqICCDataLen = (ushort)PubChar2Long(glSendPack.sICCData, 2, NULL);
	memcpy(stErrLog.sReqICCData, &glSendPack.sICCData[2], stErrLog.uiReqICCDataLen);
	stErrLog.uiReqField56Len = (ushort)PubChar2Long(glSendPack.sICCData2, 2, NULL);
	memcpy(stErrLog.sReqField56, &glSendPack.sICCData2[2], stErrLog.uiReqField56Len);
	if( memcmp(glSendPack.szSTAN, glRecvPack.szSTAN, 6)==0 )
	{
		stErrLog.uiRspICCDataLen = (ushort)PubChar2Long(glRecvPack.sICCData, 2, NULL);
		memcpy(stErrLog.sRspICCData, &glRecvPack.sICCData[2], stErrLog.uiRspICCDataLen);
	}
	stErrLog.ulSTAN = glProcInfo.stTranLog.ulSTAN;

	PubASSERT( glSysCtrl.uiErrLogNo<MAX_ERR_LOG );
	if( glSysCtrl.uiErrLogNo>=MAX_ERR_LOG )
	{
		glSysCtrl.uiErrLogNo = 0;
	}
	iRet = PubFileWrite(FILE_ERR_LOG, (long)(glSysCtrl.uiErrLogNo * sizeof(EMV_ERR_LOG)),
						&stErrLog, sizeof(EMV_ERR_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("SaveEmvErrLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	glSysCtrl.uiErrLogNo++;
	if( glSysCtrl.uiErrLogNo>=MAX_ERR_LOG )
	{
		glSysCtrl.uiErrLogNo = 0;
	}
	SaveSysCtrlBase();

	return 0;
}
#endif

#ifdef ENABLE_EMV
// load one error log
int LoadErrLog(ushort uiRecNo, void *pOutErrLog)
{
	int		iRet;

	iRet = PubFileRead(FILE_ERR_LOG, (long)(uiRecNo * sizeof(EMV_ERR_LOG)),
						pOutErrLog, sizeof(EMV_ERR_LOG));
	if( iRet!=0 )
	{
		PubTRACE0("LoadEmvErrLog");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}
#endif

// ͬ�������ļ���manager��EPS
// Sync password to manager application. usually for HongKong
int SyncPassword(void)
{
	int		iRet;

	iRet = PubFileWrite(FILE_PASSWORD, 0L, glSysParam.sPassword, sizeof(glSysParam.sPassword));
	if( iRet!=0 )
	{
		PubTRACE0("SyncPassword");
		SysHalt();
		return ERR_FILEOPER;
	}

	return 0;
}

// for BEA fallback process
int LastRecordIsFallback(void)
{
	int			iRet;
	TRAN_LOG	stLog;

	if( glSysCtrl.uiLastRecNoList[glCurAcq.ucIndex]>=MAX_TRANLOG )
	{
		return FALSE;
	}

	memset(&stLog, 0, sizeof(TRAN_LOG));
	iRet = LoadTranLog(&stLog, glSysCtrl.uiLastRecNoList[glCurAcq.ucIndex]);
	if( iRet!=0 )
	{
		return FALSE;
	}
	if( (stLog.uiEntryMode & MODE_FALLBACK_SWIPE) ||
		(stLog.uiEntryMode & MODE_FALLBACK_MANUAL) )
	{
		return TRUE;
	}

	return FALSE;
}
int LoadWLBBit63Flag(void)
{
	int fd;
	uchar ucResult;
	
	if (fexist("WLBBit63.dat") < 0)// for test
	{
		fd = open("WLBBit63.dat", O_CREATE);
		ucResult = write(fd, "10", 2);		//"10"  1��ʾ�忨������Ϊ2��0��ʾ��һ�ʽ��ף�����Ϊ1
		// 		ucWLBBuf[0] = 1;
		// 		ucWLBBuf[1] = 0;
		ucResult = read(fd, ucWLBBuf, 2);
		close(fd);
	}
	else
	{
		fd = open("WLBBit63.dat", O_RDWR);
		read(fd, ucWLBBuf, 2);		//"10"  1��ʾ�忨������Ϊ2��0��ʾ��һ�ʽ��ף�����Ϊ1
		close(fd);	
	}
	
	return 0;
}


// end of file
