
/*********************************************************************************
NAME
    global.h - 隅砱鼠僕杅擂賦凳

DESCRIPTION
    隅砱茼蚚腔�姥眻靾�/�姥硈�講脹

REFERENCE

MODIFICATION SHEET:
    MODIFIED   (YYYY.MM.DD)
    shengjx     2006.09.12      - created
*********************************************************************************/

#ifndef _GLOBAL_H
#define _GLOBAL_H

/*********************************************************************************
扢隅剒猁晤祒腔儂倰
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
扢隅跪砐杻俶羲ゐ/壽敕
Set to correct macro before compile
*********************************************************************************/
#define APP_MANAGER_VER	// When build this app as manager, should enable this macro 絞晤祒翋茼蚚奀ㄛ羲ゐ森粽隅砱
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

// Coordination app-manager name 茼蚚奪燴ん靡備(�蝜�衄)
#define APPNAME_MANAGER		"EDC MANAGER"

#define WAIT_CARDHOLDER_CHOICE    //PP DCC, wait until card holder made a choice

/*********************************************************************************
Application attribute 茼蚚扽俶(靡備, ID, 唳掛)
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
#define EDC_VER_PUB		"1.00"			// 鼠僕唳掛瘍. Public version number

#define EDC_VER_INTERN	"1.00.204T"
#else
#define EDC_VER_PUB		"1.00"			// 鼠僕唳掛瘍. Public version number
                         //2016-2-5 AMEX Express
#define EDC_VER_INTERN	"1.00.0222C"	// 孺桯唳掛瘍(ヶ窒煦茼睿鼠僕唳掛瘍珨祡). Extend version number. should be same as EDC_VER_INTERN's heading.

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
Features of specific area 華⑹蚳衄扽俶
*********************************************************************************/
//#define AREA_TAIWAN
#define AREA_HK
//#define AREA_SG
//#define AREA_VIETNAM		// Vietnam
//#define AREA_KH			// Cambodia

/*********************************************************************************
EMV terminal capability EMV笝傷夔薯饜离
*********************************************************************************/
#define EMV_CUP_CAPABILITY  "\xE0\xF0\xC8"  //added only for indirect cup card
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
//因為PAYPASS Reader要求的終端能力跟EMV不一致，所以增加了該項宏定義。
#ifdef PAYPASS_CAPABILITY
//#define EMV_CLSS_CAPABILITY	"\xE0\xB0\xC8"
//#define EMV_CLSS_CAPABILITY	"\xE0\xB8\xC8"
#define EMV_CLSS_CAPABILITY	"\xE0\xB0\xC8"
#endif


