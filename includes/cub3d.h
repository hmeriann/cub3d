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
	char	*xpm[5];
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

/*parser*/
int		ft_parser(t_p *p, int argc, char **argv);
void	ft_print_error(char *s);
void	ft_check_map_line(t_p *p, char *line);
void	ft_parse_line(t_p *p, char *line);



#endif