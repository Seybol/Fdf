/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:26:54 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 20:17:49 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		ft_edit_depth(t_init *init, float d)
{
	int i;
	int j;

	if (init->depth + d > 357 || init->depth + d < -2000)
		return ;
	i = 0;
	j = 0;
	ft_rotate(init, init->center->x, init->center->y, -init->rot);
	while (init->map[j])
	{
		while (init->map[j][i])
		{
			init->map[j][i]->y += init->map[j][i]->z * init->mod / d;
			i++;
		}
		i = 0;
		j++;
	}
	init->depth += d;
	ft_rotate(init, init->center->x, init->center->y, init->rot);
}

void		ft_rotate(t_init *init, float x, float y, double deg)
{
	int		i;
	int		j;
	float	l1;
	float	l2;

	i = 0;
	j = 0;
	while (init->map[j])
	{
		while (init->map[j][i])
		{
			l1 = init->map[j][i]->x - x;
			l2 = init->map[j][i]->y - y;
			init->map[j][i]->x = x + (l1 * cos(deg / 180 * M_PI)) -
				(l2 * sin(deg / 180 * M_PI));
			init->map[j][i]->y = y + (l1 * sin(deg / 180 * M_PI)) +
				(l2 * cos(deg / 180 * M_PI));
			i++;
		}
		i = 0;
		j++;
	}
}

char		ft_transformation(t_init *i, t_mat *m)
{
	int		k;
	int		j;
	t_point	*t;

	k = -1;
	j = -1;
	if (!m)
		return (0);
	while (i->map[++j])
	{
		while (i->map[j][++k])
		{
			t = ft_new_point(i->map[j][k]->x, i->map[j][k]->y, i->map[j][k]->z);
			i->map[j][k]->x = m->a1 * t->x + m->a2 * t->y + m->a3 * t->z +
				m->a4;
			i->map[j][k]->y = m->b1 * t->x + m->b2 * t->y + m->b3 * t->z +
				m->b4;
		}
		k = -1;
	}
	if (m->type == 's')
		i->mod *= m->a1;
	free(m);
	m = NULL;
	return (1);
}
