#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

/* offsets from unknowncheats.me :(*/
DWORD playerbase;
DWORD PlayerBaseAddress = 0x0050F4F4;

DWORD HealthOffset = 0xF8;
DWORD GrenadeOffset = 0x158;
DWORD AmmoOffset = 0x150;
DWORD PistolOffset = 0x13C;
DWORD ArmorOffset = 0xFC;
DWORD AkimboAmmo = 0x15C;

DWORD val = 999; 
DWORD pid;

int main()
{
	static const char banner[] =

		"Assault Cube Trainer\n"
		"Author : Souhardya Sardar\n"
		"Github : github.com/Souhardya\n\n";



	fwrite(banner, sizeof(char), sizeof(banner), stdout);

	HWND handle = FindWindow(NULL, "AssaultCube");
	DWORD getid = GetWindowThreadProcessId(handle, &pid);
	if (!getid) {
		std::cout <<"Assault Cube isn't running" << std::endl;
		std::cout <<"";
		Sleep(999);
		exit(0);
	}

	HANDLE openproc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!openproc) {
		std::cout << "Can't get a handle to the process" << std::endl;
		Sleep(999);
		exit(0);
	}

	
	for (;;) { // infinite loop :3

		std::cout <<"Popping the hacks ";

		/*Healthhack*/
		bool healthread = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool healthhack = WriteProcessMemory(openproc, (LPVOID)(playerbase + HealthOffset), &val, sizeof(int), NULL);
		
		

		/*Ammohack*/

		bool ammoread = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool ammohack = WriteProcessMemory(openproc, (LPVOID)(playerbase + AmmoOffset), &val, sizeof(int), NULL);
		

		/*Grenadehack*/

		bool greanderead = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool grenaderead = WriteProcessMemory(openproc, (LPVOID)(playerbase + GrenadeOffset), &val, sizeof(int), NULL);
		
		
		/*Pistolammoz*/
		bool pistolread = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool pistolhack = WriteProcessMemory(openproc, (LPVOID)(playerbase + PistolOffset), &val, sizeof(int), NULL);
		
		/*ArmorHackz*/
		bool armorread = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool armorhack = WriteProcessMemory(openproc, (LPVOID)(playerbase + ArmorOffset), &val, sizeof(int), NULL);

		bool akimboread = ReadProcessMemory(openproc, (LPCVOID)PlayerBaseAddress, &playerbase, sizeof(int), NULL);
		bool akimbohack = WriteProcessMemory(openproc, (LPVOID)(playerbase + AkimboAmmo), &val, sizeof(int), NULL);

		
	}

	system("pause");

	return 0;

}
