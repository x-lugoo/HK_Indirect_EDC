
/*********************************************************************************
NAME
    global.h - ���幫�����ݽṹ

DESCRIPTION
    ����Ӧ�õ�ȫ�ֱ���/ȫ�ֳ�����

REFERENCE

MODIFICATION SHEET:
    MODIFIED   (YYYY.MM.DD)
    shengjx     2006.09.12      - created
*********************************************************************************/

#ifndef _GLOBAL_H
#define _GLOBAL_H

/*********************************************************************************
�趨��Ҫ����Ļ���
Set to correct macro before compile
*********************************************************************************/
//#define _P60_S1_
// #define _P70_S_
// #define _P78_
// #define _P80_
// #define _P90_
// #define _P58_

#define IP_ENCRYPT //2014-5-20 IP Encryption adding

#define _S_SERIES_
//ver1.00.0122 
#define _S60_  //S60
// #define _SP30_

/*********************************************************************************
�趨�������Կ���/�ر�
Set to correct macro before compile
*********************************************************************************/
#define APP_MANAGER_VER	// When build this app as manager, should enable this macro ��������Ӧ��ʱ�������˺궨��
#define ALLOW_NO_TMS		// enable "load default" menu in func-0.
//#define USE_EXTEND_PXXCOM	// use external Pxx communication module. (external box or so)
#define ENABLE_EMV			// Link EMV lib into the application.
//#define EMV_TEST_VERSION	// use hard coded emv parameters for EMV test. Valid only when ENABLE_EMV defined
//#define APP_DEBUG			// debug mode
//#define DCC_DEBUG
//#define PAYPASS_DEMO        //PAYPASS DEMO FOR HK
#define SUPPORT_TABBATCH      // Support enable/disable MS-SCB Tab Batch (AUTH log storage)//2014-11-25 
#define ENC_USE_TESTKEY//2016-2-29 ttt //2016-3-9 for  Wing Lung Bank IP Encryption //Gillian 2016-7-14

#define LOIS_DEFAULT_KEY //2015-11-17 Gillian 20160923

#define APP_DEBUG_RICHARD //add by richard 20161107, for debug mode

//#define FUN2_READ_ONLY	// Allow operator to modify FUNCTION 2.
//#define DEMO_HK			// Demo
//#define TAXI_MODE			// taxi mode version
//#define AMT_PROC_DEBUG      //2014-9-19 to detect all amt changes during transaction process.

// Coordination app-manager name Ӧ�ù���������(�����)
#define APPNAME_MANAGER		"EDC MANAGER"

#define WAIT_CARDHOLDER_CHOICE    //PP DCC, wait until card holder made a choice

/*********************************************************************************
Application attribute Ӧ������(����, ID, �汾)
*********************************************************************************/
#ifdef DEMO_HK
	#define APP_NAME		"EDC DEMO"
	#define EDCAPP_AID		"EDC_DEMO_001"
#endif


	#define APP_NAME		"EDC MAIN"
	#define EDCAPP_AID		"EDC_MAIN_001"



#ifdef EMV_TEST_VERSION
#define EDC_VER_PUB		"1.00"
#define EDC_VER_INTERN	"1.00.0204e-EMVT"
#else
#ifdef AMT_PROC_DEBUG
#define EDC_VER_PUB		"1.00"			// �����汾��. Public version number

#define EDC_VER_INTERN	"1.00.204T"
#else
#define EDC_VER_PUB		"1.00"			// �����汾��. Public version number
                         //2016-2-5 AMEX Express
#define EDC_VER_INTERN	"1.00.0219"	// ��չ�汾��(ǰ����Ӧ�͹����汾��һ��). Extend version number. should be same as EDC_VER_INTERN's heading.

/*----------2015-11-17 KMS START-----------*/ //Gillian 20160923
#define KMSCFG  				"KMSCFG.INI" 
//KEY
#define PARA_CURRENT_LANG						"Para.Current.Lang"
#define PARA_SET_DEFAULT						"Para.Set.Default"//flag for set default
#define PARA_FILE_VERSION						"Para.File.Version"
#define PARA_COMMODE							"Para.ComMode"
#define PARA_APPNAME							"Para.AppName"
#define PARA_LOADTYPE							"Para.LoadType"
#define PARA_PROTOCOL							"Para.Protocol"
#define PARA_CALLMODE							"Para.CallMode"
#define PARA_TID									"Para.Terminal.id"
#define PARA_CUSTOM_LANG						"Para.Custom.Lang"
/*----------2015-11-17 KMS   END-----------*/
#endif
#endif
//linda
/*********************************************************************************
Features of specific area ����ר������
*********************************************************************************/
//#define AREA_TAIWAN
#define AREA_HK
//#define AREA_SG
//#define AREA_VIETNAM		// Vietnam
//#define AREA_KH			// Cambodia

/*********************************************************************************
EMV terminal capability EMV�ն���������
*********************************************************************************/
#define EMV_CAPABILITY		"\xE0\xB0\xC8"
#define EMV_AECAPABILITY	"\xE0\xB8\xC8"
//	9F33 - Terminal Capabilities Length = 03
//		Byte 1 Bit 8 Manual key entry 
//		Byte 1 Bit 7 Magnetic stripe 
//		Byte 1 Bit 6 IC with contacts
//		Byte 2 Bit 8 Plaintext PIN for offline ICC verification 
//		Byte 2 Bit 7 Enciphered PIN for online verification 
//		Byte 2 Bit 6 Signature (paper) 
//		Byte 2 Bit 5 Enciphered PIN for offline ICC verification 
//		Byte 2 Bit 4 No CVM Required
//		Byte 3 Bit 8 Offline static data authentication 
//		Byte 3 Bit 7 Offline dynamic data authentication 
//		Byte 3 Bit 6 Card capture
//		Byte 3 Bit 4 Combined DDA/AC Generation

#define PAYPASS_CAPABILITY
//�]��PAYPASS Reader�n�D���׺ݯ�O��EMV���@�P�A�ҥH�W�[�F�Ӷ����w�q�C
#ifdef PAYPASS_CAPABILITY
//#define EMV_CLSS_CAPABILITY	"\xE0\xB0\xC8"
//#define EMV_CLSS_CAPABILITY	"\xE0\xB8\xC8"
#define EMV_CLSS_CAPABILITY	"\xE0\xB0\xC8"
#endif


/*********************************************************************************
���¶�����ڱ������������ʱ�޸ġ����ĳЩ���Ժʹ˻����ǰ󶨵ģ����ڴ˶���
ע�⣺ƽʱ�벻Ҫ�ֶ�����/�ر����кꡣ��Щ��Ŀ���Ӧ��ǰ��ĺ��Ƿ��ѱ�������Զ������Ƿ���
Below macro definitions are related to application functionality and less changed.
If any feature is related to machine, but not related to specific app, add them below
Warning: DO NOT manually enable/disable below macros. they're determined automatically.
*********************************************************************************/

#if defined(WIN32) && defined(_P60_S1_)		// Convenient for Propay(P70) use.
#undef _P60_S1_
#define _P70_S_
#endif

#ifdef _P60_S1_
#endif

#ifdef _P70_S_
#endif

#ifdef _P80_
#define PXX_COMM
#endif

#ifdef _P90_
#define PXX_COMM				// P80/P90��IPģ������ģ��ͨѸ��ʽ
#endif

#ifdef _P58_
#endif

#ifdef USE_EXTEND_PXXCOM
#define PXX_COMM
#endif

// ע�⣺Ҳ�в�����S80��֧��SXX_WIRELESS_MODULE
#ifdef _S_SERIES_
#define SXX_IP_MODULE			//S80��IPģ��ͨѸ��ʽ
#define SXX_WIRELESS_MODULE		//Sϵ������ģ��
//#define IP_INPUT            //raymond 3 Jun 2010: Input IP without typing dot '.'
#endif

// ���ã���GCC�������趨�ֽڶ���
#if defined(_WIN32) || defined(_WINDOWS)
	#define PACK_STRUCT
#elif defined(_P80_) || defined(_P90_) || defined(_P78_) || defined(_S_SERIES_) || defined(_SP30_)
	#define PACK_STRUCT		__attribute__((packed))
#else
	#define PACK_STRUCT
#endif

#include "Stdarg.h"

// �����������Ĺ��̵�ͷ�ļ�
// Please add your customized header files here.
#include "posapi.h"
#include "appLib.h"

#ifdef ENABLE_EMV
#include "emvlib.h"		// Recommend to link to external file, not copying it into source folder.
						// Use project--settings--c/c++--category=preprocessor--additional include directories
#endif

#include "commlib.h"
#include "util.h"
#include "pack8583.h"
#include "st8583.h"
#include "initpos.h"
#include "setup.h"
#include "fileoper.h"
#include "tranproc.h"
#include "eventmsg.h"
#include "checkopt.h"
#include "commproc.h"
#include "print.h"
#include "password.h"
#include "manage.h"
#include "pedpinpad.h"
#include "cpinpad.h"
#include "MultiApp.h"
#include "lng.h"
#include "Simulate.h"
#include "MultiApp.h"
#include "DccPP.h"
#include "dccboc.h"
#include "ecrtrans.h"
#include "PayWavePosTm.h"
#include "clssproc.h"
#include "CL_common.h"
#include "ClssApi_MC.h"
//#include "ClssApi_PBOC.h"
#include "ClssApi_Wave.h"
#include "CLEntryApi.h"
#include "ClssApi_AE.h"
#include "ecr.h"
#include "keyManage.h" //add by richard 20161114

#ifdef ENABLE_EMV
#include "emvproc.h"
#include "emvtest.h"
#endif

#ifdef _P60_S1_
#include "PED.h"
#endif
#if defined(SXX_WIRELESS_MODULE) || defined(SXX_IP_MODULE)
#include "SxxCom.h"
#endif
 
/*----------2015-11-17 KMS START-----------*/ //Gillian 20160923
#include "common.h"
#define _SXX_PROTIMS	// SXX or PXX
//#define REAL_ECR //Gillian 20161010
//Modem Para
#define MODEM_PHONE_NUM						"Modem.Phone.Number"
#define MODEM_OUTSIDE_NUM						"Modem.Outside.Number"
#define MODEM_TIMEOUT							"Modem.Timeout"
#define MODEM_PARA_DP							"Modem.Para.DP"
#define MODEM_PARA_CHDT						"Modem.Para.CHDT"
#define MODEM_PARA_DT1						"Modem.Para.DT1"
#define MODEM_PARA_DT2						"Modem.Para.DT2"
#define MODEM_PARA_HT							"Modem.Para.HT"
#define MODEM_PARA_WT							"Modem.Para.WT"
#define MODEM_PARA_SSETUP						"Modem.Para.SSETUP"
#define MODEM_PARA_DTIMES						"Modem.Para.DTIMES"
#define MODEM_PARA_TIMEOUT					"Modem.Para.Timeout"
#define MODEM_PARA_ASMODE					"Modem.Para.ASMode"
#define MODEM_PARA_BAUDRATE					"Modem.Para.BaudRate"
#define MODEM_PARA_TPDU						"Modem.Para.TPDU"	//add TPDU header in front of the data 
#define MODEM_PARA_NII							"Modem.Para.Nii"


//Com Para
#define COM_BAUD_RATE							"Com.Baud.Rate"

//Tcp Para
#define TCP_REMOTE_IP							"Tcp.Remote.IP"
#define TCP_REMOTE_PORT						"Tcp.Remote.Port"
#define TCP_ENABLE_DHCP						"Tcp.Enable.DHCP"
#define TCP_LOCAL_IP							"Tcp.Local.IP"
#define TCP_LOCAL_PORT							"Tcp.Local.Port"
#define TCP_NETMASK								"Tcp.Netmask"
#define TCP_GATEWAY							"Tcp.Gateway"


//Cdma Para
#define CDMA_PHONE_NUM						"Cdma.Phone.Num"
#define CDMA_USERNAME							"Cdma.Username"
#define CDMA_PASSWORD							"Cdma.Password"
#define CDMA_REMOTE_IP							"Cdma.Remote.IP"
#define CDMA_REMOTE_PORT						"Cdma.Remote.Port"
#define CDMA_PIN_CODE							"Cdma.Pin.Code"
#define CDMA_AT_CMD							"Cdma.At.Cmd"

//Gprs Para
#define GPRS_APN								"Gprs.APN"
#define GPRS_USERNAME							"Gprs.Username"
#define GPRS_PASSWORD							"Gprs.Password"
#define GPRS_REMOTE_IP							"Gprs.Remote.IP"
#define GPRS_REMOTE_PORT						"Gprs.Remote.Port"
#define GPRS_PIN_CODE							"Gprs.Pin.Code"
#define GPRS_AT_CMD							"Gprs.At.Cmd"
#define WL_PACKAGE_LENGTH						"Wl.Package.Length"
//PPP Para
#define PPP_PHONENUM							"Ppp.PhoneNum"
#define PPP_USERNAME							"Ppp.Username"
#define PPP_PASSWORD							"Ppp.Password"
#define PPP_REMOTE_IP							"Ppp.Remote.IP"
#define PPP_REMOTE_PORT						"Ppp.Remote.Port"

