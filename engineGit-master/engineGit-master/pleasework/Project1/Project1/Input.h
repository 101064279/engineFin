#pragma once
#include<string>
#include<vector>
#include "forestStd.h"

using namespace std;

class Input
{
public:
	Input();
	~Input();

	void KeyboardHandler(UINT message, WPARAM wParam);

	bool myBool;
	LPCSTR value = "test";
	std::string storedKey = "a";
	LPCSTR toPrint = "Press Button";

	bool deleteline = false;
	bool readyToDrawLine = 0;
	int storedPointBeginX = 0;
	int storedPointBeginY = 0;
	int storedPointEndX = 0;
	int storedPointEndY = 0;
	std::vector <int> pointsBeginX;
	std::vector <int>pointsBeginY;
	std::vector <int>pointsEndX;
	std::vector <int>pointsEndY;
	POINTS ptsBegin;
	POINT pt;
	int color = 1;
	std::vector<RECT> arrayofRects;

public:
	void ProcessInput(WPARAM wparam);
	void MouseMove(LPARAM lParam);
	void LeftMouseDown();
	void LeftMouseUp();
	void RightMouseDown();

	bool goLeft = false;
	bool goRight = false;
	bool goUp = false;
	bool goDown = false;

	//bool isWPressed = false;
	bool isEscapePressed = false;
	bool isSPressed = false;
	bool isUpPressed = false;
	bool isLeftPressed = false;
	bool isDownPressed = false;
	bool isRightPressed = false;
	bool isSpacePressed = false;

	void inputCheck();
};

