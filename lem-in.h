#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft/libft.h"
#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define FILL_BUFF 100

int		test();
void	fill_graph(int fd, t_graph *graph);

void    ssp_finder(t_graph *graph);
void    print_ssp(t_graph *graph);


#endif //LEM_IN_H
