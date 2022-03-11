#include <unistd.h>

void	print_matrix(char **matrix)
{
	int	r;
	int	c;

	r = 0;
	while (matrix[r])
	{
		c = 0;
		while (matrix[r][c])
		{
			write(1, &matrix[r][c], 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}
