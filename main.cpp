#include <iostream>
#include "Headers/astronaut.h"

int main(){
    Astronaut astro("12345678901", "John Doe", 35);
    std::cout << astro.getCPF() << ", " << astro.getName() << ", " << astro.getAge() << std::endl;
    std::cout << "OK!" << std::endl;
    return 0;
}