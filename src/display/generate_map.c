/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:30:28 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/08 16:09:26 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pattern(t_textures *pattern, t_windo *param, t_map *map_info)
{
	if (pattern->collectibles)
		mlx_destroy_image(param->mlx_ptr, pattern->collectibles);
	if (pattern->exit)
		mlx_destroy_image(param->mlx_ptr, pattern->exit);
	if (pattern->floor)
		mlx_destroy_image(param->mlx_ptr, pattern->floor);
	if (pattern->player_back1)
		mlx_destroy_image(param->mlx_ptr, pattern->player_back1);
	if (pattern->player_front1)
		mlx_destroy_image(param->mlx_ptr, pattern->player_front1);
	if (pattern->player_left1)
		mlx_destroy_image(param->mlx_ptr, pattern->player_left1);
	if (pattern->player_right1)
		mlx_destroy_image(param->mlx_ptr, pattern->player_right1);
	if (pattern->walls)
		mlx_destroy_image(param->mlx_ptr, pattern->walls);
	if (map_info->map)
		free_tab(map_info->map);
}

void	*my_mlx_xpm_file_to_image(char *filename, int *x, int *y, t_data *all)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(all->wind.mlx_ptr, filename, x, y);
	if (!tmp)
		exit_free("Something's wrong with the sprites", all->map_info.map);
	return (tmp);
}

void	file_to_img(t_data *all)
{
	int	x;
	int	y;

	all->pattern.player_front1 = my_mlx_xpm_file_to_image
		("./sprites/player_front1.xpm", &x, &y, all);
	all->pattern.player_back1 = my_mlx_xpm_file_to_image
		("sprites/player_back1.xpm", &x, &y, all);
	all->pattern.player_left1 = my_mlx_xpm_file_to_image
		("sprites/player_left1.xpm", &x, &y, all);
	all->pattern.player_right1 = my_mlx_xpm_file_to_image
		("sprites/player_right1.xpm", &x, &y, all);
	all->pattern.collectibles = my_mlx_xpm_file_to_image
		("sprites/collectibles.xpm", &x, &y, all);
	all->pattern.exit = my_mlx_xpm_file_to_image
		("sprites/exit.xpm", &x, &y, all);
	all->pattern.floor = my_mlx_xpm_file_to_image
		("sprites/floor.xpm", &x, &y, all);
	all->pattern.walls = my_mlx_xpm_file_to_image
		("sprites/walls.xpm", &x, &y, all);
	if (!all->pattern.player_back1 || !all->pattern.player_front1
		|| !all->pattern.player_left1 || !all->pattern.player_right1
		|| !all->pattern.collectibles || !all->pattern.exit
		|| !all->pattern.floor || !all->pattern.walls)
		close_game(all);
}

void	ft_print(char c, t_map *map, t_windo *param, t_textures *idk)
{
	if (c == 'P')
		mlx_put_image_to_window(param->mlx_ptr,
			param->wind_ptr, idk->player_front1, map->x1, map->y1);
	if (c == 'E')
		mlx_put_image_to_window(param->mlx_ptr,
			param->wind_ptr, idk->exit, map->x1, map->y1);
	if (c == 'C')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->collectibles, map->x1, map->y1);
	if (c == '1')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->walls, map->x1, map->y1);
	if (c == '2')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->walls2, map->x1, map->y);
	if (c == '3')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->walls3, map->x1, map->y1);
	if (c == '4')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->walls4, map->x1, map->y1);
	if (c == '0')
		mlx_put_image_to_window(param->mlx_ptr, param->wind_ptr,
			idk->floor, map->x1, map->y1);
}

int	gen_map(t_map *map, t_windo *param, t_textures *idk)
{
	int	i;
	int	j;

	j = -1;
	map->x1 = 0;
	map->y1 = 0;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			ft_print(map->map[j][i], map, param, idk);
			map->x1 += 64;
		}
		map->x1 = 0;
		map->y1 += 64;
	}
	return (0);
}
