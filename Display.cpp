// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Display.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: azaporoz <azaporoz@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 21:15:45 by azaporoz          #+#    #+#             //
//   Updated: 2018/10/13 21:15:45 by azaporoz         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Display.hpp"

Display::Display()
{
	this->cpuDraw = true;
	this->dsmDraw = true;
	this->hnmDraw = true;
	this->nmDraw = true;
	this->OSimDraw = true;
	this->ramDraw = true;
	this->tmDraw = true;
	this->catDraw = true;
}

Display::Display(Display const & src)
{
	*this = src;
}

Display::Display(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->cpuDraw = true;
	this->dsmDraw = true;
	this->hnmDraw = true;
	this->nmDraw = true;
	this->OSimDraw = true;
	this->ramDraw = true;
	this->tmDraw = true;
	this->catDraw = true;
}

Display::~Display()
{

}

Display & Display::operator  = (Display const & src)
{
	this->_x = src._x;
	this->_y = src._y;
	return *this;
}

int Display::getX()
{
	return (this->_x);
}

int Display::getY()
{
	return (this->_y);
}

int Display::getInfo()
{
	return this->_realInfo;
}



void Display::setX(int src)
{
	this->_x = src;
}

void Display::setY(int src)
{
	this->_y = src;
}

void Display::setMax(int src)
{
	this->_maxi = src;
}

void Display::setInfo(int src)
{
	this->_realInfo = src;
}

void Display::setType(std::string src)
{
	this->_type = src;
}

static std::string read_stats(const char* cmd)
{
	char buffer[200];
	std::string result = "";
	FILE* file = popen(cmd, "r");
	if (!file) throw std::runtime_error("popen() failed!");
	for (int i = 0; i < 10; i++)
		if (fgets(buffer, 200, file) != NULL)
	   		result += buffer;
	pclose(file);
	return result;
}

