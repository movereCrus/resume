/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:40:31 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 19:55:07 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_windata *imgvars, int x, int y, int color)
{
	char	*dst;

	dst = imgvars->addr + (y * imgvars->line_length + x
			* (imgvars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	destroyer(t_windata **matrix)
{
	int	y;

	y = 0;
	mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].img);
	mlx_destroy_window(matrix[0][0].mlx, matrix[0][0].win);
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	exit(0);
}

int	key_handler(int key, t_windata **matrix)
{
	if (key == 53)
		destroyer(matrix);
	return (0);
}

int	main(int argc, char **argv)
{
	t_windata		**matrix;
	int				fd;
	int				y;
	int				x;

	y = 0;
	x = 0;
	if (argc != 2)
	{
		ft_printf("Error!\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("File error!\n");
		return (0);
	}
	matrix = read_file(fd, &x, &y);
	fill_matrix(argv[1], matrix, y);
	calc_scale_xy_shift_x(&matrix[0][0], (float)x, (float)y);
	draw_map(matrix, &matrix[0][0]);
	mlx_key_hook(matrix[0][0].win, key_handler, matrix);
	mlx_hook(matrix[0][0].win, 17, 0, destroyer, matrix);
	mlx_loop(matrix[0][0].mlx);
}
