#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
using namespace std;

void createTitleDemo(string Title){
	int n = Title.length();
	for (int i = 1 ; i <= n + 2 ; i++) printw("=");
	string display = "\n " + Title + "\n";
	printw(display.c_str());
	for (int i = 1 ; i <= n + 2 ; i++) printw("=");
	printw("\n");
}

void printCurrentOption(string* line, int choice, int n){
	for (int i = 0 ; i < n ; i++){
		if (choice == i + 1){
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(1));
			printw(line[i].c_str());
			attroff(COLOR_PAIR(1));
		}
		else printw(line[i].c_str());
	}
}

void interfaceOption(string path, int &choice, string Title){
	// get number of line -> n
	ifstream in;
	in.open(path);
	string s;
	int n = 0;
	while (getline(in, s)){
		n++;
	}
	in.close();
	
	// get data of each line -> line[n]
	in.open(path);
	string* line = new string[n];
	int i = 0;
	while (i < n){
		getline(in, line[i]);
		line[i] += '\n';
		i++;
	}
	in.close();

	// set choice default is 1
	choice = 1;

	// create interface
	initscr();
	keypad(stdscr, TRUE); 
	noecho();

	while (true){
		clear();

		createTitleDemo(Title);
		printCurrentOption(line, choice, n);

		int key = getch();
		switch (key){
			case KEY_UP :
				if (choice == 1) choice = n;
				else choice--;
				break;

			case KEY_DOWN :
				if (choice == n) choice = 1;
				else choice++;
				break;

			case 10	: // enter key
				break;
		}
		if (key == 10) break;

		refresh();
	}
	endwin();

	// deallocate string line[n]
	delete[] line;
}