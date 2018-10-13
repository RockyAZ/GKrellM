// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesModul.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 21:10:52 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 21:10:52 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NcursesModul.hpp"

NcursesModul::NcursesModul()
{

}

NcursesModul::NcursesModul(NcursesModul const & src)
{

}

NcursesModul::NcursesModul(int x, int y, int w, int h) : Display(x, y, w, h)
{

}

NcursesModul::~NcursesModul()
{

}

// void NcursesModul::render()
// {
// 	// int varX = this->_x;
// 	float koef = this->_maxi / MAXW;//can be replaced in class
// 	int len = this->_realInfo * koef;
// 	mvprintw(this->_y, this->_x, "%s :", this->_type.c_str());
// 	mvaddch(this->_y + 1, this->_x, '>');

// 	for(int i = 0; i < len; i++)
// 		mvaddch(this->_y + 1, this->_x + i, ACS_CKBOARD);
		
// }


// NcursesModul & NcursesModul::operator = (NcursesModul const & src)
// {

// }

