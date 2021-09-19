#define _WIN32_WINNT 0x600
#include <iostream>
#include <windows.h>
#include <slpublic.h>
#include <tchar.h>  
#include <array>
#include <string>
#include "Header.h"
#pragma comment(lib, "Slwga.lib")
#pragma comment(lib, "Rpcrt4.lib")

using namespace std;

string exec(const char* cmd) {  
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool isActivated()
{
    GUID uid;
    RPC_WSTR rpc = (RPC_WSTR)_T("55c92734-d682-4d71-983e-d6ec3f16059f");
    UuidFromString(rpc, &uid);
    SL_GENUINE_STATE state;
    SLIsGenuineLocal(&uid, &state, NULL);
    return state == SL_GEN_STATE_IS_GENUINE;
}

int main() {
    system("title ReviOS Post-Install Utility");
    if (isActivated())
    {
        string version = exec("ver");
        if (version.find("10.0.19042.630") != std::string::npos || version.find("10.0.19041.329") != std::string::npos || version.find("10.0.19043.928") != std::string::npos)
            main19042();
        else
            cout << "You are using an unsupported build of Windows/ReviOS" << endl;
    }
    else
        cout << "Your Windows version is not activated. Use a license key or activate Windows through other means" << endl;
}

// Thank you danL for help with making this efficient!