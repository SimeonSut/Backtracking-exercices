/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:10 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 20:31:46 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POWERSET_H
#define POWERSET_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_set
{
	int	*set;
	int	set_len;
	int	set_sum;
	int n;
}	t_set;

//POWERSET_UTILS.C
int		doubleptr_len(char **dptr);
int		set_sum(int *set, int len);
int		*make_subset(char **argv, int set_len);
t_set	*make_set(char **argv);

#endif
