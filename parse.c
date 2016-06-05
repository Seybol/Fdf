/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:32:26 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 20:19:40 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		***ft_parse(int fd)
{
	t_point		***tab;
	char		*s;
	t_list		*list;
	int			i;

	list = NULL;
	tab = NULL;
	while ((i = get_next_line(fd, &s)))
	{
		if (i < 0)
			return (NULL);
		ft_lst_pushback(&list, s, ft_strlen(s) + 1);
		free(s);
		s = NULL;
	}
	if ((tab = ft_from_list_to_tab(&list)) == NULL)
	{
		ft_list_clear(&list);
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	ft_list_clear(&list);
	return (tab);
}

t_point		***ft_from_list_to_tab(t_list **list)
{
	t_list	*l;
	int		i;
	int		j;
	t_point	***tab;
	char	**split;

	l = *list;
	i = ft_listlen(l);
	if ((tab = (t_point ***)malloc(sizeof(t_point **) * (i + 1))) == NULL)
		return (NULL);
	j = -1;
	split = NULL;
	while (l)
	{
		split = ft_strsplit(l->content, ' ');
		if (!ft_tab_is_digits(split) || split == NULL)
			return (ft_error(tab, split, ++j));
		if (ft_extract(tab, split, ++j) == 0)
			return (NULL);
		l = l->next;
	}
	tab[++j] = NULL;
	return (tab);
}

void		*ft_error(t_point ***tab, char **split, int j)
{
	tab[j] = (t_point **)malloc(sizeof(char));
	tab[j + 1] = NULL;
	tab[j][0] = NULL;
	ft_free_tabs(tab, split);
	return (NULL);
}

void		ft_free_tabs(t_point ***tab, char **split)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			free(tab[j][i]);
			tab[j][i] = NULL;
			i++;
		}
		i = 0;
		free(tab[j]);
		tab[j] = NULL;
		++j;
	}
	free(tab);
	tab = NULL;
	if (split != NULL)
		free(split);
	split = NULL;
}

char		ft_extract(t_point ***tab, char **split, int j)
{
	int		i;
	float	z;

	i = -1;
	if (!(tab[j] = (t_point **)malloc(sizeof(t_point *) *
		(ft_tablen(split) + 1))))
		return (0);
	while (split[++i])
	{
		z = ft_atoi(split[i]);
		tab[j][i] = ft_new_point((i - j) * MULTI, (i + j) * MULTI / DEGREE, z);
		tab[j][i]->y -= (z * MULTI / DEPTH);
		free(split[i]);
		split[i] = NULL;
	}
	tab[j][i] = NULL;
	if (j > 0 && (ft_tablen_tpoint(tab[j]) != ft_tablen_tpoint(tab[j - 1])))
	{
		tab[j + 1] = NULL;
		ft_free_tabs(tab, split);
		return (0);
	}
	free(split);
	split = NULL;
	return (1);
}
