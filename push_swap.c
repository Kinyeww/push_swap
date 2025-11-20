/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:25:45 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/15 20:25:46 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_tokenise(int argc, char **argv)
{
	char	**tokens;
	char	*joined;
	int		i;

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

void	sort_small_num(int argc, t_list **stack_a, t_list **stack_b)
{
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		sort_four(stack_a, stack_b);
	else if (argc == 6)
		sort_five(stack_a, stack_b);
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
	while (i++ < max_bit)
	{
		j = 0;
		while (j++ < max_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
		}
		while (*stack_b)
			push_to_a(stack_b, stack_a);
	}
}

t_list	*push_swap(char **checked, int argc, int value)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

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
		free_stack(&stack_a);
		return (NULL);
	}
	assign_index(stack_a);
	stack_b = NULL;
	sort_num(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_tokens(checked);
	exit(0);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	char	**checked;
	int		value;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	checked = ft_tokenise(argc, argv);
	if (!checked || ft_checknum(checked) != 1)
	{
		free_tokens(checked);
		return (1);
	}
	value = ft_atoi(checked[0]);
	if (!(push_swap(checked, argc, value)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
