//
// Created by ola on 02.11.2019.
//

#include "transit.hpp"
#include <iostream>
#include <limits>

double Transit::get_percentageTransit(){
    return this->percentageTransit;
}
double Transit::get_percentageTransitOfAll(){
    return this->percentageTransitOfAll;
}
int Transit::get_nrTransitPassengers(){
    return this->nrTransitPassengers;
}
void Transit::set_nrTransitPassengers(int _nrTransitPassengers){
    nrTransitPassengers = _nrTransitPassengers;
}
void Transit::set_isPassportNeeded(bool _passportNeeded){
    passportNeeded = _passportNeeded;
}
bool Transit::isPassportNeeded() {
    return this->passportNeeded;
}

void Transit::set_budget(int _budget){
    budget = _budget;
}

int Transit::get_budget() {
    return this->budget;
}


Transit::Transit(std::string _name):
    Transport(_name),
    AllTypes("trail"){
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
    std::cin >> this->nrTransitPassengers;
    std::cout << "What's your budget?" << std::endl;
    std::cin >> this->budget;
    percentageTransitOfAll = (((double)nrTransitPassengers)/nrAllPassengers)*100;
    percentageTransit = (((double)nrTransitPassengers)/nrPassengers)*100;



}

Transit::Transit(std::string _name, long long int _income, int _nrAllPassengers, short int _costOfTravel, int _nrPassengers, bool _passportNeeded, int _budget, int _nrTransitPassengers):
Transport(_name, _income, _nrAllPassengers),
AllTypes("trail", _costOfTravel, _nrPassengers)
{
    passportNeeded = _passportNeeded;
    budget = _budget;
    nrTransitPassengers = _nrTransitPassengers;
    percentageTransitOfAll = (((double)nrTransitPassengers)/nrAllPassengers)*100;
    percentageTransit = (((double)nrTransitPassengers)/nrPassengers)*100;

}

void Transit::print(std::ostream &out) {
    std::string pass;
    if (isPassportNeeded()){
        pass = "true";
    }
    else{
        pass = "false";
    }
    out << "Name: " << std::endl << get_name() << std::endl << "Type of transport: " << std::endl << get_nameOfType() << std::endl <<
    "Number of transit passengers: " << std::endl << get_nrTransitPassengers() << std::endl << "Number of trail passengers: " << std::endl <<
     get_nrPassengers() << std::endl << "Number of all passengers: " << std::endl << get_nrAllPassengers() << std::endl << "Percentage of all transit passengers among all trail passengers: "
     << std::endl << get_percentageTransit() << std::endl << "Percentage of all trail passengers among all passengers: " << std::endl << get_percentage() << std::endl <<
     "Percentage of all transit passengers among all passengers: " << std::endl << get_percentageTransitOfAll() << std::endl << "Given budget: " << std::endl << get_budget() << std::endl
     << "Cost of travelling: " << std::endl << get_costOfTravel() << std::endl << "Income that the transport's creating for the national budget: " << std::endl <<
     get_income() << std::endl << "Is your passport needed? " << std::endl <<  pass << std::endl;
}

void Transit::modify() {
    int choose;
    bool f = true;
    while (f) {
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
                percentageTransitOfAll = (((double)nrTransitPassengers)/nrAllPassengers)*100;
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
                percentageTransit = (((double)nrTransitPassengers)/nrPassengers)*100;
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
                set_nrTransitPassengers(nrPassengersHere);
                percentageTransitOfAll = (((double)nrTransitPassengers)/nrAllPassengers)*100;
                percentageTransit = (((double)nrTransitPassengers)/nrPassengers)*100;
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

