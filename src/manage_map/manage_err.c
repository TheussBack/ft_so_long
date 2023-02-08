/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:33:35 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/08 16:37:06 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle_map(char **map)
{
	int	high;
	int	j;
	int	larg;

	j = 0;
	larg = 0;
	high = 0;
	while (map[0][j++] != '\0')
	{
		larg++;
	}
	j = 0;
	while (map[j] != 0)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[j]))
			return (1);
		high++;
		j++;
	}
	return (0);
}

int	ft_len_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_len_tab(map);
	while (map[0][i] != '\0' && map[j - 1][i] != '\0' && map[0][i] != '\n'
		&& map[j - 1][i] != '\n')
	{
		if (map[0][i] != '1' || map[j - 1][i] != '1')
			return (6);
		++i;
	}
	j = 0;
	while (map[j] != NULL)
	{
		if (map[j][0] != '1' || map[j][i - 1] != '1')
			return (1);
		++j;
	}
	if (i == j)
		return (1);
	return (0);
}

int	check_items(char **map, int p, int c, int e)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p += 1;
			if (map[i][j] == 'C')
				c += 1;
			if (map[i][j] == 'E')
				e += 1;
		}
	}
	if (p != 1 || c < 1 || e != 1)
		return (1);
	return (0);
}

int	manage_err(char **map)
{
	int	i;
	int	tab[3];

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	i += rectangle_map(map);
	i += check_items(map, tab[0], tab[1], tab[2]);
	i += check_walls(map);
	if (i != 0)
	{
		write(1, "Error with the map\n", 19);
		return (1);
	}
	else
		return (0);
}
/*
int	main(int ac, char **av)
{
	char	**map;

	if (ac == 2)
	{
		map = get_map(av[1]);
	}
	printf("%d\n", manage_err(map));
}
*/
