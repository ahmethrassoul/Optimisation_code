#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "shuffle.h"

#define ___ 0 /* placeholder */
#define ____ NULL /* placeholder */

/**
 * échange deux zones mémoire
 *
 * Cette fonction échange le contenu de deux zones mémoire de même taille
 *
 * @param a    adresse de la première zone
 * @param b    adresse de la seconde zone
 * @param size taille des zones mémoires
 */
static void swap(void *a, void *b, size_t size) {

	// on a besoin d'une zone mémoire supplémentaire et temporaire pour
	// faire l'échange :
	char tmp[size];

	// TODO : copier la première zone mémoire dans la zone temporaire
	// en utilisant la fonction memcpy (voir `man memcpy`)



	// TODO : copier la seconde zone mémoire dans la première



	// TODO : copier la zone temporaire dans la seconde zone


}

/**
 * @see shuffle.h
 */
void shuffle(void *base, size_t nmemb, size_t size) {

	// si le tableau ne contient aucun ou qu'un seul élément, il n'y a rien à
	// faire
	if (nmemb < 2) return;


	// TODO implémenter le mélange de Fisher-Yates :
	//
	// Pour i allant de nmemb - 1 à 1 faire :
	//     j := entier aléatoire entre 0 et i (utiliser la fonction rand()
	//     échanger base[i] et base[j]
	int i;
	int j;
	for (i =  ___ ; i < ___ ; i--) {
		j = ___;
		swap(____, ____, ___);
	}

}

