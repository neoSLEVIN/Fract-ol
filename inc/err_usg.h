/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_usg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:45:52 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 15:48:56 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_USG_H
# define ERR_USG_H

# include "../libft/libft.h"

int		red_x_button(void *param);
int		error(char *err_msg);
int		usage(char *app_name);
int		lite_usage(char *app_name, _Bool list_of_frac);
int		err_usage(char *err_msg, char *app_name, _Bool full);
void	list_of_fractol(char *app_name);

#endif
