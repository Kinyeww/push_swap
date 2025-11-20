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
	if ((*stack_a)->value > (*stack_a)->nextnode->value)
		swap_a(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->nextnode->value;
	c = (*stack_a)->nextnode->nextnode->value;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	bring_to_top(stack_a, size);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_to_a(stack_b, stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	bring_to_top(stack_a, size);
	push_to_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_to_a(stack_b, stack_a);
}

void	sort_num(int argc, t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->index < 5)
		sort_small_num(argc, stack_a, stack_a);
	else
		radix_sort(stack_a, stack_b);
}
