#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include <string>
#include <list>
#include "spacecraft.h"

class Astronaut{
    private:
        std::string cpf;
        std::string name;
        int age;
        bool alive;
        bool free;
        std::list<Spacecraft*> spacecrafts;
        
    public:
        Astronaut(std::string cpf, std::string name, int age);
        ~Astronaut();

        void setCPF(std::string value);
        void setName(std::string value);
        void setAge(int value);
        void setAlive(bool value);
        void setFree(bool value);
        void addSpacecraft(Spacecraft &value);

        std::string getCPF();
        std::string getName();
        int getAge();
        bool isAlive();
        bool isFree();
        std::list<Spacecraft*> listSpacecrafts();
};

#endif