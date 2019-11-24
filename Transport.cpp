//
// Created by ola on 01.11.2019.
//

#include "Transport.hpp"
#include <iostream>
#include <utility>

long long int Transport::get_income() {
    return this->income;
}
void Transport::set_income(long long int _income) {
    income = _income;
}

std::string Transport::get_name(){
    return this->name;
}

int Transport::get_nrAllPassengers() {
    return this->nrAllPassengers;
}

void Transport::set_nrAllPassengers(int _nrAllPassengers) {
    nrAllPassengers = _nrAllPassengers;
}

Transport::Transport() {}

Transport::Transport(std::string _name) {
    name = _name;
    //wrocic do tego
    std::cout << "What's the income of that type of transport?" << std::endl;
    std::cin >> this->income;
    std::cout << "How many passengers use any kind of transport?" << std::endl;
    std::cin >> this->nrAllPassengers;
}

Transport::Transport(std::string _name, long long int _income, int _nrAllPassengers) {
    name = _name;
    income = _income;
    nrAllPassengers = _nrAllPassengers;
}

Transport::~Transport() = default;

std::ostream &operator<<(std::ostream &out, Transport &object) {
    object.print(out);
    return out;
}

