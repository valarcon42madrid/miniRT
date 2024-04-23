/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:26 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/31 23:09:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

void	ft_parser_light(t_conf *conf)
{
	conf->m_s.c_l.radian = (conf->m_s.c_l.grades * 3.14159265359) / 180;
	conf->m_s.l_l.pos.x = conf->m_s.l_l.pos.x - conf->m_s.c_l.pos.x;
	conf->m_s.l_l.pos.y = conf->m_s.l_l.pos.y - conf->m_s.c_l.pos.y;
	conf->m_s.l_l.pos.z = conf->m_s.l_l.pos.z - conf->m_s.c_l.pos.z;
}

void	ft_parser_obj_sphere(t_conf *conf, t_parser parse)
{
	parse.a = (t_sphere *)parse.aux2->objet;
	parse.a->ct.x = parse.a->ct.x - conf->m_s.c_l.pos.x;
	parse.a->ct.y = parse.a->ct.y - conf->m_s.c_l.pos.y;
	parse.a->ct.z = parse.a->ct.z - conf->m_s.c_l.pos.z;
}

void	ft_parser_obj_cylinder2(t_parser parse)
{
	double	a1;
	double	a2;
	double	a3;

	parse.c->rf.radius = parse.c->radius;
	a1 = (-1) * parse.c->dir.x;
	a2 = (-1) * parse.c->dir.y;
	a3 = (-1) * parse.c->dir.z;
	parse.c->rf.n = vec(a1, a2, a3);
	a1 = parse.c->ct.x - parse.c->dir.x * parse.c->height / 2;
	a2 = parse.c->ct.y - parse.c->dir.y * parse.c->height / 2;
	a3 = parse.c->ct.z - parse.c->dir.z * parse.c->height / 2;
	parse.c->rf.ct = vec(a1, a2, a3);
	a1 = (parse.c->rf.n.x * (1 - parse.c->rf.ct.x));
	a2 = (parse.c->rf.n.y * (1 - parse.c->rf.ct.y));
	a3 = (parse.c->rf.n.z * (1 - parse.c->rf.ct.z));
	parse.c->rf.p_e = vec(a1, a2, a3);
	a1 = (parse.c->b.n.x * (1 - parse.c->b.ct.x));
	a2 = (parse.c->b.n.y * (1 - parse.c->b.ct.y));
	a3 = (parse.c->b.n.z * (1 - parse.c->b.ct.z));
	parse.c->b.p_e = vec(a1, a2, a3);
}

void	ft_parser_obj_cylinder(t_conf *conf, t_parser parse)
{
	double	a1;
	double	a2;
	double	a3;

	parse.c = (t_cylinder *)parse.aux2->objet;
	parse.c->ct.x = parse.c->ct.x - conf->m_s.c_l.pos.x;
	parse.c->ct.y = parse.c->ct.y - conf->m_s.c_l.pos.y;
	parse.c->ct.z = parse.c->ct.z - conf->m_s.c_l.pos.z;
	parse.c->dir = normalize(parse.c->dir);
	parse.c->body.ct = parse.c->ct;
	parse.c->body.dir = parse.c->dir;
	parse.c->body.color = parse.c->color;
	parse.c->body.height = parse.c->height;
	parse.c->body.radius = parse.c->radius;
	parse.c->b.color = parse.c->color;
	parse.c->rf.color = parse.c->color;
	parse.c->b.radius = parse.c->radius;
	parse.c->b.n = parse.c->dir;
	a1 = parse.c->ct.x + parse.c->dir.x * parse.c->height / 2;
	a2 = parse.c->ct.y + parse.c->dir.y * parse.c->height / 2;
	a3 = parse.c->ct.z + parse.c->dir.z * parse.c->height / 2;
	parse.c->b.ct = vec(a1, a2, a3);
	ft_parser_obj_cylinder2(parse);
}

void	ft_parser_obj_plane(t_conf *conf, t_parser parse)
{
	double	a1;
	double	a2;
	double	a3;

	parse.b = (t_m_plane *)parse.aux2->objet;
	parse.b->pt.x = parse.b->pt.x - conf->m_s.c_l.pos.x;
	parse.b->pt.y = parse.b->pt.y - conf->m_s.c_l.pos.y;
	parse.b->pt.z = parse.b->pt.z - conf->m_s.c_l.pos.z;
	parse.b->n = normalize(parse.b->n);
	a1 = (parse.b->n.x * (1 - parse.b->pt.x));
	a2 = (parse.b->n.y * (1 - parse.b->pt.y));
	a3 = (parse.b->n.z * (1 - parse.b->pt.z));
	parse.b->p_e = vec(a1, a2, a3);
}
