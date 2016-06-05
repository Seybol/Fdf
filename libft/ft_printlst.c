/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:43:58 by scebula           #+#    #+#             */
/*   Updated: 2015/12/03 20:47:27 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *list)
{
	t_list *l;

	l = list;
	while (l)
	{
		ft_putstr(l->content);
		ft_putchar('\n');
		l = l->next;
	}
}
