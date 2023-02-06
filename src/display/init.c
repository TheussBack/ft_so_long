/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:23:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/06 15:10:27 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int key, t_data *all)
{
	static int	mouv = 0;
	int			check;

	check = mouv;
	find_p(&all->map_info.x, &all->map_info.y, all->map_info.map, 'P');
	if (key == XK_Escape)
		close_game(all);
	if (key == XK_w)
		mouv += key_up(all);
	if (key == XK_s)
		mouv += key_down(all);
	if (key == XK_d)
		mouv += key_right(all);
	if (key == XK_a)
		mouv += key_left(all);
	if (mouv != check)
		ft_printf("score : %d\n", mouv);
	return (0);
}

void	exchange(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	count_collectib(int *col_tot, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				*col_tot += 1;
		}
	}
}

void	is_too_big(t_data *all)
{
	if (all->map_info.height > 15)
		exit_free("Map height too big", all->map_info.map);
	if (all->map_info.width > 18)
		exit_free("Map width too big", all->map_info.map);
}
