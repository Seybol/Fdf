/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:14:32 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 20:24:14 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		ft_free_draw(t_draw *d)
{
	free(d->delta);
	d->delta = NULL;
	free(d->p);
	d->p = NULL;
	free(d);
	d = NULL;
}

char		ft_draw_line(t_init *i, t_point *a, t_point *b)
{
	t_draw *d;

	if (!(d = ft_init_drawing(a, b)))
		return (0);
	if ((a->z == i->z_max) && (b->z == i->z_max))
		d->color = 0x00FFFF;
	else if ((a->z == i->z_min) && (b->z == i->z_min))
		d->color = 0x004545;
	else if ((a->z == i->z_max) && (b->z != i->z_max && b->z > i->z_min))
		d->color = 0x005555;
	else if ((b->z == i->z_max) && (a->z > i->z_min && a->z != i->z_max))
		d->color = 0x005555;
	else if ((a->z > i->z_min || a->z < i->z_max) &&
			(b->z > i->z_min || b->z < i->z_max))
		d->color = 0x007575;
	if (d->delta->x > d->delta->y)
		ft_draw_case_1(d, i);
	else
		ft_draw_case_2(d, i);
	mlx_pixel_put(i->mlx, i->win, a->x, a->y, 0x004545);
	mlx_pixel_put(i->mlx, i->win, b->x, b->y, 0x004545);
	ft_free_draw(d);
	return (1);
}

char		ft_draw(t_init *init)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (init->map[j])
	{
		while (init->map[j][i])
		{
			if (init->map[j][i + 1])
				if (!ft_draw_line(init, init->map[j][i], init->map[j][i + 1]))
					return (0);
			if (init->map[j + 1])
				if (!ft_draw_line(init, init->map[j][i], init->map[j + 1][i]))
					return (0);
			i++;
		}
		j++;
		i = 0;
	}
	if (j == 1 && i == 0)
		mlx_pixel_put(init->mlx, init->win, init->map[0][0]->x,
				init->map[0][0]->y, 0x00AAAA);
	ft_legend(init);
	return (1);
}

void		ft_draw_case_1(t_draw *d, t_init *init)
{
	int i;

	d->error = d->delta->x / 2;
	i = 0;
	while (i < d->delta->x)
	{
		d->p->x += d->xincr;
		d->error += d->delta->y;
		if (d->error > d->delta->x)
		{
			d->error -= d->delta->x;
			d->p->y += d->yincr;
		}
		mlx_pixel_put(init->mlx, init->win, d->p->x, d->p->y, d->color);
		i++;
	}
}

void		ft_draw_case_2(t_draw *d, t_init *init)
{
	int i;

	d->error = d->delta->y / 2;
	i = 0;
	while (i < d->delta->y)
	{
		d->p->y += d->yincr;
		d->error += d->delta->x;
		if (d->error > d->delta->y)
		{
			d->error -= d->delta->y;
			d->p->x += d->xincr;
		}
		mlx_pixel_put(init->mlx, init->win, d->p->x, d->p->y, d->color);
		i++;
	}
}
