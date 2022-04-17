/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:59:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/17 18:04:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static const CONSPECS = "cspdiouxX%%"

void	ft_parseconv(t_io *io, t_mod *modifiers)
{
	if (!ft_strchr(io->format[io->position], CONSPECS)
		ft_modifiers(io, modifiers);
	else
		ft_conspecs(io, modifiers);
}