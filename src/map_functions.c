/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:48:02 by gudaniel          #+#    #+#             */
/*   Updated: 2024/07/02 12:18:29 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief How many lines we have
 * @param filename The name of our map
 * @param gnl Variable used to keep our info after de func get_next_line read de inf of our map
 * @param fd file descriptor
*/
void	line_map(char *filename)
{
	int		i;
	int		fd;
	char 	*gnl;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0);
		return (perror("This file can't be read"));
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		free (gnl);
		gnl = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}
/**
 * @brief This function transfer the information of our gnl to the matrix of our map
 * @param data The information struct used to code the game
 * @param fd File descriptor
 * @param gnl Variable to keep our gnl function information
*/
void	map_fill(int fd, t_data *data)
{
	int 	i;
	char	*gnl;

	i = 0;
	while (i < data->height)
		data->map[i] = get_next_line(fd);
	gnl = get_next_line(fd);
	free(gnl);
	data->map[i] = NULL;
}
/**
 * @brief See the length
 * @param c
 * @return The value of len
*/
int	strlen_untilc(char *c)
{
	while(*c != '\0' && *c != '\n' && *c != '\r')
		c++;
	return (&c);
} 
/**
 * @brief Read the map
 * @param file name the file
 * @param data Our struct
 * @param height The hight of our map
 * @param width The width of our map
*/
void	read_map(char *file, t_data *data)
{
	int	fd;

	data->height = count_lines(file);
	if (data->height <= 0)
		return(perror("The map doesn't have a height"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Invalid fd"));
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		return (perror("Error to memmory aloccation"));
	fill_map(fd, data);
	data->width = strlen_untilc(data->map[0]);
	close(fd);
}