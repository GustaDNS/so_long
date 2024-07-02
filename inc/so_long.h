/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:42:47 by gudaniel          #+#    #+#             */
/*   Updated: 2024/07/02 12:49:33 by gudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>

typedef struct	s_data 
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	t_position	player;
	t_position	exit;
	int			collectible;
}	t_data;

typedef struct s_position
{
	int x;
	int y;
}	t_position;

//------------------MAP--------------------//
void	map_size(t_data *data, t_position s_position);
void	map(int fd, t_data *data);
int		strlen_untilc(char *c);
void	read_map(char *file, t_data *data);
void	line(char *filename);


#endif