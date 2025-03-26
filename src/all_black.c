/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_black.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:53 by valarcon          #+#    #+#             */
/*   Updated: 2023/04/10 10:25:27 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

void	ft_make_black_img(t_img *img, t_conf *conf)
{
	t_m_i	ig;

	ig.tab = (void *)img->d;
	conf->my_pixel.x = 0;
	while (conf->my_pixel.x < 1080)
	{
		conf->my_pixel.y = 0;
		while (conf->my_pixel.y < 720)
		{
			conf->my_pixel.color = 0;
			*ig.tab[conf->my_pixel.y][conf->my_pixel.x] = conf->my_pixel.color;
			conf->my_pixel.y++;
		}
		conf->my_pixel.x++;
	}
}

void	ft_all_black(t_conf *conf)
{
	t_destroy	d;

	d.conf = conf;
	d.m = ft_sec_malloc(sizeof(*d.m));
	d.window = ft_sec_malloc(sizeof(*d.window));
	d.window->mlx = mlx_init();
	d.m->i = mlx_new_image(d.window->mlx, 1080, 720);
	d.m->d = (unsigned char *)mlx_get_data_addr(d.m->i, &(d.m->b),
			&(d.m->s), &(d.m->e));
	ft_make_black_img(d.m, conf);
	d.window->mlx_win = mlx_new_window(d.window->mlx, 1080, 720, "MiniRT");
	mlx_put_image_to_window(d.window->mlx, d.window->mlx_win, d.m->i, 0, 0);
	mlx_destroy_image(d.window->mlx, d.m->i); //comentado porque con el movimiento, si estas dentro de una figura, da segfault (antes tenia sentido borrar todo si iibamos a printer negro)
	mlx_key_hook(d.window->mlx_win, key_hook, &d);
	mlx_hook(d.window->mlx_win, 17, 1L << 17, ft_exit_hook, &d);
	mlx_loop(d.window->mlx);
}
