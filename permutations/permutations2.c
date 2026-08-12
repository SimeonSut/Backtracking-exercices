/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:34:17 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/12 20:39:29 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_strdup(char *str, int len)
{
	char	*new;

	new = malloc((len + 1) * sizeof(int));
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (--len >= 0)
		new[len] = str[len];
	return (new);
}

void	permutations(char *str, int start, int len)
{
	int		i;
	char	tmp;
	char	*new;

	if (start + 1 == len)
	{
		write(1, str, len);
		write(1, "\n", 1);
	}
	i = start;
	while (str[i])
	{
		tmp = str[start];
		str[start] = str[i];
		str[i] = tmp;
		new = my_strdup(str, len);
		permutations(new, start + 1, len);
		free(new);
		i++;
	}
}

int main(int argc, char **argv)
{
	char    *str;
	int		len;
	
	if (argc != 2)
		return (1);
	str = argv[1];
	len = 0;
	while (str[len])
		len++;
	permutations(str, 0, len);
	return (0);
}
