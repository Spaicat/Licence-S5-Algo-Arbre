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

	Collection<ARN>* arn1 = new Collection<ARN>();
	for (int i = 0; i < 20; i++) {
		arn1->insere(i);
	}

	std::printf("░░▒▒▓▓ Magnifique :\n");

	arn1->affichePretty();

	std::printf("░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░\n");

	return 0;
}