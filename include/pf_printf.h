/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:39:18 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/09 23:36:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		pf_putchar(char c);
int		pf_putnbr(int i);
int		pf_putnbr_base_2(unsigned int nbr, char *base);
int		pf_putnbr_base(unsigned long nbr, char *base);
int		pf_printaddr(void *addr);
int		pf_putstring(char *s);
int		pf_handle_x(va_list *ap);
int		pf_handle_p(va_list *ap);
int		pf_handle_s(va_list *ap);
int		pf_handle_c(va_list *ap);
int		pf_handle_d_i(va_list *ap);
int		pf_handle_u(va_list *ap);
int		pf_handle_x_upper(va_list *ap);
int		pf_handle_percent(va_list *args);
int		pf_putunsignednbr(unsigned int i);
void	pf_initialize_handlers(int (*handlers[256])(va_list *));
int		pf_printf(const char *fmt, ...);

#endif