#include"tchar.h"
#include<windows.h>
#include<math.h>
#include"resourse.h"

//Прототип функції вікна, яка буде визначена нижче
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PifProc(HWND, UINT, WPARAM, LPARAM);
char szMessage[] = "Меню";

//объявляем строку-имя программы
char szProgName[] = "HKudrya";

char szMenu[] = "PIF_MENU"; 
double a, b, c;
char str[80] = "рядок тексту";
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{

	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w; //создаём экземпляр структуры WNDCLASS
	//И начинаем её заполнять
	w.lpszClassName = szProgName; //имя программы - объявлено выше
	w.hInstance = hInstance; //идентификатор текущего приложения
	w.lpfnWndProc = WndProc; //указатель на функцию окна
	w.lpszMenuName = szMenu; //и меню пока не будет
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //цвет фона окна
	w.style = CS_HREDRAW | CS_VREDRAW; //стиль - перерисовываемое по х и по у
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//Если не удалось зарегистрировать класс окна - выходим
	if (!RegisterClass(&w))
		return 0;

	//Создадим окно в памяти, заполнив аргументы CreateWindow
	hWnd = CreateWindow(szProgName, //Имя программы
		"Практическая 5", //Заголовок окна
		WS_OVERLAPPEDWINDOW, //Стиль окна - перекрывающееся
		100, //положение окна на экране по х
		100, //положение по у
		500, //ширина
		400, //высота
		(HWND)NULL, //идентификатор родительского окна
		(HMENU)NULL, //идентификатор меню
		(HINSTANCE)hInstance, //идентификатор экземпляра программы
		(HINSTANCE)NULL); //отсутствие дополнительных параметров

	//Выводим окно из памяти на экран
	ShowWindow(hWnd, nCmdShow);
	//Обновим содержимое окна
	UpdateWindow(hWnd);

	//Цикл обработки сообщений

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //Получаем сообщение из очереди
		TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
		DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
	}
	return(lpMsg.wParam);
}

//Функция диалогового окна
BOOL CALLBACK PifProc(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{
	//Цикл обработки сообщений
	switch (messg)
	{
	case WM_INITDIALOG: //инициализация диалога
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {

		case IDC_COUNT: //Нажатие кнопки "Считать"
			GetDlgItemText(hdlg, IDC_VALUE1, str, 40);
			a = atof(str);
			GetDlgItemText(hdlg, IDC_VALUE2, str, 40);
			b = atof(str);
			c = sqrt(a*a + b*b);
			//_gcvt_s(c, 10, str);
			MessageBox(hdlg, str, "Гипотенуза=", 0);

			break;

		case IDC_CLEAR: //Нажатие кнопки "Очистить"
			SetDlgItemText(hdlg, IDC_VALUE1, "");
			SetDlgItemText(hdlg, IDC_VALUE2, "");

			break;

		case IDC_EXIT: //Нажатие кнопки "Выход"
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

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{

	HDC hdc; //создаём контекст устройства
	static HINSTANCE hInst;
	PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
	//BITMAP bm;
	//Цикл обработки сообщений
	switch (messg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam)){

		case IDM_ENTER:
			DialogBox(hInst, (LPCTSTR)IDD_PIFAGORUS, hWnd, PifProc);
			break;

			//Выход из программы 
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		}
		break;
		//сообщение рисования
	case WM_PAINT:
		//начинаем рисовать
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