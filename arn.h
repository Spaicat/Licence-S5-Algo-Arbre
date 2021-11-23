#ifndef _ARN
#define _ARN
#include "node.h"
#include "element.h"

class ARN
{
	public :
		ARN();
		ARN(const ARN& abr);
		~ARN();
		void vide();

		ARN& operator = (const ARN& abr);

		void insere(Element elt);
		Node* recherche(Element elt);

		void affichePretty();

	private:
		Node* root;

		Node* rechercheRec(Element e, Node* n);
		void insereRec(Node*& node, Element elt);
		void equilibreGauche(Node*& node);
		void equilibreDroit(Node*& node);
		void rotationGauche(Node*& node);
		void rotationDroite(Node*& node);
		void affichePrettyRec(Node*& node, int profondeur, std::string textBefore, bool isRight);
};

#endif