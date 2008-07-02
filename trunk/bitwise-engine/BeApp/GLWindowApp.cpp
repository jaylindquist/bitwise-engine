#include "GLWindowApp.h"

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL 0x020A
#endif

#ifndef WHEEL_DELTA
#define WHEEL_DELTA 120
#endif

using namespace BitwiseEngine;

GLWindowApp::GLWindowApp(const char* windowTitle, 
						 int x, int y, int width, int height):
WindowApp(),
m_acWindowTitle(windowTitle),
m_xPosition(x),
m_yPosition(y),
m_width(width),
m_height(height),
m_ID(0)
{
}

GLWindowApp::~GLWindowApp(void)
{
	TerminateApplication();
}


void 
GLWindowApp::OnMove(int x, int y)
{
	m_xPosition = x;
	m_yPosition = y;
}

void 
GLWindowApp::OnResize(int width, int height)
{
	if(width > 0 && height > 0)
	{
		m_width = width;
		m_height = height;
	}
}

void 
GLWindowApp::SetMousePosition(int x, int y)
{
	HWND hWnd = (HWND)IntToPtr(m_ID);
	POINT kPoint;
	kPoint.x = (LONG)x;
	kPoint.y = (LONG)y;
	ClientToScreen(hWnd,&kPoint);
	SetCursorPos(kPoint.x,kPoint.y);
}

void 
GLWindowApp::GetMousePosition(int& x, int& y) const
{
	HWND hWnd = (HWND)IntToPtr(m_ID);
	POINT kPoint;
	GetCursorPos(&kPoint);
	ScreenToClient(hWnd,&kPoint);
	x = (int)kPoint.x;
	y = (int)kPoint.y;
}

int 
GLWindowApp::GetStringWidth(const char* text) const
{
	if (!text || strlen(text) == 0)
	{
		return 0;
	}

	HWND hWnd = (HWND)IntToPtr(m_ID);
	HDC hDC = GetDC(hWnd);
	SIZE kSize;
	GetTextExtentPoint32(hDC, text, (int)strlen(text), &kSize);
	ReleaseDC(hWnd, hDC);

	return (int)kSize.cx;
}

int 
GLWindowApp::GetCharacterWidth(const char c) const
{
	HWND hWnd = (HWND)IntToPtr(m_ID);
	HDC hDC = GetDC(hWnd);
	SIZE kSize;
	GetTextExtentPoint32(hDC, &c, 1, &kSize);
	ReleaseDC(hWnd, hDC);

	return (int)kSize.cx;
}

int 
GLWindowApp::GetFontHeight() const
{
	HWND hWnd = (HWND)IntToPtr(m_ID);
	HDC hDC = GetDC(hWnd);
	TEXTMETRIC kMetric;
	GetTextMetrics(hDC, &kMetric);
	ReleaseDC(hWnd, hDC);

	return (int)kMetric.tmHeight;
}

bool
GLWindowApp::DoRegisterClass(char* windowClass)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));	
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc   = GLWindowApp::StaticWndProc;
	wc.hInstance     = 0;
	wc.hIcon         = LoadIcon(0,IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE);
	wc.lpszClassName = windowClass;


	// allow user modification to window class
	if(!PreRegisterClass(wc))
	{
		return false;
	}

	ATOM result = RegisterClassEx(&wc);
	
	return result != 0;
}

bool
GLWindowApp::DoCreateWindow(char* windowClass)
{
	DWORD windowExtendedStyle = WS_EX_APPWINDOW;
	DWORD windowStyle = WS_OVERLAPPEDWINDOW;

	// Require the window to have the specified client area.
	RECT kRect = { 0, 0, GetWidth() - 1, GetHeight() - 1 };

	if(AdjustWindowRectEx(&kRect, windowStyle, FALSE, windowExtendedStyle) == FALSE)
	{
		return false;
	}

	// Create The OpenGL Window
	HWND hWnd = CreateWindowEx(	
		windowExtendedStyle,				// Extended Style
		windowClass,						// Class Name
		GetWindowTitle(),					// Window Title
		windowStyle,						// Window Style
		GetXPosition(),						// Window X,Y Position
		GetYPosition(),
		GetWidth(),							// Window Width
		GetHeight(),						// Window Height
		HWND_DESKTOP,						// Desktop Is Window's Parent
		0,									// No Menu
		0,									// Pass The Window Instance
		(LPVOID)this);						// Creation Parameters

	if(hWnd == 0)
	{
		return false;
	}

	SetWindowID(PtrToInt(hWnd));

	return true;
}

