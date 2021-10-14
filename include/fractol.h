/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:37:40 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:07:26 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <float.h>
# include <stdbool.h>
# include "./../include/mlx.h"
# include "./../libft/libft.h"
# include "./../include/key_macro.h"
# include "./../include/fractol.h"

# define ERROR -1
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 250
# define MAX_RE 2.0
# define MAX_IM 2.0
# define MIN_RE -2.0
# define MIN_IM -2.0
# define MOVE_STEP 0.01

typedef struct s_img
{
	void	*img;
	char	*addr;
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
	double	real_mouse;
	double	imgn_mouse;
	double	interpolate;
	int		color;
	int		fractol;
	double	iterator;
	bool	shift;
}		t_info;

int		zoom(int button, int x, int y, t_info *info);
void	interpolate_image(t_info *info);
void	update_c(t_info *info);
int		push_exit(t_info *info);
int		key_press(int key, t_info *info);
int		main_loop_mande_burn(t_info *info);
int		main_loop_julia(t_info *info);
void	draw_julia(t_info *info);
void	draw_mande_burn(t_info *info);
int		set_color_burn(t_info *info);
double	abs_double(double src);
int		set_color(t_info *info);
void	set_parameter(t_info *info);
int		arg_check(int argc, char **argv);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		rgb2hex(int r, int g, int b);
int		i_max(int a, int b);
int		i_min(int a, int b);
void	err_message_fractol(void);
void	mlx_is_running(t_info *info);

#endif