/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fileargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:55:28 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 01:55:29 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parsing.h"

int	get_object_args(char *line, t_object *obj)
{
	int ret;
	int i;

	i = skip_whitespace(line);
	if (ft_strncmp(line + i, "origin:", 7) == 0)
		ret = get_nums(line + i + 8, &obj->position);
	else if (ft_strncmp(line + i, "albedo:", 7) == 0)
		ret = get_nums(line + i + 8, &obj->albedo);
	else if (ft_strncmp(line + i, "rotation:", 9) == 0)
		ret = get_nums(line + i + 10, &obj->rotation);
	else if (ft_strncmp(line + i, "radius:", 7) == 0)
	{
		obj->radius = ft_atod(line + i + 8);
		ret = 1;
	}
	else
		ret = 0;
	return (ret);
}

int	get_light_args(char *line, t_light *light)
{
	int ret;
	int i;

	i = skip_whitespace(line);
	if (ft_strncmp(line + i, "origin:", 7) == 0)
		ret = get_nums(line + i + 8, &light->position);
	else if (ft_strncmp(line + i, "albedo:", 7) == 0)
		ret = get_nums(line + i + 8, &light->albedo);
	else if (ft_strncmp(line + i, "rotation:", 9) == 0)
		ret = get_nums(line + i + 10, &light->rotation);
	else if (ft_strncmp(line + i, "intensity:", 10) == 0)
	{
		light->intensity = ft_atod(line + i + 11);
		ret = 1;
	}
	else
		ret = 0;
	return (ret);
}

int	get_camera_args(char *line, t_scene *scene)
{
	int	ret;
	int i;

	i = skip_whitespace(line);
	if (ft_strncmp(line + i, "origin:", 7) == 0)
		ret = get_nums(line + i + 8, &scene->cam.origin);
	else if (ft_strncmp(line + i, "rotation:", 9) == 0)
		ret = get_nums(line + i + 10, &scene->cam.direction);
	else
		ret = 0;
	return (ret);
}
