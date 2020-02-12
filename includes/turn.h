/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:52:44 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/12 16:18:02 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TURN_H
#define TURN_H

#include "graph.h"

typedef struct					s_turn
{
	t_fork			**arr;
	ssize_t			size;
	ssize_t			col;
}								t_turn;

t_fork						**turn_create(int size);
void						turn_add(t_turn *turn, t_fork *room, t_bool priority);
void						turn_del(t_turn *turn);
void						turn_free(t_turn *turn);

#endif
