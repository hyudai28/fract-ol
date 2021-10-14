/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:36:14 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 18:52:11 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fractol.h"

int	arg_check(int argc, char **argv)
{
	if (argc != 2)
		err_message_fractol();
	if (!ft_strncmp(argv[1], "mande\0", 6))
		return (0);
	else if (!ft_strncmp(argv[1], "julia\0", 6))
		return (1);
	else if (!ft_strncmp(argv[1], "burn\0", 5))
		return (2);
	else
		err_message_fractol();
	return (0);
}

int	set_color(t_info *info)
{
	int		iteration;
	int		color;
	double	tmp;

	iteration = 0;
	while (info->real_z * info->real_z + info->imgn_z * info->imgn_z <= 4
		&& iteration < info->iterator)
	{
		tmp = info->real_z * info->real_z - info->imgn_z \
		* info->imgn_z + info->real_c;
		info->imgn_z = 2 * info->real_z * info->imgn_z + info->imgn_c;
		info->real_z = tmp;
		iteration++;
	}
	if (iteration == info->iterator)
		color = rgb2hex(255, 255, 255);
	else
		color = iteration * info->color;
	return (color);
}

void	interpolate_image(t_info *info)
{
	info->real_max = (info->real_mouse +(info->real_max - info->real_mouse) \
		* info->interpolate);
	info->imgn_max = (info->imgn_mouse +(info->imgn_max - info->imgn_mouse) \
		* info->interpolate);
	info->real_min = (info->real_mouse +(info->real_min - info->real_mouse) \
		* info->interpolate);
	info->imgn_min = (info->imgn_mouse +(info->imgn_min - info->imgn_mouse) \
		* info->interpolate);
}

int	zoom(int button, int x, int y, t_info *info)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		info->real_mouse = (double)x / \
			(WIDTH / (info->real_max - info->real_min)) + info->real_min;
		info->imgn_mouse = (double)y / \
			(HEIGHT / (info->imgn_max - info->imgn_min)) * -1 + info->imgn_max;
		if (button == SCROLL_UP)
		{
			if (info->iterator > 4)
				info->iterator -= 1;
			info->interpolate = 1.0 / 0.8;
		}
		else if (button == SCROLL_DOWN)
		{
			info->iterator += 1;
			info->interpolate = 1.0 / 1.2;
		}
		interpolate_image(info);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.fractol = arg_check(argc, argv);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "fractol");
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
	set_parameter(&info);
	mlx_is_running(&info);
}
