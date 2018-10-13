// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 20:34:13 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 20:34:14 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <iostream>
#include <ncurses.h>

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(){}


	virtual void	render() = 0;
private:
	// IMonitorDisplay();
	// IMonitorDisplay(IMonitorDisplay const & src);
	// IMonitorDisplay & operator = (IMonitorDisplay const & src);
};

#endif