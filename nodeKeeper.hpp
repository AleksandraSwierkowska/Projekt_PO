//
// Created by ola on 05.11.2019.
//

#ifndef PO_NODEKEEPER_HPP
#define PO_NODEKEEPER_HPP

#include <iostream>
#include "node.hpp"

class NodeKeeper {
    Node * currentNode;
    std::map<std::string, Node *> nodes;
public:
    NodeKeeper();
    ~NodeKeeper();
    void CD(std::string);
    void MO(std::string);
    void DO(std::string);
    void MDO(std::string);
    void DIR();
    void SHOW(std::string);
    void SAVE();
    void READ();
    void TREE();
    void program();
};


#endif //PO_NODEKEEPER_HPP

