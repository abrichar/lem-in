/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:52:16 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:52:16 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_init_path_ant(t_anthill *anthill)
{
	int		i;
	int		j;

	anthill->path_ant = (int**)malloc(sizeof(int*) * anthill->nb_path);
	i = 0;
	while (i < anthill->nb_path)
	{
		anthill->path_ant[i] = (int*)malloc(sizeof(int) * anthill->fill_ant[i]);
		j = 0;
		while (j < anthill->fill_ant[i])
			anthill->path_ant[i][j++] = 0;
		i++;
	}
}

static int	ft_not_end(t_anthill *anthill)
{
	int		i;
	int		j;

	i = 0;
	while (i < anthill->nb_path)
	{
		j = 0;
		while (j < anthill->fill_ant[i])
		{
			if (anthill->path_ant[i][j] < anthill->len_path[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_print_ant_2(t_anthill *anthill, int *num_ant, int *k, int i)
{
	int		j;
	int		br;

	j = -1;
	br = 0;
	while (++j < anthill->nb_path)
		if (i < anthill->fill_ant[j])
		{
			while (num_ant[*k])
				(*k)++;
			if (anthill->path_ant[j][i] < anthill->len_path[j])
			{
				br = (!anthill->path_ant[j][i]) ? 1 : 0;
				anthill->path_ant[j][i]++;
				(anthill->first++ > 0) ? ft_printf(" ") : 0;
				(anthill->color) ? ft_printf("\033[%dm", 31 + *k % 7) : 0;
				ft_printf("L%d", (*k)++ + 1);
				(anthill->color) ? ft_printf("\033[0m") : 0;
				ft_printf("-%s",
				anthill->room[anthill->path[j][anthill->path_ant[j][i]]]->name);
			}
			else
				num_ant[*k] = 1;
		}
	return (br);
}

void		ft_print_ant(t_anthill *anthill)
{
	int		i;
	int		k;
	int		*num_ant;

	num_ant = (int*)malloc(sizeof(int) * anthill->ant);
	ft_init_path_ant(anthill);
	while (ft_not_end(anthill))
	{
		i = 0;
		while (i < anthill->ant)
			num_ant[i++] = 0;
		k = 0;
		i = 0;
		anthill->first = 0;
		while (i < anthill->fill_ant[0])
		{
			if (ft_print_ant_2(anthill, num_ant, &k, i))
				break ;
			i++;
		}
		if (anthill->nbr_move)
			anthill->nbr_move++;
		ft_printf("\n");
	}
}
