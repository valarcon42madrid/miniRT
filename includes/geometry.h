/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:31 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/11 10:46:08 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <stdbool.h>
# include "../src/get_next_line/get_next_line.h"
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <math.h>

typedef struct s_img
{
	void			*i;
	int				b;
	int				s;
	int				e;
	unsigned char	*d;
}				t_img;

typedef struct s_s
{
	void	*mlx;
	void	*mlx_win;
}				t_s;

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}				t_rgb;

typedef struct s_v
{
	double	x;
	double	y;
	double	z;
}				t_v;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	t_v		o;
}				t_vector;

typedef struct s_light
{
	t_vector	pos;
	double		radius;
	t_rgb		color;
}				t_light;

typedef struct s_camera
{
	t_vector	view;
	t_vector	h;
	t_vector	w;
	t_vector	pos;
	double		grades;
	double		radian;
}				t_camera;
typedef struct s_scene
{
	t_light		l_l;
	t_list		*obj_lst;
	t_camera	c_l;
	t_light		ambient;
}				t_scene;

typedef struct s_screen
{
	t_vector	pos;
	t_vector	x_axis;
	t_vector	y_axis;
	int			h;
	int			w;
}				t_screen;

typedef struct s_flag
{
	int	save;
	int	r;
	int	c;
	int	error;
	int	no_f;
}				t_flag;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*img_ptr;

	char		*window_title;
	t_vector	window_size;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;

}				t_pixel;
typedef struct s_conf
{
	t_scene		m_s;
	t_camera	my_camera;
	t_mlx		mlx;
	t_flag		flag;
	t_pixel		my_pixel;
}				t_conf;

typedef enum e_geometry{
	NONE,	
	SPHERE,	
	CYLINDER,	
	PLANE
}				t_geometry;

typedef struct s_sphere
{
	t_vector	ct;
	t_vector	inter;
	double		radius;
	t_rgb		color;
}				t_sphere;

typedef struct s_circle
{
	t_vector	ct;
	double		radius;
	t_vector	n;
	t_rgb		color;
	t_vector	p_e;
}				t_circle;

typedef struct s_tube
{
	t_vector	ct;
	t_vector	dir;
	double		radius;
	double		height;
	t_rgb		color;
}				t_tube;

typedef struct s_cylinder
{
	t_vector	dir;
	t_vector	ct;
	t_vector	inter;
	double		radius;
	double		height;
	t_rgb		color;
	t_circle	b;
	t_circle	rf;
	t_tube		body;
}				t_cylinder;

typedef struct s_m_plane
{
	t_vector	pt;
	t_vector	n;
	t_vector	p_e;
	t_vector	inter;
	t_rgb		color;
}				t_m_plane;

typedef struct s_objet
{
	void		*objet;
	t_geometry	type;
}				t_objet;

typedef struct s_parser
{
	char		*s;
	char		**lines;
	t_list		*x;
	t_objet		*aux2;
	t_sphere	*a;
	t_cylinder	*c;
	t_m_plane	*b;
	double		xp;
	double		yp;
	double		zp;
}				t_parser;

typedef struct s_m_i
{
	int				(*tab)[1080][1];
	t_objet			*obj;
	int				s;
	double			g;
	double			p;
	t_vector		v;
	double			aux;
	double			ay;
	double			ax;
	double			t;
}				t_m_i;
typedef struct s_param
{
	double	*param;
	int		pos;
	int		l;
}				t_param;

typedef struct s_process
{
	int		i;
	int		x;
	int		error;
	t_conf	*conf;
}				t_process;

typedef struct s_coords_c
{
	t_m_plane	plane;
	t_vector	ptb;
	t_vector	ptrf;
	t_vector	result;
	t_vector	aux;
	t_vector	aux2;
	t_vector	normvd;
	t_vector	ptside;
	t_vector	ptospecial;
	t_vector	ptospecial2;
	t_vector	specialcent;
	t_vector	pntexact;
	int			whichresult;
	double		a[12];
}				t_coords_c;

typedef struct s_destroy
{
	t_s		*window;
	t_img	*m;
	t_conf	*conf;
}				t_destroy;

