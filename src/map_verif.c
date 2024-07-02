/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:46 by gudaniel          #+#    #+#             */
/*   Updated: 2024/07/02 12:59:27 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** 
 * @brief Verify if the size of our map is valid or nor
 * @param data Data of the struct of the game, in this case we use hight 
 * and width to determine if the map is a square/rectangule
*/
void	map_size(t_data *data, t_position position)
{
	while (data->height > 0)
	{
		if (data->height + data-> width < 7 || data->height < 3 || data ->width < 3)
			return (perror("This is not a valid map"));
	}
}
/**
 * @brief
 * @param 
*/
void	content(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->height > y)
	{
		while(data->width > x)
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			if (data->map[y][x] == 'E')
			{
				data->exit.x = x;
				data->exit.y = y;
			}
			if (data->map[y][x] == 'C')
			{
				data->collectible++;
			}
		}
	}
}
void	borders(t_data *data)
{
	
}