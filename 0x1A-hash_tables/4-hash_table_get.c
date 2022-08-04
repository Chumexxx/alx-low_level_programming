#include "hash_tables.h"

/**
  * hash_table_get - function that retrieves a value associated with a key.
  * @ht: hash table to be looked into.
  * @key: key being looked for.
  *
  * Return: value or Null if key couldn't found.
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(key, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}
