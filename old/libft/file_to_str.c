/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:09:34 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/05 13:09:40 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"

char	*file_to_str(char *filename)
{
	int		rd;
	int		fd;
	char	buf[BUFF_SIZE];
	char	*result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = ft_strnew(0);
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		free_strjoin(&result, buf);
	}
	return (result);
}
