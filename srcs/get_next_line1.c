/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:42:04 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/13 21:25:11 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define GNL_BUFF 1024

void				ft_lstappend(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		new->end = new;
	}
	else
	{
		(*list)->end->next = new;
		(*list)->end = new;
	}
}

static void			add_in_bufs(t_list **bufs, const char *src, size_t strlen,
																		int fd)
{
	char *str;

	str = ft_strnew(strlen);
	ft_memcpy(str, src, strlen);
	ft_lstappend(bufs, ft_lstnew(str, strlen + 1));
	(*bufs)->end->content_size = fd;
	free(str);
}

static int			check_bufs(t_list **bufs, t_list **buf, int fd)
{
	t_list			*iter;
	char			*npos;
	char			*temp;

	iter = *bufs;
	while (iter && (int)iter->content_size != fd)
		iter = iter->next;
	if (!iter)
		return (0);
	npos = (char*)ft_memchr(iter->content, '\n', ft_strlen(iter->content));
	ft_lstappend(buf, ft_lstnew(iter->content, npos ?
										(size_t)(npos - (char*)iter->content) :
										(size_t)ft_strlen(iter->content)));
	if (!npos || (npos && !npos[1]))
		ft_lstdelete(bufs, &iter);
	else if (npos[1])
	{
		temp = ft_strdup(npos + 1);
		free(iter->content);
		iter->content = temp;
	}
	return (npos ? 1 : 0);
}

static char			*lst_to_str(const t_list *list)
{
	char			*str;
	char			*striter;
	const t_list	*lstiter;
	size_t			len;

	len = 0;
	lstiter = list;
	while (lstiter)
	{
		len += lstiter->content_size;
		lstiter = lstiter->next;
	}
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	striter = str;
	while (list)
	{
		ft_memcpy(striter, list->content, list->content_size);
		striter += list->content_size;
		list = list->next;
	}
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*bufs = NULL;
	t_list			*buf;
	ssize_t			ret;
	char			*npos;
	char			str[GNL_BUFF];

	if (fd < 0 || !GNL_BUFF || read(fd, str, 0) < 0 || (buf = NULL))
		return (-1);
	if (!check_bufs(&bufs, &buf, fd))
	{
		while ((ret = read(fd, str, GNL_BUFF)))
		{
			npos = (char*)ft_memchr(str, '\n', ret);
			ft_lstappend(&buf, ft_lstnew(str, npos ? npos - str : ret));
			if (npos)
				break ;
		}
		if (!ret && !buf)
			return (0);
		if (ret && npos && npos - str != ret - 1)
			add_in_bufs(&bufs, npos + 1, ret - 1 - (npos - str), fd);
	}
	*line = lst_to_str(buf);
	ft_lstpurge(&buf);
	return (*line ? 1 : -1);
}
