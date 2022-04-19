#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
# include"libft/libft.h"
# include<stdio.h>

typedef struct s_mod
{
	int		altform;
	int		zeropad;
	int		leftadj;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		adj_precision;
	char	conspec;
	int		base;
	int		putminus;
	int		pads;
}			t_mod;

typedef struct s_io
{
	const char	*format;
	va_list		ap;
	size_t		nprinted;
	size_t		position;
}				t_io;

void	ft_initmodifiers(t_mod *modifiers);
void	ft_parse(t_io *io, t_mod *modifiers);
void	ft_modifiers(t_io *io, t_mod *modifiers);
void	ft_convert(t_io *io, t_mod *modifiers);
void	ft_printchar(t_io *io, t_mod *modifiers);
void	ft_pad(t_io *io, t_mod *modifiers);
void	ft_printstr(t_io *io, t_mod *modifiers);
void	ft_printint(t_io *io, t_mod *modifiers);
void	ft_printnbr(t_io *io, t_mod *modifiers, unsigned long int nbr);
void	ft_putnbrpf(t_io *io, t_mod *modifiers, unsigned long int nbr);
void	ft_printmods(t_io *io, t_mod *modifiers);

#endif
