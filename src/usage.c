/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:35:54 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 18:29:44 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage4(char *app_name)
{
	ft_putendl("-X flag is color and gradient flag at the same time.\n");
	ft_putstr("Options can be written out of order, but arguments must ");
	ft_putendl("follow their options.");
	ft_putendl("FRACTOL should be the last parameter.\n");
	ft_putendl("Recommendation from the author:");
	ft_putstr("  Try: ");
	ft_putstr(app_name);
	ft_putendl(" -X 9 0xf 90 0x0f0 80 0x00f 70 0xf00 60 0xff0 50 0xf0f 40 0x0ff 30 0x0 0x4 julia");
	ft_putstr("   or: ");
	ft_putstr(app_name);
	ft_putendl(" -c 0x8a4a4a 0x8a8a4a 0x4a8a8a 0x8a4a8a 0x8a4a4a FRACTOL");
	ft_putstr("   or: ");
	ft_putstr(app_name);
	ft_putstr(" -X 6  0xf00  33 0xf00  34 0x00f  66 0x00f  67 0xfff  0xfff ");
	ft_putendl("FRACTOL");
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
	ft_putstr("Gradient values are set for colors from 100(max iteration) to ");
	ft_putstr("0(min iteration)\nin descending order. For simplicity, the ");
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
	ft_putstr("Usage: ");
	ft_putstr(app_name);
	ft_putendl(" [OPTION ARGS]... FRACTOL\n");
	ft_putendl("FRACTOL argument is case-INsensitive.");
	ft_putendl("List of fractals:\n  Mandelbrot\n  Julia\n");
	ft_putendl("Arguments to options are mandatory.");
	ft_putendl("  -c, --color\t\tChange the custom colors.");
	ft_putendl("\t\t\tARGS(3): HEX colors that starts with 0x.");
	ft_putendl("\t\t\tHint: 0x7 is same as 0x777 and same as 0x777777");
	ft_putendl("\t\t\tExample: --color 0x0 0x888 0xffffff\n");
	ft_putendl("  -g, --gradient\tChange the value of the gradient.");
	ft_putendl("\t\t\tARG(1): integer in range [99...1] inclusive.");
	ft_putendl("\t\t\tExample: --gradient 50\n");
	ft_putendl("  -m, --max-iter\tChange the value of the max iterations.");
	ft_putendl("\t\t\tARG(1): integer in range [2...2000] inclusive.");
	ft_putendl("\t\t\tExample: --max-iter 100\n");
	ft_putendl("  -s, --size\t\tResize the window.");
	ft_putendl("\t\t\tARG(1): integer in range [150...1500] inclusive, the");
	ft_putendl("\t\t\t  argument is for width and height at the same time.");
	ft_putendl("\t\t\tExample: --size 500\n");
	usage2(app_name);
	exit(1);
}
