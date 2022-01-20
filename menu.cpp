#define NOPTIONS 6
#include <iostream>
#include <windows.h>

int main()
{
	system("mode con: cols=100 lines=40");
	SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	std::string Menu[NOPTIONS] = { 
		"  COMMAND   ",
		"  BROWSER   ",
		"  PROGRAMS  ",
		"  CONTROL   ",
		"  REBOOT    ",
		"  POWEROFF  "
	};
	int index = 0;

	while (true)
	{
		system("cls");
		std::cout << "============\n";
		std::cout << "    MENU    \n";
		std::cout << "============\n";

		for (int i = 0; i < NOPTIONS; ++i)
		{
			if (i == index)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
				std::cout << Menu[i] << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				std::cout << Menu[i] << std::endl;
			}
		}
		std::cout << "============\n";
		while (true)
		{
			system("pause > null");
			if (GetAsyncKeyState(VK_UP) & 0x01)
			{
				index -= 1;
				if (index == -1)
				{
					index = NOPTIONS-1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x01)
			{
				index += 1;
				if (index == NOPTIONS)
				{
					index = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x01)
			{
				switch (index)
				{
				case 0:
				{
					system("start cmd");
				}
				break;
				case 1:
				{
					system("start www.google.com");
				}
				break;
				case 2:
				{
					system("start explorer \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\" ");
				}
				break;
				case 3:
				{
					system("start control");
				}
				break;
				case 4:
				{
					system("shutdown -r -t 0");
				}
				break;
				case 5:
				{
					system("shutdown -s -t 0");
				}
				break;
				

				}
				break;

			}
		}
		Sleep(10);
	}
	return 0;
}
