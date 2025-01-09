/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:25:40 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/09 23:36:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_handle_x_upper(va_list *ap)
{
	int	s;

	s = va_arg(*ap, int);
	return (pf_putnbr_base_2(s, "0123456789ABCDEF"));
}

int	pf_handle_percent(va_list *args)
{
	(void)args;
	return (pf_putchar('%'));
}

void	pf_initialize_handlers(int (*handlers[256])(va_list *))
{
	handlers['d'] = pf_handle_d_i;
	handlers['i'] = pf_handle_d_i;
	handlers['c'] = pf_handle_c;
	handlers['s'] = pf_handle_s;
	handlers['u'] = pf_handle_u;
	handlers['p'] = pf_handle_p;
	handlers['x'] = pf_handle_x;
	handlers['X'] = pf_handle_x_upper;
	handlers['%'] = pf_handle_percent;
}

int	pf_printf(const char *fmt, ...)
{
	va_list	ap;
	int		(*handlers[256])(va_list *);
	int		count;

	count = 0;
	va_start(ap, fmt);
	pf_initialize_handlers(handlers);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (handlers[(int)*fmt])
				count += handlers[(int)*fmt](&ap);
		}
		else
			count += pf_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}
