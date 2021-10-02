/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:52:36 by hyudai            #+#    #+#             */
/*   Updated: 2021/05/18 10:37:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		size;
	char		*dest;

	if (s == NULL)
		return (NULL);
	if (len >= (ft_strlen(s) - start))
		size = ft_strlen(s) - start;
	else
		size = len;
	dest = (char *)malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size && *s != '\0')
	{
		if (ft_strlen(s) <= start)
			break ;
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
