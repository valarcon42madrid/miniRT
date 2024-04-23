/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:34:49 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 02:00:35 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	ft_light_vect(t_objet *obj, t_conf *conf)
{
	t_vector	aux;

	if (obj->type == 1)
		aux = ft_light_sphere(obj, conf);
	if (obj->type == 2)
		aux = ft_light_cylinder(obj, conf);
	if (obj->type == 3)
		aux = ft_light_plane(obj, conf);
	return (aux);
}

int	ft_light_confirm(t_objet *obj, t_objet *res)
{
	if (obj->type == 1)
		return (ft_light_sphere_confirm(obj, res));
	if (obj->type == 2)
		return (ft_light_cylinder_confirm(obj, res));
	if (obj->type == 3)
		return (ft_light_plane_confirm(obj, res));
	return (0);
}

int	ft_light_intersec(t_objet *obj, t_conf *conf)
{
	t_objet		*obj2;
	t_list		*list;
	double		mod2[2];
	t_objet		*res;
	t_vector	aux;

	mod2[1] = 10000000;
	list = conf->m_s.obj_lst;
	obj2 = (t_objet *)list->content;
	res = NULL;
	aux = ft_light_vect(obj, conf);
	while (list->content)
	{
		obj2 = (t_objet *)list->content;
		if (obj2->type == 1)
			res = ft_light_s_i(aux, obj2, mod2, res);
		if (obj2->type == 2)
			res = ft_light_c_i(aux, obj2, mod2, res);
		if (obj2->type == 3)
			res = ft_light_p_i(aux, obj2, mod2, res);
		list = list->next;
	}
	if (res && res->type == obj->type)
		return (ft_light_confirm(obj, res));
	return (0);
}
