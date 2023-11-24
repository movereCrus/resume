/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:26 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:29 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_side(t_ray *ray, t_point pos)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pos.x - (double)ray->map_x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map_x + 1.0 - pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pos.y - (double)ray->map_y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_y + 1.0 - pos.y) * ray->delta_dist.y;
}

void	set_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	set_delta(t_ray *ray)
{
	if (ray->ray_dir.y == 0)
		ray->delta_dist.x = 0;
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
		ray->delta_dist.y = 0;
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void	set_ray(t_state *state, t_ray *ray, double camera)
{
	ray->ray_dir.x = state->dir.x + state->plane.x * camera;
	ray->ray_dir.y = state->dir.y + state->plane.y * camera;
	ray->map_x = (int)state->pos.x;
	ray->map_y = (int)state->pos.y;
	set_delta(ray);
	set_step(ray);
	set_side(ray, state->pos);
}
