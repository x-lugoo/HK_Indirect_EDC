
#include "global.h"


SProtims_gbVar p_gbVars;

cTMSStart pcTMSStart	     = NULL;
cTMSReset pcTMSReset         = NULL;
cTMSSendPack pcTMSSendPack   = NULL;
cTMSRecvByte pcTMSRecvByte   = NULL;
cTMSExitClose pcTMSExitClose = NULL;
cTMSNetRecv  pcTMSNetRecv    = NULL;

char DISPLAY_LANGUAGE[][PROTIMS_DISPLAY_LEN] = {""};

char DISPLAY_KEY[][PROTIMS_DISPLAY_LEN] = {                         
		"DNSRESLVE_ERROR",                            
		"APP_DOWNLOADING",                                    
		"PARA_DOWNLOADING",                                 
		"FONT_DOWNLOADING",                               
		"MONITOR_DOWNLOADING",
		"DLL_DOWNLOADING",
		"PUK_DOWNLOADING",
		"MONITOR_VER",
		"COMM_INIT",                                 
		"COMM_HANDSHAKE",                        
		"COMM_AUTHING",                                
		"COMM_GETTASK",                                
		"COMM_PRASETASK",                           
		"UPDATE_LATER",                              
		"PORT_OPEN_ERR",                                                           
		"COMM_DIALING",                                   
		"COMM_SET_IP",                              
		"COMM_DNS_RESLOVE",                      
		"COMM_TCP_CONNECT",                      
		"COMM_PPP_LOGINING",                            
		"COMM_PPP_OPENING",                            
		"COMM_PPP_CONNECTING",                   
		"COMM_WNET_INIT",                            
		"COMM_WNET_CHECK_SIGNAL",                    
		"BULDING_FILE_SYS",                     
		"DELETE_ALL_APPLICATION",                   
		"DELETE_SOME_APPLICATION",                      
		"UPDATE_APP_FILE",                                 
		"UPDATE_PARA_FILE",                              
		"UPDATE_FONT_FILE",                            
		"UPDATE_MONITOR_FILE",  
		"UPDATE_MONITOR_FAILED", 
		"UPDATE_DLL_FILE",
		"UPDATE_DLL_FAILED",
		"DELETE_DLL_FILE",
		"CUR_FILE",                                   
		"COMMAND_INCORRECT",                            
		"DOWNLOAD_100",                         
		"DOWNLOAD_99",                       
		"UPDATE_SUCCESSFULLY_1",                     
		"UPDATE_SUCCESSFULLY_2",                        
		"UPDATE_TITLE",
		"MODEM_PARA_PHONE_NUM",
		"NEW_DOWNLOAD",
		"REPEAT_DOWNLOAD",
		"RESUME_DOWNLOAD",
		"DOWNLOAD_SETUP",
		"MODEM_PARA_SETUP",
		"GET_TID",
		"OUTSIDE_NUM",
		"BAUD_RATE",
		"REMOTE_IP",
		"REMOTE_PORT",
		"ENABLE_DHCP",
		"LOCAL_IP",
		"NETMASK",
		"GATEWAY",
		"DNS",
		"USERNAME",
		"PASSWORD",
		"PINCODE",
		"USERCANCEL",
		"NOT_CONFIGURED",
		"REQUEST_UPLOAD",
		"UPLOADING_FILE",
		"UPDATE_PUK_FILE",
		"UPDATE_PUK_FAILED",
		"PROTIMS_TITLE",
		"DOWNLOAD_CONTINUE",
		"SELECT_LANGUAGE",
		"BOOT_CHECK",
		"MODEM_PARA",
		"CHECK_DIAL_TONE",
		"YES_ENTER_KEY",
		"NO_CANCEL_KEY",
		"SET_BAUD_RATE",
		"EXAMPLE_33600",
		"PARA_TIMEOUT",
		"EXAMPLE_15",
		"INPUT_WIFI_SSID",
		"SELECT_ENCRYPTION_MODE",
		"INPUT_WEP64_PASSWORD",
		"INPUT_WEP128_PASSWORD",
		"INPUT_WPA_PASSWORD",
		"PASSWORD_INDEX",
		"LOCAL_PORT",
		"DELETE_TEMPFILE",
		"ENTER_CANCEL",
		"COMM_INIT_ERROR",
		"HANDSHAKE_ERROR",
		"TERM_AUTH_ERROR",
		"GET_TASK_ERROR",
		"TASK_PARSE_ERROR",
		"NO_TASK_ERROR",
		"DOWNLOAD_FAIL",
		"PARA_ERROR",
		"TID_ERROR",
		"UPDATE_ERROR",
		"REQ_UPLOAD_ERROR",
		"UPLOAD_ERROR",
		"NO_RESPONSE",
		"LINE_BUSY",
		"NO_PHONE_LINE",
		"SEND_BUF_NOT_EMPTY",
		"TIME_OUT",
		"USER_CANCEL",
		"COMM_TIMEOUT",
		"RECV_ERROR_DATA",
		"DATA_CRC_ERROR",
		"DOWNLOAD_TIMEOUT",
		"PORT_SEND_ERR",
		"PORT_RESET_ERR",
		"PORT_RECV_ERR",
		"TCP_ROUTERSETDEFAULT_ERR",
		"TCP_DHCPSTART_ERR",
		"TCP_DHCPCHECK_ERR",
		"TCP_ETHSET_ERR",
		"TCP_NETSOCKET_ERR",
		"TCP_SOCKETADDSET_ERR",
		"TCP_NETCONNECT_ERR",
		"TCP_NETSEND_ERR",
		"TCP_NETRECV_ERR",
		"TCP_NETCLOSESOCKET_ERR",
		"PPP_LOGIN_ERR",
		"PPP_CHECK_ERR",
		"WL_INIT_ERR",
		"WL_OPENPORT_ERR",
		"WL_GETSIGNAL_ERR",
		"WL_LOGINDIAL_ERR",
		"WL_CLOSEPORT_ERR",
		"FILE_SEEK_ERR",
		"FILE_OPEN_ERR",
		"FILE_READ_ERR",
		"FILE_WRITE_ERR",
		"FILE_NOENOUGH_SPACE_ERR",
		"FILE_REMOVE_ERR",
		"UPDATE_APP_ERR",
		"UPDATE_PARA_ERR",
		"UPDATE_FONT_ERR",
		"UPDATE_DELETE_ERR",
		"UPLOAD_GETTERMINFO_ERR",
		"UPLOAD_TERMINFOEX_ERR",
		"DECOMPRESS_DATA_ERROR",
		"PACKAGE_LENGTH",
		"MODEM_ENABLE_TPDU",
		"MODEM_INPUT_NII",
		"FACTORY_RESET",
		"DOWNLOAD_PERCENTAGE",
		"PUB_FILE_DOWNLOADING",
		"UPDATE_PUB_FILE",
		"UPDATE_PUBFILE_FAILED",
		"DELETE_PUB_FILE",
		"GET_ERROR_CODE",
		"UPLOAD_SUCCESS",
		"OBTAIN_WL_INFO",
		"RSA_PUBKEY",
		"DOWNLOADING",
		"MAIN_KEY",
		"INJECTING",
		"DOWNLOAD_SUCCESS",
		"RSAKEY_GET_ERROR",
		"MAINKEY_GET_ERROR",
		"MAINKEY_WRITE_ERROR",
		"KEY_DOWNLOAD_ERROR",
		"NO_RSAKEY_ERROR",
		"KEY_VALIDATE_ERROR",
		"RSA_ENCRYPT_ERROR",
		"KEY_NUM_ERROR",
		"KEY_LENGTH_ERROR",
		"END_DISPLAY_INDEX", 
};                               
              