/*********************************************************************************
眕狟隅砱躺婓曹載最唗髡夔扽俶奀党蜊﹝�蝜�議虳杻俶睿森儂倰岆堂隅腔ㄛ③婓森隅砱
蛁砩ㄩす奀③祥猁忒雄羲ゐ/壽敕狟蹈粽﹝涴虳粽腔羲壽茼蚕ヶ醱腔粽岆瘁眒掩隅砱奧赻雄樵隅岆瘁羲ゐ
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
#define PXX_COMM				// P80/P90腔IP耀輸拸盄耀輸籵捃源宒
#endif

#ifdef _P58_
#endif

#ifdef USE_EXTEND_PXXCOM
#define PXX_COMM
#endif

// 蛁砩ㄩ珩衄窒煦橾S80祥盓厥SXX_WIRELESS_MODULE
#ifdef _S_SERIES_
#define SXX_IP_MODULE			//S80腔IP耀輸籵捃源宒
#define SXX_WIRELESS_MODULE		//S炵蹈拸盄耀輸
//#define IP_INPUT            //raymond 3 Jun 2010: Input IP without typing dot '.'
#endif

// 釬蚚ㄩ婓GCC遠噫狟扢隅趼誹勤ょ
#if defined(_WIN32) || defined(_WINDOWS)
	#define PACK_STRUCT
#elif defined(_P80_) || defined(_P90_) || defined(_P78_) || defined(_S_SERIES_) || defined(_SP30_)
	#define PACK_STRUCT		__attribute__((packed))
#else
	#define PACK_STRUCT
#endif

#include "Stdarg.h"

// 婓涴爵氝樓斕腔馱最腔芛恅璃
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

// 躇鎢濬倰 Password type
enum {PWD_BANK, PWD_TERM, PWD_MERCHANT, PWD_VOID, PWD_REFUND, PWD_ADJUST, PWD_SETTLE, PWD_MAX};

// DHCP flag
#define PROTIMS_DHCP_NO_SUPPORT            0  // 不支持DHCP
#define PROTIMS_DHCP_SUPPORT               1  // 支持DHCP

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

// �使瓿閛� Permission Level
// �蠙雩鹺髲譜骳枉M_MEDIUM�使煚皈繺探客貒恀�峈PM_LOW奀ㄛ森統杅祥埰勍掩党蜊
// for example, if editing a parameter require PM_MEDIUM, then when ucPermission==PM_LOW, user cannot modify it.
enum {PM_LOW, PM_MEDIUM, PM_HIGH, PM_DISABLE};

// PED濬倰 PED type
enum {PED_INT_PXX, PED_INT_PCI, PED_EXT_PP, PED_EXT_PCI};

// GetTermInfo()爵醱腔儂ん濬倰 Machine type defined in GetTermInfo().
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


// 芃縐/脣縐岈璃
#define NO_SWIPE_INSERT		0x00	// 羶衄芃縐/脣縐
#define CARD_SWIPED			0x01	// 芃縐
#define CARD_INSERTED		0x02	// 脣縐
#define CARD_KEYIN			0x04	// 忒怀縐瘍
#define CARD_TAPPED			0x08    // 準諉揖縐

#define SKIP_DETECT_ICC		0x20	// 祥潰脤ICC脣縐岈璃 // 滅砦蚚誧匿縐徹辦[12/12/2006 Tommy]
#define FALLBACK_SWIPE		0x40	// 芃縐(FALLBACK)
#define SKIP_CHECK_ICC		0x80	// 祥潰脤service code

#define APPMSG_SYNC				11	// 蚚衾manager砃赽茼蚚換菰陓洘
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

// 炵苀癹秶粽隅砱
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

#define USER_OPER_TIMEOUT		60		// 蚚誧閉奀扢离

#define ACQ_ALL					0xFF	// 垀衄Acquirer
#define INV_ACQ_KEY				0xFF	// 拸虴腔acquirer key
#define INV_ISSUER_KEY			0xFF	// 拸虴腔issuer key

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


// EDC 恁砐溼恀粽隅砱(Protims傷褫扢离)
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

#define EDC_PRINT_LOGO_BMP		    0X0104//打印在每張單的最上方//2015-1-7 

#define EDC_EX_RRN_DCCREFUND		0X0001
#define EDC_EX_DCC_PSC				0X0002
#define EDC_EX_INVERSE_RATE			0X0004
#define EDC_EXT_DCC_ADJUST_AMT_NO_DECIMAL  0x0005
#define EDC_EXT_TCP_ENC			    0X0008//2016-2-29 *** //Gillian 2016-7-14
// EDC 孺桯恁砐溼恀粽隅砱(Protims傷祥褫扢离ㄛ斛剕婓POS奻扢隅)

//...

// 楷縐俴恁砐溼恀粽隅砱(Protims傷褫扢离)
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

// 彶等俴恁砐溼恀粽隅砱(Protims傷褫扢离)
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
#define PROTIMS_RECV_PACKET_TIME_OUT 150   // 接收數據包超時限制15秒
#define PROTIMS_RECV_PACKECT_TIMER   4     // 接收數據包定時器
#define PROTIMS_RECV_BYTE_TIMER      3     //
#define PROTIMS_TOTAL_SEND_PACKET_TIMER       2   // 發送定時器
#define PROTIMS_TOTAL_RECEV_PACKET_TIMER      2   // 接收定時器
#define	PROTIMS_COUNT_TIMER			 1	   // 時間總計定時器

#define PROTIMS_RETRY_NUMBER			 2
#define PROTIMS_RECON_NUM				 5    // 無線重連接次數

#define PROTIMS_HANDSHAKE_RETRY_TIMES 15  // 握手包重發次數
#define PROTIMS_DATA_RETRY_TIMES      3   // 數據包重發次數
#define PROTIMS_GET_PLAN_RETRY_TIMES  10  // 獲取計劃嘗試次數
#define PROTIMS_RECV_CONTROL_BYTE_TIMEOUT     2   // 控制字節接收超時時間200ms
#define PROTIMS_RECV_BYTE_TIMEOUT             80  // 接收字節超時時長8秒

#define PROTIMS_TOTAL_SEND_PACKET_TIME_OUT    600 // 一個數據包發送最大時長60秒
#define PROTIMS_TOTAL_RECEV_PACKET_TIME_OUT   600 // 一個數據包接收最大時長60秒
#define PROTIMS_ONE_RECEV_PACKET_TIME_OUT     300


// ProTims command code
#define PROTIMS_MSG_MODEM_OK              0x05
#define PROTIMS_MSG_LOAD_DATA             0x36
#define PROTIMS_MSG_AUTH_TERMINAL         0x37
#define PROTIMS_MSG_GET_TASK_TABLE        0x38
#define PROTIMS_MSG_DOWNLOAD_OK           0x3A
#define PROTIMS_MSG_SIN_AUTH_FLAG         0x3B  //簽名認證命令碼 
												//20130416
#define PROTIMS_MSG_GET_MULTITASK_TABLE   0X3C  //請求獲取任務列表（可能多個包）

#define PROTIMS_MSG_NOTIFY_UPDATE_REQ     0x3d   
#define PROTIMS_MSG_GET_PARA_INFO         0x3e   // 查詢參數信息命令字
#define PROTIMS_MSG_SAVE_PARA_INFO_STATUS 0x3f   // 參數信息保存狀態命令碼
#define PROTIMS_MSG_SPECIAL_COMMAND       0xF0   // 特殊命令碼

#define PROTIMS_MSG_UPLOAD_REQ        		0x40
#define PROTIMS_MSG_UPLOAD_DATA           	0x41

#define PROTIMS_MSG_GET_RSAKEY				0x51
#define PROTIMS_MSG_GET_MAINKEY				0x52
#define PROTIMS_MSG_GET_KEYSTATE				0x53
/*----------2014-6-3 KMS   END-----------*/

// To keep compatible with S series. Copied from posapi_s80.h
#if defined(_P70_S_) || defined(_P60_S1_)
// Char set
#define CHARSET_WEST        0x01      //藝弊﹜荎弊摯昹韁弊模        
#define CHARSET_TAI         0x02      //怍弊                        
#define CHARSET_MID_EUROPE  0x03      //笢韁                           
#define CHARSET_VIETNAM     0x04      //埣鰍                           
#define CHARSET_GREEK       0x05      //洷幫                           
#define CHARSET_BALTIC      0x06      //疏蹕腔漆                       
#define CHARSET_TURKEY      0x07      //芩嫉む                         
#define CHARSET_HEBREW      0x08      //洷皎懂                          
#define CHARSET_RUSSIAN     0x09      //塘蹕佴                        
#define CHARSET_GB2312      0x0A      //潠极笢恅      
#define CHARSET_GBK         0x0B      //潠极笢恅     
#define CHARSET_GB18030     0x0C      //潠极笢恅        
#define CHARSET_BIG5        0x0D      //楛极笢恅        
#define CHARSET_SHIFT_JIS   0x0E      //�梇�                          
#define CHARSET_KOREAN      0x0F      //澈弊                           
#define CHARSET_ARABIA      0x10      //陝嶺皎	                          
#define CHARSET_DIY         0x11      //赻隅砱趼极
#endif

