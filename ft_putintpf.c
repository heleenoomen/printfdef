/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:59:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/18 20:08:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putintpf(t_io *io, t_mod *modifiers)
{
	int	nbr;

	nbr = va_arg(io->ap, int);
	if (nbr < 0)
	{
		modifiers->putminus = 1;
		nbr = nbr * -1;
	}
	ft_putnbrpf(io, modifiers, (unsigned long int) nbr);
}
