/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:18:15 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/10 11:19:00 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int nbr)
{
	int i;

	i = -1;
	while (str[++i] && (i < nbr))
		ft_putchar(str[i]);
}