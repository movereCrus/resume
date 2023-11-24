/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:13 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:17 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# define DEF_W 800
# define DEF_H 640
# define DEL " \t\v\f\r\n"
# define TEXTURE 64
# define STEP 0.2
# define THETA 0.05

# define KEY_NONE -1
# define KEY_ESC  53//65307
# define KEY_W  13//119
# define KEY_S  1//115
# define KEY_D  2//100
# define KEY_A  0//97
# define KEY_LD  123//65361
# define KEY_RD  124//65363

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA
}	t_dir;

typedef enum e_arrow
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_arrow;

typedef enum e_colors
{
	F,
	C
}	t_colors;

typedef enum e_side
{
	X,
	Y
}	t_side;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_ray
{
	t_point	ray_dir;
	t_point	side_dist;
	t_point	delta_dist;
	int		map_x;
	int		map_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double	ratio;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
}	t_map;

typedef struct s_img
{
	unsigned int	*addr;
	int				bpp;
	int				line;
	int				end;
}	t_img;

typedef struct s_graphics
{
	void	*img;
	void	*textures[4];
	int		colors[2];
	t_img	img_info;
	t_img	texture_info[4];

}	t_graphics;

typedef struct s_state
{
	t_point	pos;
	t_point	dir;
	t_point	plane;
}	t_state;

typedef struct s_render
{
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	double	ratio;
	int		line_h;
	int		start_y;
	int		end_y;
}	t_render;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		mapinfo;
	t_graphics	graph_info;
	t_state		state;
}	t_game;

/*UTILS*/
void	*make_img(void *mlx, char *xpm);
void	throw_error(char *str);
char	*new_line(int fd);
char	*trim_line(char *line, int back);
int		to_rgb(char *str);
char	*strtrim_back(char const *s1, char const *set);

/*DRAWINGS*/
void	draw_wall(t_game *game, t_ray *ray, int x);
void	pixel_put(t_img *img, int x, int y, int color);
void	draw_game(t_game *game);

/*INIT*/
void	init(t_game *game);

/*RAYCAST*/
void	set_ray(t_state *state, t_ray *ray, double camera);
t_ray	raycast(t_state *state, char **map, double camera);

/*VALIDATION*/
void	valid_map(t_map *info);	
void	valid_edges(char *line, int height, int row);
void	valid_inners(char *line, char **map, int height, int row);

/*PARSING*/
void	parse_all(char *file, t_game *game);
void	parse_state(t_state *state, t_map *info);
void	parse_color(int *color, char *line, int *check);
void	parse_texture(t_graphics *graphics, char *line, void *mlx, int *check);
void	graph_info(int fd, t_graphics *graphics, void *mlx);
void	map_info(t_map *info, int fd);
void	set_pos(t_state *state, double x, double y);
void	set_dir(t_state *state, double x, double y);
void	set_plane(t_state *state);

/*GAME HANDLERS*/
void	start_game(t_game *game);
int		close_game(t_game *game);
int		handler(int key, t_game *game);

#endif
