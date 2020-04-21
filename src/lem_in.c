/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:12:06 by u18188899         #+#    #+#             */
/*   Updated: 2020/04/21 12:12:07 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*init_input(t_graph *graph, t_data *data, int fd)
{
	t_room *tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->graph = graph;
	tmp->data = data;
	tmp->line = NULL;
	tmp->src = NULL;
	tmp->dst = NULL;
	tmp->name = NULL;
	tmp->start = 0;
	tmp->end = 0;
	tmp->x = 0;
	tmp->y = 0;
	tmp->fd = fd;
	tmp->i = 0;
	return (tmp);
}

int		main(void)
{
	int		fd;
	t_graph	*graph;
	t_paths	*paths;
	t_data	*data;
	t_room	*input;

	fd = 0;
	graph = init_graph();
	data = init_data();
	input = init_input(graph, data, fd);
	last_check(graph, input);
	connect_parents(graph->end);
	paths = init_paths();
	paths = solver(graph, paths);
	output(paths, input->data);
	delete_data(&data);
	delete_paths(&paths);
	delete_graph(&graph);
	free(input);
	return (0);
}
