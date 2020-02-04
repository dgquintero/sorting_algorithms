#include "sort.h"
/**
 * insertion_sort_list - 
 *
 * @list:
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *_list, *swap, *end;

	/* Validate */
	if (!list || !*list)
		return;
	
	_list = *list;
	/* Move Forward */
	while (_list && _list->next)
	{
		/* Move bigger number to the right */
		if ((_list->n) > (_list->next->n))
		{
			node_swap(_list, _list->next, list);
			end = _list;
			_list = _list->prev;
			/* Move backwards */
			while (_list && _list->prev)
			{
				swap = _list;
				/* Move little numbers to the left */
				if((swap->n) < (swap->prev->n))
				{
					node_swap(_list->prev, swap, list);
				} else
				{
					/* kill the loop */
					break;
				}
			}
			_list = end;
		} else
		{
			_list = _list->next;
		}
		
	}
}
/**
 * node_swap - 
 * @left:
 * @right:
 * @list:
 */
void node_swap(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *tmp;

	tmp = left->prev;
	if (tmp)
		tmp->next = right;
	else
	{
		*list = right;
	}
	right->prev = tmp;

	left->prev = right;
	left->next = right->next;
	right->next = left;

	if(left->next)
		left->next->prev = left;

	print_list(*list);
}
