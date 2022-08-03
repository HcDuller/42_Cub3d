/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/03 19:53:38 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	mouse_movement_hook(int x, int y, t_cub3d *game)
{
	if (!game->player.left_click)
		return (0);
	if (x > game->mouse_pos.x)
		rotate_player(game, 0.9f);
	else
		rotate_player(game, -0.9f);
	game->mouse_pos.x = x;
	game->mouse_pos.y = y;
	return (0);
}

int	mouse_hook(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	if (k == 1 && y < 480)
		fire(game);
	if (k == 3)
		game->player.left_click = 1;
	game_loop(game);
	return (0);
}

int	mouse_release(int k, int x, int y, t_cub3d *game)
{
	(void)x;
	(void)y;
	if (k == 3)
		game->player.left_click = 0;
	game_loop(game);
	return (0);
}

int	key_hook(int k, t_cub3d *game)
{
	if (k == 0xff1b)
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == 0x0061 || k == 0x0041)
		move_left(game);
	if (k == 0x0073 || k == 0x0053 || k == 0xff54)
		move_backward(game);
	if (k == 0x0064 || k == 0x0044)
		move_right(game);
	if (k == 0x0077 || k == 0x0057 || k == 0xff52)
		move_forward(game);
	if (k == 0xff51 || k == 0x0071)
		rotate_player(game, -2.5f);
	if (k == 0xff53 || k == 0x0065)
		rotate_player(game, 2.5f);
	if (k == 0x0072)
		reload(game);
	game_loop(game);
	return (0);
}
	/*
	teclas de interesse:
				normal		UPPERCASE
	a			0x0061		0x0041
	s			0x0073		0x0053
	d			0x0064		0x0044
	w			0x0077		0x0057
	p			0x0070		0x0050
	q			0x0071
	e			0x0065
	r			0x0072
	escape		0xff1b
	enter		0xff0d
	uparrow		0xff52
	downarrow	0xff54
	leftarrow	0xff51
	rightarrow	0xff53
	space		0x0020
	*/