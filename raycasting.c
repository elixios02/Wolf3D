/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:02:49 by paim              #+#    #+#             */
/*   Updated: 2016/10/31 16:49:46 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>


void	init_norm(t_data *t)
{
	t->camx = 2 * t->x / (double)WIDTH - 1;
	if (t->camx == 0)
		        printf("camX : %d", t->camx);
	t->rayposx = t->posx;
	t->rayposy = t->posy;
	t->raydirx = t->dirx + t->planx * t->camx;
	t->raydiry = t->diry + t->plany * t->camx;
	printf("camX : %d, raydirx : %d, raydirY : %d", t->camx, t->raydirx, t->raydiry);
	t->mapx = (int)t->rayposx;
	t->mapy = (int)t->rayposy;
	t->ddistx = sqrt(1 + (t->raydiry * t->raydiry) / (t->raydirx * t->raydirx));
	t->ddisty = sqrt(1 + (t->raydirx * t->raydirx) / (t->raydiry * t->raydiry));
}

void	color(t_data *t)
{
	if (t->map[t->mapx][t->mapy] == 1)
	{
		if (t->side == 1)
			t->color_img = mlx_get_color_value(t->mlx, 0xFE0265);
		if (t->side == 0)
			t->color_img = mlx_get_color_value(t->mlx, 0xFEFEFE);
		if (t->side == 0 && t->raydirx > 0)
			t->color_img = mlx_get_color_value(t->mlx, 0x00FFFF);
		if (t->side == 1 && t->raydiry < 0)
			t->color_img = mlx_get_color_value(t->mlx, 0xFEFF25);
		while (t->dstart <= t->dend)
		{
			ft_put_pixel_to_image(t);
			t->dstart++;
		}
	}
}

void	dda(t_data *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->sdistx < t->sdisty)
		{
			t->sdistx += t->ddistx;
			t->mapx += t->stepx;
			t->side = 0;
		}
		else
		{
			t->sdisty += t->ddisty;
			t->mapy += t->stepy;
			t->side = 1;
		}
		if (t->map[t->mapx][t->mapy] > 0)
			t->hit = 1;
	}
	if (t->side == 0)
		t->pwd = (t->mapx - t->rayposx + (1 - t->stepx) / 2) / t->raydirx;
	else
		t->pwd = (t->mapy - t->rayposy + (1 - t->stepy) / 2) / t->raydiry;
}

void	ifforest(t_data *t)
{
	if (t->raydirx < 0)
	{
		t->stepx = -1;
		t->sdistx = (t->rayposx - t->mapx) * t->ddistx;
	}
	else
	{
		t->stepx = 1;
		t->sdistx = (t->mapx + 1 - t->rayposx) * t->ddistx;
	}
	if (t->raydiry < 0)
	{
		t->stepy = -1;
		t->sdisty = (t->rayposy - t->mapy) * t->ddisty;
	}
	else
	{
		t->stepy = 1;
		t->sdisty = (t->mapy + 1 - t->rayposy) * t->ddisty;
	}
}

int		whlrc(t_data *t)
{
	t->x = 0;
	while (t->x <= WIDTH)
	{
		init_norm(t);
		ifforest(t);
		dda(t);
		t->lineh = (int)(HEIGHT / t->pwd);
		t->dstart = -t->lineh / 2 + HEIGHT / 2;
		if (t->dstart < 0)
			t->dstart = 0;
		t->dend = t->lineh / 2 + HEIGHT / 2;
		if (t->dend >= HEIGHT)
			t->dend = HEIGHT - 1;
		color(t);
		t->x++;
	}
	return (0);
}
