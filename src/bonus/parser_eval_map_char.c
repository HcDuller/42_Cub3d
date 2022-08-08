/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:31 by hde-camp          #+#    #+#             */
/*   Updated: 2022/08/07 20:39:36 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	is_map_allowed_character(char c)
{
	char	*allowed;
	int		i;

	allowed = MAP_ALLOWED;
	i = 0;
	while (i < (int)ft_strlen(MAP_ALLOWED))
	{
		if (allowed[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_map_first_char(char c)
{
	char	*allowed;
	int		i;

	allowed = " 10";
	i = 0;
	while (i < 3)
	{
		if (allowed[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned char	get_char_at(t_strmap *map, int x, int y)
{
	int	pos;

	if (x >= 0 && x < map->columns && y >= 0 && y < map->lines)
	{
		pos = x + (y * (map->columns));
		return (map->map[pos]);
	}
	return (0);
}

int	is_in_list(char c, char *list)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(list))
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}
