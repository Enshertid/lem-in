/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:38:46 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/14 01:39:05 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_DATA_H
# define PRIVATE_DATA_H

# include <time.h>
# include "data.h"

t_uint64			get_flags(char **argv);
void				apply_flags(t_data *data);
void				add_z(t_coord *coords);
void				del_dead_lines(t_data *data);
void				mark_ways(t_data *data);

#endif