bool
GLWindowApp::DoCreatePixelFormat()
{
	HWND hWnd = (HWND)IntToPtr(GetWindowID());
	HDC hDC = GetDC(hWnd);
	if(hDC == 0)
	{
		DestroyWindow(hWnd);
		SetWindowID(0);
		return false;
	}

	PIXELFORMATDESCRIPTOR pfd;

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
					PFD_SUPPORT_OPENGL |
					PFD_SWAP_LAYER_BUFFERS |
					PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 0;
	pfd.cRedShift = 0;
	pfd.cGreenBits = 0;
	pfd.cGreenShift = 0;
	pfd.cBlueBits = 0;
	pfd.cBlueShift = 0;
	pfd.cAlphaBits = 0;
	pfd.cAlphaShift = 0;
	pfd.cAccumBits = 0;
	pfd.cAccumRedBits = 0;
	pfd.cAccumGreenBits = 0;
	pfd.cAccumBlueBits = 0;
	pfd.cAccumAlphaBits = 0;
	pfd.cDepthBits = 0;
	pfd.cStencilBits = 0;
	pfd.cAuxBuffers = 0;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.bReserved = 0;
	pfd.dwLayerMask = 0;
	pfd.dwVisibleMask = 0;
	pfd.dwDamageMask = 0;

	if(!PreChoosePixelFormat(pfd))
	{
		return false;
	}

	int pixelFormat = ChoosePixelFormat(hDC, &pfd);
	if(pixelFormat == 0)
	{
		// Failed
		ReleaseDC(hWnd, hDC);
		DestroyWindow(hWnd);
		SetWindowID(0);
		return false;
	}

	if(SetPixelFormat(hDC, pixelFormat, &pfd) == FALSE)
	{
		// Failed
		ReleaseDC(hWnd, hDC);
		DestroyWindow(hWnd);
		SetWindowID(0);
		return false;
	}
	
	HGLRC hRC = wglCreateContext(hDC);
	if(hRC == 0)
	{
		ReleaseDC(hWnd, hDC);
		DestroyWindow(hWnd);
		SetWindowID(0);
		return false;
	}

	// Make The Rendering Context Our Current Rendering Context
	if(wglMakeCurrent(hDC, hRC) == FALSE)
	{
		wglDeleteContext(hRC);
		ReleaseDC(hWnd, hDC);
		DestroyWindow(hWnd);
		SetWindowID(0);
		return false;
	}

	return true;
}

void
GLWindowApp::TerminateApplication()
{
	PostQuitMessage(0);
}

