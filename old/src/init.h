#ifndef INIT_H
# define INIT_H

# include "rtv1.h"

void	init(t_prog *prog, char *program_name);
void	window_init(t_screen *screen, char *program_name);
void	renderer_init(t_screen *screen);
void	texture_init(t_screen *screen);
void	pixels_init(t_screen *screen);

#endif
