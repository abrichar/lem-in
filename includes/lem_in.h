/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:49:51 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 16:26:22 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct	s_room
{
	int		x;
	int		y;
	char	*name;
}				t_room;

typedef struct	s_anthill
{
	int		color;
	int		show_path;
	int		nbr_move;
	int		start;
	int		end;
	int		first;
	int		nb_room;
	int		nb_link;
	int		nb_path;
	int		ant;
	int		**link;
	int		**path;
	int		*len_path;
	int		*fill_ant;
	int		**path_ant;
	t_room	**room;
	t_list	*desc;
}				t_anthill;

void			ft_process_read(t_anthill *anthill);
int				ft_process_phase_1(char *line, int *phase, t_anthill *anthill);
int				ft_check_phase_2(char *line, int *phase, t_anthill *anthill);
int				ft_process_phase_2(char *line, t_anthill *anthill);
void			ft_find_path(t_anthill *anthill, int n);
int				ft_check_end(t_anthill *anthill, int num);
int				ft_sup_path(t_anthill *anthill, int num_path, int path_sup);
void			ft_remove_non_end_path(t_anthill *anthill);
void			ft_set_len_path(t_anthill *anthill);
void			ft_set_ant_path(t_anthill *anthill);
void			ft_print_ant(t_anthill *anthill);
int				ft_isint(char *arg);
void			ft_freetab(char **tab);
void			ft_freedim2(void **tab, size_t len);
#endif
