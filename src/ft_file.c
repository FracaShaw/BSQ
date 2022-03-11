/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:29:26 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 12:22:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_char_line(char *fname)
{
	int		n_char;
	int		fd;
	int		ret;
	char	buff[2];

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	n_char = 0;
	ret = read(fd, buff, 1);
	while (ret != 0 && buff[0] != '\n')
	{
		n_char++;
		ret = read(fd, buff, 1);
	}
	if (close(fd) == -1)
		return (0);
	return (n_char);
}

int	count_leading_digits(char *fname)
{
	int		n_digits;
	int		fd;
	int		ret;
	char	buff[2];

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	n_digits = 0;
	ret = read(fd, buff, 1);
	while (ret > 0 && (buff[0] >= '0' && buff[0] <= '9'))
	{
		n_digits++;
		ret = read(fd, buff, 1);
	}
	if (close(fd) == -1)
		return (0);
	return (n_digits);
}

int	count_f_lines(char *fname)
{
	int		n_lines;
	int		fd;
	int		ret;
	char	buff[2];

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	n_lines = 0;
	ret = read(fd, buff, 1);
	if (ret == 0)
		return (0);
	while (ret)
	{
		buff[ret] = 0;
		if (*buff == '\n')
			n_lines++;
		ret = read(fd, buff, 1);
	}
	if (close(fd) == -1)
		return (0);
	return (n_lines);
}

int	count_f_bytes(char *fname)
{
	int		n_bytes;
	int		fd;
	char	buff[2];

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	n_bytes = 0;
	while (read(fd, buff, 1))
		n_bytes++;
	if (close(fd) == -1)
		return (0);
	return (n_bytes);
}

char	*get_line(char *fname)
{
	int		n_char;
	char	*buff;
	int		fd;
	int		ret;

	n_char = count_char_line(fname);
	if (n_char == 0)
		return (0);
	buff = malloc(sizeof(*buff) * (n_char + 1));
	if (buff == 0)
		return (0);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buff, n_char);
	if (ret == 0)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (buff);
}
