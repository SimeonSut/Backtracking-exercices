/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:12 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 20:32:37 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

int		doubleptr_len(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
		i++;
	return (i);
}

int		*make_subset(char **argv, int set_len)
{
	int	i;
	int	*subset;
	
	i = 0;
	subset = malloc(set_len * sizeof(int));
	if (!subset)
		return (NULL);
	while (i < set_len)
	{
		subset[i] = 0;
		i++;
	}
	return (subset);
}

t_set	*make_set(char **argv)
{
	int		i;
	t_set	*node;
	
	i = 0;
	node = malloc(sizeof(t_set));
	if (!node)
		return (NULL);
	node->n = atoi(argv[1]);
	argv += 2;
	node->set_len = doubleptr_len(argv);
	node->set = malloc (node->set_len * sizeof(int));
	if (!node->set)
	{
		free(node);
		return (NULL);
	}
	node->set_sum = 0;
	while (i < node->set_len)
	{
		node->set[i] = atoi(argv[i]);
		node->set_sum += node->set[i];
		i++;
	}
	return (node);
}
