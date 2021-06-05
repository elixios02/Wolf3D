/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:10:59 by paim              #+#    #+#             */
/*   Updated: 2016/11/22 20:27:47 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 500
# define MWIDTH 24
# define MHEIGHT 24
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				onoff;
	int				sizeline;
	int				endian;
	unsigned int	color_img;
	int				x;
	int				y;
	int				map[22][22];
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			t;
	double			oldt;
	double			camx;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sdistx;
	double			sdisty;
	double			ddistx;
	double			ddisty;
	double			pwd;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineh;
	int				dstart;
	int				dend;
	double			ms;
	double			rs;
	clock_t			frametime;
	clock_t			sfps;
	clock_t			efps;
}					t_data;

t_data				*init_wolf();
int					error(const char *str);
void				ft_put_pixel_to_image(t_data *t);
void				color(t_data *t);
void				dda(t_data *t);
void				ifforest(t_data *t);
int					whlrc(t_data*t);
void				map(t_data *t);
void				save_map(t_data *t, int mapp[22][22]);
int					key_hook(int keycode, t_data *t);
int					key_hook2(int keycode, t_data *t);
int					key_hook3(int keycode, t_data *t);
int					mouse_hook(int keycode, t_data *t);
void				init_norm(t_data *t);

#endif
