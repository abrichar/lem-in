/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_phase_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:51:27 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:51:28 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	**ft_init_link(int nb_room)
{
	int		i;
	int		j;
	int		**link;

	i = 0;
	link = (int**)malloc(sizeof(int*) * nb_room);
	while (i < nb_room)
	{
		j = 0;
		link[i] = (int*)malloc(sizeof(int) * nb_room);
		while (j < nb_room)
			link[i][j++] = 0;
		i++;
	}
	return (link);
}

int			ft_check_phase_2(char *line, int *phase, t_anthill *anthill)
{
	int		err;

	anthill->link = ft_init_link(anthill->nb_room);
	if (!(err = ft_process_phase_2(line, anthill)))
		*phase = 2;
	return (err);
}
