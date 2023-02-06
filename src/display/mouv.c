/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:29:18 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/04 19:04:06 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p(int *x, int *y, char **map, char to_find)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == to_find)
			{
				*x = j;
				*y = i;
			}
		}
	}
}

int	key_up(t_data *all)
{
	if (all->map_info.map[all->map_info.y - 1][all->map_info.x] == '1'
		|| all->map_info.map[all->map_info.y - 1][all->map_info.x] == 'E')
	{
		if (all->map_info.map[all->map_info.y - 1][all->map_info.x] == 'E'
			&& all->map_info.col_col == all->map_info.col_tot)
			close_game(all);
		return (0);
	}
	if (all->map_info.map[all->map_info.y - 1][all->map_info.x] == 'C')
	{
		all->map_info.map[all->map_info.y - 1][all->map_info.x] = '0';
		all->map_info.col_col++;
	}
	exchange(&(all->map_info.map[all->map_info.y - 1][all->map_info.x]),
		&(all->map_info.map[all->map_info.y][all->map_info.x]));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.floor, (all->map_info.x * 64), (all->map_info.y * 64));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.player_back1, (all->map_info.x * 64), ((all->map_info.y
				- 1) * 64));
	all->map_info.y -= 1;
	return (1);
}

int	key_down(t_data *all)
{
	if (all->map_info.map[all->map_info.y + 1][all->map_info.x] == '1'
		|| all->map_info.map[all->map_info.y + 1][all->map_info.x] == 'E')
	{
		if (all->map_info.map[all->map_info.y + 1][all->map_info.x] == 'E'
			&& all->map_info.col_col == all->map_info.col_tot)
			close_game(all);
		return (0);
	}
	if (all->map_info.map[all->map_info.y + 1][all->map_info.x] == 'C')
	{
		all->map_info.map[all->map_info.y + 1][all->map_info.x] = '0';
		all->map_info.col_col++;
	}
	exchange(&(all->map_info.map[all->map_info.y + 1][all->map_info.x]),
		&(all->map_info.map[all->map_info.y][all->map_info.x]));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.floor, (all->map_info.x * 64), (all->map_info.y * 64));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.player_front1, (all->map_info.x * 64),
		((all->map_info.y + 1) * 64));
	all->map_info.y += 1;
	return (1);
}

int	key_right(t_data *all)
{
	if (all->map_info.map[all->map_info.y][all->map_info.x + 1] == '1'
		|| all->map_info.map[all->map_info.y][all->map_info.x + 1] == 'E')
	{
		if (all->map_info.map[all->map_info.y][all->map_info.x + 1] == 'E'
			&& all->map_info.col_col == all->map_info.col_tot)
			close_game(all);
		return (0);
	}
	if (all->map_info.map[all->map_info.y][all->map_info.x + 1] == 'C')
	{
		all->map_info.map[all->map_info.y][all->map_info.x + 1] = '0';
		all->map_info.col_col++;
	}
	exchange(&(all->map_info.map[all->map_info.y][all->map_info.x + 1]),
		&(all->map_info.map[all->map_info.y][all->map_info.x]));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.floor, (all->map_info.x * 64), (all->map_info.y * 64));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.player_right1, ((all->map_info.x + 1) * 64),
		((all->map_info.y) * 64));
	all->map_info.x += 1;
	return (1);
}

int	key_left(t_data *all)
{
	if (all->map_info.map[all->map_info.y][all->map_info.x - 1] == '1'
		|| all->map_info.map[all->map_info.y][all->map_info.x - 1] == 'E')
	{
		if (all->map_info.map[all->map_info.y][all->map_info.x - 1] == 'E'
			&& all->map_info.col_col == all->map_info.col_tot)
			close_game(all);
		return (0);
	}
	if (all->map_info.map[all->map_info.y][all->map_info.x - 1] == 'C')
	{
		all->map_info.map[all->map_info.y][all->map_info.x - 1] = '0';
		all->map_info.col_col++;
	}
	exchange(&(all->map_info.map[all->map_info.y][all->map_info.x - 1]),
		&(all->map_info.map[all->map_info.y][all->map_info.x]));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.floor, (all->map_info.x * 64), (all->map_info.y * 64));
	mlx_put_image_to_window(all->wind.mlx_ptr, all->wind.wind_ptr,
		all->pattern.player_left1, ((all->map_info.x - 1) * 64),
		((all->map_info.y) * 64));
	all->map_info.x += 1;
	return (1);
}
