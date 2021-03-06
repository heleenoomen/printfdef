/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:25:37 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 16:57:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printchar(t_io *io, t_mod *mods)
{
	char	c;

	if (mods->conspec == '%')
		c = '%';
	else
		c = (char) va_arg(io->ap, int);
	if (mods-> width > 1)
		mods->pads = mods->width - 1;
	if (!mods->leftadj && mods->pads)
		ft_pad(io, mods);
	io->nprinted += write(1, &c, 1);
	if (mods->leftadj && mods->pads)
		ft_pad(io, mods);
}
