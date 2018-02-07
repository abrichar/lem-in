/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:50:30 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 15:25:28 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_anthill	*ft_init_anthill(void)
{
	t_anthill	*anthill;

	anthill = (t_anthill*)malloc(sizeof(t_anthill));
	anthill->color = 0;
	anthill->show_path = 0;
	anthill->nbr_move = 0;
	anthill->start = -1;
	anthill->end = -1;
	anthill->first = 0;
	anthill->nb_room = 0;
	anthill->nb_link = 0;
	anthill->nb_path = 1;
	anthill->ant = 0;
	anthill->link = NULL;
	anthill->path = NULL;
	anthill->len_path = NULL;
	anthill->fill_ant = NULL;
	anthill->path_ant = NULL;
	anthill->room = NULL;
	anthill->desc = NULL;
	return (anthill);
}

static void			ft_print_desc(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", (char*)list->content);
		list = list->next;
	}
	ft_printf("\n");
}

static int			**ft_init_path(t_anthill *anthill)
{
	int		i;
	int		**path;

	path = NULL;
	if (anthill->start >= 0 && anthill->end >= 0)
	{
		i = 1;
		path = (int**)malloc(sizeof(int*));
		path[0] = (int*)malloc(sizeof(int) * anthill->nb_room);
		path[0][0] = anthill->start;
		while (i < anthill->nb_room)
			path[0][i++] = -1;
	}
	return (path);
}

static void			ft_print_path(t_anthill *anthill)
{
	int		i;
	int		j;

	i = 0;
	while (i < anthill->nb_path)
	{
		j = 0;
		ft_printf("path %d:", i + 1);
		while (j < anthill->nb_room && anthill->path[i][j] != -1)
			ft_printf(" %s", anthill->room[anthill->path[i][j++]]->name);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

int					main(void)
{
	int			err;
	t_anthill	*anthill;

	err = 1;
	anthill = ft_init_anthill();
	ft_process_read(anthill);
	if (anthill->link)
		if ((anthill->path = ft_init_path(anthill)))
		{
			ft_find_path(anthill, 0);
			ft_remove_non_end_path(anthill);
			if (anthill->nb_path)
			{
				err = 0;
				ft_set_len_path(anthill);
				ft_set_ant_path(anthill);
				ft_print_desc(anthill->desc);
				(anthill->show_path) ? ft_print_path(anthill) : NULL;
				ft_print_ant(anthill);
				if (anthill->nbr_move)
					ft_printf("\nNumber move: %d\n", anthill->nbr_move - 1);
			}
		}
	(err) ? ft_printf("ERROR\n") : 0;
	return (0);
}
