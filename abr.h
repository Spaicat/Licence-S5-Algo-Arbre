#ifndef _ABR
#define _ABR
#include "node.h"
#include "element.h"
#include "collection.h"

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

		void insereRec(Node*& node, Element elt);
		void affichePrettyRec(Node*& node, int profondeur, std::string textBefore, bool isRight);
};

#endif