#include "lists.h"
/**
 * check_cycle - Function that checks if a linked list has a cycle in it.
 * @list: Singly linked list to check.
 * Return: 1 if the list has a cycle in it otherwhise it will return 0.
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle = list;
	listint_t *hare = list;

	if (list == NULL)
		return (0);

	while (turtle->next != NULL && hare->next->next != NULL)
	{
		if (turtle->next)
			turtle = turtle->next;

		if (hare->next->next)
			hare = hare->next->next;

		if (hare == turtle)
			return (1);

	}

	return (0);
}
