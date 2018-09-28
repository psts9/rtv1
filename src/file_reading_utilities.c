/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading_utilities.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:45:31 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 01:45:48 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parsing.h"

int		skip_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

char	*skip_to_next_num(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i])
		++i;
	if (!line[i])
		return (NULL);
	while (line[i] == ' ' && line[i] == '\t')
		++i;
	return (line + i + 1);
}

int		get_nums(char *line, t_vec3 *dst)
{
	dst->x = ft_atod(line);
	line = skip_to_next_num(line);
	if (!line)
		return (0);
	dst->y = ft_atod(line);
	line = skip_to_next_num(line);
	if (!line)
		return (0);
	dst->z = ft_atod(line);
	line = skip_to_next_num(line);
	return (!line);
}

int		is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		++i;
	}
	return (1);
}
