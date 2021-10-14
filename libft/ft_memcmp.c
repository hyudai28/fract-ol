/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:30:47 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:44:20 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char *)buf1;
	b = (const unsigned char *)buf2;
	i = 0;
	while (i < n)
	{
		if (!(*a == *b))
			return (*a - *b);
		i++;
		a++;
		b++;
	}
	return (0);
}
