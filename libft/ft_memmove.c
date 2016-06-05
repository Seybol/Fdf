/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:37:47 by scebula           #+#    #+#             */
/*   Updated: 2015/12/04 00:26:22 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *desti;
	char *source;

	desti = (char*)dst;
	source = (char*)src;
	if (source <= desti)
	{
		while (len > 0)
		{
			*(desti + len - 1) = *(source + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(desti, source, len);
	return (dst);
}