//WiFi Para
#define WIFI_SSID								"WiFi.SSID"
#define WIFI_ENCRYMODE							"WiFi.Encrymode"
#define WIFI_PASSWORD							"WiFi.Passwd"
#define WIFI_PASSWD_INDEX						"WiFi.Passwd.Index"
#define WIFI_ENABLE_DHCP						"WiFi.Enable.DHCP"
#define WIFI_LOCAL_IP							"WiFi.Local.IP"
#define WIFI_LOCAL_PORT						"WiFi.Local.Port"
#define WIFI_REMOTE_IP							"WiFi.Remote.IP"
#define WIFI_REMOTE_PORT						"WiFi.Remote.Port"
#define WIFI_NETMASK							"WiFi.Netmask"
#define WIFI_GATEWAY							"WiFi.Gateway"
#define WIFI_DNS1								"WiFi.DNS1"
#define WIFI_DNS2								"WiFi.DNS2"

//Setup
#define SETUP_BOOT_CHECK						"Setup.Boot.Check"

//System
#define SYS_PROTIMS_VERSION					"Sys.Protims.Version"
#define SYS_COMPILE_TIME						"Sys.Compile.Time"

//ComMode 
#define COMMODE_MODEM						"M"
#define COMMODE_COM							"S"
#define COMMODE_GPRS							"G"
#define COMMODE_CDMA							"C"
#define COMMODE_TCP							"T"
#define COMMODE_PPP							"P"
#define COMMODE_WIFI							"W"

#define MAX_VALUE_LEN							33

#define STR_END_DISPLAY_INDEX				"END_DISPLAY_INDEX"
/*----------2015-11-17 KMS   END-----------*/

#define LEN_WORK_KEY	16
// Below IDs should be customized according to your project
//#define MASTER_KEY_ID	    1
#define DEF_PIN_KEY_ID	    70+1		// default PIN key ID (if not assign)

#define GENERAL_MKEY_ID     70+2       // Used for getting EMV offline plain PIN
#define GENERAL_WKEY_ID     70+2       // Used for getting EMV offline plain PIN
#define MAC_KEY_ID		    70+10

#ifdef APP_MANAGER_VER
#define AID_EDC_MAIN	"EDC_MAIN_001"
#define AID_EDC_OLD     "STAND EDC0000001"
#define AID_EMV_BOC		"EMV_EDC_BOC00001"
#define AID_EDC_MULTI	"EDC_MULTI_001"
#define APPNAME_CUP		"CUP EMV MULTI"
#define APPNAME_CUPOLD  "ZYL CUP HK"
#define AID_EPS			"EPS"
#define APPNAME_VA      "VALUACCESS"
#endif

#define EPSAPP_AUTORECAP		900       //W204: EPS autosettlement

#define PP_SSL                  //HASE GENERIC BUILD106  //Gillian 2016-8-19
#define BEA_SSL
#define S90_3G_SSL_URL  "210.177.101.25"
#define S90_3G_SSL_PORT "8899"


#ifdef PP_SSL
// 8.03.15 Build103 jiaxf
typedef struct _tagCURCOMM_PARA
{
    unsigned char ucLoaded;
    TCPIP_PARA LocalParam;
} CURCOMM_PARA;

extern int SSL_PP_GetTCPInfo(TCPIP_PARA *pTcpPara, char* hostCN);
extern int SSL_GetTCPInfo(TCPIP_PARA *pTcpPara, char* hostCN);
extern void SSL_PrintError(int errID);

CURCOMM_PARA  gCurComPara;
//CONNECTONE_COMM stComm;

//HASE GENERIC BUILD111
#define ENV_PP_IP_PORT          "PpIpPrt"       //PP IP port 
void LoadConnectOnePara(unsigned char ucForTransUse);

#endif  //end PP_SSL

// Card slot number for customer.
#define ICC_USER		0

#define MAX_EVENTBUF_SIZE		4096

// �������� Password type
enum {PWD_BANK, PWD_TERM, PWD_MERCHANT, PWD_VOID, PWD_REFUND, PWD_ADJUST, PWD_SETTLE, PWD_MAX};

// DHCP flag
#define PROTIMS_DHCP_NO_SUPPORT            0  // �����DHCP
#define PROTIMS_DHCP_SUPPORT               1  // ���DHCP

//Gillian 20160923
// communication mode
enum
{
	SERIAL_COMM = 0,
	MODEM_COMM,	// 1
	TCPIP_COMM,	// 2
	GPRS_COMM,	// 3
	CDMA_COMM,	// 4
	PPP_COMM,	// 5
	WIFI_COMM,	// 6
	WCDMA_COMM,//7
	UNKNOWN_COMM
}COMM_MODE;
// communication mode
enum
{
	PROTIMS_SUCCESS = 0,
	PROTIMS_MODEM_BASE  = 100,
	PROTIMS_MODEMCHECK,
	PROTIMS_MODEMDIAL,
	PROTIMS_MODEMTXD,
	PROTIMS_MODEMRESET,
	PROTIMS_MODEMSAYNCGET,
	PROTIMS_ONHOOK,
	PROTIMS_MODEM_END,
	PROTIMS_SERIAL_BASE = 200,
	PROTIMS_PORTOPEN,
	PROTIMS_PORTSEND,
	PROTIMS_PORTRESET,
	PROTIMS_PORTRECV,
	PROTIMS_PORT_END,
	PROTIMS_TCP_BASE    = 300,
	PROTIMS_ROUTERSETDEFAULT,
	PROTIMS_DHCPSTART,
	PROTIMS_DHCPCHECK,
	PROTIMS_ETHSET,
	PROTIMS_NETSOCKET,
	PROTIMS_DNSRESLOVE,
	PROTIMS_SOCKETADDSET,
	PROTIMS_NETCONNECT,
	PROTIMS_NETSEND,
	PROTIMS_NETRECV,
	PROTIMS_NETCLOSESOCKET,
	PROTIMS_TCP_END,
	PROTIMS_PPP_BASE    = 400,
	PROTIMS_PPPLOGIN,
	PROTIMS_PPPCHECK,
	PROTIMS_PPP_ROUTERSETDEFAULT,
	PROTIMS_PPP_NETSOCKET,
	PROTIMS_PPP_DNSRESLOVE,
	PROTIMS_PPP_SOCKETADDRSET,
	PROTIMS_PPP_NETCONNECT,
	PROTIMS_PPP_END,
	PROTIMS_WNET_BASE   = 500,
	PROTIMS_WLINIT,
	PROTIMS_WLOPENPORT,
	PROTIMS_WLGETSINGAL,
	PROTIMS_WLLOGINDIAL,
	PROTIMS_WLCLOSEPORT,
	PROTIMS_WNET_DNSRESLOVE,
	PROTIMS_WNET_CONNECT_FAILED,
	PROTIMS_WNET_NETRECV,
	PROTIMS_WIRELESS_END,
	PROTIMS_COMM_BASE  = 600,
	PROTIMS_USERCANCEL,
	PROTIMS_COMM_PARA_INCORRECT,
	PROTIMS_COMM_TIMEOUT_,
	PROTIMS_COMM_WNET_RECV_ERROR,
	PROTIMS_COMM_VERIFY_ERROR,
	PROTIMS_SERVER_DEALERROR,
	PROTIMS_TIMEOUT,
	PROTIMS_TID_ERROR,
	PROTIMS_DECOMPRESS_ERROR,
	PROTIMS_NOTASK_ERROR,
	PROTIMS_COMM_END,
	PROTIMS_FILE_OPERATE = 700,
	PROTIMS_SEEK_FILE_FAILED_,
	PROTIMS_OPEN_FILE_FAILED_,
	PROTIMS_READ_FILE_FAILED_,
	PROTIMS_WRITE_FILE_FAILED_,
	PROTIMS_NOENOUGH_SPACE,
	PROTIMS_REMOVE_FILE_FAILED_,
	PROTIMS_FILE_END,
	PROTIMS_UPDATE_ERR_BASE = 800,
	PROTIMS_UPDATE_APP,
	PROTIMS_UPDATE_PARA,
	PROTIMS_UPDATE_FONT,
	PROTIMS_UPDATE_MONITOR,
	PROTIMS_UPDATE_DLL,
	PROTIMS_UPDATE_DELETE,
	PROTIMS_UPDATE_PUK,
	PROTIMS_UPDATE_PUB,
	PROTIMS_UPDATE_END,
	PROTIMS_UPLOAD_ERR_BASE = 900,
	PROTIMS_UPLOAD_GET_TERMINFO,
	PROTIMS_UPLOAD_GET_TERMINFOEX,
	PROTIMS_UPLOAD_ERR_END,
	PROTIMS_KEY_DOWNLOAD_BASE = 1000,
	PROTIMS_NO_RSAKEY_ERROR,
	PROTIMS_KEY_VALIDATE_ERROR,
	PROTIMS_RSA_ENCRYPT_ERROR,
	PROTIMS_KEY_NUM_ERROR,
	PROTIMS_KEY_LENGTH_ERROR,
	PROTIMS_KEY_DOWNLOAD_END,	
	PROTIMS_UNKNOWN_BASE = 10000
}PROTIMS_ERROR_CODE;

enum
{
	PROTIMS_PROMPT_EN = 0,   
	PROTIMS_PROMPT_CN,   
	PROTIMS_PROMPT_CUSTOM 
};

// display index
enum
{
	DNSRESLVE_ERROR,
	APP_DOWNLOADING,
	PARA_DOWNLOADING,
	FONT_DOWNLOADING,
	MONITOR_DOWNLOADING,
	DLL_DOWNLOADING,
	PUK_DOWNLOADING,
	MONITOR_VER,
	COMM_INIT,
	COMM_HANDSHAKE,
	COMM_AUTHING,
	COMM_GETTASK,
	COMM_PRASETASK,
	UPDATE_LATER,
	PORT_OPEN_ERR,
	COMM_DIALING,
	COMM_SET_IP,
	COMM_DNS_RESLOVE,
	COMM_TCP_CONNECT,
	COMM_PPP_LOGINING,
	COMM_PPP_OPENING,
	COMM_PPP_CONNECTING,
	COMM_WNET_INIT,
	COMM_WNET_CHECK_SIGNAL,
	BULDING_FILE_SYS,
	DELETE_ALL_APPLICATION,
	DELETE_SOME_APPLICATION,
	UPDATE_APP_FILE,
	UPDATE_PARA_FILE,
	UPDATE_FONT_FILE,
	UPDATE_MONITOR_FILE,
	UPDATE_MONITOR_FAILED,
	UPDATE_DLL_FILE,
	UPDATE_DLL_FAILED,
	DELETE_DLL_FILE,
	CUR_FILE,
	COMMAND_INCORRECT,
	DOWNLOAD_100,
	DOWNLOAD_99,
	UPDATE_SUCCESSFULLY_1,
	UPDATE_SUCCESSFULLY_2,
	UPDATE_TITLE,
	MODEM_PARA_PHONE_NUM,
	NEW_DOWNLOAD,
	REPEAT_DOWNLOAD,
	RESUME_DOWNLOAD,
	DOWNLOAD_SETUP,
	MODEM_PARA_SETUP,
	GET_TID,
	OUTSIDE_NUM,
	BAUD_RATE,
	REMOTE_IP,
	REMOTE_PORT,
	ENABLE_DHCP,
	LOCAL_IP,
	NETMASK,
	GATEWAY,
	DNS,
	USERNAME,
	PASSWORD,
	PINCODE,
	USERCANCEL,
	NOT_CONFIGURED,
	REQUEST_UPLOAD,
	UPLOADING_FILE,
	UPDATE_PUK_FILE,
	UPDATE_PUK_FAILED,	
	PROTIMS_TITLE,
	DOWNLOAD_CONTINUE,
	SELECT_LANGUAGE,
	BOOT_CHECK,
	MODEM_PARA,
	CHECK_DIAL_TONE,
	YES_ENTER_KEY,
	NO_CANCEL_KEY,
	SET_BAUD_RATE,
	EXAMPLE_33600,
	PARA_TIMEOUT,
	EXAMPLE_15,
	INPUT_WIFI_SSID,
	SELECT_ENCRYPTION_MODE,
	INPUT_WEP64_PASSWORD,
	INPUT_WEP128_PASSWORD,
	INPUT_WPA_PASSWORD,
	PASSWORD_INDEX,
	LOCAL_PORT,
	DELETE_TEMPFILE,
	ENTER_CANCEL,
	COMM_INIT_ERROR,
	HANDSHAKE_ERROR,
	TERM_AUTH_ERROR,
	GET_TASK_ERROR,
	TASK_PARSE_ERROR,
	NO_TASK_ERROR,
	DOWNLOAD_FAIL,
	PARA_ERROR,
	TID_ERROR,
	UPDATE_ERROR,
	REQ_UPLOAD_ERROR,
	UPLOAD_ERROR,
	NO_RESPONSE,
	LINE_BUSY,
	NO_PHONE_LINE,
	SEND_BUF_NOT_EMPTY,
	TIME_OUT,
	USER_CANCEL,
	COMM_TIMEOUT,
	RECV_ERROR_DATA,
	DATA_CRC_ERROR,
	DOWNLOAD_TIMEOUT,
	PORT_SEND_ERR,
	PORT_RESET_ERR,
	PORT_RECV_ERR,
	TCP_ROUTERSETDEFAULT_ERR,
	TCP_DHCPSTART_ERR,
	TCP_DHCPCHECK_ERR,
	TCP_ETHSET_ERR,
	TCP_NETSOCKET_ERR,
	TCP_SOCKETADDSET_ERR,
	TCP_NETCONNECT_ERR,
	TCP_NETSEND_ERR,
	TCP_NETRECV_ERR,
	TCP_NETCLOSESOCKET_ERR,
	PPP_LOGIN_ERR,
	PPP_CHECK_ERR,
	WL_INIT_ERR,
	WL_OPENPORT_ERR,
	WL_GETSIGNAL_ERR,
	WL_LOGINDIAL_ERR,
	WL_CLOSEPORT_ERR,
	FILE_SEEK_ERR,
	FILE_OPEN_ERR,
	FILE_READ_ERR,
	FILE_WRITE_ERR,
	FILE_NOENOUGH_SPACE_ERR,
	FILE_REMOVE_ERR,
	UPDATE_APP_ERR,
	UPDATE_PARA_ERR,
	UPDATE_FONT_ERR,
	UPDATE_DELETE_ERR,
	UPLOAD_GETTERMINFO_ERR,
	UPLOAD_TERMINFOEX_ERR,
	DECOMPRESS_DATA_ERROR,
	PACKAGE_LENGTH,
	MODEM_ENABLE_TPDU,
	MODEM_INPUT_NII,
	FACTORY_RESET,
	DOWNLOAD_PERCENTAGE,
	PUB_FILE_DOWNLOADING,
	UPDATE_PUB_FILE,
	UPDATE_PUBFILE_FAILED,
	DELETE_PUB_FILE,
	GET_ERROR_CODE,
	UPLOAD_SUCCESS,
	OBTAIN_WL_INFO,
	RSA_PUBKEY,
	DOWNLOADING,
	MAIN_KEY,
	INJECTING,
	DOWNLOAD_SUCCESS,
	RSAKEY_GET_ERROR,
	MAINKEY_GET_ERROR,
	MAINKEY_WRITE_ERROR,
	KEY_DOWNLOAD_ERROR,
	NO_RSAKEY_ERROR,
	KEY_VALIDATE_ERROR,
	RSA_ENCRYPT_ERROR,
	KEY_NUM_ERROR,
	KEY_LENGTH_ERROR,	
	END_DISPLAY_INDEX
}PROTIMS_DISPLAY_INDEX;

