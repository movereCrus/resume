/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:28 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:32 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	valid_ext(char *av)
{
	int		len;
	int		v_len;
	char	*valid;

	v_len = 3;
	valid = ".cub";
	len = ft_strlen(av) - 1;
	while (v_len >= 0)
	{
		if (valid[v_len] != av[len])
			return (0);
		v_len--;
		len--;
	}
	return (1);
}

void	check_cmd(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\nUsage: ./cub3d <Map>\n", 27);
		exit(1);
	}
	if (!(valid_ext(av[1])))
	{
		write(2, "Error\nInvalid map file\n", 24);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	check_cmd(ac, av);
	init(&game);
	parse_all(av[1], &game);
	start_game(&game);
	mlx_hook(game.win, 2, 1L << 0, &handler, &game);
	mlx_hook(game.win, 17, 0, &close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
