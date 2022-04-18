/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:44 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/18 20:42:21 by hoomen           ###   ########.fr       */
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
		modifiers->altform = 2;
	if (modifiers->conspec == 'x' || modifiers->conspec == 'X' 
		|| modifiers->conspec == 'p')
		modifiers->base = 16;
	if (modifiers->precision && modifiers->conspec != 'c' 
		&& modifiers->conspec != 's')
		modifiers->zeropad = 0;
}

void	ft_convert(t_io *io, t_mod *modifiers);
{
	unsigned long int	nbr;

	modifiers->conspec = io->format[io->position];
	ft_adjustmods(modifiers);
	if (modifiers->conspec == 'c')
		ft_putcharpf(io, modifiers);
	else if (modifiers->conspec == 's')
		ft_putstrpf(io, modifiers);
	else if (modifiers->conspec == 'i' || modifiers->conspec == 'd')
		ft_putintpf(io, modifiers);
	else
		ft_putnbrpf(io, modifiers, nbr);

}
