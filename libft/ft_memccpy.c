/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:04:25 by scebula           #+#    #+#             */
/*   Updated: 2015/11/27 20:56:04 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *source;
	char *desti;

	source = (char *)src;
	desti = (char *)dest;
	while (n > 0 && *source != c)
	{
		*desti++ = *source++;
		n--;
	}
	if (n > 0)
	{
		*desti = *source;
		desti++;
		return ((void*)desti);
	}
	return (NULL);
}
