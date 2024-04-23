/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:45:00 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 11:59:32 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

double	ft_escalar_prod(t_vector a, t_vector b)
{
	double	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

double	ft_module(t_vector v)
{
	double	res;

	res = v.x * v.x + v.y * v.y + v.z * v.z;
	res = sqrt(res);
	return (res);
}

int	rgb_to_int(const t_rgb rgb)
{
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}

void	ft_put_color(t_rgb rgb, t_conf *conf)
{
	int			tmp;

	if (rgb.red > 255)
		rgb.red = 255;
	if (rgb.green > 255)
		rgb.green = 255;
	if (rgb.blue > 255)
		rgb.blue = 255;
	tmp = rgb_to_int(rgb);
	conf->my_pixel.color = tmp;
}

void	ft_pt(t_objet *obj, t_conf *conf)
{
	if (obj->type == 1)
		ft_pt_s(obj, conf, (t_sphere *)obj->objet);
	else if (obj->type == 2)
		ft_p_c(obj, conf, (t_cylinder *)obj->objet);
	else if (obj->type == 3)
		ft_p_p(obj, conf, (t_m_plane *)obj->objet);
}
