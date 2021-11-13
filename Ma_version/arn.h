#ifndef _ABR
#define _ABR
#include "node.h"
#include "element.h"

class ARN
{
	public :
		ARN();
		ARN(const ARN& abr);
		~ARN();

		ARN& operator = (const ARN& abr);

		void insere(Element elt);
		Node* recherche(Element elt);

		void affichePrefixe();
		void afficheInfixe();
		void affichePostfixe();
		void affichePretty();

	private :
		Node* root;
		void vide();
};

#endif