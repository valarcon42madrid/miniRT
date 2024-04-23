/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_figures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:31:25 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:28:34 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	ft_vector_to_sphere(t_vector v, t_sphere *objet)
{
	double		distcent;
	double		aux;
	double		aux2;
	t_vector	preaux;

	preaux.x = (objet->ct.y - v.o.y) * v.z - (objet->ct.z - v.o.z) * v.y;
	preaux.y = (objet->ct.z - v.o.z) * v.x - (objet->ct.x - v.o.x) * v.z;
	preaux.z = (objet->ct.x - v.o.x) * v.y - (objet->ct.y - v.o.y) * v.x;
	aux = sqrt(pow(preaux.x, 2) + pow(preaux.y, 2) + pow(preaux.z, 2));
	if (aux < 0)
		aux *= -1;
	aux2 = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	distcent = aux / aux2;
	if (distcent < 0)
		distcent *= -1;
	if (distcent > objet->radius)
		return (0);
	return (1);
}

double	ft_proyectvector2(t_vector a, t_vector nor)
{
	return (dot_prod(a, nor) / (ft_module(nor) * ft_module(nor)));
}

t_vector	ft_coords_pt_plane3(t_circle *plane, t_vector line)
{
	double		nb;
	t_vector	pt;
	double		a1;
	double		a2;
	double		a3;

	a1 = (plane->ct.x - line.o.x) * plane->n.x;
	a2 = (plane->ct.y - line.o.y) * plane->n.y;
	a3 = (plane->ct.z - line.o.z) * plane->n.z;
	nb = -(a1) - (a2) - (a3);
	a1 = (line.x * plane->n.x);
	a2 = (line.y * plane->n.y);
	a3 = (line.z * plane->n.z);
	nb = -nb / (a1 + a2 + a3);
	pt.x = nb * line.x;
	pt.y = nb * line.y;
	pt.z = nb * line.z;
	return (pt);
}

int	ft_vector_to_cylinder(t_vector vision, t_cylinder *objet)
{
	t_vector	c;

	c = ft_coords_pt_cylinder(objet, vision);
	if (c.x == objet->ct.x && c.y == objet->ct.y && c.z == objet->ct.z)
		return (0);
	else
		return (1);
}

int	ft_vector_to_plane(t_vector v, t_m_plane *objet)
{
	t_vector	origplane;
	t_vector	noorigiplane;
	double		dist;
	double		dist2;
	double		dist3;

	origplane.x = objet->pt.x - v.o.x;
	origplane.y = objet->pt.y - v.o.y;
	origplane.z = objet->pt.z - v.o.z;
	dist = objet->pt.x - v.o.x - v.x * 0.0000000001;
	dist2 = objet->pt.y - v.o.y - v.y * 0.0000000001;
	dist3 = objet->pt.z - v.o.z - v.z * 0.0000000001;
	noorigiplane = vec(dist, dist2, dist3);
	dist = ft_module(origplane);
	dist2 = ft_module(noorigiplane);
	if (dist < dist2)
		return (0);
	return (1);
}