char DISPLAY_DEFAULT[][PROTIMS_DISPLAY_LEN] =    //enum                      
{                                           //{                         
	"DnsReslove Err",                     // 	DNSRESLVE_ERROR,  0      
	"APP%12dK",                             // 	APP_DOWNLOADING,  1      
	"PARA%11dK",                            // 	PARA_DOWNLOADING,  2     
	"FONT%11dK",                            // 	FONT_DOWNLOADING,   3    
	"MONITOR%9dK",                          // 	MONITOR_DOWNLOADING, 4   
	"SO%11dK",                             // 	DLL_DOWNLOADING,      5  
	"PUK%11dB",                             // 	PUK_DOWNLOADING,    6
	"Ver%11s",                             // 	MONITOR_VER,         7   
	"Init...",                              // 	COMM_INIT,            8  
	"Handshake Start...",                   // 	COMM_HANDSHAKE,        9 
	"Authenticate...",                      // 	COMM_AUTHING,           10
	"Get Tasks...",                         // 	COMM_GETTASK,           11
	"Parse Tasks...",                       // 	COMM_PRASETASK,         12
	"Update Later",                         // 	UPDATE_LATER,           13
	"PortOpen Err",                        // 	PORT_OPEN_ERR,          14
	"Dialing...",                           // 	COMM_DIALING,           15
	"Set IP...",                            // 	COMM_SET_IP,            16
	"DnsResolve...",                        // 	COMM_DNS_RESLOVE,       17
	"TCP Connect...",                       // 	COMM_TCP_CONNECT,       18
	"PPP Login...",                         // 	COMM_PPP_LOGINING,      19
	"PPP Open...",                          // 	COMM_PPP_OPENING,       20
	"PPP NetConnect...",                    // 	COMM_PPP_CONNECTING,    21
	"Wnet Init...",                         // 	COMM_WNET_INIT,         22
	"Check Signal...",                      // 	COMM_WNET_CHECK_SIGNAL, 23
	"Build File Sys!",                      // 	BULDING_FILE_SYS,       24
	"Delete All Apps",                      // 	DELETE_ALL_APPLICATION, 25
	"Delete App",                          // 	DELETE_SOME_APPLICATION,26
	"Update App",                           // 	UPDATE_APP_FILE,        27
	"Update Para",                          // 	UPDATE_PARA_FILE,       28
	"Update Font",                          // 	UPDATE_FONT_FILE,       29
	"Update Monitor",                       // 	UPDATE_MONITOR_FILE,  30
	"Update Monitor Fail",                 // 	UPDATE_MONITOR_FAILED,  31
	"Update SO",                       		// 	UPDATE_DLL_FILE,  32
	"Update SO Fail",                 		// 	UPDATE_DLL_FAILED,  33
	"Delete SO",                 			// 	DELETE_DLL_FILE,  34
	"Cur. File ",                           // 	CUR_FILE,           35    
	"Command Err",                        // 	COMMAND_INCORRECT,    36  
	" DOWNLOAD  100%% ",                    // 	DOWNLOAD_100,           37
	" DOWNLOAD   99%% ",                    // 	DOWNLOAD_99,            38
	"  Download OK!\n",                     //  UPDATE_SUCCESSFULLY_1,  39
	"  Reboot System",                      //  UPDATE_SUCCESSFULLY_2,  40
	"      UPDATE     ",					//  UPDATE_TITLE,41
	"Phone Number",							//	MODEM_PARA_PHONE_NUM 42
	"1.New Download",						//	NEW_DOWNLOAD 43
	"2.RepeatDownload",						//	REPEAT_DOWNLOAD 44
	"3.ResumeDownload",						//	RESUME_DOWNLOAD	45
	"2.Download Setup",                     //  46
	"1.Modem Para",                         //  47
	"Task ID",							    //	GET_TID 48 //2014-7-8 should be task ID, not terminal ID
	"Outside Number",						//	OUTSIDE_NUM 49
	"SELECT BAURATE",							//	BAUD_RATE 50 
	"Remote IP",							//	REMOTE_IP 51
	"Remote Port",							//	REMOTE_PORT 52
	"Enable DHCP",							//	ENABLE_DHCP 53
	"Local IP",								//	LOCAL_IP 54
	"NetMask",								//	NETMASK 55
	"GateWay",								//	GATEWAY 56
	"DNS",									//	DNS 57
	"User Name",							//	USERNAME 58
	"Password",								//	PASSWORD 59
	"PIN Code",								//	PINCODE 60
	"User Canceled",						//	USERCANCEL 61
	"Not Configured",						//	NOT_CONFIGURED 62
	"Request Upload",                     //  63
	"Uploading File",                     //  64
	"Update PUK",                     //  65
	"Update PUK Fail",                     //  66
	"REMOTE DOWNLOAD",                     //  67
	"Download Continue?",                     //  68
	"Select Language",                     //  69
	"Resume Setting",                     //  70
	"Modem Para",                     //  71
	"Check Dial Tone?",                     //  72
	"Yes:ENTER Key",                     //  73
	"No:CANCEL Key",                     //  74
	"Set Baud Rate:",                     //  75
	"(Example:33600)",                     //  76
	"Timeout:",                     //  77
	"(Example:15)",                     //  78
	"Input SSID",                     //  79
	"Encryption Mode",                     //  80
	"Input Passwd",                     //  81
	"Input Passwd",                     //  82
	"Input Passwd",                     //  83
	"Passwd Index",                     //  84
	"Local Port",                     //  85
	"Delete Temp File?",                     //  86
	"[ENTER/CNACEL]",                     //  87
	"Comm Init Err",                     //  88
	"Handshake Err",                     //  89
	"Term Auth Err",                     //  90
	"Get Task  Err",                     //  91
	"Task Parse Err",                     //  92
	"No Task List",                     //  93
	"Download Fail",                     //  94
	"Comm Para Err",                     //  95
	"TID Err",                     //  96
	"Update Err",                     //  97
	"Req Upload Err",                     //  98
	"Upload Err",                     //  99
	"No Response",                     //  100
	"Line Busy",                     //  101
	"No Phone Line",                     //  102
	"Send Buf Not Empty",                     //  103
	"Timeout",                     //  104
	"User Cancel",                     //  105
	"Comm Timeout",                     //  106
	"Recv Error Data",                     //  107
	"Data CRC Err",                     //  108
	"Download Timeout",                     //  109
	"Port Send Err",                     //  120
	"Port Reset Err",                     //  121
	"Port Recv Err",                     //  122
	"Set Default Route Err",                     //  123
	"DHCP Start Err",                     //  124
	"DHCP Check Err",                     //  125
	"Set IP Err",                     //  126
	"Socket Create Err",                     //  127
	"Socket Bind Err",                     //  128
	"TCP Connect Err",                     //  129
	"TCP Send Err",                     //  130
	"TCP Recv Err",                     //  131
	"Socket Close Err",                     //  132
	"PPP Login Err",                     //  133
	"PPP Check Err",                     //  134
	"WL Init Err",                     //  135
	"WL Open Err",                     //  136
	"WL Get Signal Err",                     //  137
	"WL Dial Err",                     //  138
	"WL Close Err",                     //  139
	"File Seek Err",                     //  140
	"File Open Err",                     //  141
	"File Read Err",                     //  142
	"File Write Err",                     //  143
	"No Enough Space",                     //  144
	"File Remove Err",                     //  145
	"Update APP Err",                     //  146
	"Update Para Err",                     //  147
	"Update Font Err",                     //  148
	"Update Delete Err",                     //  149
	"Get TermInfo Err",                     //  150
	"Get TermInfoEX Err",                     //  151
	"Decompress Data Err",                     //  152
	"Package Length",                     //  153
	"Enable TPDU",                     //  154
	"Input NII",                     //  155
	"Factory Reset?",                     //  156
	" DOWNLOAD  %3d%% ",                     //  157
	"PUB FILE%8dK",                        //PUB_FILE_DOWNLOADING,    158
	"Update Pub File",                      //UPDATE_PUB_FILE,  159
	"Update Pub Fail",                 	//UPDATE_PUBFILE_FAILED,  	160
	"Delete Pub File",				//DELETE_PUB_FILE 161
	"Recv Err Code",                     //  162
	"Upload Success!",                     //  163
	"Obtain WL Info...",                     //  164
	"RSA Key",                     //  165
	"Downloading...",                     //  166
	"Main Key",                     //  167
	"Injecting...",                     //  168
	"Download Success!",                     //  169
	"Get RSA Key Err",                     //  170
	"Get Main Key Err",                     //  171
	"Inject Key Err",                     //  172
	"Download Key Fail",                     //  173
	"No RSA Key Err",                     //  174
	"Key Validate Err",                     //  175
	"RSA Encrypt Err",                     //  176
	"Key Num Err",                     //  177
	"Key Length Err",	                     //  178
	"",                                     // 	UNKNOW_DISPLAY_INDEX    
};                                          //}PROTIMS_DISPLAY_INDEX;   

