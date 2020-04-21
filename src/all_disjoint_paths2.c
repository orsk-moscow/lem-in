/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_disjoint_paths2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:12:40 by u18188899         #+#    #+#             */
/*   Updated: 2020/04/21 12:12:41 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		combine_paths(t_vertice_node *start, t_vertice_node *end)
{
	t_vertice_node	*a;
	t_vertice_node	*b;

	b = end;
	while ((a = b->parent) != NULL)
	{
		if (a->from != b && b->to != a)
		{
			if (a != start)
				a->to = b;
			if (b != end)
				b->from = a;
		}
		else
		{
			if (a->from == b)
				a->from = NULL;
			if (b->to == a)
				b->to = NULL;
		}
		b = a;
	}
}

void		divide_vertex(t_graph *graph)
{
	t_vertice_node	*tmp;
	t_adjacent		*cur_vertex;

	cur_vertex = graph->start->neighbors_head;
	while (cur_vertex)
	{
		tmp = cur_vertex->elem_in_main_list;
		while (tmp->to && tmp != graph->end)
		{
			vertex_dup(graph, tmp);
			tmp = tmp->to;
		}
		cur_vertex = cur_vertex->next;
	}
}
