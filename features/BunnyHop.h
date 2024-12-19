#pragma once
void BunnyHop() {
	int ground;
	while (1) {
		game->Read<int>(HL_BASE_ADDRESS + FL_ONGROUND, ground);

		if (GetKeyState(VK_SPACE) & 0x8000) {
			if (ground == 1) {
				SendMessage(ventana, WM_KEYDOWN, F2, F2);
				Sleep(1);
				SendMessage(ventana, WM_KEYUP, F2, F2);
			}
		}
		Sleep(1);
	}
}