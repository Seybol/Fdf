/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:11:48 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 17:35:16 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		ft_tab_is_digits(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]) == 1 && s[i][0] == '-')
			return (0);
		if (ft_isdigits(s[i]) || (s[i][0] == '-' && ft_isdigits(s[i] + 1)))
			(void)i;
		else if (!ft_isdigits(s[i]) && !ft_contain_more(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char		ft_contain_more(char *s)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	if (s[i] == '-')
	{
		++i;
		neg = 1;
	}
	while (ft_isdigit(s[i]))
		++i;
	if (neg && i > 1)
	{
		while (s[i])
			s[i++] = '\0';
		return (1);
	}
	else if (neg == 0 && i > 0)
	{
		while (s[i])
			s[i++] = '\0';
		return (1);
	}
	return (0);
}

void		ft_legend(t_init *i)
{
	mlx_string_put(i->mlx, i->win, 30, 200, 0x0099FF,
			"          MOVEMENTS: W A S D ");
	mlx_string_put(i->mlx, i->win, 30, 300, 0x0099FF,
			"          ZOOM: Mouse Scroll v|^");
	mlx_string_put(i->mlx, i->win, 30, 400, 0x0099FF,
			"          DEPTH: R / F");
	mlx_string_put(i->mlx, i->win, 30, 500, 0x0099FF,
			"          REPLACE FIGURE: R-Click");
	mlx_string_put(i->mlx, i->win, 30, 600, 0x0099FF,
			"          REPLACE ROTATION CENTER: L-Click");
	mlx_string_put(i->mlx, i->win, 30, 1100, 0xFF0000,
			"          __CLOSE__ : Escape");
}

void		ft_cross(t_init *init)
{
	int i;
	int j;
	int tmp;

	i = init->center->x - 10;
	j = init->center->y;
	tmp = i + 20;
	while (i <= tmp)
	{
		mlx_pixel_put(init->mlx, init->win, i, j, 0xFF7777);
		i++;
	}
	i -= 10;
	j -= 10;
	tmp = j + 20;
	while (j <= tmp)
	{
		mlx_pixel_put(init->mlx, init->win, i, j, 0xFF7777);
		j++;
	}
}

size_t		ft_tablen_tpoint(t_point **p)
{
	int		j;
	size_t	cpt;

	j = 0;
	cpt = 0;
	while (p[j++])
		cpt++;
	return (cpt);
}
