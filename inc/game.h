/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:30:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/12 14:05:54 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define SIZE 32
# define COLORS "RBKOGYP"
# define GAME_RATE 17
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "map.h"
# include "utils.h"
# include "colors.h"

enum e_keys
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_R = 15,
	KEY_Q = 12
};

enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

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
}				t_pl_sprite;

typedef struct s_sprite
{
	void		*logo;
	void		**wall;
	void		*pacfood;
	void		*portal;
	void		*pacman;
	void		*black;
	void		*intra;
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
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			n_frames;
	int			n_moves;
	int			redraw;
	int			g_rate;
}				t_game;

void		init_game(char **map, t_lay lay);
void		new_game(char **map, t_game *game, t_lay *lay);
t_sprite	init_sprites(t_game *game);
t_font		load_score_font(t_game *game);
void		ft_entitylist(char **map, t_game *game);
t_player	*ft_entnew(t_vector pos);
void		ft_entadd_back(t_player **lst, t_player *newnode);
void		ft_load_pacmans(t_game *game);
void		ft_load_ghosts(t_game *game);
t_list		*ft_load_north(t_game *game, int i);
t_list		*ft_load_south(t_game *game, int i);
t_list		*ft_load_east(t_game *game, int i);
t_list		*ft_load_west(t_game *game, int i);
int			ft_update(t_game *game);
void		ft_check_game(t_game *game);
void		ft_redraw_pac(t_game *game);
int			ft_choose_dir(t_game *game, t_player *ghost, t_player *pacman);
void		ft_update_legal(t_game *game, t_player *pl);
void		ft_restrict_legal(t_player *ghost);
int			ft_legal_len(t_player *player);
int			end_game(t_game *game);
int			free_sprites(t_game *game);
void		free_players(t_game *game);
void		free_animation(t_game *game, t_list *start);
void		free_fonts(t_game *game);
void		free_entitylist(t_game *game);
void		ft_next_dir(t_game *game);
int			ft_in_legal(t_player *player, int dir);
void		ft_update_score(t_game *game);
void		ft_put_font(t_game *game, int digit, int i);
void		ft_put_map(t_game *game, int x, int y);
void		ft_anim_north(t_game *game, t_player *pl);
void		ft_anim_south(t_game *game, t_player *pl);
void		ft_anim_east(t_game *game, t_player *pl);
void		ft_anim_west(t_game *game, t_player *pl);
void		ft_put_stopped(t_game *game, t_player *pl);
void		ft_move(int d, t_game *game, t_player *temp);
void		ft_put_pacman(t_game *game);
int			ft_swap_tile(t_vector old, t_vector nw, t_game *game);
int			ft_delete_entity(t_game *game, t_vector old);
void		ft_free_singlepl(t_game *game, t_player *pl);
int			ft_deletefirst_ent(t_game *game);
int			ft_deletelast_ent(t_game *game);
int			key_hook(int key, t_game *game);
void		ft_newdirection(t_game *game, int direction);
int			ft_reset(t_game *game);

#endif
