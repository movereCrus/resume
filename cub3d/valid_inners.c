/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inners.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:30 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	check_space(char **map, int row, int col, int arrow)
{
	if (arrow == UP)
		arrow = map[row - 1][col];
	else if (arrow == DOWN)
		arrow = map[row + 1][col];
	else if (arrow == LEFT)
		arrow = map[row][col - 1];
	else if (arrow == RIGHT)
		arrow = map[row][col + 1];
	if (arrow != ' ' && arrow != '1')
		throw_error("Error\nInvalid inner wall\n");
}

void	check_side(char **map, int row, int col)
{
	int	len;

	len = ft_strlen(map[row]);
	if (col == 0)
		check_space(map, row, col, RIGHT);
	else if (col == len - 1)
		check_space(map, row, col, LEFT);
	else
	{
		check_space(map, row, col, LEFT);
		check_space(map, row, col, RIGHT);
	}
}

void	valid_inners(char *line, char **map, int height, int row)
{
	int	col;

	col = 0;
	while (line[col])
	{
		if (line[col] == ' ')
		{
			if (row == 0)
				check_space(map, row, col, DOWN);
			else if (row == height - 1)
				check_space(map, row, col, UP);
			else
			{
				check_space(map, row, col, UP);
				check_space(map, row, col, DOWN);
			}
			check_side(map, row, col);
		}
		col++;
	}
}
