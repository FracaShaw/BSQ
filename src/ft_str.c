/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:50:00 by nprimo            #+#    #+#             */
/*   Updated: 2021/07/19 20:18:51 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	int		pos;

	pos = 0;
	dst = malloc(sizeof(*dst) * (ft_strlen(str) + 1));
	if (dst == 0)
		return (0);
	while (str[pos])
	{
		dst[pos] = str[pos];
		pos++;
	}
	dst[pos] = 0;
	return (dst);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	c;
	unsigned int	flag;

	c = 0;
	if (to_find[c] == 0)
		return (str);
	while (str[c] != 0)
	{
		flag = 0;
		while (str[c + flag] == to_find[flag])
		{
			flag++;
			if (to_find[flag] == 0)
				return (&str[c]);
		}
		c++;
	}
	return (0);
}
