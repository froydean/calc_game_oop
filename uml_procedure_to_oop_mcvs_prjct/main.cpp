#include <iostream>

using namespace std;

class Player {
public:
	unsigned short game_; //1 - math, 2 - strings, 3 - sort
	void choose_game() {
		string input;
		cin >> input;
		if (input == "/math") {
			game_ = 1;
		}
		else if (input == "/strings") {
			game_ = 2;
		}
		else if (input == "/sort") {
			game_ = 3;
		}
	};
	string admit_game_start() {
		string input;
		cin >> input;
		return input;
	};
	void solve_task() {};
};


class GameManager {
public:
	unsigned short game_; //1 - math, 2 - strings, 3 - sort
	unsigned short level_;
	unsigned short score_;
	unsigned short attemts_left_;
	string hello_string_;
	string rules_;

	void write_start() {
		cout << "-----Hello, welcome to the Games! Choose your game!-----" << endl << endl;
		cout << "type \"/math\" or \"/strings\" or \"/sort\" for the choosen game and get ready!" << endl;
	}

	void start_game(Player * player) {

		if (player->game_ == 1) {
			hello_string_ = "-----Hello, welcome to the Math Solver!Try to finish this game and reach the TOP!-----";
			rules_ = "Rules are simple\n\tYou need solve given equations and type your answer";
		}
		else if (player->game_ == 2) {
			hello_string_ = "-----Hello, welcome to the String Solver!Try to finish this game and reach the TOP!-----";
			rules_ = "Rules are simple\n\tYou need to calculate how many times symbol appears in string and type your answer";
		}
		else if (player->game_ == 3) {
			hello_string_ = "-----Hello, welcome to the Sort Solver!Try to finish this game and reach the TOP!-----";
			rules_ = "Rules are simple\n\tYou need to sort given numbers and type your answer";
		}
		cout << hello_string_ << endl << endl;
		cout << rules_ << endl;
		cout << "\tWith each right answer you're becoming closer to the TOP!" << endl << endl << endl;
		cout << "If you ready, type \"/start\" for game start!\n" << endl;

		if (player->admit_game_start() == "/start") {
			//launch level
		}
	};
	
	bool is_game_over() {};
	bool is_level_passed() {};
};


int main() {
	setlocale(LC_ALL, "en");

	GameManager gameMgr;
	gameMgr.write_start();

	Player player; //player will be play math solver game
	player.choose_game();

	gameMgr.start_game(&player);
	
	return 0;
}