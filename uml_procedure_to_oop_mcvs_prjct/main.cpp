#include "classes_decl.h"

int main() {

	setlocale(LC_ALL, "en");

	GameMenuStarter menu;
	menu.write_menu_greetings();

	Player player;
	player.choose_game();

	return 0;
}