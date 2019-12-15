/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:50:13 by cschoen           #+#    #+#             */
/*   Updated: 2019/12/16 00:14:03 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ZOOM 1.1
# define SPEED 0.05
# define COLOR 8
# define EPS 1e-4
# define SCREEN 500
# define N_ITER 40
# define T_CNT 50
# define PIX_CNT 5000

# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include "flag.h"
# include "err_usg.h"
/*
** __linux__, __linux, linux are pre-defined macroses for linux
** __APPLE__, __MACH__ are pre-defined macroses for MACOS X
*/
# if defined (__linux__) || defined (__linux) || defined (linux)
#  include "linuxkeys.h"
# elif defined (__APPLE__) || defined (__MACH__)
#  include "macoskeys.h"
# endif

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			size;
	int			y_lines;
	int			t_max;
	t_point		pos;
	t_type		type;
}				t_img;

typedef struct	s_mem
{
	double		zoom;
	t_complex	cam;
	int			color;
	_Bool		mouse_hook;
	_Bool		mouse_zoom;
	_Bool		no_hook;
	_Bool		center;
	_Bool		side;
	_Bool		ui;
}				t_mem;

typedef struct	s_root
{
	int			cnt;
	t_complex	damping;
	t_complex	roots[5];
	t_rgb		cols[5];
}				t_root;

typedef struct	s_newton
{
	t_complex	c1;
	t_complex	c2;
	t_point		pos;
	int			ftl_id;
}				t_newton;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			size;
	int			iter;
	int			pow;
	t_flg		*flg;
	t_mem		mem;
	t_img		*img;
	t_img		*black_img;
	t_img		*side_imgs;
	t_type		type;
	t_grad		grad;
	t_root		root;
	double		zoom;
	t_complex	*cp;
	t_complex	min;
	t_complex	max;
	t_complex	cam;
	t_complex	step;
	t_complex	k;
}				t_frac;

typedef struct	s_thread
{
	t_frac		*ftl;
	int			ftl_id;
	int			img_id;
	int			y_min;
	int			y_max;
}				t_thread;

void			init_flg(t_flg *flg, int ac, char **av);
void			init_fractol(t_frac *ftl, t_flg *flg);
void			init_root_pos(t_root *root, int cnt);
void			set_grad_colors(t_frac *ftl, t_flg *flg);

void			new_image(t_frac *ftl, int size);
void			new_black_image(t_frac *ftl);
void			new_side_image(t_frac *ftl, int size);

void			mandelbrot(t_frac *ftl, int ftl_id, t_point limits, t_img *img);
void			mandelbar(t_frac *ftl, int ftl_id, t_point limits, t_img *img);
void			celtic(t_frac *ftl, int ftl_id, t_point limits, t_img *img);
void			julia(t_frac *ftl, int ftl_id, t_point limits, t_img *img);
void			newton(t_frac *ftl, int ftl_id, t_point limits, t_img *img);
void			burning_ship(t_frac *ftl, int ftl_id, t_point limits,
							t_img *img);

int				is_move(int key);
int				is_hex(char *hex);
int				no_hook(void *param);
int				deal_key(int key, void *param);
void			deal_key2(t_frac *ftl, int key);
int				mouse_click(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			zoom_std(t_frac *ftl, int key);
void			move_std(t_frac *ftl, int key);
void			zoom_camera(t_frac *ftl, int key);
void			move_camera(t_frac *ftl, int key);
void			draw(t_frac *ftl, int key);
void			draw_ui(t_frac *ftl);
void			draw_str(t_frac *ftl, int x, int *y, char *str);
void			draw_fractol(t_frac *ftl, t_img *img, int img_id);
void			draw_info(t_frac *ftl, int *y, char *str, char *temp);
void			draw_current(t_frac *ftl, int *y, char *str, char *temp);
void			draw_complex(t_frac *ftl, t_complex *complex, int x, int *y);
void			print_cmd(t_frac *ftl);
void			print_double(double num);
void			print_fractol(t_type type);
void			print_itoa16(short num, _Bool full);
void			plot(t_img *img, t_point *coord, t_rgb *color);
long long		ft_atoll(char *num, size_t len);
char			*ft_dtoa(double num);

#endif
