#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include <iostream>
#include <string>
#include <map>

class Spacecraft{
    public:
        int getCode();
};

class Astronaut{
    private:
        std::string cpf;
        std::string name;
        int age;
        bool alive;
        bool free;
        std::map<int, Spacecraft*> spacecrafts;
        
    public:
        Astronaut(std::string cpf, std::string name, int age);
        ~Astronaut();

        void setCPF(std::string value);
        void setName(std::string value);
        void setAge(int value);
        void setAlive(bool value);
        void setFree(bool value);
        void addSpacecraft(Spacecraft* &value);
        void removeSpacecraft(Spacecraft* &value);

        std::string getCPF();
        std::string getName();
        int getAge();
        bool isAlive();
        bool isFree();
        bool spacecraftExist(int code);
        std::map<int, Spacecraft*> listSpacecrafts();

        friend std::ostream& operator<<(std::ostream& os, const Astronaut& astronaut);
};

#endif