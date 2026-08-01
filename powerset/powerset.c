/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 00:02:48 by ssutarmi         ###   ########.fr       */
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

void	powerset(int n, int *set, int set_len, int *subset, int subset_len)
{
	int	i;

	i = set_len - (set_len - subset_len);
	while (i < set_len)
	{
		if (set[i] == n)
			print_solution(&set[i], 1);
		add_nb_to_subset(subset, set_len, &subset_len, set[i]);
		if (set_sum(subset, subset_len) == n && subset_len > 1)
			print_solution(subset, subset_len);
		i++;
	}
	powerset(n, set, set_len, subset, --subset_len);
}

int main(int argc, char **argv)
{
	int	n;
	int	set_len;
	int	subset_len;
	int	*set;
	int	*subset;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = atoi(argv[1]);
	argv += 2;
	set_len = doubleptr_len(argv);
	if (make_set(argv, set, set_len, set_len) == 1)
		return (1);
	subset_len = 0;
	if (make_set(argv, subset, subset_len, set_len) == 1)
		return (free(set), 1);
	powerset(n, set, set_len, subset, subset_len);
	free(set);
	free(subset);
	return (0);
}

/*
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

void	store_solution(t_set *node, int *subset, int sublen)
{
	t_list	*storage;

	storage = iter_n_check_diff(node, subset, sublen);
	if (!storage)
		return ;
	storage->next = new_solution(subset, sublen);
}
*/
