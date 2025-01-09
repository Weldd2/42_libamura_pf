/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:37:48 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/09 23:36:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_putstring(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (count);
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int	pf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	pf_putnbr(int i)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	if (i == -2147483648)
	{
		pf_putstring("-2147483648");
		return (11);
	}
	if (i < 0)
	{
		count += pf_putchar('-');
		i *= -1;
	}
	temp = i % 10;
	if (i >= 10)
	{
		count += pf_putnbr(i / 10);
	}
	count += pf_putchar(temp + '0');
	return (count);
}

int	pf_putunsignednbr(unsigned int i)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	temp = i % 10;
	if (i >= 10)
	{
		count += pf_putnbr(i / 10);
	}
	count += pf_putchar(temp + '0');
	return (count);
}

int	pf_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		count += pf_putnbr_base(nbr / base_len, base);
		count += pf_putnbr_base(nbr % base_len, base);
	}
	else
		count += pf_putchar(base[nbr]);
	return (count);
}
