#ifndef HOSTNAME_MODULE_HPP
# define HOSTNAME_MODULE_HPP
#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule
{
private:
    std::string _hostname;
public:
    HostnameModule();
    HostnameModule(HostnameModule const &);
    HostnameModule const & operator=(HostnameModule const &);
    virtual void parse_it(std::string);
    std::string getHostname() const;
    ~HostnameModule();
};

#endif