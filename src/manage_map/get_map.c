/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:12:04 by hrobin            #+#    #+#             */
/*   Updated: 2023/01/21 20:13:38 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_open(char *filename)
{
	int	fd;

	errno = 0;
	fd = open(filename, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
	}
	errno = 0;
	fd = open(filename, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0 || errno != 0)
	{
		if (errno == 40)
			write(1, "failed to open file.", 20);
	}
	return (fd);
}

int	count(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	get_lines(char *fichier)
{
	int		i;
	int		fd;
	int		nb_bytes;
	char	*buff;

	i = 0;
	fd = my_open(fichier);
	nb_bytes = 1;
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 2);
	if (!buff)
		return (0);
	while (nb_bytes > 0)
	{
		if (fd < 0)
			return (0);
		nb_bytes = read(fd, buff, BUFFER_SIZE);
		if (nb_bytes < 0)
			exit_fail("read encountered a problem.");
		buff[nb_bytes] = '\0';
		i += count(buff);
	}
	free(buff);
	close(fd);
	return (i);
}

int	get_map(char *av, t_map *data)
{
	int		i;
	int		nb_l;
	int		fd;
	char	**map;

	i = 0;
	nb_l = get_lines(av);
	data->height = nb_l;
	fd = my_open(av);
	map = ft_calloc(sizeof(char **), (nb_l + 1));
	if (!map)
		return (1);
	if (nb_l > 0)
	{
		map[i] = get_next_line(fd);
		while (map[i] && i < nb_l)
			map[++i] = get_next_line(fd);
		map[i] = '\0';
	}
	close(fd);
	data->map = map;
	data->width = ft_strlen(data->map[0]);
	return (0);
}

/*int main (int ac, char **av)
{
	t_map	map;
	int		i;

	i = -1;
	if (ac == 2)
	{
		if (get_map(av[1], &map))
			return (1); // error !
		map.height = 10; // calcule
		c
		free (map.map);
	}
	return (0);
}
*/
