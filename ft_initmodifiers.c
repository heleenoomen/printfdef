/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmodifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:56:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 14:48:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_initmodifiers(t_mod *modifiers)
{
	modifiers->altform = 0;
	modifiers->zeropad = 0;
	modifiers->leftadj = 0;
	modifiers->space = 0;
	modifiers->plus = 0;
	modifiers->width = 0;
	modifiers->precision = -1;
	modifiers->adj_precision = 0;
	modifiers->conspec = 0;
	modifiers->base = 0;
	modifiers->putminus = 0;
	modifiers->pads = 0;
}