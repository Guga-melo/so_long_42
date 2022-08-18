/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:30:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/18 14:15:31 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define SIZE 32

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "utils.h"
# include "map.h"
# include "colors.h"
# include <stdio.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;


typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*black;
}				t_font;

typedef struct s_pl_sprite
{
	t_list	*up;
	t_list	*up_bak;
	t_list	*down;
	t_list	*down_bak;
	t_list	*left;
	t_list	*left_bak;
	t_list	*right;
	t_list	*right_bak;
	t_list	*panic;
	t_list	*panic_bak;
}				t_pl_sprite;

typedef struct s_sprite
{
	void		*logo;
	void		**wall;
	void		*pacfood;
	void		*pacpower;
	void		*portal;
	void		*pacman;
	void		*pixels;
	void		*black;
	t_list		*pac_dying_bak;
	t_list		*pac_dying;
	t_font		score_font;
}				t_sprite;

typedef struct s_legal_actions
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_legal_actions;

typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	t_pl_sprite		sprites;
	t_legal_actions	legal;
	struct s_player	*next;
}				t_player;

typedef struct s_game
{
	int			width;
	int			height;
	void		*id;
	void		*w_id;
	t_lay		*lay;
	t_lay		lay_bak;
	t_sprite	sprites;
	t_player	*pl;
	t_player	*gh;
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			pac_dying;
	int			panic_mode;
	int			n_frames;
	int			n_moves;
	int			redraw;
	int			g_rate;
}				t_game;

void		init_game(char **map, t_lay lay);
void		new_game(char **map, t_game *game, t_lay *lay);
t_sprite	init_sprites(t_game *game);
t_list		*load_pac_death(t_game *game);
t_font		load_score_font(t_game *game);

#endif
