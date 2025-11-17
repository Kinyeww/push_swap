#include "push_swap.h"

t_list	*find_min(t_list *stack_a)
{
	t_list	*min;

	min = stack_a;
	while (stack_a)
	{
		if (min->index > stack_a->index )
			min = stack_a;
		stack_a = stack_a->nextnode;
	}
	return (min);
}

int	find_pos(t_list *stack_a, int target)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->index == target)
			return (pos);
		pos++;
		stack_a->nextnode;
	}
	return (-1);
}

void	bring_to_top(t_list **stack_a, int size)
{
	int	min_pos;
	int	moves;

	min_pos = find_pos(*stack_a, size);
	if (min_pos < 0)
		return ;
	if (min_pos < (size / 2))
	{
		while (min_pos-- > 0)
			write (1, "ra\n", 3);
	}
	else
	{
		moves = size - min_pos;
		while (min_pos-- < 0)
			write (1, "rra\n", 4);
	}
}