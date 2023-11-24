/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:42:31 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 19:37:43 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	winvars_init(t_windata *wv)
{
	wv->mlx = mlx_init();
	wv->win_x = 2000;
	wv->win_y = 1000;
	wv->win = mlx_new_window(wv->mlx, wv->win_x, wv->win_y, "FDF!");
	wv->img = mlx_new_image(wv->mlx, wv->win_x, wv->win_y);
	wv->addr = mlx_get_data_addr(wv->img, &wv->bits_per_pixel,
			&wv->line_length, &wv->endian);
}

float	max_o2(float a, float b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	calc_scale_xy_shift_x(t_windata *wvars, float max_x, float max_y)
{
	float	prop;

	if (max_o2(max_x, max_y) == max_y && (max_y - max_x) >= 2)
		prop = ((max_y * max_y) / (max_x * max_y));
	else if (max_o2(max_x, max_y) == max_x && (max_x - max_y) >= 2)
		prop = ((max_x * max_x) / (max_x * max_y));
	else
		prop = 1;
	wvars->scale_xy = wvars->win_y / (prop * max_y * cos(0.532599));
	wvars->shift_x = --max_y * cos(0.532599) * wvars->scale_xy + 2;
}

void	calc_scale_z_shift_y(t_windata **matrix)
{
	if (matrix[0][0].alt[0] == 0 && matrix[0][0].alt[1] == 0)
		matrix[0][0].scale_z = 1;
	else if (max_o2(matrix[0][0].alt[1], matrix[0][0].alt[0]) >= 100)
		matrix[0][0].scale_z = (matrix[0][0].win_y
				/ (fabs(matrix[0][0].alt[0]) + fabs(matrix[0][0].alt[1]))) / 10;
	else if (max_o2(matrix[0][0].alt[0], matrix[0][0].alt[1]) <= 30)
		matrix[0][0].scale_z = 30 / fabs(matrix[0][0].alt[0]
				- matrix[0][0].alt[1]);
	else
		matrix[0][0].scale_z = 1;
	matrix[0][0].shift_y = matrix[0][0].alt[0] * matrix[0][0].scale_z + 2;
	matrix[0][0].alt[0] *= matrix[0][0].scale_z;
	matrix[0][0].alt[1] *= matrix[0][0].scale_z;
}
