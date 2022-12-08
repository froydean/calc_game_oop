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