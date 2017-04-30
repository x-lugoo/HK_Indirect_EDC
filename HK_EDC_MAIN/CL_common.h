/*****************************************************/
/* Cl_Common.h                                       */
/* Define the common macros and structurese          */
/* of Contactless application for all PAX Readers    */
/* Created by Liuxl at July 30, 2009                 */
/*****************************************************/

#ifndef _CLSS_COMMON_H
#define _CLSS_COMMON_H
  

// EMV_LIB δ����
#ifndef _EMV_LIB_H 

#define  MAX_REVOCLIST_NUM    30      // EMVCOҪ��ÿ��RID����֧��30�������б�  
#define MAX_APP_NUM       32         //EMV��Ӧ���б����ɴ洢��Ӧ����  

#define PART_MATCH        0x00       //Ӧ��ѡ��ƥ���־(����ƥ��)  
#define FULL_MATCH        0x01       //Ӧ��ѡ��ƥ���־(��ȫƥ��) 

#define EMV_CASH          0x01       //��������(�ֽ�) 
#define EMV_GOODS	      0x02       //��������(����) 
#define EMV_SERVICE       0x04       //��������(����) 
#define EMV_CASHBACK      0x08       //��������(����) 
#define EMV_INQUIRY		  0x10		 //��������(��ѯ) 
#define EMV_TRANSFER	  0x20		 //��������(ת��) 
#define EMV_PAYMENT		  0x40		 //��������(֧��) 
#define EMV_ADMIN		  0x80		 //��������(����) 

#define EMV_OK             0         //�ɹ� 
#define ICC_RESET_ERR     -1         //IC����λʧ�� 
#define ICC_CMD_ERR       -2         //IC����ʧ�� 
#define ICC_BLOCK         -3         //IC������   

#define EMV_RSP_ERR       -4         //IC��������� 
#define EMV_APP_BLOCK     -5         //Ӧ������ 
#define EMV_NO_APP        -6         //��Ƭ��û��EMVӦ�� 
#define EMV_USER_CANCEL   -7         //�û�ȡ����ǰ�������� 
#define EMV_TIME_OUT      -8         //�û�������ʱ 
#define EMV_DATA_ERR      -9         //��Ƭ���ݴ��� 
#define EMV_NOT_ACCEPT    -10        //���ײ����� 
#define EMV_DENIAL        -11        //���ױ��ܾ� 
#define EMV_KEY_EXP       -12        //��Կ���� 

//�ص��������������������붨��
#define EMV_NO_PINPAD     -13        //û��������̻���̲����� 
#define EMV_NO_PASSWORD   -14        //û��������û��������������� 
#define EMV_SUM_ERR       -15        //��֤������ԿУ��ʹ��� 
#define EMV_NOT_FOUND     -16        //û���ҵ�ָ�������ݻ�Ԫ�� 
#define EMV_NO_DATA       -17        //ָ��������Ԫ��û������ 
#define EMV_OVERFLOW      -18        //�ڴ���� 

//��������־
#define NO_TRANS_LOG      -19 
#define RECORD_NOTEXIST   -20 
#define LOGITEM_NOTEXIST  -21 

#define ICC_RSP_6985      -22        // GPO/GAC�п�Ƭ����6985, ��Ӧ�þ����Ƿ�fallback

#define REFER_APPROVE     0x01       //�ο�������(ѡ����׼) 
#define REFER_DENIAL      0x02       //�ο�������(ѡ��ܾ�) 
#define ONLINE_APPROVE    0x00       //����������(������׼) 
#define ONLINE_FAILED     0x01       //����������(����ʧ��)	 
#define ONLINE_REFER      0x02       //����������(�����ο�) 
#define ONLINE_DENIAL     0x03       //����������(�����ܾ�) 
#define ONLINE_ABORT      0x04       //����PBOC(������ֹ) 

typedef struct {
	uchar RID[5];            //Ӧ��ע�������ID
	uchar KeyID;             //��Կ����
	uchar HashInd;           //HASH�㷨��־
	uchar ArithInd;          //RSA�㷨��־
	uchar ModulLen;          //ģ����
	uchar Modul[248];        //ģ
	uchar ExponentLen;       //ָ������
	uchar Exponent[3];       //ָ��
	uchar ExpDate[3];        //��Ч��(YYMMDD)
	uchar CheckSum[20];      //��ԿУ���
}EMV_CAPK;
// added by liuxl 20070710 ����ͨ���򵥵�ɾ����Ӧ�Ĺ�Կ��������������֤������
// �������ʹ�øù�Կ�����������й�Կ֤���޷�ʹ�� 
typedef  struct 
{
	uchar   ucRid[5];  		        // RID
	uchar   ucIndex;   		        // CA��Կ����
	uchar   ucCertSn[3];            // ������֤�����к�
}EMV_REVOCLIST;

#endif


