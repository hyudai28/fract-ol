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
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->size_l
            + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
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