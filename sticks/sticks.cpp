#include <windows.h>
#include "KWnd.h"
#include "KDib.h"
#include "time.h"
#include "resource.h"
#include <math.h>
using namespace std;


COLORREF crFirst = RGB(255,0,0);
COLORREF crSecond = RGB(0,800,255);


int t,p;
int k=1;

bool tmp= true;
bool GameStart=0;
bool Rules=0;
bool player=1;
bool Win1=0;
bool Win2=0;
int *X=new int[22] ;
int *Y=new int[22] ;
bool Ver[21][22];
bool Gor[22][21];
bool Square [21][21];

#define FILE_NAME "fon.bmp"
#define RULES "rules.bmp"
#define START "start.bmp"
#define WIN1 "win1.bmp"
#define WIN2 "win2.bmp"

KDib bmp;
KDib startofgame;
KDib rules;
KDib win1;
KDib win2;

HPEN hCr,hN;
HBRUSH hBrush1,hBrush2;
void Paint(HDC hdc, int x1,int y1 ){
	    hCr = CreatePen(PS_SOLID,2,crFirst);
		hN = CreatePen(PS_SOLID,2,crSecond);
		hBrush1= CreateSolidBrush(crFirst);
		hBrush2= CreateSolidBrush(crSecond);

				for (int i=0;i<21;i++){ 
			
	
				for(int j=0;j<22;j++){
	
					
					if (Ver[i][j]==true){

						if(player==1){SelectObject(hdc,hCr);}
						if(player==0){SelectObject(hdc,hN);}
						MoveToEx (hdc, X[i], Y[j], NULL);
						LineTo   (hdc,X[i],Y[j+1]);
					
		

				
				}
				}}

			

				for (int i=0;i<22;i++){
				for(int j=0;j<21;j++){
//				if((x1-X[j]<20)&&((x1-X[j])>0)){
					if (Gor[i][j]==true){
					//HDC dc = hDC;
					if(player==1){SelectObject(hdc,hCr);}
					if(player==0){SelectObject(hdc,hN);}
				MoveToEx (hdc, X[j], Y[i], NULL);
				LineTo   (hdc,X[j+1],Y[i]);

					
					
		//			InvalidateRect (hWnd, &rect, FALSE) ;
			//		ReleaseDC (hWnd, dc);}
			//		PostMessage(hWnd,WM_PAINT,wParam,lParam);

				}
				}
			}
				
				for (int i=0;i<21;i++){
					for(int j=0;j<21;j++){
						if (Square[i][j]){
							if(player==1){SelectObject(hdc,hBrush1);}
							if(player==0){SelectObject(hdc,hBrush2);}
							Rectangle(hdc,X[i],Y[j],X[i+1],Y[j+1]);
						}
					}
				}
//			}}

}


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

//------------------------------------------------------------------------
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	for(int i=0;i<21;i++){
		for(int j=0;j<22;j++){
			Ver[i][j]=0;
		}
	}
	
	for(int i=0;i<22;i++){
		for(int j=0;j<21;j++){
			Gor[i][j]=0;
		}
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			Square[i][j]=0;
		}
	}
	 X[0]=73;
	 Y[0]=114;
	for (int i=1;i<22;i++)
	{
	X[i]=X[i-1]+20;
	Y[i]=Y[i-1]+20;
	}
	

	MSG msg;
	KWnd mainWnd ("Stics", hInstance, nCmdShow, WndProc);
	HWND hWnd=mainWnd.GetWnd();

	
	

	while ( GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}

	return msg.wParam;
}

//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------
int coordinate1, coordinate2, coordinate3,coordinate4;

