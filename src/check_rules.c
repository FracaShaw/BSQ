/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:36:57 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 17:18:47 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_rules_len(char *fname)
{
	int	n_char;

	n_char = count_char_line(fname);
	if (n_char < 4)
		return (0);
	return (1);
}

int	get_c_count(char *fname, t_rules *rules)
{
	char	*str;
	int		shift;
	int		len;

	shift = count_char_line(fname) + 1;
	len = 0;
	str = ft_strdup(get_matrix_content(fname));
	if (shift == 1 || str == 0 || str[shift] == 0
		|| ft_strstr(&str[shift], "\n") == 0)
		return (0);
	len = ft_strlen(&str[shift]) - ft_strlen(ft_strstr(&str[shift], "\n"));
	if (len == 0)
		return (0);
	rules->c_count = len;
	free(str);
	return (1);
}

t_rules	get_rules(char *fname)
{
	t_rules	rules;
	char	*line;
	int		n_char;

	if (get_line(fname))
		line = ft_strdup(get_line(fname));
	n_char = count_char_line(fname);
	if (check_rules_len(fname) == 0 || n_char == 0)
	{
		rules.r_count = 0;
		return (rules);
	}
	rules.r_count = ft_atoi_n(line, n_char - 3);
	rules.full = line[(n_char - 1)];
	rules.obs = line[(n_char - 2)];
	rules.empty = line[(n_char - 3)];
	if (rules.full == rules.obs || rules.full == rules.empty
		|| rules.empty == rules.obs || rules.r_count == 0
		|| get_c_count(fname, &rules) == 0)
	{
		rules.r_count = 0;
		return (rules);
	}
	return (rules);
}
