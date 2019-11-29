#include "curses.h"

#include <iostream>
#include <ncurses.h>


bool Curses::Start()
{
    initscr();      // Initialise Curses
    noecho();       // Disable Output
    
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    
    return true;
}

bool Curses::Stop()
{
    echo();
    endwin(); 
    
    return true;
}

void Curses::Refresh()
{
    refresh();
}

int Curses::GetCh()
{
    refresh();
    return getch();
}
