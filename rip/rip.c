/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:57:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/07 21:06:28 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check_validity(char *str, int ignore)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count++;
		if (str[i] == ')')
			count--;
		if (count < 0)
			return (1);
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}

void	rip(char *str, int prev_space, int char_input)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (check_validity(str, i) == 0)
		{
			;//print_solution
			return ;
		}
		i++;
		if ((!str[i] || i == prev_space) && i > 0)
		{
			str[i] = char_input;
			i--;
			tmp = str[i];
			str[i] = ' ';
			rip(str, i, tmp);
		}
	}
}

int 	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (1);
	str = argv[1];
	rip(str);
	return (0);
}
