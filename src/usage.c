/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:35:54 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 02:20:12 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage3(char *app_name)
{
	ft_putendl("Recommendation from the author:");
	ft_putstr("  Try: ");
	ft_putstr(app_name);
	ft_putendl(" -c 0xf88 0xff8 0x8ff 0xf8f 0xf88 FRACTOL");
	ft_putstr("   or: ");
	ft_putstr(app_name);
	ft_putendl(" -c 0x8a4a4a 0x8a8a4a 0x4a8a8a 0x8a4a8a 0x8a4a4a FRACTOL");
	ft_putstr("   or: ");
	ft_putstr(app_name);
	ft_putstr(" -X 6  0xf00  33 0xf00  34 0x00f  66 0x00f  67 0xfff  0xfff ");
	ft_putendl("FRACTOL");
}

static void	usage2(char *app_name)
{
	ft_putstr("  -X, --col-grad\tChange the custom colors and the values of ");
	ft_putendl("the gradient.");
	ft_putendl("\t\t\tMAIN ARG(1): integer in range [2...11] inclusive. Must");
	ft_putendl("\t\t\t  be first among the arguments of -X flag.");
	ft_putstr("\t\t\tSIDE ARGS(X): list of HEX colors that starts with 0x and");
	ft_putendl("\n\t\t\t  integers in range [1...99] inclusive in ascending");
	ft_putendl("\t\t\t  order. X is the sum of the color and gradient");
	ft_putendl("\t\t\t  arguments reduced by 2. This means that COUNT of");
	ft_putendl("\t\t\t  color's arguments is equal to value of the main");
	ft_putendl("\t\t\t  argument, COUNT of gradient's arguments is equal to");
	ft_putendl("\t\t\t  value of the main argument minus two.");
	ft_putendl("\t\t\tHint: Colors and gradient values can be intertwined.");
	ft_putendl("\t\t\tExample: --col-grad 3  0xf  50 0x8  0x0\n");
	ft_putendl("      --help\t\tDisplay this help and exit.\n");
	ft_putstr("In the examples shown standard values that are set without ");
	ft_putendl("options.\n");
	ft_putstr("Gradient values are set for colors from 0(first color) to ");
	ft_putstr("100(last color) in\nascending order. For simplicity, the ");
	ft_putendl("first and last values do not need to be");
	ft_putendl("entered in the options.\n");
	ft_putendl("-X flag is color and gradient flag at the same time.\n");
	ft_putstr("Options can be written out of order, but arguments must ");
	ft_putendl("follow their options.");
	ft_putendl("FRACTOL should be the last parameter.\n");
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
	ft_putendl("\t\t\tExample: --color 0xf 0x888 0x000000\n");
	ft_putendl("  -g, --gradient\tChange the value of the gradient.");
	ft_putendl("\t\t\tARG(1): integer in range [1...99] inclusive.");
	ft_putendl("\t\t\tExample: --gradient 50\n");
	ft_putendl("  -m, --max-iter\tChange the value of the max iterations.");
	ft_putendl("\t\t\tARG(1): integer in range [2...500] inclusive.");
	ft_putendl("\t\t\tExample: --max-iter 100\n");
	ft_putendl("  -s, --size\t\tResize the window.");
	ft_putendl("\t\t\tARG(1): integer in range [150...1500] inclusive, the");
	ft_putendl("\t\t\t  argument is for width and height at the same time.");
	ft_putendl("\t\t\tExample: --size 500\n");
	usage2(app_name);
	exit(1);
}

int			lite_usage(char *app_name, _Bool list_of_frac)
{
	if (list_of_frac)
	{
		ft_putstr("Usage: ");
		ft_putstr(app_name);
		ft_putendl(" [OPTION ARGS]... FRACTOL\n");
		ft_putendl("FRACTOL argument is case-INsensitive.");
		ft_putendl("List of fractals:\n  Mandelbrot\n  Julia\n");
	}
	ft_putstr("Try '");
	ft_putstr(app_name);
	ft_putendl(" --help' for more information.");
	exit(1);
}

int			err_usage(char *err_msg, char *app_name, _Bool full)
{
	if (err_msg)
	{
		ft_putstr("Error: ");
		ft_putendl(err_msg);
	}
	return (full ? usage(app_name) : lite_usage(app_name, 0));
}