/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:10 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 10:45:54 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

int	ft_light_plane_confirm(t_objet *obj, t_objet *res)
{
	t_m_plane	*plane;
	t_m_plane	*plane2;

	plane = (t_m_plane *)obj->objet;
	plane2 = (t_m_plane *)res->objet;
	if (plane2->pt.x == plane->pt.x
		&& plane2->pt.y == plane->pt.y
		&& plane2->pt.z == plane->pt.z
		&& plane2->n.x == plane->n.x
		&& plane2->n.y == plane->n.y
		&& plane2->n.z == plane->n.z)
		return (1);
	return (0);
}

t_vector	ft_light_plane(t_objet *obj, t_conf *conf)
{
	t_m_plane	*plane;
	t_vector	aux;
	double		a1;
	double		a2;
	double		a3;

	plane = (t_m_plane *)obj->objet;
	a1 = plane->inter.x - conf->m_s.l_l.pos.x;
	a2 = plane->inter.y - conf->m_s.l_l.pos.y;
	a3 = plane->inter.z - conf->m_s.l_l.pos.z;
	aux = normalize(vec(a1, a2, a3));
	aux.o.x = conf->m_s.l_l.pos.x;
	aux.o.y = conf->m_s.l_l.pos.y;
	aux.o.z = conf->m_s.l_l.pos.z;
	return (aux);
}

t_objet	*ft_light_p_i(t_vector aux, t_objet *obj2, double *mod2, t_objet *res)
{
	t_vector	coords_light;
	t_m_plane	*plane;
	double		a[3];

	plane = (t_m_plane *)obj2->objet;
	if (ft_vector_to_plane(aux, plane) == 1)
	{
		coords_light = ft_coords_pt_plane222(plane, aux, 1);
		if (coords_light.x == 0 && coords_light.y == 0 && coords_light.z == 0)
			return (obj2);
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
