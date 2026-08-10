/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:57:14 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/11 00:44:31 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static void	setup(char *str, int len);
static void	rip(char *str, int *array, int len, int count_zero);

int 	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc != 2)
		return (1);
	i = 0;
	str = argv[1];
	while (str[i])
		i++;
	setup(str, i);
	return (0);
}

static void	setup(char *str, int len)
{
	int	array[len];

	while (len > 0)
	{
		len--;
		array[len] = 1;
	}
	rip(str, array, len, 0);
}

static void	rip(char *str, int *array, int len, int recursion)
{
	int	i;
	int	iteration;

	i = recursion;
	while (--i >= 0)
		array[i] = 0;
	i = recursion;
	iteration = 0;
	while (are_zeros_right(array, len) == 0)
	{
		while (i < len)
		{
			array[i] = 0;
			;//test_validity
			array[i] = 1;
			i++;
		}
		move_zeros(array, len, recursion, iteration);
		iteration++;
	}
	if (/*test_validity*/)
		rip(str, array, len, recursion + 1);
}

static int	are_zeros_right(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len && array[i] == 1)
		i++;
	while (i < len && array[i] == 0)
		i++;
	if (i == len)
		return (0);
	return (i);
}

static void	move_zeros(int *array, int len, int recursion, int iteration)
{
	int	i;

	i = len - 1;
	array[i] = 1;
	if (recursion == 0)
		return ;
	while (array[i] == 1)
		i--;
	while (iteration >= 0)
	{
		array[i] == 0;
		iteration--;
	}
}

/*
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

int		visit(char *str, int start)
{
	int		i;
	int		validity;
	char	tmp;

	i = start + 1;
	if (check_validity(str) == 0)
		return 1;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ' ';
		validity = check_validity(str);
		str[i] = tmp;
		i++;
	}
	return (validity);
}

void	rip(char *str, int *array, int len)
{
	int		i;
	char	tmp;

	if (visit(str, start) == 1 || bfs != 0)
		return ;
	i = start + 1;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ' ';
		rip(str, 0, i);
		str[i] = tmp;
		i++;
	}
	rip(str, 1, start + 1);
}
*/
