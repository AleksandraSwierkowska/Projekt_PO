//
// Created by ola on 05.11.2019.
//
#include <bits/stdc++.h>
#include <iostream>
#include "nodeKeeper.hpp"
#include "node.hpp"
#include "transit.hpp"
#include "internal.hpp"
#include "sea.hpp"
#include "international.hpp"

NodeKeeper::NodeKeeper() {
    nodes = std::map<std::string, Node *>();
    std::vector<std::string> nodelist = std::vector<std::string>{"Transit", "Internal", "International", "Sea", "River"};
    Node *node1 = new Node("Transport", nodelist);
    std::pair<std::string, Node *> pair1 = {"Transport", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Transit", "Internal"};
    node1 = new Node("Trail", nodelist);
    pair1 = {"Trail", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Internal", "International"};
    node1 = new Node("Road", nodelist);
    pair1 = {"Road", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Sea", "River"};
    node1 = new Node("Water", nodelist);
    pair1 = {"Water", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Transit"};
    node1 = new Node("Transit", nodelist);
    pair1 = {"Transit", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Internal"};
    node1 = new Node("Internal", nodelist);
    pair1 = {"Internal", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"International"};
    node1 = new Node("International", nodelist);
    pair1 = {"International", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"Sea"};
    node1 = new Node("Sea", nodelist);
    pair1 = {"Sea", node1};
    nodes.insert(pair1);

    nodelist = std::vector<std::string>{"River"};
    node1 = new Node("River", nodelist);
    pair1 = {"River", node1};
    nodes.insert(pair1);


    currentNode = nodes["Transport"];

}

NodeKeeper::~NodeKeeper() {
    for (auto i : nodes){
        delete i.second;
    }
}

void NodeKeeper::CD(std::string _nameOfTheNode) {
    bool check = true;
    for (auto i : nodes){
        if (i.first == _nameOfTheNode){
            currentNode = nodes[_nameOfTheNode];
            std::cout << "Currently you're in the node called " + _nameOfTheNode + "." << std::endl;
            check = false;
            break;
        }
    }
    if (check){
        std::cout << "Sorry, there's no such node. You can see all the nodes by writing TREE" << std::endl;
    }

}

void NodeKeeper::MO(std::string _name) {
    if (currentNode->get_nameOfTheNode() != "Transport" && currentNode->get_nameOfTheNode() != "Rail" && currentNode->get_nameOfTheNode() != "Road" && currentNode->get_nameOfTheNode() != "Water") {
        currentNode->add(_name, currentNode->get_nameOfTheNode());
    }
    else{
        std::cout << "You cannot create a new object, the current node in not a leaf." << std::endl;
    }
}

void NodeKeeper::DO(std::string _name) {

    if (currentNode->get_nameOfTheNode() != "Transport" && currentNode->get_nameOfTheNode() != "Rail" && currentNode->get_nameOfTheNode() != "Road" && currentNode->get_nameOfTheNode() != "Water") {
        currentNode->del(_name);
    }
    else{
        std::cout << "You cannot delete the object, the current node in not a leaf." << std::endl;
    }


}

void NodeKeeper::MDO(std::string _name) {
    if (currentNode->get_nameOfTheNode() != "Transport" && currentNode->get_nameOfTheNode() != "Rail" && currentNode->get_nameOfTheNode() != "Road" && currentNode->get_nameOfTheNode() != "Water") {
        currentNode->modify(_name);
    }
    else{
        std::cout << "You cannot modify the object, the current node in not a leaf." << std::endl;
    }
}

void NodeKeeper::DIR() {
    std::cout << currentNode->get_nameOfTheNode() + ": " << std::endl;
    for(auto i :  currentNode->get_availableLeafList())
    {
        for(auto const& j : nodes[i]->get_objects())
        {
           std::cout << j.first << std::endl;
        }
    }
}

void NodeKeeper::SHOW(std::string _name) {
    for(auto i :  nodes["Transport"]->get_availableLeafList())
    {
        for(auto const& j : nodes[i]->get_objects())
        {
            if (j.first == _name){
                std::cout << *j.second << std::endl;
                return;
            }
        }
    }
    std::cout << "There's no such object." << std::endl;
    }


void NodeKeeper::READ() {
    std::string nameFile;
    std::cout << "Which file do you want to open?" << std::endl;
    std::cin >> nameFile;
    std::ifstream input(nameFile);
    if (!input){
        std::cout << "The path to the file is incorrect." << std::endl;
        return;
    }
    std::string type = currentNode->get_nameOfTheNode();
    std::string _name;
    std::string temp;
    getline(input, temp);
    getline(input, _name);
    while(!_name.empty()){
        std::pair<std::string, Transport*> pair;
        Transport *object;
        if(type == "Transit"){
            long long int _income;
            int _nrAllPassengers;
            short int _costOfTravel;
            int _nrPassengers;
            bool _passportNeeded;
            std::string pass;
            int _budget;
            int _nrTransitPassengers;
            for(int i = 0; i < 3; i++){
                getline(input, temp);
            }
            input >>_nrTransitPassengers;
            input.get();
            getline(input, temp);
            input >> _nrPassengers;
            input.get();
            getline(input, temp);
            input >> _nrAllPassengers;
            input.get();
            for (int i = 0; i < 7; i++){
                getline(input, temp);
            }
            input >> _budget;
            input.get();
            getline(input, temp);
            input >> _costOfTravel;
            input.get();
            getline(input, temp);
            input >> _income;
            input.get();
            getline(input, temp);
            input >> pass;
            if (pass.compare("false") == 0){
                _passportNeeded = false;
            }
            else {
                _passportNeeded = true;
            }
            input.get();
            temp.clear();
            object = new Transit(_name, _income, _nrAllPassengers, _costOfTravel, _nrPassengers, _passportNeeded, _budget, _nrTransitPassengers);
        }
        else if(type == "Internal"){
            long long int _income;
            int _nrAllPassengers;
            short int _costOfTravel1;
            unsigned short int _costOfTravel2;
            int _nrPassengers1;
            int _nrPassengers2;
            int _budget;
            int _nrInternalPassengers;
            for(int i = 0; i < 4; i++){
                getline(input, temp);}
            input >>_nrInternalPassengers;
            input.get();
            getline(input, temp);
            input >> _nrPassengers1;
            input.get();
            getline(input, temp);
            input >> _nrPassengers2;
            input.get();
            getline(input, temp);
            input >> _nrAllPassengers;
            input.get();
            for (int i = 0; i < 9; i++){
                getline(input, temp);
            }
            input >> _budget;
            input.get();
            getline(input, temp);
            input >> _costOfTravel1;
            input.get();
            getline(input, temp);
            input >> _costOfTravel2;
            input.get();
            getline(input, temp);
            input >> _income;
            input.get();
            temp.clear();
            object = new Internal(_name, _income, _nrAllPassengers, _costOfTravel1, _costOfTravel2, _nrPassengers1, _nrPassengers2,  _budget, _nrInternalPassengers);


        }
        else if(type == "International"){
            long long int _income;
            int _nrAllPassengers;
            unsigned short int _costOfTravel;
            int _nrPassengers;
            bool _passportNeeded;
            std::string pass;
            int _budget;
            int _nrInternationalPassengers;
            for(int i = 0; i < 3; i++){
                getline(input, temp);}
            input >>_nrInternationalPassengers;
            input.get();
            getline(input, temp);
            input >> _nrPassengers;
            input.get();
            getline(input, temp);
            input >> _nrAllPassengers;
            input.get();
            for (int i = 0; i < 7; i++){
                getline(input, temp);
            }
            input >> _budget;
            input.get();
            getline(input, temp);
            input >> _costOfTravel;
            input.get();
            getline(input, temp);
            input >> _income;
            input.get();
            getline(input, temp);
            input >> pass;
            if (pass.compare("false") == 0){
                _passportNeeded = false;
            }
            else {
                _passportNeeded = true;
            }
            input.get();
            temp.clear();
            object = new International(_name, _income, _nrAllPassengers, _costOfTravel, _nrPassengers, _passportNeeded, _budget, _nrInternationalPassengers);

        }

        else if(type == "Sea"){
            long long int _income;
            int _nrAllPassengers;
            int _costOfTravel;
            int _nrPassengers;
            int _budget;
            int _nrSeaPassengers;
            for(int i = 0; i < 3; i++){
                    getline(input, temp);}
            input >>_nrSeaPassengers;
            input.get();
            getline(input, temp);
            input >> _nrPassengers;
            input.get();
            getline(input, temp);
            input >> _nrAllPassengers;
            input.get();
            for (int i = 0; i < 7; i++){
                getline(input, temp);
            }
            input >> _budget;
            input.get();
            getline(input, temp);
            input >> _costOfTravel;
            input.get();
            getline(input, temp);
            input >> _income;
            input.get();
            getline(input, temp);
            input.get();
            temp.clear();
            object = new Sea(_name, _income, _nrAllPassengers, _costOfTravel, _nrPassengers,  _budget, _nrSeaPassengers);
        }
        else if(type == "River"){
            long long int _income;
            int _nrAllPassengers;
            int _costOfTravel;
            int _nrPassengers;
            int _budget;
            int _nrRiverPassengers;
            for(int i = 0; i < 3; i++){
                        getline(input, temp);}
            input >>_nrRiverPassengers;
            input.get();
            getline(input, temp);
            input >> _nrPassengers;
            input.get();
            getline(input, temp);
            input >> _nrAllPassengers;
            input.get();
            for (int i = 0; i < 7; i++){
                getline(input, temp);
            }
            input >> _budget;
            input.get();
            getline(input, temp);
            input >> _costOfTravel;
            input.get();
            getline(input, temp);
            input >> _income;
            input.get();
            getline(input, temp);
            input.get();
            temp.clear();
            object = new Sea(_name, _income, _nrAllPassengers, _costOfTravel, _nrPassengers,  _budget, _nrRiverPassengers);

        }
        else{
            std::cout << "Change the current node, please." << std::endl;
        }
        pair = {_name, object};
        currentNode->add_objects(pair);
        _name.clear();
        getline(input, temp);
        getline(input, _name);

    }
}

void NodeKeeper::SAVE() {
    if (currentNode->get_nameOfTheNode() != "Transport" && currentNode->get_nameOfTheNode() != "Rail" && currentNode->get_nameOfTheNode() != "Road" && currentNode->get_nameOfTheNode() != "Water") {
        std::string nameFile;
        std::cout << "Where do you want to save this?" << std::endl;
        std::cin >> nameFile;
        std::ofstream output(nameFile);
        for(auto const& i :  currentNode->get_availableLeafList())
        {
            for(auto const& j : nodes[i]->get_objects())
            {
                output << *j.second;
            }
        }
    }
    else{
        std::cout << "You cannot save the objects, the current node in not a leaf." << std::endl;
    }
}

void NodeKeeper::TREE() {
    using namespace std;
    cout << "                                   "  << endl;
    cout << "                               Transport                               " << endl;
    cout << "                              /    |     \\ " << endl;
    cout << "                             /     |      -------- " << endl;
    cout << "                            /      |              \\ " << endl;
    cout << "                           /       |               \\ " << endl;
    cout << "                          /        |                \\ " << endl;
    cout << "                      Rail      Road               Water " << endl;
    cout << R"(                     /   \     /    \               /  \ )" << endl;
    cout << R"(                    /     \   /      \             /    \ )" << endl;
    cout << "                Transit   Internal  International  Sea  River" << endl;
    cout << "                                   "  << endl;
}

void NodeKeeper::program(){
    std::cout << "Welcome in the transport program!" << std::endl;
    std::cout << "Currently you're in the main node - Transport" << std::endl;
    std::cout << "Other possible nodes are Rail, Road, Water, Transit, Internal, International, Sea, River." << std::endl;
    while(true){
        std::cout << "Choose one of the possible commends: CD, MO, DO, MDO, DIR, SHOW, SAVE, READ, TREE, EXIT.:" << std::endl;
        std::string commend;
        std::cin >> commend;
        if (commend == "DIR"){
            DIR();
        }
        else if (commend == "SAVE"){
            SAVE();
        }
        else if (commend == "READ"){
            READ();
        }
        else if (commend == "TREE"){
            TREE();
        }
        else if (commend == "EXIT"){
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::vector <std::string> tokens;
            std::stringstream check1(commend); //allows me to treat string as stream
            std::string text;
            while(getline(check1, text, '(')){
                tokens.push_back(text);
            }
            if (tokens.size() > 1){
                tokens[1].pop_back(); //remove last )
                if (tokens[0] == "CD"){
                    CD(tokens[1]);
                }
                else if (tokens[0] == "MO"){
                    MO(tokens[1]);
                }
                else if (tokens[0] == "DO"){
                    DO(tokens[1]);
                }
                else if (tokens[0] == "MDO"){
                    MDO(tokens[1]);
                }
                else if (tokens[0] == "SHOW"){
                    SHOW(tokens[1]);
            }
            }
            else {
                std::cout << "Error! Give a correct commend, please!" << std::endl;
            }

        }
    }
}


