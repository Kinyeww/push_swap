#include "push_swap.h"

l_list	*create_node(int value)
{
	l_list	*new_node;

	new_node = (l_list*)malloc(sizeof(l_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->nextNode = NULL;
	return (new_node);
}

void	add_node(l_list **list, int value)
{
	l_list *last;
	l_list	*new;

	new = create_node(value);
	if (!new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = find_last_node(*list);
	last->nextNode = new;
	return ;
}

void	print_list(l_list *list)
{
	while (list != NULL)
	{
		printf("num = %d, rank = %d\n", list->value, list->index);
		list = list->nextNode;
	}
	printf("done printing list\n");
}

void	assign_index(l_list *stack_a)
{
	l_list	*current;
	l_list	*compare;
	int		rank;

	current = stack_a;
	while (current)
	{
		rank = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->nextNode;
		}
		current->index = rank;
		current = current->nextNode;
	}
}

int	find_max_num(l_list* stack_a)
{
	int	rank;
	int	num;

	rank = stack_a->index;
	num = stack_a->value;
	while (stack_a)
	{
		if (stack_a->index > rank)
		{
			rank = stack_a->index;
			num = stack_a->value;
		}
		stack_a = stack_a->nextNode;
	}
	return (num);
}

int	list_size(l_list* stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->nextNode;
		i++;
	}
	return (i);
}