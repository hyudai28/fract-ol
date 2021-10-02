#ifndef FRACTOL_H
# define FRACTOL_H

# if __APPLE__
// #  include "macos/mlx.h"
# elif __linux__
// #  include "linux/mlx.h"
# endif

// # include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <float.h>

# define ERROR -1
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 250
# define MAX_RE 2.0
# define MAX_IM 2.0
# define MIN_RE -2.0
# define MIN_IM -2.0
# define MOVE_STEP 0.01

# if __APPLE__
#  define KEYCODE_A	0
#  define KEYCODE_B	11
#  define KEYCODE_C	8
#  define KEYCODE_D	2
#  define KEYCODE_E	14
#  define KEYCODE_F	3
#  define KEYCODE_G	5
#  define KEYCODE_H	4
#  define KEYCODE_I	34
#  define KEYCODE_J	38
#  define KEYCODE_K	40
#  define KEYCODE_L	37
#  define KEYCODE_M	46
#  define KEYCODE_N	45
#  define KEYCODE_O	31
#  define KEYCODE_P	35
#  define KEYCODE_Q	12
#  define KEYCODE_R	15
#  define KEYCODE_S	1
#  define KEYCODE_T	17
#  define KEYCODE_U	32
#  define KEYCODE_V	9
#  define KEYCODE_W	13
#  define KEYCODE_X	7
#  define KEYCODE_Y	16
#  define KEYCODE_Z	6
#  define KEYCODE_MINUS	27
#  define KEYCODE_PLUS	24
#  define KEYCODE_LEFT_SB	33
#  define KEYCODE_RIGHT_SB	30
#  define KEYCODE_BS	42
#  define KEYCODE_SEMICOLON	41
#  define KEYCODE_BQ	39
#  define KEYCODE_COMMA	43
#  define KEYCODE_PERIOD	47
#  define KEYCODE_SLASH	44
#  define KEYCODE_TAB	48
#  define KEYCODE_CAPS_LOCK	57
#  define KEYCODE_SP	49
#  define KEYCODE_RE	52
#  define KEYCODE_LEFT_SHIFT	257
#  define KEYCODE_RIGHT_SHIFT	258
#  define KEYCODE_LEFT_OPTION	58
#  define KEYCODE_RIGHT_OPTION	61
#  define KEYCODE_LEFT_CONTROL	59
#  define KEYCODE_RIGHT_CONTROL	62
#  define KEYCODE_LEFT_COMMAND	55
#  define KEYCODE_RIGHT_COMMAND	54
#  define KEYCODE_DEL	51
#  define KEYCODE_ESC	53
#  define KEYCODE_LEFT	123
#  define KEYCODE_RIGHT	124
#  define KEYCODE_UP	126
#  define KEYCODE_DOWN	125
#  define KEYCODE_FN	63
#  define KEYCODE_HOME	116
#  define KEYCODE_END	121
#  define KEYCODE_PAGE_UP	115
#  define KEYCODE_PAGE_DOWN	119
#  define SCROLL_UP	4
#  define SCROLL_DOWN	5
#  define MOUSE_LEFT	6
#  define MOUSE_RIGHT	7
#  define HOOK_NUM	17
#  define HOOK_KEY	2
#  define HOOK_RELEASE	18
#  define HOOK_KEY_MASK	0
#  define HOOK_RELEASE_MASK	18
# elif __linux__
#  define KEYCODE_ESC	65307
#  define KEYCODE_LEFT	65361
#  define KEYCODE_RIGHT	65363
#  define KEYCODE_UP	65362
#  define KEYCODE_DOWN	65364
#  define KEYCODE_Q	113
#  define KEYCODE_LEFT_SHIFT	65505
#  define KEYCODE_RIGHT_SHIFT	65506
#  define SCROLL_UP	5
#  define SCROLL_DOWN	4
#  define MOUSE_RIGHT	1
#  define MOUSE_LEFT	3

#  define HOOK_NUM			33
#  define HOOK_KEY		2
#  define HOOK_RELEASE	3
#  define HOOK_KEY_MASK	1
#  define HOOK_RELEASE_MASK	2
# endif

// typedef struct s_img
// {
// 	void		*img;
// 	char		*addr;
// 	int			bits_per_pixel;
// 	int			line_length;
// 	int			endian;
// 	int			width;
// 	int			height;
// }				t_img;

// typedef enum e_flag
// {
// 	MANDELBROT = 0,
// 	JULIA = 1,
// 	BURNINGSHIP = 2
// }				t_flag;

// typedef struct s_data
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	int			r_x;
// 	int			r_y;
// 	int			iter;
// 	double		max_re;
// 	double		max_im;
// 	double		min_re;
// 	double		min_im;
// 	double		z_re;
// 	double		z_im;
// 	double		c_re;
// 	double		c_im;
// 	double		d_re;
// 	double		d_im;
// 	int			flag;
// 	double		m_re;
// 	double		m_im;
// 	double		interpolate;
// 	int			shift;
// 	double		zoom;
// 	int			color;
// 	double		z;
// 	double		z_init;
// }				t_data;

// typedef struct s_hsv
// {
// 	double		h;
// 	double		s;
// 	double		v;
// 	double		hh;
// 	double		p;
// 	double		q;
// 	double		t;
// 	double		ff;
// 	long		i;
// }				t_hsv;

// void			init_info(t_data *info, char *kinds);
// void			set_prms(t_data *info);

// int				return_error(char *str);
// int				exit_error(char *str);

// int				exit_window(t_data *info);
// int				key_press(int key, t_data *info);

// int				rgb2hex(int r, int g, int b);
// void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
// unsigned int	get_color_from_img(t_img img, int x, int y);
// unsigned int	hsv2rgb2hex(double h, double s, double v);
// int				set_hsv_prms(t_hsv *hsv);
// unsigned int	set_color(t_data *info);
// unsigned int	set_color_burn(t_data *info);

// void			draw_mandelbrot(t_data *info);
// void			draw_burningship(t_data *info);
// void			draw_julia(t_data *info);

// int				main_loop_man(t_data *info);
// int				main_loop_julia(t_data *info);
// int				main_loop_burn(t_data *info);

// int				i_min(int a, int b);
// int				i_max(int a, int b);
// double			f_sqr(double x);
// double			abs_double(double val);

// int				zoom(int button, int x, int y, t_data *info);
// void			interpolate_image(t_data *info);

// void			update_c(t_data *info);
// void			move(int key, t_data *info);
#endif
