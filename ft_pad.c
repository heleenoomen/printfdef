/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:39:33 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:56:18 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_pad(t_io *io, t_mod *modifiers)
{
	char	c;
	
	if (modifiers->zeropad && !modifiers->leftadj)
		c = '0';
	else
		c = ' ';
	while (modifiers->pads)
	{
		io->nprinted += write(1, &c, 1);
		modifiers->pads--;
	}
}
