/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:31:39 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:47:57 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_objet2(t_conf *conf, double *param, t_objet	*obj)
{
	ft_objetinit(param, obj);
	free(param);
	ft_lstadd_front(&(conf->m_s.obj_lst), ft_lstnew(obj));
}

int	ft_not_objet2(double *param, t_objet *obj)
{
	free(param);
	return (ft_not_objet(obj));
}

int	ft_objet(char *buf, t_conf *conf)
{
	t_objet	*obj;
	double	*param;
	int		i;

	i = which_obj(buf);
	obj = ft_sec_malloc(sizeof(t_objet));
	if (buf[i] && buf[i + 1] && buf[i] == 's' && buf[i + 1] == 'p')
		param = params_sphere(obj, buf);
	else if (buf[i] && buf[i + 1] && buf[i] == 'p' && buf[i + 1] == 'l')
		param = params_plane(obj, buf);
	else if (buf[i] && buf[i + 1] && buf[i] == 'c' && buf[i + 1] == 'y')
		param = params_cylinder(obj, buf);
	else
		return (ft_not_objet(obj));
	if (param == NULL)
		return (1);
	if ((obj->type == SPHERE && ft_process_range_sphere(param) == 1)
		|| (obj->type == PLANE && ft_process_range_flat(param) == 1)
		|| (obj->type == CYLINDER && ft_process_range_cylinder(param) == 1))
	{
		return (ft_not_objet2(param, obj));
	}
	else
		ft_objet2(conf, param, obj);
	return (0);
}

int	ft_light(char *buf, t_conf *conf)
{
	double	*param;

	param = get_params(buf, 4);
	if (param == NULL)
		return (1);
	if (ft_process_range_light(param) == 1)
	{
		free(param);
		return (1);
	}
	else if (conf->m_s.l_l.radius == 0
		&& conf->m_s.l_l.pos.x == 0
		&& conf->m_s.l_l.pos.y == 0
		&& conf->m_s.l_l.pos.z == 0)
	{
		conf->m_s.l_l.pos = vec(param[0], param[1], param[2]);
		conf->m_s.l_l.radius = param[3] * 10;
		free(param);
		return (0);
	}
	return (1);
}

int	ft_camera(char *buff, t_conf *conf)
{
	double	*params;

	params = get_params(buff, 7);
	if (params == NULL)
		return (1);
	if (ft_process_range_camara(params) == 1)
		return (1);
	else if (conf->m_s.c_l.pos.x == 0
		&& conf->m_s.c_l.pos.y == 0
		&& conf->m_s.c_l.pos.z == 0)
	{
		camera(buff, conf);
		return (0);
	}
	return (2);
}
