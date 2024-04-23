/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:40:32 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:46:46 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	next_pos(const char *buf, t_param p)
{
	while (buf[p.pos] && (buf[p.pos] == 32 || buf[p.pos] == 9))
		p.pos++;
	return (p.pos);
}

int	next_pos2(const char *buf, t_param p)
{
	while ((buf[p.pos]) != 32
		&& (buf[p.pos]) != 9
		&& buf[p.pos] != ',' && buf[p.pos])
		p.pos++;
	return (p.pos);
}

double	*get_params2(int size, t_param p)
{
	if (size > p.l)
		return (not_param(p.param));
	return (p.param);
}

double	*get_params(const char *buf, int size)
{
	t_param	p;

	p.pos = -1;
	p.l = 0;
	p.param = (double *)ft_sec_malloc(sizeof(double) * (size));
	while (buf[++p.pos])
	{
		if ((ft_isdigit(buf[p.pos]) || buf[p.pos] == '-') && p.l < size)
		{
			p.param[p.l++] = ft_atod(&buf[p.pos]);
			p.pos = next_pos2(buf, p);
			if (size == p.l && buf[p.pos - 1] == '\0')
				break ;
			else if (size == p.l)
			{
				p.pos = next_pos(buf, p);
				if (buf[p.pos] == '\0')
					break ;
				else
					return (not_param(p.param));
			}
		}
	}
	return (get_params2(size, p));
}
