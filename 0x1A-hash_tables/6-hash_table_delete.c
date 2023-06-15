#include "hash_tables.h"

/**
 * hash_table_delete - prints a hash table
 * @ht: the hash table
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *temp = NULL, *node = NULL;

	if (ht != NULL && ht->array != NULL)
	{
		for (idx = 0; idx < ht->size; idx++)
		{
			node = ht->array[idx];
			while (node != NULL)
			{
				free(node->key);
				free(node->value);
				temp = node;
				node = node->next;
				free(temp);
			}
		}
		free(ht->array);
		free(ht);
	}
}