#define PROTIMS_DISPLAY_LEN		24

// Ȩ������ Permission Level
// ��ĳ��������ҪPM_MEDIUMȨ�ޣ��򵱴������ΪPM_LOWʱ���˲����������޸�
// for example, if editing a parameter require PM_MEDIUM, then when ucPermission==PM_LOW, user cannot modify it.
enum {PM_LOW, PM_MEDIUM, PM_HIGH, PM_DISABLE};

// PED���� PED type
enum {PED_INT_PXX, PED_INT_PCI, PED_EXT_PP, PED_EXT_PCI};

// GetTermInfo()����Ļ������� Machine type defined in GetTermInfo().
#define _TERMINAL_P60_S_   1
#define _TERMINAL_P70_S_   2
#define _TERMINAL_P60_S1_  3
#define _TERMINAL_P80_     4
#define _TERMINAL_P78_     5
#define _TERMINAL_P90_     6
#define _TERMINAL_S80_	   7  
#define _TERMINAL_SP30_	   8  
#define _TERMINAL_S60_	   9
#define _TERMINAL_S90_	   10

// #define EPSAPP_UPDATEPARAM		100
// #define EPSAPP_GENSUBINFO		110
// #define EPSAPP_DEBITTRANS		200
// #define EPSAPP_NONEPS_DEBIT		250
// #define EPSAPP_TIMEREVENT		400
// #define EPSAPP_RECAP				500
// #define EPSAPP_REPRINT			700
#define TIMER_TEMPORARY		4
#define TIMERCNT_MAX	48000


// ˢ��/�忨�¼�
#define NO_SWIPE_INSERT		0x00	// û��ˢ��/�忨
#define CARD_SWIPED			0x01	// ˢ��
#define CARD_INSERTED		0x02	// �忨
#define CARD_KEYIN			0x04	// ���俨��
#define CARD_TAPPED			0x08    // �ǽӴ���

#define SKIP_DETECT_ICC		0x20	// �����ICC�忨�¼� // ��ֹ�û��ο�����[12/12/2006 Tommy]
#define FALLBACK_SWIPE		0x40	// ˢ��(FALLBACK)
#define SKIP_CHECK_ICC		0x80	// �����service code

#define APPMSG_SYNC				11	// ����manager����Ӧ�ô�����Ϣ
#define EPSAPP_FUNCKEYMSG		800
#define EDC_ECR_MSG				1231
#define EDCAPP_LOADDOWNPARA		1232
#define EDCAPP_GETPARA			1233
#define EDCAPP_AUTOUPDATE		1235
#define APPMSG_CLSS             18
#define AMEX_RETURN				1234


#define EPSAPP_NONEPS_DEBIT		250
#define EPSAPP_RECAP			500
#define EPSAPP_DEBITTRANS		200
#define EPSAPP_TIMEREVENT       400



#define EVENT_GET_NAME		0x2001
#define EVENT_GET_NAME_OK	0x2002

// ϵͳ���ƺ궨��
#define MAX_PLAN 				24
#define MAX_ACQ					16
#define MAX_ISSUER				32
#define MAX_CARD				128
#define MAX_DESCRIPTOR			10
#define MAX_CARDBIN_NUM			800
#define MAX_CARDBIN_ISSUER		250
#define MAX_CARBIN_NAME_LEN		30
#define LEN_MAX_AD_DATA			4000
#ifdef AMT_PROC_DEBUG//2014-9-22
#define MAX_TRANLOG				180
#else
#define MAX_TRANLOG				400		// must <65535
#endif
#define MAX_ERR_LOG				10		// # of EMV error transactions, adjust as needed

#define USER_OPER_TIMEOUT		60		// �û���ʱ����

#define ACQ_ALL					0xFF	// ����Acquirer
#define INV_ACQ_KEY				0xFF	// ��Ч��acquirer key
#define INV_ISSUER_KEY			0xFF	// ��Ч��issuer key

// RFU
#define ECR_NONE		0
#define ECR_BEGIN		1
#define ECR_SUCCEED		2
#define ECR_REJECT		3

//
#ifdef PAYPASS_DEMO
#define PAYWAVE        1
#define PAYPASS		   2
#endif


// EDC ѡ����ʺ궨��(Protims�˿�����)
#define EDC_DATE_FORMAT				0x0040
#define EDC_PRINT_TIME				0x0020
#define EDC_TIP_PROCESS				0x0004
#define EDC_NUM_PRINT_HIGH			0x0180
#define EDC_NUM_PRINT_LOW			0x0140
#define EDC_USE_PRINTER				0x0102
#define EDC_ENABLE_INSTALMENT		0x0222
#define EDC_AUTH_PREAUTH			0x0220
#define EDC_BEA_IP_ENCRY			0x0212     //Gillian 2016-8-1
#define EDC_CASH_PROCESS			0x0210
#define EDC_ECR_ENABLE				0x0208
#define EDC_FREE_PRINT				0x0206
#define EDC_NOT_ADJUST_PWD			0x0320
#define EDC_NOT_MANUAL_PWD			0x0310
#define EDC_NOT_SETTLE_PWD			0x0308
#define EDC_NOT_REFUND_PWD			0x0304
#define EDC_NOT_VOID_PWD			0x0302

#define EDC_NOT_KEYBOARD_LOCKED		0x0301
#define EDC_SELECT_ACQ_FOR_CARD		0x0480
#define EDC_ENABLE_DCC				0x0440
#define EDC_REFERRAL_DIAL			0x0410
#define EDC_LONG_SLIP				0x0408

#define EDC_WINGLUNG_ENCRY			0x0406     //Gillian 20160923
#define EDC_AUTH_PAN_MASKING		0x0402     //Gillian 20160923
//#define EDC_FREE_PRINT				0x0402     //Gillian 20160923


//by Wanglr //Gillian 2016-8-17
//#define EDC_PP_SSL_ENABLE          EDC_PRINT_TIME

#define EDC_PRINT_LOGO_BMP		    0X0104//���L�b�C�i�檺�̤W��//2015-1-7 

#define EDC_EX_RRN_DCCREFUND		0X0001
#define EDC_EX_DCC_PSC				0X0002
#define EDC_EX_INVERSE_RATE			0X0004
#define EDC_EXT_DCC_ADJUST_AMT_NO_DECIMAL  0x0005
#define EDC_EXT_TCP_ENC			    0X0008//2016-2-29 *** //Gillian 2016-7-14
// EDC ��չѡ����ʺ궨��(Protims�˲������ã�������POS���趨)

//...

// ������ѡ����ʺ궨��(Protims�˿�����)
#define ISSUER_EN_ADJUST				0x0080
#define ISSUER_EN_DISCRIPTOR 			0x0040
#define ISSUER_EN_VOICE_REFERRAL		0x0020
#define ISSUER_EN_OFFLINE				0x0010
#define ISSUER_EN_EXPIRY				0x0008
#define ISSUER_EN_MANUAL				0x0004
#define ISSUER_EN_PIN					0x0002
#define ISSUER_EN_ACCOUNT_SELECTION		0x0001
#define ISSUER_NO_PREAUTH				0x0180
#define ISSUER_NO_REFUND				0x0140
#define ISSUER_CHECK_EXPIRY_OFFLINE		0x0110
#define ISSUER_CAPTURE_TXN				0x0108
#define ISSUER_EN_PRINT					0x0104
#define ISSUER_ROC_INPUT_REQ			0x0102
#define ISSUER_CHKPAN_MOD10				0x0101
#define ISSUER_CHKPAN_MOD11				0x0280
#define ISSUER_CHECK_EXPIRY				0x0210
#define ISSUER_AUTH_CODE				0x0208
#define ALLOW_EXTEND_PAY				0x0204
#define ISSUER_ADDTIONAL_DATA			0x0202
#define ISSUER_NO_VOID					0x0201
#define ISSUER_SECURITY_INSERT			0x0390
#define ISSUER_SECURITY_MANUL			0x0380
#define ISSUER_SECURITY_SWIPE			0x0340
#define ISSUER_MASK_EXPIRY				0x0302
#define ISSUER_EN_BALANCE				0x0301

#define ISSUER_EX_DCCREFER				0X0001
#define ISSUER_EX_CHECKIN_RATE			0X0002

#define ISSUER_FORBID_EMVPIN_BYPASS		ISSUER_EN_BALANCE	// or use other option instead, as long as it is not in used.
#define ISSUER_EN_TRACK1				ISSUER_ADDTIONAL_DATA	// or use other option instead, as long as it is not in used.	- Kenny Ting 20100120

// �յ���ѡ����ʺ궨��(Protims�˿�����)
#define ACQ_VISA_CHOICE						0x0080
#define ACQ_PRINT_AUDIT_TRAIL				0x0040
#define ACQ_EXPRESS_PAYMENT_PROMPT			0x0020
#define ACQ_DISABLE_BUSINESS_DATE			0x0010
#define ACQ_IGNORE_HOST_TIME				0x0008
#define ACQ_REQ_OPEN_SUSPEND_BATCH			0x0004
#define ACQ_CLEAR_BATCH						0x0002
#define ACQ_AMEX_SPECIFIC_FEATURE			0x0001
#define ACQ_PRINT_AUTH_CODE					0x0120
#define ACQ_DISABLE_TRICK_FEED				0x0110
#define ACQ_BLOCK_AUTH_FOR_OFFLINE			0x0108
#define ACQ_USE_TRACK3						0x0104
#define ACQ_NOT_PRINT_RRN					0x0102
#define ACQ_ADDTIONAL_PROMPT				0x0101
#define ACQ_CITYBANK_INSTALMENT_FEATURE		0x0240
#define ACQ_DBS_FEATURE						0x0220
#define ACQ_BOC_INSTALMENT_FEATURE			0x0210
#define ACQ_ONLINE_VOID						0x0208
#define ACQ_ONLINE_REFUND					0x0204
#define ACQ_AIR_TICKET						0x0201
#define ACQ_EMV_FEATURE						0x0202
#define ACQ_ASK_CVV2						0x0380

/*----------2015-11-17 KMS START-----------*/
// LOAD Flag
#define LOAD_ALL_FLAG            0x00		// not yet use
#define LOAD_APPL_FLAG           0x01		// enable download application
#define LOAD_PARA_FLAG           0x02		// enable download parameter of app
#define LOAD_DATA_FLAG           0x04		// enable download data file of app
#define LOAD_FONT_MONITOR_FLAG	 0x08		// enable download font and monitor file
#define LOAD_FIRMWARE_FLAG		 0x10		// enable download wireless firmware file
#define LOAD_DELETE_FLAG		 0x20		// enable remote delete app, font

/*KMS Main Flow Chart Error*/
#define KMS_INIT_COMM_ERROR			1001	//
#define KMS_HANDSHAKE_ERROR          	1002  // HANDSHAKE error
#define KMS_RSAKEY_GET_ERROR         		1003
#define KMS_MAINKEY_GET_ERROR         	1004
#define KMS_MAINKEY_WRITE_ERROR         	1005
#define KMS_KEY_DOWNLOAD_ERROR         	1006

