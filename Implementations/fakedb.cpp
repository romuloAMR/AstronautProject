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
                if(!(s->astronautExist(a->getCPF()))){
                    a->addSpacecraft(s, s->getCode());
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
                a->removeSpacecraft(s->getCode());
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

//Modify Spacecrafts
void FakeDB::launchSpacecraft(){
    int code;
    std::cout << "Inform a Spacecraft code: ";
    std::cin >> code;
    if (spacecraftsInPlannig.find(code) != spacecraftsInPlannig.end()){
        Spacecraft* s = spacecraftsInPlannig[code];
        auto tempMap = s->getAstronauts();
        if(!tempMap->empty()){
            for (auto iter = tempMap->begin(); iter != tempMap->end(); ++iter) {
                if (!iter->second->isFree()){
                    std::cout << "Erro: Astronaut doesn't free!" << std::endl;
                    return;
                }
            }
            for (auto iter = tempMap->begin(); iter != tempMap->end(); ++iter) {
                iter->second->setFree(false);
            }
            s->setAvailable(false);
            spacecraftsInLauch[code] = s;
            spacecraftsInPlannig.erase(code);
            std::cout << "Operation Success" << std::endl;
        }
        else {
            std::cout << "Erro: Spacecraft empty!" << std::endl;
        }
    }
    else {
        std::cout << "Error: Spacecraft not found!" << std::endl;
    }
}
void FakeDB::destroySpacecraft(){
    int code;
    std::cout << "Inform a Spacecraft code: ";
    std::cin >> code;
    if(spacecraftsInLauch.find(code) != spacecraftsInLauch.end()){
        Spacecraft* s = spacecraftsInLauch[code];
        auto tempMap = s->getAstronauts();
        for (auto iter = tempMap->begin(); iter != tempMap->end(); ++iter) {
                auto a = iter->second;
                a->setAlive(false);
                deadAstronauts[a->getCPF()] = a;
                astronauts.erase(a->getCPF());

                for (auto interr = spacecraftsInPlannig.begin(); interr!= spacecraftsInPlannig.end(); interr++){
                    auto s2 = interr->second;
                    if(a->spacecraftExist(s2->getCode())){
                        s2->removeAstronaut(a);
                        a->removeSpacecraft(s2->getCode());
                    }
                }
            }
        s->setWorking(false);
        spacecraftsDestroyed[code] = s;
        spacecraftsInLauch.erase(code);
        std::cout << "Spacecraft destroyed!" << std::endl;
    } else {
        std::cout << "Error: Spacecraft not found!" << std::endl;
    }
}
void FakeDB::finalizeLaunch(){
    int code;
    std::cout << "Inform a Spacecraft code: ";
    std::cin >> code;
    if(spacecraftsInLauch.find(code) != spacecraftsInLauch.end()){
        Spacecraft* s = spacecraftsInLauch[code];
        auto tempMap = s->getAstronauts();
        for (auto iter = tempMap->begin(); iter != tempMap->end(); ++iter) {
                iter->second->setFree(true);
            }
        s->setAvailable(true);
        returningSpacecrafts[code] = s;
        spacecraftsInLauch.erase(code);
        std::cout << "Spacecraft returned!" << std::endl;
    } else {
        std::cout << "Error: Spacecraft not found!" << std::endl;
    }
}
void FakeDB::reuseSpacecraft(){
    int code;
    std::cout << "Inform a Spacecraft code: ";
    std::cin >> code;
    if(returningSpacecrafts.find(code) != returningSpacecrafts.end()){
        auto s = returningSpacecrafts[code];
        s->setAvailable(true);
        s->getAstronauts()->clear();
        spacecraftsInPlannig[code] = s;
        returningSpacecrafts.erase(code);
        std::cout << "Reusable Spacecraft!" << std::endl;
    } else {
        std::cout << "Error: Spacecraft not found!" << std::endl;
    }
}

//List
template<typename KeyType, typename ValueType>
void FakeDB::listMap(const std::map<KeyType, ValueType>& list){
    if(list.empty()){
        std::cout << "List Empty" << std::endl;
    } else {
        for (const auto& pair : list) {
            std::cout << *pair.second << std::endl;
        }
    }
}

void FakeDB::listPlannedLaunches(){
    listMap(spacecraftsInPlannig);
}
void FakeDB::listLaunches(){
    listMap(spacecraftsInLauch);
}
void FakeDB::listFinalizedLaunches(){
    std::cout << "Successfully completed:" << std::endl;
    listMap(returningSpacecrafts);
    std::cout << "Exploded:" << std::endl;
    listMap(spacecraftsDestroyed);
}
void FakeDB::listAllDeadAstronauts(){
    if(deadAstronauts.empty()){
        std::cout << "List Empty" << std::endl;
    } else {
        for (const auto& astronaut : deadAstronauts) {
            std::cout << *astronaut.second;
            std::cout << "Astronaut Launches: ";
            for (const auto& spacecrafts : astronaut.second->listSpacecrafts()) {
                std::cout << spacecrafts.first << " ";
            }
            std::cout << std::endl;
        }
    }
}