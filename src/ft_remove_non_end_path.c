/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_non_end_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:52:55 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:52:56 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_non_end_path(t_anthill *anthill)
{
	int		i;
	int		j;
	int		sup;
	int		path_sup;

	path_sup = 0;
	i = 0;
	while (i < anthill->nb_path - path_sup)
	{
		sup = 0;
		j = 0;
		while (anthill->path[i][j] != anthill->end && anthill->path[i][j] != -1
			&& j < anthill->nb_room)
			j++;
		if (j == anthill->nb_room || anthill->path[i][j] != anthill->end)
			sup = ft_sup_path(anthill, i, path_sup++);
		if (!sup)
			i++;
	}
	anthill->nb_path -= path_sup;
}
