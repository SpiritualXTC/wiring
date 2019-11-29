

#include <iostream>
#include <cstdio>
#include <wiringPi.h>

#include "curses.h"

#define ledPin 0

int main()
{
    std::cout << "Hello World" << std::endl;

    if (wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed !");
        return 1;
    }

    initscr();
    noecho();
    
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    printf("wiringPi initialisied successfully, GPIO %d(wiringPi pin)\n", ledPin);

    pinMode(ledPin, OUTPUT);

    bool state = LOW;

    while(1)
    {
        state = state == LOW ? HIGH : LOW;
        
        digitalWrite(ledPin, state);
        std::cout << "LED: " << (state == LOW ? "Off" : "On") << std::endl;
        refresh();
        delay(1000);
        
        int ch = getch();
        if (ch != ERR)
        {
            if (ch == 10 || ch == 27)
            {
                std::cout << "Terminating: " << std::endl;
                break;
            }
            std::cout << "Key Pressed: " << ch << std::endl;
        }
    }

    echo();
    endwin();    

    std::cout << "Uninitialising wiringPi" << std::endl;
    digitalWrite(ledPin, LOW);

 
    
    return 0;
}
