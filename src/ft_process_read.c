/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:52:48 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 15:25:36 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_process_phase_0(char *line, int *phase, t_anthill *anthill)
{
	int		err;

	err = 1;
	if (ft_isint(line))
	{
		*phase = 1;
		if ((anthill->ant = ft_atoi(line)) >= 0)
			err = 0;
	}
	return (err);
}

static void	ft_set_opt(t_anthill *anthill, char *line)
{
	if (!ft_strcmp("##color", line))
		anthill->color = 1;
	else if (!ft_strcmp("##path", line))
		anthill->show_path = 1;
	else if (!ft_strcmp("##move", line))
		anthill->nbr_move = 1;
}

static int	ft_process_sharp(char *line, int phase, t_anthill *anthill)
{
	int		err;

	err = 1;
	if (!ft_strcmp("##color", line) || !ft_strcmp("##path", line)
		|| !ft_strcmp("##move", line))
	{
		ft_set_opt(anthill, line);
		err = 0;
	}
	else if (!ft_strcmp("##start", line) && phase == 1
		&& anthill->start < 0 && anthill->end > -2)
	{
		anthill->start--;
		err = 0;
	}
	else if (!ft_strcmp("##end", line) && phase == 1
		&& anthill->end < 0 && anthill->start > -2)
	{
		anthill->end--;
		err = 0;
	}
	else if (line[1] != '#' || (ft_strcmp("##start", line)
		&& ft_strcmp("##end", line)))
		err = 0;
	return (err);
}

void		ft_process_read(t_anthill *anthill)
{
	int			err;
	int			phase;
	char		*line;

	phase = 0;
	line = NULL;
	err = 0;
	while (!err && get_next_line(0, &line))
	{
		err = 1;
		if (line[0] == '#')
			err = ft_process_sharp(line, phase, anthill);
		else if (phase == 0)
			err = ft_process_phase_0(line, &phase, anthill);
		else if (phase == 1)
			err = ft_process_phase_1(line, &phase, anthill);
		else if (phase == 2)
			err = ft_process_phase_2(line, anthill);
		if (!err)
			ft_lstaddlast(&anthill->desc, ft_lstnew(line, ft_strlen(line) + 1));
	}
}
