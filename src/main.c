/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:48:44 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/23 23:45:16 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*load_texture(t_cub3d *game, char *filename)
{
	t_mlx_img		*img;
	int				width;
	int				height;

	width = 64;
	height = 64;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, filename, &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	return (img);
}

void	destroy_img(t_mlx_img *mlx_img)
{
	mlx_destroy_image(mlx_img->mlx->mlx_ptr,	mlx_img->img_ptr);
	free(mlx_img);
}

void	mlx_disconnect(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

void	gracefull_shutdown(t_cub3d	*game)
{
	t_mlx	*mlx;

	mlx = game->mlx;
	free(game->player.rays);
	free(game->player.collisions);
	destroy_img(game->texture_no);
	destroy_img(game->texture_so);
	destroy_img(game->texture_we);
	destroy_img(game->texture_ea);
	destroy_img(mlx->img);
	destroy_img(game->map->minimap);
	mlx_disconnect(mlx);
	free(mlx);
	destroy_strmap(game->map);
	free(game);
}

int		game_loop(t_cub3d *game)
{
	clear_map(game);
	build_map_img(game);
	print_player_int_map(game);
	print_map(game);
	build_projection(game);
	print_projection(game);
	print_bar(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
	return (0);
}

void	mlx_test(t_cub3d	*game)
{
	t_mlx_img	*mlx_img;

	if (init_game_state(game))
	{
		game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, w_width, w_height, "Nuk3d");
		mlx_img = new_blank_img(game->mlx, w_width, w_height);
		game->mlx->img = mlx_img;
		game->texture_no = load_texture(game, game->s_map->no_path);
		game->texture_so = load_texture(game, game->s_map->so_path);
		game->texture_ea = load_texture(game, game->s_map->ea_path);
		game->texture_we = load_texture(game, game->s_map->we_path);
		mlx_hook(game->mlx->win_ptr, 17, 0L, mlx_loop_end, game->mlx->mlx_ptr); // fecha no X
		mlx_hook(game->mlx->win_ptr, 2, 1L << 0, key_hook, game);
		// mlx_loop_hook(game->mlx->mlx_ptr, game_loop, game); 
		game_loop(game); // usado no lugar do loop pra ver o ponto de colisão individualmente
		mlx_loop(game->mlx->mlx_ptr);
		gracefull_shutdown(game);
	}
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_cub3d	*game;

	(void)argc;
	(void)argv;
	// map = load_map("./maps/huge_map.cub");
	map = load_map("./maps/subject_map.cub");
	eval_map(map);
	if (map->status == OK)
	{
		game = load_game(map);
		if (game)
			mlx_test(game);
	}
	free_t_map(map);
	return (0);
}
