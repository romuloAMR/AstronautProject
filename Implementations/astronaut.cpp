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
void Astronaut::addSpacecraft(Spacecraft* &value, int code){
    spacecrafts[code] = value;
}
void Astronaut::removeSpacecraft(int code){
    spacecrafts.erase(code);
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
bool Astronaut::spacecraftExist(int code){
    return (spacecrafts.find(code) != spacecrafts.end());
}
std::map<int, Spacecraft*> Astronaut::listSpacecrafts(){
    return spacecrafts;
}

//Overloading
std::ostream& operator<<(std::ostream& os, const Astronaut& astronaut) {
    os << "(" << astronaut.cpf << ", " << astronaut.name << ", " << astronaut.age  << ")" << std::endl;
    return os;
}