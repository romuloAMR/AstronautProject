#include <iostream>

short homeMenu(){
    std::cout << "------------- Menu -------------\n"
              << "| 1- Add Astronaut             |\n"
              << "| 2- Add Spacecraft            |\n"
              << "| 3- Spacecraft option         |\n"
              << "| 4- List all dead astronauts  |\n"
              << "| 5- End                       |\n"
              << "--------------------------------\n"
              <<std::endl;
    std::cout << "Choise a option: ";
    
    short option;
    std::cin >> option;
    switch (option){
    case 1: /*code*/ return 0;
    case 2: /*code*/ return 0;
    case 3: /*code*/ return 1;
    case 4: /*code*/ return 0;
    case 5: return -1;
    default: std::cout << "Invalid option!" << std::endl; return 0;
    }
}

short spacecraftMenu(){
    std::cout << "------ Spacecraft Menu ------|\n"
              << "| 1- Add Astronaut           |\n"
              << "| 2- Remove Astronaut        |\n"
              << "| 3- Launch Spacecraft       |\n"
              << "| 4- Destroy Spacecraft      |\n"
              << "| 5- Finalize Launch         |\n"
              << "| 6- List planned Launches   |\n"
              << "| 7- List Launches           |\n"
              << "| 8- List finalized Launches |\n"
              << "| 9- Exit                    |\n"
              << "------------------------------\n"
              << std::endl;
    std::cout << "Choise a option: ";

    short option;
    std::cin >> option;
    switch (option){
        case 1: /*code*/ return 1;
        case 2: /*code*/ return 1;
        case 3: /*code*/ return 1;
        case 4: /*code*/ return 1;
        case 5: /*code*/ return 1;
        case 6: /*code*/ return 1;
        case 7: /*code*/ return 1;
        case 8: /*code*/ return 1;
        case 9: return 0;
        default: std::cout << "Invalid option!" << std::endl; return 1;
    }
}

int main(){
    short option = 0;
    while(option != -1){
        switch(option){
            case 0: option = homeMenu(); break;
            case 1: option  = spacecraftMenu(); break;
        }
    }
    return 0;
}