/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:15 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	parse_color(int *color, char *line, int *check)
{
	t_colors	type;
	char		*str;

	type = 0;
	if (!ft_strncmp(line, "F", 1))
		type = F;
	else if (!ft_strncmp(line, "C", 1))
		type = C;
	else
		throw_error("Error\nUnknown color type\n");
	str = ft_strtrim(line + 2, DEL);
	if (check[type + 4] == 1)
		throw_error("Error\nFound duplicate in graphics\n");
	color[type] = to_rgb(str);
	check[type + 4] = 1;
	free(str);
	free(line);
}

void	parse_texture(t_graphics *graphics, char *line, void *mlx, int *check)
{
	t_dir	dir;
	t_img	imginfo;

	if (!ft_strncmp(line, "NO", 2))
		dir = NO;
	else if (!ft_strncmp(line, "SO", 2))
		dir = SO;
	else if (!ft_strncmp(line, "WE", 2))
		dir = WE;
	else if (!ft_strncmp(line, "EA", 2))
		dir = EA;
	else
	{
		parse_color(graphics->colors, line, check);
		return ;
	}
	if (check[dir] == 1)
		throw_error("Error\nFound duplicate in graphics\n");
	graphics->textures[dir] = make_img(mlx, ft_strtrim(line + 2, DEL));
	imginfo.addr = (unsigned int *)mlx_get_data_addr(graphics->textures[dir], \
		&imginfo.bpp, &imginfo.line, &imginfo.end);
	graphics->texture_info[dir] = imginfo;
	check[dir] = 1;
	free(line);
}

void	valid_graphics(int *check)
{
	int	cnt;
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check[i++] != 1)
			throw_error("Error\nCant find a texture");
	}
	cnt = i;
	while (i < cnt + 2)
	{
		if (check[i++] != 1)
			throw_error("Error\nCant find a color");
	}
}

void	graph_info(int fd, t_graphics *graphics, void *mlx)
{
	char	*line;
	int		i;
	int		check[6];

	i = -1;
	while (++i < 6)
		check[i] = 0;
	i = -1;
	while (++i < 6)
	{
		line = trim_line(new_line(fd), 0);
		if (!line && i == 0)
			throw_error("Error\nFile is empty\n");
		while (*line == '\0')
		{
			free(line);
			line = trim_line(new_line(fd), 0);
		}
		parse_texture(graphics, line, mlx, check);
	}
	valid_graphics(check);
}
