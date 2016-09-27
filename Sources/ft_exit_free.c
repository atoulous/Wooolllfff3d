/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:05:18 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:38:54 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_crossquit(t_var *var)
{
	free_all(var);
	exit(EXIT_SUCCESS);
}

void	free_weapons_textures(t_var *var)
{
	mlx_destroy_image(MLX, AK);
	mlx_destroy_image(MLX, AKF);
	mlx_destroy_image(MLX, USP);
	mlx_destroy_image(MLX, KNIFE);
	mlx_destroy_image(MLX, HE);
	mlx_destroy_image(MLX, C4);
}

void	free_textures(t_var *var)
{
	free_weapons_textures(var);
	mlx_destroy_image(MLX, SKYFRONT);
	mlx_destroy_image(MLX, SKYBACK);
	mlx_destroy_image(MLX, SKYLEFT);
	mlx_destroy_image(MLX, SKYRIGHT);
	mlx_destroy_image(MLX, ROAD);
	mlx_destroy_image(MLX, ROADH);
	mlx_destroy_image(MLX, ROADA);
	mlx_destroy_image(MLX, ROADB);
	mlx_destroy_image(MLX, SAND);
	mlx_destroy_image(MLX, CEIL);
	mlx_destroy_image(MLX, WALL);
	mlx_destroy_image(MLX, WALLTAG);
	mlx_destroy_image(MLX, WINWALL);
	mlx_destroy_image(MLX, WINTAG);
	mlx_destroy_image(MLX, DOORWALL);
	mlx_destroy_image(MLX, INDOOR);
	mlx_destroy_image(MLX, OIM);
	mlx_destroy_image(MLX, PORTAL);
	mlx_destroy_image(MLX, BOX);
	mlx_destroy_image(MLX, METALBOX);
	mlx_destroy_image(MLX, AUTOMAT);
	mlx_destroy_image(MLX, MENU);
	mlx_destroy_image(MLX, RADAR);
}

void	free_all(t_var *var)
{
	int		i;

	i = -1;
	while (TAB[++i])
		free(TAB[i]);
	free(TAB);
	free(MAP);
	free_textures(var);
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	free(var->ray);
	free(var->text);
	free(var->floor);
	free(var);
}
