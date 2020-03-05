//
// Created by Bears Gerda on 02/03/2020.
//

#ifndef GRAPH_H
#define GRAPH_H

/*
 * A structure to represent an adjacency list node
 */

typedef struct s_vertice_node   t_vertice_node;
typedef struct s_adjacent       t_adjacent;

struct s_adjacent
{
    char            *name;
    t_vertice_node  *elem_in_main_list;
    t_adjacent      *next;
};

struct s_vertice_node
{
    char 			*name;
    int 			x;
    int 			y;
    int				start;
    int 			end;
    t_adjacent      *neigbors;
    t_vertice_node  *next;
    t_vertice_node  *prev;
};

typedef struct		s_graph
{
    int 			size;
    t_vertice_node	*head;
    t_vertice_node	*tail;
}					t_graph;

typedef struct 		s_room
{
    int 			x;
    int 			y;
    char 			*name;
    int				start;
    int 			end;
}					t_room;


t_graph             *init_graph();
t_adjacent          *add_nieghbors();
int                 add_vertice_node(t_graph *graph, t_room *room);
void                push_nieghbors(t_vertice_node *vertice, char *name, t_vertice_node *ref);
t_vertice_node      *getnth(t_graph *graph, char *src, char *link, t_vertice_node **ref);
void                add_niegh_and_link (t_graph *graph, char *src, char *dst);
void                print_graph(t_graph *graph);


#endif
