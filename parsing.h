/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <bbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:02:49 by bbrunet           #+#    #+#             */
/*   Updated: 2020/02/26 11:47:07 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "vectors.h"

# define _R 2
# define _S 4
# define _F 8
# define _C 16
# define _NO 32
# define _SO 64
# define _WE 128
# define _EA 1

enum			e_textures
{
	SPRIT,
	NO,
	SO,
	WE,
	EA
};

typedef struct	s_cord_i
{
	int x;
	int y;
}				t_cord_i;

typedef struct	s_tex
{
	char		*path;
	int			*tex;
	t_cord_i	dim;
}				t_tex;

typedef struct	s_param
{
	t_cord_i	res;
	t_cord_f	pos;
	t_cord_f	dir;
	t_cord_f	plane;
	char		**map;
	t_tex		tex[5]; // dans lordre de lenum: tex[0] = SPRIT, tex[1] = NO...
	t_tex		ceiling;
	t_tex		floor;
	int			col_f;
	int			col_c;
	t_cord_f	*sprites;
	int			sprite_num;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
	int			key_esc;
	int			key_up;
	int			key_down;
	float			jump;
	int			texture_floor;
}				t_param;

int				ft_init_parse(t_param *params, char *filename);
int				ft_return_error(int err_index);
int				ft_get_map(t_list **lst, char *line);
int				ft_fill_check_map(t_list **lst, char ***map, t_param *params);
int				ft_fill_map(t_list *lst, char ***map);
int				ft_fill_params(int indice, char *line, t_param *params);
int				ft_fill_dir_pos(t_cord_f *pos, t_cord_f *dir, char **map);
int				ft_fill_plane(t_cord_f *plane, t_cord_f dir);
int				ft_check_map(char **map);
int				set_dir(t_cord_f *dir, char orientation);
int				ft_free_params(t_param params);
void			ft_print_map(char **map);
void			ft_init_params(t_param *params);
int				check_filename(char *filename);
int				ft_fill_sprites(t_cord_f **sprites, int *num, char **map);

#endif
