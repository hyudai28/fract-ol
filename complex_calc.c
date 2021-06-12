#include "./mlx.h"

typedef struct s_cpx_num
{
    int real;
    int cpx;
}               t_cpx_num;

t_cpx_num     complex_add(t_cpx_num a, t_cpx_num b)
{
    t_cpx_num ret;
    
    ret.real = a.real + b.real;
    ret.real = a.real + b.real;
    return (ret);
}