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
    std::map<int, Spacecraft*> spacecraftsInPlannig;
    std::map<int, Spacecraft*> spacecraftsDestroyed;
    std::map<int, Spacecraft*> returningSpacecrafts;
public:
    FakeDB();
    ~FakeDB();

    void registerAstronaut();
    void registerSpacecraft();

    void addAstronautInSpacecraft();
    void removeAstronautInSpacecraft();
};

#endif