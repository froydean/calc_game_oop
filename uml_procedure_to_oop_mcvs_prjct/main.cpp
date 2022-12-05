#include "classes_def.h"

using namespace std;

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

class Player {

private:

	unsigned int game_; //1 - math, 2 - strings, 3 - sort

public:

	unsigned int get_game() {
		return game_;
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
	};

	string get_input() {
		string input;
		cin >> input;
		return input;
	}

	string solve_task() {
		return get_input();
	};
};

class Task {

protected:

	unsigned int right_answer_;

public:

	void generate_task() {
	}

	void calc_right_answer() {
	}

	void show() {
	}

	unsigned int get_right_answer() {
		return right_answer_;
	}
};

class MathTask : public Task {

private:
	unsigned int first_operand_, second_operand_;
	unsigned int range_start_, range_size_;

public:

	MathTask() {
		first_operand_ = 0;
		second_operand_ = 0;
		range_start_ = 0;
		range_size_ = 0;

	}

	void generate_task(unsigned int dif) {
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

	void calc_right_answer() {
		right_answer_ = first_operand_ + second_operand_;
	}

	void show() {
		cout << first_operand_ << " + " << second_operand_ << " = ?" << endl;
	}
	
};


class StringTask : public Task {

private:
	string string_;
	char sym_to_find_;
	unsigned int len_;

public:

	void generate_task(unsigned int dif) {
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

	void calc_right_answer() {
		unsigned int count = 0;
		for (int i = 0; i < string_.length(); i++) {
			if (string_[i] == sym_to_find_)
				count++;
		}
		right_answer_ = count;
	}

	void show() {
		cout << "How many " << sym_to_find_ << " in " << string_ << " ? " << endl;
	}
};

class SortTask : public Task {

private:

	unsigned int my_array_[10];
	unsigned int input_[10];
	unsigned int range_;

public:

	void show(unsigned int len) {
		cout << "Sort this: ";
		for (int i = 0; i < len; i++) {
			cout << my_array_[i] << " ";
		}
		cout << endl;
	}

	void generate_task(unsigned int dif) {
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
		for (int i = 0; i < 10; i++) {
			my_array_[i] = rand() % range_;
		}
	}

	void calc_right_answer() {
		qsort(my_array_, 10, sizeof(unsigned int), compare);
		char tmp[11];
		for (int i = 0; i < 10; i++) {
			tmp[i] = char(my_array_[i]) + 48;
		}
		right_answer_ = atoi(tmp);
	}
};

class Level {

private:

	unsigned int score_;
	unsigned int attemts_left_;
	string grade_string_;
	unsigned int grade_;

	bool is_answer_right(string player_answer, Task task) {
		return atoi(player_answer.c_str()) == task.get_right_answer();
	}

	Task give_task(unsigned int game) {
		if (game == 1) {
			MathTask task;
			task.generate_task(grade_);
			task.calc_right_answer();
			task.show();
			return task;
		}
		if (game == 2) {
			StringTask task2;
			task2.generate_task(grade_);
			task2.calc_right_answer();
			task2.show();
			return task2;
		}
		if (game == 3) {
			SortTask task3;
			task3.generate_task(grade_);
			task3.show(10);
			task3.calc_right_answer();
			return task3;
		}

	}

public:

	Level(unsigned int level_num) {
		attemts_left_ = 10;
		score_ = 0;
		grade_ = level_num;
		switch (level_num) {
		case 1:
			grade_string_ = "dumb";
			break;
		case 2:
			grade_string_ = "average";
			break;
		case 3:
			grade_string_ = "PhD";
			break;
		case 4:
			grade_string_ = "genius";
			break;
		}
	}

	void write_greetings() {
		cout << endl << endl << "___First level___" << endl << endl;
		write_state();
	}

	void write_state() {
		cout << "You are " << grade_string_ << " for now.\tYour current score: " << score_ << ".\tTries left : " << attemts_left_ << endl;
	}

	bool is_level_passed() {
		if (score_ == 5 && attemts_left_ > 0) return true;
		else return false;
	}

	void launch_level(Player* player) {
		while (attemts_left_ && score_ < 5) {
			if (is_answer_right(player->solve_task(), give_task(player->get_game()))) {
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

public:

	GameManager() {
		level_ = 1;
		is_game_over_ = false;
	}

	bool is_game_over() {
		return is_game_over_;
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

	void write_endgame() {
		if (is_game_over()) {
			write_game_over();
		}
		else {
			write_game_win();
		}
	}

};

int main() {
	setlocale(LC_ALL, "en");

	GameManager gameMgr;
	gameMgr.game_start();

	Player player; //player will be play math solver game
	player.choose_game();

	gameMgr.launch_game(&player);
	
	return 0;
}