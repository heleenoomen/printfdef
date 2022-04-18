/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:39:33 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/18 19:45:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pad(t_io *io, t_mod *modifiers)
{
	char	c;
	
	if (modifiers->zeropad && !modifiers->leftadj)
		c = '0'
	else
		c = ' '
	while (modifiers->pads)
	{
		nprinted = write(1, &c, 1);
		modifiers->pads--;
	}
}