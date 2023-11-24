/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:56 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	update_ray(t_ray *ray, int axis)
{
	if (axis == X)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = X;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = Y;
	}
}

void	set_wall(t_ray *ray, t_point *pos)
{
	if (ray->side == X)
		ray->wall_dist = \
			(ray->map_x - pos->x + (1 - ray->step_x) / 2.0) / ray->ray_dir.x;
	else
		ray->wall_dist = \
			(ray->map_y - pos->y + (1 - ray->step_y) / 2.0) / ray->ray_dir.y;
}

t_ray	raycast(t_state *state, char **map, double camera)
{
	t_ray	ray;
	int		hit;

	hit = 0;
	set_ray(state, &ray, camera);
	while (hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
			update_ray(&ray, X);
		else if (ray.side_dist.x > ray.side_dist.y)
			update_ray(&ray, Y);
		else
		{
			update_ray(&ray, X);
			update_ray(&ray, Y);
		}
		if (map[ray.map_y][ray.map_x] == '1')
			hit = 1;
	}
	set_wall(&ray, &state->pos);
	return (ray);
}
