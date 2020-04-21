/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:08:46 by klekisha          #+#    #+#             */
/*   Updated: 2020/03/14 12:08:47 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i1;
	char			*fresh;

	i1 = 0;
	if (!s || !f)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!fresh)
		return (NULL);
	while (s[i1])
	{
		fresh[i1] = f(i1, s[i1]);
		i1++;
	}
	fresh[i1] = '\0';
	return (fresh);
}
