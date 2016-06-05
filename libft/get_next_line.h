/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:58:25 by scebula           #+#    #+#             */
/*   Updated: 2016/02/24 19:57:17 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct			s_data
{
	t_list				*l;
	int					sp;
	size_t				i;
	ssize_t				ret;
	char				*s;
	char				*tmp;
	char				*t;
}						t_data;
int						get_next_line(int const fd, char **line);
void					ft_list_to_string(t_data **d, size_t i, char **line);
void					ft_init_data(t_data **d, int fd, char **line);
void					ft_init_data_2(t_data **d, char **line, int fd);
int						ft_free_data(t_data **d);
#endif
