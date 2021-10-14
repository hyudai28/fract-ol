/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyudai <hyudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 00:55:54 by hyudai            #+#    #+#             */
/*   Updated: 2021/10/14 17:53:49 by hyudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_find_newline(int fd, char **line, char **st_arr, char *buf)
{
	int		chr;
	int		flag;
	char	*buf_tmp;
	char	*line_tmp;

	flag = 0;
	buf_tmp = NULL;
	chr = gnl_strchr(buf, '\n');
	line_tmp = ft_strnjoin(*line, buf, chr);
	if (!line_tmp)
		return (-1);
	free(*line);
	*line = line_tmp;
	line_tmp = NULL;
	if (buf[chr] == '\n')
	{
		buf_tmp = gnl_strdup(buf + chr + 1);
		if (!buf_tmp)
			return (-1);
		flag = 1;
	}
	free(st_arr[fd]);
	st_arr[fd] = buf_tmp;
	return (flag);
}

int	gnl_read_fd(int fd, char **line, char **st_arr)
{
	ssize_t	r_result;
	char	*buf;
	int		find_new;

	find_new = 0;
	r_result = 1;
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (r_result > 0 && find_new == 0)
	{
		r_result = read(fd, buf, BUFFER_SIZE);
		if (r_result > 0)
			buf[r_result] = '\0';
		if (r_result == 0)
			break ;
		find_new = gnl_find_newline(fd, line, st_arr, buf);
	}
	free(buf);
	if (r_result == -1)
		gnl_free_all(line, st_arr, fd);
	return (find_new);
}

int	get_next_line(int fd, char **line)
{
	static char	*st_arr[256];
	int			check;

	if (0 > fd || fd >= 256 || !line)
		return (-1);
	*line = malloc(1);
	if (!*line)
		return (-1);
	*line[0] = '\0';
	check = 0;
	if (st_arr[fd] != NULL)
		check = gnl_find_newline(fd, line, st_arr, st_arr[fd]);
	if (check == 0)
		check = gnl_read_fd(fd, line, st_arr);
	return (check);
}
