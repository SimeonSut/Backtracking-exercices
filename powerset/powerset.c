/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/30 21:37:59 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

int		int_array_diff(int *arr_one, int len_one, int *arr_two, int len_two)
{
	if (len_one != len_two)
		return (0);
	while (--len_one >= 0)
	{
		if (arr_one[len_one] != arr_two[len_one])
			return (0);
	}
	return (1);
}

t_list	*iter_n_check_diff(t_set *node, int *subset, int sublen)
{
	t_list	*track;

	track = node->lst;
	while (track && track->next)
	{
		if (int_array_diff(track->solution, track->len, subset, sublen) != 0)
			return (NULL);
		track = track->next;
	}
	return (track);
}

void	powerset(t_set *node, int *subset, int sublen, int start)
{
	int	i;

	i = start;
}

int main(int argc, char **argv)
{
	t_set	*node;
	int		*subset;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	argv += 2;
	node = make_set(argv);
	if (!node)
		return (NULL);
	subset = malloc(sizeof(int));
	if (!subset)
		return (NULL);//free all nodes as well
	subset[0] = atoi(argv[0]);
	powerset(node, subset, 1, 0);
	return (0);
}
