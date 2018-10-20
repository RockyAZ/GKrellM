#ifndef TIME_MODULE_HPP
# define TIME_MODULE_HPP
#include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule
{
private:
    std::string _time;
public:
    TimeModule();
    TimeModule(TimeModule const &);
    TimeModule const & operator=(TimeModule const &);
    virtual void parse_it(std::string);
    std::string getTime();
    ~TimeModule();
};

#endif