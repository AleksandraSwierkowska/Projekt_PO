//
// Created by ola on 02.11.2019.
//

#include "river.hpp"
#include <iostream>
#include <limits>

double River::get_percentageRiver(){
    return this->percentageRiver;
}
double River::get_percentageRiverOfAll(){
    return this->percentageRiverOfAll;
}
int River::get_nrRiverPassengers(){
    return this->nrRiverPassengers;
}
void River::set_nrRiverPassengers(int _nrRiverPassengers){
    nrRiverPassengers = _nrRiverPassengers;
}

void River::set_budget(int _budget){
    budget = _budget;
}

River::River(std::string _name) :
Transport(_name),
AllTypes<int>("water"){
    std::cout << "How many passengers use this specific kind of transport?" << std::endl;
    std::cin >> this->nrRiverPassengers;
    std::cout << "What's your budget?" << std::endl;
    std::cin >> this->budget;
    percentageRiver = (((double)nrRiverPassengers)/nrPassengers)*100;
    percentageRiverOfAll = (((double)nrRiverPassengers)/nrAllPassengers)*100;

}

River::River(std::string _name, long long int _income, int _nrAllPassengers, int _costOfTravel, int _nrPassengers, int _budget, int _nrRiverPassengers):
Transport(_name),
AllTypes("water", _costOfTravel, _nrPassengers) {
    budget = _budget;
    nrRiverPassengers = _nrRiverPassengers;
    percentageRiver = (((double)nrRiverPassengers)/nrPassengers)*100;
    percentageRiverOfAll = (((double)nrRiverPassengers)/nrAllPassengers)*100;
}

int River::get_budget() {
    return this->budget;
}

void River::print(std::ostream &out) {
    out << "Name: " << std::endl << get_name() << std::endl << "Type of transport: " << std::endl << get_nameOfType() << std::endl <<
        "Number of river passengers: " << std::endl << get_nrRiverPassengers() << std::endl << "Number of water passengers: " << std::endl <<
        get_nrPassengers() << std::endl << "Number of all passengers: " << std::endl << get_nrAllPassengers() << std::endl << "Percentage of all river passengers among all water passengers: "
        << std::endl << get_percentageRiver() << std::endl << "Percentage of all water passengers among all passengers: " << std::endl << get_percentage() << std::endl <<
        "Percentage of all river passengers among all passengers: " << std::endl << get_percentageRiverOfAll() << std::endl << "Given budget: " << std::endl << get_budget() << std::endl
        << "Cost of travelling: " << std::endl << get_costOfTravel() << std::endl << "Income that the transport's creating for the national budget: " << std::endl << get_income() << std::endl;
}

void River::modify() {
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
                percentageRiverOfAll = (((double)nrRiverPassengers)/nrAllPassengers)*100;
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
                percentageRiver = (((double)nrRiverPassengers)/nrPassengers)*100;
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
                set_nrRiverPassengers(nrPassengersHere);
                percentageRiverOfAll = (((double)nrRiverPassengers)/nrAllPassengers)*100;
                percentageRiver = (((double)nrRiverPassengers)/nrPassengers)*100;
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
