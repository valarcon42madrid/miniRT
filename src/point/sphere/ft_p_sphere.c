/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:40:01 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:14:27 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

int	ft_dark_sp(t_vector	inter, t_vector	l, t_vector	campos, t_sphere *sp)
{
	t_vector	normplane;
	double		a[10];

	ft_darkside_reset(a, l, campos);
	normplane = vec(a[0], a[1], a[2]);
	ft_darkside_reset2(a, normplane, campos, inter);
	ft_darkside_reset3(a, normplane, l);
	if ((a[9] > 0 && a[6] + a[7] + a[8] - (a[3] + a[4] + a[5]) < 0))
		return (1);
	a[0] = l.x - sp->ct.x;
	a[1] = l.y - sp->ct.y;
	a[2] = l.z - sp->ct.z;
	a[3] = ft_module(vec(a[0], a[1], a[2]));
	a[0] = campos.x - sp->ct.x;
	a[1] = campos.y - sp->ct.y;
	a[2] = campos.z - sp->ct.z;
	a[4] = ft_module(vec(a[0], a[1], a[2]));
	if ((a[3] > sp->radius && a[4] < sp->radius)
		|| (a[3] < sp->radius && a[4] > sp->radius))
		return (1);
		a[0] = campos.x - sp->ct.x;
	if (a[3] < ft_module(vec(l.x - inter.x, l.y - inter.y, l.z - inter.z)))
		return (1);
	return (0);
}

void	ft_pt_s_reset(double *a, t_vector b, t_vector c)
{
	a[0] = b.x - c.x;
	a[1] = b.y - c.y;
	a[2] = b.z - c.z;
}

void	ft_pt_s(t_objet *obj, t_conf *conf, t_sphere *aux)
{
	double		intensity;
	double		distance;
	t_vector	perp;
	double		a[3];
	t_rgb		rgb;

	ft_pt_s_reset(a, aux->inter, aux->ct);
	perp = normalize(vec(a[0], a[1], a[2]));
	ft_pt_s_reset(a, aux->inter, conf->m_s.l_l.pos);
	intensity = 0;
	if (ft_light_intersec(obj, conf))
		intensity = ft_escalar_prod((vec(a[0], a[1], a[2])), perp);
	if (ft_dark_sp(aux->inter, conf->m_s.l_l.pos, conf->m_s.c_l.pos, aux) == 1)
		intensity = 0;
	distance = sqrt(pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2));
	if (intensity < 0)
		intensity *= -1;
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.red / 255;
	a[1] = intensity / distance * (conf->m_s.l_l.radius / distance);
	rgb.red = ((a[0]) + (a[1])) * aux->color.red;
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.green / 255;
	rgb.green = ((a[0]) + (a[1])) * aux->color.green;
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.blue / 255;
	rgb.blue = ((a[0]) + (a[1])) * aux->color.blue;
	ft_put_color(rgb, conf);
}
