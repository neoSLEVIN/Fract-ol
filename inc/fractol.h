/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:50:13 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 02:19:21 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 500
# define MAX_ITER 100

# define ERR_EXIT 1
# define COLOR 1
# define INT 2

# define F_COL 1
# define F_GRD 2
# define F_SIZ 4
# define F_MIT 8

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# include "linuxkeys.h"
//# include "macoskeys.h"

typedef enum		e_type
{
	MANDELBROT,
	JULIA,
	CNT_OF_TYPE
}					t_type;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_dpoint
{
	double			x;
	double			y;
}					t_dpoint;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_gradient
{
	int				col_cnt;
	t_rgb			col[11];
	double			range[11];
}					t_grad;

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	t_point			size;
}					t_img;

typedef struct		s_flag
{
	t_type			type;
	int				flag;
	int				args;
	int				size;
	int				iter;
	int				col_cnt;
	t_grad			grad;
	_Bool			help;
}					t_flg;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			size;
	t_img			*img;
	t_type			type;
	t_grad			grad;
	double			zoom;
	int				iter;
	t_flg			*flg;
}					t_frac;

int					error(char *err_msg);
int					usage(char *app_name);
int					lite_usage(char *app_name, _Bool list_of_frac);
int					err_usage(char *err_msg, char *app_name, _Bool full);

t_point				set_point(int x, int y);
t_dpoint			set_dpoint(double x, double y);
t_rgb				set_rgb(int red, int green, int blue);
t_complex			set_complex(double re, double im);

void				set_grad_colors(t_frac *ftl, t_flg *flg);
t_rgb				get_grad_color(t_grad *grad, double t);

void				init_fractol(t_frac *ftl, t_flg *flg);
void				init_flg(t_flg *flg, int ac, char **av);

void				mandelbrot(t_frac *ftl);

int					is_hex(char *hex);
int					is_fractal(char *fractal);
int					red_x_button(void *param);
int					deal_key(int key, void *param);
int					mouse_click(int button, int x, int y, void *param);
void				hex_to_rgb(char *hex, t_rgb *color);
void				color(t_flg *flg, int ac, char **av, int i);
void				gradient(t_flg *flg, int ac, char **av, int i);
void				col_grad(t_flg *flg, int ac, char **av, int i);
void				plot(t_img *img, t_rgb color, t_point coord);
void				draw(t_frac *ftl);

#endif
