#ifndef CPU_MODULE_HPP
# define CPU_MODULE_HPP
#include "IMonitorModule.hpp"
#include <list>

class CPUModule : public IMonitorModule
{
private:
    unsigned long		_processes;
    unsigned long		_threads;
    float           	_userUsage;
    float           	_systemUsage;
    float           	_idle;
    std::string     	_model;
	float				_frequency;
	unsigned int		_cores;
	std::list<float>	_CPUlist;
public:
    CPUModule();
    CPUModule(CPUModule const &);
    CPUModule const & operator=(CPUModule const &);
    virtual void parse_it(std::string);
    unsigned long getProcesses() const;
    unsigned long getThreads() const;
    float           getUserUsage() const;
    float           getSystemUsage() const;
    float           getIdle() const;
    std::string     getModel() const;
	float			getFrequency() const;
	unsigned int	getCores() const;
	std::list<float> *getCPUList() const;
    ~CPUModule();
};

#endif