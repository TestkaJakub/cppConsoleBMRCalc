#include <iostream>
#include <string.h>
/*
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)

    1. GetUserSex | DONE
    2. GetUserAge | DONE

    3. GetUserHeight | TO DO
    4. GetUserMass | TO DO
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

int main() {
    std::cout << "Witaj w kalkulatorze zapotrzebowania kalorycznego\n";
    
    bool userSex = getUserSex();
    int userAge = getUserAge();

    

    return 0;
}
