/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:26:09 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/09 23:37:28 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_putnbr_base_2(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		count += pf_putnbr_base_2(nbr / base_len, base);
		count += pf_putnbr_base_2(nbr % base_len, base);
	}
	else
		count += pf_putchar(base[nbr]);
	return (count);
}

int	pf_printaddr(void *addr)
{
	pf_putchar('0');
	pf_putchar('x');
	return (2 + pf_putnbr_base((long)addr, "0123456789abcdef"));
}

int	pf_handle_x(va_list *ap)
{
	int	s;

	s = va_arg(*ap, int);
	return (pf_putnbr_base_2(s, "0123456789abcdef"));
}
