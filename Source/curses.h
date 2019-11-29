#pragma once



class Curses
{

private:
    Curses(){}
    virtual ~Curses(){}

public:
    static bool     Start();
    static bool     Stop();
    static void     Refresh();

    static int      GetCh();

private:


};
