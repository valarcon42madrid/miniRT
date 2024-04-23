/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:14:44 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 10:45:50 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_coords_pt_plane_222_reset(double *a, t_m_plane *plane, t_vector line)
{
	a[0] = -((plane->pt.x - line.o.x) * plane->n.x);
	a[1] = ((plane->pt.y - line.o.y) * plane->n.y);
	a[2] = ((plane->pt.z - line.o.z) * plane->n.z);
	a[3] = (line.x * plane->n.x);
	a[4] = (line.y * plane->n.y);
	a[5] = (line.z * plane->n.z);
}

void	ft_coords_pt_plane_222_reset2(double *a, t_m_plane *plane)
{
	a[0] = pow(plane->pt.x, 2);
	a[1] = pow(plane->pt.y, 2);
	a[2] = pow(plane->pt.z, 2);
}

t_vector	ft_coords_pt_plane222(t_m_plane *plane, t_vector line, int z)
{
	double		res;
	t_vector	pt;
	double		a[6];

	ft_coords_pt_plane_222_reset(a, plane, line);
	res = -(a[0] - a[1] - a[2]) / (a[3] + a[4] + a[5]);
	if (a[3] + a[4] + a[5] == 0)
	{
		ft_coords_pt_plane_222_reset2(a, plane);
		res = sqrt(a[0] + a[1] + a[2]);
	}
	pt.x = line.o.x + res * line.x;
	pt.y = line.o.y + res * line.y;
	pt.z = line.o.z + res * line.z;
	if (z == 0)
	{
		if (line.x != 0 && pt.x / line.x < 0)
			return (vec(0, 0, 0));
		else if (line.y != 0 && pt.y / line.y < 0)
			return (vec(0, 0, 0));
		else if (line.z != 0 && pt.z / line.z < 0)
			return (vec(0, 0, 0));
	}
	return (pt);
}