void Display::render()
{
	int start = 23;
	int maxw = 40;
	std::string str = read_stats("top");
	static bool deb = true;
	int y = 1;
	if (this->cpuDraw)
	{
		this->cpu.parse_it(str);
		attron(COLOR_PAIR(2));
		mvprintw(y++, 1, "Processes %i", this->cpu.getProcesses());//1200
		mvprintw(y++, 1, "Workload  %f", 100 - this->cpu.getIdle());//100 | 100 - idle
		mvprintw(y++, 1, "SysUsage  %f", this->cpu.getSystemUsage());//100
		mvprintw(y++, 1, "UserUsage %f", this->cpu.getUserUsage());//100
		mvprintw(y++, 1, "Threads   %u", this->cpu.getThreads());//5000
		mvprintw(y++, 1, "Cores     %u", this->cpu.getCores());//
		mvprintw(y++, 1, "Frequency %f", this->cpu.getFrequency());
		mvprintw(y++, 1, "Model     %s", this->cpu.getModel().c_str());
	attroff(COLOR_PAIR(2));

attron(COLOR_PAIR(1));
		int idleLen = (100.0 - this->cpu.getIdle()) * static_cast<float>(maxw / 100.0);
		mvaddch(y - 7, start, '>');
		mvaddch(y - 7, maxw + start, '<');
		for(int i = 1; i < idleLen; i++)
			mvaddch(y - 7, start + i , ACS_CKBOARD);

		int sysLen = this->cpu.getSystemUsage() * static_cast<float>(maxw / 100.0);
		mvaddch(y - 6, start, '>');
		mvaddch(y - 6, maxw + start, '<');
		for(int i = 1; i < sysLen; i++)
			mvaddch(y - 6, start + i, ACS_CKBOARD);

		int userLen = this->cpu.getUserUsage() * static_cast<float>(maxw / 100.0);
		mvaddch(y - 5, start, '>');
		mvaddch(y - 5, maxw + start, '<');
		for(int i = 1; i < userLen; i++)
			mvaddch(y - 5, start + i, ACS_CKBOARD);
	std::list<float>::const_iterator graphBegin = this->cpu.getCPUList()->begin();//pometka
	std::list<float>::const_iterator graphEnd = this->cpu.getCPUList()->end();
	int len;
	int listX = 73;
	int listY = 0;
	attron(COLOR_PAIR(4));
	while (graphBegin != graphEnd)
	{
		len = *graphBegin * static_cast<float>(10 / 100.0);
		for (int i = len; i > 0; i--)
		{
			mvaddch(listY + 10 - i, listX, '|');
		}
		listX++;
		graphBegin++;
	}
	attron(COLOR_PAIR(1));
	mvprintw(12, 83, "CPU USAGE");
	attroff(COLOR_PAIR(1));
	if (listX - 73 > 30)
		this->cpu.getCPUList()->pop_front();
	attroff(COLOR_PAIR(4));
attroff(COLOR_PAIR(1));
	}
	if (this->dsmDraw)
	{
		y++;
		this->dsm.parse_it(str);
	attron(COLOR_PAIR(3));
		mvprintw(y++, 1, "Read            %d", dsm.getRead());
		mvprintw(y++, 1, "ReadCycles      %d",  dsm.getReadCycles());
		mvprintw(y++, 1, "Write           %d", dsm.getWrite());
		mvprintw(y++, 1, "WriteCycles     %d", dsm.getWriteCycles());
		if (dsm.getPrevReadCycles() != dsm.getReadCycles())
		{
			attron(COLOR_PAIR(2));
			mvaddch(y - 3, start + 5, ACS_DIAMOND);
			attroff(COLOR_PAIR(2));
		}
		else
		{
			attron(COLOR_PAIR(1));
			mvaddch(y - 3, start + 5, ACS_DIAMOND);
			attroff(COLOR_PAIR(1));
		}
		if (dsm.getPrevWriteCycles() != dsm.getWriteCycles())
		{
			attron(COLOR_PAIR(2));
			mvaddch(y - 1, start + 5, ACS_DIAMOND);
			attroff(COLOR_PAIR(2));
		}
		else
		{
			attron(COLOR_PAIR(1));
			mvaddch(y - 1, start + 5, ACS_DIAMOND);
			attroff(COLOR_PAIR(1));
		}
	attroff(COLOR_PAIR(3));
	}
	if (this->hnmDraw)
	{
		y++;
		attron(COLOR_PAIR(2));
		this->hnm.parse_it(str);
		mvprintw(y++, 1, "Hostname        %s",  hnm.getHostname().c_str());
		attroff(COLOR_PAIR(2));
	}
	if (this->nmDraw)
	{
		y++;
		this->nm.parse_it(str);
attron(COLOR_PAIR(3));
		mvprintw(y++, 1, "Packets in      %d",  nm.getPacketsIn());
		mvprintw(y++, 1, "Data in         %d",  nm.getDataIn());
		mvprintw(y++, 1, "Packets out     %d",  nm.getPacketsOut());
		mvprintw(y++, 1, "Data out        %d",  nm.getDataOut());

			if (nm.getPrevPacketsIn() != nm.getPacketsIn())
			{
				attron(COLOR_PAIR(2));
				mvaddch(y - 4, start + 5, ACS_DIAMOND);
				attroff(COLOR_PAIR(2));
			}
			else
			{
				attron(COLOR_PAIR(1));
				mvaddch(y - 4, start + 5, ACS_DIAMOND);
				attroff(COLOR_PAIR(1));
			}
			if (nm.getPrevPacketsOut() != nm.getPacketsOut())
			{
				attron(COLOR_PAIR(2));
				mvaddch(y - 2, start + 5, ACS_DIAMOND);
				attroff(COLOR_PAIR(2));
			}
			else
			{
				attron(COLOR_PAIR(1));
				mvaddch(y - 2, start + 5, ACS_DIAMOND);
				attroff(COLOR_PAIR(1));
			}
attroff(COLOR_PAIR(3));
	}
	if (this->OSimDraw)
	{
		y++;
attron(COLOR_PAIR(2));
		this->OSim.parse_it(str);
		mvprintw(y++, 1, "Name    %s", OSim.getName().c_str());
		mvprintw(y++, 1, "Version %s", OSim.getVersion().c_str());
attroff(COLOR_PAIR(2));
	}
	if (this->ramDraw)
	{
		y++;
attron(COLOR_PAIR(3));
		this->ram.parse_it(str);
		mvprintw(y++, 1, "Used 	%d", ram.getUsed());
		mvprintw(y++, 1, "Wired 	%d", ram.getWired());
		mvprintw(y++, 1, "Unused %d", ram.getUnused());
	attron(COLOR_PAIR(1));
		int ramLen = static_cast<float>((ram.getWired() * 1.0 / (ram.getUsed() + ram.getUnused()))) * maxw;
		mvaddch(y - 3, start, '>');
		mvaddch(y - 3, maxw + start, '<');
		for(int i = 1; i < ramLen; i++)
			mvaddch(y - 3, start + i , ACS_CKBOARD);
	attroff(COLOR_PAIR(1));
	std::list<float>::const_iterator wiredBegin = this->ram.getRAMList()->begin();
	std::list<float>::const_iterator wiredEnd = this->ram.getRAMList()->end();
	int len;
	int listX = 73;
	int listY = 13;
	attron(COLOR_PAIR(4));
	while (wiredBegin != wiredEnd)
	{
		len = static_cast<int>(*wiredBegin * 10);
		for (int i = len; i > 0; i--)
		{
			mvaddch(listY + 10 - i, listX, '|');
		}
		listX++;
		wiredBegin++;
	}
	attron(COLOR_PAIR(1));
	mvprintw(25, 83, "RAM USAGE");
	attroff(COLOR_PAIR(1));
	if (listX - 73 > 30)
		this->ram.getRAMList()->pop_front();
	attroff(COLOR_PAIR(4));
attroff(COLOR_PAIR(3));
	}
	if (this->tmDraw)
	{
		y++;
		tm.parse_it(str);
		mvprintw(y++, start, "Time: %s", this->tm.getTime().c_str());
	}
	if (this->catDraw)
	{
		if (deb)
		{

mvprintw(y++, start, "\nX XXXXX                                       XXX\n \
X     XXX                                   XXX X\n \
 X      XXX                                XX   XX\n \
 X        XXX                            XX      X\n \
 XX         XX                          XX       X                      XXX\n \
  X           XX      XXXXX             X        X                     XX XX  XXX\n \
  X            XX XXXX     XXXXXXX     X         X                    XX   XXXX X\n \
  XX            XXX              XXXXXXX         X                   XXXXXXXX  XX\n \
  XX            XX                   XX          X                 XXX   XXX  XX\n \
  XX                                  XXXXXXX    X               XXX       XXXXXXXX\n \
    X                  XX         XXXXX   XXXXX XX             XXX           X XXXX\n \
     X             XXXXX X     XXX            X X            XX            XXXXX\n \
      X           XX  X  XXXXXXX           XXXX X         XXXX          XXX\n \
       XX          XXXXXXXX                 XX  X      XXXX           XXX\n \
        XX       XXXXXXX          XXXXXXXXXXXX XX    XXX            XX\n \
          XXXXXXX              XXXXX           X   XX             XX\n \
        XXXXXX             XXXXX              X  XX            XXX\n \
     XXXX    XXX       XXXXX XX              XX XX           XX\n \
   XX          XXXXXXXX                     XXXX          XXX\n \
   XXX        XXXXXXX         XXXXX        XXX         XXX\n \
     XXX      XX  X  XXXX    XX    XX     XXX        XXX\n \
       XXX     XX X     XXXX           XXX X       XXX\n \
         XXX    XXX         XXXXXXXXXXX    XX     XX\n \
           XXX  XX                          X  XXX\n \
             XXX X                          XXXX\n \
                XX                          XX\n \
                 X                          X\n \
                 X                          X\n \
                 X                          X\n \
                 X                          X\n");
		}
		else
		{
mvprintw(y++, start, "\n\
                         XXX                                             X\n\
                         X XXXXX                                       XXX\n\
                         X     XXX                                   XXX X\n\
                          X      XXX                                XX   XX\n\
                          X        XXX                            XX      X\n\
      XXXX                XX         XX                          XX       X\n\
  XX X   XX                X           XX      XXXXX             X        X\n\
 XX XXXX  X                X            XX XXXX     XXXXXXX     X         X\n\
  XXXX   XX                XX            XXX              XXXXXXX         X\n\
XX  XXX   XX               XX            XX                   XX          X\n\
XX          XX             XX                                             X\n\
  XXXXX      XXX             X                XXXX         XXX           XX\n\
      XXX      XXX            X           XXXXX  XXXXX  XXX   XXX        X\n\
         XX       XX           X          XX           XXXX  X  X        X\n\
           XXX      XXX         XX        XX               XXXXXX        X\n\
             XXXX     XXX        XX      XX                  XXXXXXXXX  XX\n\
                XXX      XXXX      XX     XXXXXXXXXXXXX              XXXXXX\n\
                  XXX       XXXX     XX              XXXXXXXX              XXXX\n\
                     XXX       XXX    XXX             XX     XXXXXXX          XXX\n\
                        XXX       XXX   XXX                        XXX        XX\n\
                          XXX       XXXX   XXX         XXXXX        XXX      XX\n\
                            XXXX       XXX X  XXXX    XX    XX     XXXX     XX\n\
                               XXX        XX     XXXX           XXX XX    XX\n\
                                 XXXX     XX         XXXXXXXXXXX    XX   XX\n\
                                     XXXX X                          X  XX\n\
                                        XXX                          X XX\n\
                                          X                          XXX\n\
                                          X                          X\n\
                                          X                          X\n\
                                         XX                          X\n\
                                         X                           X\n\
                                         X                           X\n\
                                         X                           XX\n");
		}
		deb = !deb;
		}
}
