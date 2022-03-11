/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:54:21 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 17:53:06 by gloyer-p         ###   ########.fr       */
/*   Updated: 2021/07/20 15:11:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	ft_stdinput(void)
{
	int		fd;
	char	*buf;

	fd = open("input", O_WRONLY | O_CREAT | O_TRUNC | S_IWUSR);
	buf = malloc(sizeof(*buf) * 2);
	if (buf == NULL || fd == -1)
		return (0);
	buf[1] = '\0';
	while (read(0, buf, 1))
		write(fd, &buf[0], 1);
	free(buf);
	if (close(fd) == -1)
		return (0);
	if (!put_solution("input"))
		return (ft_putstr(MAP_ERROR));
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	*fname;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			fname = av[i];
			if (!put_solution(fname))
				ft_putstr(MAP_ERROR);
			if (i == (ac - 1))
				return (0);
			write(1, "\n", 1);
			i++;
		}
	}
	return (ft_stdinput());
}
