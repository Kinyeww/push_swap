#include "push_swap.h"

void	free_tokens(char **arr)
{
	int	i;

	if (!arr)
		return;
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

char	**ft_tokenise(int argc, char **argv)
{
	char	**tokens;
	char	*joined;
	int	i;

	i = 1;
	joined = NULL;
	tokens = NULL;
	while (i < argc)
	{
		joined = ft_strjoin_space(joined, argv[i]);
		i++;
	}
	tokens = ft_split(joined, ' ');
	free (joined);
	if (!tokens || num_only(tokens) != 1)
	{
		free_tokens(tokens);
		return (0);
	}
	return (tokens);
}

int	check_dupes(t_list *stack_a)
{
	int		cmp;
	t_list	*start;

	while (stack_a->nextnode)
	{
		start = stack_a;
		cmp = stack_a->value;
		while (start->nextnode)
		{
			start = start->nextnode;
			if (cmp == start->value)
				return (0);
		}
		stack_a = stack_a->nextnode;
	}
	return (1);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_num;
	int	max_bit;
	int	max_size;
	int	i;
	int	j;

	max_num = find_max_num(*stack_a);
	max_size = list_size(*stack_a);
	max_bit = 0;
	while (max_num >> max_bit != 0)
		max_bit++;
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j++ < max_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			push_to_b(stack_a, stack_b);
		}
		while (*stack_b)
			push_to_a(stack_b, stack_a);
		i++;
	}
}

t_list	*push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**checked;
	int	i;
	int	value;

	checked = ft_tokenise(argc, argv);
	if (!checked || ft_checknum(checked) != 1)
	{
		free_tokens(checked);
		return (NULL);
	}
	value = ft_atoi(checked[0]);
	stack_a = create_node(value);
	i = 1;
	while (checked[i])
	{
		value = ft_atoi(checked[i]);
		add_node(&stack_a, value);
		i++;
	}
	if (!(check_dupes(stack_a)))
	{
		free(stack_a);
		return (NULL);
	}
	assign_index(stack_a);
	stack_b = NULL;
	radix_sort(&stack_a, &stack_b);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	// char	**token;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
	{
		if (!(push_swap(argc, argv)))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}