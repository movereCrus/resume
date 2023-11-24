/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:46:48 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 18:47:14 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include "../mlx/mlx.h"
# include <fcntl.h>

typedef struct s_windata {
	float	x;
	float	y;
	float	z;
	int		end_pos;
	int		win_x;
	int		win_y;
	float	alt[2];
	float	scale_xy;
	float	scale_z;
	float	shift_x;
	float	shift_y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_windata;

void		calc_scale_xy_shift_x(t_windata *wvars, float max_x, float max_y);
void		calc_scale_z_shift_y(t_windata **matrix);
void		winvars_init(t_windata *wv);
void		my_mlx_pixel_put(t_windata *imgvars, int x, int y, int color);
void		draw_line(t_windata pos0, t_windata pos1, t_windata *wv);
void		isometrization(float *max_x, float *max_y, float max_z);
void		draw_map(t_windata **matrix, t_windata *winvars);
void		fill_matrix(char *file, t_windata **matrix, int y);
t_windata	**read_file(int fd, int *x, int *y);
float		max_o2(float a, float b);

#endif
