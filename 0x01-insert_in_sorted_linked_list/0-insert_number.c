#include "lists.h"

/**
* insert_node - Inserts a number into a sorted singly linked list.
* @head: first node
* @number: number
* Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *n_n = NULL;
	listint_t *next = NULL;
	listint_t *prev = NULL;

	if (head == NULL)
		return (NULL);

	n_n = malloc(sizeof(*n_n));
	if (!n_n)
		return (NULL);

	n_n->n = number;
	n_n->next = NULL;
	next = *head;

	if (*head == NULL)
		*head = n_n;
	while (prev || next)
	{
		if ((next == NULL || next->n > number)
			&& (prev == NULL || prev->n <= number))
		{
			if (prev == NULL)
				*head = n_n;
			else
				prev->next = n_n;
			n_n->next = next;
		}
		prev = next;
		if (next)
			next = next->next;
	}

	return (*head);
}
