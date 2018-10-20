# include "DataStorageModule.hpp"

bool			DataStorageModule::_first;
unsigned long	DataStorageModule::_prevReadCycles;
unsigned long	DataStorageModule::_prevWriteCycles;

DataStorageModule::DataStorageModule(void)
{ }

DataStorageModule::~DataStorageModule(void)
{ }

DataStorageModule::DataStorageModule(DataStorageModule const &src)
{
    *this = src;
}

DataStorageModule const &DataStorageModule::operator=(DataStorageModule const &src)
{
    this->_read = src._read;
    this->_readCycles = src._readCycles;
    this->_write = src._write;
    this->_writeCycles = src._writeCycles;
    return (*this);
}

void                DataStorageModule::parse_it(std::string str)
{
	if (_first)
	{
		this->_prevReadCycles = _readCycles;
		this->_prevWriteCycles = _writeCycles;
	}
    size_t  start = str.find("Disks: ");
    size_t  pos;
    this->_readCycles = stoul(str.substr(start + 7, str.find("/", start) - start - 7));
    pos = str.find("/", start);
    this->_read = stoul(str.substr(pos + 1, str.find(" ", pos) - pos));
    if (str[str.find(" ", pos) - 1] == 'G')
        this->_read *= 1024;
    start = str.find("read, ");
    pos = str.find("/", start);
    this->_writeCycles = stoul(str.substr(start + 6, pos - start - 6));
    this->_write = stoul(str.substr(pos + 1, str.find(" ", pos) - pos));
    if (str[str.find(" ", pos) - 1] == 'G')
        this->_write *= 1024;
	_first = 1;
}

unsigned long DataStorageModule::getRead(void) const
{
    return (this->_read);
}

unsigned long    DataStorageModule::getReadCycles(void) const
{
    return (this->_readCycles);
}

unsigned long    DataStorageModule::getPrevReadCycles(void) const
{
    return (this->_prevReadCycles);
}

unsigned long    DataStorageModule::getWrite(void) const
{
    return (this->_write);
}

unsigned long    DataStorageModule::getWriteCycles(void) const
{
    return (this->_writeCycles);
}

unsigned long    DataStorageModule::getPrevWriteCycles(void) const
{
    return (this->_prevWriteCycles);
}