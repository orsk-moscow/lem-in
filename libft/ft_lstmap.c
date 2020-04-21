/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:06:48 by klekisha          #+#    #+#             */
/*   Updated: 2020/04/21 11:55:30 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	if (elem)
		elem->next = ft_lstmap(lst->next, f);
	if (elem->next == NULL && lst->next != NULL)
	{
		free(elem);
		elem = NULL;
	}
	return (elem);
}
