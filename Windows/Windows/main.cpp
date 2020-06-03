#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInctance, HINSTANCE hPrevInst,
	LPSTR lpCmdLine, int nCmdShow)
{
	//MessageBox(NULL, "Hello World!", "First program", MB_YESNO | MB_ICONINFORMATION);
	DialogBoxParam(hInctance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	SetFocus(GetDlgItem(hwnd, IDC_NAME));
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//MessageBox(hwnd, "Была нажата кнопка OK!", "Info", MB_OK | MB_ICONINFORMATION);
			//EndDialog(hwnd, IDOK);
			CONST INT SIZE = 20;
			CHAR sz_name[SIZE]{};
			HWND hEdit = GetDlgItem(hwnd, IDC_NAME);
			SendMessage(hEdit, WM_GETTEXT, 20, (LPARAM)sz_name);
			CHAR sz_greeting[SIZE] = "Привет ";
			strcat_s(sz_greeting, SIZE, sz_name);
			strcat_s(sz_greeting, SIZE, "!");
			MessageBox(hwnd, sz_greeting, "Greeting", MB_OK|MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL:
			EndDialog(hwnd, IDCANCEL);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}