/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:23:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:58:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_numlen(t_mod *modifiers, long unsigned int nbr)
{
	int	numlen;

	numlen = 1;
	while (nbr / modifiers->base > 0)
	{
		numlen++;
		nbr = nbr / modifiers->base;
	}
	if (modifiers->putminus || modifiers->plus || modifiers->space)
		numlen++;
	if (modifiers->altform)
		numlen = numlen + 2;
	return (numlen);
}

static void	ft_putprefix(t_io *io, t_mod *modifiers)
{
	if (modifiers->putminus)
		io->nprinted += write(1, "-", 1);
	else if (modifiers->plus)
		io->nprinted += write(1, "+", 1);
	else if (modifiers->space)
		io->nprinted += write(1, " ", 1);
	else if (modifiers->altform && modifiers->conspec == 'X')
		io->nprinted += write(1, "0X", 2);
	else if (modifiers->altform)
		io->nprinted += write(1, "0x", 2);
}

static void	ft_putpreczeros(t_io *io, t_mod *modifiers, int len)
{
	int	preczeros;

	if (modifiers->precision > len)
	{
		preczeros = modifiers->precision - len;
		while (preczeros)
		{
			io->nprinted += write(1, "0", 1);
			preczeros--;
		}
	}
}

void	ft_printnbr(t_io *io, t_mod *modifiers, unsigned long int nbr)
{
	int	len;

	len = ft_numlen(modifiers, nbr);
	modifiers->pads = modifiers->width - len - modifiers->precision;
	if (modifiers->zeropad)
		ft_putprefix(io, modifiers);
	if (!modifiers->leftadj && modifiers->pads)
		ft_pad(io, modifiers);
	if (!modifiers->zeropad)
		ft_putprefix(io, modifiers);
	ft_putpreczeros(io, modifiers, len);
	ft_putnbrpf(io, modifiers, nbr);
	if (modifiers->pads && modifiers->leftadj)
		ft_pad(io, modifiers);
}
