#include <array>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <ctime>
/*
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)

    1. Variables | DONE
    2. Strings | DONE
    3. Int and doubles | DONE
    4. If statements and loops | DONE
    5. Arrays | DONE
    6. Functions | DONE
    7. Input | DONE
    8. Date | DONE
    9. Exception handling | DONE

    1. Comments in english
*/

void getDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout<<"Dzisiejsza data to: "<< ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << "\n";
}

class User {
    bool _sex;
    int _age;
    int _height;
    int _mass;

    bool _SetUserSex(){
        std::string sexInput;
        std::array<std::string, 4> female = {"k", "f", "kobieta", "female"};
        std::array<std::string, 3> male = {"m", "mezczyzna", "male"};
        
        std::cout<<"Podaj swoja plec (wpisz h zeby zobaczyc liste akceptowanych wartosci):\n";
        std::cin>>sexInput;
        std::transform(sexInput.begin(), sexInput.end(), sexInput.begin(), ::tolower);
        
        if(sexInput == "h"){
            std::cout<<"Akceptowane wartosci dla plci - kobieta:\n";
            for(const std::string& value : female) std::cout<<"- "<<value<<"\n";
            std::cout<<"Akceptowane wartosci dla plci - mezczyzna:\n";
            for(const std::string& value : male) std::cout<<"- "<<value<<"\n";
            return _SetUserSex();
        }
        else if(std::find(female.begin(), female.end(), sexInput) != female.end()) return true;
        else if(std::find(male.begin(), male.end(), sexInput) != male.end()) return false;
        else {
            throw std::invalid_argument("Niepoprawna plec, sprobuj ponownie.\n");
        }
    }

    int _SetUserAge(){
        int ageInput;
        std::cout<<"Podaj swoj wiek:\n";
        std::cin>>ageInput;
        if(ageInput < 5 || ageInput > 149) {
            throw std::invalid_argument("Niepoprawny wiek, wiek powinien byc mniejszy niz 150 i nie mniejszy niz 5 sprobuj ponownie.\n");
        }
        else return ageInput;
    }

    int _SetUserHeight(){
        int heightInput;
        std::cout<<"Podaj swoj wzrost w centymetrach:\n";
        std::cin>>heightInput;
        if(heightInput < 20 || heightInput > 300) {
            throw std::invalid_argument("Niepoprawny wzrost, wzrost powinien byc wiekszy badz rowny 20 cm i mniejszy badz rowny 300 cm. Sprobuj ponownie.\n");
        }
        else return heightInput;
    }
    
    int _SetUserMass(){
        int massInput;
        std::cout<<"Podaj mase swojego ciala w kg:\n";
        std::cin>>massInput;
        if(massInput <= 0) {
            throw std::invalid_argument("Niepoprawna masa, masa powinna byc wieksza niz 0. Sprobuj ponownie.\n");
        }
        else return massInput;
    }
    
    public:
        User(){
            bool isSexSet = false;
            while(!isSexSet){
                try
                { 
                    _sex = _SetUserSex();
                    isSexSet = true;
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; }
            }
            bool isAgeSet = false;
            while(!isAgeSet){
                try
                {
                    _age = _SetUserAge();
                    isAgeSet = true;
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; }
            }
            bool isHeightSet = false;
            while(!isHeightSet){
                try
                {
                    _height = _SetUserHeight();
                    isHeightSet = true;
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; }
            }
            bool isMassSet = false;
            while(!isMassSet){
                try
                {
                    _mass = _SetUserMass();
                    isMassSet = true;
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; }
            }
        }
        void CalculateBMR(){
            int s;
            if(_sex) s = -161;
            else s = 5;
            double bmr = _mass * 10 + _height * 6.25 - _age * 5 + s;
            std::cout << "Twoje BMR wynosi " << bmr << " kcal.\n";
        }
};

int main(){
    std::cout<<"Witaj w kalkulatorze BMR!\n";
    getDate();
    User user;
    user.CalculateBMR();
    return 0;
}