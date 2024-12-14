#pragma once
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
