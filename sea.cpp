//
// Created by ola on 02.11.2019.
//

#include "sea.hpp"
#include <iostream>
#include <limits>

double Sea::get_percentageSea(){
    return this->percentageSea;
}
double Sea::get_percentageSeaOfAll(){
    return this->percentageSeaOfAll;
}
int Sea::get_nrSeaPassengers(){
    return this->nrSeaPassengers;
}
void Sea::set_nrSeaPassengers(int _nrSeaPassengers){
    nrSeaPassengers = _nrSeaPassengers;
}

void Sea::set_budget(int _budget){
    budget = _budget;
}


Sea::Sea(std::string _name) :
Transport(_name),
AllTypes<int>("water"){
    std::cout << "How many passengers use this specific kind of transport?" << std::endl;
    std::cin >> this->nrSeaPassengers;
    std::cout << "What's your budget?" << std::endl;
    std::cin >> this->budget;
    percentageSea = (((double)nrSeaPassengers)/nrPassengers)*100;
    percentageSeaOfAll = (((double)nrSeaPassengers)/nrAllPassengers)*100;

}

Sea::Sea(std::string _name, long long int _income, int _nrAllPassengers, int _costOfTravel, int _nrPassengers, int _budget, int _nrSeaPassengers):
Transport(_name, _income, _nrAllPassengers),
AllTypes("water", _costOfTravel, _nrPassengers) {
    budget = _budget;
    nrSeaPassengers = _nrSeaPassengers;
    percentageSea = (((double)nrSeaPassengers)/nrPassengers)*100;
    percentageSeaOfAll = (((double)nrSeaPassengers)/nrAllPassengers)*100;
}

int Sea::get_budget() {
    return this->budget;
}

void Sea::print(std::ostream &out) {
    out << "Name: " << std::endl << get_name() << std::endl << "Type of transport: " << std::endl << get_nameOfType() << std::endl <<
        "Number of sea passengers: " << std::endl << get_nrSeaPassengers() << std::endl << "Number of water passengers: " << std::endl <<
        get_nrPassengers() << std::endl << "Number of all passengers: " << std::endl << get_nrAllPassengers() << std::endl << "Percentage of all sea passengers among all water passengers: "
        << std::endl << get_percentageSea() << std::endl << "Percentage of all water passengers among all passengers: " << std::endl << get_percentage() << std::endl <<
        "Percentage of all sea passengers among all passengers: " << std::endl << get_percentageSeaOfAll() << std::endl << "Given budget: " << std::endl << get_budget() << std::endl
        << "Cost of travelling: " << std::endl << get_costOfTravel() << std::endl << "Income that the transport's creating for the national budget: " << std::endl <<
        get_income() << std::endl;

}

void Sea::modify() {
    int choose;
    bool f = true;
    while(f) {
        std::cout << "Which of the following do you want to modify (choose a number): 1. Income 2. Number of all passengers 3. Cost of the travel "
                     "4. Number of passengers using that type of transport 5. Your budget 6. Number of passengers in this specific type of transport 7. Exit." << std::endl;
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
                percentageSeaOfAll = (((double)nrSeaPassengers)/nrAllPassengers)*100;
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
                percentageSea = (((double)nrSeaPassengers)/nrPassengers)*100;
                set_percentage();
               break;
            case 5:
                int budg; //budget
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> budg;
                set_budget(budg);
              break;
            case 6:
                int nrPassengersHere;
                std::cout << "Set a new value, please" << std::endl;
                std::cin >> nrPassengersHere;
                set_nrSeaPassengers(nrPassengersHere);
                percentageSeaOfAll = (((double)nrSeaPassengers)/nrAllPassengers)*100;
                percentageSea = (((double)nrSeaPassengers)/nrPassengers)*100;
                break;
            case 7:
                f = false;
                break;
            default:
                std::cout << "The given number wasn't correct, try again." << std::endl;
                std::cin >> choose;
        }
    }
}
