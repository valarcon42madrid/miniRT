/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:17:01 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 10:46:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_objet	*ft_closet_sphere2(t_vector v, t_objet *obj, t_objet *res, double *mod)
{
	t_sphere	*tmp;
	t_vector	coord;

	tmp = (t_sphere *)obj->objet;
	coord = ft_second_coords_pt_sphere(v, tmp);
	if ((v.x != 0 && (coord.x - v.o.x) / v.x > 0)
		|| (v.y != 0 && (coord.y - v.o.y) / v.y > 0)
		|| (v.z != 0 && (coord.z - v.o.z) / v.z > 0))
	{
		tmp->inter = coord;
		mod[0] = ft_module(coord);
		if (mod[0] < mod[1])
		{
			mod[1] = mod[0];
			res = obj;
		}
	}
	return (res);
}

t_objet	*ft_closet_sphere(t_vector v, t_objet *obj, t_objet *res, double *mod)
{
	t_sphere	*tmp;
	t_vector	coord;

	tmp = (t_sphere *)obj->objet;
	if (ft_vector_to_sphere(v, tmp) == 1)
	{
		coord = ft_coords_pt_sphere(v, tmp);
		if ((v.x != 0 && (coord.x - v.o.x) / v.x > 0)
			|| (v.y != 0 && (coord.y - v.o.y) / v.y > 0)
			|| (v.z != 0 && (coord.z - v.o.z) / v.z > 0))
		{
			tmp->inter = coord;
			mod[0] = ft_module(coord);
			if (mod[0] < mod[1])
			{
				mod[1] = mod[0];
				res = obj;
			}
		}
		else
			res = ft_closet_sphere2(v, obj, res, mod);
	}
	return (res);
}

t_objet	*ft_closet_plane(t_vector v, t_objet *obj, t_objet *res, double *mod)
{
	t_m_plane	*tmp2;
	t_vector	coord;

	tmp2 = (t_m_plane *)obj->objet;
	if (ft_vector_to_plane(v, tmp2) == 1)
	{
		coord = ft_coords_pt_plane222(tmp2, v, 0);
		if (coord.x != 0
			|| coord.y != 0
			|| coord.z != 0)
		{
			tmp2->inter = coord;
			mod[0] = ft_module(coord);
			if (mod[0] < mod[1])
			{
				mod[1] = mod[0];
				res = obj;
			}
		}
	}
	return (res);
}

t_objet	*ft_closet_cylinder(t_vector v, t_objet *obj, t_objet *res, double *mod)
{
	t_cylinder	*tmp3;
	t_vector	coord;

	tmp3 = (t_cylinder *)obj->objet;
	if (ft_vector_to_cylinder(v, tmp3) == 1)
	{
		coord = ft_coords_pt_cylinder(tmp3, v);
		if (coord.x != tmp3->ct.x
			|| coord.y != tmp3->ct.y
			|| coord.z != tmp3->ct.z)
		{
			tmp3->inter = coord;
			mod[0] = ft_module(coord);
			if (mod[0] < mod[1])
			{
				mod[1] = mod[0];
				res = obj;
			}
		}
	}
	return (res);
}

t_objet	*ft_closet(t_conf *conf, t_vector v)
{
	t_list		*list;
	t_objet		*obj;
	t_objet		*res;
	double		mod[2];

	mod[0] = 0;
	mod[1] = 10000000;
	list = conf->m_s.obj_lst;
	obj = (t_objet *)list->content;
	res = NULL;
	while (list->content)
	{
		obj = (t_objet *)list->content;
		if (obj->type == 1)
			res = ft_closet_sphere(v, obj, res, mod);
		else if (obj->type == 2)
			res = ft_closet_cylinder(v, obj, res, mod);
		else if (obj->type == 3)
			res = ft_closet_plane(v, obj, res, mod);
		list = list->next;
	}
	return (res);
}