// offsets in the string returned by GetTermInfo()
#define HWCFG_MODEL		0
#define HWCFG_PRINTER		1
#define HWCFG_MODEM		2
#define HWCFG_M_SYNC		3
#define HWCFG_M_ASYNC		4
#define HWCFG_PCI			5
#define HWCFG_USBHOST		6
#define HWCFG_USBDEV		7
#define HWCFG_LAN			8
#define HWCFG_GPRS			9
#define HWCFG_CDMA		10
#define HWCFG_WIFI			11
#define HWCFG_CONTACT		12
#define HWCFG_CFONT		13
#define HWCFG_FONTVER		14
#define HWCFG_ICCREAD		15
#define HWCFG_MSR			16
#define HWCFG_WCDMA		18
// 20--29 reserved
#define HWCFG_END		30
// TIMER, TIMEOUT & RETRY DEFINE
#define PROTIMS_RECV_PACKET_TIME_OUT 150   // �����ƾڥ]�W�ɭ���15��
#define PROTIMS_RECV_PACKECT_TIMER   4     // �����ƾڥ]�w�ɾ�
#define PROTIMS_RECV_BYTE_TIMER      3     //
#define PROTIMS_TOTAL_SEND_PACKET_TIMER       2   // �o�e�w�ɾ�
#define PROTIMS_TOTAL_RECEV_PACKET_TIMER      2   // �����w�ɾ�
#define	PROTIMS_COUNT_TIMER			 1	   // �ɶ��`�p�w�ɾ�

#define PROTIMS_RETRY_NUMBER			 2
#define PROTIMS_RECON_NUM				 5    // �L�u���s������

#define PROTIMS_HANDSHAKE_RETRY_TIMES 15  // ����]���o����
#define PROTIMS_DATA_RETRY_TIMES      3   // �ƾڥ]���o����
#define PROTIMS_GET_PLAN_RETRY_TIMES  10  // ����p�����զ���
#define PROTIMS_RECV_CONTROL_BYTE_TIMEOUT     2   // ����r�`�����W�ɮɶ�200ms
#define PROTIMS_RECV_BYTE_TIMEOUT             80  // �����r�`�W�ɮɪ�8��

#define PROTIMS_TOTAL_SEND_PACKET_TIME_OUT    600 // �@�Ӽƾڥ]�o�e�̤j�ɪ�60��
#define PROTIMS_TOTAL_RECEV_PACKET_TIME_OUT   600 // �@�Ӽƾڥ]�����̤j�ɪ�60��
#define PROTIMS_ONE_RECEV_PACKET_TIME_OUT     300


// ProTims command code
#define PROTIMS_MSG_MODEM_OK              0x05
#define PROTIMS_MSG_LOAD_DATA             0x36
#define PROTIMS_MSG_AUTH_TERMINAL         0x37
#define PROTIMS_MSG_GET_TASK_TABLE        0x38
#define PROTIMS_MSG_DOWNLOAD_OK           0x3A
#define PROTIMS_MSG_SIN_AUTH_FLAG         0x3B  //ñ�W�{�ҩR�O�X 
												//20130416
#define PROTIMS_MSG_GET_MULTITASK_TABLE   0X3C  //�ШD������ȦC��]�i��h�ӥ]�^

#define PROTIMS_MSG_NOTIFY_UPDATE_REQ     0x3d   
#define PROTIMS_MSG_GET_PARA_INFO         0x3e   // �d�߰ѼƫH���R�O�r
#define PROTIMS_MSG_SAVE_PARA_INFO_STATUS 0x3f   // �ѼƫH���O�s���A�R�O�X
#define PROTIMS_MSG_SPECIAL_COMMAND       0xF0   // �S��R�O�X

#define PROTIMS_MSG_UPLOAD_REQ        		0x40
#define PROTIMS_MSG_UPLOAD_DATA           	0x41

#define PROTIMS_MSG_GET_RSAKEY				0x51
#define PROTIMS_MSG_GET_MAINKEY				0x52
#define PROTIMS_MSG_GET_KEYSTATE				0x53
/*----------2014-6-3 KMS   END-----------*/

// To keep compatible with S series. Copied from posapi_s80.h
#if defined(_P70_S_) || defined(_P60_S1_)
// Char set
#define CHARSET_WEST        0x01      //������Ӣ������ŷ����        
#define CHARSET_TAI         0x02      //̩��                        
#define CHARSET_MID_EUROPE  0x03      //��ŷ                           
#define CHARSET_VIETNAM     0x04      //Խ��                           
#define CHARSET_GREEK       0x05      //ϣ��                           
#define CHARSET_BALTIC      0x06      //���޵ĺ�                       
#define CHARSET_TURKEY      0x07      //������                         
#define CHARSET_HEBREW      0x08      //ϣ����                          
#define CHARSET_RUSSIAN     0x09      //����˹                        
#define CHARSET_GB2312      0x0A      //��������      
#define CHARSET_GBK         0x0B      //��������     
#define CHARSET_GB18030     0x0C      //��������        
#define CHARSET_BIG5        0x0D      //��������        
#define CHARSET_SHIFT_JIS   0x0E      //�ձ�                          
#define CHARSET_KOREAN      0x0F      //����                           
#define CHARSET_ARABIA      0x10      //������	                          
#define CHARSET_DIY         0x11      //�Զ�������
#endif

// !!!! ����
typedef struct _tagIP_ADDR
{
	uchar		szIP[15+1];
	uchar		szPort[5+1];
}IP_ADDR;

// �ն˴洢EDC��Ϣ
typedef struct _tagEDC_INFO
{
#define EDC_INIT_OK		0x5A5A
	ushort	uiInitFlag;				// 0x5A5A OK
	uchar	szInitTime[14+1];		// YYMMDDhhmmss
	uchar	sInitSTAN[3];			// to be sync to SYS_CONTROL

	uchar	ucDllTracking;			// reserved
	uchar	bClearBatch;			// 0-none, 1-clear former batch
	uchar	ucPrinterType;			// 0-Sprocket, 1-Thermal
	uchar	ucEcrSpeed;				// ECR speed, reserved ?
	uchar	szHelpTelNo[24+1];		// for help function
	uchar	sOption[5];				// option for access
									// sOption[0] = ucOption1
									// sOption[1] = ucOption2
									// sOption[2] = ucOption3
									// sOption[3] = ucPwdMask
									// sOption[4] = ucDialOption

	uchar	sExtOption[8];			// extended option. this option cannot be controlled by Protims.

	uchar	sReserved[4];			// sReserved[0] = ucUnused1
									// sReserved[1..3] = sUnused2

	uchar	szMerchantAddr[46+1];	// line 2 and 3 on invoice
	uchar	szMerchantName[23+1];	// merchant name,line 1
	uchar	szAddlPrompt[20+1];		// for show and print

	uchar	ucLanguage;				// 0-english,1-others 

	CURRENCY_CONFIG	stLocalCurrency;	// local currency name, code, decimal position, ignore digits.
    uchar   szEppType;
	uchar   szEppType2;
	uchar	ucCurrencySymbol;
	uchar	ucTranAmtLen;			// decimal value
	uchar	ucStlAmtLen;			// decimal value

	ulong	ulOfflineLimit;			// �ſ�Floor limit
	ulong	ulNoSignLmtVisa;		//VISA����ǩ���޶�
	ulong	ulNoSignLmtMaster;		//Master����ǩ���޶�
	ulong	ulNoSignLmtAmex;		//Amex����ǩ���޶�
	uchar	ucScrGray;				// LCD����, Ĭ��Ϊ4
	uchar	ucAcceptTimeout;		// ��ʾ���׳ɹ���Ϣ��ʱ��
	uchar	szPabx[10+1];			// ���ߺ���
	uchar	szDownTelNo[25+1];		// ���ص绰����
	uchar	szDownLoadTID[8+1];		// ���ز����ն˺�
// 	uchar	szDownLoadMID[15+1];	// ���ز����̻��� (reserved)
	uchar	szTMSNii[3+1];			// ���ز�����NII
	uchar	ucTMSTimeOut;			// ���ز���ͨѶ��ʱ

	IP_ADDR	stDownIpAddr;			// ���ز�����Զ��IP��ַ

	uchar	bPreDial;				// TRUE: enable pre-dial for modem

	// ����ΪProTims�Զ����µĲ���, ��ʱ���Բ���Ҫ
	uchar	szCallInTime[8+1];		// start(HHMM)+end(hhmm)
	uchar	ucAutoMode;				// 0 none, 1 auto, 2 call in
	uchar	szAutoDayTime[10+1];	// YYMMDDHHmm
	ushort	uiAutoInterval;			// unit: day

	LANG_CONFIG	stLangCfg;			// current using language
	uchar	ucPedMode;				// Current using PED (PxxPED/SxxPED/PP/ExtSxxPED)
	uchar	ucIdleMinute;			// Power Save timeout
	uchar	ucIdleShutdown;			// Shutdown when idle for [ucIdleMinute] minutes have passed.
	
	
#define CLSS_TYPE_NONE 0x00
#define CLSS_TYPE_VISA 0x01
#define CLSS_TYPE_MC   0x02
#define CLSS_TYPE_AE   0x03 //2016-3-31
#define CLSS_TYPE_PBOC 0x04
#define CLSS_TYPE_JSpeedy 0x05 //Gillian 20161101
	
	uchar ucClssFlag;				//�Ƿ�֧��CLSS
	uchar ucClssMode;				//֧��CLSSģʽ, 0,����������ʾ������ 1,����������ʾˢ��, F4�л� 2,�̶����ģʽ
	uchar ucClssFixedAmt[13];		//�̶����
	uchar ucClssPARAFlag;			//�Ƿ�ɹ������˲���
	uchar ucClssRdFlag;				//֧��RD�Ļ���,Ĭ����R50
	int	  iClssLoadNum;				//S80��R50����Ӧ�ó���,�����˼�����
	ulong ulClssSigFlmt;			// No signature floor limit for CLSS
	ulong ulClssOffFLmt;			// Offline floor limit for CLSS
	ulong ulClssMaxLmt;				//�ǽӽ�������
	uchar ucClssComm;				// Comm for CLSS
	uchar ucClssAPID[16+1];         //2015-10-14
	uchar ucCasinoMode;             //�Ƿ�֧�ְ��Ŷĳ�ģʽ 0-��֧�֣� 1-֧��  by Lijy 2010-12-29
    uchar szExchgeRate[12+1];       //���� by Lijy 2010-12-29

	uchar ucClssEnbFlag;			//�Ƿ�֧��CLSS card: 0x01-visa 0x02-Master 0x04-CUP

	uchar ucPANmaskFlag;			//Pan MASK
	uchar  ucINPUT_ONLY;			//key-in only
	uchar ucPrnStlTotalFlag;        //2014-11-4 

#ifdef SUPPORT_TABBATCH
    uchar ucEnableAuthTabBatch;     // �O�_��TAB BATCH�O�s�w���v����O���C��BATCH�W�ߩ�SALE BATCH
    uchar ucTabBatchExpDates;       // TAB BATCH�C�ӰO���̪��O�s�ɶ��]��^�C�W�X���ɶ��h�۰ʧR���C0����H��SALE BATCH����Ӧ۰ʧR��
    uchar ucPreAuthCompPercent;     // �bTAB BATCH�s�b�ɡA�w���v�������B�W�X�w���v���B���̤j���\�ʤ���    
    //uchar ucMSSCBMaxAdjustCnt;      // MAX adjustment times to one transaction
    //uchar szTranMaxAmt[12+1];       // All transactions max amount.
    //uchar szTranMinAmt[12+1];       // All transactions minimum amount.
    //uchar szRefundMaxAmt[12+1];     // Refund�̤j���B�C�L�ȩΪ̬�0�ɤ��ˬd
    //uchar szRefundPwdAmt[12+1];     // Refund�ݭn��J�h�f�K�X�����B
#endif
    // PP DCC
    ushort  uiDccAutoLoadBinPeriod; // PP DCC auto load card bin period
	/*=======BEGIN: Jason BUILD096 2015.05.29  9:50 modify===========*/ //2015-10-14
    ulong ulODCVClssFLmt;                    //on device cardholder verfication contactless transaction limit only used for paypass
    /*====================== END======================== */
	ulong ulForeignCVMLmt;//2015-10-14
	ulong ulForeignOFFLmt;//2015-11-12
}EDC_INFO;

// ������Ϣ
typedef struct _tagCARD_TABLE
{
	uchar	sPanRangeLow[5];		// ������ʼ��
	uchar	sPanRangeHigh[5];		// ������ֹ��
	uchar	ucIssuerKey;			// ����ָ��ķ������
	uchar	ucAcqKey;				// ����ָ����յ����
	uchar	ucPanLength;			// ���ų���, 00Ϊ����鳤��
	uchar	ucOption;				// b1-allow payment
}CARD_TABLE;

