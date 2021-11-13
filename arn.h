#ifndef _ABR
#define _ABR
#include "node.h"
#include "element.h"

class ARN
{
	friend void insereRec(Node*& node, Element elt);
	friend void equilibreGauche(Node*& node);
	friend void equilibreDroit(Node*& node);
	friend void rotationGauche(Node*& node);
	friend void rotationDroite(Node*& node);

	friend void affichePrefixeRec(Node*& node);
	friend void afficheInfixeRec(Node*& node);
	friend void affichePostfixeRec(Node*& node);
	friend void affichePrettyRec(Node*& node, int profondeur, bool isRight);

	public :
		ARN();
		ARN(const ARN& abr);
		~ARN();
		void vide();

		ARN& operator = (const ARN& abr);

		void insere(Element elt);
		Node* recherche(Element elt);

		void affichePrefixe();
		void afficheInfixe();
		void affichePostfixe();
		void affichePretty();


		Node* root;
};

#endif