#ifndef ushort 
#define ushort unsigned short
#endif
#ifndef uchar
#define uchar uchar
#endif
#ifndef ulong
#define ulong ulong
#endif
#ifndef uint
#define uint unsigned int
#endif

#define KERNTYPE_DEF 0
#define KERNTYPE_JCB 1	
#define KERNTYPE_MC  2
#define KERNTYPE_VIS 3
#define KERNTYPE_PBOC  4	

//2016-2-5 start
#define KERNTYPE_AE                     5
#define KERNTYPE_ZIP                    6
#define KERNTYPE_FLASH                  7
#define KERNTYPE_EFT                    8
#define KERNTYPE_RFU                    0xFF
//#define KERNTYPE_EXP 5 
//#define KERNTYPE_RFU 5
//2016-2-5 end

// ÿ��AID��Ӧ�Ĳ���,���ڽ���Ԥ����
typedef struct CLSS_PREPROC_INTER_FLAG_INFO
{
	uchar aucAID[17];       
	uchar ucAidLen; 
	
	//	uchar ucKernType; // ���������AID ����ѭ���ں�����
	
	// payWave
	uchar   ucZeroAmtFlg;       // 0-���׽��!=0; 1-���׽��=0
	uchar   ucStatusCheckFlg;    // �������Ƿ�֧��״̬���
    uchar   aucReaderTTQ[5];      // �ն˽������ܣ�����VISA/PBOC�У�tag =9F66
	uchar   ucCLAppNotAllowed; // 1-��AID���ܽ��зǽӴ�����
	
	// common
	uchar ucTermFLmtExceed; 
	uchar ucRdCLTxnLmtExceed; 
	uchar ucRdCVMLmtExceed;  
	uchar ucRdCLFLmtExceed;  

	uchar ucTermFLmtFlg;
	uchar aucTermFLmt[5];
	
	uchar aucRFU[2];
}Clss_PreProcInterInfo;

//	CLSS_TRANSPARAM ������ز����ṹ
typedef struct CLSS_TRANSPARAM
{
    ulong  ulAmntAuth;     // ��Ȩ���(ulong)
    ulong  ulAmntOther;    // �������(ulong) 
    ulong  ulTransNo;      // �������м�����(4 BYTE)
	uchar  ucTransType;    // ��������'9C'
	uchar  aucTransDate[4]; // �������� YYMMDD
	uchar  aucTransTime[4]; // ����ʱ�� HHMMSS
}Clss_TransParam;


#define CLSS_MAX_AIDLIST_NUM  32
#define CLSS_MAX_KEY_NUM       7     //EMV����֤���Ĺ�Կ�����ɴ洢�Ĺ�Կ��


// clss err code
#define CLSS_PARAM_ERR    -30 // -26 // ��EMV �ں��еĲ���������Ϊ-30
#define CLSS_USE_CONTACT  -23    // ����ʹ������������н���
//#define CLSS_READDATA_ERR -24    // ����¼�г���,Ӧ��ֹ���ײ�����ѯ��
#define CLSS_TERMINATE    -25    // Ӧ��ֹ����       -25 
#define CLSS_FAILED       -26    // ����ʧ�� 20081217 
#define CLSS_WAVE2_OVERSEA -31  // 20090418 for visa wave2 trans
#define CLSS_WAVE2_TERMINATED CLSS_TERMINATE //-32 // 20090421 for wave2 DDA response TLV format error
#define CLSS_WAVE2_US_CARD -33  // 20090418 for visa wave2 trans
#define CLSS_WAVE3_INS_CARD -34 // 20090427 FOR VISA L3
#define CLSS_RESELECT_APP   -35


#define CLSS_PATH_NORMAL  0
#define CLSS_VISA_MSD     1   // scheme_visa_msd_20
#define CLSS_VISA_QVSDC   2   // scheme_visa_wave3
#define CLSS_VISA_VSDC    3   // scheme_visa_full_vsdc
#define CLSS_VISA_CONTACT 4 
// 5~6: MCHIP, MAGSTRIPE  
#define CLSS_MC_MAG       5
#define CLSS_MC_MCHIP     6
#define CLSS_VISA_WAVE2   7 //SCHEME_VISA_WAVE_2 // 7   // SCHEME_VISA_WAVE_2 
// end

#define RD_CVM_NO 0x00
#define RD_CVM_SIG 0x10
#define RD_CVM_ONLINE_PIN 0x11
#define RD_CVM_OFFLINE_PIN 0x12


 // �� amount > contactless cvm limit ʱ����Ҫִ�к���CVM��ʽ��
#define RD_CVM_REQ_SIG 0x01
#define RD_CVM_REQ_ONLINE_PIN 0x02

typedef struct _tagDRL//2015-11-12 add APID lists
{
    uchar szProgramID[5];
    uchar ulRdClssTxnLmt[12];
    uchar ulRdCVMLmt[12];
    uchar ulRdClssLmt[12];
    //���ݭn�A�K�[
} DRL;
 
