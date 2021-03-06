/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eval_map_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:40:31 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/05 12:08:47 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_map_allowed_character(char c)
{
	char	*allowed;
	int		i;

	allowed = "10NSEW ";
	i = 0;
	while (i < 7)
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