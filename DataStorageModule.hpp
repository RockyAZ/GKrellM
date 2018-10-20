#ifndef DATA_STORAGE_MODULE_HPP
# define DATA_STORAGE_MODULE_HPP
#include "IMonitorModule.hpp"

class DataStorageModule : public IMonitorModule
{
private:
    unsigned long     		_readCycles;
    static unsigned long    _prevReadCycles;
    unsigned long     		_read;
    unsigned long     		_writeCycles;
    static unsigned long	_prevWriteCycles;
    unsigned long     		_write;
	static bool				_first;
public:
    DataStorageModule();
    DataStorageModule(DataStorageModule const &);
    DataStorageModule const & operator=(DataStorageModule const &);
    virtual void parse_it(std::string);
    unsigned long getRead() const;
    unsigned long getReadCycles() const;
    unsigned long getPrevReadCycles() const;
    unsigned long getWrite() const;
    unsigned long getWriteCycles() const;
    unsigned long getPrevWriteCycles() const;
    ~DataStorageModule();
};

#endif