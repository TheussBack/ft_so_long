/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:08:29 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/04 17:46:50 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(char **map)
{
	int		i;
	int		j;
	t_data	*all;

	i = 0;
	j = 0;
	all = NULL;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	all->map_info.xp = j;
	all->map_info.yp = i;
	return (0);
}

int	get_y(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

/*
	char **map =
	{
		0x5f000,
		0x5f010,
		0x5f020,
		0x0
	}


	@0x5f000 ="1111111"
	@0x5f010 ="10PCE11"
	@0x5f020 ="1111111"

*/

int	dfs(t_map *map_info, int x, int y)
{
	int	new_value;

	new_value = '1';
	if (y < 0 || y >= map_info->height || x < 0 || x >= map_info->width)
		return (0);
	if (map_info->map[y][x] != 'P' && map_info->map[y][x] != 'C'
		&& map_info->map[y][x] != 'E' && map_info->map[y][x] != '0')
		return (0);
	if (map_info->map[y][x] == 'E')
	{
		map_info->map[y][x] = '1';
		return (0);
	}
	map_info->map[y][x] = new_value;
	dfs(map_info, x - 1, y);
	dfs(map_info, x + 1, y);
	dfs(map_info, x, y + 1);
	dfs(map_info, x, y - 1);
	return (0);
}

int	flood_fill(t_map *map)
{
	int	x;
	int	y;

	x = get_x(map->map);
	y = get_y(map->map);
	if (map->map[y][x] == '1')
		return (1);
	dfs(map, x, y);
	x = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] != '1' && map->map[y][x] != '0'
				&& map->map[y][x] != '\n')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// int main (int ac, char **av)
// {
// 	t_map map;

// 	if (ac == 2)
// 	{
// 		if (get_map(av[1],&map))
// 		{
// 			write (1, "Something's wrong with the path :((", 35);
// 			return (1);
// 		}
// 		if (flood_fill(&map))
// 		{
// 			write (1, "Something's wrong with the map :((", 34);
// 			return (1);
// 		}
// 	}
// 	//fonction pour free la carte
// 	return (0);
// }
