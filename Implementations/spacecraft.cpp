#include "../Headers/spacecraft.h"
#include <iostream>

int Spacecraft::quantity = 0;

Spacecraft::Spacecraft(){
    setCode(quantity);
    quantity++;
    setIntact(true);
    setWorking(true);
}
Spacecraft::~Spacecraft(){}

//Getters
int Spacecraft::getCode(){
    return code;
}
void Spacecraft::showAstronauts(){
    std::cout <<"(Spacecraft: " << getCode() << ") " << "Astronauts on board:" << std::endl;
    if(astronauts.empty()){
        std::cout << "\tEmpty List" <<std::endl;
    } else {
        for (std::map<std::string, Astronaut*>::iterator it = astronauts.begin(); it != astronauts.end(); ++it) {
            std::cout << *(it->second) << std::endl;
        }
    }
}
bool Spacecraft::isIntact(){
    return intact;
}
bool Spacecraft::isWorking(){
    return working;
}

//Setters
void Spacecraft::setCode(int value){
    code = value;
}
void Spacecraft::addAstronaut(Astronaut& value){
    astronauts[value.getCPF()] = &value;
}
void Spacecraft::removeAstronaut(Astronaut& value){
    astronauts.erase(value.getCPF());
}
void Spacecraft::setIntact(bool value){
    intact = value;
}
void Spacecraft::setWorking(bool value){
    working = value;
}