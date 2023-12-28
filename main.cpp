#include <array>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <ctime>
/*
    The Miffin St Jeor equation used here to calculate BMR is as follows:
    P = (10 * mass in kg / 1kg) + (6.25 * height in cm / 1cm) - (5 * age in years / 1 year) ( +5 for males || -161 for females)
*/

void getDate() { // Get and print current date
    time_t now = time(0); // Get the current time
    tm *ltm = localtime(&now); // Convert the current time to local time
    std::cout << "Today's date is: " << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << "\n";
}

class User {
    bool _sex; // User's sex (true for female, false for male)
    int _age; // User's age
    int _height; // User's height in centimeters
    int _mass; // User's mass in kilograms

    bool _SetUserSex(){
        std::string sexInput; // User input for sex
        std::array<std::string, 4> female = {"k", "f", "kobieta", "female"}; // Array of accepted values for female
        std::array<std::string, 3> male = {"m", "mezczyzna", "male"}; // Array of accepted values for male
        
        std::cout<<"Podaj swoja plec (wpisz h zeby zobaczyc liste akceptowanych wartosci):\n";
        std::cin>>sexInput;
        std::transform(sexInput.begin(), sexInput.end(), sexInput.begin(), ::tolower); // User sexInput to lowercase
        
        if(sexInput == "h"){ // If user input is h, print accepted values and call _SetUserSex() again
            std::cout<<"Akceptowane wartosci dla plci - kobieta:\n";
            for(const std::string& value : female) std::cout<<"- "<<value<<"\n"; // Printing accepted values for female
            std::cout<<"Akceptowane wartosci dla plci - mezczyzna:\n";
            for(const std::string& value : male) std::cout<<"- "<<value<<"\n"; // Printing accepted values for male
            return _SetUserSex(); // Call _SetUserSex() again
        }
        else if(std::find(female.begin(), female.end(), sexInput) != female.end()) return true; // User sex is female, return true
        else if(std::find(male.begin(), male.end(), sexInput) != male.end()) return false; // User sex is male, return false
        else {
            throw std::invalid_argument("Niepoprawna plec, sprobuj ponownie.\n"); // User input is not valid, throw exception
        }
    }

    int _SetUserAge(){
        int ageInput; // User input for age
        std::cout<<"Podaj swoj wiek:\n";
        std::cin>>ageInput;
        if(ageInput < 5 || ageInput > 149) throw std::invalid_argument("Niepoprawny wiek, wiek powinien byc mniejszy niz 150 i nie mniejszy niz 5 sprobuj ponownie.\n"); // User input is not valid, throw exception
        else return ageInput; // Return age inputed by user
    }

    int _SetUserHeight(){
        int heightInput; // User input for height
        std::cout<<"Podaj swoj wzrost w centymetrach:\n";
        std::cin>>heightInput;
        if(heightInput < 20 || heightInput > 300) throw std::invalid_argument("Niepoprawny wzrost, wzrost powinien byc wiekszy badz rowny 20 cm i mniejszy badz rowny 300 cm. Sprobuj ponownie.\n"); // User input is not valid, throw exception
        else return heightInput; // Return height inputed by user
    }
    
    int _SetUserMass(){
        int massInput; // User input for mass
        std::cout<<"Podaj mase swojego ciala w kg:\n";
        std::cin>>massInput;
        if(massInput <= 0) throw std::invalid_argument("Niepoprawna masa, masa powinna byc wieksza niz 0. Sprobuj ponownie.\n"); // User input is not valid, throw exception
        else return massInput; // Return mass inputed by user
    }
    
    public:
        User(){
            bool isSexSet = false;
            while(!isSexSet){ // Continue if user's sex is not set
                try
                {
                    _sex = _SetUserSex(); // Sets user's sex
                    isSexSet = true; // Stops while loop from repeating
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; } // Prints error message, while loop repeats
            }
            bool isAgeSet = false;
            while(!isAgeSet){ // Continue if user's age is not set
                try
                {
                    _age = _SetUserAge(); // Sets user's age
                    isAgeSet = true; // Stops while loop from repeating
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; } // Prints error message, while loop repeats
            }
            bool isHeightSet = false;
            while(!isHeightSet){ // Continue if user's height is not set
                try
                {
                    _height = _SetUserHeight(); // Sets user's height
                    isHeightSet = true; // Stops while loop from repeating
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; } // Prints error message, while loop repeats
            }
            bool isMassSet = false;
            while(!isMassSet){ // Continue if user's mass is not set
                try
                {
                    _mass = _SetUserMass(); // Sets user's mass
                    isMassSet = true; // Stops while loop from repeating
                }
                catch(const std::invalid_argument error_message){ std::cerr << error_message.what() << '\n'; } // Prints error message, while loop repeats
            }
        }
        void CalculateBMR(){ // Calculates user's BMR using Mifflin St Jeor equation and prints it
            int s; // This variable in Mifflin St Jeor equation is called s aswell, I don't know how to name other than that
            if(_sex) s = -161; // If female s = -161
            else s = 5; // If male s = 5
            double bmr = _mass * 10 + _height * 6.25 - _age * 5 + s; // Mifflin St Jeor equation
            std::cout << "Twoje BMR wynosi " << bmr << " kcal.\n";
        }
};

int main(){
    std::cout<<"Welcome to the BMR calculator!\n";
    getDate(); // Get and print current date
    User user; // Create User object
    user.CalculateBMR(); // Calculate user's BMR
    
    return 0;
}