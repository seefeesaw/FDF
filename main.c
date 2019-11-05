/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:54:36 by ashongwe          #+#    #+#             */
/*   Updated: 2019/09/15 11:29:21 by ashongwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	my_key_hook_funct(int key, t_struct *data_store)
{
	(void)data_store;
	if (key == ESC)
	{
		mlx_destroy_window(data_store->mlx, data_store->win);
		exit(0);
	}
	return (0);
}

static void	wireframe_call(char *file1, t_struct *dstore)
{
	dstore->map_width = 0;
	dstore->map_height = 0;
	map_dimensions(file1, dstore);
	map_data(file1, dstore);
	ft_set_constants(dstore);
	dstore->mlx = mlx_init();
	dstore->win = mlx_new_window(dstore->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	draw_map(dstore);
	mlx_key_hook(dstore->win, my_key_hook_funct, dstore);
	mlx_loop(dstore->mlx);
}

int			main(int ac, char **av)
{
	t_struct *data_store;

	if (!(data_store = (t_struct*)malloc(sizeof(t_struct))))
		exit(write(2, "malloc failure\n", 15));
	if (ac == 2)
		wireframe_call(av[1], data_store);
	else
		ft_putendl_fd("usage: ./fdf file", 2);
	free(data_store);
	return (0);
}
