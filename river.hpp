//
// Created by ola on 02.11.2019.
//

#ifndef PO_RIVER_HPP
#define PO_RIVER_HPP


#include "AllTypes.hpp"

class River:
        public AllTypes<int>{
    private:
        double percentageRiver;
        double percentageRiverOfAll;
        int budget;
    protected:
        int nrRiverPassengers;
    public:
        River(std::string);
        River(std::string, long long int, int, int, int, int, int);
        void print(std::ostream& out) override;
        double get_percentageRiver();
        double get_percentageRiverOfAll();
        int get_nrRiverPassengers();
        void set_nrRiverPassengers(int);
        void set_budget(int);
        int get_budget();
        void modify();
};


#endif //PO_RIVER_HPP
