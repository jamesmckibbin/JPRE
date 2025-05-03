#include "app.h"

void App::Create()
{
	// Create a window using SDL
	SDL_Window* sdlWnd = SDL_CreateWindow(
		"JPRE", DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 0);
	window = GetActiveWindow();

	// Initialize ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForD3D(sdlWnd);

	// Initialize Renderer & ImGui for DirectX
	renderer = new Renderer();
	if (!renderer->Init(
		window,
		screenState,
		currentWindowWidth,
		currentWindowHeight))
	{
		MessageBox(0, "Failed to initialize Direct3D 12", "Error", MB_OK);
		renderer->UnInit();
		running = false;
	}
}

void App::Destroy()
{
	renderer->WaitForPreviousFrame();
	renderer->CloseFenceEventHandle();
	renderer->UnInit();

	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();

	delete renderer;
	renderer = nullptr;
}

void App::Update()
{
	SDL_Event windowEvent;
	if (SDL_PollEvent(&windowEvent))
	{
		if (windowEvent.type == SDL_EVENT_QUIT)
		{
			StopRunning();
		}

		ImGui_ImplSDL3_ProcessEvent(&windowEvent);
	}

	float dt = timer.GetFrameDelta();
	renderer->Update(dt);
}

void App::Draw()
{
	renderer->Render();
}

HWND* App::GetWindow() { return &window; }

ScreenState App::GetScreenState() { return screenState; }

float App::GetWindowWidth() { return currentWindowWidth; }

float App::GetWindowHeight() { return currentWindowHeight; }

void App::StopRunning() { running = false; }
