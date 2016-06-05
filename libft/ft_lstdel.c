/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:10:34 by scebula           #+#    #+#             */
/*   Updated: 2015/11/26 13:12:44 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *robin;
	t_list *batman;

	batman = *alst;
	while (batman != NULL)
	{
		robin = batman->next;
		ft_lstdelone(&batman, del);
		batman = robin;
	}
	*alst = NULL;
}
