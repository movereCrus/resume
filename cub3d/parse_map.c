/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:11 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	*ft_realloc(void *buf, int before, int after)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after);
	i = 0;
	while (i < before)
	{
		dst[i] = src[i];
		i++;
	}
	free(buf);
	return ((void *)dst);
}

void	map_info(t_map *info, int fd)
{
	char	*line;

	line = trim_line(new_line(fd), 1);
	if (!line)
		throw_error("Error\nEmpty file");
	while (*line == '\0')
	{
		free(line);
		line = trim_line(new_line(fd), 1);
	}
	while (line)
	{
		info->map = (char **)ft_realloc(info->map, info->h, info->h + 1);
		info->map[info->h] = line;
		info->h++;
		if (info->w < ft_strlen(line))
			info->w = ft_strlen(line);
		line = trim_line(new_line(fd), 1);
	}
	if (line)
		free(line);
	close(fd);
}
