// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesModul.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 21:11:01 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 21:11:01 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSESMODUL_HPP
#define NCURSESMODUL_HPP

#include <ncurses.h>
#include "Display.hpp"

class NcursesModul : public Display
{
public:
	NcursesModul();
	NcursesModul(NcursesModul const & src);

//x, y - position of left upper angle
	NcursesModul(int x, int y, int w, int h);

	~NcursesModul();
	// void render();

// private:
	// NcursesModul & operator = (NcursesModul const & src);
};

#endif
