/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:48:35 by scebula           #+#    #+#             */
/*   Updated: 2015/12/04 00:25:07 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *source;
	char *desti;

	source = (char *)src;
	desti = (char *)dst;
	while (n > 0)
	{
		*desti = *source;
		desti++;
		source++;
		n--;
	}
	return (dst);
}
