/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:44:32 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/29 20:58:45 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	camera(char *buf, t_conf *conf)
{
	double	*param;

	param = get_params(buf, 7);
	conf->m_s.c_l.pos = vec(param[0], param[1], param[2]);
	conf->m_s.c_l.view = vec(param[3], param[4], param[5]);
	conf->m_s.c_l.grades = param[6];
}
