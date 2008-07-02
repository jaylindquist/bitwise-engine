#pragma once

#include <GLWindowApp.h>

class Test : public BitwiseEngine::GLWindowApp
{
public:
	Test(const char* windowTitle, int x, int y, int width, int height);
	virtual ~Test(void) {};

	virtual bool OnKeyDown(int key, int x, int y);
	virtual void OnDisplay();
};
