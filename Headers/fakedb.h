#ifndef FAKEDB_H
#define FAKEDB_H

#include <map>
#include <string>
#include <iostream>
#include "astronaut.h"
#include "spacecraft.h"

class FakeDB{
private:
    std::map<std::string, Astronaut*> astronauts;
    std::map<std::string, Astronaut*> deadAstronauts;
    std::map<int, Spacecraft*> spacecraftsInPlannig;
    std::map<int, Spacecraft*> spacecraftsInLauch;
    std::map<int, Spacecraft*> spacecraftsDestroyed;
    std::map<int, Spacecraft*> returningSpacecrafts;
    
    template<typename KeyType, typename ValueType>
    void listMap(const std::map<KeyType, ValueType>& list);

public:
    FakeDB();
    ~FakeDB();

    void registerAstronaut();
    void registerSpacecraft();

    void addAstronautInSpacecraft();
    void removeAstronautInSpacecraft();

    void launchSpacecraft();
    void destroySpacecraft();
    void finalizeLaunch();
    void reuseSpacecraft();

    void listPlannedLaunches();
    void listLaunches();
    void listFinalizedLaunches();
    void listAllDeadAstronauts();


};

#endif