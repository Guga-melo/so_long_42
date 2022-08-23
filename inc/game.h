/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:30:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/23 11:33:38 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define SIZE 32
# define COLORS "RBKOGYP"
# define GAME_RATE 17
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# else
#  include "../minilibx/mlx.h"
# endif

# include "../libft/libft.h"
# include "map.h"
# include "utils.h"
# include "colors.h"
# include <stdio.h>

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
void		ft_entitylist(char **map, t_game *game);
t_player	*ft_entnew(t_vector pos);
void    	ft_entadd_back(t_player **lst, t_player *newnode);
void		ft_load_ghosts(t_game *game);
t_list		*ft_chooseghcolor(t_game *game, int i, int dir);
t_list		*ft_load_north(t_game *game, char *path, int i);
t_list		*ft_load_south(t_game *game, char *path, int i);
t_list		*ft_load_east(t_game *game, char *path, int i);
t_list		*ft_load_west(t_game *game, char *path, int i);
t_list		*ft_load_panic(t_game *game, int i);
void		ft_load_pacmans(t_game *game);
int			ft_update(t_game *game);
void		ft_check_game(t_game *game);
void		ft_redraw_gh(t_game *game);
void		ft_redraw_pac(t_game *game);
void		ft_update_ghosts(t_game *game);
t_player	*ft_murderpath(t_game *game, t_player *ghost);
int			ft_choose_dir(t_game *game, t_player *ghost, t_player *pacman);
void		ft_update_legal(t_game *game, t_player *ghost);
int			ft_find_ghost(t_player *pl, t_vector pos);
void		ft_restrict_legal(t_player *ghost);
int			ft_legal_len(t_player *player);
int			end_game(t_game *game);
int			free_sprites(t_game *game);
void		free_players(t_game *game);
void		free_animation(t_game *game, t_list *start);
void		free_fonts(t_game *game);
void		free_entitylist(t_game *game);
int			ft_advanced_dir(t_player *ghost, t_player *pacman, int *distances);
int			ft_advanced_dir2(int *distances);
void		ft_move_ghost(int d, t_game *game, t_player *gh);
void		ft_next_dir(t_game *game);
int			ft_in_legal(t_player *player, int dir);
void		ft_anim_pacdeath(t_game *game);
void		ft_put_ghosts(t_game *game);
void		ft_update_score(t_game *game);
void		ft_put_font(t_game *game, int digit, int i);
void		ft_put_map(t_game *game, int x, int y);
void		ft_anim_north(t_game *game, t_player *pl);
void		ft_anim_south(t_game *game, t_player *pl);
void		ft_anim_east(t_game *game, t_player *pl);
void		ft_anim_west(t_game *game, t_player *pl);
void		ft_anim_panic(t_game *game, t_player *pl);
void		ft_put_stopped(t_game *game, t_player *pl);
void		ft_move(int d, t_game *game, t_player *temp);
void		ft_put_pacman(t_game *game);
void		ft_redraw_pacfood(t_game *game, t_player *pl);
void		ft_redraw_exit(t_game *game, t_player *pl);
int			ft_checkmvtogh(t_game *game, int d, t_player *pl);
int			ft_swap_tile(t_vector old, t_vector nw, t_game *game);
int			ft_delete_entity(t_game *game, t_vector old);
void		ft_free_singlepl(t_game *game, t_player *pl);
int			ft_deletefirst_ent(t_game *game);
int			ft_deletelast_ent(t_game *game);

#endif
