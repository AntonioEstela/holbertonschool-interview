#include "lists.h"
/**
 * insert_node - function that inserts a number into a sorted linked list.
 * @head: Double pointer to linked list head.
 * @number: Integer to add into a linked list.
 * Return: NULL in failure otherwhise will return the adress of the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode = NULL, *h = NULL;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	h = *head;
	newNode->n = number;
	newNode->next = NULL;

	if (!head)
		(*head) = newNode;

	while (h != NULL)
	{
		if (h->next)
		{
			if (h->n > number)
			{
				newNode->next = h;
				(*head) = newNode;
				break;
			}
			if (h->n < number && h->next->n > number)
			{
				newNode->next = h->next;
				h->next = newNode;
				break;
			}
		}
		if (h->next == NULL)
		{
			h->next = newNode;
			break;
		}
		h = h->next;
	}
	return (newNode);
}
