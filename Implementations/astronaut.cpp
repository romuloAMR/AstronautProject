#include "../Headers/astronaut.h"

Astronaut::Astronaut(std::string cpf, std::string name, int age){
    setCPF(cpf);
    setName(name);
    setAge(age);
    setAlive(true);
    setFree(true);
}
Astronaut::~Astronaut(){}


//Setters
void Astronaut::setCPF(std::string value){
    cpf = value;
}
void Astronaut::setName(std::string value){
    name = value;
}
void Astronaut::setAge(int value){
    age = value;
}
void Astronaut::setAlive(bool value){
    alive = value;
}
void Astronaut::setFree(bool value){
    free = value;
}
void Astronaut::addSpacecraft(Spacecraft &value){
    spacecrafts.push_back(&value);
}


//Getters
std::string Astronaut::getCPF(){
    return cpf;
}
std::string Astronaut::getName(){
    return name;
}
int Astronaut::getAge(){
    return age;
}
bool Astronaut::isAlive(){
    return alive;
}
bool Astronaut::isFree(){
    return free;
}
std::list<Spacecraft*> Astronaut::listSpacecrafts(){
    return spacecrafts;
}