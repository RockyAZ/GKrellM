#include <iostream>
#include "CPUModule.hpp"
#include "DataStorageModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "OSInfoModule.hpp"
#include "RAMModule.hpp"
#include "TimeModule.hpp"

#include "NcursesModul.hpp"

int main()
{
	CPUModule	 		cpu;
	DataStorageModule   dsm;
	HostnameModule      hnm;
	NetworkModule       nm;
	OSInfoModule		OSim;
	RAMModule			ram;
	TimeModule			tm;

	NcursesModul ncurses;

	initscr();
	nodelay(stdscr, true);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	noecho();
	curs_set(0);
	char key;
	while (1)
	{
try
{
		erase();
		ncurses.render();
	key = getch();
	switch(key)
	{
		case '1':
			ncurses.cpuDraw = ! ncurses.cpuDraw;
			break ;
		case '2':
			ncurses.dsmDraw = ! ncurses.dsmDraw;
			break ;
		case '3':
			ncurses.hnmDraw = ! ncurses.hnmDraw;
			break ;
		case '4':
			ncurses.nmDraw = ! ncurses.nmDraw;
			break ;
		case '5':
			ncurses.OSimDraw = ! ncurses.OSimDraw;
			break ;
		case '6':
			ncurses.ramDraw = ! ncurses.ramDraw;
			break ;
		case '7':
			ncurses.tmDraw = ! ncurses.tmDraw;
			break ;
		case '8':
			ncurses.catDraw = ! ncurses.catDraw;
			break ;
		case 27:
			endwin();
			exit(0);
		}
		refresh();
}
catch(std::exception &e)
{
	std::cout << "DEB DEB DEB" << std::endl;
}
	}
	endwin();
	return (0);
}
