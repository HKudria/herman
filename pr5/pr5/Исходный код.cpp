#include"tchar.h"
#include<windows.h>
#include<math.h>
#include"resourse.h"

//�������� ������� ����, ��� ���� ��������� �����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PifProc(HWND, UINT, WPARAM, LPARAM);
char szMessage[] = "����";

//��������� ������-��� ���������
char szProgName[] = "HKudrya";

char szMenu[] = "PIF_MENU"; 
double a, b, c;
char str[80] = "����� ������";
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{

	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w; //������ ��������� ��������� WNDCLASS
	//� �������� � ���������
	w.lpszClassName = szProgName; //��� ��������� - ��������� ����
	w.hInstance = hInstance; //������������� �������� ����������
	w.lpfnWndProc = WndProc; //��������� �� ������� ����
	w.lpszMenuName = szMenu; //� ���� ���� �� �����
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���� ���� ����
	w.style = CS_HREDRAW | CS_VREDRAW; //����� - ���������������� �� � � �� �
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//���� �� ������� ���������������� ����� ���� - �������
	if (!RegisterClass(&w))
		return 0;

	//�������� ���� � ������, �������� ��������� CreateWindow
	hWnd = CreateWindow(szProgName, //��� ���������
		"������������ 5", //��������� ����
		WS_OVERLAPPEDWINDOW, //����� ���� - ���������������
		100, //��������� ���� �� ������ �� �
		100, //��������� �� �
		500, //������
		400, //������
		(HWND)NULL, //������������� ������������� ����
		(HMENU)NULL, //������������� ����
		(HINSTANCE)hInstance, //������������� ���������� ���������
		(HINSTANCE)NULL); //���������� �������������� ����������

	//������� ���� �� ������ �� �����
	ShowWindow(hWnd, nCmdShow);
	//������� ���������� ����
	UpdateWindow(hWnd);

	//���� ��������� ���������

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //�������� ��������� �� �������
		TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
		DispatchMessage(&lpMsg); //������� ��������� ��������������� ������� ����
	}
	return(lpMsg.wParam);
}

//������� ����������� ����
BOOL CALLBACK PifProc(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{
	//���� ��������� ���������
	switch (messg)
	{
	case WM_INITDIALOG: //������������� �������
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {

		case IDC_COUNT: //������� ������ "�������"
			GetDlgItemText(hdlg, IDC_VALUE1, str, 40);
			a = atof(str);
			GetDlgItemText(hdlg, IDC_VALUE2, str, 40);
			b = atof(str);
			c = sqrt(a*a + b*b);
			//_gcvt_s(c, 10, str);
			MessageBox(hdlg, str, "����������=", 0);

			break;

		case IDC_CLEAR: //������� ������ "��������"
			SetDlgItemText(hdlg, IDC_VALUE1, "");
			SetDlgItemText(hdlg, IDC_VALUE2, "");

			break;

		case IDC_EXIT: //������� ������ "�����"
			EndDialog(hdlg, LOWORD(wParam));
			return TRUE;
			break;

		}
		break;

	case WM_QUIT:
		DestroyWindow(hdlg);
		break;


	default: return false;

	}

}

//������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{

	HDC hdc; //������ �������� ����������
	static HINSTANCE hInst;
	PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������
	//BITMAP bm;
	//���� ��������� ���������
	switch (messg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam)){

		case IDM_ENTER:
			DialogBox(hInst, (LPCTSTR)IDD_PIFAGORUS, hWnd, PifProc);
			break;

			//����� �� ��������� 
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		}
		break;
		//��������� ���������
	case WM_PAINT:
		//�������� ��������
		//hmdc=CreateCompatibleDC(hdc);
		hdc = BeginPaint(hWnd, &ps);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, 5, 5, szMessage, strlen(szMessage));
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