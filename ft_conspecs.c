/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conspecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:05:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/17 18:10:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_modifiers(t_io *io, t_mod *modifiers)
{
	if (io->format[io->position] == 'c')
		modifiers->conspec = 'c';
	else if (io->format[io->position] == 's')
		modifiers->conspec = 's';
	else if (io->format[io->position] == 'd')
		modifiers->conspec = 'd';
	else if (io->format[io->position] == 'i')
		modifiers->conspec = 'i';
	else if (io->format[io->position] == 'u')
		modifiers->conspec = 'u';
	else if (io->format[io->position] == 'x')
		modifiers->conspec = 'x';
	else if (io->format[io->position] == 'X')
		modifiers->conspec = 'X';
	else if (io->format[io->position] == 'p')
		modifiers->conspec = 'p';
}
