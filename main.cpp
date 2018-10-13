// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 20:42:22 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 20:42:22 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// #include <ncurses.h>
// #include <ctime>
// #include <sys/ioctl.h>
// #include <iostream>

// int main()
// {
// 	initscr();
// 	noecho();
// 	curs_set(0);
// 	keypad(stdscr, true);
// 	cbreak();
// 	nodelay(stdscr, true);

// 	while (1)
// 	{
// 		start_color();
// 		init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
// 		attron(COLOR_PAIR(1));
// 			// for (int j = 0; j < w::height; j++)
// 					// mvaddch(j, w::width / 2, ')');
// 		mvaddch(5, 7, ACS_DIAMOND);
// 		attroff(COLOR_PAIR(3));
// 	}
// }


#include <ncurses.h>
#include "NcursesModul.hpp"

int main()
{
	initscr();

	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	// mvaddch(5, 7, ACS_CKBOARD);
	NcursesModul n(1, 1, 20, 20);
	n.setType("Omega lul");
	n.setMax(30);
	int jj = 0;
	// for (int i = 0; i < 100000; i++)
	int i = 0;
	while(1)
	{
		// erase();
		if (i % 13 == 0)
		n.render();
		jj++;
		n.setInfo(jj);
		if (jj > 25)
			jj = 0;
		refresh();
		i++;
	}
	getch();
	endwin();
	return 0;
}
