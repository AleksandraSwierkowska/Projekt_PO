//
// Created by ola on 02.11.2019.
//
#include <vector>
#include "node.hpp"
#include "transit.hpp"
#include "internal.hpp"
#include "international.hpp"
#include "sea.hpp"
#include "river.hpp"
#include "AllTypes.hpp"

void Node::add(std::string _name, std::string leaf) {
    while (true){
        if (objects.count(_name) == 0){
            break;
        }
        else {
            std::cout << "Sorry, the name of the object already exists! Choose another name, please." << std::endl;
            std::cin >> _name;
        }
    }
    std::pair<std::string, Transport*> pair;
    Transport *object;
    if (leaf == "Transit"){
        object = new Transit(_name);
    }
    else if (leaf == "Internal"){
        object = new Internal(_name);
    }
    else if (leaf == "International"){
        object = new International(_name);
    }
    else if (leaf == "Sea"){
        object = new Sea(_name);
    }
    else if (leaf == "River"){
        object = new River(_name);
    }
    else{
        std::cout << "This is not a leaf. Change the node, please." << std::endl;
    }
    pair = {_name, object};
    objects.insert(pair);
}

void Node::del(std::string _name) {
    if(objects.find(_name) != objects.end()){
        {
        objects.erase(objects.find(_name));
        }
    }
    else{
        std::cout << "There's no such object in the current node." << std::endl;
    }
}

void Node::modify(std::string _name) {
    if(objects.find(_name) != objects.end()){
        {
            objects[_name] -> modify();
        }
    }
    else{
        std::cout << "There's no such object in the current node." << std::endl;
    }
}

std::string Node::get_nameOfTheNode() {
    return nameOfTheNode;
}

std::vector<std::string> Node::get_availableLeafList() {
    return availableLeafList;
}

std::map<std::string, Transport*> Node::get_objects() {
    return objects;
}


Node::Node(std::string _nameOfTheNode, std::vector<std::string> leaf) {
    availableLeafList = std::move(leaf);
    objects = std::map<std::string, Transport *>();
    nameOfTheNode = _nameOfTheNode;

}

Node::~Node() {
    for (auto i : objects){
        delete i.second;
    }
}

void Node::add_objects(std::pair<std::string, Transport*> pair){
    objects.insert(pair);
}

