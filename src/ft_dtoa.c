/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:54:06 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/24 00:22:57 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clear_zero(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (--len)
		if (str[len] == '0')
			str[len] = '\0';
		else
			break ;
}

static void	ft_dtoa2(char *str, char *temp, int num)
{
	if (num != 0)
	{
		ft_strncat(str, ".00000000", (size_t)(9 - ft_strlen(temp)));
		ft_strcat(str, temp);
		ft_strdel(&temp);
		if (!(temp = ft_itoa(num)))
			error("No memory allocated for string");
	}
	if (*temp != '0')
	{
		if (num == 0)
		{
			ft_strcat(str, ".");
			ft_strncat(str, "00000000", (size_t)(8 - ft_strlen(temp)));
		}
		else
			ft_strncat(str, "0000000", (size_t)(7 - ft_strlen(temp)));
		clear_zero(temp);
		ft_strcat(str, temp);
	}
	ft_strdel(&temp);
}

char		*ft_dtoa(double num)
{
	char	*str;
	char	*temp;

	if (!(str = ft_strnew(30)))
		error("No memory allocated for string");
	if (num <= -10)
		return (ft_strcpy(str, "Small double"));
	if (num >= 10)
		return (ft_strcpy(str, "Big double"));
	str[0] = num < 0 ? '-' : ' ';
	num < 0 ? num *= -1 : 0;
	if (!(temp = ft_itoa((int)num)))
		error("No memory allocated for string");
	ft_strcat(str, temp);
	ft_strdel(&temp);
	num = (num - (int)num) * 100000000;
	if (!(temp = ft_itoa((int)num)))
		error("No memory allocated for string");
	num = (num - (int)num) * 10000000;
	ft_dtoa2(str, temp, num);
	return (str);
}
