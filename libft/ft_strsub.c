/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:09:24 by klekisha          #+#    #+#             */
/*   Updated: 2020/03/14 12:09:24 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i1;
	char	*fresh;

	i1 = 0;
	if (!s)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	while (i1 < len)
	{
		fresh[i1] = s[start + i1];
		i1++;
	}
	fresh[i1] = '\0';
	return (fresh);
}
