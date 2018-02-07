/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_phase_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:52:29 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:52:31 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_freeroom(t_room **room, int nb_room)
{
	int		i;

	i = 0;
	while (i < nb_room)
	{
		free(room[i]->name);
		free(room[i++]);
	}
	free(room);
}

static t_room	*ft_initroom(char *name, int x, int y)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->x = x;
	room->y = y;
	return (room);
}

static void		ft_addroom(t_anthill *anthill, t_room *new)
{
	int		i;
	t_room	**room;

	i = 0;
	room = (t_room**)malloc(sizeof(t_room*) * (anthill->nb_room + 1));
	while (i < anthill->nb_room)
	{
		room[i] = ft_initroom(anthill->room[i]->name, anthill->room[i]->x,
			anthill->room[i]->y);
		i++;
	}
	room[i] = ft_initroom(new->name, new->x, new->y);
	free(new->name);
	free(new);
	ft_freeroom(anthill->room, anthill->nb_room);
	anthill->room = room;
}

static int		ft_test_space_line(char *line)
{
	int		i;
	int		nb_space;

	i = 0;
	nb_space = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			nb_space++;
		i++;
	}
	if (nb_space == 0)
		nb_space = 1;
	return (nb_space);
}

int				ft_process_phase_1(char *line, int *phase, t_anthill *ah)
{
	int		err;
	char	**tab;
	t_room	*room;

	err = ft_test_space_line(line);
	if (err == 2)
	{
		tab = ft_strsplit(line, ' ');
		if (tab[0] && tab[0][0] != 'L' && tab[1] && ft_isint(tab[1])
			&& tab[2] && ft_isint(tab[2]) && !tab[3])
		{
			err = 0;
			room = ft_initroom(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
			ft_addroom(ah, room);
			ah->start = ah->start < -1 ? ah->nb_room : ah->start;
			ah->end = ah->end < -1 ? ah->nb_room : ah->end;
			ah->nb_room++;
		}
		ft_freetab(tab);
	}
	if (err && ft_strchr(line, '-'))
		err = ft_check_phase_2(line, phase, ah);
	return (err);
}
