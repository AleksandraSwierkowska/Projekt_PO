//
// Created by ola on 02.11.2019.
//

#ifndef PO_INTERNAL_HPP
#define PO_INTERNAL_HPP
#include "AllTypes.hpp"

class Internal:
        public AllTypes<short int>, public AllTypes<unsigned short int>{
private:
    double percentageInternal; //percentage of both road and rail transport since it counts both trains and cars
    double percentageInternalOfAll;
    int budget;
protected:
    int nrInternalPassengers;
public:
    Internal(std::string);
    Internal(std::string, long long int, int, short int, unsigned short int, int, int, int, int);
    void print(std::ostream& out) override ;
    double get_percentageInternal();
    double get_percentageInternalOfAll();
    int get_nrInternalPassengers();
    void set_nrInternalPassengers(int);
    void set_budget(int);
    int get_budget();
    void modify();
};


#endif //PO_INTERNAL_HPP
