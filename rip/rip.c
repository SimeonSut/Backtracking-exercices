/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:57:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/06 16:56:57 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check_validity(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	if (str[i] == '(')
		return (0);
	while (str[i])
	{
		if (str[i] == '(')
			quote++;
		else if (str[i] == ')')
			;
	}
	return (quote);
}

void	rip(char *str)
{
}

int 	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (1);
	str = argv[1];
	return (0);
}
