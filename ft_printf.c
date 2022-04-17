/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:59:17 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/17 18:38:11 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_initio(t_io *io, const char *format, va_list ap)
{
	io->format = format;
	va_copy(io->ap, ap);
	va_end(ap);
	io->nprinted = 0;
	io->position = 0;
}

static void	ft_initmodifiers(t_mod *modifiers)
{
	modifiers->altform = 0;
	modifiers->zeropad = 0;
	modifiers->leftadj = 0;
	modifiers->space = 0;
	modifiers->plus = 0;
	modifiers->width = 0;
	modifiers->precision = -1;
	mod->adj_precision = 0;
	modifiers->conspec = 0;
	modifiers->base = 0;
	modifiers->putminus = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_mod	modifiers;
	t_io	io;

	va_start(ap, format);
	ft_initio(&io, format, ap);
	va_end(ap);
	ft_initmodifiers(&modifiers);
	ft_parse(&io, &modifiers);
	return (io.nprinted);
}

int main(void)
{
	ft_printf("these are three ints %i %i %i\n", 3, 97, -348);
}