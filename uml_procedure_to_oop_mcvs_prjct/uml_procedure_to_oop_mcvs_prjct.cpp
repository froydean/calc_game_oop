//// uml_procedure_to_oop_mcvs_prjct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////this file do not care about unexpected input
////no rand
////no limits 
//
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//void game_start() {
//	printf_s("-----Hello, welcome to the Games! Choose your game!-----\n\n");
//	printf_s("type \"/math\" or \"/strings\" or \"/sort\" for the choosen game and get ready!\n");
//}
//
//
////true - passed, false - failed
//bool first_level_passed() {
//	unsigned char total_score = 0;
//	unsigned int first_operand = 0, second_operand = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___First level___\n\n");
//	printf_s("You are dumb for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//	
//	while (tries_left && total_score < 5) {
//		first_operand = rand() % 10 + 1;
//		second_operand = rand() % 10 + 1;
//		printf_s("%d + %d = ?\n", first_operand, second_operand);
//		cin >> input;
//		if (input == first_operand + second_operand) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool second_level_passed() {
//	unsigned char total_score = 0;
//	unsigned int first_operand = 0, second_operand = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Second level___\n\n");
//	printf_s("You are average for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		first_operand = rand() % 20 + 10;
//		second_operand = rand() % 10 + 1;
//		printf_s("%d - %d = ?\n", first_operand, second_operand);
//		cin >> input;
//		if (input == first_operand - second_operand) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool third_level_passed() {
//	unsigned char total_score = 0;
//	unsigned int first_operand = 0, second_operand = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Third level___\n\n");
//	printf_s("You are PhD for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		first_operand = rand() % 10 + 1;
//		second_operand = rand() % 10 + 1;
//		printf_s("%d * %d = ?\n", first_operand, second_operand);
//		cin >> input;
//		if (input == first_operand * second_operand) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool fourth_level_passed() {
//	unsigned char total_score = 0;
//	unsigned int first_operand = 0, second_operand = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Fourth level___\n\n");
//	printf_s("You are genius for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		first_operand = rand() % 1000 + 100;
//		second_operand = rand() % 10 + 1;
//		printf_s("%d / %d = ?(%d)\n", first_operand, second_operand, first_operand / second_operand); //(%d) - answer for debugging
//		cin >> input;
//		if (input == first_operand / second_operand) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
//void game_math_start() {
//	printf_s("-----Hello, welcome to the Math Solver!Try to finish this game and reach the TOP in math!-----\n\n");
//	printf_s("Rules are simple:\n\tYou need solve given equations and type your answer\n");
//	printf_s("\tWith each right answer you're becoming closer to the TOP!\n\n\n");
//	printf_s("If you ready, type \"/start\" for game start!\n");
//
//	string input;
//	cin >> input;
//
//	if (input == "/start") {
//		if (first_level_passed()) {
//			printf_s("Congratulations! You passed level 1\n");
//			if (second_level_passed()) {
//				printf_s("Congratulations! You passed level 2\n");
//				if (third_level_passed()) {
//					printf_s("Congratulations! You passed level 3\n");
//					if (fourth_level_passed()) {
//						printf_s("Congratulations! You won the game. You are TOP in math!\n");
//					}
//					else {
//						printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//					}
//				}
//				else {
//					printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//				}
//			}
//			else {
//				printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//			}
//		}
//		else {
//			printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//		}
//	}
//}
//
//string generate_string(unsigned int len) {
//	string output;
//
//	for (int i = 0; i < len; i++) {
//		char tmp = rand() % 25 + 65;
//		output.append(&tmp, 1);
//	}
//
//	return output;
//}
//unsigned int times_founded(char sym, string str) {
//	unsigned int count = 0;
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == sym)
//			count++;
//	}
//	return count;
//}
//
////true - passed, false - failed
//bool first_level_passed_s() {
//	unsigned char total_score = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___First level___\n\n");
//	printf_s("You are dumb for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		string src_str = generate_string(10);
//		char sym_to_find = rand() % 25 + 65;
//		printf_s("How many %c in %s ?(%d)\n", sym_to_find, src_str.c_str(), times_founded(sym_to_find, src_str)); //(%d) - answer for debugging
//		cin >> input;
//		if (input == times_founded(sym_to_find, src_str)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool second_level_passed_s() {
//	unsigned char total_score = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Second level___\n\n");
//	printf_s("You are average for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		string src_str = generate_string(15);
//		char sym_to_find = rand() % 25 + 65;
//		printf_s("How many %c in %s ?(%d)\n", sym_to_find, src_str.c_str(), times_founded(sym_to_find, src_str)); //(%d) - answer for debugging
//		cin >> input;
//		if (input == times_founded(sym_to_find, src_str)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool third_level_passed_s() {
//	unsigned char total_score = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Third level___\n\n");
//	printf_s("You are PhD for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		string src_str = generate_string(20);
//		char sym_to_find = rand() % 25 + 65;
//		printf_s("How many %c in %s ?(%d)\n", sym_to_find, src_str.c_str(), times_founded(sym_to_find, src_str)); //(%d) - answer for debugging
//		cin >> input;
//		if (input == times_founded(sym_to_find, src_str)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool fourth_level_passed_s() {
//	unsigned char total_score = 0;
//	unsigned int input = 0;
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Fourth level___\n\n");
//	printf_s("You are genius for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		string src_str = generate_string(25);
//		char sym_to_find = rand() % 25 + 65;
//		printf_s("How many %c in %s ?(%d)\n", sym_to_find, src_str.c_str(), times_founded(sym_to_find, src_str)); //(%d) - answer for debugging
//		cin >> input;
//		if (input == times_founded(sym_to_find, src_str)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
//void game_string_start() {
//	printf_s("-----Hello, welcome to the String Solver!Try to finish this game and reach the TOP!-----\n\n");
//	printf_s("Rules are simple:\n\tYou need to calculate how many times symbol appears in string and type your answer\n");
//	printf_s("\tWith each right answer you're becoming closer to the TOP!\n\n\n");
//	printf_s("If you ready, type \"/start\" for game start!\n");
//
//	string input;
//	cin >> input;
//
//	if (input == "/start") {
//		if (first_level_passed_s()) {
//			printf_s("Congratulations! You passed level 1\n");
//			if (second_level_passed_s()) {
//				printf_s("Congratulations! You passed level 2\n");
//				if (third_level_passed_s()) {
//					printf_s("Congratulations! You passed level 3\n");
//					if (fourth_level_passed_s()) {
//						printf_s("Congratulations! You won the game. You are TOP!\n");
//					}
//					else {
//						printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//					}
//				}
//				else {
//					printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//				}
//			}
//			else {
//				printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//			}
//		}
//		else {
//			printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//		}
//	}
//}
//
//void fill_array(unsigned int* my_array, unsigned int len, unsigned int range) {
//	for (int i = 0; i < len; i++) {
//		my_array[i] = rand() % range + 1;
//	}
//}
//
//void show_array(unsigned int* my_array, unsigned int len) {
//	for (int i = 0; i < len; i++) {
//		printf_s("%d ", my_array[i]);
//	}
//	printf_s("\n");
//}
//
//int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
//{
//	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
//}
//	
////true - passed, false - failed
//bool input_right(unsigned int* my_array, unsigned int* input_array, unsigned int len) {
//	qsort(my_array, 10, sizeof(unsigned int), compare);
//	for (int i = 0; i < len; i++) {
//		if (input_array[i]!=my_array[i]) return false;
//	}
//	return true;
//}
//
////true - passed, false - failed
//bool first_level_passed_sort() {
//	unsigned char total_score = 0;
//	unsigned int my_array[10];
//	unsigned int input[10];
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___First level___\n\n");
//	printf_s("You are dumb for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		fill_array(my_array, 10, 5);
//		show_array(my_array, 10);
//		for (int i = 0; i < 10; i++) {
//			cin >> input[i];
//		}
//		if (input_right(my_array, input, 10)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are dumb for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
////true - passed, false - failed
//bool second_level_passed_sort() {
//	unsigned char total_score = 0;
//	unsigned int my_array[10];
//	unsigned int input[10];
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Second level___\n\n");
//	printf_s("You are average for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		fill_array(my_array, 10, 10);
//		show_array(my_array, 10);
//		for (int i = 0; i < 10; i++) {
//			cin >> input[i];
//		}
//		if (input_right(my_array, input, 10)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are average for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
////true - passed, false - failed
//bool third_level_passed_sort() {
//	unsigned char total_score = 0;
//	unsigned int my_array[10];
//	unsigned int input[10];
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Third level___\n\n");
//	printf_s("You are PhD for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		fill_array(my_array, 10, 15);
//		show_array(my_array, 10);
//		for (int i = 0; i < 10; i++) {
//			cin >> input[i];
//		}
//		if (input_right(my_array, input, 10)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are PhD for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
////true - passed, false - failed
//bool fourth_level_passed_sort() {
//	unsigned char total_score = 0;
//	unsigned int my_array[10];
//	unsigned int input[10];
//	unsigned int tries_left = 10;
//
//	printf_s("\n\n___Fourth level___\n\n");
//	printf_s("You are genius for now.\tYour current score: %d.\tTries left: %d\n", total_score, tries_left);
//
//	while (tries_left && total_score < 5) {
//		fill_array(my_array, 10, 20);
//		show_array(my_array, 10);
//		for (int i = 0; i < 10; i++) {
//			cin >> input[i];
//		}
//		if (input_right(my_array, input, 10)) {
//			total_score++;
//			printf_s("Good!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//		else {
//			tries_left--;
//			printf_s("You are dummy!\n");
//			printf_s("You are genius for now.\tYour current score: %d\tTries left: %d\n", total_score, tries_left);
//		}
//	}
//	if (total_score == 5) {
//		return true;
//	}
//	return false;
//}
//
//
//void game_sort_start() {
//	printf_s("-----Hello, welcome to the Sorting Solver!Try to finish this game and reach the TOP!-----\n\n");
//	printf_s("Rules are simple:\n\tYou need to sort given numbers and type your answer\n");
//	printf_s("\tWith each right answer you're becoming closer to the TOP!\n\n\n");
//	printf_s("If you ready, type \"/start\" for game start!\n");
//
//	string input;
//	cin >> input;
//
//	if (input == "/start") {
//		if (first_level_passed_sort()) {
//			printf_s("Congratulations! You passed level 1\n");
//			if (second_level_passed_sort()) {
//				printf_s("Congratulations! You passed level 2\n");
//				if (third_level_passed_sort()) {
//					printf_s("Congratulations! You passed level 3\n");
//					if (fourth_level_passed_sort()) {
//						printf_s("Congratulations! You won the game. You are TOP!\n");
//					}
//					else {
//						printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//					}
//				}
//				else {
//					printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//				}
//			}
//			else {
//				printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//			}
//		}
//		else {
//			printf_s("Sorry but not really sorry, you failed. Game over!!!\n");
//		}
//	}
//}
//
////int main()
////{
////	setlocale(LC_ALL, "en");
////	game_start();
////	
////	string input;
////	cin >> input;
////
////	if (input == "/math") {
////		game_math_start();
////	}
////	if (input == "/strings") {
////		game_string_start();
////	}
////	if (input == "/sort") {
////		game_sort_start();
////	}
////	else {
////		printf_s("Sorry, game wasn't choosen, game over!\n");
////	}
////
////	return 0;
////}