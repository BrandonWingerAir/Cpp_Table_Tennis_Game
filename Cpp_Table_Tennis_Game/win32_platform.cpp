#include <windows.h>

bool gameRunning = true;

LRESULT CALLBACK window_callback(HWND handleWindow, UINT systemMessage, WPARAM messageInfo, LPARAM additionalInfo) {
	LRESULT result = 0;

	switch (systemMessage) {
		case WM_CLOSE:
		case WM_DESTROY: {
			gameRunning = false;
		} break;

		default: {
			result = DefWindowProc(handleWindow, systemMessage, messageInfo, additionalInfo);
		}
	}

	return result;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nShowCmd) {
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;

	// Register Class
	RegisterClass(&window_class);

	// Create Window
	HWND window = CreateWindow(
		window_class.lpszClassName, 
		"Table Tennis", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		1280, 
		720, 
		0, 
		0, 
		hInstance, 
		0
	);

	while (gameRunning) {
		// Input
		MSG message;

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// Simulate

		// Render
	}
}