/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:32:16 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/07 12:32:19 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "rtv1.h"
#include "init.h"
#include "loop.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	argc = 0;
	t_prog	prog;
	
	init(&prog, argv[0]);
	run(&prog);
	return (0);
}
