#include <stddef.h> /* pour size_t */

/**
 * cette fonction mélange aléatoirement les éléments d'un tableau
 *
 * @param base  adresse du premier élément du tableau
 * @param nmemb nombre d'éléments dans le tableau
 * @param size  taille en octetd d'un élément
 */
void shuffle(void *base, size_t nmemb, size_t size);
