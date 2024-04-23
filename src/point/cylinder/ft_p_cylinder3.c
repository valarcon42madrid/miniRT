/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_cylinder3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:49:15 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/01 01:49:25 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/geometry.h"

void	ft_p_c_reset3(double *a, t_cylinder *aux3)
{
	a[0] = aux3->b.p_e.x * aux3->b.ct.x;
	a[1] = aux3->b.p_e.y * aux3->b.ct.y;
	a[2] = aux3->b.p_e.z * aux3->b.ct.z;
}

void	ft_p_c_reset4(double *a, t_cylinder *aux3, int dist)
{
	a[0] = aux3->inter.x + aux3->body.dir.x * dist;
	a[1] = aux3->inter.y + aux3->body.dir.y * dist;
	a[2] = aux3->inter.z + aux3->body.dir.z * dist;
}

void	ft_p_c_reset5(double *a, t_cylinder *aux3, t_vector t_v)
{
	a[0] = t_v.x - aux3->body.ct.x;
	a[1] = t_v.y - aux3->body.ct.y;
	a[2] = t_v.z - aux3->body.ct.z;
}
