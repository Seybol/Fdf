/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:20:24 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 17:38:23 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_init		*ft_init(t_point ***p)
{
	t_init *init;

	init = (t_init *)malloc(sizeof(t_init));
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, L, H, "mlx 42");
	init->map = p;
	init->mod = MULTI;
	init->depth = DEPTH;
	init->iso = DEGREE;
	init->rot = 0;
	init->z_max = ft_find_zmax(init);
	init->z_min = ft_find_zmin(init);
	init->center = ft_new_point(H / 2, L / 2, 0);
	ft_transformation(init, ft_mat_translate(OFFSET + 200, OFFSET - 250, 0));
	return (init);
}

float		ft_find_zmax(t_init *init)
{
	int		i;
	int		j;
	float	max;

	i = 0;
	j = 0;
	max = init->map[j][i]->z;
	while (init->map[j])
	{
		while (init->map[j][i])
		{
			if (init->map[j][i]->z > max)
				max = init->map[j][i]->z;
			i++;
		}
		i = 0;
		j++;
	}
	if (j > 200 || i > 200)
		while (init->mod > 4)
			ft_transformation(init, ft_mat_scale(1 / ZOOM, 1 / ZOOM, 0));
	else if (j > 30 || i > 30)
		while (init->mod > 7)
			ft_transformation(init, ft_mat_scale(1 / ZOOM, 1 / ZOOM, 0));
	return (max);
}

float		ft_find_zmin(t_init *init)
{
	int		i;
	int		j;
	float	min;

	i = 0;
	j = 0;
	min = init->map[j][i]->z;
	while (init->map[j])
	{
		while (init->map[j][i])
		{
			if (init->map[j][i]->z < min)
				min = init->map[j][i]->z;
			i++;
		}
		i = 0;
		j++;
	}
	return (min);
}

t_draw		*ft_init_drawing(t_point *a, t_point *b)
{
	t_draw *draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	draw->p = ft_new_point(a->x, a->y, a->z);
	draw->delta = ft_new_point(fabs(b->x - a->x), fabs(b->y - a->y), 0);
	draw->xincr = (a->x < b->x) ? 1 : -1;
	draw->yincr = (a->y < b->y) ? 1 : -1;
	draw->p->x = a->x;
	draw->p->y = a->y;
	draw->color = 0x009999;
	return (draw);
}

t_point		*ft_new_point(float x, float y, float z)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
