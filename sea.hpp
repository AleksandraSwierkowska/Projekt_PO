//
// Created by ola on 02.11.2019.
//

#ifndef PO_SEA_HPP
#define PO_SEA_HPP
#include "AllTypes.hpp"

class Sea:
        public AllTypes<int>{
private:
    double percentageSea;
    double percentageSeaOfAll;
    int budget;
protected:
    int nrSeaPassengers;
public:
    Sea(std::string);
    Sea(std::string, long long int, int, int, int, int, int);
    void print(std::ostream& out) override;
    double get_percentageSea();
    double get_percentageSeaOfAll();
    int get_nrSeaPassengers();
    void set_nrSeaPassengers(int);
    void set_budget(int);
    int get_budget();
    void modify();
};



#endif //PO_SEA_HPP
