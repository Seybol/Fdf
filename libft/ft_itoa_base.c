/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 04:00:42 by scebula           #+#    #+#             */
/*   Updated: 2015/12/03 20:16:06 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlength(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	ft_fill(int n, int sign, char *str, int base)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		k = n % base;
		str[i++] = (k > 9) ? (k - 10) + 'a' : (k + '0');
		n = n / base;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
}

char		*ft_itoa_base(int n, int base)
{
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		sign = 1;
		str = ft_strnew(ft_nlength(n));
		if (str == NULL)
			return (NULL);
		if (n < 0)
		{
			sign = -1;
			n = -n;
		}
		ft_fill(n, sign, str, base);
		ft_strrev(str);
		return (str);
	}
}
