#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/errno.h>

// # include "mlx.h"
// # include "get_next_line.h"
# include "./libft/libft.h"

typedef struct s_p
{
    int     argc;
    char    **argv;
	int		res_x;
	int		res_y;
	char	*tex[5];
	int		floor;
	int		ceiling;
	bool	got_sets;

	bool	end_map;
	int		map_height;
	int		map_width;
	t_list	*lst_map;
	char	**map;

	int		pers_x;
	int		pers_y;
	int		cnt_v;

}t_p;

/*utils*/
int		ft_digits(char *line);
int		ft_count_chars(const char *line, char *chars);
void	ft_free_split(char **arr);

/*parser*/
int		ft_parser(t_p *p, int argc, char **argv);
void	ft_print_error(char *s);
void	ft_check_map_line(t_p *p, char *line);
void	ft_parse_line(t_p *p, char *line);
void	ft_check_map_line(t_p *p, char *line);
void	ft_get_fc(t_p *p, char *line, bool is_floor);
void	ft_get_walls(t_p *p, char *line);
void	ft_create_map(t_p *p);
void	ft_check_holes(t_p *p);





#endif