/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_objet2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:23:23 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:46:19 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	normalize(t_vector u)
{
	return (prod(u, 1.0 / magnitude(u)));
}

t_sphere	*sphere_init(double *param)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)ft_sec_malloc(sizeof(t_sphere));
	sphere->ct = vec(param[0], param[1], param[2]);
	sphere->radius = param[3] / 2;
	sphere->color = ft_color(param[4], param[5], param[6]);
	return (sphere);
}

t_cylinder	*cylinder_init(double *param)
{
	t_cylinder	*cylinder;

	cylinder = ft_sec_malloc(sizeof(t_cylinder));
	cylinder->ct = vec(param[0], param[1], param[2]);
	cylinder->dir = normalize(vec(param[3], param[4], param[5]));
	cylinder->radius = param[6] / 2;
	cylinder->height = param[7];
	cylinder->color = ft_color(param[8], param[9], param[10]);
	return (cylinder);
}

t_m_plane	*plane_init(double *param)
{
	t_m_plane	*plane;

	plane = ft_sec_malloc(sizeof(t_m_plane));
	plane->pt = vec(param[0], param[1], param[2]);
	plane->n = normalize(vec(param[3], param[4], param[5]));
	plane->color = ft_color(param[6], param[7], param[8]);
	return (plane);
}

void	ft_objetinit(double *paramsin, t_objet *obj)
{
	if (obj->type == SPHERE)
		obj->objet = (sphere_init(paramsin));
	else if (obj->type == PLANE)
		obj->objet = (plane_init(paramsin));
	else if (obj->type == CYLINDER)
		obj->objet = (cylinder_init(paramsin));
}