// !!!! 陔崝
typedef struct _tagIP_ADDR
{
	uchar		szIP[15+1];
	uchar		szPort[5+1];
}IP_ADDR;

// 笝傷湔揣EDC陓洘
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

	ulong	ulOfflineLimit;			// 棠縐Floor limit
	ulong	ulNoSignLmtVisa;		//VISA祥剒ワ靡癹塗
	ulong	ulNoSignLmtMaster;		//Master祥剒ワ靡癹塗
	ulong	ulNoSignLmtAmex;		//Amex祥剒ワ靡癹塗
	uchar	ucScrGray;				// LCD謠僅, 蘇�玴�4
	uchar	ucAcceptTimeout;		// 珆尨蝠眢傖髡陓洘腔奀潔
	uchar	szPabx[10+1];			// 俋盄瘍鎢
	uchar	szDownTelNo[25+1];		// 狟婥萇趕瘍鎢
	uchar	szDownLoadTID[8+1];		// 狟婥統杅笝傷瘍
// 	uchar	szDownLoadMID[15+1];	// 狟婥統杅妀誧瘍 (reserved)
	uchar	szTMSNii[3+1];			// 狟婥統杅腔NII
	uchar	ucTMSTimeOut;			// 狟婥統杅籵捅閉奀

	IP_ADDR	stDownIpAddr;			// 狟婥統杅腔堈最IP華硊

	uchar	bPreDial;				// TRUE: enable pre-dial for modem

	// 眕狟峈ProTims赻雄載陔腔統杅, 婃奀褫眕祥剒猁
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
	
	uchar ucClssFlag;				//岆瘁盓厥CLSS
	uchar ucClssMode;				//盓厥CLSS耀宒, 0,渾儂賜醱枑尨怀�踳蘤� 1,渾儂賜醱枑尨芃縐, F4з遙 2,嘐隅踢塗耀宒
	uchar ucClssFixedAmt[13];		//嘐隅踢塗
	uchar ucClssPARAFlag;			//岆瘁傖髡換菰賸統杅
	uchar ucClssRdFlag;				//盓厥RD腔儂ん,蘇�珅ズ50
	int	  iClssLoadNum;				//S80跤R50狟婥茼蚚最唗,狟婥賸撓跺婦
	ulong ulClssSigFlmt;			// No signature floor limit for CLSS
	ulong ulClssOffFLmt;			// Offline floor limit for CLSS
	ulong ulClssMaxLmt;				//準諉蝠眢奻癹
	uchar ucClssComm;				// Comm for CLSS
	uchar ucClssAPID[16+1];         //2015-10-14
	uchar ucCasinoMode;             //岆瘁盓厥凰藷傭部耀宒 0-祥盓厥ㄛ 1-盓厥  by Lijy 2010-12-29
    uchar szExchgeRate[12+1];       //颯薹 by Lijy 2010-12-29

	uchar ucClssEnbFlag;			//岆瘁盓厥CLSS card: 0x01-visa 0x02-Master 0x04-CUP

	uchar ucPANmaskFlag;			//Pan MASK
	uchar  ucINPUT_ONLY;			//key-in only
	uchar ucPrnStlTotalFlag;        //2014-11-4 

#ifdef SUPPORT_TABBATCH
    uchar ucEnableAuthTabBatch;     // 是否有TAB BATCH保存預授權交易記錄。此BATCH獨立於SALE BATCH
    uchar ucTabBatchExpDates;       // TAB BATCH每個記錄最長保存時間（日）。超出此時間則自動刪除。0表示隨著SALE BATCH結算而自動刪除
    uchar ucPreAuthCompPercent;     // 在TAB BATCH存在時，預授權完成金額超出預授權金額的最大允許百分比    
    //uchar ucMSSCBMaxAdjustCnt;      // MAX adjustment times to one transaction
    //uchar szTranMaxAmt[12+1];       // All transactions max amount.
    //uchar szTranMinAmt[12+1];       // All transactions minimum amount.
    //uchar szRefundMaxAmt[12+1];     // Refund最大金額。無值或者為0時不檢查
    //uchar szRefundPwdAmt[12+1];     // Refund需要輸入退貨密碼的金額
#endif
    // PP DCC
    ushort  uiDccAutoLoadBinPeriod; // PP DCC auto load card bin period
	/*=======BEGIN: Jason BUILD096 2015.05.29  9:50 modify===========*/ //2015-10-14
    ulong ulODCVClssFLmt;                    //on device cardholder verfication contactless transaction limit only used for paypass
    /*====================== END======================== */
	ulong ulForeignCVMLmt;//2015-10-14
	ulong ulForeignOFFLmt;//2015-11-12
}EDC_INFO;

// 縐桶陓洘
typedef struct _tagCARD_TABLE
{
	uchar	sPanRangeLow[5];		// 縐瘍れ宎瘍
	uchar	sPanRangeHigh[5];		// 縐瘍笝砦瘍
	uchar	ucIssuerKey;			// 縐桶硌砃腔楷縐桶瘍
	uchar	ucAcqKey;				// 縐桶硌砃腔彶等桶瘍
	uchar	ucPanLength;			// 縐瘍酗僅, 00峈祥潰脤酗僅
	uchar	ucOption;				// b1-allow payment
}CARD_TABLE;

