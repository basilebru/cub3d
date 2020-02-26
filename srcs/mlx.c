/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <bbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:13:35 by bbrunet           #+#    #+#             */
/*   Updated: 2020/02/13 205:49 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color; // marche aussi avec int. Pas compris pourquoi unsigned
}

void	my_mlx_pixel_get(t_img img, int x, int y, int *color)
{
	char	*dst;
	int		*dst_i;

	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	dst_i = (int *)dst;
	//printf("*dst_i %d\n", *dst_i);
	*color = *dst_i;
	//printf("x y: %d %d\n", x, y);
}

int		encode_color(int r_, int g_, int b_)
{
	int r;
	int g;
	int b;
	int color;

	r = (r_ & 255) << 16;
	g = (g_ & 255) << 8;
	b = (b_ & 255);
	color = r | g | b;
	//color = (0 & 0xff) << 24 | color;
	return (color);
}

int		init_mlx(t_img *i, int xres, int yres) //gerer les erreurs
{
	if (!(i->mlx = mlx_init()))
		return (ERROR);
	if (!(i->win = mlx_new_window(i->mlx, xres, yres, "Cub3d")))
		return (ERROR);
	if (!(i->img = mlx_new_image(i->mlx, xres, yres)))
		return (ERROR);
	if (!(i->addr =
		mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian)))
		return (ERROR);
	return (SUCCESS);
}