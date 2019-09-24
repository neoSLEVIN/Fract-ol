/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:22:49 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/24 21:06:34 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define F_COL (1 << 0)
# define F_GRD (1 << 1)
# define F_SIZ (1 << 2)
# define F_MIT (1 << 3)
# define F_ZOM (1 << 4)
# define F_REC (1 << 5)
# define F_IMC (1 << 6)
# define F_REK (1 << 7)
# define F_IMK (1 << 8)
# define F_POW (1 << 9)

# include "grad.h"
# include "complex.h"
# include "err_usg.h"
# include "../libft/libft.h"

typedef enum	e_type
{
	MANDELBROT,
	BURNING_SHIP,
	MANDELBAR,
	CELTIC,
	JULIA,
	NEWTON,
	CNT_OF_TYPES
}				t_type;

typedef struct	s_flag
{
	t_type		type;
	char		*app;
	int			flag;
	int			args;
	int			size;
	int			iter;
	int			pow;
	double		zoom;
	t_grad		grad;
	t_complex	cam;
	t_complex	k;
	_Bool		help;
}				t_flg;

void			valid_stdin(t_flg *flg, int ac, char **av);
void			size(t_flg *flg, int ac, char **av, int i);
void			color(t_flg *flg, int ac, char **av, int i);
void			complex(t_flg *flg, int ac, char **av, int i);
void			gradient(t_flg *flg, int ac, char **av, int i);
void			max_iter(t_flg *flg, int ac, char **av, int i);
void			col_grad(t_flg *flg, int ac, char **av, int i);
void			root_cnt(t_flg *flg, int ac, char **av, int i);
void			zoom_exp(t_flg *flg, int ac, char **av, int i);

#endif
