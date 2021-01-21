#include "lists.h"
/**
 * linked_list_size - function that calculates the size of a linked list.
 * @head: A pointer to the head of the list.
 * Return: the size of the list.
 */
int linked_list_size(listint_t **head)
{
	listint_t *h = (*head);
	int size = 0;

	if (head == NULL)
		return (0);

	while (h != NULL)
	{
		size += 1;
		h = h->next;
	}

	return (size);

}
/**
 * check_linked_list - function that checks if a linked list is a palindrome.
 * @head: A pointer to the head of the list.
 * @size: The size of the list.
 * Return: 1 if the list is palindrome, otherwhise will return 0.
 */
int check_linked_list(listint_t **head, int size)
{
	listint_t *h = (*head);
	int newList[size];
	int i = 0;
	int start = 0;
	int end = size - 1;

	for (i = 0; i < size; i++, h = h->next)
	{
		newList[i] = h->n;
	}

	for (start = 0; start < end; start++, end--)
	{
		if (newList[start] != newList[end])
		{
			return (0);
		}
	}

	return (1);
}
/**
 * is_palindrome - function that checks if a linked list is a palindrome or not
 * @head: A pointer to the head of the list.
 * Return: 1 if the list is palindrome, otherwhise will return 0.
 */
int is_palindrome(listint_t **head)
{
	int size;
	int isPalindrome;

	if (head == NULL)
		return (1);

	size = linked_list_size(head);
	isPalindrome = check_linked_list(head, size);

	return (isPalindrome);
}
