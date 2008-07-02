#pragma once

#include "App.h"
#include "BeApp.h"

namespace BitwiseEngine
{

/***********************************************
*
* Window Application Interface
* All methods are virtual and none
* are defined
*
************************************************/

class BE_APPLICATION_ITEM WindowApp : public App
{
public:
	WindowApp();
	virtual ~WindowApp();

	virtual void SetWindowID(int windowID) = 0;
	virtual int GetWindowID() const = 0;

	// event callbacks
	virtual bool OnPrecreate() = 0;
	virtual bool OnInitialize() = 0;
	virtual void OnTerminate() = 0;

	virtual void OnMove(int x, int y) = 0;
	virtual void OnResize(int width, int height) = 0;

	virtual void OnDisplay() = 0;
	virtual void OnIdle() = 0;

	virtual bool OnKeyDown(int key, int x, int y) = 0;
	virtual bool OnKeyUp(int key, int x, int y) = 0;

	virtual bool OnMouseUp(int button, int x, int y, unsigned int modifiers) = 0;
	virtual bool OnMouseDown(int button, int x, int y, unsigned int modifiers) = 0;
	virtual bool OnMouseDoubleClick(int button, int x, int y, unsigned int modifiers) = 0;

	virtual bool OnMotion(int button, int x, int y, unsigned int modifiers) = 0;
	virtual bool OnMouseWheel(int scrollDelta, int x, int y, unsigned int modifiers) = 0;

	// mouse position
	virtual void SetMousePosition(int x, int y) = 0;
	virtual void GetMousePosition(int& x, int& y) const = 0;

	virtual void TerminateApplication() = 0;

	// Key identifiers.  These are platform-specific, so classes that
	// implement the WindowApplication interfaces must define these variables.
	// They are not defined by WindowApplication.
	static const int KEY_ESCAPE;
	static const int KEY_LEFT_ARROW;
	static const int KEY_RIGHT_ARROW;
	static const int KEY_UP_ARROW;
	static const int KEY_DOWN_ARROW;
	static const int KEY_HOME;
	static const int KEY_END;
	static const int KEY_PAGE_UP;
	static const int KEY_PAGE_DOWN;
	static const int KEY_INSERT;
	static const int KEY_DELETE;
	static const int KEY_F1;
	static const int KEY_F2;
	static const int KEY_F3;
	static const int KEY_F4;
	static const int KEY_F5;
	static const int KEY_F6;
	static const int KEY_F7;
	static const int KEY_F8;
	static const int KEY_F9;
	static const int KEY_F10;
	static const int KEY_F11;
	static const int KEY_F12;
	static const int KEY_BACKSPACE;
	static const int KEY_TAB;
	static const int KEY_ENTER;
	static const int KEY_RETURN;

	// keyboard modifiers
	static const int KEY_SHIFT;
	static const int KEY_CONTROL;
	static const int KEY_ALT;
	static const int KEY_COMMAND;

	// mouse buttons
	static const int MOUSE_LEFT_BUTTON;
	static const int MOUSE_MIDDLE_BUTTON;
	static const int MOUSE_RIGHT_BUTTON;
	static const int MOUSE_NO_BUTTON;

	// mouse state
	static const int MOUSE_UP;
	static const int MOUSE_DOWN;

	// mouse modifiers
	static const int MODIFIER_CONTROL;
	static const int MODIFIER_LBUTTON;
	static const int MODIFIER_MBUTTON;
	static const int MODIFIER_RBUTTON;
	static const int MODIFIER_SHIFT;
};

}