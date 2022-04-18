/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:46:25 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/18 19:59:24 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstrpf(t_io *io, t_mod *modifiers)
{
	size_t	len;
	char	*s
	size_t	i;

	s = va_arg(io->ap, char *);
	len = ft_strlen(s);
	if (modifiers->precision >= 0)
		len = (size_t) modifiers->precision;
	if (len < (size_t) modifiers->width)
		modifiers->pads = modifiers->width - (int) len;
	if (!modifiers->leftadj && modifiers->pads)
		ft_pad(io, modifiers);
	i = 0;
	while (i < len)
	{
		nprinted = write(1, s + i, 1);
		i++;
	}
	if (modifiers->leftadj && modifiers->pads)
		ft_pad(io, modifiers);
}