// ��������Ϣ
typedef struct _tagISSUER
{
	uchar	ucKey;					// ���
	uchar	szName[10+1];			// ����������
	uchar	szRefTelNo[12*2+1];		// phone # for voice referral

	// sOption[0]:
		// b7-allow adjust, b6-descriptor required
		// b5-voice referral allowed, b4-allow offline
		// b3-expiry required, b2-allow manual pan,
		// b1-pin required, b0-account type selection
		// sOption[1]:
		// b7-inhibit pre-auth, b6-inhibit refund
		// b4-check expiry for offline
		// b3-capture txn, b2-print
		// b1-roc input required, b0-pan MOD 10 check
	// sOption[2]:
		// b7-pan Robinson's MOD 11 check, b4-check expiry
		// b3-omit auth_code display and input for offline
		// b2-extended pay, b1-additional data allowed
		// b0-inhibit void
	// sOption[3]:
		// b6-security code entry
	uchar	sOption[4];

	uchar	ucDefAccount;		// reserved ?
	uchar	sPanMask[3];		// for print slips
								// sPanMask[0]=sReserved[0]
								// sPanMask[1]=sPanMask[1]
								// sPanMask[2]=sPanMask[0]
	ulong	ulFloorLimit;		// unit: cent
	uchar	ucAdjustPercent;
	uchar	ucReserved;			// sReserved[1]
}ISSUER;

typedef struct _tagPHONE_INFO
{
	uchar	szTelNo[12*2+1];
	uchar	ucDialWait;			// by second, time wait after fail
	uchar	ucDialAttempts;		// dial attempt times
}PHONE_INFO;

typedef struct _tagPPP_INFO
{
	uchar	szTelNo[12*2+1];
	uchar	szUserName[20+1];
	uchar	szUserPWD[20+1];
	uchar	szIPAddr[15+1];
	uchar	szIPPort[5+1];
	uchar	ucTimeOut;		//by second, time to wait until failure
}PPP_INFO;

//Gillian 20160923
/*----------2015-11-17 KMS START-----------*/
// communication port
#define PROTIMS_PORT_COM1		0
#define PROTIMS_PORT_COM2		1
#define PROTIMS_PORT_WIRELESS	2
#define PROTIMS_PORT_PINPAD		3
#define PROTIMS_PORT_MODEM		4
#define PROTIMS_PORT_WIFI		5
#define PROTIMS_PORT_USB		10
#define PROTIMS_PORT_USBDEV		11

//������
#define LIB_VER  		"002" 
#define PROTIMS_VER  	"PX02"			//protims Э��

// �q�T�ѼƳ]�m
typedef struct
{
    unsigned char bCommMode;        // 0:Serial, 1:Modem, 2:LAN, 3:GPRS, 4:CDMA, 5:PPP
                           // �ثe���{�U���u�����f�Bmodem�BLAN�MPPP�|�سq�T�Ҧ��A
                           // �Ӥ����GPRS�MCDMA��سq�T�Ҧ�  2005-12-22
                            
    unsigned char szAppName[33];       // ���ΦW�A�Y���ūh�U���Ҧ������ΤΰѼơB�ƾڤ��
    unsigned char bLoadType;        // �U�������Abit0:���ΡAbit1:�ѼƤ��Abit2:�ƾڤ��
    unsigned char psProtocol;       // ��ĳ�H���G0-protims�F1-ftims�F2-tims
    unsigned char bPedMode;         // 0-�~�mPED�]�pPP20�^�@1�Ф��mPED�]P60��S1�AP80�^
                           // �ثe�ӰѼƦbProTims�MTims�����ϥΡA�u�bFTims���ϥ�
                            
    unsigned char bDMK_index;       // �D�K�_���ޡAProTims�����ϥ�
    unsigned char sTransCode[5];    // ����X�A�u�bFTims�b���ϥΡAProTims�MTims�����ϥ�
                           // ����     �t�q
                           // "2001"�G�����ΤU�����
                           // "2011"�G�h���ΤU�����
                           // "1000"�G������POS�d�ߤU������
                           // "1005"�G������POS�d�ߩM�U���b�@���q�T������
                           // "1010"�G�h����POS�d�ߤU������
                           // "1015"�G�h����POS�d�ߩM�U���b�@���q�T������
                            
    unsigned char ucCallMode;    // �եμҦ��A�ثe�ӰѼƦb�ꤺ��ProTims�BFTims�MTims��
                        // ���ϥ� 2005-09-26
    // �b�s�����~��ProTims���ϥθӰѼơA�D�n�O���䨺��}�l�ϥ�P80 2005-10-17
    // ���νեΥ����f������Cbit0~bit3: 0�G�ާ@���D�ʭn�D�F
    // 1�G���p���w�ɡF
    // 2�G�Q���{�A�Ⱦ��I�s�A�ШDmonitor����server����s�q��
    // ����(���f��^�ɡAmonitor�����_�u)�F
    // 3�G(v0.8.0)�Q���{�A�Ⱦ��I�s�A�ШDmonitor�����{�U���ާ@�A
    // �p�Gbit4~bit7=0, P70��monitor�ݭn�Τ�����f�ާ@
    // modem�C
    // bit4~bit7: 0�Gmonitor���ݭn�إ߳q�T�s���F1�Gmonitor
    // �ۤv�إ߳s��
    
    unsigned char szTermID[9];     // �׺ݸ��A�ثe�ӰѼƦb���~����PtoTims�M�s������
                        // �ꤺProTims���ϥ� 2006-04-18
    union
    {
        struct
        {
            unsigned char szPara[16]; //��f�q�T�ѼơA�榡�p"57600,8,n,1"
        }tSerial;  // ��f�q�T�ѼơA�Ѽ�bCommMode=0�ɸӰѼƤ~����
        struct
        {
            unsigned char szTelNo[33];         //�q�ܸ��X�A�ԲӰѦ�ModemDial()���
            COMM_PARA tModPara;  //Modem�q�T�Ѽ�
            unsigned char bTimeout;         //�������\�᪺����[��]
        }tModem;  // modem�q�T�ѼơA�Ѽ�bCommMode=1�ɸӰѼƤ~����
        struct
        {
            unsigned char szLocal_IP_Addr[16];       // ���aIP�a�}�A�bTCP/IP�覡�U�����ϥ�
            unsigned short wLocalPortNo;           	// ���a�ݤf���A�{�b���ϥΡAIP80�Ҷ��|�۰ʨϥ��q�{�ݤf��
            unsigned char szRemote_IP_Addr[16];      // ���{IP�a�}�A�bTCP/IP�覡�U�����ϥ�
            unsigned short wRemotePortNo;          	// ���{�ݤf���A�bTCP/IP�覡�U�����ϥ�
            unsigned char szSubnetMask[16];          //   �l�����X�A�bTCP/IP�覡�U�����ϥ�  2006-04-21
            unsigned char szGatewayAddr[16];         //       �����A�bTCP/IP�覡�U�����ϥ�      2006-04-21
        }tLAN; // TCP/IP��ĳ�q�T�ѼơA�Ѽ�bCommMode=2�ɸӰѼƤ~����
        struct
        {
            unsigned char szAPN[33];          //APN
            unsigned char szUserName[33];     //�Τ�W
            unsigned char szPasswd[33];       //�Τ�K�X
            unsigned char szIP_Addr[16];      //IP�a�}
            unsigned short nPortNo;         //�ݤf��
            unsigned char szPIN_CODE[11];     //�p�GSIM�d���K�X�A�٭n��JPIN�X
            unsigned char szAT_CMD[33];       //�p�G��AT�R�O����
        }tGPRS; // GSM����q�T�ѼơA�Ѽ�bCommMode=3�ɸӰѼƤ~����
        struct
        {
            unsigned char szTelNo[33];        //�q�ܸ��X
            unsigned char szUserName[33];     //�Τ�W
            unsigned char szPasswd[33];       //�Τ�K�X
            unsigned char szIP_Addr[16];      //IP�a�}
            unsigned short nPortNo;         //�ݤf��
            unsigned char szPIN_CODE[11];     //�p�GSIM�d���K�X�A�٭n��JPIN�X
            unsigned char szAT_CMD[33];       //�p�G��AT�R�O����
        }tCDMA; // CDMA����q�T�ѼơA�Ѽ�bCommMode=4�ɸӰѼƤ~����
        struct 
        {
            unsigned char szTelNo[33];        // �q�ܸ��X
            COMM_PARA tModPara; // MODEM�q�H�Ѽ�
            unsigned char szUserName[33];     // �Τ�W
            unsigned char szPasswd[33];       // �Τ�K�X
            unsigned char szIP_Addr[16];      // IP�a�}
            unsigned short nPortNo;         // �ݤf��
        }tPPP; // ���modem���I���I(Point to Point Protocol)���{�U���q�T�ѼơA
               // �Ѽ�bCommMode=5�ɸӰѼƤ~����

		struct //WIFI �Ѽ�bCommMode=6�ɸӰѼƤ~����
		{
			
			unsigned char szWifi_SSID[40];        // SSID
			unsigned char szPasswd[64];       // �Τ�K�X
			
			unsigned char szLocal_IP[16]; // ����IP
			
			unsigned short Local_PortNo;
			
			unsigned char szRemote_IP_Addr[16];      // ���{IP�a�}
			unsigned short RemotePortNo;          // ���{�ݤf��
			unsigned char szSubnetMask[16];          //   �l�����X
			unsigned char szGatewayAddr[16];         //       ����
			unsigned char szDns1[16]; 
			unsigned char szDns2[16]; 	
			unsigned char Encryption_Mode; //  1: WEP 64(ASCII); 2 WEP 128 (ASCII);    3  WPA_TKIP;  4 WPA_AES  	
			unsigned char Encryption_Index; // WEP�ɥΨ��Ƚd��:1~4
			unsigned char DHCP_Flag; // 1:�ϥ�DHCP 
        }tWIFI; 
    }tUnion;
}T_CSCOMMPARA;
/*----------2015-11-17 KMS   END-----------*/


// �յ�����Ϣ
typedef struct _tagACQUIRER
{
//	uchar	ucStatus;	//(�Ƶ�SYS_CONTROL)
	uchar	ucKey;						// ���
	uchar	szPrgName[10+1];			// �������������ƣ�reserved?
	uchar	szName[10+1];				// �յ�������
	uchar	sIssuerKey[MAX_ISSUER];		// ��������Ϣ
	uchar	ucIndex;					// ���յ��е������±�

#define TxnTelNo1	stTxnPhoneInfo[0].szTelNo
#define TxnTelNo2	stTxnPhoneInfo[1].szTelNo
#define StlTelNo1	stStlPhoneInfo[0].szTelNo
#define StlTelNo2	stStlPhoneInfo[1].szTelNo
	PHONE_INFO	stTxnPhoneInfo[2];
	PHONE_INFO	stStlPhoneInfo[2];
	uchar		ucPhoneTimeOut;			// timeout for wait resp

#define TxnTcpIp1	stTxnTCPIPInfo[0].szIP
#define TxnTcpPort1	stTxnTCPIPInfo[0].szPort
#define TxnTcpIp2	stTxnTCPIPInfo[1].szIP
#define TxnTcpPort2	stTxnTCPIPInfo[1].szPort
#define StlTcpIp1	stStlTCPIPInfo[0].szIP
#define StlTcpPort1	stStlTCPIPInfo[0].szPort
#define StlTcpIp2	stStlTCPIPInfo[1].szIP
#define StlTcpPort2	stStlTCPIPInfo[1].szPort
	IP_ADDR		stTxnTCPIPInfo[2];
	IP_ADDR		stStlTCPIPInfo[2];
	uchar		ucTcpTimeOut;

#define TxnPPPIp1	stTxnPPPInfo[0].szIP
#define TxnPPPPort1	stTxnPPPInfo[0].szPort
#define TxnPPPIp2	stTxnPPPInfo[1].szIP
#define TxnPPPPort2	stTxnPPPInfo[1].szPort
#define StlPPPIp1	stStlPPPInfo[0].szIP
#define StlPPPPort1	stStlPPPInfo[0].szPort
#define StlPPPIp2	stStlPPPInfo[1].szIP
#define StlPPPPort2	stStlPPPInfo[1].szPort	
	PPP_INFO	stTxnPPPInfo[2];
	PPP_INFO	stStlPPPInfo[2];
	uchar		ucPppTimeOut;

#define TxnGPRSIp1		stTxnGPRSInfo[0].szIP
#define TxnGPRSPort1	stTxnGPRSInfo[0].szPort
#define TxnGPRSIp2		stTxnGPRSInfo[1].szIP
#define TxnGPRSPort2	stTxnGPRSInfo[1].szPort
#define StlGPRSIp1		stStlGPRSInfo[0].szIP
#define StlGPRSPort1	stStlGPRSInfo[0].szPort
#define StlGPRSIp2		stStlGPRSInfo[1].szIP
#define StlGPRSPort2	stStlGPRSInfo[1].szPort
	IP_ADDR		stTxnGPRSInfo[2];
	IP_ADDR		stStlGPRSInfo[2];	// Since the APN,UID,PWD,SIMPIN are shared, here only store IP,Port for acquirer.
	uchar		ucGprsTimeOut;

	uchar	ucTxnModemMode;		// reserved?
								// 0-bell 1200 sdlc,1-bell 1200 async e71
								// 2-ccitt 1200 sdlc
								// 3-ccitt 1200 async e71,4-bell 300 async e71
								// 5-ccitt 300 async e71,6-ccitt 2400 sdlc,
								// 7-ccitt 2400 async e71,20-ccitt 1200 etsl
	uchar	ucStlModemMode;		// see ucTxnModemMode

	uchar	sCommTypes[8];		// No actual use

	// sOption[0]:
		// b7-visa choice
		// b6-print audit trail after settle
		// b5-express payment prompt
		// b4-disable business date
		// b3-ignore host time
		// b2-request open suspended batch
		// b1-clear batch after initial
		// b0-amex specific feature
	// sOption[1]:
		// b5-prompt auth_code on receipt 1
		// b4-disable trick feed
		// b3-block auth prompt for offline
		// b2-use track
		// b1-no rrn on receipt
		// b0-additional prompt
	// sOption[2]:
		// b3-online void, b2-online refund
	// sOption[3]: // unused
	uchar	sOption[4];

	uchar	szNii[3+1];
	uchar	szTermID[8+1];
	uchar	szMerchantID[15+1];
	ulong	ulCurBatchNo;
	ulong	ulNextBatchNo;
	uchar	szVisa1TermID[23+1];		// reserved
	uchar	sReserved[4];				// reserved
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT	
	//Jerome edit
#define SupportKIN       1    //�Ӧ������EFTSec�C this ACQUIRER Support EFTSec.
#define NotSupportKIN    0    //�Ӧ���椣���EFTSec�C this ACQUIRER don't Support EFTSec. 
#define KeyBlank         0    //key seed is blank, and then the terminal should ask for a key by registration operation
#define KeyNotBlank      1    //key is not blank, and the transaction could begin.
	ulong ulKIN;
	ulong ulKeyIdx;
	uchar ucIsSupportKIN;     //when there havn't have any registration, the value of ucIsSupportKIN should be NotSupportKIN
	uchar ucIsKeyBlank;
	//
#endif
/*----------------2014-5-20 IP encryption----------------*/
}ACQUIRER;

