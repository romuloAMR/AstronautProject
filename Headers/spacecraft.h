#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <map>
#include <string>
#include <iostream>
#include "astronaut.h"

class Spacecraft{
    private:
        static int quantity;
        int code;
        std::map<std::string, Astronaut*> astronauts;
        bool intact;
        bool working;   
    public:
        Spacecraft();
        ~Spacecraft();

        int getCode();
        void showAstronauts();
        bool isIntact();
        bool isWorking();

        void setCode(int value);
        void addAstronaut(Astronaut& value);
        void removeAstronaut(Astronaut& value);
        void setIntact(bool value);
        void setWorking(bool value);
};

#endif