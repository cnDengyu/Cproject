#include <windows.h>
/*------------------------

������ļ��л�ͼ 

------------------------*/

extern int dangoPositionX;
extern int dangoPositionY;

const int textWidth = 60;
const int textHeight = 17;



//�� WM_PAINT �ص� 
void onPaint(HWND hwnd, HDC hdc)
{
	HDC hDCMem;
	HBITMAP hBmpMem,hPreBmp;
	RECT rect,smallRect;
	HBRUSH hBrush;
	HPEN hPen;
	
	/* ����˫������ */ 
	// �����뵱ǰDC���ݵ��ڴ�DC
	hDCMem = CreateCompatibleDC(hdc);
	// ����һ��ָ����С��λͼ
	GetClientRect(hwnd, &rect);
	hBmpMem = CreateCompatibleBitmap(hdc, rect.right, rect.bottom); 
	// ����λͼѡ�뵽�ڴ�DC�У�Ĭ����ȫ��ɫ��
	hPreBmp = (HBITMAP)SelectObject(hDCMem, hBmpMem);
	
	//���Ʊ��� 
	hBrush = CreateSolidBrush(0x00DDDDDD);
	FillRect(hDCMem, &rect, hBrush);
	DeleteObject(hBrush);
	hBrush = CreateSolidBrush(0x00FFFFFF);
	smallRect.bottom = rect.bottom - 20;
	smallRect.left = rect.left + 20;
	smallRect.right = rect.right - 20;
	smallRect.top = rect.top + 20; 
	FillRect(hDCMem, &smallRect, hBrush);
	DeleteObject(hBrush);

	hBrush = CreateSolidBrush(0x00AAAAFF);
	hPen = CreatePen(PS_SOLID, 3, 0x00333399);
	SelectObject(hDCMem, hPen);
	SelectObject(hDCMem, hBrush);
	Ellipse(hDCMem, dangoPositionX - 20, dangoPositionY -30, dangoPositionX + 80, dangoPositionY + 50);
	DeleteObject(hPen);
	DeleteObject(hBrush); 
	
	hPen = CreatePen(PS_SOLID, 3, 0x00000000);
	SelectObject(hDCMem, hPen);
	MoveToEx(hDCMem, dangoPositionX + 20, dangoPositionY -20, NULL);
	LineTo(hDCMem, dangoPositionX + 20, dangoPositionY);
	MoveToEx(hDCMem, dangoPositionX + 40, dangoPositionY -20, NULL);
	LineTo(hDCMem, dangoPositionX + 40, dangoPositionY);
	DeleteObject(hPen);
		
	/* ��˫������ͼ���Ƶ���ʾ������ */
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, hDCMem, 0, 0, SRCCOPY);
	/* �ͷ���Դ */
	SelectObject(hDCMem, hPreBmp);
	DeleteObject(hBmpMem);
	DeleteDC(hDCMem);
}
