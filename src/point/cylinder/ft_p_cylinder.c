/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:39:58 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:49:14 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

void	ft_p_c_i_r(double *a, t_objet *obj, t_conf *conf, t_cylinder *aux3)
{
	if (ft_light_intersec(obj, conf))
		a[11] = ft_escalar_prod(vec(a[8], a[9], a[10]), aux3->rf.n);
	else
		a[11] = 0;
	if (a[11] < 0)
		a[11] *= -1;
	ft_p_c_reset2(a);
	ft_p_c_c_b(a, conf, aux3);
}

void	ft_p_c_i_c(double *a, t_objet *obj, t_conf *conf, t_cylinder *aux3)
{
	t_vector	cn;

	cn = normalize(vec(a[0], a[1], a[2]));
	if (ft_light_intersec(obj, conf))
		a[11] = ft_escalar_prod(vec(a[8], a[9], a[10]), cn);
	else
		a[11] = 0;
	if (a[11] < 0)
		a[11] *= -1;
	ft_p_c_reset2(a);
	ft_p_c_c_b(a, conf, aux3);
}

void	ft_p_c(t_objet *obj, t_conf *conf, t_cylinder *aux3)
{
	t_vector	t_v;
	t_vector	t_vv;
	int			dist;
	int			extra;
	double		a[15];

	t_v = vec(aux3->b.ct.x, aux3->b.ct.y, aux3->b.ct.z);
	t_vv = vec(aux3->rf.ct.x, aux3->rf.ct.y, aux3->rf.ct.z);
	a[13] = sqrt(t_v.x * t_v.x + t_v.y * t_v.y + t_v.z * t_v.z);
	ft_p_c_reset(a, conf, aux3, t_vv);
	if (a[3] > a[7] - a[14] && a[3] < a[7] + a[14] && a[13] < a[12])
		ft_p_c_i_b(a, obj, conf, aux3);
	else if (a[3] > a[4] + a[5] + a[6] - a[14]
		&& a[3] < a[4] + a[5] + a[6] + a[14] && a[13] > a[12])
		ft_p_c_i_r(a, obj, conf, aux3);
	else
	{
		ft_p_c_reset3(a, aux3);
		extra = a[0] + a[1] + a[2];
		dist = ft_dist_pt_plane(aux3->b.p_e, extra, aux3->inter);
		ft_p_c_reset4(a, aux3, dist);
		t_v = vec(a[0], a[1], a[2]);
		ft_p_c_reset5(a, aux3, t_v);
		ft_p_c_i_c(a, obj, conf, aux3);
	}
}
