/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:21:40 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:21:42 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	do_decimals(int *i, double *n, const char *str)
{
	double	d;

	d = 0.1;
	++(*i);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*n += d * (str[(*i)++] - '0');
		d /= 10.0;
	}
}

double		ft_atod(const char *str)
{
	double	n;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	n = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = 10 * n + (str[i++] - '0');
	if (str[i] == '.')
		do_decimals(&i, &n, str);
	return (neg ? -n : n);
}
