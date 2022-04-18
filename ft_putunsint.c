/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:23:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/18 20:53:52 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen(t_mod *modifiers, long unsigned int nbr)
{
	int	numlen;

	numlen = 1;
	while (nbr / modifiers->base > 0)
	{
		numlen++;
		nbr = nbr / modifiers->base;
	}
	if (modifiers->putminus || modifiers->plus || modifiers->space)
		numlen++;
	if (modifiers->altform)
		numlen = numlen + 2;
	return (numlen);
}


void	ft_putunsint(t_io *io, t_mod *modifiers, unsigned long int nbr)
{
	int	len;

	modifiers->pads = modifiers->width - ft_numlen(nbr) - ;
	if (modifiers->zeros && !modifiers->leftadj)
		ft_putprefix(io, modifiers);
	if (!modifiers->leftadj && modifiers->pads)
		ft_putpads(io, modifiers);
	if (!modifiers->zeros || modifiers->leftadj)
		ft_putprefix(io, modifiers);
	ft_putpreczeros(io, mod, len);
	ft_putnbrpf(io, mod, nbr);
	if (modifiers->pads && modifiers->leftadj)
		ft_putpads(io, modifiers);
}