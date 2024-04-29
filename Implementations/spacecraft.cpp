#include "../Headers/spacecraft.h"

int Spacecraft::quantity = 0;

Spacecraft::Spacecraft(){
    setCode(quantity);
    quantity++;
    setAvailable(true);
    setWorking(true);
}
Spacecraft::~Spacecraft(){}

//Getters
int Spacecraft::getCode() const{
    return code;
}
std::map<std::string, Astronaut*> Spacecraft::getAstronauts(){
    return astronauts;
}
bool Spacecraft::astronautExist(std::string cpf){
    return (astronauts.find(cpf) != astronauts.end());
}
bool Spacecraft::isAvailable(){
    return available;
}
bool Spacecraft::isWorking(){
    return working;
}

//Setters
void Spacecraft::setCode(int value){
    code = value;
}
void Spacecraft::addAstronaut(Astronaut* &value){
    astronauts[value->getCPF()] = value;
}
void Spacecraft::removeAstronaut(Astronaut* &value){
    astronauts.erase(value->getCPF());
}
void Spacecraft::setAvailable(bool value){
    available = value;
}
void Spacecraft::setWorking(bool value){
    working = value;
}

std::ostream& operator<<(std::ostream& os, const Spacecraft& spacecraft) {
    os <<"(Spacecraft: " << spacecraft.getCode() << ") " << "Astronauts on board:" << std::endl;
    if(spacecraft.astronauts.empty()){
        os << "Empty List" <<std::endl;
    } else {
        for (auto it = spacecraft.astronauts.begin(); it != spacecraft.astronauts.end(); ++it) {
            os << *(it->second) << std::endl;
        }
    }
    return os;
}