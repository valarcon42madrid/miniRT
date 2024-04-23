/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_cylinder2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:46:30 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:48:44 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

int	ft_dist_pt_plane(t_vector plane, int extra, t_vector pt)
{
	int	res;
	int	a1;

	a1 = plane.x * pt.x + plane.y * pt.y + plane.z * pt.z + extra;
	res = ((a1) / sqrt(pow(plane.x, 2) + pow(plane.y, 2) + pow(plane.z, 2)));
	if (res < 0)
		res *= -1;
	return (res);
}

void	ft_p_c_reset(double *a, t_conf *conf, t_cylinder *aux3, t_vector t)
{
	a[0] = aux3->b.n.x * aux3->inter.x;
	a[1] = aux3->b.n.y * aux3->inter.y;
	a[2] = aux3->b.n.z * aux3->inter.z;
	a[3] = a[0] + a[1] + a[2];
	a[0] = aux3->b.n.x * aux3->b.ct.x;
	a[1] = aux3->b.n.y * aux3->b.ct.y;
	a[2] = aux3->b.n.z * aux3->b.ct.z;
	a[4] = aux3->b.n.x * aux3->rf.ct.x;
	a[5] = aux3->b.n.y * aux3->rf.ct.y;
	a[6] = aux3->b.n.z * aux3->rf.ct.z;
	a[7] = (a[0] + a[1] + a[2]);
	a[8] = conf->m_s.l_l.pos.x - aux3->inter.x;
	a[9] = conf->m_s.l_l.pos.y - aux3->inter.y;
	a[10] = conf->m_s.l_l.pos.z - aux3->inter.z;
	a[12] = sqrt(t.x * t.x + t.y * t.y + t.z * t.z);
	a[14] = 0.00000000000001;
}

void	ft_p_c_reset2(double *a)
{
	a[0] = pow(a[8], 2);
	a[1] = pow(a[9], 2);
	a[2] = pow(a[10], 2);
}

void	ft_p_c_c_b(double *a, t_conf *conf, t_cylinder *aux3)
{
	t_rgb		rgb;
	double		distance;

	distance = sqrt(a[0] + a[1] + a[2]);
	a[0] = conf->m_s.ambient.radius * conf->m_s.ambient.color.red / 255;
	a[2] = conf->m_s.l_l.radius / distance;
	a[1] = a[11] / distance * (a[2]);
	rgb.red = ((a[0]) + (a[1])) * aux3->color.red;
	a[2] = conf->m_s.ambient.radius * conf->m_s.ambient.color.green;
	rgb.green = ((a[2] / 255) + (a[1])) * aux3->color.green;
	a[2] = conf->m_s.ambient.radius * conf->m_s.ambient.color.blue;
	rgb.blue = ((a[2] / 255) + (a[1])) * aux3->color.blue;
	ft_put_color(rgb, conf);
}

void	ft_p_c_i_b(double *a, t_objet *obj, t_conf *conf, t_cylinder *aux3)
{
	if (ft_light_intersec(obj, conf))
		a[11] = ft_escalar_prod(vec(a[8], a[9], a[10]), aux3->b.n);
	else
		a[11] = 0;
	if (a[11] < 0)
		a[11] *= -1;
	ft_p_c_reset2(a);
	ft_p_c_c_b(a, conf, aux3);
}
