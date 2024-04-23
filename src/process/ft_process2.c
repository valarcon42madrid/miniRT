/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:30 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/29 20:59:13 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

double	*params_sphere(t_objet *obj, char *buf)
{
	obj->type = SPHERE;
	return (get_params(buf, 7));
}

double	*params_plane(t_objet *obj, char *buf)
{
	obj->type = PLANE;
	return (get_params(buf, 9));
}

double	*params_cylinder(t_objet *obj, char *buf)
{
	obj->type = CYLINDER;
	return (get_params(buf, 11));
}

int	ft_not_objet(t_objet *obj)
{
	free(obj);
	return (1);
}

int	which_obj(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && (buf[i] == ' ' || buf[i] == 9))
		i++;
	return (i);
}
