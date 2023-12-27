#include <array>
#include <algorithm>
#include <iostream>
#include <string.h>
/*
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)

    1. Variables | DONE
    2. Strings | DONE
    3. Int and doubles | DONE
    4. If statements and loops | DONE
    5. Arrays | DONE
    6. Functions | DONE
    7. Input | DONE

    1. Comments in english
    2. Date
    3. Exception handling
*/


bool getUserSex() {
    std::string userSex;
    std::array<std::string, 10> female = {"k", "d", "g", "w", "kobieta", "dziewczyna", "female", "girl", "women", "woman"};
    std::array<std::string, 10> male = {"m", "c", "ch", "mezczyzna", "facet", "chlopak", "male", "boy", "man", "men"};
    

    do {
        std::cout << "Podaj swoja plec (wpisz h zeby zobaczyc liste akceptowanych wartosci):\n";
        std::cin >> userSex;
        std::transform(userSex.begin(), userSex.end(), userSex.begin(), ::tolower);
        if (userSex == "h"){
            std::cout << "Akceptowane wartosci dla plci - kobieta:\n";
            for (const std::string& value : female) std::cout << "- " << value << "\n";
            std::cout << "Akceptowane wartosci dla plci - mezczyzna:\n";
            for (const std::string& value : male) std::cout << "- " << value << "\n";
        }
        else if (std::find(female.begin(), female.end(), userSex) != female.end()) return true;
        else if ((std::find(male.begin(), male.end(), userSex) != male.end())) return false;
        else std::cout << "Niepoprawna plec, sprobuj ponownie.\n";
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
        std::cout << "Podaj mase swojego ciala w kg:\n";
        std::cin >> mass;

        if (mass <= 0) {
            std::cout << "Niepoprawna masa, masa powinna byc wieksza niz 0. Sprobuj ponownie.\n";
        } else {
            return mass * 10;
        }
    } while (true);
}

double calculateBMR(bool userSex, int userAge, int userHeight, int userMass) {
    int s; // This variable is named s in Mifflin St Jeor equation
    if (userSex) s = -161; // Female
    else s = 5; // Male
    return userMass + 6.25 * userHeight - 5 * userAge + s;
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
