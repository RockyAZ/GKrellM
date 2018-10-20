#ifndef RAM_MODULE_HPP
# define RAM_MODULE_HPP
#include "IMonitorModule.hpp"
#include <list>

class RAMModule : public IMonitorModule
{
private:
    int _used;
    int _wired;
    int _unused;
	std::list<float>	_RAMlist;
public:
    RAMModule();
    RAMModule(RAMModule const &);
    RAMModule const &operator=(RAMModule const &);
    virtual void parse_it(std::string);
    int getUsed() const;
    int getWired() const;
    int getUnused() const;
    std::list<float> *getRAMList(void) const;
    ~RAMModule();
};

#endif