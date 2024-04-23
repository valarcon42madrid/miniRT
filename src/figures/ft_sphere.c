/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:12:17 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 10:47:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	ft_coords_pt_sphere(t_vector v, t_sphere *objet)
{
	t_vector	result;
	t_vector	normalv;
	t_vector	pointplane;
	t_m_plane	plane;
	double		a[5];

	a[0] = objet->ct.x - v.o.x;
	a[1] = objet->ct.y - v.o.y;
	a[2] = objet->ct.z - v.o.z;
	normalv = normalize(v);
	a[3] = ft_module(provec(vec(a[0], a[1], a[2]), normalv));
	if (a[3] > objet->radius)
		return (vec(0, 0, 0));
	plane.pt = objet->ct;
	plane.n = v;
	pointplane = ft_coords_pt_plane222(&plane, v, 0);
	a[4] = sqrt(pow(objet->radius, 2) - pow(a[3], 2));
	a[0] = pointplane.x - a[4] * normalv.x;
	a[1] = pointplane.y - a[4] * normalv.y;
	a[2] = pointplane.z - a[4] * normalv.z;
	result = vec(a[0], a[1], a[2]);
	return (result);
}

t_vector	ft_second_coords_pt_sphere(t_vector v, t_sphere *objet)
{
	t_vector	result;
	t_vector	normalv;
	t_m_plane	plane;
	t_vector	pointplane;
	double		a[5];

	a[0] = objet->ct.x - v.o.x;
	a[1] = objet->ct.y - v.o.y;
	a[2] = objet->ct.z - v.o.z;
	normalv = normalize(v);
	a[4] = ft_module(provec(vec(a[0], a[1], a[2]), normalv));
	if (a[4] > objet->radius)
		return (vec(0, 0, 0));
	plane.pt = objet->ct;
	plane.n = v;
	pointplane = ft_coords_pt_plane222(&plane, v, 0);
	a[3] = sqrt(pow(objet->radius, 2) - pow(a[4], 2));
	a[0] = pointplane.x + a[3] * normalv.x;
	a[1] = pointplane.y + a[3] * normalv.y;
	a[2] = pointplane.z + a[3] * normalv.z;
	result = vec(a[0], a[1], a[2]);
	return (result);
}
