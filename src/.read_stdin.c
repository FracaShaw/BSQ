/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:54:53 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 15:32:38 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include <unistd.h>

int	read_stdin()
{
	int fd;
	int ret;
	char *buf;
	int 	i;

	buf = malloc(sizeof(*buf) * 2);
	if (buf == NULL)
		return (printf("error malloc"));
	buf[1] = '\0';
	while (read(STDIN_FILENO, buf, 1) && *buf != '\n')
		printf("%s", buf);
	if (close(fd) == -1)
		return(printf("error closing"));
	return (printf("succses"));
}

int	main()
{
	read_stdin();
}
