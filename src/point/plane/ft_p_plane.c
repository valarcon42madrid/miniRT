/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:39:59 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:52:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

void	ft_p_p_reset4(double *a)
{
	a[0] = pow(a[3], 2);
	a[1] = pow(a[4], 2);
	a[2] = pow(a[5], 2);
	a[6] = sqrt(a[0] + a[1] + a[2]);
}

void	ft_p_p2(double *a, t_conf *conf, t_m_plane *aux2, double intensity)
{
	t_rgb		rgb;

	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.red / 255;
	a[1] = intensity / a[6] * (conf->m_s.l_l.radius / a[6]);
	rgb.red = ((a[0]) + (a[1])) * aux2->color.red;
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.green / 255;
	rgb.green = ((a[0]) + (a[1])) * aux2->color.green;
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.blue / 255;
	rgb.blue = ((a[0]) + (a[1])) * aux2->color.blue;
	ft_put_color(rgb, conf);
}

void	ft_p_p(t_objet *obj, t_conf *conf, t_m_plane *aux2)
{
	double		intensity;
	t_vector	t_v;
	t_vector	t_vv;
	double		a[10];

	ft_p_p_reset(a, aux2->inter, conf->m_s.l_l.pos);
	t_v = (vec(a[3], a[4], a[5]));
	if (ft_light_intersec(obj, conf))
		intensity = ft_escalar_prod(t_v, (aux2->n));
	else
		intensity = 0;
	if (intensity < 0)
		intensity *= -1;
	ft_p_p_reset2(a, aux2->n, conf->m_s.l_l.pos);
	t_v = vec(a[0], a[1], a[2]);
	ft_p_p_reset2(a, aux2->n, conf->m_s.c_l.pos);
	t_vv = vec(a[0], a[1], a[2]);
	ft_p_p_reset2(a, aux2->n, aux2->pt);
	ft_p_p_reset3(a, t_v, t_vv);
	if ((a[9] < a[7] && a[8] > a[7])
		|| (a[9] > a[7] && a[8] < a[7]))
		intensity = 0;
	ft_p_p_reset4(a);
	ft_p_p2(a, conf, aux2, intensity);
}
