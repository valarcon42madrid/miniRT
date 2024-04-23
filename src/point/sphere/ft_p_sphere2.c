/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_sphere2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:53:06 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:53:23 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

void	ft_darkside_reset(double *a, t_vector lightpos, t_vector campos)
{
	a[0] = lightpos.x - campos.x;
	a[1] = lightpos.y - campos.y;
	a[2] = lightpos.z - campos.z;
}

void	ft_darkside_reset2(double *a, t_vector n, t_vector c, t_vector i)
{
	a[0] = n.x * c.x;
	a[1] = n.y * c.y;
	a[2] = n.z * c.z;
	a[3] = n.x * i.x;
	a[4] = n.y * i.y;
	a[5] = n.z * i.z;
	a[9] = a[0] + a[1] + a[2] - (a[3] + a[4] + a[5]);
}

void	ft_darkside_reset3(double *a, t_vector normplane, t_vector lightpos)
{
	a[6] = normplane.x * lightpos.x;
	a[7] = normplane.y * lightpos.y;
	a[8] = normplane.z * lightpos.z;
}
