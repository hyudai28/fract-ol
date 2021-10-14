/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:55:43 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:40:38 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0 || dest == NULL)
		return (src_len);
	if (size == 1)
	{
		dest[0] = '\0';
		return (src_len);
	}
	while ((i++ < size - 1) && (src[i - 1] != '\0'))
		dest[i - 1] = src[i - 1];
	if (src[size - 1] == '\0' && src[i - 1] != '\0')
		dest[size - 1] = '\0';
	else
		dest[i - 1] = '\0';
	return (src_len);
}
