/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:19:38 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:51:03 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *string1, const char *string2, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	k;

	i = 0;
	n = ft_strlen(string1);
	k = ft_strlen(string2);
	if (n >= size)
		return (size + k);
	while ((n + i < size - 1) && (string2[i] != '\0'))
	{
		string1[i + n] = string2[i];
		i++;
	}
	string1[i + n] = '\0';
	if (ft_strlen(string1) > size)
		return (k + size);
	else
		return (n + k);
}
