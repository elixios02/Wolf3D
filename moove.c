/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:17:35 by paim              #+#    #+#             */
/*   Updated: 2016/11/19 11:36:35 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			mouse_hook(int keycode, t_data *t)
{
	exit(EXIT_FAILURE);
	return (0);
}

int			key_hook3(int keycode, t_data *t)
{
	double	odirx;
	double	oplanx;

	if (keycode == RIGHT)
	{
		odirx = t->dirx;
		t->dirx = odirx * cos(-t->rs) - t->diry * sin(-t->rs);
		t->diry = odirx * sin(-t->rs) + t->diry * cos(-t->rs);
		oplanx = t->planx;
		t->planx = oplanx * cos(-t->rs) - t->plany * sin(-t->rs);
		t->plany = oplanx * sin(-t->rs) + t->plany * cos(-t->rs);
	}
	return (0);
}

int			key_hook2(int keycode, t_data *t)
{
	double	odirx;
	double	oplanx;

	if (keycode == UP)
	{
		if (t->map[(int)(t->posx + t->dirx * t->ms)][(int)t->posy] < 1)
			t->posx += t->dirx * t->ms;
		if (t->map[(int)t->posx][(int)(t->posy + t->diry * t->ms)] < 1)
			t->posy += t->diry * t->ms;
	}
	else if (keycode == DOWN)
	{
		if (t->map[(int)(t->posx - t->dirx * t->ms)][(int)t->posy] < 1)
			t->posx -= t->dirx * t->ms;
		if (t->map[(int)t->posx][(int)(t->posy - t->diry * t->ms)] < 1)
			t->posy -= t->diry * t->ms;
	}
	else
		key_hook3(keycode, t);
	return (0);
}

int			key_hook(int keycode, t_data *t)
{
	double	odirx;
	double	oplanx;

	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	t->img = mlx_new_image(t->mlx, WIDTH, HEIGHT);
	printf("%d\n", keycode);
	if (keycode == 12 && t->onoff == 0)
	{
		t->ms = t->ms * 2;
		t->onoff++;
	}
	if (keycode == 12 && t->onoff == 1)
	{
		t->ms = t->ms / 2;
		t->onoff--;
	}
	if (keycode == 53)
		exit(EXIT_FAILURE);
	else if (keycode == LEFT)
	{
		odirx = t->dirx;
		t->dirx = odirx * cos(t->rs) - t->diry * sin(t->rs);
		t->diry = odirx * sin(t->rs) + t->diry * cos(t->rs);
		oplanx = t->planx;
		t->planx = oplanx * cos(t->rs) - t->plany * sin(t->rs);
		t->plany = oplanx * sin(t->rs) + t->plany * cos(t->rs);
	}
	else
		key_hook2(keycode, t);
	whlrc(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}
