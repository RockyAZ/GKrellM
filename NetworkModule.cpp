#include "NetworkModule.hpp"

bool			NetworkModule::_first;
unsigned long	NetworkModule::_prev_packets_out;
unsigned long	NetworkModule::_prev_packets_in;


NetworkModule::NetworkModule(void)
{ }

NetworkModule::~NetworkModule(void)
{ }

NetworkModule::NetworkModule(NetworkModule const &src)
{
    *this = src;
}

NetworkModule const &NetworkModule::operator=(NetworkModule const &src)
{
    this->_data_in = src._data_in;
    this->_data_out = src._data_out;
    this->_packets_in = src._packets_in;
    this->_packets_out = src._packets_out;
    return (*this);
}

void        NetworkModule::parse_it(std::string str)
{
	if (_first)
	{
		this->_prev_packets_in = _packets_in;
		this->_prev_packets_out = _packets_out;
	}
    size_t start = str.find("packets: ");
    size_t pos;
    this->_packets_in = stoul(str.substr(start + 8, str.find("/", start) - start - 8));
    pos = str.find("/", start);
    this->_data_in = stoul(str.substr(pos + 1, str.find(" ", pos) - pos));
    if (str[str.find(" ", pos) - 1] == 'G')
        this->_data_in *= 1024;
    start = str.find("in, ");
    this->_packets_out = stoul(str.substr(start + 4, str.find("/", start) - start - 4));
    pos = str.find("/", start);
    this->_data_out = stoul(str.substr(pos + 1, str.find(" ", pos) - pos));
    if (str[str.find(" ", pos) - 1] == 'G')
        this->_data_out *= 1024;
	this->_first = 1;
}

unsigned long NetworkModule::getDataIn(void) const
{
    return (this->_data_in);
}

unsigned long NetworkModule::getDataOut(void) const
{
    return (this->_data_out);
}

unsigned long NetworkModule::getPacketsIn(void) const
{
    return (this->_packets_in);
}

unsigned long NetworkModule::getPrevPacketsIn(void) const
{
    return (this->_prev_packets_in);
}

unsigned long NetworkModule::getPacketsOut(void) const
{
    return (this->_packets_out);
}

unsigned long NetworkModule::getPrevPacketsOut(void) const
{
    return (this->_prev_packets_out);
}