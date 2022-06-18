#define NOPTIONS 6
#include <iostream>
#include <windows.h>

int main()
{
	//system("mode con: cols=16 lines=10");
	//SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	HWND hwnd = GetConsoleWindow();
	//SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
	EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	
	std::string Menu[NOPTIONS] = { 
		"    INTERNET    ",
		"    PROGRAMS    ",
		"    PANEL       ",
		"    COMMAND     ",
		"    REBOOT      ",
		"    POWEROFF    "
	};
	int index = 0;

	while (true)
	{
		system("cls");
		std::cout << "================\n";
		std::cout << "      MENU      \n";
		std::cout << "================\n";

		for (int i = 0; i < NOPTIONS; ++i)
		{
			if (i == index)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
				std::cout << Menu[i] << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				std::cout << Menu[i] << std::endl;
			}
		}
		std::cout << "================";
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
					system("start www.google.com");
				}
				break;
				case 1:
				{
					system("start explorer \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\" ");
				}
				break;
				case 2:
				{
					system("start control");
				}
				break;
				case 3:
				{
					system("start cmd");
				}
				break;
				case 4:
				{
					char y;
					do
					{
						system("cls");
						std::cout<< "\n Reboot (Y/N)?\n > ";
						std::cin >> y;
						if ((y =='Y')||(y =='y')) {
							system("shutdown -r -t 0");
						} 
					}
					while((y !='Y')&&(y !='N')&&(y !='y')&&(y !='n'));
				}
				break;
				case 5:
				{
					char y;
					do
					{
						system("cls");
						std::cout<< "\n Poweroff (Y/N)?\n > ";
						std::cin >> y;
						if ((y =='Y')||(y =='y')) {
							system("shutdown -s -t 0");
						} 
					}
					while((y !='Y')&&(y !='N')&&(y !='y')&&(y !='n'));
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
