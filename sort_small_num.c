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
	if ((*stack_a)->index > (*stack_a)->nextnode->index)
		write(1, "sa\n", 3);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->nextnode->index;
	c = (*stack_a)->nextnode->nextnode->index;
	if (a > b && b < c && a < c)
		write(1, "sa\n", 3);
	else if (a > b && b > c)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (a > b && b < c && a > c)
		write(1, "ra\n", 3);
	else if (a < b && b > c && a < c)
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
	}
	else if (a < b && b > c && a > c)
		write(1, "rra\n", 4);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	bring_to_top(stack_a, size);
	write(1, "pb\n", 3);
	sort_three(stack_a);
	write(1, "pa\n", 3);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	bring_to_top(stack_a, size);
	write(1, "pb\n", 3);
	sort_four(stack_a);
	write(1, "pa\n", 3);
}