// ���ڸ���ƻ���Ϣ
typedef struct _tagINSTALMENT_PLAN
{
	uchar	ucIndex;		// 1~MAX_PLAN
	uchar	ucAcqIndex;
	uchar	szName[7+1];
	uchar	ucMonths;
	ulong	ulBottomAmt;	// ��ͽ��
    // MS-SCB
    uchar   szDescript[20+1];   // Text description
    uchar   szMaxAmount[12+1];
    uchar   ucWaiverMonth;      // Months don't pay
    uchar   sValidFromDate[4];  // mmddyyyy, BCD
    uchar   sValidToDate[4];    // mmddyyyy, BCD
	uchar   szProgID[6+1];      // Program ID
    uchar   szProductID[4+1];   // Product ID
}INSTALMENT_PLAN;

// ��Ʒ������Ϣ
typedef struct _tagDESCRIPTOR
{
	uchar	ucKey;
	uchar	szCode[2+1];		// ANS format
	uchar	szText[20+1];		// for display and print
}DESCRIPTOR;

// ��ϸ������Ϣ(RFU for HK)
#define LEN_MAX_CARBIN_NAME		30
typedef struct _tagISSUER_NAME
{
	uchar	szChineseName[16+1];
	uchar	szEnglishName[LEN_MAX_CARBIN_NAME+1];
}ISSUER_NAME;

typedef struct _tagCARD_BIN
{
	uchar	ucIssuerIndex;		// ��IssuerName������������
	uchar	ucPanLen;			// ���ų���(reserved)
	uchar	ucMatchLen;			// ƥ��ʱ��ĳ���
	uchar	sStartNo[10];
	uchar	sEndNo[10];
}CARD_BIN;

// �Զ����ز�����Ϣ(RFU for HK),���ڴ��ݲ�����Manager
typedef struct _tagEDC_DOWN_PARAM
{
	uchar	szPabx[10+1];
	uchar	szTermID[8+1];
	uchar	szCallInTime[8+1];		// HHMM-hhmm
	// EDC�����е���ֹʱ��,24ʱ��
	uchar	bEdcSettle;				// 0: not settle 1: settle
	uchar	ucAutoMode;				// 0 none, 1 auto, 2 call in
	uchar	szAutoDayTime[10+1];	// YYMMDDHHmm
}EDC_DOWN_PARAM;

// �������������ݽṹ
// EPSϵͳ����(���ϵͳ����,�����������ϵͳ����)
#define EPS_INITIALIZED			0x55
#define EPS_NOT_INITIALIZED		0x00
#define EPS_TERMINAL_LOCKED		0xAA
#define EPS_TERMINAL_UNLOCKED	0x00
typedef struct _tagEPS_MULTISYS_PARAM
{
	uchar	HYear;			// BCD, for display year with yyyy format

	/* here is only high 2 bytes of yyyy */
	uchar	MerchantPWD[4];			/* ASCII (4 bytes only) */
	uchar	TerminalPWD[4];			/* ASCII (4 bytes only) */
	uchar	BANKPWD[6];				/* ASCII (6 bytes only) */
	uchar	PABX[8];					/* ASCII (8 bytes only) */
	uchar	TelNo[2][25];				/* ASCII (25 bytes only)*2 */
	uchar	Nii[2];					/* BCD */
	uchar	MerchantName[41];		/* ASCII(40 bytes+\x00) */
	uchar	MerchantNo[10];			/* ASCII(9 bytes+\x00) */
	uchar	StoreNo[4];				/* ASCII(3 bytes+\x00) */
	uchar	TerminalNo[4];			/* ASCII(3 bytes+\x00) */
	//----------------------------------------------------
	//BYTE	CurrencySymbol[5][5];	/* for multi-currency, but eps use HKD(..[0][]) noly now. */
	uchar	TXNCode[4];  //for multi-currency, DEFAULT:000
	uchar	CurrencySymbol[4];  //for multi-currency, DEFAULT: HKD
	uchar	CurrencyCode[4];		//for multi-currency, DEFAULT: 344
	//----------------------------------------------------
	uchar	DailMode;				/* 0-sync,1-async*/
	uchar	SSETUP;					/* 0x05-SYN, 0x82-ASYN */
	uchar	AsMode;					/* 0x00-SYN, 0x04 -ASYN */
	uchar	DP;						/* 0x00 */
	uchar	CHDT;					/* 0x00 */
	uchar	DT1;					/* 0x05 */
	uchar	DT2;					/* 0x07 */
	uchar	HT;						/* 70 */
	uchar	WT;						/* 5 */
	uchar	DTIMES;					/* 1 */
	uchar	TimeOut;				/* 0x00 */
	uchar	TerminalLocked;			/* 0-unlocked, 1-locked */
	uchar	TerminalContrast;
	uchar	InitialFlag;

	ushort	AnswerToneWait;
	ushort	RedialWait;
	ushort	WelcomeWait;
	ushort	NextTxnWait;
	ushort	DebitRespWait;
	ushort	NonEPSDebitRespWait;
	ushort	AdmRespWait;
	ushort	ReverseRetryWait;
	ushort	T9Wait;
	ushort	T10Wait;

	uchar	ScrambleTAB1[91];
	uchar	ScrambleTAB2[91];
	uchar	KeyinLimitChar[20];
	uchar	TransType;			// 0-both, 1-eps, 2-noneps
} EPS_MULTISYS_PARAM;

// ����������Ϣ
typedef struct _tagTRAN_CONFIG
{
	uchar	szLabel[16+1];		// ��ʾ�Ľ�������
	uchar	szTxMsgID[4+1];		// �������ͱ�����Ϣ
	uchar	szProcCode[6+1];	// ���״�����ǰ����λ

#define PRN_RECEIPT			0x80
#define WRT_RECORD			0x40
#define IN_SALE_TOTAL		0x20
#define IN_REFUND_TOTAL		0x10
#define VOID_ALLOW			0x08
#define NEED_REVERSAL		0x04
#define ACT_INC_TRACE		0x02
#define NO_ACT				0x00
	uchar	ucTranAct;		// �ý�����Ҫ�Ĺ���
}TRAN_CONFIG;

// ѡ�������Ϣ
typedef struct _tagOPTION_INFO
{
	void	*pText;				// ��ʾ����ʾ
	ushort	uiOptVal;			// λ�á�0304��ʾ byte[3]��0x04λ��
	uchar	ucInverseLogic;		// �Ƿ����߼������� EDC_NOT_SETTLE_PWD
	uchar	ucPermissionLevel;	// ���д��޸�������û�Ȩ��
}OPTION_INFO;

typedef struct _tagHOST_ERR_MSG
{
	uchar	szRspCode[2+1];		// ����������
	uchar	szMsg[16+1];
}HOST_ERR_MSG;

typedef struct _tagTERM_ERR_MSG
{
	int		iErrCode;
	uchar	szMsg[16+1];
}TERM_ERR_MSG;

// ������־
#define	MAX_GET_DESC		4
typedef struct _tagTRAN_LOG
{
	uchar	ucTranType;					// ��������
	uchar	ucOrgTranType;				// ԭ��������
	uchar	szPan[19+1];				// ����
	uchar	szExpDate[4+1];				// ��Ч��
	uchar	szAmount[12+1];				// ���׽��
	uchar	szInitialAmount[12+1];		// ��������Ľ��
	uchar	szTipAmount[12+1];			// С�ѽ��
	uchar	szAbolishedTip[12+1];		// ������δ���� VOID���ϵ�С��
	uchar	szOrgAmount[12+1];			// ԭ���׽��
	uchar	szFrnAmount[12+1];			// ��ҽ��
	uchar	szDateTime[14+1];			// YYYYMMDDhhmmss
	uchar	szRRN[13+1];				// RRN, system ref. no
	uchar	ucAcqKey;					// �յ��б��
	uchar	ucIssuerKey;				// �����б��
//	uchar	szProcCode[6+1];			// ������, Bit 3
	uchar	szCondCode[2+1];			// Bit 25
	uchar	ucDescTotal;				// total # of Descriptor
	uchar	szDescriptor[MAX_GET_DESC+1];
	uchar	szRspCode[2+1];				// ��Ӧ��
	uchar	szHolderName[26+1];
	uchar	szAddlPrompt[20+1];
	uchar	szAuthCode[6+1];
	uchar	ucInstalment;
    uchar   szInstalProgID[6+1];            // MS-SCB : program ID from plan
    uchar   szInstalProductID[4+1];         // MS-SCB : product ID from plan
	CURRENCY_CONFIG	stTranCurrency;
	CURRENCY_CONFIG	stHolderCurrency;
	uchar   ucReversalFlag;//2015-1-23 only for AMEX

	// EMV related data
	uchar	bPanSeqOK;					// TRUE: PAN Seq read OK
	uchar	ucPanSeqNo;
	uchar	sAppCrypto[8];
	uchar	sTVR[5];
	uchar	sTSI[2];
	uchar	sATC[2];
	uchar	szAppLabel[16+1];
	uchar	szAppPreferName[16+1];
	uchar	ucAidLen;
	uchar	sAID[16];
	ushort	uiIccDataLen;
	uchar	sIccData[LEN_ICC_DATA];
	ushort	uiField56Len;
	uchar	sField56[LEN_ICC_DATA2];
	uchar   szCVMRslt[3+1]; //by Gillian 20160629 cvm result  //Gillian 2016-8-12
//	uchar	szEcrRef[10+1];

#define CARDFLAG_FOREIGN	0x01
#define CARDFLAG_LOYALTY	0x02
	uchar	ucCardAttr;

    // PP-DCC
    //------------ DCC --------------
#define PPTXN_DOMESTIC      0x00
#define PPTXN_NOT_ELIGIBLE  0x01    // send to PP host but return "DCC not eligible"
#define PPTXN_DCC		    0x02    // DCC eligible
#define PPTXN_OPTOUT	    0x03    // already opt-out
#define PPTXN_MCP           0x04    // MCP
	uchar	ucDccType;	    	    // PP DCC transaction type
	uchar	szDccRate[LEN_DCC_RATE+2];	    // DCC Rate
	uchar	szInvDccRate[LEN_DCC_RATE+2];	// Inversed DCC Rate. For display only
    uchar   szFrnTip[12+1];			    // ���С�ѽ��
    uchar   sPPDccMarkupRate[3];        // "+\x03\x46" = +3.46
    uchar   szPPDccMarkupTxt[22+1];     // "+Three pt. four six   "
	//Build 1.00.0113
    uchar   szPPDccTxnID[15+1];     // "+TraceId\TxnIdentifier   "
    //-------------------------------

#define	MODE_NO_INPUT			0x0000
#define	MODE_MANUAL_INPUT		0x0001	// ���俨��
#define	MODE_SWIPE_INPUT		0x0002	// �ſ�ˢ��
#define	MODE_CHIP_INPUT			0x0004	// EMV���忨
#define	MODE_FALLBACK_SWIPE		0x0008	// EMVˢ��
#define	MODE_PIN_INPUT			0x0010	// online PIN input
#define MODE_OFF_PIN			0x0020	// for AMEX
#define MODE_SECURITYCODE		0x0040	// CVV/4DBC entered
#define MODE_CONTACTLESS		0x0080	// �ǽӴ�
#define MODE_FALLBACK_MANUAL	0x0100	// ��ʱ����Ҫ,���UOB��Ҫ������
	ushort	uiEntryMode;			// ����ģʽ, �ɼ����Bit 22

	ulong	ulInvoiceNo;			// Ʊ�ݺ�
	ulong	ulSTAN;					// STAN
	ulong	ulOrgSTAN;				// ԭ������ˮ

	uchar   szEcrTxnNo[6+1];        // ECR : TXNNO
    uchar   szEcrConseqNo[4+1];     // ECR : TXN consequential num


#define TS_OK			0x0000		// txn accepted
#define TS_NOSEND		0x0001		// txn not sent to host
#define TS_ADJ			0x0002		// txn adjusted
#define TS_REVD			0x0004		// txn reversed (reserved)
#define TS_VOID			0x0008		// txn voided
#define TS_CHANGE_APPV	0x0010		// �滻Approval Code, reserved
#define TS_FLOOR_LIMIT	0x0020		// ���׽�����Floor Limit
#define TS_OFFLINE_SEND	0x0040		//
#define TS_NOT_UPLOAD	0x0080		// ����Ҫ����(��NOSEND/ADJ�ж�)
#define TS_NEED_TC		0x0100		// ��Ҫ����TC
#define TS_ALL_LOG		0xFFFF
	ushort	uiStatus;				// ����״̬

	//Lijy
	uchar szDebitInAmt[12+1];       //�����Casinoģʽ������Ϊ��Ԫ��������Ϊ��Ԫ
#ifdef AMT_PROC_DEBUG
	//2014-9-18 ttt �N�Ҧ���amt�y�{���B���ʨ�o��
	int     cntAmt;
	uchar	szAmt[30][12+4+1];//2014-9-22 
	uchar	glAmt[30][12+4+1];
#endif
}TRAN_LOG;

