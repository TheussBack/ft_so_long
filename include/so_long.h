/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:10:45 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/06 18:07:10 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1024

# endif

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <errno.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <string.h>
# include <X11/X.h>
# include <stdlib.h>


typedef struct	s_textures
{
	void	*player_front1;
	void	*player_front2;
	void	*player_back1;
	void	*player_back2;
	void	*player_left1;
	void	*player_left2;
	void	*player_right1;
	void	*player_right2;
	void	*collectibles;
	void	*exit;
	void	*floor;
	void	*walls;
	void	*walls2;
	void	*walls3;
	void	*walls4;
} t_textures ;

typedef struct	s_map {
	char **map;
	int	height;
	int	width;
	int	xp;
	int	yp;
	int	col_tot;
	int	col_col;
	int	x;
	int y;
	int x1;
	int y1;
} t_map ;

typedef struct	s_windo {
	void *mlx_ptr;
	void *wind_ptr;
	void *heihgt;
	void *width;
	void *x;
	void *y;
} t_windo ;

typedef struct s_data {
	t_textures	pattern;
	t_map	map_info;
	t_windo	wind;
}	t_data ;

int	check_mappath(t_map *map_info);
int	show_map(t_data *game, char **av);
int	deal_key(int key, t_windo *param);
char	**parse_map();
int	rectangle_map(char **map);
int	check_walls(char **map);
int	check_items(char **map, int p, int c, int e);
int	manage_err(char **map);
int	get_map(char *av, t_map *map_info);
int	get_lines(char *fichier);
int	count(char *str);
int	my_open(char *filename);
int	flood_fill(t_map *map_info);
int	dfs(t_map *map_info, int x ,int y);
int	get_y(char **map);
int	get_x(char **map);
void    file_to_img(t_data *all);
void    ft_print(char c, int x, int y, t_windo *param, t_textures *idk);
int    gen_map(t_map *map_info, t_windo *param, t_textures *idk);
void	free_tab(char **tab);
void	destroy_map(char **copy);
int	check_flood_fill(char **copy);
char	**get_copy(t_map *data);
void	exit_free(char *str, char **map);
void	exit_fail(char *str);
void	close_game(t_data *all);
void    free_pattern(t_textures *pattern, t_windo *param, t_map *map_info);
int ft_fct(int key, t_data *all);
void	find_p(int *x, int *y, char **map, char to_find);
void	exchange(char *x, char *y);
int	key_event(int key, t_data *all);
int key_up(t_data *all);
int key_down(t_data *all);
int	key_right(t_data *all);
int	key_left(t_data *all);
void	count_collectib(int *col_tot, char **map);
void	is_ber(char *filename);
int	red_cross(void *sl);
void is_too_big(t_data *all);

#endif
