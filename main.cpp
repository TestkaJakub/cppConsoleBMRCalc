#include <iostream>
#include <string.h>
/*
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)
*/

bool getUserSex() {
    char userSex;    
    do {
        std::cout << "Podaj swoja plec ('K' jesli kobieta /'M' jesli mezczyzna):\n";
        std::cin >> userSex;
        
        if (userSex == 'M' || userSex == 'm') {
            return 0;
        } else if (userSex == 'K' || userSex == 'k') {
            return 1;
        } else {
            std::cout << "Niepoprawna plec, sprobuj ponownie.\n";
        }
    } while (true);
}

int getUserAge() {
    int age;
    do {
        std::cout << "Podaj swoj wiek:\n";
        std::cin >> age;

        if (age < 5 || age > 149) {
            std::cout << "Niepoprawny wiek, wiek powinien byc mniejszy niz 150 i wiekszy niz 4 spróbuj ponownie.\n";
        } else {
            return age;
        }
    } while (true);
}

int getUserHeight() {
    int height;
    do {
        std::cout << "Podaj swoj wzrost w centymetrach:\n";
        std::cin >> height;

        if (height < 20 || height > 300) {
            std::cout << "Niepoprawny wzrost, wzrost powinien byc wiekszy badz rowny 20 cm i mniejszy badz rowny 300 cm. Sprobuj ponownie.\n";
        } else {
            return height;
        }
    } while (true);
}

int getUserMass() {
    int mass;
    do {
        std::cout << "Podaj swoja mase w dekagramach:\n";
        std::cin >> mass;

        if (mass <= 0) {
            std::cout << "Niepoprawna masa, masa powinna byc wieksza niz 0. Sprobuj ponownie.\n";
        } else {
            return mass;
        }
    } while (true);
}

double calculateBMR(bool userSex, int userAge, int userHeight, int userMass) {
    int s; // This variable is named s in Mifflin St Jeor equation
    if (userSex) s = -161; // Female
    else s = 5; // Male
    return userMass * 0.1 + 6.25 * userHeight - 5 * userAge + s;
}

int main() {
    std::cout << "Witaj w kalkulatorze zapotrzebowania kalorycznego\n";
    
    bool userSex = getUserSex();
    int userAge = getUserAge();
    int userHeight = getUserHeight();
    int userMass = getUserMass();
    double userBMR = calculateBMR(userSex, userAge, userHeight, userMass);

    std::cout << "Twoje BMR wynosi "<<userBMR<<" kcal.\n";

    return 0;
}