// 楷縐俴陓洘
typedef struct _tagISSUER
{
	uchar	ucKey;					// 桶瘍
	uchar	szName[10+1];			// 楷縐俴靡備
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

//版本號
#define LIB_VER  		"002" 
#define PROTIMS_VER  	"PX02"			//protims 衪祜

// 通訊參數設置
typedef struct
{
    unsigned char bCommMode;        // 0:Serial, 1:Modem, 2:LAN, 3:GPRS, 4:CDMA, 5:PPP
                           // 目前遠程下載只支持串口、modem、LAN和PPP四種通訊模式，
                           // 而不支持GPRS和CDMA兩種通訊模式  2005-12-22
                            
    unsigned char szAppName[33];       // 應用名，若為空則下載所有的應用及參數、數據文件
    unsigned char bLoadType;        // 下載類型，bit0:應用，bit1:參數文件，bit2:數據文件
    unsigned char psProtocol;       // 協議信息：0-protims；1-ftims；2-tims
    unsigned char bPedMode;         // 0-外置PED（如PP20）　1－內置PED（P60－S1，P80）
                           // 目前該參數在ProTims和Tims中不使用，只在FTims中使用
                            
    unsigned char bDMK_index;       // 主密鑰索引，ProTims中不使用
    unsigned char sTransCode[5];    // 交易碼，只在FTims在中使用，ProTims和Tims中不使用
                           // 取值     含義
                           // "2001"：單應用下載交易
                           // "2011"：多應用下載交易
                           // "1000"：單應用POS查詢下載任務
                           // "1005"：單應用POS查詢和下載在一次通訊內完成
                           // "1010"：多應用POS查詢下載任務
                           // "1015"：多應用POS查詢和下載在一次通訊內完成
                            
    unsigned char ucCallMode;    // 調用模式，目前該參數在國內版ProTims、FTims和Tims中
                        // 不使用 2005-09-26
    // 在新版海外版ProTims中使用該參數，主要是香港那邊開始使用P80 2005-10-17
    // 應用調用本接口的控制。bit0~bit3: 0：操作員主動要求；
    // 1：按計劃定時；
    // 2：被遠程服務器呼叫，請求monitor接收server的更新通知
    // 消息(接口返回時，monitor不能斷線)；
    // 3：(v0.8.0)被遠程服務器呼叫，請求monitor做遠程下載操作，
    // 如果bit4~bit7=0, P70的monitor需要用內部串口操作
    // modem。
    // bit4~bit7: 0：monitor不需要建立通訊連接；1：monitor
    // 自己建立連接
    
    unsigned char szTermID[9];     // 終端號，目前該參數在海外版本PtoTims和新版本的
                        // 國內ProTims中使用 2006-04-18
    union
    {
        struct
        {
            unsigned char szPara[16]; //串口通訊參數，格式如"57600,8,n,1"
        }tSerial;  // 串口通訊參數，參數bCommMode=0時該參數才有效
        struct
        {
            unsigned char szTelNo[33];         //電話號碼，詳細參考ModemDial()函數
            COMM_PARA tModPara;  //Modem通訊參數
            unsigned char bTimeout;         //撥號成功後的延時[秒]
        }tModem;  // modem通訊參數，參數bCommMode=1時該參數才有效
        struct
        {
            unsigned char szLocal_IP_Addr[16];       // 本地IP地址，在TCP/IP方式下必須使用
            unsigned short wLocalPortNo;           	// 本地端口號，現在不使用，IP80模塊會自動使用默認端口號
            unsigned char szRemote_IP_Addr[16];      // 遠程IP地址，在TCP/IP方式下必須使用
            unsigned short wRemotePortNo;          	// 遠程端口號，在TCP/IP方式下必須使用
            unsigned char szSubnetMask[16];          //   子網掩碼，在TCP/IP方式下必須使用  2006-04-21
            unsigned char szGatewayAddr[16];         //       網關，在TCP/IP方式下必須使用      2006-04-21
        }tLAN; // TCP/IP協議通訊參數，參數bCommMode=2時該參數才有效
        struct
        {
            unsigned char szAPN[33];          //APN
            unsigned char szUserName[33];     //用戶名
            unsigned char szPasswd[33];       //用戶密碼
            unsigned char szIP_Addr[16];      //IP地址
            unsigned short nPortNo;         //端口號
            unsigned char szPIN_CODE[11];     //如果SIM卡有密碼，還要輸入PIN碼
            unsigned char szAT_CMD[33];       //如果有AT命令的話
        }tGPRS; // GSM手機通訊參數，參數bCommMode=3時該參數才有效
        struct
        {
            unsigned char szTelNo[33];        //電話號碼
            unsigned char szUserName[33];     //用戶名
            unsigned char szPasswd[33];       //用戶密碼
            unsigned char szIP_Addr[16];      //IP地址
            unsigned short nPortNo;         //端口號
            unsigned char szPIN_CODE[11];     //如果SIM卡有密碼，還要輸入PIN碼
            unsigned char szAT_CMD[33];       //如果有AT命令的話
        }tCDMA; // CDMA手機通訊參數，參數bCommMode=4時該參數才有效
        struct 
        {
            unsigned char szTelNo[33];        // 電話號碼
            COMM_PARA tModPara; // MODEM通信參數
            unsigned char szUserName[33];     // 用戶名
            unsigned char szPasswd[33];       // 用戶密碼
            unsigned char szIP_Addr[16];      // IP地址
            unsigned short nPortNo;         // 端口號
        }tPPP; // 基於modem的點對點(Point to Point Protocol)遠程下載通訊參數，
               // 參數bCommMode=5時該參數才有效

		struct //WIFI 參數bCommMode=6時該參數才有效
		{
			
			unsigned char szWifi_SSID[40];        // SSID
			unsigned char szPasswd[64];       // 用戶密碼
			
			unsigned char szLocal_IP[16]; // 本機IP
			
			unsigned short Local_PortNo;
			
			unsigned char szRemote_IP_Addr[16];      // 遠程IP地址
			unsigned short RemotePortNo;          // 遠程端口號
			unsigned char szSubnetMask[16];          //   子網掩碼
			unsigned char szGatewayAddr[16];         //       網關
			unsigned char szDns1[16]; 
			unsigned char szDns2[16]; 	
			unsigned char Encryption_Mode; //  1: WEP 64(ASCII); 2 WEP 128 (ASCII);    3  WPA_TKIP;  4 WPA_AES  	
			unsigned char Encryption_Index; // WEP時用取值範圍:1~4
			unsigned char DHCP_Flag; // 1:使用DHCP 
        }tWIFI; 
    }tUnion;
}T_CSCOMMPARA;
/*----------2015-11-17 KMS   END-----------*/


// 彶等俴陓洘
typedef struct _tagACQUIRER
{
//	uchar	ucStatus;	//(痄善SYS_CONTROL)
	uchar	ucKey;						// 桶瘍
	uchar	szPrgName[10+1];			// 梗靡ˋ翋儂靡備ˋreserved?
	uchar	szName[10+1];				// 彶等俴靡備
	uchar	sIssuerKey[MAX_ISSUER];		// 楷縐俴陓洘
	uchar	ucIndex;					// 蜆彶等俴腔杅郪狟梓

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
#define SupportKIN       1    //該收單行支持EFTSec。 this ACQUIRER Support EFTSec.
#define NotSupportKIN    0    //該收單行不支持EFTSec。 this ACQUIRER don't Support EFTSec. 
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

// 煦ぶ葆遴數赫陓洘
typedef struct _tagINSTALMENT_PLAN
{
	uchar	ucIndex;		// 1~MAX_PLAN
	uchar	ucAcqIndex;
	uchar	szName[7+1];
	uchar	ucMonths;
	ulong	ulBottomAmt;	// 郔腴踢塗
    // MS-SCB
    uchar   szDescript[20+1];   // Text description
    uchar   szMaxAmount[12+1];
    uchar   ucWaiverMonth;      // Months don't pay
    uchar   sValidFromDate[4];  // mmddyyyy, BCD
    uchar   sValidToDate[4];    // mmddyyyy, BCD
	uchar   szProgID[6+1];      // Program ID
    uchar   szProductID[4+1];   // Product ID
}INSTALMENT_PLAN;

// 妀こ鏡扴陓洘
typedef struct _tagDESCRIPTOR
{
	uchar	ucKey;
	uchar	szCode[2+1];		// ANS format
	uchar	szText[20+1];		// for display and print
}DESCRIPTOR;

// 砆牉縐桶陓洘(RFU for HK)
#define LEN_MAX_CARBIN_NAME		30
typedef struct _tagISSUER_NAME
{
	uchar	szChineseName[16+1];
	uchar	szEnglishName[LEN_MAX_CARBIN_NAME+1];
}ISSUER_NAME;

typedef struct _tagCARD_BIN
{
	uchar	ucIssuerIndex;		// 迵IssuerName壽薊腔坰竘瘍
	uchar	ucPanLen;			// 縐瘍酗僅(reserved)
	uchar	ucMatchLen;			// ぁ饜奀緊腔酗僅
	uchar	sStartNo[10];
	uchar	sEndNo[10];
}CARD_BIN;

// 赻雄狟婥統杅陓洘(RFU for HK),蚚衾換菰統杅跤Manager
typedef struct _tagEDC_DOWN_PARAM
{
	uchar	szPabx[10+1];
	uchar	szTermID[8+1];
	uchar	szCallInTime[8+1];		// HHMM-hhmm
	// EDC埰勍掩請腔れ砦奀潔,24奀秶
	uchar	bEdcSettle;				// 0: not settle 1: settle
	uchar	ucAutoMode;				// 0 none, 1 auto, 2 call in
	uchar	szAutoDayTime[10+1];	// YYMMDDHHmm
}EDC_DOWN_PARAM;

// 迵奪燴ん眈壽杅擂賦凳
// EPS炵苀統杅(迵導炵苀潭��,韜靡寞寀迵導炵苀潭��)
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

// 蝠眢饜离陓洘
typedef struct _tagTRAN_CONFIG
{
	uchar	szLabel[16+1];		// 珆尨腔蝠眢濬倰
	uchar	szTxMsgID[4+1];		// 蝠眢奻冞惆恅陓洘
	uchar	szProcCode[6+1];	// 蝠眢揭燴鎢ヶ醱謗弇

#define PRN_RECEIPT			0x80
#define WRT_RECORD			0x40
#define IN_SALE_TOTAL		0x20
#define IN_REFUND_TOTAL		0x10
#define VOID_ALLOW			0x08
#define NEED_REVERSAL		0x04
#define ACT_INC_TRACE		0x02
#define NO_ACT				0x00
	uchar	ucTranAct;		// 蜆蝠眢剒猁腔髡夔
}TRAN_CONFIG;

// 恁砐統杅陓洘
typedef struct _tagOPTION_INFO
{
	void	*pText;				// 珆尨腔枑尨
	ushort	uiOptVal;			// 弇离﹝0304桶尨 byte[3]腔0x04弇离
	uchar	ucInverseLogic;		// 岆瘁毀砃軀憮﹝瞰�� EDC_NOT_SETTLE_PWD
	uchar	ucPermissionLevel;	// 輛俴森党蜊垀剒腔蚚誧�使�
}OPTION_INFO;

typedef struct _tagHOST_ERR_MSG
{
	uchar	szRspCode[2+1];		// 翋儂殿隙鎢
	uchar	szMsg[16+1];
}HOST_ERR_MSG;

typedef struct _tagTERM_ERR_MSG
{
	int		iErrCode;
	uchar	szMsg[16+1];
}TERM_ERR_MSG;

// 蝠眢�欶�
#define	MAX_GET_DESC		4
typedef struct _tagTRAN_LOG
{
	uchar	ucTranType;					// 蝠眢濬倰
	uchar	ucOrgTranType;				// 埻蝠眢濬倰
	uchar	szPan[19+1];				// 縐瘍
	uchar	szExpDate[4+1];				// 衄虴ぶ
	uchar	szAmount[12+1];				// 蝠眢踢塗
	uchar	szInitialAmount[12+1];		// 蝠眢郔場腔踢塗
	uchar	szTipAmount[12+1];			// 苤煤踢塗
	uchar	szAbolishedTip[12+1];		// 覃淕綴帤奻冞 VOID釬煙腔苤煤
	uchar	szOrgAmount[12+1];			// 埻蝠眢踢塗
	uchar	szFrnAmount[12+1];			// 俋啟踢塗
	uchar	szDateTime[14+1];			// YYYYMMDDhhmmss
	uchar	szRRN[13+1];				// RRN, system ref. no
	uchar	ucAcqKey;					// 彶等俴桶瘍
	uchar	ucIssuerKey;				// 楷縐俴桶瘍
//	uchar	szProcCode[6+1];			// 揭燴鎢, Bit 3
	uchar	szCondCode[2+1];			// Bit 25
	uchar	ucDescTotal;				// total # of Descriptor
	uchar	szDescriptor[MAX_GET_DESC+1];
	uchar	szRspCode[2+1];				// 砒茼鎢
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
    uchar   szFrnTip[12+1];			    // 俋啟苤煤踢塗
    uchar   sPPDccMarkupRate[3];        // "+\x03\x46" = +3.46
    uchar   szPPDccMarkupTxt[22+1];     // "+Three pt. four six   "
	//Build 1.00.0113
    uchar   szPPDccTxnID[15+1];     // "+TraceId\TxnIdentifier   "
    //-------------------------------

#define	MODE_NO_INPUT			0x0000
#define	MODE_MANUAL_INPUT		0x0001	// 忒怀縐瘍
#define	MODE_SWIPE_INPUT		0x0002	// 棠縐芃縐
#define	MODE_CHIP_INPUT			0x0004	// EMV縐脣縐
#define	MODE_FALLBACK_SWIPE		0x0008	// EMV芃縐
#define	MODE_PIN_INPUT			0x0010	// online PIN input
#define MODE_OFF_PIN			0x0020	// for AMEX
#define MODE_SECURITYCODE		0x0040	// CVV/4DBC entered
#define MODE_CONTACTLESS		0x0080	// 準諉揖
#define MODE_FALLBACK_MANUAL	0x0100	// 婃奀祥剒猁,�蝜�UOB剒猁婬崝樓
	ushort	uiEntryMode;			// 怀�踽�宒, 褫數呾堤Bit 22

	ulong	ulInvoiceNo;			// き擂瘍
	ulong	ulSTAN;					// STAN
	ulong	ulOrgSTAN;				// 埻蝠眢霜阨

	uchar   szEcrTxnNo[6+1];        // ECR : TXNNO
    uchar   szEcrConseqNo[4+1];     // ECR : TXN consequential num


#define TS_OK			0x0000		// txn accepted
#define TS_NOSEND		0x0001		// txn not sent to host
#define TS_ADJ			0x0002		// txn adjusted
#define TS_REVD			0x0004		// txn reversed (reserved)
#define TS_VOID			0x0008		// txn voided
#define TS_CHANGE_APPV	0x0010		// 杸遙Approval Code, reserved
#define TS_FLOOR_LIMIT	0x0020		// 蝠眢踢塗腴衾Floor Limit
#define TS_OFFLINE_SEND	0x0040		//
#define TS_NOT_UPLOAD	0x0080		// 祥剒猁奻冞(蚕NOSEND/ADJ瓚剿)
#define TS_NEED_TC		0x0100		// 剒猁奻冞TC
#define TS_ALL_LOG		0xFFFF
	ushort	uiStatus;				// 蝠眢袨怓

	//Lijy
	uchar szDebitInAmt[12+1];       //怀�踳蘤謑慢asino耀宒怀�踳蘤鎃疙觚炒狠慬蓐蘤鎃穹珆�
#ifdef AMT_PROC_DEBUG
	//2014-9-18 ttt 將所有的amt流程金額移動到這裡
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
// 炵苀蝠眢揭燴陓洘,祥剒猁湔揣善恅璃炵苀
typedef struct _tagSYS_PROC_INFO
{
	TRAN_LOG	stTranLog;
	uchar		szTrack1[79+1];
	uchar		szTrack2[40+1];
	uchar		szTrack3[107+1];

	// む坻杅擂猁匼,③跦擂蝠眢揭燴剒⑴懂崝樓
	uchar		bIsFallBack;
#define ST_OFFLINE		0
#define ST_ONLINE_FAIL	1
#define ST_ONLINE_APPV	2
	uchar		ucOnlineStatus;		// expansion of "bIsOnlineTxn"
	uchar		bIsFirstGAC;			// 岆瘁岆菴珨棒GAC
	uchar		ucEcrCtrl;				// ECR梓祩(RFU)
	uchar		ucEcrRFFlg;				// ECR RF 梓祩
	uchar		bExpiryError;			// TRUE: 縐瘍衄虴ぶ渣昫
	uchar		szSecurityCode[4+1];	// CVV2/4DBC
// 	uchar		bPinEnter;				// 岆瘁怀�蹅沏IN
	uchar		sPinBlock[8];			// PIN block (RFU)
	uchar		bAutoDownFlag;
	uchar		szSettleMsg[30+1];		// 賦呾陓洘(蚚衾珆尨/湖荂脹)
	ushort		uiRecNo;				// 埻蝠眢暮翹瘍(for VOID)
	int			iFallbackErrCode;		// 婖傖fallback腔埻秪(for AMEX)
	uchar		sSessionKey[32];		// 線路加密session key//2016-2-29 *** //Gillian 2016-7-14
	STISO8583	stSendPack;				// 楷冞惆恅掘爺
	uchar       bIfClssTxn;             // 蚚蜆硉�毓京Й鵓骳玫翾疝Х蚐供馭�
	uchar		ucTrack2Len;			// 2棠耋酗僅
	WAVE_TRANS_DATA stWaveTransData;
}SYS_PROC_INFO;

// 蝠眢喳淏陓洘
typedef struct _tagREVERSAL_INFO
{
	uchar			bNeedReversal;		// TRUEㄩ剒猁喳淏, FALSE: 祥剒猁
	STISO8583		stRevPack;			// 埻蝠眢③⑴惆恅
	ushort			uiEntryMode;		// 怀�踽�宒
}REVERSAL_INFO;

// 籵捅杅擂
#define	LEN_MAX_COMM_DATA	1024
typedef struct _tagCOMM_DATA
{
	ushort		uiLength;
	uchar		sContent[LEN_MAX_COMM_DATA+10];
}COMM_DATA;

// 蝠眢颯軞陓洘
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
#define ECRMODE_ENABLED		1	// 羲ゐECR
#define ECRMODE_ONLY		2	// 硐埰勍ECR楷れ蝠眢
    uchar   ucMode;  // ECR耀宒(壽敕/耀宒1/耀宒2/...)
    uchar   ucPort;  // ECR揹諳瘍
#define ECRSPEED_9600       0
#define ECRSPEED_115200     1
    uchar   ucSpeed;
}ECR_CONFIG;
// 炵苀饜离陓洘婓狟婥統杅麼氪党蜊統杅腔奀緊符剒猁載陔
typedef struct _tagSYS_PARAM
{
#define LOGON_MODE		0x01
#define CHANGE_MODE 	0x02
#define TRANS_MODE		0x04
#define INIT_MODE		0x08
	uchar				ucTermStatus;		// 笝傷袨怓

#define _TxnPSTNPara	stTxnCommCfg.stPSTNPara
#define _TxnModemPara	stTxnCommCfg.stPSTNPara.stPara
#define _TxnRS232Para	stTxnCommCfg.stRS232Para
#define _TxnTcpIpPara	stTxnCommCfg.stTcpIpPara
#define _TxnWirlessPara	stTxnCommCfg.stWirlessPara
	COMM_CONFIG			stTxnCommCfg;		// 蝠眢籵捅饜离

#define _TmsPSTNPara	stTMSCommCfg.stPSTNPara
#define _TmsModemPara	stTMSCommCfg.stPSTNPara.stPara
#define _TmsRS232Para	stTMSCommCfg.stRS232Para
#define _TmsTcpIpPara	stTMSCommCfg.stTcpIpPara
#define _TmsWirlessPara	stTMSCommCfg.stWirlessPara
	COMM_CONFIG			stTMSCommCfg;		// TMS籵捅饜离
	uchar				ucNewTMS;			// TMS恅璃衪祜狟婥
	uchar				ucTMSSyncDial;		// 肮祭耀宒(躺modem)

	EDC_INFO			stEdcInfo;			// 笝傷統杅

	uchar				ucAcqNum;			// 彶等俴杅醴
	ACQUIRER			stAcqList[MAX_ACQ];

	uchar				ucIssuerNum;		// 楷縐俴杅醴
	ISSUER				stIssuerList[MAX_ISSUER];

	uchar				ucCardNum;			// 縐桶杅醴
	CARD_TABLE			stCardTable[MAX_CARD];

	uchar				ucDescNum;			// 妀こ鏡扴跺杅
	DESCRIPTOR			stDescList[MAX_DESCRIPTOR];

	uchar				ucPlanNum;			// 煦ぶ葆遴數赫跺杅
	INSTALMENT_PLAN		stPlanList[MAX_PLAN];

	uchar				sPassword[PWD_MAX][10];	// 躇鎢杅擂

	// for HK
	ushort				uiIssuerNameNum;
	ISSUER_NAME			stIssuerNameList[MAX_CARDBIN_ISSUER];
	ushort				uiCardBinNum;
	CARD_BIN			stCardBinTable[MAX_CARDBIN_NUM];
	uchar				bTextAdData;		// False: bitmap TRUE: text
	uchar				sAdData[LEN_MAX_AD_DATA];	// 嫘豢陓洘

	uchar				sTermInfo[HWCFG_END];	// Terminal hardware infomation. for GetTermInfo() use.
#define APMODE_INDEPEND		0		// Current app is app manager.   絞ヶ茼蚚峈黃蕾堍俴耀宒
#define APMODE_MAJOR		1		// Current app is major sub-app. 絞ヶ茼蚚峈翋猁赽茼蚚(EDC for VISA MASTERCARD)
#define APMODE_MINOR		2		// Current app is minor sub-app. 絞ヶ茼蚚峈棒猁赽茼蚚(EDC for AE, DINERS, JCB)
	uchar				ucRunMode;
	uchar				ucManagerOn;			// 1--掛最唗醴ヶ蚕Manager覃蚚 0--祥岆植Manager輛��

#ifdef APP_MANAGER_VER
	
#define APP_EDC			0
#define APP_CUP			1
#define APP_EPS			2
#define APP_AMEX		3
#define APP_EDC_OLD		4
#define APP_OTHER_START	5		// 其它子應用的起始位置
#define APP_VA			8
#define APP_NUM_MAX		15		// 最多支持的子應用個數
    APP_PARAM       astSubApp[APP_NUM_MAX];
	uchar           FuncEnable[APP_NUM_MAX][100];
   
    uchar			ucKbSound;				// enable keyboard sound
#define EN_EMV_NORMAL   1
#define EN_EMV_TEST     2
    uchar           ucEnableEMV;            // EMV support. 0--disabled;1--enabled;2--ADVT/TIP
	uchar			ucEnableCLSS;			// CLSS support 0--disabled;1--Idle Amount Clss 2--Fixed Amount CLSS
	uchar			ucClssFixedAmt[13];			// CLSS Fixed Amount
	uchar			ucDecimal;				// 赽茼蚚妏蚚億啟腔苤杅萸弇 
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
// 炵苀堍俴統杅婓藩棒蝠眢飲褫夔輛俴党蜊,湔揣婓恅璃炵苀
enum {S_RESET, S_SET, S_LOAD, S_INS, S_OUT, S_USE ,S_PENDING, S_CLR_LOG};
typedef struct _tagSYS_CONTROL
{
	ulong			ulSTAN;			// 絞ヶ笝傷霜阨瘍
	ulong			ulInvoiceNo;	// 絞ヶき擂瘍
	ushort			uiLastRecNo;	// 郔綴珨捩蝠眢暮翹#
	ushort			uiErrLogNo;		// 絞ヶ暮翹EMV渣昫�欶噩躁Ъ�#
	ushort			uiLastRecNoList[MAX_ACQ];		// for bea
	uchar			sAcqStatus[MAX_ACQ];			// 彶等俴袨怓陓洘
	uchar			sAcqKeyList[MAX_TRANLOG];		// 蝠眢暮翹桶
	uchar			sIssuerKeyList[MAX_TRANLOG];	// 蝠眢暮翹桶
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
	REVERSAL_INFO	stRevInfo[MAX_ACQ];		// 喳淏陓洘

#define LEN_SYSCTRL_NORMAL	((int)OFFSET(SYS_CONTROL, stRePrnStlInfo))
	REPRN_STL_INFO	stRePrnStlInfo;

	EMV_FIELD56		stField56[MAX_ACQ];		// 56郖陓洘
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
// 任務列表
typedef struct
{
	unsigned long AllSize;      // 當前任務大小尺寸
	unsigned char TaskNo;         // 任務號
	unsigned char TaskType;      // 任務類型
	unsigned char FileName[33];  // 文件名
	unsigned char AppName[33];   // 應用程序名
	unsigned char vern[21];      // 版本號
	unsigned char ForceUpdate;	 //強制更新標誌
	unsigned char Rev[5];		// 用作補齊
	unsigned char done;          // 0:未下載 1:下載中 2:下載完成 3:更新完成
}TASK_TABLE;	//total 42 + 4*4 + 22 = 80


typedef struct
{
	unsigned char TeleCode[31];       // 電話號碼
	unsigned char ChkDialTone;
	unsigned long BaudRate;
	unsigned char TimeOut;

	unsigned char m_aIPAddress[24];   // 遠端IP 地址，考慮到IPV6佔用6個字段，要用到23個字節
	unsigned char m_aPppPort[6];      // 端口號
	unsigned char m_aUserName[33];    // 用戶名
	unsigned char m_aPassword[17];    // 密碼

	unsigned char m_psTermID[10];     // 終端號

	unsigned char m_aLocalIPAddr[24]; // 本地IP 地址，考慮到IPV6佔用6個字段，要用到23個字節
	unsigned char m_aSubnetMask[24];  // 子網掩碼
	unsigned char m_aGatewayAddr[24]; // 網關
}MODEM_SETUP;  // 遠程下載配置信息結構

#define PROTIMS_DISPLAY_LEN		24
#define  PROTIMS_MAX_TASK                   256//20  // 下載任務最大個數
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
	unsigned char gbDeleteCurApp;		// 岆瘁刉壺絞ヶ茼蚚最唗
	unsigned char g_byTcpipDHCPFlag;
	unsigned char bIsChnFont;
	unsigned char g_FileName[32+1];
	unsigned char g_bTosanDial;//modem dial need add TPDU Header
	unsigned char g_bSetTimer;
	unsigned char TPDU_Tosan[8];	// 5弇TPDU,suixingpay, verne, 20120611
	unsigned long g_dwPacketLen;
	unsigned long AllLoadSize;
	unsigned long DownloadSize;
	unsigned long ulReservel;
	int gbCrtlBit;						// 狟婥諷秶
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

extern SProtims_gbVar p_gbVars;	// 存放全局變量的結構，防止與用戶的全局變量重名，便於管理
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

extern SYS_PARAM		glSysParam, glSysParamBak;		// 炵苀饜离統杅
extern SYS_CONTROL		glSysCtrl;		// 炵苀諷秶統杅
extern SYS_PROC_INFO	glProcInfo;		// 蝠眢揭燴陓洘

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
extern COMM_DATA		glSendData, glRecvData, glSendDataDebug, glRecvDataDebug;		// 籵捅杅擂//2014-9-1
extern STISO8583		glSendPack;		// 楷冞惆恅
extern STISO8583		glRecvPack;		// 諉彶惆恅

extern STTMS8583		glTMSSend;		// TMS楷冞惆恅
extern STTMS8583		glTMSRecv;		// TMS諉彶惆恅

extern ST_EVENT_MSG		*glEdcMsgPtr;	// 奪燴ん岈璃

extern ACQUIRER			glCurAcq;		// 絞ヶ彶等俴
extern ISSUER			glCurIssuer;	// 絞ヶ楷縐俴

extern COMM_CONFIG		glCommCfg;		// 絞ヶ籵捅饜离統杅

extern TOTAL_INFO		glAcqTotal[MAX_ACQ];		// 彶等俴颯軞陓洘
extern TOTAL_INFO		glIssuerTotal[MAX_ISSUER];	// 楷縐俴颯軞陓洘
extern TOTAL_INFO		glEdcTotal;		// 笝傷颯軞陓洘
extern TOTAL_INFO		glTransTotal;	// 蝠眢揭燴妏蚚腔颯軞陓洘
extern TOTAL_INFO		glPrnTotal;		// 等擂湖荂妏蚚腔颯軞陓洘
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
extern uchar ucWLBBuf[2];		//還奀buf
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
extern EFTSec_Control glEFTSec_Control;   //加密報文的EDS信息和密鑰信息。
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











