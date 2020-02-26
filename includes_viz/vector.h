/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:46 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/26 17:02:47 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define __INFO		(sizeof(size_t) << 2)

# include <stddef.h>

typedef struct		s_memory
{
	void			*ptr;
	struct s_memory	*next;
}					t_memory;

void				vec_pushback(void *ptr, void *elem);
void				vec_delelem(void *vecptr, size_t pos);
void				*vec_init(size_t rows, size_t elems, size_t type_size);
void				vec_clear(void *ptr);
void				vec_addrow(void *ptr, size_t elems);
void				vec_cut(void *ptr);
void				*vec_cp(void *ptr);
size_t				vec_size(const void *vec);
size_t				vec_free(const void *vec);
size_t				vec_tpsz(const void *vec);
size_t				vec_rows(const void *vec);
void				vec_set_size(void *vec, size_t size);

#endif
