#include "Test.h"
#include <iostream>
#include <GL/gl.h>

using namespace std;
using namespace BitwiseEngine;


Test::Test(const char* windowTitle, int x, int y, int width, int height):
GLWindowApp(windowTitle, x, y, width, height)
{
}


void
Test::OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	SwapBuffers(GetDC((HWND)IntToPtr(GetWindowID())));
}


bool 
Test::OnKeyDown(int key, int x, int y)
{

	switch(key)
	{
	case 'Q':
		TerminateApplication();
		break;

	case 'R':
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		break;

	case 'W':
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		break;

	default: break;
	}

	return 0;
}

int main(int argc, char** argv)
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);
	App::TheApplication = new Test("Hello World", 100, 100, 500, 500);
	return App::TheApplication->Run(argc, argv);
}