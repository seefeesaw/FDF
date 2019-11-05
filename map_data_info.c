/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:00:42 by ashongwe          #+#    #+#             */
/*   Updated: 2019/09/15 11:29:33 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*file_to_string(char *file)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	fd = open(file, O_RDONLY);
	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		exit(write(2, "read failure\n", 13));
	close(fd);
	return (str);
}

static void	validate_file(char *str)
{
	size_t a;

	a = 0;
	while (str[a] != '\0')
	{
		if (!ft_isdigit(str[a]) && str[a] != '-' && str[a] != ' '
		&& str[a] && str[a] != '\n')
		{
			if (str[a] == ',')
				while (str[a] != ' ' && str[a + 1] != '\0')
					a++;
			else
				exit(write(2, "invalid file\n", 13));
		}
		a++;
	}
}

void		map_dimensions(char *file1, t_struct *dstore)
{
	size_t	a;
	char	*s;

	a = 0;
	s = file_to_string(file1);
	validate_file(s);
	while (s[a] != '\0' && s[a] != '\n')
	{
		if (ft_isdigit(s[a]) || (s[a] == '-' && ft_isdigit(s[a + 1])))
		{
			dstore->map_width++;
			while (s[a] != ' ' && s[a + 1] != '\n' && s[a + 1] != '\0')
				a++;
		}
		a++;
	}
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == '\n')
			dstore->map_height++;
		a++;
	}
	free(s);
}

void		map_data(char *file1, t_struct *dstore)
{
	size_t	a;
	size_t	b;

	a = 0;
	dstore->fd = open(file1, O_RDONLY);
	if (!(dstore->map = (int**)malloc(sizeof(int*) * dstore->map_height)))
		exit(write(2, "malloc failure\n", 15));
	while (get_next_line(dstore->fd, &dstore->line))
	{
		b = 0;
		if (!(dstore->values = ft_strsplit(dstore->line, ' ')))
			exit(write(2, "malloc failure\n", 15));
		free(dstore->line);
		if (!(dstore->map[a] = (int*)malloc(sizeof(int) * dstore->map_width)))
			exit(write(2, "malloc failure\n", 15));
		while (dstore->values[b] != 0)
		{
			dstore->map[a][b] = ft_atoi(dstore->values[b]);
			free(dstore->values[b]);
			b++;
		}
		free(dstore->values);
		a++;
	}
	close(dstore->fd);
}
