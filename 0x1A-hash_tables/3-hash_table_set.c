#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return (0);
	if (key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL && strcmp(temp->key, key) != 0)
		temp = temp->next;

	if (temp != NULL)
	{
		free(temp->value);
		temp->value = strdup(value);
		if (temp->value == NULL)
			return (0);
	}
	else
	{
		node = malloc(sizeof(hash_node_t));
		if (node == NULL)
			return (0);
		node->key = strdup(key);
		if (node->key == NULL)
			return (0);
		node->value = strdup(value);
		if (node->value == NULL)
		{
			free(node->key);
			return (0);
		}
		node->next = ht->array[idx];
		ht->array[idx] = node;
	}
	return (1);
}
