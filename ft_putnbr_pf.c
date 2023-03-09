/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:05:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 19:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *ch_printed)
{
	unsigned int	m;

	m = (unsigned int)(n);
	if (n < 0)
	{
		ft_putchar_pf('-', ch_printed);
		m *= -1;
	}
	if (m >= 10)
	{
		ft_putnbr_pf(m / 10, ch_printed);
		ft_putnbr_pf(m % 10, ch_printed);
	}
	else
		ft_putchar_pf('0' + m, ch_printed);
}