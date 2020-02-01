#include "sort.h"

/**
* insertion_sort_list - insertion sort function.
* @list: nodes.
* Return: Nothing.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2;

	tmp2 = (*list)->next;
	tmp = tmp2;

	while (tmp2 != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp->n > tmp2->n && tmp->prev == NULL && tmp2->next == NULL)
			{
				tmp->next->prev = NULL;
				tmp->prev = tmp->next;
				tmp->next = NULL;
				tmp->prev->next = tmp;
				tmp = tmp->prev;
				*list = tmp;
				print_list(*list);
			}
			if (tmp->n > tmp2->n && tmp->prev == NULL)
			{
				tmp->prev = tmp->next;
				tmp->next->next->prev = tmp;
				tmp->next = tmp->next->next;
				tmp->prev->prev = NULL;
				tmp->prev->next = tmp;
				tmp = tmp->prev;
				*list = tmp;
				print_list(*list);
			}
			if (tmp->n > tmp2->n && tmp->prev != NULL)
			{
				if (tmp->n > tmp2->n && tmp2->next == NULL)
				{
					tmp->prev->next = tmp->next;
					tmp->next->next = tmp;
					tmp->next->prev = tmp->prev;
					tmp->prev = tmp->next;
					tmp->next = NULL;
					print_list(*list);
				}
				else
				{
					tmp->next->next->prev = tmp;
					tmp->next->prev = tmp->prev;
					tmp->prev = tmp->next;
					tmp->next = tmp->next->next;
					tmp->prev->prev->next = tmp->prev;
					tmp->prev->next = tmp;
					print_list(*list);
				}
			}
			tmp = tmp->prev;
		}
		tmp2 = tmp2->next;
		tmp = tmp2;
	}
}
