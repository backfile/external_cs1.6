#include <iostream>
#include "./utils/memory.h" 
#include "./utils/offset.h" 
#include <string>

#define F2 0x3C0000

using namespace std;

// Datos globles
char gameName[] = "hl.exe";
Memory* game;  // Puntero global si necesitas acceso desde otro lugar.
HWND ventana;
uintptr_t HL_BASE_ADDRESS;


// Features
void BunnyHop();
void MenuSpeedBunny();

int main() {
   
	game = new Memory(gameName);
	ventana = FindWindow(0, "Counter-Strike");
	HL_BASE_ADDRESS = game->GetModuleAddress(gameName);

	//MenuSpeedBunny();
	//BunnyHop();
	
    return 0;
}

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

	}
}

void MenuSpeedBunny() {
	float vel;
	int text_on = 1;
	int text_off = 0;
	string text = "Bunny creado por Frankiller UwU\n \\rVelocidad: ";
	string velo;
	string text_def;
	char textchar[256];

	while (1) {
		if (GetKeyState(VK_F3)) {
			game->Read<float>(HL_BASE_ADDRESS + FL_VELOCITY, vel);

			velo = to_string(vel);
			//Unir textos
			text_def = text + velo;
			strcpy_s(textchar, text_def.c_str());

			game->Write(HL_BASE_ADDRESS + FL_TEXT, textchar);
			game->Write(HL_BASE_ADDRESS + FL_TOGGLE_TEXT, text_on);
		}
		else {
			game->Write(HL_BASE_ADDRESS + FL_TOGGLE_TEXT, text_off);
		}
		Sleep(1);
	}

}
