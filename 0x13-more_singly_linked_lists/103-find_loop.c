#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *cat, *mouse;

	if (head == NULL || head->next == NULL)
		return (NULL);

	cat = head->next;
	mouse = (head->next)->next;

	while (mouse)
	{
		if (cat == mouse)
		{
			cat = head;

			while (cat != mouse)
			{
				cat = cat->next;
				mouse = mouse->next;
			}

			return (cat);
		}

		cat = cat->next;
		mouse = (mouse->next)->next;
	}

	return (NULL);
}
