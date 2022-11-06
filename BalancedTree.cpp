//
// Created by da on 28.10.2022.
//

#include "BalancedTree.h"

BalancedTree::BalancedTree(int size) {
    if (size < 0)return;
    this->size = size;
    root = createTree(root, size);
}
Node *BalancedTree::createTree(Node *nodeRoot, int n) {
    if (n == 0)return nullptr;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> distribution(-10, 10);
    if (nodeRoot == nullptr) {
        nodeRoot = new Node(distribution(mt));;
        createTree(nodeRoot, n - 1);
    } else if (nodeRoot->right == nullptr) {
        nodeRoot->right = new Node(distribution(mt));;
        createTree(nodeRoot, n - 1);
    } else {
        nodeRoot->left = new Node(distribution(mt));;
        createTree(nodeRoot->right, n / 2);
        createTree(nodeRoot->left, n - n / 2 - 1);
    }
    return nodeRoot;
}

int BalancedTree::countPositiveLeafs(Node *node) {
    if (node == nullptr)return 0;
    if (node->left == nullptr && node->right == nullptr && node->val > 0) return 1;
    return countPositiveLeafs(node->left) + countPositiveLeafs(node->right);
}

int BalancedTree::countPositiveLeafs() {
    return countPositiveLeafs(root);
}

void BalancedTree::print(Node *node, string pref, bool isRight) {
    if (node == nullptr)return;
    cout << pref << ((isRight && node->left != nullptr) ? "├── " : "└── ") << node->val << endl;
    string nextPref = pref + (isRight ? "│   " : "    ");
    print(node->right, nextPref, true);
    print(node->left, nextPref, false);
}
void BalancedTree::print() {
    print(root, "", false);
}

int BalancedTree::count(Node *node, int value) {
    if (node == nullptr)return 0;
    if (node->val == value) return 1 + count(node->right, value) + count(node->left, value);
    return count(node->left, value) + count(node->right, value);
}

int BalancedTree::count(int value) {
    return count(root, value);
}

void BalancedTree::doubleValueOfNodes() {
    if (root == nullptr)
        return;
    queue<Node *> n;
    n.push(root);
    while (!n.empty()) {
        n.front()->val *= 2;
        if (n.front()->left != nullptr)
            n.push(n.front()->left);
        if (n.front()->right != nullptr)
            n.push(n.front()->right);
        n.pop();
    }
}











