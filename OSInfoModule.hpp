#ifndef OS_INFO_MODULE_HPP
# define OS_INFO_MODULE_HPP
#include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule
{
private:
    std::string _name;
    std::string _version;
public:
    OSInfoModule();
    OSInfoModule(OSInfoModule const &);
    OSInfoModule const & operator=(OSInfoModule const &);
    virtual void parse_it(std::string);
    std::string getName() const;
    std::string getVersion() const;
    ~OSInfoModule();
};

#endif