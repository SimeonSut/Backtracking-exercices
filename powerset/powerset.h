/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:10 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/07/30 21:20:05 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POWERSET_H
#define POWERSET_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_set
{
	int		*set;
	int		len;
	int		n;
	t_list	*lst;
}		t_set;

typedef struct s_list
{
	int				*solution;
	int				len;
	struct s_list	*next;
}	t_list;

//POWERSET_UTILS.C
int		doubleptr_len(char **dptr);
t_set	*make_set(char **argv);
t_list	*new_solution(int *solution, int len);

#endif
