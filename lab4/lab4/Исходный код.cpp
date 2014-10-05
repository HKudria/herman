#include "tchar.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "MyMenu.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szProgName[] = _T("HKudrya");
TCHAR str[] = _T("����������� 4");
TCHAR szMenu[] = _T("MainMenu");
TCHAR szMessage[] = _T("������� �������� ����� ����.");
short sLen;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;


	WNDCLASS w;
	w.lpszClassName = szProgName;
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	w.lpszMenuName = szMenu; //��� ������ ����
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	if (!RegisterClass(&w))
		return 0;

	hWnd = CreateWindow(szProgName,
		"������������ ���� � Win32 API",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		500,
		400,
		(HWND)NULL,
		(HMENU)NULL,
		hInstance,
		(LPSTR)NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&lpMsg, NULL, 0, 0)) {
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	//������� ����������
	unsigned long lSectInClust, lByteInSect, lNumFreeClust, lTotal, lBuf, lBuf1;
	char szCurrent[MAX_PATH];

	//���������� ��� ���� � ���
	SYSTEMTIME st;
	WORD month, day, year, hour, min, sec;

	//������������� ���� ����������� � ���������
	char ComputerName[MAX_COMPUTERNAME_LENGTH + 1];
	unsigned long len_ComputerName = MAX_COMPUTERNAME_LENGTH + 1;
	char UserName[256 + 1];
	unsigned long len_UserName = 256 + 1;

	BOOL comp;

	//���� ������� ����������
	switch (messg)
	{

	case WM_COMMAND:
		switch (LOWORD(wParam)){

			//����� � �������� 
		case IDM_EXIT: DestroyWindow(hWnd);

			//������ ���� �� �����?
		case IDM_DSPACE:
			GetDiskFreeSpace(NULL, &lSectInClust, &lByteInSect, &lNumFreeClust, &lTotal);
			lBuf1 = lSectInClust*lByteInSect*lTotal;
			sLen = sprintf_s(szMessage, "������ �� �����: %ld ��", lBuf1 / 1000000);
			break;

			//³���� �� �����
		case IDM_FREE:
			GetDiskFreeSpace(NULL, &lSectInClust, &lByteInSect, &lNumFreeClust, &lTotal);
			lBuf = lSectInClust;
			lBuf *= lByteInSect;
			lBuf *= lNumFreeClust;
			sLen = sprintf_s(szMessage, "�� ����� �����: %ld ��", lBuf / 1000000);
			break;

			
			//�������� ���
		case IDM_TIME:
			GetSystemTime(&st);
			min = st.wMinute;
			sec = st.wSecond;
			hour = st.wHour;
			
				sLen = sprintf_s(szMessage, "���: %ld:%d:%d", hour, min, sec);
			break;

			//������� ����
		case IDM_DATE:
			GetSystemTime(&st);
			year = st.wYear;
			month = st.wMonth;
			day = st.wDay;
			if (month<10)
				sLen = sprintf_s(szMessage, "����: %d/0%d/%d", day, month, year);
			else
				sLen = sprintf_s(szMessage, "����: %d/%d/%d", day, month, year);
			break;

			//��� ���������
		case IDM_ACOMP:

			comp = GetComputerName(ComputerName, &len_ComputerName);

			if (comp != 0)
			{
				sLen = sprintf_s(szMessage, "%s", ComputerName);
			}
			else
				MessageBox(hWnd, "��� ��������� ����������!", "�����������:", MB_OK | MB_ICONSTOP);

			break;

			//��� �����������
		case IDM_ABOUT:

			comp = GetUserNameA(UserName, &len_UserName);

			if (comp != 0)
			{
				sLen = sprintf_s(szMessage, "%s", UserName);
			}
			else
				MessageBox(hWnd, " ��� ����������� ����������!", " �����������...", MB_OK | MB_ICONSTOP);

			break;

		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;

		//��������� ����� �� �����
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, szMessage, sLen);
		ValidateRect(hWnd, NULL);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return 0;
}
