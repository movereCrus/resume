/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:26 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	player_count(char *line, int *cnt)
{
	int	col;

	col = 0;
	while (line[col])
	{
		if (ft_strchr("NSEW", line[col]))
		{
			(*cnt)++;
			if (*cnt != 1)
				throw_error("Error\nInvalid number of player position");
		}
		col++;
	}
}

char	**map_dup(t_map *info)
{
	int		row;
	int		col;
	int		size;
	char	**map;

	map = ft_calloc(info->h, sizeof(char *));
	if (!map)
		throw_error("Error\nMalloc error");
	row = -1;
	while (++row < info->h)
	{
		map[row] = ft_calloc(info->w + 1, sizeof(char));
		col = -1;
		size = ft_strlen(info->map[row]);
		while (++col < size)
			map[row][col] = info->map[row][col];
		while (col < info->w)
		{
			map[row][col] = ' ';
			col++;
		}
	}
	return (map);
}

void	valid_map(t_map *info)
{
	char	**map;
	char	*line;
	int		row;
	int		cnt;

	row = 0;
	cnt = 0;
	map = map_dup(info);
	while (row < info->h)
	{
		line = map[row];
		player_count(line, &cnt);
		valid_edges(line, info->h, row);
		valid_inners(line, map, info->h, row);
		row++;
	}
	if (cnt != 1)
		throw_error("Error\nInvalid number of player position");
	row = -1;
	while (++row < info->h)
		free(map[row]);
	free(map);
}
