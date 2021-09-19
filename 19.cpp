#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "./Header.h"
#include "./termcolor.hpp"
#include <Windows.h>
#include <string>
#include <cwchar>
#pragma comment(lib, "urlmon.lib")

using namespace std;
using namespace termcolor;

void windowTitle() 
{
    cout << red << "                                         ReviOS Post-Install Utility (20H2+)                                         " << reset << endl;
}

void invalidInput()
{
    cout << yellow << "                                 Please choose a valid input option from the list!" << endl << endl << endl;
}

void font()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void openUtility()
{
    system("cls");
    cout << endl;
    windowTitle();
    cout << yellow << "                                    It is recommended to follow the order already set!" << endl << endl << endl;
    cout << cyan << "                     [1] " << reset << "Change Keyboard layout | " << cyan << "[2] " << reset << "Install VC++ Runtimes |" << cyan << "[3] " << reset << "NVIDIA Drivers | " << cyan << "[4] " << reset << "AMD Drivers |" << endl<< cyan << "                     [5] " << reset << "LAPTOP ONLY - Intel iGPU Drivers |" << endl << endl
        << "                     Input the number of a utility and press Enter, " << cyan << "[0] " << reset << "to exit, or " << endl;
    cout << cyan << "                     [9]" << reset << " to go back to the main menu: ";
    wchar_t optChoice;
    cout << cyan;
    wcin >> optChoice;
    cout << reset;
    if (iswdigit(optChoice)) {
        int optChoiceInt = optChoice - '0';
        switch (optChoiceInt) {
        case 1:
            system("start ms-settings:regionlanguage");
            openUtility();
            break;
        case 2: {
            system("start /max https://www.techpowerup.com/download/visual-c-redistributable-runtime-package-all-in-one/");
            windowTitle();
            Sleep(2000);
            MessageBox(NULL, (LPCWSTR)L"To install, run the included install_all.bat with admin privileges(Right click and Run as Administrator)", (LPCWSTR)L"Important", MB_ICONINFORMATION | MB_OK);
            openUtility();
        }
            break;
        case 3: {
            system("start /max https://www.nvidia.com/Download/index.aspx");
            openUtility();
            break;
        }
        case 4: {
            system("start /max https://www.amd.com/en/support");
            openUtility();
            break;
        }
        case 5: {
            system("start /max https://downloadcenter.intel.com/download/30381/Intel-Graphics-Windows-10-DCH-Drivers");
            openUtility();
            break;
        }
        case 0:
            exit(1);
            break;
        case 9:
            main19042();
            break;
        default:
            system("cls");
            windowTitle();
            invalidInput();
            system("pause");
            openUtility();
        }
    }
    else {
        system("cls");
        windowTitle();
        invalidInput();
        system("pause");
        openUtility();
    }
}

void licenseCheck() {
    system("cls");
    cout << endl;
    windowTitle();
    cout << endl << cyan << "    By using this software, you agree that you are using it at your OWN RISK.If your PC breaks and you need to reinstall    your OS, It is most likely something on your end, as these changes should be 95 % safe unless you touch any code or     manually modify your install afterwards.In case any problems arise, ask respectfully for help in the Discord.           The members are not entitled to helping you, so do not @ anyone unless they have previously answered you and ask        for some kind of information.If you don�t understand something, or want more information about this software          and/or the changes it makes, refer to the github repository and the README(2 to be redirected)." << endl<< endl
         << reset << "    Press " << cyan << "[1] " << reset << "to continue, press " << cyan << "[2] " << reset << "to be redirected to the Github repo, press " << cyan << "[0]" << reset << " to exit" << endl
         << "    or press " << cyan << "[9]" << reset << " to go back to the main menu: ";
    cout << reset;
    wchar_t choice2;
    cout << cyan;
    wcin >> choice2;
    cout << reset;
    if (iswdigit(choice2)) {
        int choiceconv = choice2 - '0';
        switch (choiceconv) {
        case 1:
            openUtility();
            break;
        case 2 :
            system("start /max https://github.com/Cyanidexd/Post-Install-Utility"); // To be replaced with the actual github repo 
            licenseCheck();
            break;
        case 0 :
            exit(1);
        case 9 :
            main19042();
            break;
        default:
            system("cls");
            windowTitle();
            invalidInput();
            system("pause");
            licenseCheck();
        }
    }
    else {
        system("cls");
        windowTitle();
        invalidInput();
        system("pause");
        licenseCheck();
    }
}

int main19042() {
    system("cls");
    cout << endl;
    windowTitle();
    cout << cyan << "                     [1] " << reset << "ReviOS Post-Install Utility | " << cyan << "[2] " << reset << "Revision Website | " << cyan << "[3] " << reset << "Revision Discord" << endl
         << endl
         << "                     Input the number of a utility and press Enter, or " << cyan << "[0] " << reset << "to exit: ";
    wchar_t choice;
    cout << cyan;
    wcin >> choice;
    cout << reset;
    switch (choice) {
        case '1' :
            licenseCheck();
            break;
        case '2' :
            system("start /max https://sites.google.com/view/meetrevision");
            main19042();
            break;
        case '3' : 
            system("start /max https://discord.gg/962y4pU/");
            main19042();
            break;
        case '0' :
            return 0;
        default :
            system("cls");
            windowTitle();
            invalidInput();
            system("pause");
            main19042();
    }   
}
