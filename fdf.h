/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:39:40 by scebula           #+#    #+#             */
/*   Updated: 2016/04/28 17:36:00 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# define L 2500
# define H 1400
# define MULTI 40
# define DEPTH 7
# define ZOOM 1.10
# define OFFSET 700
# define DEGREE 2

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_mat
{
	char		type;
	float		a1;
	float		a2;
	float		a3;
	float		a4;
	float		b1;
	float		b2;
	float		b3;
	float		b4;
	float		c1;
	float		c2;
	float		c3;
	float		c4;
	float		d1;
	float		d2;
	float		d3;
	float		d4;
}				t_mat;

typedef struct	s_init
{
	void		*mlx;
	void		*win;
	t_point		***map;
	float		mod;
	float		depth;
	float		iso;
	t_point		*center;
	float		rot;
	float		z_max;
	float		z_min;
}				t_init;

typedef struct	s_draw
{
	t_point		*p;
	t_point		*delta;
	int			xincr;
	int			yincr;
	int			error;
	int			color;
}				t_draw;
t_point			***ft_from_list_to_tab(t_list **list);
t_point			***ft_parse(int fd);
t_point			*ft_new_point(float x, float y, float z);
char			ft_extract(t_point ***tab, char **split, int j);
char			ft_tab_is_digits(char **s);
char			ft_draw_line(t_init *init, t_point *a, t_point *b);
void			ft_edit_depth(t_init *init, float d);
char			ft_draw(t_init *init);
int				ft_keyboard(int keycode, void *init);
int				ft_mouse(int button, int x, int y, void *param);
t_init			*ft_init(t_point ***p);
void			ft_rotate(t_init *init, float x, float y, double deg);
t_mat			*ft_mat_translate(float x, float y, float z);
char			ft_transformation(t_init *i, t_mat *m);
t_mat			*ft_mat_scale(float x, float y, float z);
void			ft_cross(t_init *init);
float			ft_find_zmax(t_init *init);
t_draw			*ft_init_drawing(t_point *a, t_point *b);
void			ft_draw_case_1(t_draw *d, t_init *init);
void			ft_draw_case_2(t_draw *d, t_init *init);
void			grille(t_init *init);
float			ft_find_zmin(t_init *init);
char			ft_contain_more(char *s);
void			ft_free_tabs(t_point ***tab, char **split);
void			ft_close(t_init *i);
void			ft_zoom(t_init *i, int x, int y, float z);
void			ft_translation_management(int keycode, t_init *i);
void			*ft_error(t_point ***tab, char **split, int j);
size_t			ft_tablen_tpoint(t_point **p);
void			ft_legend(t_init *i);
#endif
