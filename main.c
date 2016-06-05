/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:25:44 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 20:16:59 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display(t_point ***p)
{
	t_init *init;

	init = ft_init(p);
	ft_cross(init);
	ft_draw(init);
	mlx_mouse_hook(init->win, ft_mouse, init);
	mlx_do_key_autorepeaton(init->mlx);
	mlx_hook(init->win, 2, 0L, ft_keyboard, init);
	mlx_loop(init->mlx);
}

void		ft_close(t_init *i)
{
	mlx_destroy_window(i->mlx, i->win);
	free(i);
	i = NULL;
	ft_putstr("Program closed successfully.\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_point		***points;
	int			fd;

	points = NULL;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 3)
		{
			if ((points = ft_parse(fd)) == NULL)
			{
				ft_putstr("Error ... \n");
				return (0);
			}
			display(points);
		}
	}
	ft_putstr("Error ... \n");
	return (0);
}
