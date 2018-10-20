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

NcursesModul::NcursesModul() : Display()
{

}

NcursesModul::NcursesModul(NcursesModul const & src)
{
	*this = src;
}

NcursesModul::NcursesModul(int x, int y) : Display(x, y)
{

}

NcursesModul::~NcursesModul()
{

}

NcursesModul & NcursesModul::operator = (NcursesModul const & src)
{
	this->_x = src._x;
	this->_y = src._y;
	return *this;
}