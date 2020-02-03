#include "sort.h"

/**
* swap_1 - insertion sort function.
* @tmp: nodes.
* Return: Nothing.
*/

void swap_1(listint_t *tmp)
{
	tmp->prev = tmp->next;
	tmp->next->next->prev = tmp;
	tmp->next = tmp->next->next;
	tmp->prev->prev = NULL;
	tmp->prev->next = tmp;
}

/**
* swap_2 - insertion sort function.
* @tmp: nodes.
* Return: Nothing.
*/

void swap_2(listint_t *tmp)
{
	tmp->next->next->prev = tmp;
	tmp->next->prev = tmp->prev;
	tmp->prev = tmp->next;
	tmp->next = tmp->next->next;
	tmp->prev->prev->next = tmp->prev;
	tmp->prev->next = tmp;
}

/**
* swap_3 - insertion sort function.
* @tmp: nodes.
* Return: Nothing.
*/

void swap_3(listint_t *tmp)
{
	tmp->prev->next = tmp->next;
	tmp->next->next = tmp;
	tmp->next->prev = tmp->prev;
	tmp->prev = tmp->next;
	tmp->next = NULL;
}

/**
* swap_4 - insertion sort function.
* @tmp: nodes.
* Return: Nothing.
*/

void swap_4(listint_t *tmp)
{
	tmp->next->prev = NULL;
	tmp->prev = tmp->next;
	tmp->next = NULL;
	tmp->prev->next = tmp;
}

/**
* insertion_sort_list - insertion sort function.
* @list: nodes.
* Return: Nothing.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp2;

	if (*list != NULL && list != NULL)
	{
		tmp2 = (*list)->next;
		tmp = tmp2;
		while (tmp2 != NULL)
		{
			while (tmp != NULL)
			{
				if (tmp->n > tmp2->n && tmp->prev == NULL && tmp2->next == NULL)
				{
					swap_4(tmp);
					tmp = tmp->prev;
					*list = tmp;
					print_list(*list);
				}
				if (tmp->n > tmp2->n && tmp->prev == NULL)
				{
					swap_1(tmp);
					tmp = tmp->prev;
					*list = tmp;
					print_list(*list);
				}
				if (tmp->n > tmp2->n && tmp->prev != NULL)
				{
					if (tmp->n > tmp2->n && tmp2->next == NULL)
					{
						swap_3(tmp), print_list(*list);
					}
					else
					{swap_2(tmp), print_list(*list); }
				}
				tmp = tmp->prev;
			}
			tmp2 = tmp2->next;
			tmp = tmp2;
		}
	}
}
