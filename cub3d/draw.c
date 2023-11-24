/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:05 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:08 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = img->bpp / 8;
	pixel = (y * img->line) / color_byte + x;
	*(img->addr + pixel) = color;
}

void	draw_bg(t_graphics *graphic)
{
	t_img	*img;
	int		x;
	int		y;

	img = &graphic->img_info;
	y = -1;
	while (++y < DEF_H / 2)
	{
		x = -1;
		while (++x < DEF_W)
		{
			pixel_put(img, x, y, graphic->colors[C]);
			pixel_put(img, x, y + (DEF_H / 2), graphic->colors[F]);
		}
	}
}

void	draw_game(t_game *game)
{
	int		x;
	t_ray	ray;
	double	camera;

	x = 0;
	draw_bg(&game->graph_info);
	while (x < DEF_W)
	{
		camera = 2 * x / (double)DEF_W - 1;
		ray = raycast(&game->state, game->mapinfo.map, camera);
		draw_wall(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->graph_info.img, 0, 0);
}
