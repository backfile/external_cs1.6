#include <iostream>
#include "./utils/memory.h" 
#include "./utils/offset.h" 
#include <string>
#include <thread> // crear hilos
#define F2 0x3C0000

using namespace std;

// Datos globles
char gameName[] = "hl.exe";
Memory* game;  // Puntero global si necesitas acceso desde otro lugar.
HWND ventana;
uintptr_t HL_BASE_ADDRESS;

#include "./features/BunnyHop.h"
#include "./features/MenuSpeedBunny.h"

// Features

int main() {
   
	game = new Memory(gameName);
	ventana = FindWindow(0, "Counter-Strike");
	HL_BASE_ADDRESS = game->GetModuleAddress(gameName);

	// Features en distintos hilos de ejecución
	thread tBunnyHop(BunnyHop);
	thread tMenuSpeedBunny(MenuSpeedBunny);

	// Se podria separar la accion de saltar y la de leer en 2 hilos diferentes
	tBunnyHop.join();
	tMenuSpeedBunny.join();
	
    return 0;
}



