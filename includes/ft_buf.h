/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:09:11 by ymanilow          #+#    #+#             */
/*   Updated: 2020/02/14 02:09:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUF_H
# define FT_BUF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define DEFAULT_BUFSIZE		4096

typedef struct			s_buf
{
	size_t				size;
	size_t				pos;
	size_t				printed;
	int					fd;
	char				*buf;
}						t_buf;

void					buf_init(int fd, size_t size);
void					buf_destroy(void);

char					*buf_get(size_t *elems);
void					buf_flush(void);
void					buf_flush_to(int fd);

void					buf_add_str(const char *str);
void					buf_add_chr(char chr, size_t times);

t_buf					**get_buf(void);


#endif
