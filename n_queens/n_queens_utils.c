/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:50:52 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/28 21:44:27 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_queens.h"

/*int		**n_queens_init(int n)

 clear ; cc -Wall -Wextra -Werror n_queens.c n_queens_utils.c -g -o n_queens

{
	int	i;
	int	sub_i;
	int	**queens;

	i = 0;
	queens = malloc(n * sizeof(int *));
	if (!queens)
		return (1);
	while (i < n)
	{
		sub_i = 0;
		queens[i] = malloc(n *sizeof(int));
		if (!queens[i])
		{
			while (--i >= 0)
				free(queens[i]);
			free(queens);
			return (1);
		}
		while (sub_i < n)
			queens[i][sub_i++] = 0;
		i++;
	}
	return (queens);
}*/
