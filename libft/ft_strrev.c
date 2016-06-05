/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:38:52 by scebula           #+#    #+#             */
/*   Updated: 2015/11/28 01:44:40 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char tmp;
	char *rev;

	rev = s + ft_strlen(s) - 1;
	while (s < rev)
	{
		tmp = *s;
		*s = *rev;
		*rev = tmp;
		s++;
		rev--;
	}
}
