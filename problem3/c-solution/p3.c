/*
 * p3.c
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143 ?
 *
 * note: Solves for all numbers that are within the bounds of
 * 'unsigned long long'
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define		TEST		13195
#define		DEFAULT		600851475143
#define		NOT_PF		1

typedef unsigned long long ull;

/*
 * simple implementation of an array_list
 */
struct array_list {
	ull *list_ptr;
	ull size;
};

void create_list(struct array_list *list, ull size)
{
	if (size == 0)
		size = 64; // default
	list->list_ptr = (ull *) malloc(sizeof(ull) * size);
	for (ull i = 0; i < size; i++) {
		list->list_ptr[i] = 0;
	}
	list->size = size;
}

void delete_list(struct array_list *list)
{
	free(list->list_ptr);
}

ull get_elem_list(const struct array_list *list, const ull pos)
{
	return list->list_ptr[pos];
}

void insert_elem_list(struct array_list *list, const ull elem, const ull pos)
{
	while (pos >= list->size) {
		ull temp = list->size;
		delete_list(list);
		create_list(list, temp * 2);
	}

	list->list_ptr[pos] = elem;
}

void make_list_of_facts(struct array_list *pfs, const ull num)
{
	ull i;
	ull pos = 0;
	for (i = 2; i < (ull) sqrtl(num) + 1; i++) {
		if (num % i == 0) {
			insert_elem_list(pfs, i, pos++);
			insert_elem_list(pfs, num / i, pos++);
		}
	}
}

int is_prime(const ull num)
{
	ull i;
	int retval = 1;
	for (i = 2; i <= (ull) sqrtl(num) + 1; i++) {
		if (num % i == 0) {
			retval = 0;
			break;
		}
	}
	return retval;
}

void prune_facts(struct array_list *pfs)
{
	ull i;
	for (i = 0; i < pfs->size; i++) {
		if (get_elem_list(pfs, i) == 0)
			break;
		if (!is_prime(get_elem_list(pfs, i)))
			insert_elem_list(pfs, NOT_PF, i);
	}
}

ull find_max(const struct array_list *list)
{
	ull max = 0;
	ull i;
	for (i = 0; i < list->size; i++) {
		if (get_elem_list(list, i) > max)
			max = get_elem_list(list, i);
	}
	return max;
}

ull find_largest_pf(const ull num)
{
	struct array_list pfs;
	pfs.list_ptr = NULL;
	pfs.size = 0;
	create_list(&pfs, 0);

	make_list_of_facts(&pfs, num);

	prune_facts(&pfs);

	ull largest = find_max(&pfs);
	if (largest == 1)
		largest = num;
	return largest;
}

int main(int argc, char **argv)
{
	ull num, largest;
	(argc == 2) ? (num = atoi(argv[1])) : (num = DEFAULT);

	largest = find_largest_pf(num);

	printf("\nThe largest prime factor of the number %llu", num);
	printf(" is: %llu\n\n", largest);
	return 0;
}
