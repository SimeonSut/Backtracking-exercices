/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/03 16:13:40 by ssutarmi         ###   ########.fr       */
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

void	powerset(t_set *node, int start, int *subset, int subset_sum)
{
	if (subset[node->set_len - 1] == 1)
		;//backtracking
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
