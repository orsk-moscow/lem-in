/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:08:43 by klekisha          #+#    #+#             */
/*   Updated: 2020/03/14 12:08:43 by klekisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i1;
	char	*fresh;

	i1 = 0;
	if (!s || !f)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!fresh)
		return (NULL);
	while (s[i1])
	{
		fresh[i1] = f(s[i1]);
		i1++;
	}
	fresh[i1] = '\0';
	return (fresh);
}
