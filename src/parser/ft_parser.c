/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:54:27 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/10 13:45:44 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_parser_objs(t_conf *conf, t_parser parse)
{
	parse.x = conf->m_s.obj_lst;
	while (parse.x->content)
	{
		parse.aux2 = (t_objet *)parse.x->content;
		if (parse.aux2->type == 1)
			ft_parser_obj_sphere(conf, parse);
		else if (parse.aux2->type == 2)
			ft_parser_obj_cylinder(conf, parse);
		else if (parse.aux2->type == 3)
			ft_parser_obj_plane(conf, parse);
		parse.x = parse.x->next;
	}
}

t_vector	ft_vectors_camara(t_vector a1, int nb)
{
	t_vector	b1;

	if (nb == 0)
		b1 = vec(0, 0, 1);
	if (nb == 1)
		b1 = vec(0, 1, 0);
	if (nb == 2)
		b1 = vec(1, 0, 0);
	return (normalize(provec(a1, b1)));
}

void	ft_parser_camara(t_conf *conf, t_parser parse)
{
	conf->m_s.c_l.pos.x = 0;
	conf->m_s.c_l.pos.y = 0;
	conf->m_s.c_l.pos.z = 0;
	conf->m_s.c_l.view = normalize(conf->m_s.c_l.view);
	parse.xp = conf->m_s.c_l.view.x;
	parse.yp = conf->m_s.c_l.view.y;
	parse.zp = conf->m_s.c_l.view.z;
	if (parse.xp < 0)
		parse.xp *= (-1);
	if (parse.yp < 0)
		parse.yp *= (-1);
	if (parse.zp < 0)
		parse.zp *= (-1);
	if (parse.zp <= parse.yp && parse.zp <= parse.xp)
		conf->m_s.c_l.w = ft_vectors_camara(conf->m_s.c_l.view, 0);
	else if (parse.yp <= parse.xp && parse.yp <= parse.zp)
		conf->m_s.c_l.w = ft_vectors_camara(conf->m_s.c_l.view, 1);
	else
		conf->m_s.c_l.w = ft_vectors_camara(conf->m_s.c_l.view, 2);
	conf->m_s.c_l.w = normalize(provec(conf->m_s.c_l.view, conf->m_s.c_l.w));
	conf->m_s.c_l.h = normalize(provec(conf->m_s.c_l.view, conf->m_s.c_l.w));
}

int	ft_inside(t_conf *conf)
{
	t_list		*auxobj;
	t_objet		*o;
	t_sphere	*s;

	auxobj = conf->m_s.obj_lst;
	while (auxobj->content)
	{
		o = (t_objet *)auxobj->content;
		if (o->type == 1)
		{
			s = (t_sphere *)o->objet;
			if (ft_module(s->ct) == s->radius)
				return (2);
		}
		if (o->type == 2 && ft_inside_cy((t_cylinder *)o->objet) == 1)
		{
			return (2);
		}
		if (o->type == 3 && ft_inplane((t_m_plane *)o->objet) == 1)
		{
			return (2);
		}
		auxobj = auxobj->next;
	}
	return (0);
}

int	ft_parser(char **argv, t_conf *conf)
{
	int			x;
	t_parser	parse;

	parse.s = ft_data(argv);
	if (!parse.s)
	{
		perror("Error in open the file");
		return (1);
	}
	parse.lines = ft_split(parse.s, '\n');
	free(parse.s);
	*conf = ft_process(parse.lines);
	x = 0;
	while (parse.lines[x])
		free(parse.lines[x++]);
	free(parse.lines);
	if (conf->flag.error != 0)
	{
		return (ft_error_free_return(conf));
	}
	ft_parser_light(conf);
	ft_parser_objs(conf, parse);
	ft_parser_camara(conf, parse);
	return (ft_inside(conf));
}
