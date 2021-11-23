#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "collection.h"
#include "abr.h"
#include "arn.h"

const int NB_TREE = 100;
const int NB_ELT = 5000;
const std::string NAME_FILE = "PerformanceABR";

int main()
{
	//Seed pour l'aléatoire
	srand(time(NULL));

	std::cout << "▒ Test d'un arbre :" << std::endl;
	Collection* testArbre = new Collection();
	for (int i = 0; i < 30; i++) {
		testArbre->insere(rand() % 100+1);
	}
	testArbre->affichePretty();

	std::cout << "▒ Compilation du fichier performance" << std::endl;

	std::vector<Collection> ArrayOftrees;

	//Tableau d'arbre vide
	for (int i = 0; i < NB_TREE; i++) {
		Collection tree = Collection();
		ArrayOftrees.push_back(tree);
	}

	std::chrono::time_point<std::chrono::system_clock> start, end;
	int perfInsertion = 0;
	int perfTotal = 0;

	//On crée le fichier excel
	std::ofstream filePerf(NAME_FILE + ".txt");
	filePerf << "# \"Nombre d'éléments\" \"Temps\"" << std::endl;

	//On ajoute un certains nombre d'éléments dans tous nos arbres
	for (int i = 0; i < NB_ELT; i++) {
		start = std::chrono::system_clock::now();
		for (int j = 0; j < ArrayOftrees.size(); j++) {
			int nbRand = rand() % NB_ELT/2;
			ArrayOftrees[j].insere(nbRand);
		}
		end = std::chrono::system_clock::now();

		//Calcul de la moyenne d'une insertion dans un arbre
		perfInsertion = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / ArrayOftrees.size();
		perfTotal += perfInsertion;

		if (i%20 == 0) filePerf << i << " " << perfInsertion << "\n";
	}
	perfTotal /= NB_ELT;
	filePerf.close();

	std::cout << "▒ Fin de la compilation du fichier performance" << std::endl;
	std::cout << "▒ Performances moyenne d'une insertion : " << perfTotal << " nanosecondes" << std::endl;

	return 0;
}