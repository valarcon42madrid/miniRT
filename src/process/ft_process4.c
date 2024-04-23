/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:51:06 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/29 20:59:20 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	ft_ambient(char *buff, t_scene *s_scene)
{
	double	*params;

	params = get_params(buff, 4);
	if (params == NULL)
		return (1);
	if (ft_process_range_ambient_light(params) == 1)
	{
		free(params);
		return (1);
	}
	else
	{
		s_scene->ambient.radius = params[0];
		s_scene->ambient.color = ft_color(params[1], params[2], params[3]);
	}
	free(params);
	return (0);
}
