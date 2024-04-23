/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_plane2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:51:43 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:52:04 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

void	ft_p_p_reset(double *a, t_vector aux2, t_vector light)
{
	a[3] = aux2.x - light.x;
	a[4] = aux2.y - light.y;
	a[5] = aux2.z - light.z;
}

void	ft_p_p_reset2(double *a, t_vector b, t_vector c)
{
	a[0] = b.x * c.x;
	a[1] = b.y * c.y;
	a[2] = b.z * c.z;
}

void	ft_p_p_reset3(double *a, t_vector t_v, t_vector t_vv)
{
	a[7] = a[0] + a[1] + a[2];
	a[9] = t_v.x + t_v.y + t_v.z;
	a[8] = t_vv.x + t_vv.y + t_vv.z;
}
