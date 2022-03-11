/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:28:58 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/07/20 17:53:38 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAP_ERROR "map error\n"

typedef struct s_rules
{
	int		r_count;
	int		c_count;
	char	empty;
	char	obs;
	char	full;
}	t_rules;

typedef struct s_point
{
	int	c;
	int	r;
}	t_point;

int		ft_putstr(char *str);
void	ft_putnbr(int nb);
t_rules	get_rules(char *fname);
int		count_char_line(char *fname);
int		count_f_lines(char *fname);
int		ft_atoi_n(char *str, int n);
void	print_matrix(char **matrix);
int		count_leading_digits(char *fname);
char	*get_line(char *fname);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		count_f_bytes(char *fname);
char	*ft_strstr(char *str, char *to_find);
char	**malloc_matrix(int r_count, int c_count);
char	**get_og_matrix(char *fname, t_rules rules, int line0_size);
int		check_matrix(char *fname, t_rules rules);
char	*get_matrix_content(char *fname);
int		**malloc_matrix_int(t_rules rules);
int		**gen_matrix_n(char **og_matrix, t_rules rules);
void	print_matrix_int(int **matrix, t_rules rules);
int		**get_squares(int **matrix_n, t_rules rules);
t_point	get_max_sq(int **matrix_n, t_rules rules);
int		draw_solution(char **matrix_or, t_rules rules, t_point max_sq,
			int size_sq);
int		put_solution(char *fname);


#endif
