/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:36:15 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:41:36 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	ft_cylinder5(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	c->normvd = (provec(obj->dir, vision));
	if (c->normvd.x == 0 && c->normvd.y == 0 && c->normvd.z == 0)
		return (c->result);
	ft_cylinder6(obj, vision, c);
	if (vision.x != 0)
	{
		if (c->a[0] / vision.x < 0)
			return (c->result);
	}
	if (vision.y != 0)
	{
		if (c->a[1] / vision.y < 0)
			return (c->result);
	}
	if (vision.z != 0)
	{
		if (c->a[2] / vision.z < 0)
			return (c->result);
	}
	ft_cylinder7(obj, c);
	if (c->a[8] >= obj->radius)
		return (c->result);
	ft_cylinder8(obj, vision, c);
	return (ft_cylinder9(obj, vision, c));
}

void	ft_cylinder6(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	c->normvd = normalize(c->normvd);
	c->plane.pt = obj->ct;
	c->plane.n = (provec(c->normvd, normalize(obj->dir)));
	c->ptside = ft_coords_pt_plane22(&c->plane, vision);
	ft_c_reset3(c->a, vision, c->ptside);
}

void	ft_cylinder7(t_cylinder *obj, t_coords_c *c)
{
	c->a[7] = ft_dist_pt_recta(c->ptside, obj->dir, obj->ct);
	ft_c_reset4(c->a, c->ptside, c->normvd, c->a[7]);
	c->ptospecial2 = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset4(c->a, c->ptside, c->normvd, c->a[7]);
	c->ptospecial = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset5(c->a, obj->ct, c->ptospecial);
	c->specialcent = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset5(c->a, obj->ct, c->ptospecial2);
	ft_c_reset6(c->a, c->specialcent, vec(c->a[0], c->a[1], c->a[2]));
	if (sqrt(c->a[0] + c->a[1] + c->a[2]) > sqrt(c->a[3] + c->a[4] + c->a[5]))
		c->ptospecial = c->ptospecial2;
	ft_c_reset5(c->a, c->ptside, c->ptospecial);
	c->a[8] = sqrt(pow(c->a[0], 2) + pow(c->a[1], 2) + pow(c->a[2], 2));
}

void	ft_cylinder8(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	c->a[9] = sqrt(pow(obj->radius, 2) - pow(c->a[8], 2));
	ft_c_reset4(c->a, c->ptside, normalize(vision), c->a[9]);
	c->pntexact = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset7(c->a, obj->dir, obj->ct, obj->b.ct);
	c->a[10] = c->a[0] + c->a[1] + c->a[2] - (c->a[3] + c->a[4] + c->a[5]);
	ft_c_reset7(c->a, obj->dir, c->pntexact, obj->b.ct);
	c->a[11] = c->a[0] + c->a[1] + c->a[2] - (c->a[3] + c->a[4] + c->a[5]);
}

t_vector	ft_cylinder9(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	if ((c->a[11] >= 0 && c->a[10] < 0) || (c->a[11] <= 0 && c->a[10] > 0))
		return (c->result);
	ft_c_reset7(c->a, obj->dir, obj->ct, obj->rf.ct);
	c->a[10] = c->a[0] + c->a[1] + c->a[2] - (c->a[3] + c->a[4] + c->a[5]);
	ft_c_reset7(c->a, obj->dir, c->pntexact, obj->rf.ct);
	c->a[11] = c->a[0] + c->a[1] + c->a[2] - (c->a[3] + c->a[4] + c->a[5]);
	if ((c->a[11] >= 0 && c->a[10] < 0) || (c->a[11] <= 0 && c->a[10] > 0))
		return (c->result);
	if (c->whichresult == 1)
	{
		ft_c_reset3(c->a, vision, c->pntexact);
		ft_c_reset3_2(c->a, vision, c->ptb);
		ft_c_reset8(c->a);
		if (c->a[6] > c->a[7])
			return (c->result);
	}
	else if (c->whichresult == 2)
	{
		ft_c_reset3(c->a, vision, c->pntexact);
		ft_c_reset3_2(c->a, vision, c->ptrf);
		ft_c_reset8(c->a);
		if (c->a[6] > c->a[7])
			return (c->result);
	}
	return (c->pntexact);
}
