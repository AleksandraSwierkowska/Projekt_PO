//
// Created by ola on 01.11.2019.
//

#ifndef PO_TRANSPORT_HPP
#define PO_TRANSPORT_HPP
#include <string>

class Transport {
    private:
        long long int income;
        std::string name;
    protected:
        int nrAllPassengers;
        virtual void print(std::ostream& out) = 0;
    public:
        Transport();
        Transport(std::string);
        Transport(std::string, long long int, int);
        virtual ~Transport();
        friend std::ostream&operator<<(std::ostream& out, Transport& object);
        long long int get_income();
        void set_income(long long int);
        int get_nrAllPassengers();
        void set_nrAllPassengers(int);
        std::string get_name();
        virtual void modify() = 0;

};


#endif //PO_TRANSPORT_HPP
