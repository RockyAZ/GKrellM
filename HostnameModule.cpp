#include "HostnameModule.hpp"

HostnameModule::HostnameModule(void)
{ }

HostnameModule::~HostnameModule(void)
{ }

HostnameModule::HostnameModule(HostnameModule const &src)
{
    *this = src;
}

HostnameModule const &HostnameModule::operator=(HostnameModule const &src)
{
    this->_hostname = src._hostname;
    return (*this);
}

void            HostnameModule::parse_it(std::string str)
{
    char buf[100];

    FILE *file = popen("whoami", "r");
    fgets(buf, 100, file);
    (void)str;
    this->_hostname = buf;
	pclose(file);
}

std::string     HostnameModule::getHostname(void) const
{
    return (this->_hostname);
}