void		ft_pt(t_objet *obj, t_conf *conf);
int			rgb_to_int(const t_rgb rgb);
t_vector	ft_coords_pt_plane222(t_m_plane *plane, t_vector line, int z);
int			ft_impact(t_conf *conf, t_vector v);
t_objet		*ft_closet(t_conf *conf, t_vector v);
double		dot_prod(t_vector u, t_vector v);
int			ft_vector_to_plane(t_vector v, t_m_plane *objet);
int			ft_vector_to_cylinder(t_vector v, t_cylinder *objet);
int			ft_vector_to_sphere(t_vector v, t_sphere *objet);
int			ft_dist_pt_plane(t_vector plane, int extra, t_vector pt);
t_vector	ft_coords_pt_cylinder(t_cylinder *obj, t_vector v);
t_vector	vec(double x, double y, double z);
t_vector	ft_coords_pt_plane(t_m_plane *plane, t_vector line);
double		ft_module(t_vector v);
t_vector	ft_coords_pt_sphere(t_vector v, t_sphere *objet);
char		*ft_data(char *argv[]);
int			ft_process_range_ambient_light(double *nb);
int			ft_process_range_camara(double *nb);
int			ft_process_range_light(double *nb);
int			ft_process_range_sphere(double *nb);
int			ft_process_range_flat(double *nb);
int			ft_process_range_cylinder(double *nb);
int			ft_strncmp_rev(const char *s1, const char *s2, size_t n);
t_conf		ft_process(char **buff);
double		*get_params(const char *buf, int size);
t_rgb		ft_color(double r, double g, double b);
t_vector	vec(double x, double y, double z);
long double	ft_atod(const char *str);
void		ft_objetinit(double *paramsin, t_objet *obj);
void		camera(char *buf, t_conf *conf);
int			ft_mcd(int a, int b);
t_vector	normalize(t_vector u);
t_vector	add(t_vector u, t_vector v);
t_vector	provec(t_vector u, t_vector v);
int			ft_objet(char *buf, t_conf *conf);
void		ft_mlx_init(t_conf *conf);
double		dot_prod(t_vector u, t_vector v);
double		magnitude(t_vector u);
t_vector	prod(t_vector u, double lamda);
t_vector	add(t_vector u, t_vector v);
t_vector	provec(t_vector u, t_vector v);
t_vector	normalize(t_vector u);
t_sphere	*sphere_init(double *param);
t_cylinder	*cylinder_init(double *param);
t_m_plane	*plane_init(double *param);
void		ft_objetinit(double *paramsin, t_objet *obj);
void		ft_parser_obj_plane(t_conf *conf, t_parser parse);
void		ft_parser_obj_cylinder(t_conf *conf, t_parser parse);
void		ft_parser_obj_cylinder2(t_parser parse);
void		ft_parser_obj_sphere(t_conf *conf, t_parser parse);
void		ft_parser_light(t_conf *conf);
void		ft_parser_objs(t_conf *conf, t_parser parse);
t_vector	ft_vectors_camara(t_vector a1, int nb);
void		ft_parser_camara(t_conf *conf, t_parser parse);
int			ft_parser(char **argv, t_conf *conf);
int			ft_camera(char *buff, t_conf *conf);
int			ft_light(char *buf, t_conf *conf);
int			ft_objet(char *buf, t_conf *conf);
int			ft_not_objet2(double *param, t_objet *obj);
void		ft_objet2(t_conf *conf, double *param, t_objet	*obj);
int			which_obj(char *buf);
int			ft_not_objet(t_objet *obj);
double		*params_cylinder(t_objet *obj, char *buf);
double		*params_plane(t_objet *obj, char *buf);
double		*params_sphere(t_objet *obj, char *buf);
void		ft_obj(t_m_i ig, t_conf *conf);
void		ft_not_pixel_obj(t_m_i ig, t_conf *conf);
double		*not_param(double *param);
double		ft_proyectvector(t_vector a, t_vector nor);
int			ft_ambient(char *buff, t_scene *s_scene);
t_vector	ft_init_vector(t_m_i ig, t_conf *conf);
t_v			ft_init_zero(void);
t_vector	ft_second_coords_pt_sphere(t_vector v, t_sphere *objet);
void		ft_c_reset(double *a, t_cylinder *obj, t_vector b);
void		ft_c_reset2(double *a, t_vector vision, t_vector c, t_vector b);
void		ft_c_reset3(double *a, t_vector b, t_vector c);
void		ft_c_reset3_2(double *a, t_vector b, t_vector c);
void		ft_c_reset4(double *a, t_vector b, t_vector c, double x);
void		ft_c_reset5(double *a, t_vector b, t_vector c);
void		ft_c_reset6(double *a, t_vector b, t_vector c);
void		ft_c_reset7(double *a, t_vector b, t_vector c, t_vector d);
void		ft_c_reset8(double *a);
double		ft_dist_pt_recta(t_vector pt, t_vector vect, t_vector precta);
t_vector	ft_coords_pt_plane22(t_m_plane *plane, t_vector line);
void		ft_cylinder2(t_cylinder *obj, t_vector vision, t_coords_c *c);
void		ft_cylinder3(t_cylinder *obj, t_vector vision, t_coords_c *c);
t_vector	ft_cylinder4(t_cylinder *obj, t_vector vision, t_coords_c *c);
t_vector	ft_cylinder5(t_cylinder *obj, t_vector vision, t_coords_c *c);
void		ft_cylinder6(t_cylinder *obj, t_vector vision, t_coords_c *c);
void		ft_cylinder7(t_cylinder *obj, t_coords_c *c);
void		ft_cylinder8(t_cylinder *obj, t_vector vision, t_coords_c *c);
t_vector	ft_cylinder9(t_cylinder *obj, t_vector vision, t_coords_c *c);
int			ft_light_intersec(t_objet *obj, t_conf *conf);
void		ft_pt_s(t_objet *obj, t_conf *conf, t_sphere *aux);
void		ft_p_p(t_objet *obj, t_conf *conf, t_m_plane *aux2);
void		ft_p_c(t_objet *obj, t_conf *conf, t_cylinder *aux3);
void		ft_put_color(t_rgb rgb, t_conf *conf);
double		ft_module(t_vector v);
double		ft_escalar_prod(t_vector a, t_vector b);
int			ft_dist_pt_plane(t_vector plane, int extra, t_vector pt);
void		ft_p_c_reset(double *a, t_conf *conf, t_cylinder *aux3, t_vector t);
void		ft_p_c_reset2(double *a);
void		ft_p_c_c_b(double *a, t_conf *conf, t_cylinder *aux3);
void		ft_p_c_i_b(double *a, t_objet *obj, t_conf *conf, t_cylinder *aux3);
void		ft_p_c_reset3(double *a, t_cylinder *aux3);
void		ft_p_c_reset4(double *a, t_cylinder *aux3, int dist);
void		ft_p_c_reset5(double *a, t_cylinder *aux3, t_vector t_v);
void		ft_p_p_reset(double *a, t_vector aux2, t_vector light);
void		ft_p_p_reset2(double *a, t_vector b, t_vector c);
void		ft_p_p_reset3(double *a, t_vector t_v, t_vector t_vv);
void		ft_darkside_reset(double *a, t_vector lightpos, t_vector campos);
void		ft_darkside_reset2(double *a, t_vector n, t_vector c, t_vector i);
void		ft_darkside_reset3(double *a, t_vector normplane,
				t_vector lightpos);
