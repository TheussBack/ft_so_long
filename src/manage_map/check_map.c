/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:14:22 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/04 16:55:40 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_copy(t_map *data)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = 0;
	map_cpy = malloc(sizeof(char *) * (data->height + 1));
	if (!map_cpy)
		return (NULL);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			map_cpy[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	return (map_cpy);
}

int	check_flood_fill(char **copy)
{
	int	x;
	int	y;

	y = -1;
	while (copy[++y])
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'C')
				return (1);
		}
	}
	return (0);
}

int	check_mappath(t_map *map)
{
	t_map	*map_cpy;
	int		result;

	map_cpy = map;
	flood_fill(map_cpy);
	result = check_flood_fill(map_cpy->map);
	if (result)
		exit_free("invalid path sorry", map_cpy->map);
	free_tab(map_cpy->map);
	return (result);
}
