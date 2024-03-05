#include <windows.h>

LRESULT CALLBACK window_callback(HWND handleWindow, UINT systemMessage, WPARAM messageInfo, LPARAM additionalInfo) {
	return DefWindowProc(handleWindow, systemMessage, messageInfo, additionalInfo);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nShowCmd) {
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;

	// Register Class

	// Create Window
}