#ifdef AMT_PROC_DEBUG
typedef struct _tagECR_AMT//2014-11-4 
{
	uchar szTranType;//0-V/M, 1-CUP
	uchar szTime[6+1];//hhmmss
	uchar szEcrAmt[12+1];//?? number ?[MAX_TRANLOG]
}ECR_AMT;

typedef struct _tagECR_AMT_LOG//2014-11-4 
{
	ECR_AMT glEcrAmtLog[100];
}ECR_AMT_LOG;
#endif

typedef struct _tagWAVE_TXN_OTHER_DATA
{
	uchar ucVLP_IAC_Flg;
	uchar sVLP_IAC[6]; // 9F74
	uchar ucOffSpendAmtFlg;
	uchar sOffSpendAmt[6]; // 9F5D
	uchar ucOnlinePinFlg; // 99 0-online pin not required
	uchar sOnlinePin[8];
	uchar ucSignatureFlg; // 55 0-signature not required
	uchar sSignature[512];
	uchar ucOfflinePinFlg; // 44 0-offline pin not required
	uchar ucOfflinePinReslut; // 0-reader not supported, 1-verified successfully
	uchar ucDDAFailFlg; // 9F4B 1-dda failed,the iss want to send 
	// the offline cryptogram(TC) for online authorizatio
}WAVE_TXN_OTHER_DATA;

typedef struct _tagWAVE_TRANS_DATA
{
	uchar ucSchemeId;
	
	ushort nChipDataLen;
	uchar sChipData[512];
	
	uchar ucOtherDataLen;
	uchar sOtherData[256];
	
	ushort nDDcardTrack1Len;
	uchar szDDcardTrack1[256];
	
	ushort nDDcardTrack2Len;
	uchar szDDcardTrack2[256];
	
	WAVE_TXN_OTHER_DATA stWaveOtherData;
}WAVE_TRANS_DATA;
// ϵͳ���״�����Ϣ,����Ҫ�洢���ļ�ϵͳ
typedef struct _tagSYS_PROC_INFO
{
	TRAN_LOG	stTranLog;
	uchar		szTrack1[79+1];
	uchar		szTrack2[40+1];
	uchar		szTrack3[107+1];

	// ��������Ҫ��,����ݽ��״�������������
	uchar		bIsFallBack;
#define ST_OFFLINE		0
#define ST_ONLINE_FAIL	1
#define ST_ONLINE_APPV	2
	uchar		ucOnlineStatus;		// expansion of "bIsOnlineTxn"
	uchar		bIsFirstGAC;			// �Ƿ��ǵ�һ��GAC
	uchar		ucEcrCtrl;				// ECR��־(RFU)
	uchar		ucEcrRFFlg;				// ECR RF ��־
	uchar		bExpiryError;			// TRUE: ������Ч�ڴ���
	uchar		szSecurityCode[4+1];	// CVV2/4DBC
// 	uchar		bPinEnter;				// �Ƿ�������PIN
	uchar		sPinBlock[8];			// PIN block (RFU)
	uchar		bAutoDownFlag;
	uchar		szSettleMsg[30+1];		// ������Ϣ(������ʾ/��ӡ��)
	ushort		uiRecNo;				// ԭ���׼�¼��(for VOID)
	int			iFallbackErrCode;		// ���fallback��ԭ��(for AMEX)
	uchar		sSessionKey[32];		// �u���[�Ksession key//2016-2-29 *** //Gillian 2016-7-14
	STISO8583	stSendPack;				// ���ͱ��ı���
	uchar       bIfClssTxn;             // �ø�ֵȷ���Ƿ���Ҫ�򿪷ǽ�ͨѶ��
	uchar		ucTrack2Len;			// 2�ŵ�����
	WAVE_TRANS_DATA stWaveTransData;
}SYS_PROC_INFO;

// ���׳�����Ϣ
typedef struct _tagREVERSAL_INFO
{
	uchar			bNeedReversal;		// TRUE����Ҫ����, FALSE: ����Ҫ
	STISO8583		stRevPack;			// ԭ����������
	ushort			uiEntryMode;		// ����ģʽ
}REVERSAL_INFO;

// ͨѶ����
#define	LEN_MAX_COMM_DATA	1024
typedef struct _tagCOMM_DATA
{
	ushort		uiLength;
	uchar		sContent[LEN_MAX_COMM_DATA+10];
}COMM_DATA;

// ���׻�����Ϣ
typedef struct _tagTOTAL_INFO
{
	ushort		uiSaleCnt;
	ushort		uiTipCnt;
	ushort		uiRefundCnt;
	ushort		uiVoidSaleCnt;
	ushort		uiVoidRefundCnt;
	ushort      uiReversalCnt;//2015-1-23 for AMEX field63
	ushort      uiAdjustCnt;//2015-1-23 for AMEX field63

	uchar		szSaleAmt[12+1];	// base amount + tip amount
	uchar		szTipAmt[12+1];
	uchar		szRefundAmt[12+1];
	uchar		szVoidSaleAmt[12+1];
	uchar		szVoidRefundAmt[12+1];

        ushort      uiZeroCount;    // transactions that with amount=0  // HJJ 20110928
}TOTAL_INFO;

// reprint settle information
typedef struct _tagREPRN_STL_INFO
{
	uchar		bValid[MAX_ACQ];
	uchar		szSettleMsg[MAX_ACQ][30];
	ulong		ulBatchNo[MAX_ACQ];
	ulong		ulSOC[MAX_ACQ];
	TOTAL_INFO	stAcqTotal[MAX_ACQ];
	TOTAL_INFO	stIssTotal[MAX_ACQ][MAX_ISSUER];
}REPRN_STL_INFO;

extern MULTIAPP_EVENTS      MultiAppEvent;
#ifdef APP_MANAGER_VER

typedef struct _tagAPP_PARAM
{
#define EXIST_APP_NEW   1
#define EXIST_APP_OLD   2
    uchar		ucExist;        // Whether exist
    uchar       ucAppNo;        // index in the POS
    uchar		ucEnabled;	    // Whether enabled
    uchar       ucEventMode;    // Whether support called by DoEvent(). if NOT, manager only use RunApp() to run it
    APPINFO		stAppInf;
}APP_PARAM;
#endif
typedef struct _tagECR_CONFIG
{
#define ECRMODE_OFF         0
#define ECRMODE_ENABLED		1	// ����ECR
#define ECRMODE_ONLY		2	// ֻ����ECR������
    uchar   ucMode;  // ECRģʽ(�ر�/ģʽ1/ģʽ2/...)
    uchar   ucPort;  // ECR���ں�
#define ECRSPEED_9600       0
#define ECRSPEED_115200     1
    uchar   ucSpeed;
}ECR_CONFIG;
// ϵͳ������Ϣ�����ز��������޸Ĳ�����ʱ�����Ҫ����
typedef struct _tagSYS_PARAM
{
#define LOGON_MODE		0x01
#define CHANGE_MODE 	0x02
#define TRANS_MODE		0x04
#define INIT_MODE		0x08
	uchar				ucTermStatus;		// �ն�״̬

#define _TxnPSTNPara	stTxnCommCfg.stPSTNPara
#define _TxnModemPara	stTxnCommCfg.stPSTNPara.stPara
#define _TxnRS232Para	stTxnCommCfg.stRS232Para
#define _TxnTcpIpPara	stTxnCommCfg.stTcpIpPara
#define _TxnWirlessPara	stTxnCommCfg.stWirlessPara
	COMM_CONFIG			stTxnCommCfg;		// ����ͨѶ����

#define _TmsPSTNPara	stTMSCommCfg.stPSTNPara
#define _TmsModemPara	stTMSCommCfg.stPSTNPara.stPara
#define _TmsRS232Para	stTMSCommCfg.stRS232Para
#define _TmsTcpIpPara	stTMSCommCfg.stTcpIpPara
#define _TmsWirlessPara	stTMSCommCfg.stWirlessPara
	COMM_CONFIG			stTMSCommCfg;		// TMSͨѶ����
	uchar				ucNewTMS;			// TMS�ļ�Э������
	uchar				ucTMSSyncDial;		// ͬ��ģʽ(��modem)

	EDC_INFO			stEdcInfo;			// �ն˲���

	uchar				ucAcqNum;			// �յ�����Ŀ
	ACQUIRER			stAcqList[MAX_ACQ];

	uchar				ucIssuerNum;		// ��������Ŀ
	ISSUER				stIssuerList[MAX_ISSUER];

	uchar				ucCardNum;			// ������Ŀ
	CARD_TABLE			stCardTable[MAX_CARD];

	uchar				ucDescNum;			// ��Ʒ��������
	DESCRIPTOR			stDescList[MAX_DESCRIPTOR];

	uchar				ucPlanNum;			// ���ڸ���ƻ�����
	INSTALMENT_PLAN		stPlanList[MAX_PLAN];

	uchar				sPassword[PWD_MAX][10];	// ��������

	// for HK
	ushort				uiIssuerNameNum;
	ISSUER_NAME			stIssuerNameList[MAX_CARDBIN_ISSUER];
	ushort				uiCardBinNum;
	CARD_BIN			stCardBinTable[MAX_CARDBIN_NUM];
	uchar				bTextAdData;		// False: bitmap TRUE: text
	uchar				sAdData[LEN_MAX_AD_DATA];	// �����Ϣ

	uchar				sTermInfo[HWCFG_END];	// Terminal hardware infomation. for GetTermInfo() use.
#define APMODE_INDEPEND		0		// Current app is app manager.   ��ǰӦ��Ϊ��������ģʽ
#define APMODE_MAJOR		1		// Current app is major sub-app. ��ǰӦ��Ϊ��Ҫ��Ӧ��(EDC for VISA MASTERCARD)
#define APMODE_MINOR		2		// Current app is minor sub-app. ��ǰӦ��Ϊ��Ҫ��Ӧ��(EDC for AE, DINERS, JCB)
	uchar				ucRunMode;
	uchar				ucManagerOn;			// 1--������Ŀǰ��Manager���� 0--���Ǵ�Manager����

#ifdef APP_MANAGER_VER
	
#define APP_EDC			0
#define APP_CUP			1
#define APP_EPS			2
#define APP_AMEX		3
#define APP_EDC_OLD		4
#define APP_OTHER_START	5		// �䥦�l���Ϊ��_�l��m
#define APP_VA			8
#define APP_NUM_MAX		15		// �̦h������l���έӼ�
    APP_PARAM       astSubApp[APP_NUM_MAX];
	uchar           FuncEnable[APP_NUM_MAX][100];
   
    uchar			ucKbSound;				// enable keyboard sound
#define EN_EMV_NORMAL   1
#define EN_EMV_TEST     2
    uchar           ucEnableEMV;            // EMV support. 0--disabled;1--enabled;2--ADVT/TIP
	uchar			ucEnableCLSS;			// CLSS support 0--disabled;1--Idle Amount Clss 2--Fixed Amount CLSS
	uchar			ucClssFixedAmt[13];			// CLSS Fixed Amount
	uchar			ucDecimal;				// ��Ӧ��ʹ�û��ҵ�С����λ 
	uchar			ucEnableDemo;			// Demo mode or not 
#define LANG_ENG    0
#define LANG_CHN    1
#define LANG_BI     2
    uchar           ucLang;
    
    ECR_CONFIG      stECR;
    
    uchar			ucIdleMinute;			// Power Save timeout
    uchar			ucIdleShutdown;			// Shutdown(or not) when idle for [ucIdleMinute] minutes.
#endif


}SYS_PARAM;

// RFU for HK
typedef struct _tagEMV_FIELD56
{
	ushort		uiLength;
	uchar		sData[LEN_ICC_DATA2];
}EMV_FIELD56;

