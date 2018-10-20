#include "TimeModule.hpp"

TimeModule::TimeModule(void)
{ }

TimeModule::~TimeModule(void)
{ }

TimeModule::TimeModule(TimeModule const &src)
{
    *this = src;
}

TimeModule const &TimeModule::operator=(TimeModule const &src)
{
    this->_time = src._time;
    return (*this);
}

void            TimeModule::parse_it(std::string str)
{
	this->_time = str.substr(str.find("threads") + 9, str.find("Load Avg") - str.find("threads") - 13);
}

std::string     TimeModule::getTime(void)
{
    return (this->_time);
}