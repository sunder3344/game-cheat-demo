
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define PAGESIZE 4096

int main(void) {
	HWND h = FindWindow(NULL, "123 - 记事本");
	printf("%x\n", h);
	//SendMessage(h, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	DWORD processid; 
	GetWindowThreadProcessId(h, &processid);
	printf("processid = %d\n", processid);
	
	HANDLE hprocess = 0;
	hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);
	if (hprocess == 0) {
		printf("open process failed!\n");
	} else {
		printf("open process success!\n");
	}
	
	DWORD addr = 0x01FCC410;	//根据cheat engine找到的地址 
	DWORD num = 97;			//ascii码 
	char buffer[2];

	if (ReadProcessMemory(hprocess, (LPVOID)(INT_PTR)addr, buffer, 2, NULL)) {
	
	}
	
	
	printf("read str = %s\n", buffer); 
	DWORD res = WriteProcessMemory(hprocess, (LPVOID)(INT_PTR)addr, &num, 2, 0);
	printf("res = %d\n", res);
	system("pause");
	return 0;
}
