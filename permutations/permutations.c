/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:33:30 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/29 22:13:17 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char			*solution;
	struct s_list	*next;
}	t_list;

t_list	*new(char *solution, int len)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->solution = malloc(len * sizeof(char));
	if (node->solution)
	{
		free(node);
		return (NULL);
	}
	while (len >= 0)
	{
		node->solution[len] = solution;
		len--;
	}
	node->next = NULL;
	return (node);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	swap(char *one, char *two)
{
	char	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}


void	permutations(char *str, int start, int swap_i, int len)
{
	int	i;

	i = start;
	while (start <= len)
	{
		swap(str[start], str[i]);
		i++;
		permutations(str, i, len);
	}
	//swap the current index of the string with itself and increment if you can
	//if you cant increment, backtrack to the previous if you can and swap with the next one if any
	//if you cant backtrack, return;
}

int main(int argc, char **argv)
{
	char	*str;
	int		len;
	
	if (argc != 2)
		return (1);
	str = argv[1];
	len = my_strlen(str);
	permutations(str, 0, len);
	return (0);
}