typedef struct _tagWRITE_INFO
{
#define SAVE_NONEED		0
#define SAVE_NEW		1
#define SAVE_UPDATE		2
	uchar		bNeedSave;		// TRUE: should save stTranLog
	uchar		ucAcqIndex;		// acquirer index, must < 255
	ushort		uiRecNo;		// record # of stTranLog
	TRAN_LOG	stTranLog;		// txn information to save
}WRITE_INFO;

#ifdef SUPPORT_TABBATCH
typedef struct _tagAUTH_RECORD_PROFILE 
{
#define LEN_DATE_BCD    7
    uchar   sDateBCD[LEN_DATE_BCD];
    uchar   ucAcqKey;
}AUTH_RECORD_PROFILE;
#endif
// ϵͳ���в�����ÿ�ν��׶����ܽ����޸�,�洢���ļ�ϵͳ
enum {S_RESET, S_SET, S_LOAD, S_INS, S_OUT, S_USE ,S_PENDING, S_CLR_LOG};
typedef struct _tagSYS_CONTROL
{
	ulong			ulSTAN;			// ��ǰ�ն���ˮ��
	ulong			ulInvoiceNo;	// ��ǰƱ�ݺ�
	ushort			uiLastRecNo;	// ���һ�ʽ��׼�¼#
	ushort			uiErrLogNo;		// ��ǰ��¼EMV������־�ļ�¼#
	ushort			uiLastRecNoList[MAX_ACQ];		// for bea
	uchar			sAcqStatus[MAX_ACQ];			// �յ���״̬��Ϣ
	uchar			sAcqKeyList[MAX_TRANLOG];		// ���׼�¼��
	uchar			sIssuerKeyList[MAX_TRANLOG];	// ���׼�¼��
#define LOGIN_MODE		1
#define LOGOFF_MODE		0
	uchar           ucLoginStatus;
	uchar           ucCurrAcqIdx;
	WRITE_INFO		stWriteInfo;	// information for saving txn log

#ifdef SUPPORT_TABBATCH
    AUTH_RECORD_PROFILE astAuthRecProf[MAX_TRANLOG];
	WRITE_INFO		stWriteInfo_TabBatch;
	
	ulong	ulLastAuthInvoiceNo;    //trace no. of last Auth/Pre-Auth transaction
	uchar ucLastTransIsAuth;      //flag - TRUE(last trans is Auth/Pre-Auth) / FALSE (otherwise)
#endif

ushort uiRePrnRecNo;          //build88S: memory position of last printed transaction

#define LEN_SYSCTRL_BASE	((int)OFFSET(SYS_CONTROL, stRevInfo))
	REVERSAL_INFO	stRevInfo[MAX_ACQ];		// ������Ϣ

#define LEN_SYSCTRL_NORMAL	((int)OFFSET(SYS_CONTROL, stRePrnStlInfo))
	REPRN_STL_INFO	stRePrnStlInfo;

	EMV_FIELD56		stField56[MAX_ACQ];		// 56����Ϣ
}SYS_CONTROL;

typedef struct _tagCLSS_INFO
{
	uchar			glAmount[13];//for clss enter amount 
	uchar			bFirstPollFlag;
}CLSS_INFO;
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
//define EFTSec struct by Jerome
extern int glKeyInjectOK;//2015-11-17 add a global flag to identify if key injection is success

typedef struct _tagTriDesKey_Dual
{
	uchar* szK1;
	uchar* szK2;
}TriDesKey_Dual;

//=========================Gillian 20160923================//
/*----------2015-11-17 KMS START-----------*/
#define SECTION_CONFIG						"CONFIG"
// ���ȦC��
typedef struct
{
	unsigned long AllSize;      // ��e���Ȥj�p�ؤo
	unsigned char TaskNo;         // ���ȸ�
	unsigned char TaskType;      // ��������
	unsigned char FileName[33];  // ���W
	unsigned char AppName[33];   // ���ε{�ǦW
	unsigned char vern[21];      // ������
	unsigned char ForceUpdate;	 //�j���s�лx
	unsigned char Rev[5];		// �Χ@�ɻ�
	unsigned char done;          // 0:���U�� 1:�U���� 2:�U������ 3:��s����
}TASK_TABLE;	//total 42 + 4*4 + 22 = 80


typedef struct
{
	unsigned char TeleCode[31];       // �q�ܸ��X
	unsigned char ChkDialTone;
	unsigned long BaudRate;
	unsigned char TimeOut;

	unsigned char m_aIPAddress[24];   // ����IP �a�}�A�Ҽ{��IPV6����6�Ӧr�q�A�n�Ψ�23�Ӧr�`
	unsigned char m_aPppPort[6];      // �ݤf��
	unsigned char m_aUserName[33];    // �Τ�W
	unsigned char m_aPassword[17];    // �K�X

	unsigned char m_psTermID[10];     // �׺ݸ�

	unsigned char m_aLocalIPAddr[24]; // ���aIP �a�}�A�Ҽ{��IPV6����6�Ӧr�q�A�n�Ψ�23�Ӧr�`
	unsigned char m_aSubnetMask[24];  // �l�����X
	unsigned char m_aGatewayAddr[24]; // ����
}MODEM_SETUP;  // ���{�U���t�m�H�����c

#define PROTIMS_DISPLAY_LEN		24
#define  PROTIMS_MAX_TASK                   256//20  // �U�����ȳ̤j�Ӽ�
// global variables
typedef struct PROTIMS_GBVAR
{
	unsigned char g_aucRecvBuff[60*1024];		// recv buff, small buff
	unsigned char g_aucSendBuff[24*1024];		// send buff, huge buff
	unsigned char HostRandom_En[8];
	unsigned char TermRandom_En[8];
	unsigned char M_SN[32];
	unsigned char abyTempStr[40];
	unsigned char abyPwd[40];
	unsigned char abyUserName[64+1];
	unsigned char szPINCode[16];
	unsigned char gbSerialLoad;			// COMM MODE
	unsigned char gbDeleteCurApp;		// �Ƿ�ɾ����ǰӦ�ó���
	unsigned char g_byTcpipDHCPFlag;
	unsigned char bIsChnFont;
	unsigned char g_FileName[32+1];
	unsigned char g_bTosanDial;//modem dial need add TPDU Header
	unsigned char g_bSetTimer;
	unsigned char TPDU_Tosan[8];	// 5λTPDU,suixingpay, verne, 20120611
	unsigned long g_dwPacketLen;
	unsigned long AllLoadSize;
	unsigned long DownloadSize;
	unsigned long ulReservel;
	int gbCrtlBit;						// ���ؿ���
	int g_ErrorCode[2];					// last error code
	unsigned short g_timer;
	char (*pDisplay)[PROTIMS_DISPLAY_LEN];
	TASK_TABLE RemoteTaskTable[PROTIMS_MAX_TASK];
//	PPP_LOG_INFO g_PPPLogInfo;	
	COMM_PARA stModemPara;
	unsigned char g_bRemoteLoadAppFlag;
	int g_bTaskNum;
	unsigned char g_bNewTMSVersion;//new TMS version support upload and PUK download 2013.11.07
	TASK_TABLE PukTaskTable[PROTIMS_MAX_TASK];
	int gPukNum;
	unsigned char PackageSize;//only for wireless mode,default value is 8kB 
	unsigned char CurAppNo;//Current App number.0xff->monitor; 0->MAIN APP; 1~23 ->Normal APP
	//T_POS_HARD_INFO stHardInfo;
	//unsigned char szRemoteIPAddr[16];
	unsigned char sTmpMKey[16];
}SProtims_gbVar;

extern SProtims_gbVar p_gbVars;	// �s������ܶq�����c�A����P�Τ᪺�����ܶq���W�A�K��޲z
extern char DISPLAY_KEY[][PROTIMS_DISPLAY_LEN];
extern char DISPLAY_LANGUAGE[][PROTIMS_DISPLAY_LEN];
extern char DISPLAY_DEFAULT[][PROTIMS_DISPLAY_LEN];
extern char DISPLAY_CN[][PROTIMS_DISPLAY_LEN];
//=========================end Gillian 20160923 ================//

//End of Jerome's define
#endif
/*----------------2014-5-20 IP encryption----------------*/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern SYS_PARAM		glSysParam, glSysParamBak;		// ϵͳ���ò���
extern SYS_CONTROL		glSysCtrl;		// ϵͳ���Ʋ���
extern SYS_PROC_INFO	glProcInfo;		// ���״�����Ϣ

extern uchar  glClssCVMFlag;//2016-4-25
#ifdef AMT_PROC_DEBUG//2014-11-4
extern ECR_AMT_LOG      glEcrAMT;//2014-11-4MAX_TRANLOG
extern uchar glEcrAmtCnt;
#endif
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
//control info of EFTSec
typedef struct _tagEFTSec_Control
{	
//	TriDesKey_Dual stTriDeskey;
	// head of tpdu and EDS
	uchar ucEDSControl;
	ulong ulEDSStart;
	ulong ulEDSKIN;
	ulong ulEDSLength;
	uchar ucEDSChecksum;
	uchar ucTPDUid;
	uchar strTPDUNII[2];
	uchar strTPDUSRC[2];
	
	uchar ucKeyIdx; //the index of TDK
	ulong ulDataLen;
//	uchar ucMacMode; //the para mode of function PedGetMac
//	char  szFileOfKeyIdx[16];//file name for getting key index 
}EFTSec_Control;

#endif
/*----------------2014-5-20 IP encryption----------------*/
extern COMM_DATA		glSendData, glRecvData, glSendDataDebug, glRecvDataDebug;		// ͨѶ����//2014-9-1
extern STISO8583		glSendPack;		// ���ͱ���
extern STISO8583		glRecvPack;		// ���ձ���

extern STTMS8583		glTMSSend;		// TMS���ͱ���
extern STTMS8583		glTMSRecv;		// TMS���ձ���

extern ST_EVENT_MSG		*glEdcMsgPtr;	// �������¼�

extern ACQUIRER			glCurAcq;		// ��ǰ�յ���
extern ISSUER			glCurIssuer;	// ��ǰ������

extern COMM_CONFIG		glCommCfg;		// ��ǰͨѶ���ò���

extern TOTAL_INFO		glAcqTotal[MAX_ACQ];		// �յ��л�����Ϣ
extern TOTAL_INFO		glIssuerTotal[MAX_ISSUER];	// �����л�����Ϣ
extern TOTAL_INFO		glEdcTotal;		// �ն˻�����Ϣ
extern TOTAL_INFO		glTransTotal;	// ���״���ʹ�õĻ�����Ϣ
extern TOTAL_INFO		glPrnTotal;		// ���ݴ�ӡʹ�õĻ�����Ϣ
extern uchar           glLastPageOfSettle;
#ifdef ENABLE_EMV
extern EMV_PARAM		glEmvParam;
extern EMV_STATUS		glEmvStatus;
#endif

extern const LANG_CONFIG glLangList[];
extern const CURRENCY_CONFIG glCurrency[];

extern TRAN_CONFIG		glTranConfig[];

extern HOST_ERR_MSG		glHostErrMsg[];
extern HOST_ERR_MSG		glHostErrMsg_AE_Sett[];
extern HOST_ERR_MSG		glHostErrMsg_AE_Tran[];
extern TERM_ERR_MSG		glTermErrMsg[];
extern int HardCodeFlag; //Gillian 20160803 Gillian 20160923
#ifdef _S_SERIES_                 //raymond 27 Jun 2011: SXX EPS implementation
uchar glReversalPending;       //0 - no reversal pending, 1 - reversal pending
#endif
extern	uchar			glAmount[13];
extern uchar bFirstPollFlag;
extern CLSS_INFO glClssInfo;
extern uchar gucIsPayWavePass;
extern int	iWLBfd;
extern uchar ucWLBBuf[2];		//��ʱbuf
extern uchar    glKeyValue;
extern  uchar  sg_bWaveInitPara;

//W204
extern int      EPS_AutoRecap;
extern char     EPS_Recap_Time[4+1];
extern char     EPS_Last_Recap_Date[4+1];
//end W204

typedef uchar (*FNPTR_EcrSend)(uchar *psData, ushort usLen);
extern 	FNPTR_EcrSend   FuncEcrSend;
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
/************************************************************************/
/* defined by jerome                                                    */
/************************************************************************/
int glKeyInjectOK;//2015-11-17 add a global flag to identify if key injection is success
extern uchar glTSI[2];  //Gillian 20161020
extern uchar glTVR[5];  //Gillian 20161020
extern uchar glCVMR[5];
extern uchar glCVR[32];
extern int INSTAL_VOID;  //Gillian 20161020
extern uchar glTemp[1];  //Gillian 20161101
extern EFTSec_Control glEFTSec_Control;   //�[�K���媺EDS�H���M�K�_�H���C
/* end of Jerome*/
#endif
/*----------------2014-5-20 IP encryption----------------*/

extern char *strstr(const char *, const char *);
//extern int vsprintf(char *buffer, const char *format, va_list argptr);

extern void Richard_test(); //add by richard for function test

#ifdef __cplusplus
}
#endif /* __cplusplus */
//extern uchar         glPwd[6+1];//2014-11-17 Gillian 20161010
//#define Gillian debug
#define EMV_DEBUG
#endif	// _GLOBAL_H

// end of file











