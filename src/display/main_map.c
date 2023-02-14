/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:38:41 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/14 10:19:33 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(void *sl)
{
	close_game(sl);
	return (0);
}

void	is_ber(char *filename)
{
	int	i;
	int	len_name;

	i = 0;
	len_name = ft_strlen(filename);
	if (len_name < 4)
		exit_fail("Error\nFile is not a .ber");
	while (filename[i] && i < (len_name - 4))
		i++;
	if (ft_strncmp((filename + i), ".ber", 4))
		exit_fail("Error\nFile is not a .ber");
}

int	show_map(t_data *data, char **argv)
{
	get_map(argv[1], &(data->map_info));
	data->wind.mlx_ptr = mlx_init();
	data->wind.wind_ptr = mlx_new_window(data->wind.mlx_ptr, 1100, 1000,
			"mlx 42");
	file_to_img(data);
	gen_map(&(data->map_info), &(data->wind), &(data->pattern));
	mlx_hook(data->wind.wind_ptr, 17, 0L << 2, red_cross, data);
	mlx_hook(data->wind.wind_ptr, KeyPress, KeyPressMask, key_event, data);
	mlx_loop(data->wind.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (1);
	ft_bzero(&game, sizeof(game));
	is_ber(av[1]);
	get_map(av[1], &(game.map_info));
	is_too_big(&game);
	count_collectib(&game.map_info.col_tot, game.map_info.map);
	if (manage_err(game.map_info.map))
		close_game(&game);
	check_mappath(&(game.map_info));
	show_map(&game, av);
}
