/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:22:22 by ting              #+#    #+#             */
/*   Updated: 2023/10/02 17:10:41 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_prtchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_prtstr(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += ft_prtchar(*str);
		str++;
	}
	return (count);
}

int	ft_prtnbr(int nbr)
{
	long int	n;
	int			count;

	count = 0;
	n = nbr;
	if (n < 0)
	{
		ft_prtchar('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_prtnbr(n / 10);
	}
	n = n % 10 + '0';
	count += ft_prtchar(n);
	return (count);
}

int	ft_prtunnbr(unsigned int nbr)
{
	unsigned int	n;
	int				count;

	count = 0;
	n = nbr;
	if (n > 9)
	{
		count += ft_prtunnbr(n / 10);
	}
	n = n % 10 + '0';
	count += ft_prtchar(n);
	return (count);
}

int	ft_prthexe(unsigned long long n, char format)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'p')
		if (n == 0)
			count += ft_prtstr("(nil)");
	if (n > 15)
		count += ft_prthexe(n / 16, format);
	n = n % 16;
	if (count == 0)
		count += ft_prtstr("0x");
	count += ft_prtchar(base[n]);
	return (count);
}
/*
int	ft_prthex(unsigned long long n, char format)
{
	int	count;
	char	*base;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'x')
		base = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_prthex(n / 16, format);
	}
	n = n % 16;
	count += ft_prtchar(base[n]);
	return (count);
}

int	ft_prtaddress(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += ft_prtstr("(nil)");
	else
	{
		count += ft_prtstr("0x");
		count += ft_prthex(n, 'x');
	}
	return (count);
}
*/
/*
#include <stdio.h>
int	main(void)
{
	int	c = 'H';
	char	*str = "hello";
	int	nbr = -123;
	unsigned int num = 1234567899;
	int	hex = 15;

	printf("character: %d\n", ft_prtchar(c));
	ft_prtchar(c);
	ft_prtchar('\n');
	ft_prtstr(str);
	ft_prtchar('\n');
	ft_prtnbr(nbr);
	ft_prtchar('\n');
	ft_prtunnbr(num);
	ft_prtchar('\n');
	printf("%d", ft_prtunnbr(num));
	ft_prtchar('\n');
	ft_prthex(hex, 'X');
	ft_prtchar('\n');
	ft_prtaddress(1011);
	ft_prthexe(1011, 'p');
	ft_prtchar('\n');
	printf("%d", ft_prthexe(1011, 'p'));
}
*/
