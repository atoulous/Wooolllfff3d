/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:38:50 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/21 20:36:31 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key(int	keycode, t_var *var)
{
	if (keycode == 53)
	{
		free_tab(var);
		exit(EXIT_SUCCESS);
	}
	ft_refresh_image(var);
	keycode == 123 ? POS_X -= 0.5 : 0;
	keycode == 124 ? POS_X += 0.5 : 0;
	keycode == 125 ? POS_Y -= 0.5 : 0;
	keycode == 126 ? POS_Y += 0.5 : 0;
	//keycode == 49 ? restart_wolf3d(var) : 0;
	return (0);
}

void	fill_image(t_var *var, int x, int y, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = color >> 0;
	g = color >> 8;
	b = color >> 16;
	if (x >= 0 && x < WIDTH_WIN && y >= 0 && y < HEIGHT_WIN)
	{
		DATA[y * SIZELINE + x * (BPP / 8)] = r;
		DATA[y * SIZELINE + x * (BPP / 8) + 1] = g;
		DATA[y * SIZELINE + x * (BPP / 8) + 2] = b;
	}
}

void	init_wolf3d(t_var *var, char *map)
{
	WIDTH_WIN = 1024;
	HEIGHT_WIN = 768;
	WIDTH_MAP = XMAX * 10;
	HEIGHT_MAP = YMAX * 10;
	WIDTH_WALL = 64;
	HEIGHT_WALL = 64;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
}

void	ft_wolf3d(int fd, char *map)
{
	t_var	*var;
	int		i;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (exit(EXIT_FAILURE));
	if (!(var->ray = (t_ray*)ft_memalloc(sizeof(t_ray))))
		return (exit(EXIT_FAILURE));
	parse_map(var, fd);
	i = -1;
	while (TAB[++i])
		ft_putendl(TAB[i]);
	init_wolf3d(var, map);
	mlx_loop_hook(MLX, launch_wolf3d, var);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key, var);
	//mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse, var);
	//mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_motion_mouse, var);
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
