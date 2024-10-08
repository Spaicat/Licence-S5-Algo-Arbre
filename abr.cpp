﻿#include "abr.h"
#include "node.h"
#include <iostream>

ABR::ABR() {
	root = nullptr;
}

ABR::ABR(const ABR & abr) {
	root = new Node(abr.root);
}

ABR::~ABR() {
	vide();
}

void ABR::vide() {
    if (root != nullptr)
        root->vide();
	root = nullptr;
}

ABR & ABR::operator = (const ABR & abr) {
	if (this == &abr)
		return *this;

	ABR abrCopy(abr);
	return abrCopy;
}

void ABR::insereRec(Node*& node, Element elt) {
	if (elt < node->elt) {
		if (node->left != nullptr)
			insereRec(node->left, elt);
		else
			node->left = new Node(elt);
	}
	else {
		if (node->right != nullptr)
			insereRec(node->right, elt);
		else
			node->right = new Node(elt);
	}
}
void ABR::insere(Element elt) {
	if (root == nullptr) {
		root = new Node(elt);
	}
	else {
		insereRec(root, elt);
	}
}

Node* ABR::rechercheRec(Element e, Node* n)
{
	if (n != nullptr)
	{
		if (e == n->elt) return n;
		else if (e < n->elt) return rechercheRec(e, n->left);
		else return rechercheRec(e, n->right);
	}
	return n;
}

Node* ABR::recherche(Element e) {
	Node* elem = rechercheRec(e, root);
	return elem;
}

void ABR::affichePrettyRec(Node*& node, int profondeur, std::string textBefore, bool isRight) {
	std::string branch = "";

	//Droite
	if (node->right != nullptr) {
		if (profondeur != 0) branch = (!isRight ? "│       " : "        ");

		affichePrettyRec(node->right, profondeur + 1, textBefore + branch, true);
	}

	//Racine
	std::cout << textBefore;
	if (profondeur != 0) std::cout << (isRight ? "┌───────" : "└───────");
	std::cout << "┼" << node->toString() << std::endl;

	//Gauche
	if (node->left != nullptr) {
		if (profondeur != 0) branch = (isRight ? "│       " : "        ");

		affichePrettyRec(node->left, profondeur + 1, textBefore + branch, false);
	}
}
void ABR::affichePretty() {
	if (root != nullptr)
		affichePrettyRec(root, 0, "", false);
	std::cout << std::endl;
}