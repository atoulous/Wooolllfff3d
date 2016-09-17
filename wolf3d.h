/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:38:27 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 17:45:32 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "Libs/libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define flo var->floor

# define HEIGHT_CAM var->ray->height_cam
# define MAP_X var->ray->map_x
# define MAP_Y var->ray->map_y
# define STEP_X var->ray->step_x
# define STEP_Y var->ray->step_y
# define HIT var->ray->hit
# define SIDE var->ray->side
# define LINEHEIGHT var->ray->lineheight
# define DRAWSTART var->ray->drawstart
# define DRAWEND var->ray->drawend
# define COLOR var->ray->color
# define MOVESPEED var->ray->movespeed
# define ROTSPEED var->ray->rotspeed
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
# define WALLX var->ray->wallx
# define PX var->ray->px

# define MLX var->mlx
# define WIN var->win
# define IMG var->img
# define FLD var->fld
# define DATA var->data
# define MAP var->map
# define TAB var->tab
# define C var->c
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
# define Y1 var->y1
# define Y2 var->y2
# define I var->i
# define LINE var->line
# define KEYCODE var->keycode

# define WALL var->text->wall
# define WINWALL var->text->winwall
# define DOORWALL var->text->doorwall
# define WOOD var->text->wood
# define INDOOR var->text->indoor
# define SKYFRONT var->text->skyfront
# define SKYBACK var->text->skyback
# define SKYLEFT var->text->skyleft
# define SKYRIGHT var->text->skyright
# define GLASS var->text->glass
# define BOX var->text->box
# define METALBOX var->text->metalbox
# define AUTOMAT var->text->automat
# define ROAD var->text->road
# define ROADH var->text->roadh
# define ROADA var->text->roada
# define ROADB var->text->roadb
# define SAND var->text->sand
# define CEIL var->text->ceil
# define WALLDATA var->text->walldata
# define WINWALLDATA var->text->winwalldata
# define DOORWALLDATA var->text->doorwalldata
# define WOODDATA var->text->wooddata
# define INDOORDATA var->text->indoordata
# define SKYFRONTDATA var->text->skyfrontdata
# define SKYBACKDATA var->text->skybackdata
# define SKYLEFTDATA var->text->skyleftdata
# define SKYRIGHTDATA var->text->skyrightdata
# define GLASSDATA var->text->glassdata
# define BOXDATA var->text->boxdata
# define METALBOXDATA var->text->metalboxdata
# define AUTOMATDATA var->text->automatdata
# define ROADDATA var->text->roaddata
# define ROADHDATA var->text->roadhdata
# define ROADADATA var->text->roadadata
# define ROADBDATA var->text->roadbdata
# define SANDDATA var->text->sanddata
# define CEILDATA var->text->ceildata
# define TEXTSIZELINE var->text->textsizeline
# define TEXTX var->text->textx
# define SKYX var->text->skyx
# define SKYY var->text->skyy
# define ROADX var->text->roadx
# define ROADSIZELINE var->text->roadsizeline
# define SKYSIZELINE var->text->skysizeline
# define OIM var->text->oim
# define OIMDATA var->text->oimdata
# define OIMX var->text->oimx
# define OIMSIZELINE var->text->oimsizeline

typedef struct		s_text
{
	void			*wall;
	void			*winwall;
	void			*doorwall;
	void			*wood;
	void			*indoor;
	void			*skyfront;
	void			*skyback;
	void			*skyright;
	void			*skyleft;
	void			*oim;
	void			*glass;
	void			*box;
	void			*metalbox;
	void			*automat;
	void			*road;
	void			*roadh;
	void			*roada;
	void			*roadb;
	void			*sand;
	void			*ceil;
	char			*walldata;
	char			*winwalldata;
	char			*doorwalldata;
	char			*wooddata;
	char			*indoordata;
	char			*skyfrontdata;
	char			*skybackdata;
	char			*skyrightdata;
	char			*skyleftdata;
	char			*oimdata;
	char			*glassdata;
	char			*boxdata;
	char			*metalboxdata;
	char			*automatdata;
	char			*roaddata;
	char			*roadhdata;
	char			*roadadata;
	char			*roadbdata;
	char			*sanddata;
	char			*ceildata;
	int				textsizeline;
	int				textx;
	int				roadx;
	int				skysizeline;
	int				skyx;
	int				skyy;
	int				oimx;
	int				oimsizeline;
	int				roadsizeline;
}					t_text;

typedef struct		s_floor
{
	double			floorwallx;
	double			floorwally;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	int				floortexx;
	int				floortexy;
}					t_floor;

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
	int				drawstart;
	int				drawend;
	int				color;
	int				px;
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
	double			movespeed;
	double			rotspeed;
	double			wallx;
}					t_ray;

typedef struct		s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*map;
	char			**tab;
	char			c;
	int				fld;
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
	int				y1;
	t_floor			*floor;
	t_ray			*ray;
	t_text			*text;
}					t_var;

void				parse_map(t_var *var, int fd);
void				free_tab(t_var *var);
void				restart_wolf3d(t_var *var);
void				fill_image(t_var *var, int x, int y, int color);
void				wall_raycasting(t_var *var, int x);
void				draw_wall(t_var *var, int x);
void				find_start(t_var *var);
void				floor_raycasting(t_var *var, int x);
void				draw_floor(t_var *var, int x);
void				init_textures(t_var *var);
void				init_raycasting(t_var *var);
void				ft_moves(t_var *var);
int					rotateright(t_var *var);
int					rotateleft(t_var *var);
int					ft_key(int keycode, t_var *var);
int					ft_release(int keycode, t_var *var);
int					ft_crossquit(t_var *var);
int					launch_wolf3d(t_var *var);
int					ft_mouse(int button, int x, int y, t_var *var);
int					ft_motion_mouse(int x, int y, t_var *var);

#endif
