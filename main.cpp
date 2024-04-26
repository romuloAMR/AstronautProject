#include <iostream>
#include "Headers/fakedb.h"

short homeMenu(FakeDB* &db){
    std::cout << "------------ Menu: ------------\n"
              << "| 1- Add Astronaut            |\n"
              << "| 2- Add Spacecraft           |\n"
              << "| 3- Spacecraft option        |\n"
              << "| 4- List all dead astronauts |\n"
              << "| 5- End                      |\n"
              << "-------------------------------\n"
              <<std::endl;
    std::cout << "Choise a option: ";
    
    short option;
    std::cin >> option;
    switch (option){
    case 1: db->registerAstronaut(); return 0;
    case 2: db->registerSpacecraft(); return 0;
    case 3: return 1;
    case 4: db->listAllDeadAstronauts(); return 0;
    case 5: return -1;
    default: std::cout << "Invalid option!" << std::endl; return 0;
    }
}

short spacecraftMenu(FakeDB* &db){
    std::cout << "-------------------- Spacecraft Menu: ---------------------\n"
              << "| 1- Add Astronaut           | 6- Reuse Spacecraft        |\n"
              << "| 2- Remove Astronaut        | 7- List planned Launches   |\n"
              << "| 3- Launch Spacecraft       | 8- List Launches           |\n"
              << "| 4- Destroy Spacecraft      | 9- List finalized Launches |\n"
              << "| 5- Finalize Launch         | 10- Exit                   |\n"
              << "-----------------------------------------------------------\n"
              << std::endl;
    std::cout << "Choise a option: ";

    short option;
    std::cin >> option;
    switch (option){
        case 1: db->addAstronautInSpacecraft(); return 1;
        case 2: db->removeAstronautInSpacecraft(); return 1;
        case 3: db->launchSpacecraft(); return 1;
        case 4: db->destroySpacecraft(); return 1;
        case 5: db->finalizeLaunch(); return 1;
        case 6: db->reuseSpacecraft(); return 1;
        case 7: db->listPlannedLaunches(); return 1;
        case 8: db->listLaunches(); return 1;
        case 9: db->listFinalizedLaunches(); return 1;
        case 10: return 0;
        default: std::cout << "Invalid option!" << std::endl; return 1;
    }
}

int main(){
    FakeDB* db = new FakeDB();
    short option = 0;
    while(option != -1){
        switch(option){
            case 0: option = homeMenu(db); break;
            case 1: option  = spacecraftMenu(db); break;
        }
    }
    return 0;
}