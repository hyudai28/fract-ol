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

double	abs_double(double src)
{
	if (src < 0)
		src *= -1;
	return (src);
}