/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:26:43 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/17 18:01:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static const	ALLSYMBOLS = "cspdiouxX%%#-+ .*0123456789";

void ft_parse(t_io *io, t_mod *modifiers)
{
	while (*io->format)
	{
		if (*io->format[io->position] != '%')
		{
			io->nprinted = write(1, io->format[io->position], 1);
			io->position++;
		}
		else if (ft_strchr(ALLSYMBOLS, *io->format[io->position + 1])
		{
			while (ft_strchar(ALLSYMBOLS, *io->format[io->position]))
			{
				ft_parseconv(io, modifiers);
				io->position++;
			}
			if (log->conspec)
				ft_convert(io, modifiers);
		}
	}
}