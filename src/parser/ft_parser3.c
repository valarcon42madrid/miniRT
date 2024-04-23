/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valarcon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:07 by valarcon          #+#    #+#             */
/*   Updated: 2023/04/10 13:58:21 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

double	ft_dist_p_plane(t_vector plane, t_vector pt)
{
	double	res;
	double	a1;

	a1 = plane.x * pt.x + plane.y * pt.y + plane.z * pt.z;
	res = ((a1) / sqrt(pow(plane.x, 2) + pow(plane.y, 2) + pow(plane.z, 2)));
	if (res < 0)
		res *= -1;
	return (res);
}

int	ft_insidecy(t_cylinder *c)
{
	t_vector	plane;
	double		aaa;

	aaa = ft_dist_pt_recta(vec(0, 0, 0), c->dir, c->ct);
	if (aaa > c->radius)
		return (0);
	plane = c->dir;
	aaa = ft_dist_p_plane(plane, c->b.ct);
	if (aaa > c->height)
		return (0);
	aaa = ft_dist_p_plane(plane, c->rf.ct);
	if (aaa > c->height)
		return (0);
	return (1);
}

int	ft_inside_cy(t_cylinder *c)
{
	if (ft_insidecy(c) == 1 && ft_module(c->b.ct)
		< sqrt(c->height * c->height + c->radius * c->radius)
		&& ft_module(c->rf.ct)
		< sqrt(c->height * c->height + c->radius * c->radius)
		&& ft_module(c->ct)
		< sqrt(c->height / 2 * c->height / 2 + c->radius * c->radius)
		&& (ft_module(c->b.ct) - ft_module(c->rf.ct) == 0
			|| (ft_module(c->b.ct) - ft_module(c->rf.ct) > 0
				&& ft_module(c->rf.ct) - ft_module(c->b.ct) < 0)
			|| (ft_module(c->b.ct) - ft_module(c->rf.ct) < 0
				&& ft_module(c->rf.ct) - ft_module(c->b.ct) > 0)))
		return (1);
	else
		return (0);
}

int	ft_error_free_return(t_conf	*conf)
{
	printf("ERROR");
	free (conf->m_s.obj_lst);
	exit (1);
}

int	ft_inplane(t_m_plane *p)
{
	if (p->n.x * p->pt.x + p->n.y * p->pt.y + p->n.z * p->pt.z == 0)
		return (1);
	return (0);
}
