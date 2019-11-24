//
// Created by ola on 02.11.2019.
//

#ifndef PO_INTERNATIONAL_HPP
#define PO_INTERNATIONAL_HPP
#include "AllTypes.hpp"

class International:
        public AllTypes<unsigned short int>{
private:
    double percentageInternationalOfAll;
    double percentageInternational;
    bool passportNeeded;
    int budget;
protected:
    int nrInternationalPassengers;
public:
    International(std::string);
    International(std::string, long long int, int, unsigned short int, int, bool, int, int);
    void print(std::ostream& out) override;
    double get_percentageInternational();
    double get_percentageInternationalOfAll();
    int get_nrInternationalPassengers();
    void set_nrInternationalPassengers(int);
    void set_isPassportNeeded(bool);
    bool isPassportNeeded();
    void set_budget(int);
    int get_budget();
    void modify();
};



#endif //PO_INTERNATIONAL_HPP
