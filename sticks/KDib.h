#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

class KDib
{
public:
	KDib ();
	~KDib();
	BOOL CreateDib24 (int w, int h, const char* fileName);		// ������� 24��������� ����� � ��������� ������� � �������.� �������� �������� �������������� ������������� ����� ��������� �����. ����� � ������.�����.����� ������ ��� �������� ������� ��������
	void StoreDib24();											// ��������� �������� �����, ��������� ��� �� ���� � ������� BMP
	BOOL LoadFromFile (const char* fileName);					//��������� � ����� � ����������. �������� ��������� ���������� �����, ������ ������  ��������� ���.�����.������.������ ����� � ������
	void SetPixel (int x, int y, COLORREF color);				// ������ ������ � �������� � 24���� ������
	int Draw (HDC hdc, int xDst, int yDst, int wDst, int hDst, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop); // ������� ����� 
	int GetWidth () {return width;}
	int GetHeight () {return height; }
	const char* GetError () {return error.c_str();}

private:
	int width;
	int height;
	int bytesPerLine;
	BITMAPFILEHEADER fileHead;		// ��������� ���������� �����
	BITMAPINFOHEADER infoHead;		// ��������� ��������������� �����
	BITMAPINFOHEADER* pInfoHead;
	BYTE* aBitmapBits;				//������ �������� (RGB)
	int fileHeadSize;
	int infoHeadSize;
	int imageSize;
	string error;

	ifstream inpFile;
	ofstream outFile;
};
	