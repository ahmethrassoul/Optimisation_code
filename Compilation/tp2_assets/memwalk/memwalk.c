#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>
#include <inttypes.h>

#include "shuffle.h"
#include "rdtsc.h"

#define ___ 0 /* placeholder */
#define ____ NULL /* placeholder */

struct cell {
	struct cell *next;   /**< adresse de la prochaine cellule */
	unsigned long value; /**< valeur ce la cellule courante */
};

/**
 * mesure le nombre de cycles processeur nécessaires pour parcourir un certain
 * nombre de cellules, en mettant à jour la valeur de chaque cellule visitée
 * (on lui ajoute 1)
 *
 * @param start adresse de la cellule de départ
 * @param steps nombre de cellules
 *
 * @returns le nombre de cycles processeur nécessaires pour exécuter le parcours
 */
uint64_t walk(struct cell *cell, size_t steps) {
	// mémorise le compteur de cycles en début de fonction
	uint64_t cycles_start = ts_start();
	
	while (steps--) {
		// TODO : ajouter 1 au champ `value` de la cellule courante 
		cell->value = ___;

		// TODO : mettre à jour le pointeur de cellule courante `cell` avec
		// l'adresse de la celluse suivante
		cell = ____;
	}

	// retourne la différence du compteur de cycles entre le début et la fin
	// de la fonction
	return ts_stop() - cycles_start;
}

/**
 * compare deux nombres flottants double précision, pour la fonction
 * qsort
 *
 * @param a adresse du premier double
 * @param b adresse du second double
 *
 * @returns 0 si les nombres sont égaux, 1 si le premier est supérieur, -1 sinon
 */
int cmp_doubles(const void *a, const void *b) {
	double da = *(double *)a;
	double db = *(double *)b;
	if (da == db)     return 0;
	else if (da > db) return 1;
	else              return -1;
}

/* procédure principale */
int main(int argc, char **argv) {
	size_t total_bytes = 1024;
	int total_steps = 5;
	int randomize = 0;
	int times = 5; 
	
	// récupération des options de la ligne de commande
	int c;
	while ((c = getopt(argc, argv, "m:n:rt:")) != -1) {
		switch (c) {
			case 'm':
				total_bytes = strtoul(optarg, NULL, 10);
				if (total_bytes < sizeof(struct cell)) {
					fprintf(stderr, "taille minimale: %lu octets\n", sizeof(struct cell));
					exit(1);
				}
				break;
			case 'n':
				total_steps = strtoul(optarg, NULL, 10);
				if (total_steps == 0) {
					exit(1);
				}
				break;
			case 'r':
				randomize = 1;
				break;
			case 't':
				times = atoi(optarg) | 1; // on s'assure que le nombre est impair avec ̀ | 1`
				break;
		}
	}


	// TODO : calculer le nombre de structures `struct cell` qu'une zone
	// mémoire de taille `total_bytes` octets peut contenir, l'arrondir à
	// l'entier inférieur
	size_t ncells = ___;

	// TODO : allouer une zone mémoire, dont l'adresse sera mise dans le
	// pointeur `cells`, pour y loger un tableau de `ncells` structures `struct
	// cell` 
	struct cell *cells = ____;

	// TODO : initialiser chaque cellule
	//
	// - champ `next` : l'adresse de la cellule suivante dans le tableau
	// - champ `value` : à 0
	//
	// remarque : la dernière cellule doit être reliée à la première afin de
	// former un grand cycle
	int i = 0;
	for (i = 0 ; i < ncells ; i++) {
		cells[i].next = ____;
		cells[i].value = 0;
	}
	
	// TODO : la dernière cellule est à relier à la première
	cells[___].next = ____;


	// ce tableau contiendra les résultats obtenus pour les `times` mesures
	// effectuées
	double samples[times];

	// TODO : calculer `times` fois le temps de traitement moyen d'une cellule
	// dans la fonction `walk()`
	for (i = 0 ; i < times ; i++) {
		// TODO : mélanger le tableau si demandé
		if (randomize) {
			shuffle(____, ___, ___);
		}
		
		uint64_t total_cycles = walk(cells, total_steps);

		// TODO : quel est le temps moyen pour traiter une cellule dans walk() ?
		samples[i] = ___;
	}

	// TODO : calculer la valeur médiane du tableau de mesure `samples[]`
	//
	// - le trier avec la fonction `qsort()` (man qsort), la fonction de
	//   comparaison vou est donnée plus haut (`cmp_doubles()`)
	// - récupérer la valeur au milieu du tableau [remarque : la taille du
	//   tableau est forcément impaire, on s'en est assuré lors de la
	//   récupération des options de la ligne de commande]
	qsort(samples, times, sizeof *samples, cmp_doubles);
	double median_access_time = ___;

	// affichage du résultat :
	//     [taille de la zone mémoire] <TAB> [temps moyen d'accès à une cellule]
	printf("%zu\t%f\n", total_bytes, median_access_time);

	return 0;
}
