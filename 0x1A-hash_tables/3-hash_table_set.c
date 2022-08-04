#include "hash_tables.h"

/**
  * hash_table_set - function that adds an element to the hash table.
  * @ht: hash table to add or update the key value to
  * @key: key that cannot be an empty string.
  * @value: associated with key, duplicated and can be an empty string.
  *
  * Return: 1 if successful 0 if otherwise.
  */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *h_node, *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	h_node = malloc(sizeof(hash_node_t));
	if (h_node == NULL)
		return (0);

	h_node->key = strdup(key);
	h_node->value = strdup(value);
	h_node->next = ht->array[index];
	ht->array[index] = h_node;
	return (1);
}
