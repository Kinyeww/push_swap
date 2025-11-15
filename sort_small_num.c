/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:02:13 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/16 00:09:26 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->rank > (*stack_a)->nextnode->rank)
		
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->nextnode->nbr;
	c = (*stack_a)->nextnode->next->nbr;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	bring_to_top(t_list **stack, int value)
{
	int	position;
	int	size;

	position = find_position(*stack, value);
	size = stack_size(*stack);
	if (position < (size / 2))
	{
		while ((*stack)->nbr != value)
			ra(stack);
	}
	else
	{
		while ((*stack)->nbr != value)
			rra(stack);
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	bring_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	bring_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

