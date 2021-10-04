#include "./../include/fractol.h"

int    i_min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int    i_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int    rgb2hex(int r, int g, int b)
{
    r = i_max(0, i_min(r, 255));
    g = i_max(0, i_min(g, 255));
    b = i_max(0, i_min(b, 255));
    return (r << 16 | g << 8 | b);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->size_l
            + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void	err_message_fractol(void)
{
	printf("\
This is fractol help.\n\
you can use 3 command.\n\
	1. ./fractol julia\n\
	2. ./fractol mande\n\
	3. ./fractol burn\n");
	exit (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc != 2)
		err_message_fractol();
	if (!ft_strncmp(argv[1], "mande", 5))
		return (0);
	else if (!ft_strncmp(argv[1], "julia", 5))
		return (1);
	else if (!ft_strncmp(argv[1], "burn", 4))
		return (2);
	else
		err_message_fractol();
	return (0);
}

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
}

int set_color(t_info *info)
{
	int	iteration;
	int	color;
	double	tmp;

	iteration = 0;
	while (info->real_z * info->real_z + info->imgn_z * info->imgn_z <= 4
		&& iteration < info->iterator)
	{
		tmp = info->real_z * info->real_z - info->imgn_z * info->imgn_z + info->real_c;
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

double	abs_double(double src)
{
	if (src < 0)
		src *= -1;
	return (src);
}

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

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
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
	else if (key == K_G)
		info->color = 114514;
	return (0);
}

int	push_exit(t_info *info)
{
	(void)info;
	printf("you click esc, bye!\n");
	exit(0);
}

void	update_c(t_info *info)
{
	int	x;
	int	y;
	double	real_ms;
	double	imgn_ms;

	mlx_mouse_get_pos(info->win, &x, &y);
	if (!x && !y)
		return ;
	real_ms = (double)x / (WIDTH / (info->real_max - info->real_min)) + info->real_min;
	imgn_ms = (double)y / (HEIGHT / (info->imgn_max - info->imgn_min)) * -1 + info->imgn_max;
	info->real_c = real_ms;
	info->imgn_c = imgn_ms;
}

void	interpolate_image(t_info *info)
{
	info->real_max = (info->real_mouse +(info->real_max - info->real_mouse) * info->interpolate);
	info->imgn_max = (info->imgn_mouse +(info->imgn_max - info->imgn_mouse) * info->interpolate);
	info->real_min = (info->real_mouse +(info->real_min - info->real_mouse) * info->interpolate);
	info->imgn_min = (info->imgn_mouse +(info->imgn_min - info->imgn_mouse) * info->interpolate);
}

int	zoom(int button, int x, int y, t_info *info)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		info->real_mouse = (double)x / (WIDTH / (info->real_max - info->real_min)) + info->real_min;
		info->imgn_mouse = (double)y / (HEIGHT / (info->imgn_max - info->imgn_min)) * -1 + info->imgn_max;
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
	if (info.fractol == 0 || info.fractol == 2)
		mlx_loop_hook(info.mlx, &main_loop_mande_burn, &info);
	else if (info.fractol == 1)
		mlx_loop_hook(info.mlx, &main_loop_julia, &info);
	mlx_hook(info.win, 2, 0, key_press, &info);
	mlx_hook(info.win, 17, 1L << 17, &push_exit, &info);
	mlx_mouse_hook(info.win, zoom, &info);
	mlx_loop(info.mlx);
}