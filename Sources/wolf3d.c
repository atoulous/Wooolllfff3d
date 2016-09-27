/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:38:50 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 16:08:24 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	restart_wolf3d(t_var *var)
{
	int		i;

	i = -1;
	while (TAB[++i])
		free(TAB[i]);
	free(TAB);
	TAB = ft_strsplit(MAP, '\n');
	init_raycasting(var);
}

void	init_raycasting(t_var *var)
{
	find_start(var);
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	MOVESPEED = 0.4;
	ROTSPEED = 0.1;
	DUCK = 2;
	DUCKEND = 4;
	WEAPON = 1;
}

void	init_wolf3d(t_var *var, char *map)
{
	WIDTH_WIN = 1024;
	HEIGHT_WIN = 768;
	M = 1;
	init_raycasting(var);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	init_textures(var);
}

void	ft_wolf3d(int fd, char *map)
{
	t_var	*var;
	int		i;

	if (ft_strcmp(map, "Maps/de_dust2") && ft_strcmp(map, "Maps/race"))
		ft_exit(2);
	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (exit(EXIT_FAILURE));
	if (!(var->ray = (t_ray*)ft_memalloc(sizeof(t_ray))))
		return (exit(EXIT_FAILURE));
	if (!(var->floor = (t_floor*)ft_memalloc(sizeof(t_floor))))
		return (exit(EXIT_FAILURE));
	if (!(var->text = (t_text*)ft_memalloc(sizeof(t_text))))
		return (exit(EXIT_FAILURE));
	parse_map(var, fd);
	i = -1;
	while (TAB[++i])
		ft_putendl(TAB[i]);
	init_wolf3d(var, map);
	mlx_loop_hook(MLX, launch_wolf3d, var);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key, var);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, ft_release, var);
	mlx_hook(WIN, DestroyNotify, Button1MotionMask, ft_crossquit, var);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse, var);
	mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_motion_mouse, var);
	mlx_loop(MLX);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	if (ac < 2)
		ft_putendl("Usage: ./wolf3d <map>");
	else
	{
		i = 0;
		while (++i < ac)
		{
			if (fork())
			{
				fd = open(av[i], O_RDONLY);
				if (fd > 0)
					ft_wolf3d(fd, av[i]);
			}
		}
	}
	return (0);
}
