/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:42:45 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 21:42:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen_pf(const char *s)
{
    size_t	len;
	char	*base;

	len = 0;
	base = (char *)(s);
	while (*base++ != '\0')
	{
		len++;
	}
	return (len); 
}

static size_t ft_numlen_pf(unsigned long long n, char *base)
{
    size_t len;
    unsigned long long  b_lenght;

    len = 1;
    b_lenght = ft_strlen_pf(base);
    while (n >= b_lenght)
        {
            n = n / b_lenght;
            len++;
        }
    return(len);
}

static void    ft_bzero_pf(void *s, size_t n)
{
    unsigned char   *clean;
    size_t  i;
    
    clean = (unsigned char *)(s);
    i = 0;
    while (i < n)
        {
            clean[i] = '\0';
            i++;
        }
}

void    *ft_calloc_pf(size_t n, size_t size)
{
    void    *str;

    str =(char *) malloc (n * size);
    if (str == NULL)
        return (NULL);
    ft_bzero_pf(str, n * size);
    return (str);
}

char	*ft_transition_pf(unsigned long long n, char *base)
{
	char	*str;
	int		n_lenght;
	int		b_lenght;

	n_lenght = ft_numlen_pf(n, base);
	b_lenght = ft_strlen_pf(base);
	str = ft_calloc_pf((n_lenght + 1), sizeof(char));
	if (*str == '\0')
		return (NULL);
	while (n_lenght != '\0')
	{
		n_lenght = n_lenght - 1;
		str[n_lenght] = base[n % b_lenght];
		n = n / b_lenght;
	}
	return (str);
}