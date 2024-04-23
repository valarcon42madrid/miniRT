/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:15:41 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:41:40 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

t_vector	ft_coords_pt_plane22(t_m_plane *plane, t_vector line)
{
	double		nb;
	double		res;
	t_vector	pt;
	double		a[3];

	a[0] = -((plane->pt.x - line.o.x) * plane->n.x);
	a[1] = ((plane->pt.y - line.o.y) * plane->n.y);
	a[2] = ((plane->pt.z - line.o.z) * plane->n.z);
	nb = a[0] - a[1] - a[2];
	a[0] = (line.x * plane->n.x);
	a[1] = (line.y * plane->n.y);
	a[2] = (line.z * plane->n.z);
	res = -nb / (a[0] + a[1] + a[2]);
	if (a[0] + a[1] + a[2] == 0)
		res = 1;
	pt.x = line.o.x + res * line.x;
	pt.y = line.o.y + res * line.y;
	pt.z = line.o.z + res * line.z;
	return (pt);
}

t_vector	ft_coords_pt_cylinder(t_cylinder *obj, t_vector vision)
{
	t_coords_c	c;

	ft_cylinder2(obj, vision, &c);
	ft_cylinder3(obj, vision, &c);
	return (ft_cylinder4(obj, vision, &c));
}

void	ft_cylinder2(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	c->whichresult = 0;
	c->result = vec(obj->ct.x, obj->ct.y, obj->ct.z);
	c->plane.pt = obj->b.ct;
	c->plane.n = normalize(obj->b.n);
	c->ptb = ft_coords_pt_plane22(&c->plane, vision);
	ft_c_reset5(c->a, obj->b.ct, c->ptb);
	c->aux = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset(c->a, obj, c->ptb);
	c->a[6] = pow((obj->height / 2), 2);
	c->a[11] = sqrt(pow(c->aux.x, 2) + pow(c->aux.y, 2) + pow(c->aux.z, 2));
	c->a[10] = sqrt(c->a[0] + c->a[1] + c->a[2]);
	if (c->a[11] < obj->radius
		&& c->a[10] < sqrt(pow(obj->radius, 2) + c->a[6])
		&& dot_prod(obj->dir, vision))
	{
		if ((vision.x != 0 && (c->ptb.x - vision.o.x) / vision.x > 0)
			|| (vision.y != 0 && (c->ptb.y - vision.o.y) / vision.y > 0)
			|| (vision.z != 0 && (c->ptb.z - vision.o.z) / vision.z > 0))
		{
			c->result = vec(c->ptb.x, c->ptb.y, c->ptb.z);
			c->whichresult = 1;
		}
	}
}

void	ft_cylinder3(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	c->plane.pt = obj->rf.ct;
	c->plane.n = normalize(obj->rf.n);
	c->ptrf = ft_coords_pt_plane22(&c->plane, vision);
	ft_c_reset5(c->a, obj->rf.ct, c->ptrf);
	c->aux2 = vec(c->a[0], c->a[1], c->a[2]);
	ft_c_reset(c->a, obj, c->ptrf);
	c->a[11] = sqrt(pow(c->aux2.x, 2) + pow(c->aux2.y, 2) + pow(c->aux2.z, 2));
}

t_vector	ft_cylinder4(t_cylinder *obj, t_vector vision, t_coords_c *c)
{
	double	b;

	b = sqrt(c->a[0] + c->a[1] + c->a[2]);
	if (c->a[11] < obj->radius && b < sqrt(pow(obj->radius, 2) + c->a[6])
		&& dot_prod(obj->dir, vision))
	{
		if ((vision.x != 0 && (c->ptrf.x - vision.o.x) / vision.x > 0)
			|| (vision.y != 0 && (c->ptrf.y - vision.o.y) / vision.y > 0)
			|| (vision.z != 0 && (c->ptrf.z - vision.o.z) / vision.z > 0))
		{
			ft_c_reset2(c->a, vision, c->ptrf, c->ptb);
			c->a[11] = sqrt(c->a[0] + c->a[1] + c->a[2]);
			if (c->whichresult == 0)
			{
				c->result = vec(c->ptrf.x, c->ptrf.y, c->ptrf.z);
				c->whichresult = 2;
			}
			else if (c->whichresult == 1
				&& c->a[11] < sqrt(c->a[3] + c->a[4] + c->a[5]))
				return (c->ptrf);
			else
				return (c->result);
		}
	}
	return (ft_cylinder5(obj, vision, c));
}
