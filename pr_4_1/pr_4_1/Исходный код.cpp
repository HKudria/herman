#include <windows.h> 
#include <tchar.h>

int x = -10;
int y = 0;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR hello[] = _T("");
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w;
	w.lpszClassName = "HKudrya";
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	w.lpszMenuName = 0;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW; w.cbClsExtra = 0;
	w.cbWndExtra = 0;
	if (!RegisterClass(&w))
		return 0;
	
	hWnd = CreateWindow("HKudrya",
		"PRACKT 4_1",
		WS_OVERLAPPEDWINDOW, 500, 500, 500, 500,
		(HWND)NULL,
		(HMENU)NULL,
		(HINSTANCE)hInstance,
		(HINSTANCE)NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //�������� ��������� �� �������
		TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
		DispatchMessage(&lpMsg); //������� ��������� ��������������� ������� ����
	}
	return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (messg)
	{
		unsigned int key;
			case WM_CHAR:
				key = wParam;
				wsprintf(hello, "%c", key);
				hdc = GetDC(hWnd); //��������� ��������� ���������
				TextOut(hdc, x, y, hello, 1); //��������� ������ �� �����
			break;
		case WM_KEYDOWN:
				key = wParam; //��������� ���� ��������� �����

				//������� ���������� �����
				if (key == 8)
				{
					hdc = GetDC(hWnd); //��������� ��������� ���������
					TextOut(hdc, x, y, " ", 1);
					x = x - 10;
					
				}
				if (key == 13)
				{
					y = y + 20;
					x = -20;
				}

				if (key = true) {
					x = x + 10;
				}
				
			
					
		
		
				break;

		

		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return 0;
}