char DISPLAY_CN[][PROTIMS_DISPLAY_LEN] =
{
	"DNS����ʧ��",
	"Ӧ��%11dk",
	"����%11dk",
	"�ֿ�%11dk",
	"���%11dk",
	"��̬��%9dK",
	"��Կ%11dB",
	"�汾%11s",
	"ͨѶ��ʼ��...",
	"���ֿ�ʼ...",
	"��֤������...",
	"��ȡ����...",
	"��������...",
	"�Ƴٸ���",
	"�򿪴��ڴ���",
	"���ڲ���...",
	"����IP...",
	"DNS����...",
	"����TCP����...",
	"PPP���ڵ�¼...",
	"���ڴ�PPP...",
	"PPP����...",
	"��ʼ��...",
	"����ź�...",
	"�����ļ�ϵͳ",
	"ɾ������Ӧ��",
	"ɾ��Ӧ��",
	"���³����ļ�",
	"���²����ļ�",
	"�����ֿ�",
	"���¼��",
	"���¼��ʧ��",
	"����SO",
	"����SOʧ��",
	"ɾ��SO",
	"��ǰ�ļ�  ",
	"�����ִ���",
	" Զ������  100%% ",
	" Զ������   99%% ",
	"   ���سɹ�!\n",
	"  ���������� ",
	"      ����       ",					//  UPDATE_TITLE,
	"�绰����",
	"1.�µ�����",
	"2.��������",
	"3.��������",
	"2.��������",
	"1.Modem ����",
	"�ն˺�",
	"���ߺ���",
	"��ѡ������ ",
	"������IP",
	"�������˿�",
	"�Ƿ�DHCP",
	"����IP",
	"��������",
	"����",
	"DNS",
	"�û���",
	"����",
	"PIN��",
	"�û�ȡ��",
	"δ���ò���",
	"��������",
	"��������",
	"����PUK",
	"����PUKʧ��",
	"Զ������",
	"��������?",
	"ѡ������",
	"�����ϵ�����",
	"Modem����",
	"��Ⲧ����?",
	"��:��ȷ�ϼ�",
	"��:��ȡ����",
	"���ò�����:",
	"(����:33600)",
	"������ʱ:",
	"(����:15)",
	"������ SSID",
	"ѡ����ܷ�ʽ",
	"����5�ֽ�����",
	"����13�ֽ�����",
	"��������",
	"������Կ����",
	"���ض˿�",
	"ɾ����ʱ�ļ�?",
	"[ȷ��/ȡ��]",
	"ͨ�ų�ʼ��ʧ��",
	"����ʧ��",
	"��֤ʧ��",
	"��ȡ����ʧ��",
	"�������ʧ��",
	"����������",
	"����ʧ��",
	"ͨ�Ų�������",
	"TID����",
	"����ʧ��",
	"��������ʧ��",
	"����ʧ��",
	"����Ӧ",
	"��·æ",
	"δ����绰��",
	"���ͻ�����δ���",
	"��ʱ",
	"�û�ȡ��",
	"ͨ�ų�ʱ",
	"���յ���������",
	"��������CRC����",
	"���س�ʱ",	
	"���ڷ��ʹ��� ",
	"�������ô���",
	"���ڽ��մ���",
	"����Ĭ��·��ʧ��",
	"DHCPʹ��ʧ��",
	"DHCP��ȡʧ��",
	"����IPʧ��",
	"Socket����ʧ��",
	"Socket��ʧ��",
	"TCP����ʧ��",
	"TCP����ʧ��",
	"TCP����ʧ��",
	"Socket�ر�ʧ��",
	"PPP��¼ʧ��",
	"PPP��·����ʧ��",
	"���߳�ʼ��ʧ��",
	"����ģ���ʧ��",
	"��ȡ�ź�ʧ��",
	"���߲���ʧ��",
	"����ģ��ر�ʧ��",
	"�ļ���λ����",
	"���ļ�����",
	"��ȡ�ļ�����",
	"д���ļ�����",
	"û���㹻�ռ�",
	"ɾ���ļ�����",
	"����Ӧ��ʧ��",
	"���²���ʧ��",
	"�����ֿ�ʧ��",
	"����ɾ��ʧ��",
	"��ȡ�ն���Ϣʧ��",
	"��ȡӲ����Ϣʧ��",	
	"��ѹ���ݴ���",
	"���ݰ���С",
	"�Ƿ�ʹ��TPDU",
	"������NII",
	"�ָ���������?",
	" Զ������  %3d%% ",
	"�����ļ�%8dK",                          // 	PUB_FILE_DOWNLOADING,    
	"���¹����ļ�",                       		// 	UPDATE_PUB_FILE,  
	"���¹����ļ�ʧ��",                 		// 	UPDATE_PUBFILE_FAILED,  	
	"ɾ�������ļ�",				//DELETE_PUB_FILE	
	"�յ�������",
	"���ͳɹ�!",
	"��ȡ������Ϣ...",
	"RSA��Կ",
	"��������...",
	"����Կ",
	"����ע��...",		
	"��Կ���سɹ�!",
	"��ȡRSA��Կʧ��",
	"��ȡ����Կʧ��",
	"ע����Կʧ��",
	"������Կʧ��",
	"û��RSA��Կ",
	"��ԿУ�����",
	"RSA���ܴ���",
	"��Կ��������",
	"��Կ���ȴ���",	
	"",
};

