#include "main.h"

#include <iostream>
#include <stdexcept>
#include <wiringPi.h>

#include "curses.h"

const int KEY_ESCAPE = 27;
const int KEY_ENTER = 10;


ITutorial::ITutorial(const std::string& name)
    : _name(name)
{

}

ITutorial::~ITutorial()
{

}

bool ITutorial::init()
{
    if (wiringPiSetup() == -1)
    {
        throw std::runtime_error("Failed to initialise Wiring Pi Library");
        return false;
    }
    
    return true;
}

void ITutorial::run()
{
    std::cout << "Creating Curses" << std::endl;
    Curses::Start();

    std::cout << "Starting Tutorial" << std::endl;
    
    if (! start())
        return;

    std::cout << "Start Loop" << std::endl;
    while (1)
    {
        Curses::Refresh();
        
        poll();

        int ch = Curses::GetCh();
        if (ch == KEY_ESCAPE || ch == KEY_ENTER)
        {
            break;
        }
    }

    std::cout << "End Loop" << std::endl;
    
    if (! stop())
    {

    }

    Curses::Stop();
}
