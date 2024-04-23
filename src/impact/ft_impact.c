/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_impact.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:01:48 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:28:45 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	ft_impact(t_conf *conf, t_vector v)
{
	t_list	*list;
	t_objet	*obj;

	list = conf->m_s.obj_lst;
	while (list->content)
	{
		obj = (t_objet *)list->content;
		if (obj->type == 1)
		{
			if (ft_vector_to_sphere(v, (t_sphere *)obj->objet) == 1)
				return (1);
		}
		else if (obj->type == 2)
		{
			if (ft_vector_to_cylinder(v, (t_cylinder *)obj->objet) == 1)
				return (1);
		}
		else if (obj->type == 3)
		{
			if (ft_vector_to_plane(v, (t_m_plane *)obj->objet) == 1)
				return (1);
		}
		list = list->next;
	}
	return (0);
}
