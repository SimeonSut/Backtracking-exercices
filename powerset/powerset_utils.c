/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:12 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/30 21:20:08 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

int	doubleptr_len(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
		i++;
	return (i);
}

t_set	*make_set(char **argv)
{
	int		i;
	t_set	*node;

	node = malloc(sizeof(t_set));
	if (!node)
		return (NULL);
	node->len = doubleptr_len(argv);
	i = node->len;
	node->set = malloc(node->len * sizeof(int));
	if (!node->set)
	{
		free(node);
		return (NULL);
	}
	while (--i >= 0)
		node->set[i] = atoi(argv[i]);
	node->lst = NULL;
	return (node);
}

t_list	*new_solution(int *subset, int len)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->solution = malloc(len * sizeof(int));
	if (!node->solution)
	{
		free(node);
		return (NULL);
	}
	while (--len >= 0)
		node->solution[len] = subset[len];
	node->len = len;
	node->next = NULL;
	return (node);
}
