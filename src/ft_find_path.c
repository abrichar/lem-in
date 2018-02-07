/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:51:42 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:51:46 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_add_path(t_anthill *anthill, int num_path, int num_room,
	int path_add)
{
	int		i;
	int		j;
	int		**path;

	if (anthill->path[num_path][num_room + 1] == -1)
		return (0);
	path = (int**)malloc(sizeof(int*) * (anthill->nb_path + path_add + 1));
	i = -1;
	while (++i < anthill->nb_path + path_add)
	{
		path[i] = (int*)malloc(sizeof(int) * anthill->nb_room);
		j = -1;
		while (++j < anthill->nb_room)
			path[i][j] = anthill->path[i][j];
	}
	path[i] = (int*)malloc(sizeof(int) * anthill->nb_room);
	j = -1;
	while (++j < anthill->nb_room)
		path[i][j] = anthill->path[num_path][j];
	ft_freedim2((void**)anthill->path, anthill->nb_path + path_add);
	anthill->path = path;
	return (i);
}

static int	ft_check_path(t_anthill *anthill, int room)
{
	int		i;
	int		j;
	int		ret;

	ret = 1;
	if (room != anthill->end)
	{
		i = 0;
		while (i < anthill->nb_path)
		{
			j = 0;
			while (j < anthill->nb_room)
				if (anthill->path[i][j++] == room)
					ret = 0;
			i++;
		}
	}
	return (ret);
}

void		ft_find_path(t_anthill *anthill, int n)
{
	int		i;
	int		j;
	int		num_path;
	int		path_add;

	i = -1;
	path_add = 0;
	while (++i < anthill->nb_path)
		if (anthill->path[i][n] != anthill->end && anthill->path[i][n] != -1)
		{
			j = -1;
			while (++j < anthill->nb_room)
				if (anthill->link[anthill->path[i][n]][j]
					&& ft_check_path(anthill, j))
				{
					if (!(num_path = ft_add_path(anthill, i, n, path_add)))
						num_path = i;
					else if (num_path > 0)
						path_add++;
					anthill->path[num_path][n + 1] = j;
				}
		}
	anthill->nb_path += path_add;
	anthill->nb_path -= ft_check_end(anthill, n);
	return ((n < anthill->nb_room - 2) ? ft_find_path(anthill, n + 1) : NULL);
}
