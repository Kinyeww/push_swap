#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// This line defines a new data type called 'node'
typedef struct node
{
	// It stores the data inside this node (like 7, 21, etc.)
	int value;
	int index;
	// This is a pointer to another 'struct node'
	struct node *nextNode;
	struct node *prevNode;
// So from now on, instead of typing 'struct node', we can just write 'l_list'
} l_list;

int	num_only(char **str);
void	assign_index(l_list *stack_a);
l_list	*create_node(int value);
void	add_node(l_list **list, int value);
void	print_list(l_list *list);
char	**ft_split(char const *s, char c);
l_list	*find_last_node(l_list *head);
long	ft_atoi(const char *nptr);
char	*ft_strjoin_space(char const *s1, char const *s2);
void	radix_sort(l_list** stack_a, l_list** stack_b);
int		find_max_num(l_list* stack_a);
void	rotate_a(l_list **stack_a);
void	push_to_a(l_list** stack_b, l_list** stack_a);
void	push_to_b(l_list** stack_a, l_list** stack_b);
int	list_size(l_list* stack_a);

#endif