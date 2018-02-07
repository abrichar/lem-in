/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:52:09 by abrichar          #+#    #+#             */
/*   Updated: 2018/02/06 14:52:09 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_isint(char *arg)
{
	int		i;
	int		ret;
	size_t	neg;

	ret = 1;
	neg = (arg[0] == '-') ? 1 : 0;
	i = neg;
	while (arg[i] == '0')
		i++;
	if (ft_strlen(&arg[i]) > 10)
		ret = 0;
	else if (ft_strlen(&arg[i]) == 10)
	{
		if (neg && ft_strcmp(&arg[i], "2147483648") > 0)
			ret = 0;
		else if (!neg && ft_strcmp(&arg[i], "2147483647") > 0)
			ret = 0;
	}
	else
		while (arg[i])
			if (!ft_isdigit(arg[i++]))
				ret = 0;
	return (ret);
}
