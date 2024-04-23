/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:11:51 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 09:46:34 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	ft_init_vector(t_m_i ig, t_conf *conf)
{
	double	a1;
	double	a2;
	double	a3;
	double	a4;

	a4 = conf->m_s.c_l.h.x * ig.p;
	a1 = conf->m_s.c_l.view.x + a4 + conf->m_s.c_l.w.x * ig.g;
	a4 = conf->m_s.c_l.h.y * ig.p;
	a2 = conf->m_s.c_l.view.y + a4 + conf->m_s.c_l.w.y * ig.g;
	a4 = conf->m_s.c_l.h.z * ig.p;
	a3 = conf->m_s.c_l.view.z + a4 + conf->m_s.c_l.w.z * ig.g;
	return (normalize(vec(a1, a2, a3)));
}

void	ft_obj(t_m_i ig, t_conf *conf)
{
	ig.obj = ft_closet(conf, ig.v);
	if (!ig.obj)
		ft_not_pixel_obj(ig, conf);
	else
		ft_pt(ig.obj, conf);
}

t_v	ft_init_zero(void)
{
	t_v	a;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	return (a);
}

void	ft_not_pixel_obj(t_m_i ig, t_conf *conf)
{
	ig.s = rgb_to_int(conf->m_s.ambient.color);
	conf->my_pixel.color = ig.s;
}
