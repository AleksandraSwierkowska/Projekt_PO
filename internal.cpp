//
// Created by ola on 02.11.2019.
//

#include "internal.hpp"
#include <iostream>
#include <limits>

double Internal::get_percentageInternal(){
    return this->percentageInternal;
}
double Internal::get_percentageInternalOfAll(){
    return this->percentageInternalOfAll;
}
int Internal::get_nrInternalPassengers(){
    return this->nrInternalPassengers;
}
void Internal::set_nrInternalPassengers(int _nrInternalPassengers){
    nrInternalPassengers = _nrInternalPassengers;
}

void Internal::set_budget(int _budget){
    budget = _budget;
}

Internal::Internal(std::string _name) :
Transport(_name), AllTypes<int short>("trail"), AllTypes<unsigned short int>("road")
{
    std::cout << "How many passengers use this specific kind of transport?" << std::endl;
    std::cin >> this->nrInternalPassengers;
    std::cout << "What's your budget?" << std::endl;
    std::cin >> this->budget;
    percentageInternal = (((double)nrInternalPassengers)/(AllTypes<short int>::nrPassengers + AllTypes<unsigned short int>::nrPassengers))*100;
    percentageInternalOfAll =  (((double)nrInternalPassengers)/AllTypes<short int>::nrAllPassengers)*100;
}

Internal::Internal(std::string _name, long long int _income, int _nrAllPassengers, short int _costOfTravel1, unsigned short int _costOfTravel2, int _nrPassengers1, int _nrPassengers2, int _budget, int _nrInternalPassengers):
Transport(_name, _income, _nrAllPassengers), AllTypes<short int>("trail", _costOfTravel1, _nrPassengers1), AllTypes<unsigned short int>("road", _costOfTravel2, _nrPassengers2)
{
    budget = _budget;
    nrInternalPassengers = _nrInternalPassengers;
    percentageInternal = (((double)nrInternalPassengers)/(AllTypes<short int>::nrPassengers + AllTypes<unsigned short int>::nrPassengers))*100;
    percentageInternalOfAll =  (((double)nrInternalPassengers)/nrAllPassengers)*100;
}

int Internal::get_budget() {
    return this->budget;
}

void Internal::print(std::ostream &out) {
    out << "Name: " << std::endl << get_name() << std::endl << "Type of transport: " << std::endl << AllTypes<short int>::get_nameOfType() << std::endl <<
    AllTypes<unsigned short int>::get_nameOfType() << std::endl << "Number of internal passengers: " << std::endl << get_nrInternalPassengers() << std::endl << "Number of trail passengers: " << std::endl <<
    AllTypes<short int>::get_nrPassengers() << std::endl << "Number of road passengers: " << std::endl << AllTypes<unsigned short int>::get_nrPassengers() << std::endl << "Number of all passengers: " << std::endl << Transport::get_nrAllPassengers() << std::endl <<
    "Percentage of all internal passengers among all trail and road passengers: " << std::endl << get_percentageInternal() << std::endl << "Percentage of all trail passengers among all passengers: " << std::endl << ((double)(AllTypes<short int>::nrPassengers)/nrAllPassengers)*100
    << std::endl << "Percentage of all road passengers among all passengers: " << std::endl << ((double)(AllTypes<unsigned short int>::nrPassengers)/nrAllPassengers)*100 << std::endl << "Percentage of all internal passengers among all passengers: " <<
    std::endl << get_percentageInternalOfAll() << std::endl << "Given budget: " << std::endl << get_budget() << std::endl << "Cost of travelling by train: " << std::endl << AllTypes<short int>::get_costOfTravel() << std::endl <<
    "Cost of travelling by bus: " << std::endl << AllTypes<unsigned short int>::get_costOfTravel() << std::endl << "Income that the transport's creating for the national budget: " << std::endl << get_income() << std::endl;
}

void Internal::modify() {
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
                percentageInternalOfAll = (((double)nrInternalPassengers)/nrAllPassengers)*100;
                AllTypes<short int>::set_percentage();
                AllTypes<unsigned short int>::set_percentage();
                break;
            case 3:
                std::cout << "Give the cost of travelling by train, please" << std::endl;
                AllTypes<short int>::set_costOfTravel();
                std::cout << "Give the cost of travelling by car or by bus, please" << std::endl;
                AllTypes<unsigned short int>::set_costOfTravel();
                break;
            case 4:
                std::cout << "Give the number of passengers travelling by train, please" << std::endl;
                int nrPassengers;
                std::cin >> nrPassengers;
                AllTypes<short int>::set_nrPassengers(nrPassengers);
                AllTypes<short int>::set_percentage();
                std::cout << "Give the number of passengers travelling by car or by bus, please" << std::endl;
                int nrPassengers2;
                std::cin >> nrPassengers2;
                AllTypes<unsigned short int>::set_nrPassengers(nrPassengers2);
                AllTypes<unsigned short int>::set_percentage();
                percentageInternal = (((double)nrInternalPassengers)/(AllTypes<short int>::nrPassengers + AllTypes<unsigned short int>::nrPassengers))*100;
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
                set_nrInternalPassengers(nrPassengersHere);
                percentageInternal = (((double)nrInternalPassengers)/(AllTypes<short int>::nrPassengers + AllTypes<unsigned short int>::nrPassengers))*100;
                percentageInternalOfAll =  (((double)nrInternalPassengers)/nrAllPassengers)*100;
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
