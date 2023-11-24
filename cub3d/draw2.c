/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:58 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:02 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

unsigned int	get_color(t_img *img, int x, int y)
{
	int	color;
	int	pixel;

	color = img->bpp / 8;
	pixel = (y * img->line) / color + x;
	return (*(img->addr + pixel));
}

int	texture_scaled(t_point *pos, t_ray *ray)
{
	double	wall;
	int		texture;

	if (ray->side == X)
		wall = pos->y + ray->wall_dist * ray->ray_dir.y;
	else
		wall = pos->x + ray->wall_dist * ray->ray_dir.x;
	wall = wall - floor(wall);
	texture = (int)(wall * (double)TEXTURE);
	if (ray->side == X && ray->ray_dir.x < 0)
		texture = TEXTURE - texture - 1;
	if (ray->side == Y && ray->ray_dir.y > 0)
		texture = TEXTURE - texture - 1;
	return (texture);
}

t_render	get_render(t_ray *ray, t_state *state)
{
	t_render	info;

	info.line_h = (int)(DEF_H / ray->wall_dist);
	info.ratio = (double)TEXTURE / info.line_h;
	info.start_y = (DEF_H / 2) - (info.line_h / 2);
	info.end_y = (DEF_H / 2) + (info.line_h / 2);
	if (info.start_y < 0)
		info.start_y = 0;
	if (info.end_y >= DEF_H)
		info.end_y = DEF_H;
	info.tex_x = texture_scaled(&state->pos, ray);
	info.tex_pos = (info.start_y - DEF_H / 2 + info.line_h / 2) * info.ratio;
	return (info);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_render	info;
	t_img		*tex_info;
	t_img		*img_info;
	int			color;

	img_info = &game->graph_info.img_info;
	info = get_render(ray, &game->state);
	tex_info = game->graph_info.texture_info;
	while (info.start_y < info.end_y)
	{
		info.tex_y = (int)info.tex_pos & (TEXTURE - 1);
		if (ray->side == X && ray->ray_dir.x > 0)
			color = get_color(&tex_info[WE], info.tex_x, info.tex_y);
		else if (ray->side == X && ray->ray_dir.x < 0)
			color = get_color(&tex_info[EA], info.tex_x, info.tex_y);
		else if (ray->side == Y && ray->ray_dir.y > 0)
			color = get_color(&tex_info[NO], info.tex_x, info.tex_y);
		else if (ray->side == Y && ray->ray_dir.y < 0)
			color = get_color(&tex_info[SO], info.tex_x, info.tex_y);
		pixel_put(img_info, x, info.start_y, color);
		info.tex_pos += info.ratio;
		info.start_y++;
	}
}
