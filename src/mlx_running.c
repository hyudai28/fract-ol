/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_running.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:37:16 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:25:55 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fractol.h"

void	mlx_is_running(t_info *info)
{
	if (info->fractol == 0 || info->fractol == 2)
		mlx_loop_hook(info->mlx, &main_loop_mande_burn, info);
	else if (info->fractol == 1)
		mlx_loop_hook(info->mlx, &main_loop_julia, info);
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_hook(info->win, 17, 1L << 17, &push_exit, info);
	mlx_mouse_hook(info->win, zoom, info);
	mlx_loop(info->mlx);
}
