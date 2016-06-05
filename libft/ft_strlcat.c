/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:58:06 by scebula           #+#    #+#             */
/*   Updated: 2015/12/03 22:20:35 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (size + srclen);
	i = (int)size;
	while (*dst && i >= 0)
	{
		dst++;
		i--;
	}
	while (*src && i-- > 1)
		*dst++ = *src++;
	if (i == 1)
		*dst++ = '\0';
	while (*dst)
	{
		*dst = '\0';
		dst++;
	}
	return (srclen + dstlen);
}
