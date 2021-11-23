#include "node.h"
#include <iostream>
#include <string>

Node::Node() {
    this->color = Color::Noire;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node* nde) {
    if (nde != nullptr) {
        this->elt = nde->elt;
        this->color = nde->color;
        if (nde->left != nullptr) left = new Node(nde->left);
        if (nde->right != nullptr) right = new Node(nde->right);
    }
    else {
        this->color = Color::Noire;
        this->left = nullptr;
        this->right = nullptr;
    }
}

Node::Node(Element elt) {
    this->elt = elt;
    this->left = nullptr;
    this->right = nullptr;
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
    return std::to_string(elt);
}

std::string Node::toStringColor() {
    std::string colorString = (color == Color::Noire) ? "\033[1;40m" : "\033[1;41m";
    return colorString + std::to_string(elt) + "\033[0m";
}
