#include "lem-in.h"

void    print_ant(int ant, char *name)
{
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(name);
}

int     put_ant(t_paths *paths, t_ants *ants, int i)
{
    t_path  *tmp;
    t_ant   *ant;

    tmp = paths->head;
    ant = ants->head;
    while (ant)
    {
        if (ant->node)
            ant->node = ant->node->save;
        ant = ant->next;
    }
    while (tmp && tmp->moves > 0)
    {
        addant(ants, tmp->node, i++);
        tmp->moves--;
        tmp = tmp->next;
    }
    return (i);
}

void    print_line(t_ants *ants)
{
    t_ant   *tmp;
    char    *name;

    tmp = ants->head;
    while (tmp)
    {
        if (tmp->node)
        {
            name = tmp->node->name;
            print_ant(tmp->number, name);
            if (tmp->next == NULL)
                ft_putchar('\n');
            else
                ft_putchar(' ');
        }
        tmp = tmp->next;
    }
}

void    output(t_paths *paths, t_graph *graph)
{
    t_ants  *ants;
    int     i;
    int     j;

    i = 1;
    j = 85;
    ants = init_ants();
    moves(paths);
    while (paths->num_moves--)
    {
        i = put_ant(paths, ants, i);
        print_line(ants);
    }
    delete_ants(&ants);
}
