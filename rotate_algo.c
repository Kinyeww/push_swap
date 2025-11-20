/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:30:46 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/20 20:03:14 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->nextnode)
		return ;
	first_node = *stack_a;
	last_node = find_last_node(*stack_a);
	*stack_a = first_node->nextnode;
	first_node->nextnode = NULL;
	last_node->nextnode = first_node;
	write (1, "ra\n", 3);
}

void	push_to_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*head_b;

	if (*stack_b == NULL)
		return ;
	head_b = *stack_b;
	*stack_b = (*stack_b)->nextnode;
	head_b->nextnode = *stack_a;
	*stack_a = head_b;
	write (1, "pa\n", 3);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;

	if (*stack_a == NULL)
		return ;
	head_a = *stack_a;
	*stack_a = (*stack_a)->nextnode;
	head_a->nextnode = *stack_b;
	*stack_b = head_a;
	write (1, "pb\n", 3);
}

void	swap_a(t_list **stack_a)
{
	t_list	*head;
	t_list	*second;

	if (*stack_a == NULL)
		return ;
	head = *stack_a;
	second = head->nextnode;
	head->nextnode = second->nextnode;
	second->nextnode = head;
	*stack_a = second;
	write (1, "sa\n", 3);
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*head;

	if (*stack_a == NULL)
		return ;
	head = *stack_a;
	second_last = NULL;
	while (head->nextnode)
	{
		second_last = head;
		head = head->nextnode;
	}
	last = head;
	last->nextnode = (*stack_a);
	second_last->nextnode = NULL;
	(*stack_a) = last;
	write (1, "rra\n", 4);
}
