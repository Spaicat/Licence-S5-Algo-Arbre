#ifndef _NODE
#define _NODE
#include "node.h"
#include "element.h"
#include <string>

enum class Color { Rouge, Noire };

class Node
{
	friend class ARN;

	public :
		Node();
		Node(Node* nde);
		Node(Element elt, Color clr);
		~Node();

		std::string toString();
		void insere(Element elt);

		void affichePrefixe();
		void afficheInfixe();
		void affichePostfixe();
		void affichePretty(int profondeur, bool isRight);

	private :
		Element elt;
		Color color;
		Node* left;
		Node* right;
		void equilibreGauche();
		void equilibreDroit();
		void rotationGauche();
		void rotationDroite();
		void vide();
};

#endif