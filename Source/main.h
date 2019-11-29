#pragma once

#include <string>

class ITutorial
{
public:
        ITutorial(const std::string& name);
        virtual ~ITutorial();

        bool            init();
        void            run();

protected:
        virtual bool    start() = 0;
        virtual bool    stop() = 0;
        virtual void    poll() = 0;

private:

        std::string _name;
};


