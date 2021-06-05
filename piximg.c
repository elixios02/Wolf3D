/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:49:57 by paim              #+#    #+#             */
/*   Updated: 2016/11/01 16:28:58 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ft_put_pixel_to_image2(t_data *t, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (y <= 0 || x <= 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	r = (t->color_img & 0xFF0000) >> 16;
	g = (t->color_img & 0xFF00) >> 8;
	b = (t->color_img & 0xFF) >> 0;
	t->data[y * t->sizeline + x * t->bpp / 8] = b;
	t->data[y * t->sizeline + x * t->bpp / 8 + 1] = g;
	t->data[y * t->sizeline + x * t->bpp / 8 + 2] = r;
}

void				ft_put_pixel_to_image(t_data *t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (t->dstart <= 0 || t->x <= 0 || t->x >= WIDTH || t->dstart >= HEIGHT)
		return ;
	r = (t->color_img & 0xFF0000) >> 16;
	g = (t->color_img & 0xFF00) >> 8;
	b = (t->color_img & 0xFF) >> 0;
	t->data[t->dstart * t->sizeline + t->x * t->bpp / 8] = b;
	t->data[t->dstart * t->sizeline + t->x * t->bpp / 8 + 1] = g;
	t->data[t->dstart * t->sizeline + t->x * t->bpp / 8 + 2] = r;
}
