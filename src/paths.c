/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:25:33 by student           #+#    #+#             */
/*   Updated: 2020/03/27 18:25:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "graph.h"

t_paths		*init_paths(void)
{
	t_paths	*tmp;

	tmp = (t_paths *)malloc(sizeof(t_path));
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->amt_paths = 0;
	tmp->num_moves = 0;
	tmp->paths_len = 0;
	tmp->ants = 0;
	return (tmp);
}

void		delete_paths(t_paths **paths)
{
	t_path	*tmp;
	t_path	*next;

	tmp = (*paths)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*paths);
	(*paths) = NULL;
}

int			path_len(t_vertice_node *node)
{
	t_vertice_node	*tmp;
	int				i;

	i = 0;
	tmp = node;
	while (tmp)
	{
		i++;
		tmp = tmp->to;
	}
	return (i);
}

void		addback(t_paths *paths, t_vertice_node *data)
{
	t_path	*tmp;

	tmp = (t_path *)malloc(sizeof(t_path));
	if (tmp == NULL)
		exit(3);
	tmp->node = data;
	tmp->next = NULL;
	tmp->prev = paths->tail;
	if (paths->tail)
		paths->tail->next = tmp;
	paths->tail = tmp;
	if (paths->head == NULL)
		paths->head = tmp;
	tmp->length = path_len(data);
	tmp->moves = 0;
	paths->amt_paths++;
	paths->paths_len += tmp->length;
}

void		save_path(t_vertice_node *node)
{
	t_vertice_node *tmp;

	tmp = node;
	while (tmp)
	{
		tmp->save = tmp->to;
		tmp = tmp->to;
	}
}
