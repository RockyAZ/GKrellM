#ifndef NETWORK_MODULE_HPP
# define NETWORK_MODULE_HPP
#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
private:
    unsigned long			_packets_in;
    static unsigned long	_prev_packets_in;
    unsigned long			_data_in;
    unsigned long			_packets_out;
    static unsigned long	_prev_packets_out;
    unsigned long			_data_out;
	static bool				_first;
public:
    NetworkModule();
    NetworkModule(NetworkModule const &);
    NetworkModule const &operator=(NetworkModule const &);
    virtual void parse_it(std::string);
    unsigned long getPacketsIn() const;
    unsigned long getPrevPacketsIn() const;
    unsigned long getPacketsOut() const;
    unsigned long getPrevPacketsOut() const;
    unsigned long getDataIn() const;
    unsigned long getDataOut() const;
    ~NetworkModule();
};

#endif