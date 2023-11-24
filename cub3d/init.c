/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:44 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:47 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	init_state(t_state *state)
{
	state->pos.x = 0;
	state->pos.y = 0;
	state->dir.x = 0;
	state->dir.y = 0;
	state->plane.x = 0;
	state->plane.y = 0;
}

void	init_map(t_map *info)
{
	info->map = (char **)ft_calloc(1, sizeof(char *));
	info->w = 0;
	info->h = 0;
}

void	init_img(t_graphics *graph, void *mlx)
{
	t_img	imgi;

	graph->img = mlx_new_image(mlx, DEF_W, DEF_H);
	imgi.addr = (unsigned int *) \
		mlx_get_data_addr(graph->img, &imgi.bpp, &imgi.line, &imgi.end);
	graph->img_info = imgi;
}

void	init_graphics(t_graphics *graph, void *mlx)
{
	int	i;

	init_img(graph, mlx);
	i = -1;
	while (++i < 4)
		graph->textures[i] = NULL;
	i = -1;
	while (++i < 2)
		graph->colors[i] = -1;
}

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		throw_error("mlx init\n");
	}
	init_map(&game->mapinfo);
	init_graphics(&game->graph_info, game->mlx);
	init_state(&game->state);
}
