#include <cstdio>
#include <iostream>
#include "collection.h"
#include "abr.h"
#include "arn.h"
#include <Windows.h> //Pour windows (utf8) A ENLEVER

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Pour windows (utf8) A ENLEVER
	std::printf("░░▒▒▓▓ Arbre Rouge Noir ▓▓▒▒░░\n");

	Collection<ABR>* arn1 = new Collection<ABR>();
	arn1->insere(25);
	arn1->insere(15);
	arn1->insere(10);
	arn1->insere(20);
	arn1->insere(5);
	arn1->insere(30);
	arn1->insere(35);
	arn1->insere(40);

	std::printf("░░▒▒▓▓ Magnifique :\n");

	arn1->affichePretty();

	std::printf("░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░\n");

	return 0;
}