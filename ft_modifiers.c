/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:05:05 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:53:17 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_width(t_io *io, t_mod *modifiers)
{
	if (io->format[io->position] == '*')
		modifiers->width = va_arg(io->ap, int);
	else if (io->position == 0 || !ft_isdigit(io->format[io->position - 1]))
		modifiers->width = io->format[io->position] - '0';
	else
		modifiers->width = (modifiers->width * 10) + (io->format[io->position] - '0');
}

static void	ft_precision(t_io *io, t_mod *modifiers)
{
	if (io->format[io->position] == '*')
	{
		modifiers->width = va_arg(io->ap, int);
		modifiers->adj_precision = 0;
		return ;
	}
	else if (!ft_isdigit(io->format[io->position - 1]))
		modifiers->width = io->format[io->position] - '0';
	else
		modifiers->width = (modifiers->width * 10) + (io->format[io->position] - '0');
	if (!ft_isdigit(io->format[io->position + 1]))
		modifiers->adj_precision = 0;
}

void	ft_modifiers(t_io *io, t_mod *modifiers)
{
	if (ft_isdigit(io->format[io->position]) && !modifiers->adj_precision)
		ft_width(io, modifiers);
	else if (ft_isdigit(io->format[io->position]))
		ft_precision(io, modifiers);
	else if (io->format[io->position] == '*' && !modifiers->adj_precision)
		ft_width(io, modifiers);
	else if (io->format[io->position])
		ft_precision(io, modifiers);
	else if (io->format[io->position] == '+')
		modifiers->plus = 1;
	else if (io->format[io->position] == '-')
		modifiers->leftadj = 1;
	else if (io->format[io->position] == ' ')
		modifiers->space = 1;
	else if (io->format[io->position] == '#')
		modifiers->altform = 1;
	else if (io->format[io->position] == '.')
	{
		modifiers->precision = 0;
		modifiers->adj_precision = 1;
	}
}