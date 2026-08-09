/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:57:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/09 21:15:47 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check_validity(char *str)
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
	puts(str);
	return (0);
}

void	rip(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	if (check_validity(str) == 0)
		return ;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ' ';
		check_validity(str);
		str[i] = tmp;
		i++;
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
