/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:13 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 02:00:09 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

int	ft_light_sphere_confirm(t_objet *obj, t_objet *res)
{
	t_sphere	*sphere;
	t_sphere	*sphere2;

	sphere = (t_sphere *)obj->objet;
	sphere2 = (t_sphere *)res->objet;
	if (sphere2->ct.x == sphere->ct.x
		&& sphere2->ct.y == sphere->ct.y
		&& sphere2->ct.z == sphere->ct.z
		&& sphere2->radius == sphere->radius)
		return (1);
	return (0);
}

t_vector	ft_light_sphere(t_objet *obj, t_conf *conf)
{
	t_sphere	*sphere;
	t_vector	aux;
	double		a1;
	double		a2;
	double		a3;

	sphere = (t_sphere *)obj->objet;
	a1 = sphere->inter.x - conf->m_s.l_l.pos.x;
	a2 = sphere->inter.y - conf->m_s.l_l.pos.y;
	a3 = sphere->inter.z - conf->m_s.l_l.pos.z;
	aux = normalize(vec(a1, a2, a3));
	aux.o.x = conf->m_s.l_l.pos.x;
	aux.o.y = conf->m_s.l_l.pos.y;
	aux.o.z = conf->m_s.l_l.pos.z;
	return (aux);
}

t_objet	*ft_light_s_i(t_vector aux, t_objet *obj2, double *mod2, t_objet *res)
{
	t_vector	coords_light;
	t_sphere	*sphere;
	double		a[3];

	sphere = (t_sphere *)obj2->objet;
	if (ft_vector_to_sphere(aux, sphere) == 1)
	{
		coords_light = ft_coords_pt_sphere(aux, sphere);
		a[0] = coords_light.x - aux.o.x;
		a[1] = coords_light.y - aux.o.y;
		a[2] = coords_light.z - aux.o.z;
		coords_light = vec(a[0], a[1], a[2]);
		mod2[0] = ft_module(coords_light);
		if (mod2[0] < mod2[1])
		{
			mod2[1] = mod2[0];
			res = obj2;
		}
	}
	return (res);
}
