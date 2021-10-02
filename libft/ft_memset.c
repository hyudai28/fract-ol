/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:33:51 by hyudai            #+#    #+#             */
/*   Updated: 2020/11/25 01:04:32 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t	count;
	char	*p;

	p = buf;
	count = 0;
	while (count++ < n)
		p[count - 1] = ch;
	return ((void *)p);
}
