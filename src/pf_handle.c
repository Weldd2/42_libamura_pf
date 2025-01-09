/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:38:37 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/09 23:36:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_handle_d_i(va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	return (pf_putnbr(d));
}

int	pf_handle_u(va_list *ap)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	return (pf_putunsignednbr(u));
}

int	pf_handle_c(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	return (pf_putchar(c));
}

int	pf_handle_s(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		return (pf_putstring("(null)"));
	return (pf_putstring(s));
}

int	pf_handle_p(va_list *ap)
{
	void	*p;

	p = va_arg(*ap, void *);
	if (p == NULL)
		return (pf_putstring("0x0"));
	return (pf_printaddr(p));
}
