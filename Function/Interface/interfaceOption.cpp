#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
using namespace std;

void createTitleDemo(string Title){
	ifstream fin;
	fin.open("Function/Interface/wing.txt");
	string s;
	int i=0;
	int l=Title.length();
	printw("\n");
	while (getline(fin,s)){
		i++;
		s = "    " + s;
		start_color();
		init_pair(7, COLOR_YELLOW, COLOR_BLACK);
		attron(COLOR_PAIR(7));
		if (i==3){
			string tmp = "";
			for (int j=0; j< 21 - (l/2); j++) tmp = tmp + s[j];
			for (int k=0; k<l; k++) tmp = tmp +Title[k];
			for (int j=21 -(l/2)+l; j<s.length(); j++) tmp = tmp + s[j];
			tmp = tmp + "\n";
			printw(tmp.c_str()); 
			continue;
		}
		printw(s.c_str());
		printw("\n");
		attroff(COLOR_PAIR(7));
	}
	printw("\n");
	fin.close();
	refresh();
	//endwin();
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

		if (Title != "") createTitleDemo(Title);
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
				endwin();
				return ;
		}
		refresh();
	}
	endwin();

	// deallocate string line[n]
	delete[] line;
}