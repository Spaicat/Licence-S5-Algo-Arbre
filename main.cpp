#include <cstdio>
#include <iostream>
#include <vector>
#include <chrono>
#include "collection.h"
#include "abr.h"
#include "arn.h"
#include <Windows.h> //Pour windows (utf8) A ENLEVER

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Pour windows (utf8) A ENLEVER
	std::printf("░░▒▒▓▓ Arbre Rouge Noir ▓▓▒▒░░\n");

	std::vector<Collection> ArrayOftrees;
	for (int i = 0; i < 100; i++) {
		Collection tree = Collection();
		ArrayOftrees.push_back(tree);
	}

	std::printf("░░▒▒▓▓ Magnifique :\n");

	std::printf("░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░\n");

	return 0;
}