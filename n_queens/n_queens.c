/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:19:55 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/26 21:49:13 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_queens.h"

void	print_solution(int *position, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		fprintf(STDOUT_FILENO, "%d", position[i]);
		i++;
		if (i < n)
			fprintf(STDOUT_FILENO, " ");
	}
	fprintf(STDOUT_FILENO, "\n");
}

int	is_valid(int column_pos, int row_pos, int n , int *positions)
{
	int	row_i;

	if (row_pos == 0)
		return (0);
	row_i = row_pos;
	while (--row_i >= 0)
	{
		if (positions[row_i] == column_pos)
			return (1);
		if (positions[row_i] == column_pos - (row_pos - row_i))
			return (1);
		if (positions[row_i] == column_pos + (row_pos - row_i))
			return (1);
	}
	return (0);
}

int	n_queens(int column, int row, int n, int *positions)
{
	int	c_track;

	while (row < n)
	{
		c_track = column;
		while (c_track < n)
		{
			if (is_valid(c_track, row, n, positions) == 0)
			{
				positions[row] = c_track;
				row++;
				column = 0;
				continue ;
			}
			c_track++;
		}
		if (c_track == n && is_valid(c_track, row, n, positions) == 1)
			n_queens((positions[row - 1] + 1), (row - 1), n, positions);
		row++;
	}
	if (row == n && is_valid(c_track, row, n, positions) == 1)
		print_solution(positions, n);
	return (1);
}

int main(int argc, char **argv)
{
	int	i;
	int	n;
	int	*positions;

	if (argc != 2)
		return (1);
	i = 0;
	n = atoi(argv[1]);
	positions = malloc(n * sizeof(int));
	if (!positions)
		return (NULL);
	while (i < n)
		positions[i++] = -1;
	n_queens(0, 0, n, positions);
	return (0);
}
