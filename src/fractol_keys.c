/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:36:25 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:12:44 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fractol.h"

int	key_moves(int key, t_info *info)
{
	if (key == K_W)
	{
		info->imgn_max -= (info->imgn_max - info->imgn_min) * MOVE_STEP;
		info->imgn_min -= (info->imgn_max - info->imgn_min) * MOVE_STEP;
	}
	else if (key == K_A)
	{
		info->real_max -= (info->imgn_max - info->imgn_min) * MOVE_STEP;
		info->real_min -= (info->imgn_max - info->imgn_min) * MOVE_STEP;
	}
	else if (key == K_S)
	{
		info->imgn_max += (info->imgn_max - info->imgn_min) * MOVE_STEP;
		info->imgn_min += (info->imgn_max - info->imgn_min) * MOVE_STEP;
	}
	else if (key == K_D)
	{
		info->real_max += (info->imgn_max - info->imgn_min) * MOVE_STEP;
		info->real_min += (info->imgn_max - info->imgn_min) * MOVE_STEP;
	}
	return (0);
}

int	key_color_change(int key, t_info *info)
{
	if (key == K_G)
		info->color = 114514;
	if (key == K_H)
		info->color = 130000;
	if (key == K_J)
		info->color = 150000;
	if (key == K_K)
		info->color = 1899750;
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W || key == K_A || key == K_D || key == K_S)
		key_moves(key, info);
	else if (key == K_G || key == K_H || key == K_J || key == K_K)
		key_color_change(key, info);
	else if (key == K_L_SHIFT)
	{
		if (!info->shift)
			info->shift = 1;
		else if (info->shift)
			info->shift = 0;
	}
	return (0);
}
