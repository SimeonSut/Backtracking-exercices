/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 21:37:43 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

void	print_solution(int *solution_set, int solution_len)
{
	while (--solution_len > 0)
	{
		printf("%d ", *solution_set);
		solution_set++;
	}
	printf("%d\n", *solution_set);
}

int		check_condition(t_set *node, int *subset)
{
	int	i;

	i = 0;
	while (i < node->set_len)
	{
		if (subset[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

void	powerset(t_set *node, int start, int *subset, int subset_sum)
{
	int	i;

	i = start;
	if (subset[start] == 1)
		subset[start] == 0;
	while (i < node->set_len)
	{
		if (start == 0 || (start != 0 && i != start))
			subset[i] = 1;
		if (subset[i] == 1)
			subset_sum += node->set[i];
		else
			subset_sum -= node->set[i];
		if (subset_sum == node)
			;//print_solution
		i++;
	}
	if (check_condition(node, subset) == 1)
		powerset(node, --i, subset, subset_sum);
}

int main(int argc, char **argv)
{
	t_set	*node;
	int		*subset;

	if (argc < 2)
		return (1);
	if (argc == 2)
		return (printf("\n"), 0);
	node = make_set(argv);
	if (!node)
		return (1);
	subset = make_subset(argv, node->set_len);
	if (!subset)
		return (1);
	powerset(node, 0, subset, 0);
	return (0);
}
