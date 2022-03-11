/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_r_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:45:35 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 12:05:07 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_r_count(char fname, t_rules rules, line0_size)
{
	int	fd;
	int ret;
	char *buf;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(*buf) * line0_size);
	if (buf == NULL)
		return (0);
	ret = read(fd, buf, line0_size);
	free(bu


