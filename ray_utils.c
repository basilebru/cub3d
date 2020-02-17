/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <bbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:00:44 by bbrunet           #+#    #+#             */
/*   Updated: 2020/02/14 18:52:18 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void set_pos_dir_plane(t_ray *ray, t_param params)
{
    ray->pos = params.pos;
    ray->dir = params.dir;
    //ray->plane = params.plane;
}

void display_wall(t_img *img, t_ray ray, int x)
{
    int j;

    j = ray.drawStart;
    while (j < ray.drawEnd)
    {
        my_mlx_pixel_put(img, x, j, ray.color);
        j++;
    }
}

void fill_ceiling_floor(t_img *img, t_param params)
{
    int i;
    int j;
    
    i = 0;
    while(i < params.res.x)
    {
        j = 0;
        while(j< params.res.y)
        {
            if(j < params.res.y / 2)
                my_mlx_pixel_put(img, i, j, params.col_F);
            else
                my_mlx_pixel_put(img, i, j, params.col_C);
            j++;
        }
        i++;
    }
}

void print_ray_info(t_ray ray)
{
    printf("mapX %d\n", ray.mapX);
    printf("mapY %d\n", ray.mapY);
     printf("posX %f\n", ray.pos.x);
    printf("posY %f\n", ray.pos.y);
     printf("dirX %f\n", ray.dir.x);
    printf("dirY %f\n", ray.dir.y);
    printf("sided.x %f\n", ray.sideDist.x);
    printf("sided.y %f\n", ray.sideDist.y);
    printf("deltad.x %f\n", ray.deltaDist.x);
    printf("deltad.y %f\n", ray.deltaDist.y);
    printf("dist %f\n", ray.wallDist);
    printf("height %d\n", ray.lineHeight);
    printf("start %d\n", ray.drawStart);
    printf("end %d\n", ray.drawEnd);
}