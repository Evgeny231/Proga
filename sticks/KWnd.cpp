#include "KWnd.h"

KWnd ::KWnd (LPCTSTR windowName, HINSTANCE hInst, int cmdShow, LRESULT (WINAPI *pWndProc) (HWND,UINT,WPARAM,LPARAM), 
					LPCTSTR menuName, int x, int y, int width, int height, 
					UINT classStyle  , DWORD windowStyle , HWND hParent)

	

{
	char szClassName [] = "MyWindowClass";
//----------------------------------------------------------------------------------------------------------------
//------------------------Заполняем поля класса-------------------------------------------------------------------
	wc.cbSize = sizeof(wc);
			/* стиль класса окна */
	wc.style = classStyle; 
			/*указатель на функцию окна. Определяем оконную процедуру для главного окна*/ 
	wc.lpfnWndProc = pWndProc; 
			/*дескриптор экземпляра приложения, в котором находится оконная процедура для этого класса*/
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance = hInst;
			/* Стандартная пиктограмма, которую можно загрузить функцией LoadIcon(hInstance, MAKEINTRESOURCE(IDI_?_?)) */ 
	wc.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION); 
			/*Стандартный курсор мыши*/ 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
			/* Кисть фона и ее цвет*/
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName=menuName;
			/* Имя класса главного окна */ 
	wc.lpszClassName = szClassName; 
			/* Маленькая пиктограмма, wcex.hIconSm, которую можно загрузить функцией LoadImage() */ 
	wc.hIconSm = LoadIcon (NULL, IDI_APPLICATION); 
//----------------------------------------------------------------------------------------------------------------
//-----------------------------------------Регистрируем класс окна------------------------------------------------
	if (!RegisterClassEx (&wc)) 
	{
		char msg[100] = "Cannot register class: ";
		strcat (msg, szClassName);
		MessageBox (NULL, msg, "Error", MB_OK);
		return;
	}
//----------------------------------------------------------------------------------------------------------------
//-----------------------------------------Создаем окно-----------------------------------------------------------
	hWnd = CreateWindow (szClassName, windowName, windowStyle, x, y, width, height, hParent, (HMENU) NULL, hInst, NULL);

	if (!hWnd) 
	{
		char text[100] = "Cannot create window: ";
		strcat (text, windowName);
		MessageBox (NULL, text, "Erroe", MB_OK);
		return;
	}

//----------------------------------------------------------------------------------------------------------------
//-----------------------------------------Показываем окно--------------------------------------------------------
	ShowWindow (hWnd, cmdShow);
}

