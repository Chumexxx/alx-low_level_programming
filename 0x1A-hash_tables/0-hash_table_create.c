#include "hash_tables.h"

/**
  * hash_table_create - function that creates a hash table.
  * @size: size of the array.
  *
  * Return: pointer to newly created hash table.
  */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int x;

	/* create a table size of the struct for table */
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL || size == 0)
		return (NULL);

	/* create an array of size size array is a member of struct table */
	new_table->array = malloc(sizeof(void *) * size);
	if (new_table->array == NULL)
		return (NULL);

	new_table->size = size;

	/* initialize the array to null */
	for (x = 0; x < size; x++)
		new_table->array[x] = NULL;

	return (new_table);
}
