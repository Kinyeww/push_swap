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
void	print_list(t_list *list);
char	**ft_split(char const *s, char c);
t_list	*find_last_node(t_list *head);
long	ft_atoi(const char *nptr);
char	*ft_strjoin_space(char const *s1, char const *s2);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		find_max_num(t_list *stack_a);
void	rotate_a(t_list **stack_a);
void	push_to_a(t_list **stack_b, t_list **stack_a);
void	push_to_b(t_list **stack_a, t_list **stack_b);
int		list_size(t_list *stack_a);

#endif