#include "hash_tables.h"

/**
  * hash_table_print - function that prints a hash table.
  * @ht: hash table
  *
  */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	unsigned long int x = 0;
	int sym = 0;

	if (ht != NULL)
	{
		printf("{");
		for (x = 0; x < ht->size; x++)
		{
			tmp = ht->array[x];
			while (tmp != NULL)
			{
				if (sym == 0)
					sym = 1;
				else
					printf(", ");

				printf("'%s': '%s'", tmp->key, tmp->value);
				tmp = tmp->next;
			}
		}
		printf("}\n");
	}
}
