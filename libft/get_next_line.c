/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:58:34 by scebula           #+#    #+#             */
/*   Updated: 2016/04/26 21:55:11 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void			ft_init_data(t_data **d, int fd, char **line)
{
	if (!*d)
	{
		if ((*d = (t_data *)malloc(sizeof(t_data))) == NULL)
			return ;
		(*d)->l = ft_lstnew("", 1);
		(*d)->i = 0;
	}
	(*d)->sp = 0;
	(*d)->tmp = ft_strnew(BUFF_SIZE);
	(*d)->t = (*d)->tmp;
	while (((*d)->ret = read(fd, (*d)->tmp, BUFF_SIZE)) > 0)
	{
		(*d)->tmp[(*d)->ret] = '\0';
		ft_lst_pushback(&((*d)->l), (*d)->tmp, (size_t)(*d)->ret + 1);
		(*d)->i += (size_t)(*d)->ret;
		if (((*d)->sp = ft_strrchr_n((*d)->tmp, '\n')))
			break ;
	}
	if ((*d)->ret <= 0 && (*d)->i == 0)
		return ;
	ft_list_to_string(&(*d), (*d)->i, line);
}

void			ft_init_data_2(t_data **d, char **line, int fd)
{
	(*d)->i = 0;
	while ((*d)->tmp[(*d)->i] != '\n' && (*d)->tmp[(*d)->i])
		(*d)->i++;
	if (!(*d)->tmp[(*d)->i])
	{
		(*d)->l = ft_lstnew("", 1);
		if ((*d)->i != 0)
			ft_lst_pushback(&(*d)->l, ft_strndup((*d)->tmp, (*d)->i),
					(*d)->i + 1);
		free((*d)->t);
		(*d)->t = NULL;
		ft_init_data(&(*d), fd, line);
	}
	else
	{
		*line = ft_strndup((*d)->tmp, (*d)->i);
		(*d)->tmp = (*d)->tmp + (*d)->i + 1;
	}
}

void			ft_list_to_string(t_data **d, size_t i, char **line)
{
	t_list *list;

	list = (*d)->l->next;
	(*d)->t = NULL;
	(*d)->s = ft_strnew(i);
	while (list->next)
	{
		ft_strcat((*d)->s, (const char*)list->content);
		list = list->next;
	}
	ft_strncat((*d)->s, (const char*)(list->content), (size_t)(*d)->sp - 1);
	free((*d)->tmp);
	(*d)->tmp = NULL;
	(*d)->tmp = ft_strdup(list->content);
	(*d)->t = (*d)->tmp;
	list = (*d)->l;
	(*d)->tmp += (*d)->sp;
	ft_list_clear(&((*d)->l));
	(*d)->l = NULL;
	*line = ft_strdup((*d)->s);
	free((*d)->s);
	(*d)->s = NULL;
}

int				get_next_line(int const fd, char **line)
{
	static t_data	*d[256];

	if (line == NULL || fd < 0 || BUFF_SIZE < 1 || fd > 255)
		return (-1);
	if (d[fd] && d[fd]->ret == 0)
	{
		ft_free_data(&(d[fd]));
		return (0);
	}
	if (!d[fd])
	{
		ft_init_data(&d[fd], fd, line);
		if (!d[fd])
			return (-1);
	}
	else
		ft_init_data_2(&d[fd], line, fd);
	if (d[fd]->ret <= 0)
	{
		d[fd]->sp = (d[fd]->l != NULL) ? (d[fd]->sp + 1) : d[fd]->sp;
		if ((d[fd]->ret == 0) && (d[fd]->sp == 0))
			return (1);
		return (ft_free_data(&(d[fd])));
	}
	return (1);
}

int				ft_free_data(t_data **d)
{
	int i;

	i = (int)(*d)->ret;
	if (!(*d) && i < 0)
		return (i);
	if ((*d)->t != NULL)
	{
		free((*d)->t);
		(*d)->t = NULL;
	}
	ft_list_clear(&(*d)->l);
	if (*d != NULL)
		free(*d);
	*d = NULL;
	return (i);
}