LRESULT CALLBACK 
GLWindowApp::StaticWndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	GLWindowApp* pkTheApp = (GLWindowApp*)App::TheApplication;

	if(!pkTheApp || !pkTheApp->GetWindowID())
	{
		return DefWindowProc(hWnd, uiMsg, wParam, lParam);
	}

	if(pkTheApp->UserWndProc(hWnd, uiMsg, wParam, lParam))
	{
		return 0;
	}

	switch(uiMsg) 
	{
	case WM_PAINT:
		{
			PAINTSTRUCT kPS;
			BeginPaint(hWnd,&kPS);
			pkTheApp->OnDisplay();
			EndPaint(hWnd,&kPS);
			return 0;
		}
	case WM_ERASEBKGND:
		{
			// This tells Windows not to erase the background (and that the
			// application is doing so).
			return 1;
		}
	case WM_MOVE:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMove(x,y);
			return 0;
		}
	case WM_SIZE:
		{
			int width = int(LOWORD(lParam));
			int height = int(HIWORD(lParam));
			pkTheApp->OnResize(width, height);
			return 0;
		}
	case WM_KEYDOWN:
		{
			int iVirtKey = int(wParam);

			// get cursor position client coordinates
			POINT kPoint;
			GetCursorPos(&kPoint);
			ScreenToClient(hWnd, &kPoint);
			int x = (int)kPoint.x;
			int y = (int)kPoint.y;

			pkTheApp->OnKeyDown(iVirtKey, x, y);

			return 0;
		}
	case WM_KEYUP:
		{
			int iVirtKey = int(wParam);

			// get the cursor position in client coordinates
			POINT kPoint;
			GetCursorPos(&kPoint);
			ScreenToClient(hWnd,&kPoint);
			int x = (int)kPoint.x;
			int y = (int)kPoint.y;

			pkTheApp->OnKeyUp(iVirtKey, x, y);
			
			return 0;
		}
	case WM_LBUTTONDOWN:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDown(WindowApp::MOUSE_LEFT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_LBUTTONUP:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseUp(WindowApp::MOUSE_LEFT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_LBUTTONDBLCLK:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDoubleClick(WindowApp::MOUSE_LEFT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_MBUTTONDOWN:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDown(WindowApp::MOUSE_MIDDLE_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_MBUTTONUP:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseUp(WindowApp::MOUSE_MIDDLE_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_MBUTTONDBLCLK:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDoubleClick(WindowApp::MOUSE_MIDDLE_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_RBUTTONDOWN:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDown(WindowApp::MOUSE_RIGHT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_RBUTTONUP:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseUp(WindowApp::MOUSE_RIGHT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_RBUTTONDBLCLK:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));
			pkTheApp->OnMouseDoubleClick(WindowApp::MOUSE_RIGHT_BUTTON, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_MOUSEMOVE:
		{
			int x = int(LOWORD(lParam));
			int y = int(HIWORD(lParam));

			int iButton = WindowApp::MOUSE_NO_BUTTON;
			if(wParam & MK_LBUTTON)
			{
				iButton = WindowApp::MOUSE_LEFT_BUTTON;
			}
			else if(wParam & MK_MBUTTON)
			{
				iButton = WindowApp::MOUSE_MIDDLE_BUTTON;
			}
			else if(wParam & MK_RBUTTON)
			{
				iButton = WindowApp::MOUSE_RIGHT_BUTTON;
			}

			pkTheApp->OnMotion(iButton, x, y, PtrToUint(wParam));

			return 0;
		}
	case WM_MOUSEWHEEL:
		{
			short sWParam = (short)(HIWORD(wParam));
			int iDelta = ((int)sWParam)/WHEEL_DELTA;
			int iXPos = int(LOWORD(lParam));
			int iYPos = int(HIWORD(lParam));
			unsigned int uiModifiers = (unsigned int)(LOWORD(wParam));
			pkTheApp->OnMouseWheel(iDelta,iXPos,iYPos,uiModifiers);
			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProc(hWnd,uiMsg,wParam,lParam);
}

int 
GLWindowApp::Main(int argc, char** argv)
{
	static char windowClass[] = "Bitwise Engine";

	// Allow work to be done before the window is created.
	if(!OnPrecreate())
	{
		return -1;
	}

	// Register the window class.
	if(!DoRegisterClass(windowClass))
	{
		return -1;
	}

	// create the window
	if(!DoCreateWindow(windowClass))
	{
		return -1;
	}

	// create the pixel format
	if(!DoCreatePixelFormat())
	{
		return -1;
	}

	if(OnInitialize())
	{
		HWND hWnd = (HWND)IntToPtr(GetWindowID());

		// display the window
		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);

		// start the message pump
		bool bApplicationRunning = true;
		while(bApplicationRunning)
		{
			MSG kMsg;
			if(PeekMessage(&kMsg, 0, 0, 0, PM_REMOVE))
			{
				if(kMsg.message == WM_QUIT)
				{
					bApplicationRunning = false;
					continue;
				}

				HACCEL hAccel = 0;
				if(!TranslateAccelerator(hWnd, hAccel, &kMsg))
				{
					TranslateMessage(&kMsg);
					DispatchMessage(&kMsg);
				}
			}
			else
			{
				OnIdle();
			}
		}
	}

	UnregisterClass(windowClass, 0);

	OnTerminate();
	
	return 0;
}


const int WindowApp::KEY_ESCAPE = VK_ESCAPE;
const int WindowApp::KEY_LEFT_ARROW = VK_LEFT;
const int WindowApp::KEY_RIGHT_ARROW = VK_RIGHT;
const int WindowApp::KEY_UP_ARROW = VK_UP;
const int WindowApp::KEY_DOWN_ARROW = VK_DOWN;
const int WindowApp::KEY_HOME = VK_HOME;
const int WindowApp::KEY_END = VK_END;
const int WindowApp::KEY_PAGE_UP = VK_PRIOR;
const int WindowApp::KEY_PAGE_DOWN = VK_NEXT;
const int WindowApp::KEY_INSERT = VK_INSERT;
const int WindowApp::KEY_DELETE = VK_DELETE;
const int WindowApp::KEY_F1 = VK_F1;
const int WindowApp::KEY_F2 = VK_F2;
const int WindowApp::KEY_F3 = VK_F3;
const int WindowApp::KEY_F4 = VK_F4;
const int WindowApp::KEY_F5 = VK_F5;
const int WindowApp::KEY_F6 = VK_F6;
const int WindowApp::KEY_F7 = VK_F7;
const int WindowApp::KEY_F8 = VK_F8;
const int WindowApp::KEY_F9 = VK_F9;
const int WindowApp::KEY_F10 = VK_F10;
const int WindowApp::KEY_F11 = VK_F11;
const int WindowApp::KEY_F12 = VK_F12;
const int WindowApp::KEY_BACKSPACE = VK_BACK;
const int WindowApp::KEY_TAB = VK_TAB;
const int WindowApp::KEY_ENTER = VK_RETURN;
const int WindowApp::KEY_RETURN = VK_RETURN;

const int WindowApp::KEY_SHIFT = MK_SHIFT;
const int WindowApp::KEY_CONTROL = MK_CONTROL;
const int WindowApp::KEY_ALT = 0;      // not currently handled
const int WindowApp::KEY_COMMAND = 0;  // not currently handled

const int WindowApp::MOUSE_LEFT_BUTTON = 0;
const int WindowApp::MOUSE_MIDDLE_BUTTON = 1;
const int WindowApp::MOUSE_RIGHT_BUTTON = 2;
const int WindowApp::MOUSE_NO_BUTTON = -1;

const int WindowApp::MOUSE_UP = 0;
const int WindowApp::MOUSE_DOWN = 1;

const int WindowApp::MODIFIER_CONTROL = MK_CONTROL;
const int WindowApp::MODIFIER_LBUTTON = MK_LBUTTON;
const int WindowApp::MODIFIER_MBUTTON = MK_MBUTTON;
const int WindowApp::MODIFIER_RBUTTON = MK_RBUTTON;
const int WindowApp::MODIFIER_SHIFT = MK_SHIFT;