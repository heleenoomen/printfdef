/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:23:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 17:05:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_numlen(t_mod *mods, long unsigned int nbr)
{
	int	numlen;

	numlen = 1;
	while (nbr / mods->base > 0)
	{
		numlen++;
		nbr = nbr / mods->base;
	}
	return (numlen);
}

static int	ft_preflen(t_mod *mods)
{
	int	preflen;

	if (mods->putminus || mods->plus || mods->space)
		preflen = 1;
	if (mods->altform)
		preflen = 2;
	return (preflen);
}

static void	ft_putprefix(t_io *io, t_mod *mods)
{
	if (mods->putminus)
		io->nprinted += write(1, "-", 1);
	else if (mods->plus)
		io->nprinted += write(1, "+", 1);
	else if (mods->space)
		io->nprinted += write(1, " ", 1);
	else if (mods->altform && mods->conspec == 'X')
		io->nprinted += write(1, "0X", 2);
	else if (mods->altform)
		io->nprinted += write(1, "0x", 2);
}

static void	ft_putpreczeros(t_io *io, t_mod *mods, int len)
{
	int	preczeros;

	if (mods->precision > len)
	{
		preczeros = mods->precision - len;
		while (preczeros)
		{
			io->nprinted += write(1, "0", 1);
			preczeros--;
		}
	}
}

void	ft_printnbr(t_io *io, t_mod *mods, unsigned long int nbr)
{
	int	numlen;
	int	preflen;
	int	preczeros;

	numlen = ft_numlen(mods, nbr);
	preflen = ft_preflen(mods);
	preczeros = 0;
	if (mods->precision > numlen)
		preczeros = mods->precision - numlen;
	if (mods->width > numlen + preczeros + preflen)
		mods->pads = mods->width - numlen - preczeros - preflen;
	if (mods->zeropad)
		ft_putprefix(io, mods);
	if (!mods->leftadj && mods->pads)
		ft_pad(io, mods);
	if (!mods->zeropad)
		ft_putprefix(io, mods);
	ft_putpreczeros(io, mods, numlen);
	ft_putnbrpf(io, mods, nbr);
	if (mods->pads && mods->leftadj)
		ft_pad(io, mods);
}
