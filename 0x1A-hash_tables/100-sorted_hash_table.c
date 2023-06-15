#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the hash table
 *
 * Return: pointer to the hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);

	shash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}
	shash_table->size = size;
	for (i = 0; i < size; i++)
		shash_table->array[i] = NULL;
	shash_table->shead = NULL;
	shash_table->stail = NULL;
	return (shash_table);
}

/**
 * shash_table_set - sets a key value in the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if successful otherwise 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node, *temp;

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
		node = malloc(sizeof(shash_node_t));
		if (node == NULL)
			return (0);
		node->key = strdup(key);
		if (node->key == NULL)
			return (0);
		node->value = strdup(value);
		if (node->value == NULL)
			return (0);
		node->next = ht->array[idx];
		node->sprev = NULL;
		node->snext = NULL;
		ht->array[idx] = node;
		add_to_sorted_list(ht, node);
	}
	return (1);
}

/**
 * add_to_sorted_list - adds a node to a sorted list
 * @ht: sorted hash table
 * @node: node to be added
 */
void add_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *temp;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
	}
	else if (strcmp(node->key, ht->shead->key) <= 0)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(node->key, ht->stail->key) > 0)
	{
		ht->stail->snext = node;
		node->sprev = ht->stail;
		ht->stail = node;
	}
	else
	{
		temp = ht->shead;
		while (temp != NULL && strcmp(temp->key, node->key) < 0)
			temp = temp->snext;

		node->sprev = temp->sprev;
		temp->sprev->snext = node;
		node->snext = temp;
		temp->sprev = node;
	}
}

/**
 * shash_table_get - gets the value for a key
 * @ht: the hash table
 * @key: the key to be searched for
 *
 * Return: the value otherwise NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL && strcmp(temp->key, key) != 0)
		temp = temp->next;

	if (temp != NULL)
		return (temp->value);

	return (NULL);
}

/**
 * shash_table_print - prints the hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	short is_first_item = 1;
	shash_node_t *temp;

	if (ht != NULL && ht->array != NULL)
	{
		printf("{");
		temp = ht->shead;
		while (temp != NULL)
		{
			if (is_first_item == 0)
				printf(", ");
			else
				is_first_item = 0;
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - prints the hash table in reverse
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	short is_first_item = 1;
	shash_node_t *temp;

	if (ht != NULL && ht->array != NULL)
	{
		printf("{");
		temp = ht->stail;
		while (temp != NULL)
		{
			if (is_first_item == 0)
				printf(", ");
			else
				is_first_item = 0;
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->sprev;
		}
		printf("}\n");
	}
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int idx;
	shash_node_t *temp = NULL, *node = NULL;

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
