/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:58:56 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:39:57 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	i = 0;
	dest = buf1;
	src = buf2;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	if (buf1 > buf2)
	{
		while (i++ < n)
			dest[n - i] = src[n - i];
	}
	else
	{
		while (i++ < n)
			dest[i - 1] = src[i - 1];
	}
	return (dest);
}
