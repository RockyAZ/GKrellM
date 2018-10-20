#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP
#include <iostream>

class IMonitorModule
{
public:
	virtual void	parse_it(std::string) = 0;
	~IMonitorModule() { }
};

#endif