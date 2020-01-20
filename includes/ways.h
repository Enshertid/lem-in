/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:00:09 by ymanilow          #+#    #+#             */
/*   Updated: 2020/01/20 23:00:09 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WAYS_H
#define WAYS_H

#include "lem_in.h"

typedef struct					s_way
{
	struct s_way				*next;
	t_room						*room;
}								t_way;

typedef struct					s_ways
{
	int							col;
	t_way						**ways;
}								t_ways;

#endif
