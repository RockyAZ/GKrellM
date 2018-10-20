#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(void)
{ }

OSInfoModule::~OSInfoModule(void)
{ }

OSInfoModule::OSInfoModule(OSInfoModule const &src)
{
    *this = src;
}

OSInfoModule const &OSInfoModule::operator=(OSInfoModule const &src)
{
    this->_name = src._name;
    this->_version = src._version;
    return (*this);
}	

void            OSInfoModule::parse_it(std::string str)
{
    char buf[100];

    FILE *file = popen("sw_vers", "r");
    fgets(buf, 100, file);
    (void)str;
    this->_name = buf + 13;
	memset(buf, 100, 0);
	fgets(buf, 100, file);
    this->_version = buf + 16;
	pclose(file);
}

std::string     OSInfoModule::getName(void) const
{
    return (this->_name);
}

std::string     OSInfoModule::getVersion(void) const
{
    return (this->_version);
}