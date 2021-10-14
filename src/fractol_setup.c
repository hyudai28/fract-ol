/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:37:07 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 18:53:00 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fractol.h"

void	set_parameter(t_info *info)
{
	info->color = 1899750;
	info->iterator = 100;
	info->real_max = 2.0;
	info->imgn_max = 2.0;
	info->real_min = -2.0;
	info->imgn_min = -2.0;
	info->real_c = 0.4;
	info->imgn_c = -0.325;
	info->shift = 0;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	push_exit(t_info *info)
{
	(void)info;
	printf("bye!\n");
	exit(0);
}

void	update_c(t_info *info)
{
	int		x;
	int		y;
	double	real_ms;
	double	imgn_ms;

	mlx_mouse_get_pos(info->win, &x, &y);
	if (!x && !y)
		return ;
	real_ms = (double)x / (WIDTH / (info->real_max - info->real_min)) \
		+ info->real_min;
	imgn_ms = (double)y / (HEIGHT / (info->imgn_max - info->imgn_min)) \
		* -1 + info->imgn_max;
	info->real_c = real_ms;
	info->imgn_c = imgn_ms;
}
