/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:38:50 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/12 19:28:58 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	refresh_image(t_var *var)
{
	/*int		x;
	int		y;

	x = -1;
	while (++x < WIDTH_WIN)
	{
		y = -1;
		while (++y < HEIGHT_WIN)
			fill_image(var, x, y, 0x0);
	}*/
	int		pix;
	int		x;

	x = WIDTH_WIN;
	Y1 = 0;
	Y2 = HEIGHT_WIN;
	while (x < WIDTH_WIN)
	{
		while (Y1 < Y2)
		{
			pix = Y1 * SKYSIZELINE + x * (BPP / 8);
			COLOR = SKYFRONTDATA[pix] + SKYFRONTDATA[pix + 1] * 256 + SKYFRONTDATA[pix + 2] * 65536;
			fill_image(var, x, Y1++, COLOR);
		}
		x++;
	}
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

void	init_raycasting(t_var *var)
{
	POS_X = 8;
	POS_Y = 8;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	TIME = 0;
	OLDTIME = 0;
	HEIGHT_CAM = HEIGHT_WALL / 2;
	MOVESPEED = 0.4;
	ROTSPEED = 0.1;
}

void	init_texture(t_var *var)
{
	if (!(var->text = (t_text*)ft_memalloc(sizeof(t_text))))
		return (exit(EXIT_FAILURE));
	WOOD = mlx_xpm_file_to_image(MLX, "Text/wood.xpm", &TEXTX, &TEXTX);
	OIM = mlx_xpm_file_to_image(MLX, "Text/oim64.xpm", &OIMX, &OIMX);
	SKYFRONT = mlx_xpm_file_to_image(MLX, "Text/Dayboxfront.xpm", &SKYY, &SKYX);
	SKYBACK = mlx_xpm_file_to_image(MLX, "Text/Dayboxback.xpm", &SKYY, &SKYX);
	SKYLEFT = mlx_xpm_file_to_image(MLX, "Text/Dayboxleft.xpm", &SKYY, &SKYX);
	SKYRIGHT = mlx_xpm_file_to_image(MLX, "Text/Dayboxright.xpm", &SKYY, &SKYX);
	WOODDATA = mlx_get_data_addr(WOOD, &BPP, &TEXTSIZELINE, &ENDIAN);
	OIMDATA = mlx_get_data_addr(OIM, &BPP, &OIMSIZELINE, &ENDIAN);
	SKYFRONTDATA = mlx_get_data_addr(SKYFRONT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYBACKDATA = mlx_get_data_addr(SKYBACK, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYLEFTDATA = mlx_get_data_addr(SKYLEFT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYRIGHTDATA = mlx_get_data_addr(SKYRIGHT, &BPP, &SKYSIZELINE, &ENDIAN);
}

void	init_wolf3d(t_var *var, char *map)
{
	WIDTH_WIN = 1024;
	HEIGHT_WIN = 768;
	init_raycasting(var);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_WIN, HEIGHT_WIN, map);
	IMG = mlx_new_image(MLX, WIDTH_WIN, HEIGHT_WIN);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	init_texture(var);
}

void	ft_wolf3d(int fd, char *map)
{
	t_var	*var;
	int		i;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (exit(EXIT_FAILURE));
	if (!(var->ray = (t_ray*)ft_memalloc(sizeof(t_ray))))
		return (exit(EXIT_FAILURE));
	FLD = fd;
	parse_map(var);
	i = -1;
	while (TAB[++i])
		ft_putendl(TAB[i]);
	init_wolf3d(var, map);
	mlx_loop_hook(MLX, launch_wolf3d, var);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key, var);
	mlx_hook(WIN, 17, Button1MotionMask, ft_crossquit, var);
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
