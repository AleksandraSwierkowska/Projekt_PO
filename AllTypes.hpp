//
// Created by ola on 01.11.2019.
//

#ifndef PO_ALLTYPES_HPP
#define PO_ALLTYPES_HPP
#include <string>
#include <iostream>
#include "Transport.hpp"

template <class T>
class AllTypes : public virtual Transport {
private:
    double percentageOfAll;
    std::string nameOfType;
protected:
    T costOfTravel;
    int nrPassengers;
public:
    AllTypes(std::string);
    AllTypes(std::string, T, int);
    AllTypes(std::string, long long int, int, std::string, T, int);
    double get_percentage();
    void set_percentage();
    std::string get_nameOfType();
    void set_costOfTravel();
    T get_costOfTravel();
    int get_nrPassengers();
    void set_nrPassengers(int);
};

template <class T>
double AllTypes<T>::get_percentage(){
    return this->percentageOfAll;
}

template<class T>
void AllTypes<T>::set_percentage() {
    percentageOfAll = (((double)nrPassengers)/(nrAllPassengers))*100;
}

template <class T>
std::string AllTypes<T>::get_nameOfType() {
    return this->nameOfType;
}

template <class T>
T AllTypes<T>::get_costOfTravel() {
    return this->costOfTravel;
}

template <class T>
void AllTypes<T>::set_costOfTravel(){
    std::cin >> this->costOfTravel;
}

template<class T>
int AllTypes<T>::get_nrPassengers() {
    return this->nrPassengers;
}

template<class T>
void AllTypes<T>::set_nrPassengers(int _nrPassengers) {
    nrPassengers = _nrPassengers;
}

template<class T>
AllTypes<T>::AllTypes(std::string _name, long long int _income, int _nrAllPassengers, std::string _nameOfType, T _costOfTravel, int _nrPassengers):
    Transport(_name, _income, _nrAllPassengers)
    {
    nameOfType = _nameOfType;
    costOfTravel = _costOfTravel;
    nrPassengers = _nrPassengers;
    percentageOfAll = ((double)nrPassengers)/(nrAllPassengers)*100;
}

template<class T>
AllTypes<T>::AllTypes(std::string _nameOfType, T _costOfTravel, int _nrPassengers):
Transport()
{
    nameOfType = _nameOfType;
    costOfTravel = _costOfTravel;
    nrPassengers = _nrPassengers;
    percentageOfAll = (((double)nrPassengers)/(nrAllPassengers))*100;
}

template<class T>
AllTypes<T>::AllTypes(std:: string _nameOfType):
Transport()
    {
    nameOfType = _nameOfType;
    std::cout << "The following questions pertain to the " + nameOfType + " transport." << std::endl;
    std::cout << "What's the cost of travel using that type of transport?" << std::endl;
    std::cin >> this->costOfTravel;
    std::cout << "How many passengers use that type of transport?" << std::endl;
    std::cin >> this->nrPassengers;
    percentageOfAll = (nrPassengers/(nrAllPassengers))*100;
}




#endif //PO_ALLTYPES_HPP
