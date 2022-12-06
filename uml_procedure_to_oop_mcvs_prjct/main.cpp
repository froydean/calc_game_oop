#include "classes_def.h"

using namespace std;

class Player {

private:
	
	unsigned int answer_;

public:
	
	string get_input() { //smell
		string input;
		cin >> input;
		return input;
	}

	unsigned int get_answer() {
		return answer_;
	}

	void solve_task() { //add args Task i think
		answer_ = atoi(get_input().c_str());
	}

};

class Task {

private:

	unsigned int first_operand_, second_operand_;
	unsigned int range_start_, range_size_;
	unsigned int right_answer_;

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

public:

	Task(unsigned int dif) {
		generate_task(dif);
		calc_right_answer();
	}

	void show() {
		cout << first_operand_ << " + " << second_operand_ << " = ?" << endl;
	}

	unsigned int get_right_answer() {
		return right_answer_;
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

	Task give_task() {
			Task task(grade_);
			task.show();
			return task;
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
			Task task = give_task();
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

	void write_greetings() {
		cout << "-----Hello, welcome to the Math Solver!Try to finish this game and reach the TOP!-----" << endl;
		cout << "Rules are simple\n\tYou need solve given equations and type your answer" << endl;
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

	void launch_game(Player* player) {
		write_greetings();
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
	gameMgr.launch_game(&player);
	
	return 0;
}