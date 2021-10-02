/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 03:47:53 by hyudai            #+#    #+#             */
/*   Updated: 2020/11/25 00:39:14 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	c = (char)c;
	len = ft_strlen(s) + 1;
	while (len-- != 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
	}
	return (NULL);
}
