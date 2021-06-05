/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:11:01 by paim              #+#    #+#             */
/*   Updated: 2017/01/14 10:44:36 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_data	*t;

	if (argc != 1)
		return (error("No need argument."));
	t = init_wolf();
	map(t);
	if ((t->mlx = mlx_init()) == NULL)
		return (0);
	t->win = mlx_new_window(t->mlx, WIDTH, HEIGHT, "Wolf3D");
	t->img = mlx_new_image(t->mlx, WIDTH, HEIGHT);
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->sizeline, &t->endian);
	whlrc(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_hook(t->win, 17, (1L << 17), mouse_hook, t);
	mlx_hook(t->win, 2, 64, key_hook, t);
	mlx_loop(t->mlx);
	return (0);
}