LRESULT CALLBACK WndProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	PAINTSTRUCT ps;
	RECT rect;					
	int dX, dY;
	int ws, hs, wd, hd;
	static BOOL isFileLoaded;
	 
	//static RECT rt, rect;
	 static HDC hDC;
	

	 int x,y;
	
	switch (uMsg)
	{

	case WM_CREATE:
		GameStart=0;
			Rules=0;
		hDC= GetDC (hWnd);

		isFileLoaded = bmp.LoadFromFile (FILE_NAME);
			if (!isFileLoaded)
			{
				MessageBox (hWnd, "File " FILE_NAME " DON'T LOADED", "Error", MB_OK);
				break;
			}
			isFileLoaded = startofgame.LoadFromFile (START);
			if (!isFileLoaded)
			{
				MessageBox (hWnd, "File " START" DON'T LOADED", "Error", MB_OK);
				break;
			}
			isFileLoaded = rules.LoadFromFile (RULES);
			if (!isFileLoaded)
			{
				MessageBox (hWnd, "File " RULES" DON'T LOADED", "Error", MB_OK);
				break;
			}
			isFileLoaded = win1.LoadFromFile (WIN1);
			if (!isFileLoaded)
			{
				MessageBox (hWnd, "File " WIN1" DON'T LOADED", "Error", MB_OK);
				break;
			}
			isFileLoaded = win2.LoadFromFile (WIN2);
			if (!isFileLoaded)
			{
				MessageBox (hWnd, "File " WIN2" DON'T LOADED", "Error", MB_OK);
				break;
			}
		GetClientRect (hWnd, &rect);
		dX = bmp.GetWidth () - rect.right;
		dY = bmp.GetHeight() - rect.bottom;

		GetWindowRect (hWnd, &rect);
		InflateRect (&rect, dX/2, dY/2);
		MoveWindow (hWnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top, TRUE);
		ReleaseDC (hWnd, hDC);
		break;

	 case WM_LBUTTONDOWN:
		
		
		 x=LOWORD(lParam);
		 y=HIWORD(lParam);
		 coordinate1=x; coordinate2=y;

		 switch (Rules){
		
		case 1: if(x>750 && x<930 && y>420 && y<465) {GameStart=0;  Rules=0; InvalidateRect (hWnd, NULL, 0);}
				if(x>750 && x<930 && y>500 && y<540) { SendMessage (hWnd,WM_DESTROY, wParam, lParam);}
				break;
		case 0: if(x>380 && x<630 && y>200 && y<240 && GameStart==0 ) {GameStart=1; InvalidateRect (hWnd, NULL, 0);}	
				if(x>380 && x<630 && y>280 && y<320 && GameStart==0 ) {Rules=1; InvalidateRect (hWnd, NULL, 0);}
				if(x>380 && x<630 && y>350 && y<390 && GameStart==0 ){ SendMessage (hWnd,WM_DESTROY, wParam, lParam);}
				if(x>600 && x<800 && y>290 && y<340 && GameStart==1 ){ SendMessage (hWnd,WM_DESTROY, wParam, lParam);}
				if(x>600 && x<800 && y>210 && y<260 && GameStart==1 )
				{
					for(int i=0;i<21;i++){
		for(int j=0;j<22;j++){
			Ver[i][j]=0;
		}
	}
	
	for(int i=0;i<22;i++){
		for(int j=0;j<21;j++){
			Gor[i][j]=0;
		}
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			Square[i][j]=0;
		}
	}
					GameStart=0;  Rules=0; InvalidateRect (hWnd, NULL, 0);}
				if(x>600 && x<800 && y>127 && y<177 && GameStart==1 && player==1 ){GameStart=0;Win1=1; InvalidateRect (hWnd, NULL, 0);}
				if(x>600 && x<800 && y>127 && y<177 && GameStart==1 && player==0 ){GameStart=0;Win2=1; InvalidateRect (hWnd, NULL, 0);}
				if(x>700 && x<890 && y>530 && y<575 && Win1==1 ){ SendMessage (hWnd,WM_DESTROY, wParam, lParam);}
				if(x>700 && x<900 && y>490 && y<530 && Win2==1 ){ SendMessage (hWnd,WM_DESTROY, wParam, lParam);}
				break;
		}
		  if(player)    //ходит первый игрок
				 {
					 
					player = 0; //ход переходит ко второму игроку
				 }
				 else    //ходит второй игрок
				 {
					  
					 player = 1;  //ход переходит к первому игроку
				 }
		 for (int i=0;i<21;i++){ 
			
			if((abs(coordinate1-X[i])<3)){
				for(int j=0;j<22;j++){
				if((coordinate2-Y[j]<20)&&((coordinate2-Y[j])>0)){
					
					 Ver[i][j]=true;
					 if (Ver[i][j]){
						 if((Ver[i][j+1])&&(Gor[i][j])&&(Gor[i+1][j]))
						 {
							 Square[i][j]=true;
						 }
						 if((Ver[i][j-1])&&(Gor[i][j-1])&&(Gor[i+1][j-1]))
						 {
							 Square[i][j-1]=true;
						 }
					 }
				}
			}
		}
	}
				
				

			 for (int i=0;i<22;i++){
			if((abs( coordinate2-Y[i])<3)){
				for(int j=0;j<21;j++){
				if((coordinate1-X[j]<20)&&((coordinate1-X[j])>0)){
					Gor[i][j]=true;
					if (Gor[i][j]){
						 if((Gor[i-1][j])&&(Ver[i-1][j])&&(Gor[i-1][j+1]))
						 {
							 Square[i-1][j]=true;
						 }
						 if((Gor[i+1][j])&&(Ver[i][j])&&(Gor[i][j+1]))
						 {
							 Square[i][j]=true;
						 }
					}
				}
			}
		}
	}

		 
				InvalidateRect (hWnd, NULL, TRUE) ;
				
		

		 


		 
		 /*if (k==2){ coordinate3=x; coordinate4=y; PostMessage(hWnd,WM_PAINT,wParam,lParam);}
		 if (k==1){ coordinate1=x; coordinate2=y;PostMessage(hWnd,WM_PAINT,wParam,lParam); }
		 */
		/* rect.left = x-10;
		  rect.top =  y-10;
	     rect.right = x + 10;
		 rect.bottom = y + 10;*/
		 
		 
		break;

	case WM_PAINT:
		{
		hDC = BeginPaint (hWnd, &ps);
		hCr = CreatePen(PS_SOLID,2,crFirst);
		hN = CreatePen(PS_SOLID,2,crSecond);
		hBrush1= CreateSolidBrush(crFirst);
		hBrush2= CreateSolidBrush(crSecond);

		HPEN hOP = (HPEN)SelectObject(hDC,hCr);

		if ( GameStart==0)
		{
			wd = ws = startofgame.GetWidth ();
			hd = hs = startofgame.GetHeight ();
			startofgame.Draw (hDC, 0, 0, wd, hd, 0, 0, ws, hs, SRCCOPY);
		}
		if ( GameStart==1)
		{
			wd = ws = bmp.GetWidth ();
		    hd = hs = bmp.GetHeight ();
		    bmp.Draw (hDC, 0, 0, wd, hd, 0, 0, ws, hs, SRCCOPY);
			
			// отрисовка поля

			
			Paint(hDC,coordinate1,coordinate2);
		}
		

		
		if ( Rules==1)
		{
			wd = ws = rules.GetWidth ();
		    hd = hs = rules.GetHeight ();
		    rules.Draw (hDC, 0, 0, wd, hd, 0, 0, ws, hs, SRCCOPY);
		}

		if ( Win1==1)
		{
			wd = ws = win1.GetWidth ();
			hd = hs = win1.GetHeight ();
			win1.Draw (hDC, 0, 0, wd, hd, 0, 0, ws, hs, SRCCOPY);
		}
		if ( Win2==1)
		{
			wd = ws = win2.GetWidth ();
			hd = hs = win2.GetHeight ();
			win2.Draw (hDC, 0, 0, wd, hd, 0, 0, ws, hs, SRCCOPY);
		}
		//if (tmp==true){
		//tmp=false;
		
		
		
			
		EndPaint (hWnd, &ps);
		break;
		}	
	
	case WM_DESTROY:
		ReleaseDC(hWnd,hDC);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc (hWnd, uMsg, wParam, lParam);
		}
return 0;
}