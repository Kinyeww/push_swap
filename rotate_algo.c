#include "push_swap.h"

void	rotate_a(l_list **stack_a)
{
	l_list	*first_node;
	l_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->nextNode)
		return ;
	first_node = *stack_a;
	last_node = find_last_node(*stack_a);
	*stack_a = first_node->nextNode;
	first_node->nextNode = NULL;
	last_node->nextNode = first_node;
	write (1, "ra\n", 3);
}

void	push_to_a(l_list** stack_b, l_list** stack_a) // b to a
{
    l_list* head_b;

    if (*stack_b == NULL)
        return ;
    head_b = *stack_b;
    *stack_b = (*stack_b)->nextNode;
    head_b->nextNode = *stack_a;
    *stack_a = head_b;
	write (1, "pa\n", 3);
}

void	push_to_b(l_list** stack_a, l_list** stack_b)
{
    l_list* head_a;

    if (*stack_a == NULL)
        return ;
    head_a = *stack_a;
    *stack_a = (*stack_a)->nextNode;
    head_a->nextNode = *stack_b;
    *stack_b = head_a;
	write (1, "pb\n", 3);
}
