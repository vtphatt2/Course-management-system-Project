#include "interface.h"
//#include <curses.h>
#include <ncurses.h>
#include <fstream>
void setColor()
{
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
}

void inputArt(string s[]){
    ifstream fin;
    fin.open("Function/Interface/welcome.txt");
    int i=0;
    for (int i=0; i<25; i++) getline(fin,s[i],'\n');
    fin.close();
}

void drawLogin(){
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    setColor();
    string pic[25];
    inputArt(pic);
    int l;
    for (int i=0; i<25; i++){
        if (i<18){
            attron(COLOR_PAIR(1));
            l=pic[i].length();
            for (int j=0; j<l; j++) mvprintw(i, j+30, "%c", pic[i][j]);
            attroff(COLOR_PAIR(1));
        }
        if (i>17){
            attron(COLOR_PAIR(2));
            l=pic[i].length();
            for (int j=0; j<l; j++) mvprintw(i, j+5, "%c", pic[i][j]);
            attroff(COLOR_PAIR(2));
        }
    }
    refresh();
    endwin();
}