int			ft_dark_sp(t_vector	inter, t_vector	l,
				t_vector	campos, t_sphere *sp);
void		ft_pt_s_reset(double *a, t_vector b, t_vector c);
int			ft_light_sphere_confirm(t_objet *obj, t_objet *res);
t_vector	ft_light_sphere(t_objet *obj, t_conf *conf);
t_objet		*ft_light_s_i(t_vector aux, t_objet *obj2,
				double *mod2, t_objet *res);
int			ft_light_plane_confirm(t_objet *obj, t_objet *res);
t_vector	ft_light_plane(t_objet *obj, t_conf *conf);
t_objet		*ft_light_p_i(t_vector aux, t_objet *obj2,
				double *mod2, t_objet *res);
int			ft_light_cylinder_confirm(t_objet *obj, t_objet *res);
t_vector	ft_light_cylinder(t_objet *obj, t_conf *conf);
t_objet		*ft_light_c_i(t_vector aux, t_objet *obj2,
				double *mod2, t_objet *res);
void		ft_free_struct(t_conf *conf);
void		ft_all_black(t_conf *conf);
int			ft_error_free_return(t_conf *conf);
int			ft_inside_cy(t_cylinder *c);
void		*ft_sec_malloc(int size);
int			key_hook(int keycode, t_destroy *dest);
int			ft_exit_hook(t_destroy *dest);
int			ft_inplane(t_m_plane *p);
#endif
