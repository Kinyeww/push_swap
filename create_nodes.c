/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:25:30 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/15 20:25:31 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->nextnode = NULL;
	return (new_node);
}

void	add_node(t_list **list, int value)
{
	t_list	*last;
	t_list	*new;

	new = create_node(value);
	if (!new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = find_last_node(*list);
	last->nextnode = new;
	return ;
}

void	assign_index(t_list *stack_a)
{
	t_list	*current;
	t_list	*compare;
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
			compare = compare->nextnode;
		}
		current->index = rank;
		current = current->nextnode;
	}
}

int	find_max_num(t_list *stack_a)
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
		stack_a = stack_a->nextnode;
	}
	return (num);
}

int	list_size(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->nextnode;
		i++;
	}
	return (i);
}
