/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_checkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:06:16 by hde-camp          #+#    #+#             */
/*   Updated: 2022/05/09 13:48:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*get_path(char *line)
{
	char	*path;

	path = line + 2;
	while (ft_isspace(*path))
		path++;
	if (*path != '.' && *path != '/')
		return (NULL);
	return (path);
}

int	is_valid_texture_line(char *line)
{
	char		*path;
	int			i;
	static char	*side[5] = {"NO", "SO", "WE", "EA", 0};

	i = 0;
	while (side[i] && ft_strncmp(line, side[i], 2) != 0)
		i++;
	if (i > 3)
		return (0);
	path = get_path(line);
	if (!path)
		return (0);
	path[ft_strlen((const char *)path) - 1] = '\0';
	if (open(path, O_RDONLY) > 0)
		return (1);
	return (0);
}

int	is_valid_color_line(char *line)
{
	char	**color;
	int		i;

	if (ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1))
		return (0);
	line++;
	while (ft_isspace(*line))
		line++;
	if (!ft_isdigit(*line))
		return (0);
	line[ft_strlen((const char *)line) - 1] = '\0';
	color = ft_split(line, ',');
	i = 0;
	while (color[i] && ft_atoi(color[i]) >= 0 && ft_atoi(color[i]) < 256)
		i++;
	ft_split_free(&color);
	if (i > 2)
		return (1);
	return (0);
}

int	is_valid_map_line(char *line)
{
	int	len;
	int	i;

	len = ft_strlen((const char *)line);
	i = 0;
	while (i < len - 1)
	{
		if (!is_map_allowed_character(line[i]))
			return (0);
		i++;
	}
	if (!ft_strchr("10NSEW \n", (int) line[i]))
	{
		return (0);
	}
	return (1);
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace((char) *line))
			return (0);
		line++;
	}
	return (1);
}