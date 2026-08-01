/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssutarmi <ssutarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:18:10 by ssutarmi          #+#    #+#             */
/*   Updated: 2026/08/02 00:02:24 by ssutarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POWERSET_H
#define POWERSET_H

#include <stdlib.h>
#include <stdio.h>

//POWERSET_UTILS.C
int		doubleptr_len(char **dptr);
void	add_nb_to_subset(int *subset, int *subset_len, int nb_i, int new_nb);
int		set_sum(int *set, int len);
int		make_set(char **argv, int *set, int cpy_len, int set_len);
//t_set	*make_set(char **argv);
//t_list	*new_solution(int *solution, int len);

#endif
