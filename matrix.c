/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:09:49 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 17:37:17 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_mat		*ft_mat_translate(float x, float y, float z)
{
	t_mat *m;

	if ((m = (t_mat *)malloc(sizeof(t_mat))) == NULL)
		return (NULL);
	m->type = 't';
	m->a1 = 1;
	m->a2 = 0;
	m->a3 = 0;
	m->a4 = x;
	m->b1 = 0;
	m->b2 = 1;
	m->b3 = 0;
	m->b4 = y;
	m->c1 = 0;
	m->c2 = 0;
	m->c3 = 1;
	m->c4 = z;
	m->d1 = 0;
	m->d2 = 0;
	m->d3 = 0;
	m->d4 = 1;
	return (m);
}

t_mat		*ft_mat_scale(float x, float y, float z)
{
	t_mat *m;

	if ((m = (t_mat *)malloc(sizeof(t_mat))) == NULL)
		return (NULL);
	m->type = 's';
	m->a1 = x;
	m->a2 = 0;
	m->a3 = 0;
	m->a4 = 0;
	m->b1 = 0;
	m->b2 = y;
	m->b3 = 0;
	m->b4 = 0;
	m->c1 = 0;
	m->c2 = 0;
	m->c3 = z;
	m->c4 = 0;
	m->d1 = 0;
	m->d2 = 0;
	m->d3 = 0;
	m->d4 = 1;
	return (m);
}
