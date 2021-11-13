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
		void vide();

		std::string toString();


		Element elt;
		Color color;
		Node* left;
		Node* right;
};

#endif