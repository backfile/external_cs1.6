#pragma once

void ThirdPerson() {
	DWORD FL_THIRPERSON_ANGULO_address;

	float angulo = 0;
	int third_person_on = 1;
	int third_person_off = 0;

	//Angulo de la camara en tercera persona
	game->Read(HL_BASE_ADDRESS + FL_THIRDPERSON_ANGULO_ptr, FL_THIRPERSON_ANGULO_address);
	game->Write(FL_THIRPERSON_ANGULO_address + FL_THIRDPERSON_ANGULO_ptr_offset, angulo);

	while (1) {
		if (GetKeyState(VK_F4)) {
			//Activar Modo en tercera persona
			game->Write(HL_BASE_ADDRESS + FL_THIRDPERSON, third_person_on);
		}
		else {
			//Desactivar Modo en tercera persona
			game->Write(HL_BASE_ADDRESS + FL_THIRDPERSON, third_person_off);
		}
	}
}
