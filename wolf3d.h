/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:38:27 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/21 20:14:19 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "Libs/libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define HEIGHT_CAM var->ray->height_cam
# define MAP_X var->ray->map_x
# define MAP_Y var->ray->map_y
# define STEP_X var->ray->step_x
# define STEP_Y var->ray->step_y
# define HIT var->ray->hit
# define SIDE var->ray->side
# define LINEHEIGHT var->ray->lineheight
# define H var->ray->h
# define DRAWSTART var->ray->drawstart
# define DRAWEND var->ray->drawend
# define COLOR var->ray->color
# define POS_X var->ray->pos_x
# define POS_Y var->ray->pos_y
# define DIR_X var->ray->dir_x
# define DIR_Y var->ray->dir_y
# define PLANE_X var->ray->plane_x
# define PLANE_Y var->ray->plane_y
# define TIME var->ray->time
# define OLDTIME var->ray->oldtime
# define CAM_X var->ray->cam_x
# define RAYPOS_X var->ray->raypos_x
# define RAYPOS_Y var->ray->raypos_y
# define RAYDIR_X var->ray->raydir_x
# define RAYDIR_Y var->ray->raydir_y
# define SIDEDIST_X var->ray->sidedist_x
# define SIDEDIST_Y var->ray->sidedist_y
# define DELTADIST_X var->ray->deltadist_x
# define DELTADIST_Y var->ray->deltadist_y
# define PERPWALLDIST var->ray->perpwalldist

# define MLX var->mlx
# define WIN var->win
# define IMG var->img
# define DATA var->data
# define MAP var->map
# define TAB var->tab
# define BPP var->bpp
# define SIZELINE var->sizeline
# define ENDIAN var->endian
# define WIDTH_WIN var->width_win
# define HEIGHT_WIN var->height_win
# define WIDTH_MAP var->width_map
# define HEIGHT_MAP var->height_map
# define WIDTH_WALL var->width_wall
# define HEIGHT_WALL var->height_wall
# define XMAX var->xmax
# define YMAX var->ymax

typedef struct		s_ray
{
	int				height_cam;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				h;
	int				drawstart;
	int				drawend;
	int				color;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			oldtime;
	double			cam_x;
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
}					t_ray;

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*map;
	char			**tab;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width_win;
	int				height_win;
	int				width_map;
	int				height_map;
	int				width_wall;
	int				height_wall;
	int				xmax;
	int				ymax;
	t_ray			*ray;
}					t_var;

void				parse_map(t_var *var, int fd);
void				free_tab(t_var *var);
void				ft_refresh_image(t_var *var);
void				restart_wolf3d(t_var *var);
void				fill_image(t_var *var, int x, int y, int color);
int					launch_wolf3d(t_var *var);

#endif
