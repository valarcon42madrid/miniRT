/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:08 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 09:46:53 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	ft_exit_hook(t_destroy *dest)
{
	mlx_destroy_window(dest->window->mlx, dest->window->mlx_win);
	exit(-1);
}

int	key_hook(int keycode, t_destroy *dest)
{
	if (keycode == 53)
		ft_exit_hook(dest);
	return (0);
}

void	ft_make_img(t_img *img, t_conf *conf)
{
	t_m_i	ig;

	ig.tab = (void *)img->d;
	conf->my_pixel.x = 0;
	while (conf->my_pixel.x < 1080)
	{
		ig.aux = (conf->my_pixel.x - 540);
		ig.g = (ig.aux / 540) * tan(conf->m_s.c_l.radian);
		conf->my_pixel.y = 0;
		while (conf->my_pixel.y < 720)
		{
			ig.aux = (conf->my_pixel.y - 360);
			ig.p = (ig.aux / 540) * tan(conf->m_s.c_l.radian);
			ig.v.o = ft_init_zero();
			ig.v = ft_init_vector(ig, conf);
			if (ft_impact(conf, ig.v) == 1)
				ft_obj(ig, conf);
			else
				ft_not_pixel_obj(ig, conf);
			*ig.tab[conf->my_pixel.y][conf->my_pixel.x] = conf->my_pixel.color;
			conf->my_pixel.y++;
		}
		conf->my_pixel.x++;
	}
}

void	ft_mlx_init(t_conf *conf)
{
	t_destroy	d;

	d.conf = conf;
	d.m = ft_sec_malloc(sizeof(*d.m));
	d.window = ft_sec_malloc(sizeof(*d.window));
	d.window->mlx = mlx_init();
	d.m->i = mlx_new_image(d.window->mlx, 1080, 720);
	d.m->d = (unsigned char *)mlx_get_data_addr(d.m->i, &(d.m->b),
			&(d.m->s), &(d.m->e));
	ft_make_img(d.m, conf);
	d.window->mlx_win = mlx_new_window(d.window->mlx, 1080, 720, "MiniRT");
	mlx_put_image_to_window(d.window->mlx, d.window->mlx_win, d.m->i, 0, 0);
	mlx_destroy_image(d.window->mlx, d.m->i);
	mlx_key_hook(d.window->mlx_win, key_hook, &d);
	mlx_hook(d.window->mlx_win, 17, 1L << 17, ft_exit_hook, &d);
	mlx_loop(d.window->mlx);
}
