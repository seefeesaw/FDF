/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:22:23 by ashongwe          #+#    #+#             */
/*   Updated: 2019/09/15 11:29:11 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define ESC		53

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	void		*img;
	int			fd;
	char		*line;
	char		**values;
	int			**map;
	size_t		map_width;
	size_t		map_height;
	int			height_diff;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			size;
	int			height;
	int			border_x;
	int			border_y;
}				t_struct;

typedef struct	s_values
{
	int			i;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			d;
	int			d2;
}				t_values;

void			map_dimensions(char *file1, t_struct *dstore);
void			map_data(char *file1, t_struct *dstore);
void			ft_set_constants(t_struct *data);
void			draw_map(t_struct *data);

#endif
