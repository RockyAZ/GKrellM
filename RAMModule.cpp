#include "RAMModule.hpp"

RAMModule::RAMModule(void)
{ }

RAMModule::~RAMModule(void)
{ }

RAMModule::RAMModule(RAMModule const &src)
{
    *this = src;
}

RAMModule const &RAMModule::operator=(RAMModule const &src)
{
    this->_used = src._used;
    this->_wired = src._wired;
    this->_unused = src._unused;
    return (*this);
}

void        RAMModule::parse_it(std::string str)
{
    size_t start = str.find("PhysMem: ");
    size_t pos;
    this->_used = stoi(str.substr(start + 9, str.find(" used", start) - start - 9));
	pos = str.find("(", start);
    this->_wired = stoi(str.substr(pos + 1, str.find(" wired", start) - pos));
	pos = str.find(",", start);
	this->_unused = stoi(str.substr(pos + 1, str.find(" unused", pos) - pos));
	this->_RAMlist.push_back(static_cast<float>(this->_wired / (this->_unused + static_cast<float>(this->_used))));
}

int RAMModule::getUsed(void) const
{
    return (this->_used);
}

int RAMModule::getWired(void) const
{
    return (this->_wired);
}

int RAMModule::getUnused(void) const
{
    return (this->_unused);
}

std::list<float> *RAMModule::getRAMList(void) const
{
	return (const_cast<std::list<float> *>(&(this->_RAMlist)));
}