#pragma once

#include "rendermanager.h"
#include "timer.h"

static bool running = true;

enum ScreenState {
	WINDOWED = 0,
	BORDERLESS_WINDOWED = 1,
	FULLSCREEN = 2,
};

class App {
public:
	void Create();
	void Destroy();
	void Update();
	void Draw();

	HWND* GetWindow();
	ScreenState GetScreenState();
	float GetWindowWidth();
	float GetWindowHeight();

	void StopRunning();

private:
	HWND window;
	float currentWindowWidth = DEFAULT_WINDOW_WIDTH;
	float currentWindowHeight = DEFAULT_WINDOW_HEIGHT;
	ScreenState screenState = ScreenState::WINDOWED;

	Renderer* renderer;
	Timer timer;
};