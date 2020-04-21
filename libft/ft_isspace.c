/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:06:23 by klekisha          #+#    #+#             */
/*   Updated: 2020/03/14 12:06:24 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char		t;

	t = (unsigned char)c;
	if (t == ' ' || t == '\n' || t == '\t' || t == '\v' || t == '\f'
			|| t == '\r')
		return (c);
	return (0);
}