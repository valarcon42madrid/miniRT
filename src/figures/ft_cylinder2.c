/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:31:12 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 22:32:03 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_c_reset(double *a, t_cylinder *obj, t_vector b)
{
	a[0] = pow(obj->ct.x - b.x, 2);
	a[1] = pow(obj->ct.y - b.y, 2);
	a[2] = pow(obj->ct.z - b.z, 2);
}

void	ft_c_reset2(double *a, t_vector vision, t_vector c, t_vector b)
{
	a[0] = pow(c.x - vision.o.x, 2);
	a[1] = pow(c.y - vision.o.y, 2);
	a[2] = pow(c.z - vision.o.z, 2);
	a[3] = pow(b.x - vision.o.x, 2);
	a[4] = pow(b.y - vision.o.y, 2);
	a[5] = pow(b.z - vision.o.z, 2);
}

void	ft_c_reset3(double *a, t_vector b, t_vector c)
{
	a[0] = c.x - b.o.x;
	a[1] = c.y - b.o.y;
	a[2] = c.z - b.o.z;
}

void	ft_c_reset3_2(double *a, t_vector b, t_vector c)
{
	a[3] = c.x - b.o.x;
	a[4] = c.y - b.o.y;
	a[5] = c.z - b.o.z;
}

void	ft_c_reset4(double *a, t_vector b, t_vector c, double x)
{
	a[0] = b.x - c.x * x;
	a[1] = b.y - c.y * x;
	a[2] = b.z - c.z * x;
}
