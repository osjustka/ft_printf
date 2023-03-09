/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:55:02 by marvin            #+#    #+#             */
/*   Updated: 2023/03/08 10:55:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_puthex_pf(unsigned int num, size_t *ch_printed, char *base)
{
    char *str;

    str = ft_transition_pf(num, base);
    ft_putstr_pf(str, ch_printed);
    free(str);
}