#ifndef SEND_MSG_TO_SERVICE_HEADER
#define SEND_MSG_TO_SERVICE_HEADER

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <winsvc.h>

#define SERVICE_NAME _T("WinSEGAV AutoConfig")
//CUSTOM MESSAGE FOR SERVICE TO LAUNCH AN APP INTO SESSION1
#define SERVICE_CONTROL_CUSTOM_MESSAGE			0x0085
#define SERVICE_CONTROL_CUSTOM_MSG_STOP_SERVICE	0x0088
#define SERVICE_CONTROL_CUSTOM_MSG_UPDATE_VSD   0x0089
#define SERVICE_CONTROL_CUSTOM_MSG_RESTART_IT   0x0090
#define SERVICE_CONTROL_CUSTOM_MSG_STOP_CLAMD   0x0091
#define SERVICE_CONTROL_CUSTOM_MSG_START_CLAMD  0x0092


int SendMsgToService(unsigned int msg = SERVICE_CONTROL_CUSTOM_MESSAGE);

#endif