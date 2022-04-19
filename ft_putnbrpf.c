/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:01 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 15:00:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static char	ft_choosechar(t_mod *modifiers, unsigned long int nbr)
{
	char	c;

	if (nbr < 10)
		c = nbr + '0';
	else if (modifiers->conspec == 'X')
		c = nbr - 10 + 'A';
	else
		c = nbr - 10 + 'a';
	return (c);
}

void ft_putnbrpf(t_io *io, t_mod *modifiers, unsigned long int nbr)
{
	char c;

	if (nbr < (unsigned long int) modifiers->base)
	{
		c = ft_choosechar(modifiers, nbr);
		io->nprinted += write(1, &c, 1);
		return ;
	}
	ft_putnbrpf(io, modifiers, nbr / modifiers->base);
	c = ft_choosechar(modifiers, nbr % modifiers->base);
	io->nprinted += write(1, &c, 1);
}
