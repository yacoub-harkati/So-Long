/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:53:42 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/19 00:38:11 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_struct(t_data **data, t_map **map, char *map_name)
{
	init_map(map, map_name);
	*data = malloc(sizeof(t_data));
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, (*map)->width * 32, (*map)->height * 32, "So long");
	(*data)->imgs = malloc(sizeof(t_img));
	init_images(*data, (*data)->imgs);
}

void init_map(t_map **map, char *map_name)
{
	*map = malloc(sizeof(t_map));
	(*map)->height = read_height(map_name, *map);
	(*map)->width = 0;
	(*map)->exit_reached = false;
	(*map)->collect = 0;
	(*map)->player = 0;
	(*map)->map = NULL;
	(*map)->map_cpy = NULL;
	read_map(*map, map_name);
	read_width(*map);
	read_map_items(*map);
	check_map(*map);
}
