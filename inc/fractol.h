/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:50:13 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 22:53:31 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ZOOM 1.1
# define SPEED 0.05
# define COLOR 8
# define RANGE 0.03

# define F_COL (1 << 0)
# define F_GRD (1 << 1)
# define F_SIZ (1 << 2)
# define F_MIT (1 << 3)
# define F_ZOM (1 << 4)
# define F_REC (1 << 5)
# define F_IMC (1 << 6)
# define F_REK (1 << 7)
# define F_IMK (1 << 8)

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

//# include "linuxkeys.h"
#include <stdio.h>
# include "macoskeys.h"

typedef enum	e_type
{
	MANDELBROT,
	JULIA,
	CNT_OF_TYPE
}				t_type;

typedef struct	s_rgb
{
	short		r;
	short		g;
	short		b;
}				t_rgb;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_gradient
{
	int			col_cnt;
	t_rgb		col[9];
	double		range[9];
}				t_grad;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_point		size;
}				t_img;

typedef struct	s_mem
{
	double		zoom;
	t_complex	cam;
	int			color;
	_Bool		mouse_hook;
	_Bool		center;
	_Bool		ui;
}				t_mem;

typedef struct	s_flag
{
	t_type		type;
	int			flag;
	int			args;
	int			size;
	int			iter;
	char		*app;
	double		zoom;
	t_grad		grad;
	t_complex	cam;
	t_complex	k;
	_Bool		help;
}				t_flg;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			size;
	t_img		*img;
	t_type		type;
	t_grad		grad;
	double		zoom;
	int			iter;
	t_flg		*flg;
	t_complex	min;
	t_complex	max;
	t_complex	step;
	t_complex	cam;
	t_complex	k;
	t_mem		mem;
}				t_frac;

int				error(char *err_msg);
int				usage(char *app_name);
int				lite_usage(char *app_name, _Bool list_of_frac);
int				err_usage(char *err_msg, char *app_name, _Bool full);

t_point			set_point(int x, int y);
t_rgb			set_rgb(int red, int green, int blue);
t_complex		set_complex(double re, double im);

void			set_grad_colors(t_frac *ftl, t_flg *flg);
t_rgb			get_grad_color(t_grad *grad, double t);

void			init_fractol(t_frac *ftl, t_flg *flg);
void			init_flg(t_flg *flg, int ac, char **av);
void			init_edge(t_frac *ftl);

void			mandelbrot(t_frac *ftl);
void			julia(t_frac *ftl);

int				is_move(int key);
int				is_hex(char *hex);
int				is_fractal(char *fractal);
int				red_x_button(void *param);
int				deal_key(int key, void *param);
int				mouse_click(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			hex_to_rgb(char *hex, t_rgb *color);
void			size(t_flg *flg, int ac, char **av, int i);
void			color(t_flg *flg, int ac, char **av, int i);
void			complex(t_flg *flg, int ac, char **av, int i);
void			gradient(t_flg *flg, int ac, char **av, int i);
void			max_iter(t_flg *flg, int ac, char **av, int i);
void			col_grad(t_flg *flg, int ac, char **av, int i);
void			zoom_exp(t_flg *flg, int ac, char **av, int i);
void			zoom_std(t_frac *ftl, int key);
void			move_std(t_frac *ftl, int key);
void			zoom_camera(t_frac *ftl, int key);
void			move_camera(t_frac *ftl, int key);
void			choose_number(t_frac *ftl, int key);
void			choose_gradient(t_frac *ftl, int key);
void			plot(t_img *img, t_point coord, t_rgb color);
void			draw(t_frac *ftl);
void			print_cmd(t_frac *ftl);
void			print_double(double num);
void			print_fractol(t_type type);
void			print_info(t_frac *ftl, int i);
long long		ft_atoll(char * num, size_t len);

#endif
