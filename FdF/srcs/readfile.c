/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:40:39 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 20:00:18 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**assign(t_windata **matrix, char *line, int y)
{
	char	**splitd_line;
	int		x;

	x = 0;
	splitd_line = ft_split(line, ' ');
	while (splitd_line[x] && splitd_line[x][0] != '\n')
	{
		matrix[y][x].z = ft_atoi(splitd_line[x]);
		if (matrix[y][x].z > matrix[0][0].alt[0])
			matrix[0][0].alt[0] = matrix[y][x].z;
		if (matrix[y][x].z < matrix[0][0].alt[1])
			matrix[0][0].alt[1] = matrix[y][x].z;
		matrix[y][x].y = y;
		matrix[y][x].x = x;
		matrix[y][x].end_pos = 0;
		free(splitd_line[x++]);
	}
	free(splitd_line[x]);
	matrix[y][--x].end_pos = 1;
	return (splitd_line);
}

void	fill_matrix(char *file, t_windata **matrix, int y)
{
	int		fd;
	char	*line;

	y = 0;
	matrix[0][0].alt[0] = 0;
	matrix[0][0].alt[1] = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(assign(matrix, line, y));
		y++;
		free(line);
	}
	free(line);
	calc_scale_z_shift_y(matrix);
	matrix[y] = NULL;
	close(fd);
}

static int	wd_count(char *s, char c)
{
	size_t	w;
	size_t	i;

	w = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}

t_windata	**read_file(int fd, int *x, int *y)
{
	int			y_temp;
	char		*line;
	t_windata	**matrix;

	line = NULL;
	get_next_line(fd, &line);
	*x = wd_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		(*y)++;
		free(line);
	}
	free(line);
	matrix = (t_windata **)ft_calloc((++(*y) + 1), sizeof(t_windata *));
	y_temp = *y;
	while (*y)
		matrix[--(*y)] = (t_windata *)ft_calloc((*x + 1), sizeof(t_windata));
	winvars_init(&matrix[0][0]);
	close(fd);
	*y = y_temp;
	return (matrix);
}
