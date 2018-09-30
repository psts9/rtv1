/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:53:28 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/29 20:28:45 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "file_parsing.h"

static int	find_and_do_parameter(char *line, int fd, t_scene *scene)
{
	int ret;

	ret = 1;
	if (ft_strncmp(line, "camera:", 7) == 0)
		ret = get_parameters(fd, scene, 0, SCENE_CAMERA);
	else if (ft_strncmp(line, "sphere:", 7) == 0)
		ret = get_parameters(fd, scene, SPHERE, SCENE_OBJECT);
	else if (ft_strncmp(line, "cylinder:", 9) == 0)
		ret = get_parameters(fd, scene, CYLINDER, SCENE_OBJECT);
	else if (ft_strncmp(line, "cone:", 5) == 0)
		ret = get_parameters(fd, scene, CONE, SCENE_OBJECT);
	else if (ft_strncmp(line, "plane:", 6) == 0)
		ret = get_parameters(fd, scene, PLANE, SCENE_OBJECT);
	else if (ft_strncmp(line, "light_directional:", 18) == 0)
		ret = get_parameters(fd, scene, DIRECTIONAL, SCENE_LIGHT);
	else if (ft_strncmp(line, "light_point:", 12) == 0)
		ret = get_parameters(fd, scene, POINT, SCENE_LIGHT);
	else if (ft_strncmp(line, "light:", 6) == 0)
		ret = get_parameters(fd, scene, POINT, SCENE_LIGHT);
	else if (ft_strncmp(line, "directional:", 12) == 0)
		ret = get_parameters(fd, scene, DIRECTIONAL, SCENE_LIGHT);
	else if (line[0] != '\n' && line[0] != '#' && !is_empty(line))
		ret = 0;
	return (ret);
}

int			file_to_scene(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		perror_exit(filename);
	init_scene(scene);
	ret = 1;
	while (get_next_line(fd, &line))
	{
		ret = find_and_do_parameter(line, fd, scene);
		free(line);
		if (!ret)
			return (ret);
	}
	free(line);
	return (1);
}
