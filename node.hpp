//
// Created by ola on 02.11.2019.
//

#ifndef PO_NODE_HPP
#define PO_NODE_HPP
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Transport.hpp"

class Node {
    std::string nameOfTheNode;
    std::vector<std::string> availableLeafList;
    std::map<std::string, Transport*> objects;
public:
    Node(std::string _nameOfTheNode, std::vector<std::string> leaf);
    ~Node();
    void add(std::string, std::string);
    void del(std::string);
    void modify(std::string);
    void add_objects(std::pair<std::string, Transport*>);
    std::string get_nameOfTheNode();
    std::vector<std::string> get_availableLeafList();
    std::map<std::string, Transport*> get_objects();


};


#endif //PO_NODE_HPP
