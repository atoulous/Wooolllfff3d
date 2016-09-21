/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 12:22:00 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/21 19:05:20 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sky_textures(t_var *var)
{
	SKYFRONT = mlx_xpm_file_to_image(MLX, "Text/Dayboxfront.xpm", &SKYY, &SKYX);
	SKYBACK = mlx_xpm_file_to_image(MLX, "Text/Dayboxback.xpm", &SKYY, &SKYX);
	SKYLEFT = mlx_xpm_file_to_image(MLX, "Text/Dayboxleft.xpm", &SKYY, &SKYX);
	SKYRIGHT = mlx_xpm_file_to_image(MLX, "Text/Dayboxright.xpm", &SKYY, &SKYX);
	SKYFRONTDATA = mlx_get_data_addr(SKYFRONT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYBACKDATA = mlx_get_data_addr(SKYBACK, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYLEFTDATA = mlx_get_data_addr(SKYLEFT, &BPP, &SKYSIZELINE, &ENDIAN);
	SKYRIGHTDATA = mlx_get_data_addr(SKYRIGHT, &BPP, &SKYSIZELINE, &ENDIAN);
	MENU = mlx_xpm_file_to_image(MLX, "Text/csmenu.xpm", &SKYY, &SKYX);
	MENUDATA = mlx_get_data_addr(MENU, &BPP, &SKYSIZELINE, &ENDIAN);
	AK = mlx_xpm_file_to_image(MLX, "Text/ak47.xpm", &WEAPONY, &WEAPONX);
	AKDATA = mlx_get_data_addr(AK, &BPP, &WEAPONSIZELINE, &ENDIAN);
}

void	floor_textures(t_var *var)
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

void	init_textures(t_var *var)
{
	sky_textures(var);
	floor_textures(var);
	WALL = mlx_xpm_file_to_image(MLX, "Text/wall.xpm", &TEXTX, &TEXTX);
	WALLTAG = mlx_xpm_file_to_image(MLX, "Text/walltag.xpm", &TEXTX, &TEXTX);
	WINWALL = mlx_xpm_file_to_image(MLX, "Text/winwall.xpm", &TEXTX, &TEXTX);
	WINTAG = mlx_xpm_file_to_image(MLX, "Text/winwalltag.xpm", &TEXTX, &TEXTX);
	DOORWALL = mlx_xpm_file_to_image(MLX, "Text/doorwall.xpm", &TEXTX, &TEXTX);
	INDOOR = mlx_xpm_file_to_image(MLX, "Text/indoor.xpm", &TEXTX, &TEXTX);
	OIM = mlx_xpm_file_to_image(MLX, "Text/oim64.xpm", &OIMX, &OIMX);
	PORTAL = mlx_xpm_file_to_image(MLX, "Text/portal.xpm", &TEXTX, &TEXTX);
	BOX = mlx_xpm_file_to_image(MLX, "Text/box.xpm", &TEXTX, &TEXTX);
	METALBOX = mlx_xpm_file_to_image(MLX, "Text/metalbox.xpm", &TEXTX, &TEXTX);
	AUTOMAT = mlx_xpm_file_to_image(MLX, "Text/automat.xpm", &TEXTX, &TEXTX);
	WALLDATA = mlx_get_data_addr(WALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	WALLTAGDATA = mlx_get_data_addr(WALLTAG, &BPP, &TEXTSIZELINE, &ENDIAN);
	WINWALLDATA = mlx_get_data_addr(WINWALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	WINTAGDATA = mlx_get_data_addr(WINTAG, &BPP, &TEXTSIZELINE, &ENDIAN);
	DOORWALLDATA = mlx_get_data_addr(DOORWALL, &BPP, &TEXTSIZELINE, &ENDIAN);
	INDOORDATA = mlx_get_data_addr(INDOOR, &BPP, &TEXTSIZELINE, &ENDIAN);
	OIMDATA = mlx_get_data_addr(OIM, &BPP, &OIMSIZELINE, &ENDIAN);
	PORTALDATA = mlx_get_data_addr(PORTAL, &BPP, &TEXTSIZELINE, &ENDIAN);
	BOXDATA = mlx_get_data_addr(BOX, &BPP, &TEXTSIZELINE, &ENDIAN);
	METALBOXDATA = mlx_get_data_addr(METALBOX, &BPP, &TEXTSIZELINE, &ENDIAN);
	AUTOMATDATA = mlx_get_data_addr(AUTOMAT, &BPP, &TEXTSIZELINE, &ENDIAN);
}
