# include "CPUModule.hpp"

CPUModule::CPUModule(void)
{ }

CPUModule::~CPUModule(void)
{ }

CPUModule::CPUModule(CPUModule const & src)
{
    *this = src;
}

CPUModule const & CPUModule::operator=(CPUModule const &src)
{
    this->_idle = src._idle;
    this->_processes = src._processes;
    this->_systemUsage = src._systemUsage;
    this->_threads = src._threads;
    this->_userUsage = src._userUsage;
	this->_model = src._model;
    return (*this);
}

void            CPUModule::parse_it(std::string str)
{
	char buffer[100];
    FILE* file = popen("sysctl -n machdep.cpu.brand_string", "r");
    fgets(buffer, 100, file);
	this->_model = buffer;
    pclose(file);
	memset(buffer, 100, 0);
	file = popen("sysctl hw.cpufrequency", "r");
    fgets(buffer, 100, file);
	this->_frequency = static_cast<float>(std::stold(buffer + 17) / 1000000000);
    pclose(file);
	memset(buffer, 100, 0);
	file = popen("sysctl -n hw.physicalcpu", "r");
    fgets(buffer, 100, file);
	this->_cores = std::stoi(buffer);
    pclose(file);
    size_t start = str.find("usage: ");
    size_t pos = 0;
    pos = str.find("%");
    this->_userUsage = stof(str.substr(start + 7, pos - start + 7));
    str.erase(pos, 1);
    this->_systemUsage = stof(str.substr(pos + 6, str.find("%") - pos + 7));
    pos = str.find("%");
    str.erase(pos, 1);
    this->_idle = stof(str.substr(pos + 5, str.find("%") - pos + 6));
    this->_processes = stoul(str.substr(11, str.find(" ", 12)));
    pos = str.find("sleeping, ") + 10;
    this->_threads = stoul(str.substr(pos, str.find("threads") - pos));
	this->_CPUlist.push_back(100.0 - this->_idle);
}

unsigned long CPUModule::getProcesses(void) const
{
    return (this->_processes);
}

unsigned long CPUModule::getThreads(void) const
{
    return (this->_threads);
}

float       CPUModule::getIdle(void) const
{
    return (this->_idle);
}

float       CPUModule::getSystemUsage(void) const
{
    return (this->_systemUsage);
}

float       CPUModule::getUserUsage(void)const
{
    return (this->_userUsage);
}

std::string	CPUModule::getModel(void) const
{
	return (this->_model);
}

float		CPUModule::getFrequency(void) const
{
	return (this->_frequency);
}

unsigned int	CPUModule::getCores(void) const
{
	return (this->_cores);
}

std::list<float> *CPUModule::getCPUList(void) const
{
	return (const_cast<std::list<float> *>(&(this->_CPUlist)));
}
