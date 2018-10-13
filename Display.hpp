// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Display.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 21:15:48 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 21:15:49 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#define MAXW 20				//- max char in single col
class Display : public IMonitorDisplay
{
protected:
	int _x;
	int _y;
	int _wMod;
	int _hMod;
	int _wScreen;
	int _hScreen;
	int _maxi;//max posible value of this type
	std::string _type;//what kind of info?
	int _realInfo;//real info (to drawing)

public:
	Display();
	Display(Display const & src);
	Display(int x, int y, int w, int h);
	virtual ~Display();

	Display & operator  = (Display const & src);

	virtual int getX();
	virtual int getY();

	virtual void setX(int src);
	virtual void setY(int src);
	virtual void setMax(int src);
	virtual void setInfo(int src);
	virtual void setType(std::string src);

	virtual void render();

};

#endif