/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:38:50 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/16 17:03:33 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		//DATA[y * SIZELINE + x * (BPP / 8) + 3] = 200;
	}
}

void	find_start(t_var *var)
{
	int		i;
	int		j;

	POS_X = 0;
	POS_Y = 0;
	j = -1;
	while (++j < YMAX)
	{
		i = -1;
		while (++i < XMAX)
			if (TAB[j][i] == 'S')
			{
				!POS_X ? POS_X = j : 0;
				!POS_Y ? POS_Y = i : 0;
				TAB[j][i] = '0';
			}
	}
}

void	init_raycasting(t_var *var)
{
	find_start(var);
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

void	sky_text(t_var *var)
{
	SKYFRONT = mlx_xpm_file_to_image(MLX, "Text/Dayboxfront.xpm", &SKYY, &SKYX);
	SKYBACK = mlx_xpm_file_to_image(MLX, "Text/Dayboxback.xpm", &SKYY, &SKYX);
	SKYLEFT = mlx_xpm_file_to_image(MLX, "Text/Dayboxleft.xpm", &SKYY, &SKYX);
	SKYRIGHT = mlx_xpm_file_to_image(MLX, "Text/Dayboxright.xpm", &SKYY, &SKYX);
	SKYFRONTDATA = mlx_get_data_addr(SKYFRONT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYBACKDATA = mlx_get_data_addr(SKYBACK, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYLEFTDATA = mlx_get_data_addr(SKYLEFT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYRIGHTDATA = mlx_get_data_addr(SKYRIGHT, &BPP, &SKYSIZELINE, &ENDIAN);
}

void	floor_text(t_var *var)
{
	ROAD = mlx_xpm_file_to_image(MLX, "Text/sandfloor.xpm", &ROADX, &ROADX);
	ROADH = mlx_xpm_file_to_image(MLX, "Text/roadh.xpm", &ROADX, &ROADX);
	ROADA = mlx_xpm_file_to_image(MLX, "Text/roada.xpm", &ROADX, &ROADX);
	ROADB = mlx_xpm_file_to_image(MLX, "Text/roadb.xpm", &ROADX, &ROADX);
	SAND = mlx_xpm_file_to_image(MLX, "Text/sandl.xpm", &ROADX, &ROADX);
	CEIL = mlx_xpm_file_to_image(MLX, "Text/ceil.xpm", &ROADX, &ROADX);
	ROADDATA = mlx_get_data_addr(ROAD, &BPP, &ROADSIZELINE, &ENDIAN);
	ROADHDATA = mlx_get_data_addr(ROADH, &BPP, &ROADSIZELINE, &ENDIAN);
	ROADADATA = mlx_get_data_addr(ROADA, &BPP, &ROADSIZELINE, &ENDIAN);
	ROADBDATA = mlx_get_data_addr(ROADB, &BPP, &ROADSIZELINE, &ENDIAN);
	SANDDATA = mlx_get_data_addr(SAND, &BPP, &ROADSIZELINE, &ENDIAN);
	CEILDATA = mlx_get_data_addr(CEIL, &BPP, &ROADSIZELINE, &ENDIAN);
}

void	init_texture(t_var *var)
{
	if (!(var->text = (t_text*)ft_memalloc(sizeof(t_text))))
		return (exit(EXIT_FAILURE));
	sky_text(var);
	floor_text(var);
	WALL = mlx_xpm_file_to_image(MLX, "Text/wall.xpm", &TEXTX, &TEXTX);
	WINWALL = mlx_xpm_file_to_image(MLX, "Text/winwall.xpm", &TEXTX, &TEXTX);
	DOORWALL = mlx_xpm_file_to_image(MLX, "Text/doorwall.xpm", &TEXTX, &TEXTX);
	WOOD = mlx_xpm_file_to_image(MLX, "Text/wood.xpm", &TEXTX, &TEXTX);
	OIM = mlx_xpm_file_to_image(MLX, "Text/oim64.xpm", &OIMX, &OIMX);
	GLASS = mlx_xpm_file_to_image(MLX, "Text/glass.xpm", &TEXTX, &TEXTX);
	BOX = mlx_xpm_file_to_image(MLX, "Text/box.xpm", &TEXTX, &TEXTX);
	METALBOX = mlx_xpm_file_to_image(MLX, "Text/metalbox.xpm", &TEXTX, &TEXTX);
	AUTOMAT = mlx_xpm_file_to_image(MLX, "Text/automat.xpm", &TEXTX, &TEXTX);
	WALLDATA = mlx_get_data_addr(WALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	WINWALLDATA = mlx_get_data_addr(WINWALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	DOORWALLDATA = mlx_get_data_addr(DOORWALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	WOODDATA = mlx_get_data_addr(WOOD, &BPP, &TEXTSIZELINE, &ENDIAN);
	OIMDATA = mlx_get_data_addr(OIM, &BPP, &OIMSIZELINE, &ENDIAN);
	GLASSDATA = mlx_get_data_addr(GLASS, &BPP, &TEXTSIZELINE, &ENDIAN);
	BOXDATA = mlx_get_data_addr(BOX, &BPP, &TEXTSIZELINE, &ENDIAN);
	METALBOXDATA = mlx_get_data_addr(METALBOX, &BPP, &TEXTSIZELINE, &ENDIAN);
	AUTOMATDATA = mlx_get_data_addr(AUTOMAT, &BPP, &TEXTSIZELINE, &ENDIAN);
}

void	init_wolf3d(t_var *var, char *map)
{
	WIDTH_WIN = 1024;
	HEIGHT_WIN = 768;
	C = 0;
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
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, ft_release, var);
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
