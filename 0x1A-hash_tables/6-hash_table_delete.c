#include "hash_tables.h"

/**
  * hash_table_delete - function that deletes a hash table.
  * @ht: hash table
  *
  */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp, *tmp2;
	unsigned long int x = 0;

	if (ht == NULL)
		return;

	for (x = 0; x < ht->size; x++)
	{
		tmp = ht->array[x];
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = tmp2;
		}
	}
	free(ht->array);
	free(ht);
}
