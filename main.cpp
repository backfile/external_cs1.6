#include <Windows.h>
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


// Features
#include "./features/BunnyHop.h"
#include "./features/MenuSpeedBunny.h"
#include "./features/ThirdPerson.h"


int main() {
   
	game = new Memory(gameName);
	ventana = FindWindow(0, "Counter-Strike");
	HL_BASE_ADDRESS = game->GetModuleAddress(gameName);

	// Features en distintos hilos de ejecución
	
	thread tBunnyHop(BunnyHop);
	thread tMenuSpeedBunny(MenuSpeedBunny);
	thread tThirdPerson(ThirdPerson);

	tBunnyHop.join();
	tMenuSpeedBunny.join();
	tThirdPerson.join();

    return 0;
}



