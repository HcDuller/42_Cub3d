/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:38:46 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/22 15:06:27 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

#define	w_width 800
#define	w_height 600

typedef struct s_map		t_map;
typedef struct s_strmap		t_strmap;
typedef struct s_mlx		t_mlx;
typedef struct s_mlx_img	t_mlx_img;
typedef struct s_cub3d		t_cub3d;
typedef	struct s_point		t_point;
typedef struct s_player		t_player;
typedef struct s_int_point	t_int_point;
typedef struct s_collision	t_collision;

enum e_map_status{
	OK = 0,
	NO_MAP = 0b00000001,
	PERIMETER_ERROR = 0b00000010,
	INVALID_CHARACTER = 0b00000100,
	GARBAGE_LINES = 0b00001000,
	MAP_TOO_SHORT = 0b00010000,
	MAP_NOT_WALLED = 0b00100000,
	DUPLICATED_PARAMETER = 0b01000000
};

struct s_point
{
	float	x;
	float	y;
};

struct s_collision
{
	t_point	point;
	float	distance;
	float	perpDistance;
	int		side;
};

struct s_player
{
	t_point		pos;
	t_point		dir;
	int			n_rays;
	t_point		*rays;
	t_collision	*collisions;
	t_point		fov_vec[2];
	int			fov;
	t_cub3d		*game;
};

struct s_cub3d
{
	t_strmap		*map;
	t_mlx			*mlx;
	t_mlx_img		*projection;
	struct s_player	player;
};

struct	s_map
{
	char				**lines;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	unsigned char		floor_c[3];
	unsigned char		ceiling_c[3];
	enum e_map_status	status;
};

struct s_int_point
{
		int	x;
		int	y;
};

struct s_strmap
{
	char		*map;
	int			columns;
	int			lines;
	float		XYfactor[2];
	t_mlx_img	*minimap;
	int			minimap_pps;
	t_int_point	pos;
};

struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	*img;
	int			width;
	int			height;
};

struct s_mlx_img
{
	t_mlx	*mlx;
	void	*img_ptr;
	void	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
};

char			*get_next_line(int fd);
t_map			*load_map(const char *path);
void			eval_map(t_map	*map);
void			map_integrity(t_map *map);
int				is_map_allowed_character(char c);
int				is_map_first_char(char c);
void			eval_map_rules(t_map *map, t_strmap *strmap);
void			eval_assets(t_map *map);
t_strmap		*new_strmap(void);
void			load_strmap(t_strmap *strmap, t_map *map);
char			**get_map_first_line(t_map	*map);
char			**get_map_last_line(char **first_line);
void			print_map_error(t_map *map);
void			destroy_strmap(t_strmap *strmap);
int				is_valid_map_line(char *line);
int				is_valid_texture_line(char *line);
int				is_valid_color_line(char *line);
int				is_empty_line(char *line);
void			free_t_map(t_map *map);
char			*get_path(char *line);
int				key_hook(int k, t_cub3d *game);
void			gracefull_shutdown(t_cub3d	*game);
void			print_map(t_cub3d *game);
int				get_byte_offset(t_mlx_img	*img, int x, int y);
void			*get_pixel_addres(t_mlx_img	*img, int x, int y);
void			print_square(t_mlx_img	*img, unsigned int *dest_origin, int sqr_size, unsigned int color);
void			load_player(t_cub3d	*game, t_player	*player);
t_cub3d			*load_game(t_map	*map);
int				init_game_state(t_cub3d *game);
t_mlx_img		*new_blank_img(t_mlx	*mlx, int width, int height);
void			build_map_img(t_cub3d *game);
void			print_player_int_map(t_cub3d *game);
void			override_images(t_mlx_img *dst, t_mlx_img *src, int x, int y);
void			rotate_vector_old(float	angle, t_point *vector);
void			rotate_vector_new(float sin, float cos, t_point *vector);
t_point			sum_vectors(t_point *v_one, t_point *v_two);
t_point			subtract_vector(t_point *v_one, t_point *v_two);
float			vector_size(t_point *vector);
void			bresenham_line(t_mlx_img *img, int x0, int y0, int x1, int y1, unsigned int color);
void			multiply_vector_by_n(float	n, t_point	*vector);
void			set_fov_vectors(t_cub3d *game);
t_point			normalize_vector(t_point	vector);
t_point			first_axis_collision_y(t_point  position, t_point	norm_dir);
t_point			first_axis_collision_x(t_point  position, t_point	norm_dir);
t_point			get_first_collision(t_cub3d	*game, t_point	norm_dir);
char			square_dir_check(t_cub3d *game, t_point *collision, t_point *dir);
t_collision		get_collision(t_cub3d *game, t_point norm_dir);
void			set_collisions(t_cub3d	*game);

t_collision		get_first_collision_dda(t_cub3d *game, t_point norm_dir);
t_point			bresenham_checked_line(t_cub3d *game, int x0, int y0, int x1, int y1, unsigned int color);
char			square_check(t_cub3d *game, float x, float y);
int				game_loop(t_cub3d *game);
void	build_projection(t_cub3d *game);
void	print_projection(t_cub3d *game);

#endif
