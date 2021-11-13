#include <cstdio>
#include <iostream>
#include "arn.h"
#include <Windows.h> //Pour windows (utf8) A ENLEVER

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Pour windows (utf8) A ENLEVER
	std::printf("░░▒▒▓▓ Arbre Rouge Noir ▓▓▒▒░░\n");

	ARN* arn1 = new ARN();
	arn1->insere(25);
	arn1->insere(15);
	arn1->insere(10);
	arn1->insere(20);
	arn1->insere(5);
	arn1->insere(30);
	arn1->insere(35);
	arn1->insere(40);

	//arn1->affichePrefixe();
	//arn1->afficheInfixe();
	//arn1->affichePostfixe();

	std::printf("░░▒▒▓▓ Magnifique :\n");

	arn1->affichePretty();

	std::printf("░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░\n");

	return 0;
}
