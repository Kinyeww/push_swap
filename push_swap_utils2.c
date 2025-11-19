#include "push_swap.h"

void	free_tokens(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_checknum(char **arr)
{
	int		i;
	long	num;

	i = 0;
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_dupes(t_list *stack_a)
{
	int		check;
	t_list	*head;
	t_list	*current;

	check = 0;
	head = stack_a;
	while (stack_a)
	{
		current = head;
		check = 0;
		while (current)
		{
			if (current->value == stack_a->value)
				check++;
			if (check == 2)
				return (0);
			current = current->nextnode;
		}
		stack_a = stack_a->nextnode;
	}
	return (1);
}