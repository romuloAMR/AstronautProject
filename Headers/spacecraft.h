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
        bool available;
        bool working;   
    public:
        Spacecraft();
        ~Spacecraft();

        int getCode() const;
        std::map<std::string, Astronaut*>* getAstronauts();
        bool astronautExist(std::string cpf);
        bool isAvailable();
        bool isWorking();

        void setCode(int value);
        void addAstronaut(Astronaut* &value);
        void removeAstronaut(Astronaut* &value);
        void setAvailable(bool value);
        void setWorking(bool value);

        friend std::ostream& operator<<(std::ostream& os, const Spacecraft& spacecraft);
};

#endif