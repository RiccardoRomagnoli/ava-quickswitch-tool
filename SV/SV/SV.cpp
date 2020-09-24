// SV.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdio.h"
#include "stdafx.h"
#define WINVER 0x0500
#include <windows.h>
#include "winres.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	
	INPUT input;
	WORD vkey = 0x51;
	WORD vkey2 = VK_MBUTTON;

	bool a=false;

	printf("Up Arrow to active, Down arrow to deactivate.\n\nStatus:  ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("OFF");

	while(true)
	{
		if (GetAsyncKeyState(VK_XBUTTON2))
			a = true;
		if (GetAsyncKeyState(VK_XBUTTON1))
			a = false;
		if (a)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			printf("\b\b\b ON");
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("\b\b\bOFF");
		}

		if((GetAsyncKeyState(VK_LBUTTON)) && (a == true))
		{
			
			input.type = INPUT_KEYBOARD;
			input.ki.wScan = MapVirtualKey(vkey2, MAPVK_VK_TO_VSC);
			input.ki.time = 0;
			input.ki.dwExtraInfo = 0;
			input.ki.wVk = vkey2;
			input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &input, sizeof(INPUT));

			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));

			Sleep(100);

			input.type = INPUT_KEYBOARD;
			input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
			input.ki.time = 0;
			input.ki.dwExtraInfo = 0;
			input.ki.wVk = vkey;
			input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &input, sizeof(INPUT));

			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));

			input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &input, sizeof(INPUT));

			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));

			
		}/*else 
		{
			if((GetAsyncKeyState(VK_LBUTTON)) && (a == false))
			{
				input.type = INPUT_MOUSE;
				input.ki.wScan = MapVirtualKey(vkey2, MAPVK_VK_TO_VSC);
				input.ki.time = 0;
				input.ki.dwExtraInfo = 0;
				input.ki.wVk = vkey2;
				input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
				SendInput(1, &input, sizeof(INPUT));

				input.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &input, sizeof(INPUT));
			}
		

		}*/
	}
	return 0;
}

	


