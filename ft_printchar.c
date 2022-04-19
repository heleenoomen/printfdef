/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:25:37 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:55:26 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printchar(t_io *io, t_mod *modifiers)
{
	char	c;

	if (modifiers->conspec == '%')
		c = '%';
	else
		c = (char) va_arg(io->ap, int);
	modifiers->pads = modifiers->width - 1;
	if (!modifiers->leftadj && modifiers->pads)
		ft_pad(io, modifiers);
	io->nprinted += write(1, &c, 1);
	if (modifiers->leftadj && modifiers->pads)
		ft_pad(io, modifiers);
}
