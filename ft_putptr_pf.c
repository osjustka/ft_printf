/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:23:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 21:23:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *ptr, size_t *ch_printed)
{
    char    *s;
    unsigned long   ptr_addrs;
    
    ptr_addrs = (unsigned long)ptr; 
    s = ft_transition_pf(ptr_addrs, HEX_LOWER_BASE);
    ft_putstr_pf(s, ch_printed);
    free(s);
}