/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:12:09 by hyudai            #+#    #+#             */
/*   Updated: 2020/11/26 16:36:14 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned char			*dest;
	unsigned char			sercher;
	size_t					i;

	dest = (unsigned char *)buf;
	sercher = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*dest == sercher)
			return ((void *)dest);
		i++;
		dest++;
	}
	return (NULL);
}
