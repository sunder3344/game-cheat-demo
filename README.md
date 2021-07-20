# game-cheat-demo
a game cheat demo by C
游戏外挂demo，这里的例子以修改一个记事本内容为主，通过CE(cheat engine)软件获取需要修改内容的内存地址，然后用以下函数读取修改即可。

# 教程
* 使用win32 api
    *  HWND FindWindow（LPCTSTR IpClassName，LPCTSTR IpWindowName）; 通过类名或窗口名查找，返回窗口句柄
    *  DWORD GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId); 得到窗口句柄后通过 GetWindowThreadProcessId，这个函数来获得窗口所属进程 ID 和线程 ID
    *  HANDLE OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) 打开一个已存在的进程对象，并返回进程的句柄
    *  bool WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesWritten); 能写入某一进程的内存区域。入口区必须可以访问，否则操作将失败
    *  BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesRead); 由布尔声明可以看出， 当函数读取成功时返回1， 失败则返回0