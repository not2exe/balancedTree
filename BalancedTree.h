//
// Created by da on 28.10.2022.
//

#ifndef BALANCE_TREE_BALANCEDTREE_H
#define BALANCE_TREE_BALANCEDTREE_H

#include <iostream>
#include <random>
#include <queue>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int val;

    Node(int _val) : val(_val), right(nullptr), left(nullptr) {};
};

class BalancedTree {
    Node *root = nullptr;
    int size = 0;
public:
    BalancedTree(int);

    int countPositiveLeafs(Node *);

    int countPositiveLeafs();

    void print(Node *, string, bool);

    void print();

    Node * createTree(Node *, int);

    int count(int);

    void doubleValueOfNodes();

    int count(Node *, int);
};


#endif //BALANCE_TREE_BALANCEDTREE_H
