#include <iostream>
#include <string.h>
/*
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)

    1. GetUserSex | DONE
    2. GetUserAge | DONE
    3. GetUserHeight | DONE
    4. GetUserMass | DONE
*/

bool getUserSex() {
    char userSex;    
    do {
        std::cout << "Podaj swoją płeć ('K' jeśli kobieta /'M' jeśli mężczyzna):\n";
        std::cin >> userSex;
        
        if (userSex == 'M' || userSex == 'm') {
            return 0;
        } else if (userSex == 'K' || userSex == 'k') {
            return 1;
        } else {
            std::cout << "Niepoprawna płeć, spróbuj ponownie.\n";
        }
    } while (true);
}

int getUserAge() {
    int age;
    do {
        std::cout << "Podaj swój wiek:\n";
        std::cin >> age;

        if (age < 5 || age > 149) {
            std::cout << "Niepoprawny wiek, wiek powinien być mniejszy niż 150 i większy niż 4 spróbuj ponownie.\n";
        } else {
            return age;
        }
    } while (true);
}

int getUserHeight() {
    int height;
    do {
        std::cout << "Podaj swój wzrost w centymetrach:\n";
        std::cin >> height;

        if (height < 20 || height > 300) {
            std::cout << "Niepoprawny wzrost, wzrost powinien być większy nądź równy 20 cm i mniejszy bądź równy 300 cm. Spróbuj ponownie.\n";
        } else {
            return height;
        }
    } while (true);
}

int getUserMass() {
    int mass;
    do {
        std::cout << "Podaj swoją masę w dekagramach:\n";
        std::cin >> mass;

        if (mass <= 0) {
            std::cout << "Niepoprawna masa, masa powinna być większa niż 0. Spróbuj ponownie.\n";
        } else {
            return mass;
        }
    } while (true);
}

int main() {
    std::cout << "Witaj w kalkulatorze zapotrzebowania kalorycznego\n";
    
    bool userSex = getUserSex();
    int userAge = getUserAge();
    int userHeight = getUserHeight();
    int userMass = getUserMass();
    
    return 0;
}
