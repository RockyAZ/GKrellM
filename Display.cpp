// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Display.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 21:15:45 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 21:15:45 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Display.hpp"

Display::Display()
{

}

Display::Display(Display const & src)
{
	*this = src;
}

Display::Display(int x, int y, int w, int h)
{
	this->_x = x;
	this->_y = y;
	this->_wMod = w;
	this->_hMod = y;
}

Display::~Display()
{

}

Display & Display::operator  = (Display const & src)
{
	this->_x = src._x;
	this->_y = src._y;
	return *this;
}

int Display::getX()
{
	return (this->_x);
}

int Display::getY()
{
	return (this->_y);
}

void Display::setX(int src)
{
	this->_x = src;
}

void Display::setY(int src)
{
	this->_y = src;
}

void Display::setMax(int src)
{
	this->_maxi = src;
}

void Display::setInfo(int src)
{
	this->_realInfo = src;
}

void Display::setType(std::string src)
{
	this->_type = src;
}



void Display::render()
{
	float koef = this->_maxi / MAXW;//can be replaced in class
	int len = this->_realInfo * koef;

	mvprintw(this->_y, this->_x, "%s :", this->_type.c_str());
	mvprintw(this->_y + 3, this->_x, "%d", len);
	mvprintw(this->_y + 4, this->_x, "%f", koef);
	mvprintw(this->_y + 5, this->_x, "%d", this->_realInfo);
	mvaddch(this->_y + 1, this->_x, '>');
	mvaddch(this->_y + 1, this->_x + this->_maxi, '<');
	for(int i = 0; i < len; i++)
		mvaddch(this->_y + 1, this->_x + i + 1, ACS_CKBOARD);
}
