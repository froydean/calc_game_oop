#include "classes_decl.h"

int compare(const void* x1, const void* x2) {
	return (*(int*)x1 - *(int*)x2);              //0 equal, <0: x1<x2; >0: x1>x2
}

void GameMenuStarter::write_menu_greetings() {
	cout << "-----Hello, welcome to the Games! Choose your game!-----" << endl;
	cout << "type \"/math\" or \"/strings\" or \"/sort\" for the choosen game and get ready!" << endl;
}

Task::Task(unsigned int dif) {
	right_answer_ = 0; //why cannot be common for all tasks
}

unsigned int Task::get_right_answer() {
	return right_answer_;
}

void MathTask::generate_task(unsigned int dif) {
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

void MathTask::calc_right_answer() {
	right_answer_ = first_operand_ + second_operand_;
}

void MathTask::show() {
	cout << first_operand_ << " + " << second_operand_ << " = ?" << endl;
}

void StringTask::generate_task(unsigned int dif) {
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
	for (unsigned int i = 0; i < len_; i++) {
		char tmp = rand() % 25 + 65;
		string_.append(&tmp, 1);
	}
	sym_to_find_ = rand() % 25 + 65;
}

void StringTask::calc_right_answer() {
	unsigned int count = 0;
	for (int i = 0; i < string_.length(); i++) {
		if (string_[i] == sym_to_find_)
			count++;
	}
	right_answer_ = count;
}

void StringTask::show() {
	cout << "How many " << sym_to_find_ << " in " << string_ << " ? " << endl;
}

void SortTask::generate_task(unsigned int dif) {
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

void SortTask::calc_right_answer() {
	qsort(sorted_array_, ARRAY_SIZE, sizeof(unsigned int), compare);
	char tmp[11] = { 0 };
	for (int i = 0; i < ARRAY_SIZE; i++) {
		tmp[i] = char(sorted_array_[i]) + 48;
	}
	right_answer_ = atoi(tmp);
}

void SortTask::show() {
	cout << "Sort this: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << my_array_[i] << " ";
	}
	cout << endl;
}

void Game::write_game_over() {
	cout << "Sorry but not really sorry, you failed. Game over!!!" << endl;
}

void Game::write_game_win() {
	cout << "Congratulations! You won the game. You are TOP!" << endl;
}

bool Game::is_game_over() {
	return !(is_level_passed() && level_ == 5);
}

bool Game::is_level_passed() { //need?
	if (score_ == 5 && attempts_left_) return true;
	return false;
}

void Game::write_endgame() {
	if (is_game_over()) {
		write_game_over();
	}
	else {
		write_game_win();
	}
}

void Game::write_state() {
	cout << "You are " << level_grades_[level_ - 1] << " for now.\tYour current score: " << score_ << ".\tTries left : " << attempts_left_ << endl;
}

Game::Game() {
	is_game_over_ = false;
	level_ = 1;
	score_ = 0;
	attempts_left_ = 10;
}

void Game::launch_level(Player* player) {
	do {
		create_task(level_, &task_);
		task_->show();
		player->solve_task();
		if (task_->get_right_answer() == player->get_answer()) {
			score_++;
			cout << "Good!" << endl;
			write_state();
		}
		else {
			attempts_left_--;
			cout << "You are dummy!" << endl;
			write_state();
		}
		delete task_;
	} while (score_ < 5 && attempts_left_);
}

void Game::launch_game(Player* player) {
	write_greetings();
	if (player->get_input_string() != "/start") return;
	do {
		attempts_left_ = 10;
		score_ = 0;
		cout << endl << endl << "___" << level_list_[level_ - 1] << " level___" << endl << endl;
		write_state();
		launch_level(player);
		level_++;
	} while (is_level_passed() && level_ < 5);
	write_endgame();
}

void GameMath::write_greetings() {
	cout << "-----Hello, welcome to the Math Solver!Try to finish this game and reach the TOP!-----" << endl;
	cout << "Rules are simple\n\tYou need solve given equations and type your answer" << endl;
	cout << "\tWith each right answer you're becoming closer to the TOP!" << endl << endl << endl;
	cout << "If you ready, type \"/start\" for game start!" << endl;
}

void GameMath::create_task(unsigned int level, Task** task) {
	*task = new MathTask(level);
}

void GameString::write_greetings() {
	cout << "-----Hello, welcome to the String Solver!Try to finish this game and reach the TOP!-----" << endl;
	cout << "Rules are simple\n\tYou need to calculate how many times symbol appears in string and type your answer" << endl;
	cout << "\tWith each right answer you're becoming closer to the TOP!" << endl << endl << endl;
	cout << "If you ready, type \"/start\" for game start!" << endl;
}

void GameString::create_task(unsigned int level, Task** task) {
	*task = new StringTask(level);
}

void GameSort::write_greetings() {
	cout << "-----Hello, welcome to the Sort Solver!Try to finish this game and reach the TOP!-----" << endl;
	cout << "Rules are simple\n\tYou need to sort given numbers and type your answer" << endl;
	cout << "\tWith each right answer you're becoming closer to the TOP!" << endl << endl << endl;
	cout << "If you ready, type \"/start\" for game start!" << endl;
}

void GameSort::create_task(unsigned int level, Task** task) {
	*task = new SortTask(level);
}

unsigned int Player::get_input_int() {
	unsigned int input;
	cin >> input;
	return input;
}

string Player::get_input_string() {
	string input;
	cin >> input;
	return input;
}
unsigned int Player::get_answer() {
	return answer_;
}

void Player::solve_task() {
	answer_ = get_input_int();
}

void Player::choose_game() {
	string input = get_input_string();
	if (input == "/math") {
		Game* game_;
		game_ = new GameMath;
		game_->launch_game(this);
		delete game_;
	}
	else if (input == "/strings") {
		Game* game_;
		game_ = new GameString;
		game_->launch_game(this);
		delete game_;
	}
	else if (input == "/sort") {
		Game* game_;
		game_ = new GameSort;
		game_->launch_game(this);
		delete game_;
	}
}