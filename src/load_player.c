/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:39:07 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/14 00:33:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_player_dir(t_player *player, char dir);

void	load_player(t_strmap	*map, t_player	*player)
{
	int		y_max;
	int		x_max;
	int		count;
	char	*map_v;

	y_max = map->lines;
	x_max = map->columns;
	count = 0;
	while (count < y_max * x_max)
	{
		map_v = ft_strchr("NSEW", (int)map->map[count]);
		if (map_v)
		{
			player->pos.x = (count % x_max) + 0.5;
			player->pos.y = (count / x_max) + 0.5;
			set_player_dir(player, (char)map->map[count]);
			break;
		}
		count++;
	}
}

static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}