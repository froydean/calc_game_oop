#include "classes_def.h"
#define ARRAY_SIZE 10

using namespace std;

int compare(const void* x1, const void* x2){
	return (*(int*)x1 - *(int*)x2);              //0 equal, <0: x1<x2; >0: x1>x2
}

class Player {

private:
	
	unsigned int answer_;
	unsigned game_;

public:
	
	string get_input() { //smell
		string input;
		cin >> input;
		return input;
	}

	unsigned int get_answer() {
		return answer_;
	}

	unsigned int get_game() {
		return game_;
	}
	
	void solve_task() {
		answer_ = atoi(get_input().c_str());
	}

	void choose_game() {
		string input = get_input();
		if (input == "/math") {
			game_ = 1;
		}
		else if (input == "/strings") {
			game_ = 2;
		}
		else if (input == "/sort") {
			game_ = 3;
		}
	}

};


class Task {

protected:

	unsigned int right_answer_;
	virtual void generate_task(unsigned int dif) {}; // = 0?
	virtual void calc_right_answer() {};

public:

	Task(unsigned int dif) {
		right_answer_ = 0; //why cannot be common for all tasks
	}

	unsigned int get_right_answer() {
		return right_answer_;
	}

	virtual void show() {}
};

class MathTask : public Task {

private:

	unsigned int first_operand_, second_operand_;
	unsigned int range_start_, range_size_;

	void generate_task(unsigned int dif) override {
		switch (dif) {
		case 1:
			range_start_ = 1;
			range_size_ = 10;
			break;
		case 2:
			range_start_ = 10;
			range_size_ = 20;
			break;
		case 3:
			range_start_ = 20;
			range_size_ = 100;
			break;
		case 4:
			range_start_ = 100;
			range_size_ = 1000;
			break;
		}
		first_operand_ = rand() % range_size_ + range_start_;
		second_operand_ = rand() % 10 + 1;
	}

	void calc_right_answer() override {
		right_answer_ = first_operand_ + second_operand_;
	}

public:

	MathTask(unsigned int dif) : Task(dif) {
		generate_task(dif);
		calc_right_answer();
	}

	void show() override {
		cout << first_operand_ << " + " << second_operand_ << " = ?" << endl;
	}
	
};

class StringTask : public Task {

private:

	string string_;
	char sym_to_find_;
	unsigned int len_;

	void generate_task(unsigned int dif) override {
		switch (dif) {
		case 1:
			len_ = 5;
			break;
		case 2:
			len_ = 10;
			break;
		case 3:
			len_ = 15;
			break;
		case 4:
			len_ = 20;
			break;
		}
		for (int i = 0; i < len_; i++) {
			char tmp = rand() % 25 + 65;
			string_.append(&tmp, 1);
		}
		sym_to_find_ = rand() % 25 + 65;
	}

	void calc_right_answer() override {
		unsigned int count = 0;
		for (int i = 0; i < string_.length(); i++) {
			if (string_[i] == sym_to_find_)
				count++;
		}
		right_answer_ = count;
	}

public:

	StringTask(unsigned int dif) : Task(dif) {
		generate_task(dif);
		calc_right_answer();
	}

	void show() override {
		cout << "How many " << sym_to_find_ << " in " << string_ << " ? " << endl;
	}

};

class SortTask : public Task {

private:

	unsigned int my_array_[ARRAY_SIZE];
	unsigned int sorted_array_[ARRAY_SIZE];
	unsigned int range_;

	void generate_task(unsigned int dif) override {
		switch (dif) {
		case 1:
			range_ = 5;
			break;
		case 2:
			range_ = 7;
			break;
		case 3:
			range_ = 8;
			break;
		case 4:
			range_ = 9;
			break;
		}
		for (int i = 0; i < ARRAY_SIZE; i++) {
			my_array_[i] = rand() % range_;
			sorted_array_[i] = my_array_[i]; //just copy, not sorted yet
		}
	}

	void calc_right_answer() override {
		qsort(sorted_array_, ARRAY_SIZE, sizeof(unsigned int), compare);
		char tmp[11] = { 0 };
		for (int i = 0; i < ARRAY_SIZE; i++) {
			tmp[i] = char(sorted_array_[i]) + 48;
		}
		right_answer_ = atoi(tmp);
	}

public:

	SortTask(unsigned int dif) : Task(dif) {
		generate_task(dif);
		calc_right_answer();
	}

