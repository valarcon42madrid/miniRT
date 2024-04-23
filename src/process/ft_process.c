/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:38:08 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:47:19 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_process_conf(t_conf *conf)
{
	conf->m_s.l_l.radius = 0;
	conf->m_s.l_l.pos.x = 0;
	conf->m_s.l_l.pos.y = 0;
	conf->m_s.l_l.pos.z = 0;
	conf->m_s.c_l.pos.x = 0;
	conf->m_s.c_l.pos.y = 0;
	conf->m_s.c_l.pos.z = 0;
	conf->m_s.obj_lst = ft_sec_malloc(sizeof(t_list));
	conf->m_s.obj_lst->content = NULL;
	conf->m_s.obj_lst->next = NULL;
}

int	ft_next_letter(char	**buff, int i)
{
	int	x;

	x = 0;
	while (buff[i][x] && (buff[i][x] == ' ' || buff[i][x] == 9))
		x++;
	return (x);
}

t_conf	ft_flag_error(t_process p)
{
	p.conf->flag.error = 2;
	return (*p.conf);
}

t_conf	ft_process2(t_process p)
{
	if (p.error != 0)
	{
		p.conf->flag.error = p.error;
		return (*p.conf);
	}
	return (*p.conf);
}

t_conf	ft_process(char **buff)
{
	t_process	p;

	p.conf = ft_sec_malloc(sizeof(t_conf));
	ft_process_conf(p.conf);
	p.x = 0;
	p.i = -1;
	p.error = 0;
	while (buff[++p.i] && p.error == 0)
	{
		p.x = ft_next_letter(buff, p.i);
		if (buff[p.i][p.x] && buff[p.i][p.x] == 'A')
			p.error = ft_ambient(buff[p.i], &p.conf->m_s);
		else if (buff[p.i][p.x] && buff[p.i][p.x] == 'C')
			p.error = ft_camera(buff[p.i], p.conf);
		else if (buff[p.i][p.x] && buff[p.i][p.x] == 'L')
			p.error = ft_light(buff[p.i], p.conf);
		else if (buff[p.i][p.x] && buff[p.i][p.x + 1]
			&& ((buff[p.i][p.x] == 's' && buff[p.i][p.x + 1] == 'p')
			|| (buff[p.i][p.x] == 'p' && buff[p.i][p.x + 1] == 'l')
			|| (buff[p.i][p.x] == 'c' && buff[p.i][p.x + 1] == 'y')))
			p.error = ft_objet(buff[p.i], p.conf);
		else if (buff[p.i][p.x])
			return (ft_flag_error(p));
	}
	return (ft_process2(p));
}
