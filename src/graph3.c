/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:02:33 by student           #+#    #+#             */
/*   Updated: 2020/03/27 19:02:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	popneigh(t_vertice_node *vertex)
{
	t_adjacent	*next;
	t_adjacent	*neigh;

	neigh = vertex->neighbors_tail;
	if (neigh == NULL)
		exit(1);
	next = vertex->neighbors_tail;
	vertex->neighbors_tail = vertex->neighbors_tail->prev;
	if (vertex->neighbors_tail)
		vertex->neighbors_tail->next = NULL;
	if (next == vertex->neighbors_head)
		vertex->neighbors_head = NULL;
	free(next->name);
	free(next);
}

void	popvertex(t_graph *graph)
{
	t_vertice_node	*next;
	t_vertice_node	*tmp;

	tmp = graph->tail;
	if (tmp == NULL)
		exit(1);
	next = graph->tail;
	graph->tail = graph->tail->prev;
	if (graph->tail)
		graph->tail->next = NULL;
	if (next == graph->head)
		graph->head = NULL;
	graph->size--;
	free(next->name);
	free(next);
}

void	tail_pop(t_graph *graph)
{
	t_vertice_node	*tmp;

	while (graph->tail->name[0] == 'L')
	{
		tmp = graph->tail;
		while (tmp->neighbors_head)
			popneigh(tmp);
		popvertex(graph);
	}
}

void	stick_toghether(t_graph *graph)
{
	t_vertice_node	*tmp;
	t_adjacent		*neigh;

	tmp = graph->head;
	while (tmp && tmp->name[0] != 'L')
	{
		neigh = tmp->neighbors_tail;
		while (neigh)
		{
			neigh->visit = 1;
			neigh->weight = 1;
			if (neigh->name && neigh->name[0] == 'L')
			{
				popneigh(tmp);
				neigh = tmp->neighbors_tail;
			}
			else
				neigh = neigh->prev;
		}
		tmp = tmp->next;
	}
	tail_pop(graph);
}
