#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

class KDib
{
public:
	KDib ();
	~KDib();
	BOOL CreateDib24 (int w, int h, const char* fileName);		// создает 24разрядный растр с заданными шириной и высотой.В процессе создания осуществляется инициализация полей заголовка растр. файла и информ.блока.Выдел помять для хранения массива пикселов
	void StoreDib24();											// сохраняет заданный растр, записывая его на диск в формате BMP
	BOOL LoadFromFile (const char* fileName);					//Загружает с диска в оперативку. Читается заголовок растрового файла, вычисл размер  заголовка инф.блока.Вычисл.размер файла в байтах
	void SetPixel (int x, int y, COLORREF color);				// прямой доступ к пикселам в 24разр растре
	int Draw (HDC hdc, int xDst, int yDst, int wDst, int hDst, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop); // Выводит растр 
	int GetWidth () {return width;}
	int GetHeight () {return height; }
	const char* GetError () {return error.c_str();}

private:
	int width;
	int height;
	int bytesPerLine;
	BITMAPFILEHEADER fileHead;		// заголовок растрового файла
	BITMAPINFOHEADER infoHead;		// заголовок информационного блока
	BITMAPINFOHEADER* pInfoHead;
	BYTE* aBitmapBits;				//массив пикселов (RGB)
	int fileHeadSize;
	int infoHeadSize;
	int imageSize;
	string error;

	ifstream inpFile;
	ofstream outFile;
};
	