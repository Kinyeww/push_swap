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
	char	*temp;
	char	*joined;
	int		i;

	i = 1;
	joined = NULL;
	tokens = NULL;
	if (argv[i][0] == '\0')
		return (NULL);
	while (i < argc)
	{
		temp = joined;
		joined = ft_strjoin_space(joined, argv[i]);
		free(temp);
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

void	sort_small_num(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_size((*stack_a));
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
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
	i = -1;
	while (++i < max_bit)
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

t_list	*push_swap(char **checked, int value)
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
		free_tokens(checked);
		return (NULL);
	}
	assign_index(stack_a);
	stack_b = NULL;
	sort_num(&stack_a, &stack_b);
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
	if (!(push_swap(checked, value)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
