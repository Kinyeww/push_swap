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

char**	ft_tokenise(int argc, char **argv)
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
	//printf("joined = %s\n", joined);
	tokens = ft_split(joined, ' ');
	int	check = 0;
	while (tokens[check])
	{
		//printf("ft_split = %s\n", tokens[check]);
		check++;
	}
	free (joined);
	if (!tokens || num_only(tokens) != 1) //check invalid chars
	{
		free_tokens(tokens);
		return (0);
	}
	return (tokens);
}

int	check_dupes(l_list *stack_a)
{
	int		cmp;
	l_list	*start;

	while (stack_a->nextNode)
	{
		start = stack_a;
		cmp = stack_a->value;
		while (start->nextNode)
		{
			start = start->nextNode;
			if (cmp == start->value)
				return (0);
		}
		stack_a = stack_a->nextNode;
	}
	return (1);
}

void	radix_sort(l_list **stack_a, l_list **stack_b)
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
		while (j < max_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_to_a(stack_b, stack_a);
		i++;
	}
}

l_list	*push_swap(int argc, char **argv)
{
	l_list	*stack_a;
	l_list	*stack_b;
	char	**checked;
	int	i;
	int	value;
	
	checked = ft_tokenise(argc, argv);
	if (!checked || ft_checknum(checked) != 1) //check overflow and invalid
	{
		free_tokens(checked);
		return (NULL);
	}
	//printf("atoi now\n");
	value = ft_atoi(checked[0]);
	stack_a = create_node(value); //initialise node
	i = 1;
	while (checked[i]) // start parsing value into nodes
	{
		value = ft_atoi(checked[i]);
		add_node(&stack_a, value);
		i++;
	}
	if (!(check_dupes(stack_a))) //check for dupes
	{
		free(stack_a);
		return (NULL);
	}
	assign_index(stack_a);
	//print_list(stack_a); // checking only
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