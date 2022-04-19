/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:46:25 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/19 17:20:16 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printstr(t_io *io, t_mod *mods)
{
	size_t	len;
	char	*s;
	size_t	i;

	s = va_arg(io->ap, char *);
	if (s == NULL)
		s = "(null)";
	if (mods->precision >= 0)
		len = (size_t) mods->precision;
	else
		len = ft_strlen(s);
	if (len < (size_t) mods->width)
		mods->pads = mods->width - (int) len;
	if (!mods->leftadj && mods->pads)
		ft_pad(io, mods);
	i = 0;
	while (i < len && s[i])
	{
		io->nprinted += write(1, s + i, 1);
		i++;
	}
	if (mods->leftadj && mods->pads)
		ft_pad(io, mods);
}
