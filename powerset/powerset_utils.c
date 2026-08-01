/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:12 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 00:02:33 by ssutarmi         ###   ########.fr       */
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

void	add_nb_to_subset(int *subset, int *subset_len, int nb_i, int new_nb)
{
	subset[nb_i] = new_nb;
	*subset_len++;
}

int		set_sum(int *set, int len)
{
	int	sum;

	sum = 0;
	while (--len >= 0)
		sum += set[len];
	return (sum);
}

int		make_set(char **argv, int *set, int cpy_len, int set_len)
{
	int	i;
	
	i = 0;
	set = malloc(set_len * sizeof(int));
	if (!set)
		return (1);
	while (i < cpy_len)
	{
		set[i] = atoi(argv[i]);
		i++;
	}
	return (0);
}