typedef struct  
{
	ulong   ulReferCurrCon;       // �ο����Ҵ���ͽ��״����ת��ϵ��(���׻��ҶԲο����ҵĻ���*1000)

	ushort  usMchLocLen;          // �̻����Ƽ�λ��������ĳ���
	uchar   aucMchNameLoc[257];   // �̻����Ƽ�λ��(1-256 �ֽ�)
	uchar   aucMerchCatCode[2];   // �̻�������'9F15'(2�ֽ�) 
	uchar   aucMerchantID[15];    // �̻���ʶ(15�ֽ�) 
	
	uchar AcquierId[6];       //�յ��б�־

    uchar   aucTmID[8];           // �ն˱�ʶ(�ն˺�) 
	uchar   ucTmType;    // 0xDF86         // �ն�����
	uchar   aucTmCap[3];          // �ն�����
    uchar   aucTmCapAd[5];        // �ն˸�������

    uchar   aucTmCntrCode [2];     // �ն˹��Ҵ��� '9F1A'
	uchar   aucTmTransCur[2];      // �ն˽��׻��Ҵ���'5F2A'(2�ֽ�) 
	uchar   ucTmTransCurExp;       // �ն˽��׻���ָ��'5F36'(1�ֽ�)

	uchar   aucTmRefCurCode[2];    // �ն˽��ײο����Ҵ���'9F3C'(2�ֽ�)
	uchar   ucTmRefCurExp;	       // �ն˽��ײο�����ָ��'9F3D'(1�ֽ�)

//	uchar   ucTmTransCateCode;     // �ն˽��������� 
	uchar   aucRFU[3];
	 
	DRL auVisaDRLList[10];//2015-11-12
}Clss_ReaderParam;
 

// visa
#define SCHEME_VISA_WAVE_2     0x16  // SUPPORTED
#define SCHEME_VISA_WAVE_3     0x17  // SUPPORTED
#define SCHEME_VISA_MSD_20     0x18  // SUPPORTED
#define SCHEME_JCB_WAVE_1      0x60
#define SCHEME_JCB_WAVE_2      0x61
#define SCHEME_JCB_WAVE_3      0x62 

typedef struct VISA_AID_PARAM
{
    ulong ulTermFLmt; // 0xDF85       //����޶� - ͬEMV����޶�

	uchar ucDomesticOnly;// 0x9F35 // 01(default):only supports domestic cl transaction
	// 00 or not present: supports international cl transaction
	
	uchar ucCvmReqNum;
	uchar aucCvmReq[5];// 0xDF04 // whether a CVM is required when the amount is higher than the Contactless CVM Required Limit.
	// 01-Signature 02-Online PIN	
	
	uchar ucEnDDAVerNo; // 0xDF03 Ĭ��=0, ������֧�����а汾��DDA��Ƭ���ѻ�����,
	// 01-��֧��dda�汾Ϊ'01'�Ŀ�Ƭ�����ѻ�����	 
	 
}Clss_VisaAidParam;
/*
typedef struct  
{
	uchar ucSchemeID;
	uchar ucSupportFlg; // supported; 0-not support
	// 20090511
	uchar ucRFU[2];
}Clss_SchemeID_Info;
*/

// PBOC
typedef struct PBOC_AID_PARAM
{
    ulong ulTermFLmt;// 0xDF85        //����޶� - ͬEMV����޶�
    uchar aucRFU[4];	 
}Clss_PbocAidParam;

// mastercard
typedef struct  MC_AID_PARAM
{
    ulong FloorLimit;// 0xDF85        //����޶� - ͬEMV����޶�
	ulong Threshold;         //��ֵ 

	ushort usUDOLLen;       
	uchar uDOL[256];        //�ն�ȱʡUDOL

	uchar TargetPer;         //Ŀ��ٷֱ��� 
	uchar MaxTargetPer;      //���Ŀ��ٷֱ��� 
 	uchar FloorLimitCheck;   //�Ƿ�������޶�
	uchar RandTransSel;      //�Ƿ�����������ѡ��
	uchar VelocityCheck;     //�Ƿ����Ƶ�ȼ��
 	uchar TACDenial[6];      //�ն���Ϊ����(�ܾ�)
	uchar TACOnline[6];      //�ն���Ϊ����(����)
	uchar TACDefault[6];     //�ն���Ϊ����(ȱʡ) 
    uchar AcquierId[6];      //�յ��б�־
	uchar dDOL[256];         //�ն�ȱʡDDOL  
	uchar tDOL[256];         //�ն�ȱʡTDOL 
	uchar Version[3];        //Ӧ�ð汾��
	uchar ForceOnline;       //�̻�ǿ������(1 ��ʾ������������) 
	uchar MagAvn[3];         //����Ӧ�ð汾��

	uchar ucMagSupportFlg; // 1-������֧��MagStripe
	uchar ucRFU;
}Clss_MCAidParam; 

#endif


