/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:46:00 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/19 11:13:07 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_map(t_cub3d *game)
{
	override_images(game->mlx->img, game->map->minimap, game->map->pos.x, game->map->pos.y);
}
