/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:15:38 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:42:43 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_count(long int n, int i)
{
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_saiki(long int n, char *dest, int i, int x)
{
	if (n >= 10)
	{
		ft_itoa_saiki(n / 10, dest, i - 1, x);
	}
	dest[i] = n % 10 + '0';
	if (i == x - 1)
		dest[i] = n % 10 + '0';
	return (dest);
}

char	*ft_itoa(int k)
{
	int			i;
	int			flag;
	long int	n;
	char		*dest;

	n = (long int)k;
	i = 0;
	flag = 0;
	if (n < 0)
	{
		flag = 1;
		i++;
		n *= -1;
	}
	i = ft_itoa_count(n, i);
	dest = (char *)ft_calloc(1, i + 2);
	if (dest == NULL)
		return (NULL);
	if (flag)
		dest[0] = '-';
	ft_itoa_saiki(n, dest, i, i);
	return (dest);
}
