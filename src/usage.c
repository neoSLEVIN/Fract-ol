/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:35:54 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/21 22:16:06 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_usg.h"

void		list_of_fractol(char *app_name)
{
	ft_putstr("Usage: ");
	ft_putstr(app_name);
	ft_putendl(" [OPTION ARGS]... FRACTOL\n");
	ft_putendl("FRACTOL argument is case-INsensitive.");
	ft_putendl("List of fractals:\n  Mandelbrot\n  Julia\n  Burning_Ship");
	ft_putendl("  Mandelbar\n  Celtic\n  Newton\n");
}

static void	usage4(char *app_name)
{
	ft_putendl("-X flag is color and gradient flag at the same time.\n");
	ft_putstr("Options can be written out of order, but arguments must ");
	ft_putendl("follow their options.");
	ft_putendl("FRACTOL should be the last parameter.\n");
	ft_putendl("Recommendation from the author:");
	ft_putstr("  Try:\n    ");
	ft_putstr(app_name);
	ft_putstr(" -p 5 -X 9 0x32d2ba 809 0x060131 649 0x200737 519 0xf890bf 479");
	ft_putstr(" 0x775fc8 470 0xb9de91 460 0x0552f2 450 0x9b8c33 0x8c2373 -m");
	ft_putstr(" 180 -Re 0.000294206994828 -Im 1.183454787247950 -z 14 ");
	ft_putstr("Burning_Ship\n\n    ");
	ft_putstr(app_name);
	ft_putstr(" -X 9 0x0a221a 900 0x330c33 800 0x44449b 700 0x1d1d1d 600 ");
	ft_putstr("0x363636 500 0x47af77 400 0x6858a8 300 0x070807 0x0e110e ");
	ft_putstr("-m 140 -Re 0.025999529691095 -Im -0.834258872948030 ");
	ft_putstr("Julia\n\n    ");
	ft_putstr(app_name);
	ft_putstr(" -p 5 -X 9 0x0e190e 900 0x0a221a 800 0x330c33 700 0x44449b 600");
	ft_putstr(" 0x1d1d1d 500 0x363636 400 0x47af77 300 0x6858a8 0x070807 ");
	ft_putstr("-m 140 -Re -0.964484040910812 -Im 0.636821781468433 -z 7 ");
	ft_putendl("Mandelbar");
}

static void	usage3(char *app_name)
{
	ft_putendl("  -k-Re, -k-Im\t\tChange the start factor for Julia's set.");
	ft_putendl("\t\t\tARG(1): float in range [-10...10] not inclusive. Length");
	ft_putendl("\t\t\t  of the value after point is not more than fifteen.");
	ft_putendl("\t\t\tExample: -k-Re -0.79 or/and -k-Im 0.15\n");
	ft_putendl("      --help\t\tDisplay this help and exit.\n");
	ft_putstr("In the examples shown standard values that are set without ");
	ft_putendl("options.\n");
	ft_putstr("Gradient values are set for colors from 1000(max iteration) to");
	ft_putstr(" 0(min iteration)\nin descending order. For simplicity, the ");
	ft_putendl("first and last values do not need to be");
	ft_putendl("entered in the options.\n");
	ft_putendl("HEX standard for input:");
	ft_putendl("Length:|      Three ways\t      Two ways\t\t      One way");
	ft_putstr("-------| ");
	ft_putendl("___________________\t___________________\t___________________");
	ft_putstr("Six    | ");
	ft_putendl("|0x| ff | ff | ff |\t|0x| ff | 88 | aa |\t|0x| f7 | 64 | 3d |");
	ft_putstr("-------| ");
	ft_putendl("|=================|\t|=================|\t|=================|");
	ft_putstr("Three  | ");
	ft_putendl("|0x| f  | f  | f  |\t|0x| f  | 8  | a  |");
	ft_putendl("-------| |=================|\t|=================|");
	ft_putstr("One    | ");
	ft_putendl("|0x|      f       |\n");
	usage4(app_name);
}

static void	usage2(char *app_name)
{
	ft_putstr("  -X, --col-grad\tChange the custom colors and the values of ");
	ft_putendl("the gradient.");
	ft_putendl("\t\t\tMAIN ARG(1): integer in range [2...9] inclusive. Must");
	ft_putendl("\t\t\t  be first among the arguments of -X flag.");
	ft_putstr("\t\t\tSIDE ARGS(X): list of HEX colors that starts with 0x and");
	ft_putendl("\n\t\t\t  integers in range [999...1] inclusive in descending");
	ft_putendl("\t\t\t  order. X is the sum of the color and gradient");
	ft_putendl("\t\t\t  arguments reduced by 2. This means that COUNT of");
	ft_putendl("\t\t\t  color's arguments is equal to value of the main");
	ft_putendl("\t\t\t  argument, COUNT of gradient's arguments is equal to");
	ft_putendl("\t\t\t  value of the main argument minus two.");
	ft_putendl("\t\t\tHint: Colors and gradient values can be intertwined.");
	ft_putendl("\t\t\tExample: --col-grad 3  0x0  50 0x8  0xf\n");
	ft_putendl("  -z, --zoom-exp\tChange the initial zoom value.");
	ft_putendl("\t\t\tARG(1): integer in range [0...99] inclusive. Zoom value");
	ft_putendl("\t\t\t  is 10 to the power of this value.");
	ft_putendl("\t\t\tExample: --zoom-exp 0\n");
	ft_putendl("  -Re, -Im\t\tChange the start value of central point.");
	ft_putendl("\t\t\tARG(1): float in range [-10...10] not inclusive. Length");
	ft_putendl("\t\t\t  of the value after the point is not more than six.");
	ft_putendl("\t\t\tExample: -Re 0.0 or/and -Im 0\n");
	usage3(app_name);
}

int			usage(char *app_name)
{
	list_of_fractol(app_name);
	ft_putendl("Arguments to options are mandatory.");
	ft_putendl("  -c, --color\t\tChange the custom colors.");
	ft_putendl("\t\t\tARGS(3): HEX colors that starts with 0x.");
	ft_putendl("\t\t\tHint: 0x7 is same as 0x777 and same as 0x777777");
	ft_putendl("\t\t\tExample: --color 0x0 0x888 0xffffff\n");
	ft_putendl("  -g, --gradient\tChange the value of the gradient.");
	ft_putendl("\t\t\tARG(1): integer in range [999...1] inclusive.");
	ft_putendl("\t\t\tExample: --gradient 500\n");
	ft_putendl("  -m, --max-iter\tChange the value of the max iterations.");
	ft_putendl("\t\t\tARG(1): integer in range [20...2000] inclusive.");
	ft_putendl("\t\t\tExample: --max-iter 100\n");
	ft_putendl("  -p, --power\t\tChange the value of the z-power.");
	ft_putendl("\t\t\tARG(1): integer in range [2...99] inclusive.");
	ft_putendl("\t\t\tExample: --power 2\n");
	ft_putendl("  -s, --size\t\tResize the image.");
	ft_putendl("\t\t\tARG(1): integer in range [100...500] inclusive, the");
	ft_putendl("\t\t\t  argument is for width and height at the same time.");
	ft_putendl("\t\t\tExample: --size 500\n");
	usage2(app_name);
	exit(1);
}
