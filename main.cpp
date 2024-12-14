#include <iostream>
#include "./utils/memory.h" 
#include "./utils/offset.h" 

#define F2 0x3C0000

using namespace std;

// Datos globles
char gameName[] = "hl.exe";
Memory* game;  // Puntero global si necesitas acceso desde otro lugar.
HWND ventana;
uintptr_t HL_BASE_ADDRESS;
int ground;


// Features
void BunnyHop();

int main() {
   
	game = new Memory(gameName);
	ventana = FindWindow(0, "Counter-Strike");
	HL_BASE_ADDRESS = game->GetModuleAddress(gameName);

	BunnyHop();
	
    return 0;
}

void BunnyHop() {
	while (1) {
		game->Read<int>(HL_BASE_ADDRESS + FL_ONGROUND, ground);

		cout << ground;
		if (GetKeyState(VK_SPACE) & 0x8000) {
			if (ground == 1) {
				SendMessage(ventana, WM_KEYDOWN, F2, F2);
				Sleep(1);
				SendMessage(ventana, WM_KEYUP, F2, F2);
			}
		}

	}
}
