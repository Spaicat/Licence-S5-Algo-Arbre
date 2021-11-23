#ifndef _ABR
#define _ABR
#include "node.h"
#include "element.h"

class ABR
{
	public :
		ABR();
		ABR(const ABR & abr);
		~ABR();
		void vide();

		ABR & operator = (const ABR & abr);

		void insere(Element elt);
		Node* recherche(Element elt);

		void affichePretty();

	private:
		Node* root;

		Node* rechercheRec(Element e, Node* n);
		void insereRec(Node*& node, Element elt);
		void affichePrettyRec(Node*& node, int profondeur, std::string textBefore, bool isRight);
};

#endif