/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:44 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:42:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void ft_adjustmods(t_mod *modifiers)
{
	if (modifiers->conspec ==  'i' || modifiers->conspec == 'd' 
		|| modifiers->conspec == 'u')
	{
		modifiers->altform = 0;
		modifiers->base = 10;
	}
	if (modifiers->conspec == 'u' || modifiers->conspec == 'x' || 
		modifiers->conspec == 'X' || modifiers->conspec == 'p')
	{
		modifiers->plus = 0;
		modifiers->space = 0;
	}
	if (modifiers->conspec == 'p')
		modifiers->altform = 1;
	if (modifiers->conspec == 'x' || modifiers->conspec == 'X' 
		|| modifiers->conspec == 'p')
		modifiers->base = 16;
	if (modifiers->precision && modifiers->conspec != 'c' 
		&& modifiers->conspec != 's' && modifiers->conspec != '%')
		modifiers->zeropad = 0;
}

void	ft_convert(t_io *io, t_mod *modifiers)
{
	unsigned long int	nbr;

	modifiers->conspec = io->format[io->position];
	ft_adjustmods(modifiers);
	if (modifiers->conspec == 'c' || modifiers->conspec == '%')
		ft_printchar(io, modifiers);
	else if (modifiers->conspec == 's')
		ft_printstr(io, modifiers);
	else if (modifiers->conspec == 'i' || modifiers->conspec == 'd')
		ft_printint(io, modifiers);
	else
	{
		nbr = va_arg(io->ap, unsigned long int);
		ft_printnbr(io, modifiers, nbr);
	}

}
