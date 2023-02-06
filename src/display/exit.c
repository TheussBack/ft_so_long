/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:37 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/04 17:49:36 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_free(char *str, char **map)
{
	if (map)
		free_tab(map);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit_fail(str);
}

void	exit_fail(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	close_game(t_data *all)
{
	free_pattern(&(all->pattern), &(all->wind), &(all->map_info));
	if (all->wind.wind_ptr)
		mlx_destroy_window(all->wind.mlx_ptr, all->wind.wind_ptr);
	if (all->wind.mlx_ptr)
		mlx_destroy_display(all->wind.mlx_ptr);
	free(all->wind.mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}
