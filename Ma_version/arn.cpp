#include "arn.h"
#include "node.h"
#include <iostream>

ARN::ARN() {
	root = nullptr;
}

ARN::ARN(const ARN& arn) {
	root = new Node(arn.root);
}

ARN::~ARN() {
	vide();
}

ARN & ARN::operator = (const ARN & arn) {
	if (this == &arn)
		return *this;

	ARN abrCopy(arn);
	return abrCopy;
}

void ARN::insere(Element elt) {
	if (root == nullptr) {
		root = new Node(elt, Color::Noire);
	}
	else {
		root->insere(elt);
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


void ARN::affichePrefixe() {
	if (root != nullptr)
		root->affichePrefixe();
    std::cout << std::endl;
}

void ARN::afficheInfixe() {
	if (root != nullptr)
		root->afficheInfixe();
    std::cout << std::endl;
}

void ARN::affichePostfixe() {
	if (root != nullptr)
		root->affichePostfixe();
    std::cout << std::endl;
}

void ARN::affichePretty() {
	if (root != nullptr)
		root->affichePretty(0, false);
    std::cout << std::endl;
}

void ARN::vide() {
	if (root != nullptr)
		root->vide();
	root = nullptr;
}