	void show() override {
		cout << "Sort this: ";
		for (int i = 0; i < ARRAY_SIZE; i++) {
			cout << my_array_[i] << " ";
		}
		cout << endl;
	}

};

class Level {//shitty class

private:

	unsigned int score_;
	unsigned int attemts_left_;
	string grade_string_;
	unsigned int grade_;

	bool is_answer_right(unsigned int player_answer, Task task) {
		return player_answer == task.get_right_answer();
	}

	void write_state() {
		cout << "You are " << grade_string_ << " for now.\tYour current score: " << score_ << ".\tTries left : " << attemts_left_ << endl;
	}

	Task give_task(unsigned int game) {
		if (game == 1) {
			MathTask task(grade_);
			task.show();
			return task;
		}
		if (game == 2) {
			StringTask task(grade_);
			task.show();
			return task;
		}
		if (game == 3) {
			SortTask task(grade_);
			task.show();
			return task;
		}
	}

public:

	Level(unsigned int level_num) {

		attemts_left_ = 10;
		score_ = 0;
		grade_ = level_num;

		cout << endl << endl << "___";

		switch (level_num) {
		case 1:
			grade_string_ = "dumb";
			cout << "First";
			break;
		case 2:
			grade_string_ = "average";
			cout << "Second";
			break;
		case 3:
			grade_string_ = "PhD";
			cout << "Third";
			break;
		case 4:
			grade_string_ = "genius";
			cout << "Fourth";
			break;
		}

		cout << " level___" << endl << endl;
		write_state();
	}

	bool is_level_passed() {
		if (score_ == 5 && attemts_left_) return true;
		return false;
	}

	void launch_level(Player* player) {
		while (attemts_left_ && score_ < 5) {
			Task task = give_task(player->get_game());
			player->solve_task();
			if (is_answer_right(player->get_answer(), task)) {
				score_++;
				cout << "Good!" << endl;
				write_state();
			}
			else {
				attemts_left_--;
				printf_s("You are dummy!\n");
				write_state();
			}
		}
	}

};


class GameManager {

private:

	unsigned int level_;
	bool is_game_over_;

	void write_greetings(unsigned int game) {
		switch (game) {
		case 1:
			cout << "-----Hello, welcome to the Math Solver!Try to finish this game and reach the TOP!-----" << endl;
			cout << "Rules are simple\n\tYou need solve given equations and type your answer" << endl;
			break;
		case 2:
			cout << "-----Hello, welcome to the String Solver!Try to finish this game and reach the TOP!-----" << endl;
			cout << "Rules are simple\n\tYou need to calculate how many times symbol appears in string and type your answer" << endl;
			break;
		case 3:
			cout << "-----Hello, welcome to the Sort Solver!Try to finish this game and reach the TOP!-----" << endl;
			cout << "Rules are simple\n\tYou need to sort given numbers and type your answer" << endl;
			break;
		}
		cout << "\tWith each right answer you're becoming closer to the TOP!" << endl << endl << endl;
		cout << "If you ready, type \"/start\" for game start!" << endl;
	}

	void write_game_over() {
		cout << "Sorry but not really sorry, you failed. Game over!!!" << endl;
	}

	void write_game_win() {
		cout << "Congratulations! You won the game. You are TOP!" << endl;
	}

	bool is_game_over() {
		return is_game_over_;
	}

	void write_endgame() {
		if (is_game_over()) {
			write_game_over();
		}
		else {
			write_game_win();
		}
	}

public:

	GameManager() {
		level_ = 1;
		is_game_over_ = false;
	}

	void game_start() {
		printf_s("-----Hello, welcome to the Games! Choose your game!-----\n\n");
		printf_s("type \"/math\" or \"/strings\" or \"/sort\" for the choosen game and get ready!\n");
	}

	void launch_game(Player* player) {
		write_greetings(player->get_game());
		if (player->get_input() != "/start") return;
		do {
			Level level(level_);
			level.launch_level(player);
			is_game_over_ = !level.is_level_passed();
			level_++;
		} while (!is_game_over_ && level_ < 5);
		write_endgame();
	}

};

int main() {

	setlocale(LC_ALL, "en");

	GameManager gameMgr;
	Player player;
	gameMgr.game_start();
	player.choose_game();
	gameMgr.launch_game(&player);

	
	return 0;
}