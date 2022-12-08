#pragma once
#include <iostream>
#include <map>
#include <string>
#define ARRAY_SIZE 10

using namespace std;

//not sure abt modificators
//Game is GodObject
//limits and incorrect input are not allowed
//construcors, destructors
//a lot of issues
//repeated code

class GameMenuStarter {
public:
	void write_menu_greetings();
};

class Player {

private:

	unsigned int answer_;
	unsigned int get_input_int();

public:

	string get_input_string();
	unsigned int get_answer();
	void solve_task();
	void choose_game();

};


class Task {

protected:

	unsigned int right_answer_;
	virtual void generate_task(unsigned int dif) = 0;
	virtual void calc_right_answer() = 0;

public:

	Task(unsigned int dif);
	unsigned int get_right_answer();
	virtual void show() = 0;
};


class MathTask : public Task {

private:

	unsigned int first_operand_, second_operand_;
	unsigned int range_start_, range_size_;
	void generate_task(unsigned int dif) override;
	void calc_right_answer() override;

public:

	MathTask(unsigned int dif) : Task(dif) {
		generate_task(dif); //wish to be common
		calc_right_answer();
	}
	void show() override;

};


class StringTask : public Task {

private:

	string string_;
	char sym_to_find_;
	unsigned int len_;
	void generate_task(unsigned int dif) override;
	void calc_right_answer() override;

public:

	StringTask(unsigned int dif) : Task(dif) {
		generate_task(dif);
		calc_right_answer();
	}
	void show() override;

};


class SortTask : public Task {

private:

	unsigned int my_array_[ARRAY_SIZE];
	unsigned int sorted_array_[ARRAY_SIZE];
	unsigned int range_;
	void generate_task(unsigned int dif) override;
	void calc_right_answer() override;

public:

	SortTask(unsigned int dif) : Task(dif) {
		generate_task(dif);
		calc_right_answer();
	}
	void show() override;

};


class Game {

protected:

	bool is_game_over_;
	string level_grades_[4]{ "dumb", "average", "PhD", "genius" }; //could make enum with operator++
	string level_list_[4]{ "First" , "Second", "Third", "Fourth" };
	unsigned int level_;
	unsigned int score_;
	unsigned int attempts_left_;
	Task* task_;
	virtual void write_greetings() = 0;
	virtual void create_task(unsigned int level, Task** task) = 0; //why can't be Task *
	void write_game_over();
	void write_game_win();
	bool is_game_over();
	bool is_level_passed();
	void write_endgame();
	void write_state();

public:

	Game();
	void launch_level(Player* player);
	void launch_game(Player* player);

};


class GameMath : public Game {

public:

	GameMath() : Game() {};
	void write_greetings() override;
	void create_task(unsigned int level, Task** task) override;

};


class GameString : public Game {

public:

	GameString() : Game() {};
	void write_greetings() override;
	void create_task(unsigned int level, Task** task) override;

};


class GameSort : public Game {

public:

	GameSort() : Game() {};
	void write_greetings() override;
	void create_task(unsigned int level, Task** task) override;

};