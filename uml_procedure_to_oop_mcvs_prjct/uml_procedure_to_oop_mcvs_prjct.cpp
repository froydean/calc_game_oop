// uml_procedure_to_oop_mcvs_prjct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//this file do not care about unexpected input
//no rand
//no limits 

#include <iostream>

using namespace std;

void game_start() {
	printf_s("-----Hello, welcome to the Game Solver!Try to finish this game and reach the TOP in math!-----\n\n");
	printf_s("Rules are simple:\n\tYou need solve given equations and type your answer\n");
	printf_s("\tWith each right answer you're becoming closer to the TOP!\n\n\n");
	printf_s("If you ready, type \"/start\" for game start!\n");
}

//true - passed, false - failed
bool first_level_passed() {
	unsigned char total_score = 0;
	unsigned int first_operand = 0, second_operand = 0;
	unsigned int input = 0;
	unsigned int tries_left = 10;

	printf_s("\n\n___First level___\n\n");
	printf_s("You are dumb for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
	
	while (tries_left && total_score < 5) {
		first_operand = rand() % 10 + 1;
		second_operand = rand() % 10 + 1;
		printf_s("%d + %d = ?\n", first_operand, second_operand);
		cin >> input;
		if (input == first_operand + second_operand) {
			total_score++;
			printf_s("Good!\n");
			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
		else {
			tries_left--;
			printf_s("You are dummy!\n");
			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
	}
	if (total_score == 5) {
		return true;
	}
	return false;
}

//true - passed, false - failed
bool second_level_passed() {
	unsigned char total_score = 0;
	unsigned int first_operand = 0, second_operand = 0;
	unsigned int input = 0;
	unsigned int tries_left = 10;

	printf_s("\n\n___Second level___\n\n");
	printf_s("You are average for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);

	while (tries_left && total_score < 5) {
		first_operand = rand() % 20 + 10;
		second_operand = rand() % 10 + 1;
		printf_s("%d - %d = ?\n", first_operand, second_operand);
		cin >> input;
		if (input == first_operand - second_operand) {
			total_score++;
			printf_s("Good!\n");
			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
		else {
			tries_left--;
			printf_s("You are dummy!\n");
			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
	}
	if (total_score == 5) {
		return true;
	}
	return false;
}

//true - passed, false - failed
bool third_level_passed() {
	unsigned char total_score = 0;
	unsigned int first_operand = 0, second_operand = 0;
	unsigned int input = 0;
	unsigned int tries_left = 10;

	printf_s("\n\n___Third level___\n\n");
	printf_s("You are PhD for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);

	while (tries_left && total_score < 5) {
		first_operand = rand() % 10 + 1;
		second_operand = rand() % 10 + 1;
		printf_s("%d * %d = ?\n", first_operand, second_operand);
		cin >> input;
		if (input == first_operand * second_operand) {
			total_score++;
			printf_s("Good!\n");
			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
		else {
			tries_left--;
			printf_s("You are dummy!\n");
			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
	}
	if (total_score == 5) {
		return true;
	}
	return false;
}

//true - passed, false - failed
bool fourth_level_passed() {
	unsigned char total_score = 0;
	unsigned int first_operand = 0, second_operand = 0;
	unsigned int input = 0;
	unsigned int tries_left = 10;

	printf_s("\n\n___Fourth level___\n\n");
	printf_s("You are genius for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);

	while (tries_left && total_score < 5) {
		first_operand = rand() % 1000 + 100;
		second_operand = rand() % 10 + 1;
		printf_s("%d / %d = ?(%d)\n", first_operand, second_operand, first_operand / second_operand); //(%d) - answer for debugging
		cin >> input;
		if (input == first_operand / second_operand) {
			total_score++;
			printf_s("Good!\n");
			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
		else {
			tries_left--;
			printf_s("You are dummy!\n");
			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
		}
	}
	if (total_score == 5) {
		return true;
	}
	return false;
}

int main()
{
	game_start();
	string input;
	cin >> input;

	if (input == "/start") {
		if (first_level_passed()) {
			printf_s("Congratulations! You passed level 1\n");
			if (second_level_passed()) {
				printf_s("Congratulations! You passed level 2\n");
				if (third_level_passed()) {
					printf_s("Congratulations! You passed level 3\n");
					if (fourth_level_passed()) {
						printf_s("Congratulations! You won the game. You are TOP in math!\n");
					}
					else {
						printf("Sorry but not really sorry, you failed. Game over!!!\n");
					}
				}
				else {
					printf("Sorry but not really sorry, you failed. Game over!!!\n");
				}
			}
			else {
				printf("Sorry but not really sorry, you failed. Game over!!!\n");
			}
		}
		else {
			printf("Sorry but not really sorry, you failed. Game over!!!\n");
		}
	}

	return 0;
}