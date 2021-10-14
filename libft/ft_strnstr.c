/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:37:08 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:40:56 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		little_len;
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len < little_len)
		return (NULL);
	i = 0;
	while (*big != '\0' && len - little_len - i + 1 != 0)
	{
		if (!(ft_strncmp(big, little, little_len)))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
