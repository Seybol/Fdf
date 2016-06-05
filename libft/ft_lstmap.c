/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:20:43 by scebula           #+#    #+#             */
/*   Updated: 2015/12/04 00:07:45 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first_element;
	t_list *next_element;
	t_list *previous_element;

	first_element = NULL;
	first_element = f(lst);
	previous_element = first_element;
	lst = lst->next;
	while (lst)
	{
		next_element = f(lst);
		previous_element->next = next_element;
		previous_element = next_element;
		lst = lst->next;
	}
	previous_element->next = NULL;
	return (first_element);
}
