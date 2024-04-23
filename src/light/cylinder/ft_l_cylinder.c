/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:58:04 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 02:00:20 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

int	ft_light_cylinder_confirm(t_objet *obj, t_objet *res)
{
	t_cylinder	*cylinder;
	t_cylinder	*cylinder2;

	cylinder = (t_cylinder *)obj->objet;
	cylinder2 = (t_cylinder *)res->objet;
	if (cylinder2->ct.x == cylinder->ct.x
		&& cylinder2->ct.y == cylinder->ct.y
		&& cylinder2->ct.z == cylinder->ct.z
		&& cylinder2->dir.x == cylinder->dir.x
		&& cylinder2->dir.y == cylinder->dir.y
		&& cylinder2->dir.z == cylinder->dir.z
		&& cylinder2->height == cylinder->height)
		return (1);
	return (0);
}

t_vector	ft_light_cylinder(t_objet *obj, t_conf *conf)
{
	t_cylinder	*cylinder;
	t_vector	aux;
	double		a1;
	double		a2;
	double		a3;

	cylinder = (t_cylinder *)obj->objet;
	a1 = cylinder->inter.x - conf->m_s.l_l.pos.x;
	a2 = cylinder->inter.y - conf->m_s.l_l.pos.y;
	a3 = cylinder->inter.z - conf->m_s.l_l.pos.z;
	aux = normalize(vec(a1, a2, a3));
	aux.o.x = conf->m_s.l_l.pos.x;
	aux.o.y = conf->m_s.l_l.pos.y;
	aux.o.z = conf->m_s.l_l.pos.z;
	return (aux);
}

t_objet	*ft_light_c_i(t_vector aux, t_objet *obj2, double *mod2, t_objet *res)
{
	t_vector	coords_light;
	t_cylinder	*cylinder;
	double		a[3];

	cylinder = (t_cylinder *)obj2->objet;
	if (ft_vector_to_cylinder(aux, cylinder) == 1)
	{
		coords_light = ft_coords_pt_cylinder(cylinder, aux);
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
