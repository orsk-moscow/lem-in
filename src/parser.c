/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:11:52 by u18188899         #+#    #+#             */
/*   Updated: 2020/04/21 12:11:53 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "libft.h"

t_data	*init_data(void)
{
	t_data	*tmp;

	tmp = (t_data *)malloc(sizeof(t_data));
	tmp->str = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_data	*add_data(t_data *data, char *str)
{
	t_data	*tmp;

	tmp = data;
	if (tmp->str == NULL)
		tmp->str = ft_strdup(str);
	else
	{
		tmp = (t_data *)malloc(sizeof(t_data));
		tmp->str = ft_strdup(str);
		tmp->next = NULL;
		data->next = tmp;
	}
	return (tmp);
}

void	print_data(t_data *head)
{
	while (head)
	{
		ft_putendl(head->str);
		head = head->next;
	}
}

void	delete_data(t_data **data)
{
	t_data *tmp;
	t_data *next;

	tmp = *data;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = next;
	}
	*data = NULL;
}
