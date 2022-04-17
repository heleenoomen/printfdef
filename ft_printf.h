#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
//# include"libft/libft.h"
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
}			t_mod;

typedef struct s_io
{
	const char	*format;
	va_list		ap;
	size_t		nprinted;
	size_t		position;
}				t_io;

#endif
