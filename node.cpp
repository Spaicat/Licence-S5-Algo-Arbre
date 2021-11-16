#include "node.h"
#include <iostream>
#include <string>

Node::Node() {
    this->color = Color::Noire;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node* nde) {
    this->elt = nde->elt;
    this->color = nde->color;
    if (nde->left != nullptr) left = new Node(nde->left);
    if (nde->right != nullptr) right = new Node(nde->right);
}

Node::Node(Element elt, Color clr) {
    this->elt = elt;
    this->color = clr;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {
    vide();
    delete this;
}

void Node::vide() {
    if (left != nullptr) left->vide();
    if (right != nullptr) right->vide();
    delete this;
}

std::string Node::toString() {
    std::string colorString = (color == Color::Noire) ? " (N)" : " (R)";
    return std::to_string(elt) + colorString;
}
