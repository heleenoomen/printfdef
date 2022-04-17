/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:26:43 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/17 19:03:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static const	ALLSYMBOLS = "cspdiouxX%%#-+ .*0123456789";
static const	CONSPECS = "cspdiouxX%%";
static const	MODS = "#-+ .*0123456789";

void ft_parse(t_io *io, t_mod *modifiers)
{
	while (io->format[io->position])
	{
		if (io->format[io->position] != '%')
			io->nprinted = write(1, io->format + io->position, 1);
		else if (ft_strchr(ALLSYMBOLS, io->format[io->position + 1]))
		{
			io->position++;
			if (io->format[io->position])
			while (ft_strchr(MODS, io->format[io->position]))
			{
				ft_modifiers(io, modifiers);
				io->position++;
			}
			if (ft_strchr(CONSPECS, io->format[io->position]))
				ft_convert(io, modifiers);
			ft_initmodifiers(modifiers);
		}
		io->position++;
	}
}