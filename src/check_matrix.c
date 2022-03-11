/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:19:40 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/20 12:10:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_matrix_content(t_rules rules, char *fname)
{
	int		line;
	int		fd;
	char	buff[2];

	line = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n')
		{
			line++;
			continue ;
		}
		if (line > 0)
		{
			if (!(buff[0] == rules.empty || buff[0] == rules.obs))
				return (0);
		}
	}
	if (close(fd) == -1 || line != rules.r_count + 1)
		return (0);
	return (1);
}

char	*get_matrix_content(char *fname)
{
	int		n_bytes;
	int		fd;
	char	*content;

	n_bytes = count_f_bytes(fname);
	content = malloc(sizeof(*content) * (n_bytes + 1));
	fd = open(fname, O_RDONLY);
	if (content == 0 || n_bytes == 0 || fd == -1)
		return (0);
	read(fd, content, n_bytes);
	content[n_bytes] = 0;
	return (content);
}

int	check_matrix_size(t_rules rules, char *fname)
{
	char	*str;
	int		shift;
	int		len;

	shift = count_char_line(fname) + 1;
	len = 0;
	str = ft_strdup(get_matrix_content(fname));
	if (shift == 1 || str == 0)
		return (0);
	while (ft_strstr(&str[shift], "\n"))
	{
		len = ft_strlen(&str[shift]) - ft_strlen(ft_strstr(&str[shift], "\n"));
		if (rules.c_count != len)
			return (0);
		shift += len + 1;
	}
	free(str);
	return (1);
}

int	check_matrix(char *fname, t_rules rules)
{
	if (rules.r_count == 0)
		return (0);
	if (check_matrix_size(rules, fname) == 1
		&& check_matrix_content(rules, fname) == 1)
		return (1);
	return (0);
}
