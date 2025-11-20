/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:03:30 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/20 20:03:39 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_list *stack_a, int target)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->value == target)
			return (pos);
		pos++;
		stack_a = stack_a->nextnode;
	}
	return (-1);
}

void	bring_to_top(t_list **stack_a, int size)
{
	int	min_pos;
	int	min;

	min = find_min(*stack_a);
	min_pos = find_pos(*stack_a, min);
	if (min_pos < 0)
		return ;
	if (min_pos < (size / 2))
	{
		while (min_pos-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		size -= min_pos;
		while (size-- > 0)
			reverse_rotate_a(stack_a);
	}
}

int	find_min(t_list *stack_a)
{
	int	compare;

	compare = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < compare)
			compare = stack_a->value;
		stack_a = stack_a->nextnode;
	}
	return (compare);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (!stack || !(*stack))
		return ;
	head = (*stack);
	while (head)
	{
		tmp = head;
		head = head->nextnode;
		free (tmp);
	}
	(*stack) = NULL;
}
