//
// Created by ola on 02.11.2019.
//

#ifndef PO_TRANSIT_HPP
#define PO_TRANSIT_HPP
#include "AllTypes.hpp"

class Transit:
        public AllTypes<short int>{
    private:
        double percentageTransitOfAll;
        double percentageTransit;
        bool passportNeeded;
        int budget;
    protected:
        int nrTransitPassengers;
    public:
        Transit(std::string);
        Transit(std::string, long long int, int, short int, int, bool, int, int);
        void print(std::ostream& out) override;
        double get_percentageTransit();
        double get_percentageTransitOfAll();
        int get_nrTransitPassengers();
        void set_nrTransitPassengers(int);
        void set_isPassportNeeded(bool);
        bool isPassportNeeded();
        void set_budget(int);
        int get_budget();
        void modify();
};


#endif //PO_TRANSIT_HPP

