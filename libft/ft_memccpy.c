/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:46:52 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:43:55 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	c = (unsigned char)c;
	i = 0;
	if (a == NULL && b == NULL)
		return (NULL);
	while (i < n)
	{
		if (b[i] == c)
		{
			a[i] = c;
			return ((void *)&(a[i + 1]));
		}
		a[i] = b[i];
		i++;
	}
	if (b[i] == '\0')
		a[i] = '\0';
	return (NULL);
}
