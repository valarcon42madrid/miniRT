/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:31:54 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:37:32 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_c_reset5(double *a, t_vector b, t_vector c)
{
	a[0] = b.x - c.x;
	a[1] = b.y - c.y;
	a[2] = b.z - c.z;
}

void	ft_c_reset6(double *a, t_vector b, t_vector c)
{
	a[0] = pow(b.x, 2);
	a[1] = pow(b.y, 2);
	a[2] = pow(b.z, 2);
	a[3] = pow(c.x, 2);
	a[4] = pow(c.y, 2);
	a[5] = pow(c.z, 2);
}

void	ft_c_reset7(double *a, t_vector b, t_vector c, t_vector d)
{
	a[0] = b.x * c.x;
	a[1] = b.y * c.y;
	a[2] = b.z * c.z;
	a[3] = b.x * d.x;
	a[4] = b.y * d.y;
	a[5] = b.z * d.z;
}

void	ft_c_reset8(double *a)
{
	a[6] = ft_module(vec(a[0], a[1], a[2]));
	a[7] = ft_module(vec(a[3], a[4], a[5]));
}

double	ft_dist_pt_recta(t_vector pt, t_vector vect, t_vector precta)
{
	t_vector	pr_p;
	t_vector	prodv_prp_vec;
	double		modpr_prp_v;
	double		modvec;
	double		a[4];

	pr_p = (vec((pt.x - precta.x), (pt.y - precta.y), (pt.z - precta.z)));
	prodv_prp_vec = provec(pr_p, vect);
	if (prodv_prp_vec.x == 0 && prodv_prp_vec.y == 0 && prodv_prp_vec.z == 0)
		return (0);
	a[0] = pow(prodv_prp_vec.x, 2);
	a[1] = pow(prodv_prp_vec.y, 2);
	a[2] = pow(prodv_prp_vec.z, 2);
	modpr_prp_v = sqrt(a[0] + a[1] + a[2]);
	modvec = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	if (modvec == 0)
		return (0);
	a[3] = modpr_prp_v / modvec;
	return (a[3]);
}
