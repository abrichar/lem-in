/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:51:11 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:51:11 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_cross_path(t_anthill *anthill, int *num_path,
	int check_path, int path_sup)
{
	int		i;
	int		j;

	i = 1;
	while (anthill->path[*num_path][i] != anthill->end
		&& i < anthill->nb_room)
	{
		j = 1;
		while (anthill->path[check_path][j] != anthill->end
			&& anthill->path[check_path][j] != -1 && j < anthill->nb_room)
		{
			if (anthill->path[check_path][j] == anthill->path[*num_path][i])
			{
				ft_sup_path(anthill, check_path, path_sup);
				if (check_path < *num_path)
					*num_path = *num_path - 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_path_end(t_anthill *anthill, int num_path, int path_sup)
{
	int		i;
	int		sup;

	i = 0;
	while (i < anthill->nb_path - path_sup)
	{
		sup = 0;
		if (i != num_path)
			sup = ft_check_cross_path(anthill, &num_path, i, path_sup);
		if (!sup)
			i++;
		else
			path_sup++;
	}
	return (path_sup);
}

int			ft_check_end(t_anthill *anthill, int num)
{
	int		i;
	int		path_sup;

	i = 0;
	path_sup = 0;
	while (i < anthill->nb_path - path_sup)
	{
		if (anthill->path[i][num + 1] != -1
			&& anthill->path[i][num + 1] == anthill->end)
			path_sup = ft_check_path_end(anthill, i, path_sup);
		i++;
	}
	return (path_sup);
}
