#include <windows.h>
long myTime;
long myLastTime;

int dangoPositionX = 100;
int dangoPositionY = 100;
int dangoVelocityX = 80;
int dangoVelocityY = 80;

extern void onPaint(HWND hwnd, HDC hdc);

void onTimer(HWND hwnd){
	HDC hdc;
	HBITMAP hBmpMem,hPreBmp;
	RECT rect,smallRect;
	long deltaTime;
	
	myTime = GetTickCount();
	deltaTime = myTime - myLastTime;
	
	if(myLastTime){
		hdc = GetDC(hwnd);
		GetClientRect(hwnd,&rect); 
		
		dangoVelocityY = dangoVelocityY + 0.5 * deltaTime;
		
		dangoPositionX = dangoPositionX + deltaTime * dangoVelocityX / 1000;
		dangoPositionY = dangoPositionY + deltaTime * dangoVelocityY / 1000;
	
		/* ��˫�����л�ͼ */
		onPaint(hwnd, hdc);
		
		smallRect.bottom = rect.bottom - 20;
		smallRect.left = rect.left + 20;
		smallRect.right = rect.right - 20;
		smallRect.top = rect.top + 20; 
		
		if((dangoPositionX + 80) > (smallRect.right) || (dangoPositionX - 20) < smallRect.left){
			dangoVelocityX = -dangoVelocityX;
		}
		if((dangoPositionY + 50) > (smallRect.bottom) || (dangoPositionY - 30) < smallRect.top){
			dangoVelocityY = -dangoVelocityY;
		}

		ReleaseDC(hwnd,hdc);
	}
	myLastTime = myTime;
}
