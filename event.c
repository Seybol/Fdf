/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:16:03 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 20:13:17 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyboard(int keycode, void *init)
{
	t_init *i;

	i = (t_init *)init;
	ft_translation_management(keycode, i);
	if (keycode == 15)
		ft_edit_depth(i, -50);
	if (keycode == 3)
		ft_edit_depth(i, 50);
	if (keycode == 14)
	{
		ft_rotate(i, i->center->x, i->center->y, 10);
		i->rot += 10;
	}
	if (keycode == 12)
	{
		ft_rotate(i, i->center->x, i->center->y, -10);
		i->rot -= 10;
	}
	if (keycode == 53)
		ft_close(i);
	mlx_clear_window(i->mlx, i->win);
	ft_cross(init);
	ft_draw(i);
	return (1);
}

void	ft_translation_management(int keycode, t_init *i)
{
	if (keycode == 0)
		ft_transformation(i, ft_mat_translate(-20, 0, 0));
	if (keycode == 2)
		ft_transformation(i, ft_mat_translate(20, 0, 0));
	if (keycode == 1)
		ft_transformation(i, ft_mat_translate(0, 20, 0));
	if (keycode == 13)
		ft_transformation(i, ft_mat_translate(0, -20, 0));
}

int		ft_mouse(int button, int x, int y, void *param)
{
	t_init *i;

	i = (t_init *)param;
	if (button == 5)
		ft_zoom(i, x, y, ZOOM);
	if (button == 4)
		ft_zoom(i, x, y, 1 / ZOOM);
	if (button == 1)
	{
		i->center->x = x;
		i->center->y = y;
	}
	if (button == 2)
	{
		ft_transformation(i,
				ft_mat_translate(-i->map[0][0]->x, -i->map[0][0]->y, 0));
		ft_transformation(i, ft_mat_translate(x, y, 0));
	}
	mlx_clear_window(i->mlx, i->win);
	ft_draw(i);
	ft_cross(i);
	return (1);
}

void	ft_zoom(t_init *i, int x, int y, float z)
{
	ft_transformation(i, ft_mat_translate(-x, -y, 0));
	ft_transformation(i, ft_mat_scale(z, z, 0));
	ft_transformation(i, ft_mat_translate(x, y, 0));
}
