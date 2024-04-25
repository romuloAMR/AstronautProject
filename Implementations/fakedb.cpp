#include "../Headers/fakedb.h"

FakeDB::FakeDB(){}
FakeDB::~FakeDB(){}

//Registers
void FakeDB::registerAstronaut(){
    std::string cpf;
    std::cout << "Inform the astronaut's CPF at 000.000.000-00: ";
    std::cin >> cpf;

    std::string name;
    std::cout << "Inform the astronaut's name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    int age;
    std::cout << "Inform the astronaut's age: ";
    std::cin >> age;

    Astronaut* astronaut = new Astronaut(cpf, name, age);
    astronauts[astronaut->getCPF()] = astronaut;
    std::cout << "Registration Successfully Completed!" << std::endl;
}
void FakeDB::registerSpacecraft(){
    Spacecraft* spacecraft = new Spacecraft();
    spacecraftsInPlannig[spacecraft->getCode()] = spacecraft;
    std::cout << "Registration Successfully Completed!\n" << std::endl;

}

//add and remove astronaut in spacecraft
void FakeDB::addAstronautInSpacecraft(){
    int code;
    std::cout << "Inform the Spacecraft's code: ";
    std::cin >> code;
    
    std::string cpf;
    std::cout << "Inform the astronaut's CPF at 000.000.000-00: ";
    std::cin >> cpf;

    if(spacecraftsInPlannig.find(code) != spacecraftsInPlannig.end()){
        if(astronauts.find(cpf) != astronauts.end()){
            Astronaut* a = astronauts[cpf];
            if(a->isFree()){
                Spacecraft* s = spacecraftsInPlannig[code];
                if(a->spacecraftExist(s->getCode())){
                    a->addSpacecraft(s);
                    s->addAstronaut(a);
                    std::cout << "Operation Success" << std::endl;
                } else {
                    std::cout << "The astronaut was already added!" << std::endl;
                }
            } else {
                std::cout << "Astronaut isn't free!" << std::endl;
            }
        } else {
            std::cout << "Astronaut isn't alive or doesn't exist!" << std::endl;
        }
    } else {
        std::cout << "Spacecraft isn't in planning or doesn't exist!" << std::endl;
    }

}
void FakeDB::removeAstronautInSpacecraft(){
    int code;
    std::cout << "Inform the Spacecraft's code: ";
    std::cin >> code;
    
    std::string cpf;
    std::cout << "Inform the astronaut's CPF at 000.000.000-00: ";
    std::cin >> cpf;

    if(spacecraftsInPlannig.find(code) != spacecraftsInPlannig.end()){
        if(astronauts.find(cpf) != astronauts.end()){
            Spacecraft* s = spacecraftsInPlannig[code];
            if(s->astronautExist(cpf)){
                Astronaut* a = astronauts[cpf];
                a->removeSpacecraft(s);
                s->removeAstronaut(a);
                std::cout << "Operation Success" << std::endl;
            } else {
                std::cout << "Astronaut isn't in spacecraft!" << std::endl;
            }
        } else {
            std::cout << "Astronaut isn't alive or doesn't exist!" << std::endl;
        }
    } else {
        std::cout << "Spacecraft isn't in planning or doesn't exist!" << std::endl;
    }

}