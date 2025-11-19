/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:25:54 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/15 20:25:55 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*nextnode;
	struct node	*prevnode;
}	t_list;

int		num_only(char **str);
void	assign_index(t_list *stack_a);
t_list	*create_node(int value);
void	add_node(t_list **list, int value);
char	**ft_split(char const *s, char c);
t_list	*find_last_node(t_list *head);
char	*ft_combine(size_t len1, size_t len2, char const *s1, char const *s2);
long	ft_atoi(const char *nptr);
char	*ft_strjoin_space(char const *s1, char const *s2);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		find_max_num(t_list *stack_a);
void	rotate_a(t_list **stack_a);
void	push_to_a(t_list **stack_b, t_list **stack_a);
void	push_to_b(t_list **stack_a, t_list **stack_b);
int		list_size(t_list *stack_a);
void	free_tokens(char **arr);
int		ft_checknum(char **arr);
int		num_only(char **str);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_two(t_list **stack_a);
int		find_pos(t_list *stack_a, int target);
void	bring_to_top(t_list **stack_a, int size);
int		check_dupes(t_list *stack_a);
void	free_tokens(char **arr);
void	sort_small_num(int argc, t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	swap_a(t_list **stack_a);
int		find_min(t_list *stack_a);

#endif
