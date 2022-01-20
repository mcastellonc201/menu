#define NOPTIONS 14
#include <iostream>
#include <windows.h>

int main()
{
	system("mode con: cols=100 lines=40");
	SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	std::string Menu[NOPTIONS] = { 
		"  BROWSER   ",
		"  EXPLORER  ",
		"  OUTLOOK   ",
		"  CMD       ",
		"  NOTEPAD   ",
		"  WORD      ",
		"  EXCEL     ",
		"  POWERPNT  ",
		"  PAINT     ",
		"  PANEL     ",
		"  PRINTERS  ",
		"  NET       ",
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
					index = 2;
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
					system("start www.google.com");
				}
				break;
				case 1:
				{
					system("start explorer");
				}
				break;
				case 2:
				{
					system("start outlook");
				}
				break;
				case 3:
				{
					system("start cmd");
				}
				break;
				case 4:
				{
					system("start notepad");
				}
				break;
				case 5:
				{
					system("start winword");
				}
				break;
				case 6:
				{
					system("start excel");
				}
				break;
				case 7:
				{
					system("start powerpnt");
				}
				break;
				case 8:
				{
					system("start mspaint");
				}
				break;
				case 9:
				{
					system("start control");
				}
				break;
				case 10:
				{
					system("start control printers");
				}
				break;
				case 11:
				{
					system("start control netconnections");
				}
				break;
				case 12:
				{
					system("shutdown -r -t 0");
				}
				break;
				case 13:
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
