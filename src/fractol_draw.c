#include "./../include/fractol.h"

int set_color_burn(t_info *info)
{
	int	iteration;
	int	color;
	double	tmp;

	iteration = 0;
	while (info->real_z * info->real_z + info->imgn_z * info->imgn_z <= 4
		&& iteration < info->iterator)
	{
		tmp = info->real_z * info->real_z - info->imgn_z * info->imgn_z + info->real_c;
		info->imgn_z = 2 * abs_double(info->real_z * info->imgn_z) + info->imgn_c;
		info->real_z = tmp;
		iteration++;
	}
	if (iteration == info->iterator)
		color = rgb2hex(255, 255, 255);
	else
		color = iteration * info->color;
	return (color);
}

void	draw_mande_burn(t_info *info)
{
	int	x;
	int	y;

	info->real_del = (info->real_max - info->real_min) / (WIDTH - 1);
	info->imgn_del = (info->imgn_max - info->imgn_min) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->imgn_c = info->imgn_min + y * info->imgn_del;
			info->real_c = info->real_min + x * info->real_del;
			info->real_z = 0;
			info->imgn_z = 0;
			if (info->fractol == 0)
				my_mlx_pixel_put(&info->img, x, y, set_color(info));
			else
				my_mlx_pixel_put(&info->img, x, y, set_color_burn(info));
			x++;
		}
		y++;
	}
}

void	draw_julia(t_info *info)
{
	int	x;
	int	y;

	info->real_del = (info->real_max - info->real_min) / (WIDTH - 1);
	info->imgn_del = (info->imgn_max - info->imgn_min) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->imgn_z = info->imgn_min + y * info->imgn_del;
			info->real_z = info->real_min + x * info->real_del;
			my_mlx_pixel_put(&info->img, x, y, set_color(info));
			x++;
		}
		y++;
	}
}

int	main_loop_julia(t_info *info)
{
	update_c(info);
	draw_julia(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

int	main_loop_mande_burn(t_info *info)
{
	update_c(info);
	draw_mande_burn(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}