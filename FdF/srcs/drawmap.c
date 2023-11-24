/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:40:58 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 18:54:21 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometrization(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.532599);
	*y = (*x + *y) * sin(0.532599) - z;
}

void	set_param(t_windata *pos0, t_windata *pos1, t_windata *wv)
{
	pos0->x *= wv->scale_xy;
	pos0->y *= wv->scale_xy;
	pos1->x *= wv->scale_xy;
	pos1->y *= wv->scale_xy;
	pos0->z *= wv->scale_z;
	pos1->z *= wv->scale_z;
	isometrization(&pos0->x, &pos0->y, pos0->z);
	isometrization(&pos1->x, &pos1->y, pos1->z);
	pos0->x += wv->shift_x;
	pos1->x += wv->shift_x;
	pos0->y += wv->shift_y;
	pos1->y += wv->shift_y;
}

void	coloring(float z, int *color, float elev)
{
	if (elev / 5 >= z)
		*color = 0x002CA414;
	else if (elev / 4 >= z)
		*color = 0x00A7D806;
	else if (elev / 3 >= z)
		*color = 0x00FFA200;
	else if (elev / 2 >= z)
		*color = 0x00FFAB00;
	else if (elev / 2 < z)
		*color = 0x00FF0000;
}

void	draw_line(t_windata pos0, t_windata pos1, t_windata *wv)
{
	float	dx;
	float	dy;
	float	max;
	int		color;
	float	elev;

	elev = wv->alt[0] + wv->alt[1];
	set_param(&pos0, &pos1, wv);
	dx = pos1.x - pos0.x;
	dy = pos1.y - pos0.y;
	max = max_o2(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(pos0.x - pos1.x) || (int)(pos0.y - pos1.y))
	{
		if (pos0.x > wv->win_x || pos0.y > wv->win_y
			|| pos0.x < 0 || pos0.y < 0)
			break ;
		coloring(pos0.z, &color, elev);
		my_mlx_pixel_put(wv, pos0.x, pos0.y, color);
		pos0.x += dx;
		pos0.y += dy;
	}
}

void	draw_map(t_windata **matrix, t_windata *wv)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				draw_line(matrix[y][x], matrix[y + 1][x], wv);
			if (!matrix[y][x].end_pos)
				draw_line(matrix[y][x], matrix[y][x + 1], wv);
			if (matrix[y][x].end_pos)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(wv->mlx, wv->win, wv->img, 0, 0);
}
