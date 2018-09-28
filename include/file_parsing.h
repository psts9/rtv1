/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:00:40 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:01:01 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSING_H
# define FILE_PARSING_H

# include <fcntl.h>

# include "scene.h"
# include "libft.h"
# include "vector.h"
# include "object_list.h"
# include "light_list.h"
# include "init.h"
# include "error.h"

int		get_parameters(int fd, t_scene *scene, int type,
				enum e_scene_object scene_object_type);
int		get_object_args(char *line, t_object *obj);
int		get_light_args(char *line, t_light *light);
int		get_camera_args(char *line, t_scene *scene);
int		skip_whitespace(char *str);
char	*skip_to_next_num(char *line);
int		get_nums(char *line, t_vec3 *dst);
int		is_empty(char *str);

#endif
