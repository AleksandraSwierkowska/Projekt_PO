//
// Created by ola on 02.11.2019.
//

#include "international.hpp"
#include <iostream>
#include <limits>

double International::get_percentageInternational(){
    return this->percentageInternational;
}
double International::get_percentageInternationalOfAll(){
    return this->percentageInternationalOfAll;
}
int International::get_nrInternationalPassengers(){
    return this->nrInternationalPassengers;
}
void International::set_nrInternationalPassengers(int _nrInternationalPassengers){
    nrInternationalPassengers = _nrInternationalPassengers;
}
void International::set_isPassportNeeded(bool _passportNeeded){
    passportNeeded = _passportNeeded;
}
bool International::isPassportNeeded() {
    return this->passportNeeded;
}

void International::set_budget(int _budget){
    budget = _budget;
}


International::International(std::string _name):
Transport(_name),
AllTypes("road"){
    std::cout << R"(Is the passport needed? Please type "yes" or "no".)" << std::endl;
    std::string answer;
    while(true){
        std::cin >> answer;
        if (answer == "yes"){
            this -> passportNeeded = true;
            break;
        }
        else if (answer == "no"){
            this -> passportNeeded = false;
            break;
        }
        else{
            std::cout << R"(Is the passport needed? Please type "yes" or "no".)" << std::endl;
        }
    }

    std::cout << "How many passengers use this specific kind of transport?" << std::endl;
    std::cin >> this->nrInternationalPassengers;
    std::cout << "What's your budget?" << std::endl;
    std::cin >> this->budget;
    percentageInternationalOfAll = (((double)nrInternationalPassengers)/nrAllPassengers)*100;
    percentageInternational = (((double)nrInternationalPassengers)/nrPassengers)*100;



}

International::International(std::string _name, long long int _income, int _nrAllPassengers, unsigned short int _costOfTravel, int _nrPassengers, bool _passportNeeded, int _budget, int _nrInternationalPassengers):
Transport(_name, _income, _nrAllPassengers),
AllTypes("road", _costOfTravel, _nrPassengers)
{
passportNeeded = _passportNeeded;
budget = _budget;
budget = _budget;
nrInternationalPassengers = _nrInternationalPassengers;
percentageInternationalOfAll = (((double)nrInternationalPassengers)/nrAllPassengers)*100;
percentageInternational = (((double)nrInternationalPassengers)/nrPassengers)*100;

}

int International::get_budget() {
    return this->budget;
}

void International::print(std::ostream &out) {
    std::string pass;
    if (isPassportNeeded()){
        pass = "true";
    }
    else{
        pass = "false";
    }
    out <<  "Name: " << std::endl << get_name() << std::endl << "Type of transport: " << std::endl << get_nameOfType() << std::endl <<
        "Number of international passengers: " << std::endl << get_nrInternationalPassengers() << std::endl << "Number of international passengers: " << std::endl <<
        get_nrPassengers() << std::endl << "Number of all passengers: " << std::endl << get_nrAllPassengers() << std::endl << "Percentage of all international passengers among all road passengers: "
        << std::endl << get_percentageInternational() << std::endl << "Percentage of all road passengers among all passengers: " << std::endl << get_percentage() << std::endl <<
        "Percentage of all international passengers among all passengers: " << std::endl << get_percentageInternationalOfAll() << std::endl << "Given budget: " << std::endl << get_budget() << std::endl
        << "Cost of travelling: " << std::endl << get_costOfTravel() << std::endl << "Income that the transport's creating for the national budget: " << std::endl <<
        get_income() << std::endl << "Is your passport needed? " << std::endl << pass << std::endl;

}

void International::modify() {
    int choose;
    bool f = true;
    while(f) {
        std::cout << "Which of the following do you want to modify (choose a number): 1. Income 2. Number of all passengers 3. Cost of the travel "
                     "4. Number of passengers using that type of transport 5. Is passport needed? 6. Your budget 7. Number of passengers in this specific type of transport 8. Exit." << std::endl;
        std::cin >> choose;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choose) {
            case 1:
                long long int income;
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> income;
                set_income(income);
                break;
            case 2:
                int nrAllPassengers;
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> nrAllPassengers;
                set_nrAllPassengers(nrAllPassengers);
                percentageInternationalOfAll = (((double)nrInternationalPassengers)/nrAllPassengers)*100;
                set_percentage();
                break;
            case 3:
                std::cout << "Set a new value, please" << std::endl;
                set_costOfTravel();
                break;
            case 4:
                int nrPassengers;
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> nrPassengers;
                set_nrPassengers(nrPassengers);
                percentageInternational = (((double)nrInternationalPassengers)/nrPassengers)*100;
                set_percentage();
                break;
            case 5:
                {bool passport;
                std::cout << R"(Is the passport needed? Please type "yes" or "no".)" << std::endl;
                std::string answer;
                while(true) {
                    std::cin >> answer;
                    if (answer == "yes") {
                        passport = true;
                        break;
                    } else if (answer == "no") {
                        passport = false;
                        break;
                    } else {
                        std::cout << R"(Is the passport needed? Please type "yes" or "no".)" << std::endl;
                    }
                }
                set_isPassportNeeded(passport);
                break;}
            case 6:
                int budg; //budget
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> budg;
                set_budget(budg);
                break;
            case 7:
                int nrPassengersHere;
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> nrPassengersHere;
                set_nrInternationalPassengers(nrPassengersHere);
                percentageInternationalOfAll = (((double)nrInternationalPassengers)/nrAllPassengers)*100;
                percentageInternational = (((double)nrInternationalPassengers)/nrPassengers)*100;
                break;
            case 8:
                f = false;
                break;
            default:
                std::cout << "The given number wasn't correct, try again." << std::endl;
                std::cin >> choose;
        }
    }
}

