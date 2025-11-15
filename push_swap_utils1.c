#include "push_swap.h"

l_list	*find_last_node(l_list *head)
{
	if (!head)
		return (NULL);
	while (head->nextNode)
		head = head->nextNode;
	return (head);
}

long	ft_atoi(const char *nptr)
{
	int	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

char	*ft_combine(size_t len1, size_t len2, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	temp = malloc(sizeof(char) * (len1 + len2 + 1 + 1));
	i = 0;
	while (i < len1)
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	temp[i] = ' ';
	i++;
	while (j < len2)
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[len1 + len2 + 1] = '\0';
	return (temp);
}

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	str = ft_combine(len1, len2, s1, s2);
	return (str);
}

int	num_only(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
