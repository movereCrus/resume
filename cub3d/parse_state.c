/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:07 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_pos(t_state *state, double x, double y)
{
	state->pos.x = x;
	state->pos.y = y;
}

void	set_dir(t_state *state, double x, double y)
{
	if (x < 0)
		state->dir.x = -1;
	else if (x > 0)
		state->dir.x = 1;
	else
		state->dir.x = 0;
	if (y < 0)
		state->dir.y = -1;
	else if (y > 0)
		state->dir.y = 1;
	else
		state->dir.y = 0;
}

void	init_dir(t_state *state, char dir)
{
	if (dir == 'N')
		set_dir(state, 0, -1);
	else if (dir == 'S')
		set_dir(state, 0, 1);
	else if (dir == 'W')
		set_dir(state, -1, 0);
	else if (dir == 'E')
		set_dir(state, 1, 0);
}

void	set_plane(t_state *state)
{
	t_point	dir;

	dir = state->dir;
	if (dir.x == 0)
	{
		if (dir.y == 1)
			state->plane.x = -1;
		else
			state->plane.x = 1;
		state->plane.y = 0;
	}
	else
	{
		if (dir.x == 1)
			state->plane.y = 1;
		else
			state->plane.y = -1;
		state->plane.x = 0;
	}
}

void	parse_state(t_state *state, t_map *info)
{
	char	*line;
	int		row;
	int		col;

	row = 0;
	while (row < info->h)
	{
		line = info->map[row];
		col = 0;
		while (col < (int)ft_strlen(line))
		{
			if (line[col] && ft_strchr("NSEW", line[col]))
			{
				set_pos(state, col + 0.5, row + 0.5);
				init_dir(state, line[col]);
				set_plane(state);
				return ;
			}
			col++;
		}
		row++;
	}
}
