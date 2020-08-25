#include "lists.h"

/**
 * analyze -check if  is palindrome
 * @head1: pointer to the head of the linked list
 * @head2: pointer to the head of the linked list
 * Description: we use head2 to get to the end
 * using recursion. Then we compare head1
 * with the current value of head2. Then we compare head 1 with the
 * current value of head2. Finally we start increasing the position of
 * head1 to compare it with the old values of head2. This has the
 * effect of comparing start + 1 with end-1.
 * Return: 1 (palindrome) || 0
 */
static int analyze(listint_t **head1, listint_t *head2)
{
	int result;
	int a;
	int b;

	if (head2 == NULL)
		return (1);

	a =  analyze(head1, head2->next);
	b = ((*head1)->n == head2->n);
	result = a && b;

	(*head1) = (*head1)->next; /* head[+1] */

	return (result);
}
/**
 * is_palindrome - checks if a linked list with int is a palindrome
 * @head: head pointer to the linked list
 *
 * Return: 1 (palindrome) || 0
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (0);
	return (analyze(head, *head));
}
