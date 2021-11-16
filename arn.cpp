#include "arn.h"
#include "node.h"
#include <iostream>

ARN::ARN() {
	root = nullptr;
}

ARN::ARN(const ARN& abr) {
	root = new Node(abr.root);
}

ARN::~ARN() {
	vide();
}

void ARN::vide() {
    if (root != nullptr)
        root->vide();
    root = nullptr;
}

ARN & ARN::operator = (const ARN & abr) {
	if (this == &abr)
		return *this;

	ARN abrCopy(abr);
	return abrCopy;
}


void rotationDroite(Node*& node) {
    //On met de côté le sous-arbre gauche
    Node* temp = node->left;
    //On peut donc remplacer dans notre arbre le fils gauche par ce qu'on veut obtenir
    node->left = temp->right;
    //On prends ainsi notre nouvel arbre pour le mettre dans notre variable temporaire
    temp->right = node;

    //On a ainsi l'arbre qu'on voulait obtenir dans une variable temporaire
    //On remplace donc dans notre arbre
    node = temp;
}
void rotationGauche(Node*& node) {
    //On met de côté le sous-arbre droit
    Node* temp = node->right;
    //On peut donc remplacer dans notre arbre le fils droit par ce qu'on veut obtenir
    node->right = temp->left;
    //On prends ainsi notre nouvel arbre pour le mettre dans notre variable temporaire
    temp->left = node;

    //On a ainsi l'arbre qu'on voulait obtenir dans une variable temporaire
    //On remplace donc dans notre arbre
    node = temp;
}
void equilibreGauche(Node*& node) {
    if (node->left != nullptr && node->left->color == Color::Rouge) {
        //Cas 1 : left->left possède un oncle (right) rouge
        if (node->right != nullptr && node->right->color == Color::Rouge) {
            if (node->left->left != nullptr && node->left->left->color == Color::Rouge) {
                node->color = Color::Rouge;
                node->left->color = Color::Noire;
                node->right->color = Color::Noire;
            }
        }
        //Cas 2 : left->left ne possède pas d'oncle (right) rouge
        //Cas 2.a : left->left est le fils gauche de left (rouge)
        else if (node->left->left != nullptr && node->left->left->color == Color::Rouge) {
            rotationDroite(node);
            node->color = Color::Noire;
            node->right->color = Color::Rouge;
        }
        //Cas 2.b : left->right est le fils droit de left (rouge)
        else if (node->left->right != nullptr && node->left->right->color == Color::Rouge) {
            rotationGauche(node->left);
            rotationDroite(node);
            node->color = Color::Noire;
            node->right->color = Color::Rouge;
        }
    }
}
void equilibreDroit(Node*& node) {
    if (node->right != nullptr && node->right->color == Color::Rouge) {
        //Cas 1 : right->right possède un oncle (left) rouge
        if (node->left != nullptr && node->left->color == Color::Rouge) {
            if (node->right->right != nullptr && node->right->right->color == Color::Rouge) {
                node->color = Color::Rouge;
                node->left->color = Color::Noire;
                node->right->color = Color::Noire;
            }
        }
        //Cas 2 : right->right ne possède pas d'oncle (left) rouge
        //Cas 2.a : right->right est le fils gauche de right (rouge)
        else if (node->right->right != nullptr && node->right->right->color == Color::Rouge) {
            rotationGauche(node);
            node->color = Color::Noire;
            node->left->color = Color::Rouge;
        }
        //Cas 2.b : right->left est le fils droit de right (rouge)
        else if (node->right->left != nullptr && node->right->left->color == Color::Rouge) {
            rotationGauche(node->left);
            rotationDroite(node);
            node->color = Color::Noire;
            node->left->color = Color::Rouge;
        }
    }
}
void insereRec(Node*& node, Element elt) {
    if (elt < node->elt) {
        if (node->left != nullptr) {
            insereRec(node->left, elt);
            equilibreGauche(node);
        }
        else
            node->left = new Node(elt, Color::Rouge);
    }
    else {
        if (node->right != nullptr) {
            insereRec(node->right, elt);
            equilibreDroit(node);
        }
        else
            node->right = new Node(elt, Color::Rouge);
    }
}
void ARN::insere(Element elt) {
	if (root == nullptr) {
		root = new Node(elt, Color::Noire);
	}
	else {
		insereRec(root, elt);
		root->color = Color::Noire;
	}
}


Node* ARN::recherche(Element elt) {
	Node* curr = root;

	while(curr != nullptr && curr->elt != elt) {
		if (elt < curr->elt)
			curr = curr->left;
		else
			curr = curr->right;
	}

	return curr;
}


void affichePrefixeRec(Node*& node) {
    std::cout << node->toString();
    if (node->left != nullptr) affichePrefixeRec(node->left);
    if (node->right != nullptr) affichePrefixeRec(node->right);
}
void ARN::affichePrefixe() {
	if (root != nullptr)
		affichePrefixeRec(root);
    std::cout << std::endl;
}

void afficheInfixeRec(Node*& node) {
    if (node->left != nullptr) afficheInfixeRec(node->left);
    std::cout << node->toString();
    if (node->right != nullptr) afficheInfixeRec(node->right);
}
void ARN::afficheInfixe() {
	if (root != nullptr)
		afficheInfixeRec(root);
    std::cout << std::endl;
}

void affichePostfixeRec(Node*& node) {
    if (node->left != nullptr) affichePostfixeRec(node->left);
    if (node->right != nullptr) affichePostfixeRec(node->right);
    std::cout << node->toString();
}
void ARN::affichePostfixe() {
	if (root != nullptr)
		affichePostfixeRec(root);
    std::cout << std::endl;
}

void affichePrettyRec(Node*& node, int profondeur, bool isRight) {
    //Espace à mettre avant
    std::string textBefore = "";
    for (int i = 0; i < profondeur - 1; i++) {
        textBefore += "        ";
    }

    //Droite
    if (node->right != nullptr) {
        affichePrettyRec(node->right, profondeur + 1, true);
    }

    //Racine
    if (profondeur != 0) {
        textBefore += isRight ? "┌───────" : "└───────";
    }
    std::cout << textBefore << "┤" << node->toString() << std::endl;

    //Gauche
    if (node->left != nullptr) {
        affichePrettyRec(node->left, profondeur + 1, false);
    }
}
void ARN::affichePretty() {
	if (root != nullptr)
		affichePrettyRec(root, 0, false);
    std::cout << std::endl;
}
