#include "app.h"

int main(int argc, char* args[]) {
	
	App* main_app = new App();

	main_app->Create();

	while (running)
	{
		main_app->Update();
		main_app->Draw();
	}

	main_app->Destroy();

	delete main_app;
	main_app = nullptr;

	return 0;
}
