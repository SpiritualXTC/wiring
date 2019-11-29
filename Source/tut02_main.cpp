
#include <memory>
#include <wiringPi.h>

#include "main.h"

#define ledPin      0
#define buttonPin   1




class Tutorial_02 : public ITutorial
{
public:
    Tutorial_02();
    virtual ~Tutorial_02();

protected:
    virtual bool start() override;
    virtual bool stop() override;
    virtual void poll() override;

private:
    void* _led      = nullptr;
    void* _button   = nullptr;
    int _lastState = 0;
};

Tutorial_02::Tutorial_02() :
    ITutorial("Tutorial 02 - LED + Button")
{

}

Tutorial_02::~Tutorial_02()
{

}

bool Tutorial_02::start()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    pullUpDnControl(buttonPin, PUD_UP);

    return true;
}

bool Tutorial_02::stop()
{
    digitalWrite(ledPin, LOW);
    return true;
}

void Tutorial_02::poll()
{
    int currentState = digitalRead(buttonPin);

     if (_lastState != currentState)
    {
        if (currentState == LOW)
        {
            digitalWrite(ledPin, HIGH);
            
            printf("led on ...\n");
        }
        else
        {
            digitalWrite(ledPin, LOW);
            printf("led off ...\n");
        }
    }
    

    _lastState = currentState;
}



int main()
{
    std::unique_ptr<Tutorial_02> tut = std::make_unique<Tutorial_02>();
    
    tut->init();
    tut->run();
    
    return 0;
}
