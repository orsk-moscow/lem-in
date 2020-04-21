/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:06:58 by klekisha          #+#    #+#             */
/*   Updated: 2020/03/14 12:06:59 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i1;
	unsigned char	*pd;
	unsigned char	*ps;

	i1 = 0;
	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	while (i1 < n)
	{
		*(pd + i1) = *(ps + i1);
		if (*(ps + i1) == (unsigned char)c)
		{
			return (pd + i1 + 1);
		}
		i1++;
	}
	return (NULL);
}
