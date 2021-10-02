#include <stdio.h>
#include <stdlib.h>
#include <./mlx.h>
#include "./libft/libft.h"



//header file

#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
{
	void	*img;
	char		*addr;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}		t_img;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	real_max;
	double	imgn_max;
	double	real_min;
	double	imgn_min;
	double	real_z;
	double	imgn_z;
	double	real_c;
	double	imgn_c;
	double	real_del;
	double	imgn_del;
	int	color;
	int	fractol;
	int	iterator; //色の細かさ　６なら６色
}		t_info;

//header



int    i_min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int    i_max(int a, int b)
{
    int    res;

    if (a > b)
        res = a;
    else
        res = b;
    return (res);
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

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error.\n");
		exit(1);
	}
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

void	draw_mande(t_info *info)
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
			my_mlx_pixel_put(&info->img, x, y, set_color(info));
			x++;
		}
		y++;
	}
}

int	main_loop(t_info *info)
{
	draw_mande(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	arg_check(argc, argv);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "fractol");
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
//初期パラメータの設定
	if (!ft_strncmp(argv[1], "man", 3))
		info.fractol = 0;
	set_parameter(&info);

//hookやloopの設定
	mlx_loop_hook(info.mlx, &main_loop, &info);
	// mlx_hook(info.win, 2, 0, &key_press, &info);
	// mlx_hook(info.win, 3, 0, &key_release, &info);
	// mlx_hook(info.win, 17, 1L << 17, &push_exit, &info);
	mlx_loop(info.mlx);
}