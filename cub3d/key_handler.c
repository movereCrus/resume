/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:36 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:40 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	wall_collision(t_point next_pos, t_state *state, char **map)
{
	t_state	move_state;
	t_ray	ray;
	double	camera_x;
	int		x;

	x = 0;
	set_pos(&move_state, state->pos.x, state->pos.y);
	set_dir(&move_state, next_pos.x - state->pos.x, next_pos.y - state->pos.y);
	set_plane(&move_state);
	while (x < DEF_W)
	{
		camera_x = 2 * x / (double)DEF_W - 1;
		ray = raycast(&move_state, map, camera_x);
		if (ray.wall_dist < STEP + 0.01)
			return (-1);
		x++;
	}
	return (0);
}

void	move(int key, t_state *state, char **map)
{
	t_state	next;

	if (key == KEY_W)
		set_pos(&next, state->pos.x + STEP * state->dir.x, \
			state->pos.y + STEP * state->dir.y);
	else if (key == KEY_D)
		set_pos(&next, state->pos.x + STEP * state->plane.x,
			state->pos.y + STEP * state->plane.y);
	else if (key == KEY_A)
		set_pos(&next, state->pos.x + -STEP * state->plane.x,
			state->pos.y + -STEP * state->plane.y);
	else if (key == KEY_S)
		set_pos(&next, state->pos.x + -STEP * state->dir.x,
			state->pos.y + -STEP * state->dir.y);
	else
		return ;
	if (wall_collision(next.pos, state, map) == 0)
		set_pos(state, next.pos.x, next.pos.y);
}

void	rotate_pos(int key, t_point *dir, t_point *plane)
{
	t_point	prev_dir;
	t_point	prev_plane;

	prev_dir = *dir;
	prev_plane = *plane;
	if (key == KEY_RD)
	{
		dir->x = (prev_dir.x * cos(THETA)) - (prev_dir.y * sin(THETA));
		dir->y = (prev_dir.x * sin(THETA)) + (prev_dir.y * cos(THETA));
		plane->x = (prev_plane.x * cos(THETA)) - (prev_plane.y * sin(THETA));
		plane->y = (prev_plane.x * sin(THETA)) + (prev_plane.y * cos(THETA));
	}
	else if (key == KEY_LD)
	{
		dir->x = (prev_dir.x * cos(-THETA)) - (prev_dir.y * sin(-THETA));
		dir->y = (prev_dir.x * sin(-THETA)) + (prev_dir.y * cos(-THETA));
		plane->x = (prev_plane.x * cos(-THETA)) - (prev_plane.y * sin(-THETA));
		plane->y = (prev_plane.x * sin(-THETA)) + (prev_plane.y * cos(-THETA));
	}
}

int	handler(int key, t_game *game)
{
	if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
	{
		mlx_clear_window(game->mlx, game->win);
		move(key, &game->state, game->mapinfo.map);
		draw_game(game);
	}
	else if (key == KEY_LD || key == KEY_RD)
	{
		mlx_clear_window(game->mlx, game->win);
		rotate_pos(key, &game->state.dir, &game->state.plane);
		draw_game(game);
	}
	if (key == KEY_ESC)
		close_game(game);
	return (0);
}
