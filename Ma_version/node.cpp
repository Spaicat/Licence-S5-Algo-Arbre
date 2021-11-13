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
    delete this;
}

std::string Node::toString() {
    std::string colorString = (color == Color::Noire) ? "N" : "R";
    return "<" + std::to_string(elt) + ", " + colorString + ">";
}

void Node::insere(Element elt) {
    if (elt < this->elt) {
        if (left != nullptr) {
            left->insere(elt);
            this->equilibreGauche();
        }
        else
            left = new Node(elt, Color::Rouge);
    }
    else {
        if (right != nullptr) {
            right->insere(elt);
            this->equilibreDroit();
        }
        else
            right = new Node(elt, Color::Rouge);
    }
}

void Node::equilibreGauche() {
    if (left != nullptr && left->color == Color::Rouge) {
        //Cas 1 : left->left possède un oncle (right) rouge
        if (right != nullptr && right->color == Color::Rouge) {
            if (left->left != nullptr && left->left->color == Color::Rouge) {
                this->color = Color::Rouge;
                left->color = Color::Noire;
                right->color = Color::Noire;
            }
        }
        //Cas 2 : left->left ne possède pas d'oncle (right) rouge
        //Cas 2.a : left->left est le fils gauche de left (rouge)
        else if (left->left != nullptr && left->left->color == Color::Rouge) {
            rotationDroite();
            this->color = Color::Noire;
            right->color = Color::Rouge;
        }
        //Cas 2.b : left->right est le fils droit de left (rouge)
        else if (left->right != nullptr && left->right->color == Color::Rouge) {
            left->rotationGauche();
            rotationDroite();
            this->color = Color::Noire;
            right->color = Color::Rouge;
        }
    }
}

void Node::equilibreDroit() {
    if (right != nullptr && right->color == Color::Rouge) {
        //Cas 1 : right->right possède un oncle (left) rouge
        if (left != nullptr && left->color == Color::Rouge) {
            if (right->right != nullptr && right->right->color == Color::Rouge) {
                this->color = Color::Rouge;
                left->color = Color::Noire;
                right->color = Color::Noire;
            }
        }
        //Cas 2 : right->right ne possède pas d'oncle (left) rouge
        //Cas 2.a : right->right est le fils gauche de right (rouge)
        else if (right->right != nullptr && right->right->color == Color::Rouge) {
            rotationGauche();
            this->color = Color::Noire;
            left->color = Color::Rouge;
        }
        //Cas 2.b : right->left est le fils droit de right (rouge)
        else if (right->left != nullptr && right->left->color == Color::Rouge) {
            left->rotationGauche();
            rotationDroite();
            this->color = Color::Noire;
            left->color = Color::Rouge;
        }
    }
}


void Node::rotationDroite() {
    //On met de côté le sous-arbre gauche
    Node* temp = left;
    //On peut donc remplacer dans notre arbre le fils gauche par ce qu'on veut obtenir
    left = temp->right;
    //On prends ainsi notre nouvel arbre pour le mettre dans notre variable temporaire
    temp->right = new Node(this);

    //On a ainsi l'arbre qu'on voulait obtenir dans une variable temporaire
    //On le remet ainsi dans notre arbre

    this->elt = temp->elt;
    this->left = temp->left;
    this->right = temp->right;
}

void Node::rotationGauche() {
    //On met de côté le sous-arbre droit
    Node* temp = right;
    //On peut donc remplacer dans notre arbre le fils gauche par ce qu'on veut obtenir
    right = temp->left;
    //On prends ainsi notre nouvel arbre pour le mettre dans notre variable temporaire
    temp->left = new Node(this);

    //On a ainsi l'arbre qu'on voulait obtenir dans une variable temporaire
    //On le remet ainsi dans notre arbre

    this->elt = temp->elt;
    this->left = temp->left;
    this->right = temp->right;
}


void Node::affichePrefixe() {
	std::cout << this->toString();
	if (left != nullptr) left->affichePrefixe();
	if (right != nullptr) right->affichePrefixe();
}

void Node::afficheInfixe() {
	if (left != nullptr) left->afficheInfixe();
	std::cout << this->toString();
	if (right != nullptr) right->afficheInfixe();
}

void Node::affichePostfixe() {
	if (left != nullptr) left->affichePostfixe();
	if (right != nullptr) right->affichePostfixe();
	std::cout << this->toString();
}

void Node::affichePretty(int profondeur, bool isRight) {
    //Espace à mettre avant
    std::string textBefore = "";
    for (int i = 0; i < profondeur-1; i++) {
        textBefore += "      ";
    }
    
    //Droite
	if (right != nullptr) {
        right->affichePretty(profondeur+1, true);
    }

    //Racine
    if (profondeur != 0) {
        textBefore += isRight ? "  ┌────" : "  └────";
    }
	std::cout << textBefore << this->toString() << std::endl;

	//Gauche
    if (left != nullptr) {
        left->affichePretty(profondeur+1, false);
    }
}

void Node::vide() {
    if (left != nullptr) left->vide();
    if (right != nullptr) right->vide();
    delete this;
}