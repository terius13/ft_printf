/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:22:58 by ting              #+#    #+#             */
/*   Updated: 2023/10/02 18:25:51 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list list, char format)
{
	if (format == 'c')
		return (ft_prtchar(va_arg(list, int)));
	if (format == 's')
		return (ft_prtstr(va_arg(list, char *)));
	if (format == 'd' || format == 'i')
		return (ft_prtnbr(va_arg(list, int)));
	if (format == 'u')
		return (ft_prtunnbr(va_arg(list, unsigned int)));
	if (format == 'X' || format == 'x' || format == 'p')
		return (ft_prthexe(va_arg(list, unsigned long long), format));
	if (format == '%')
		return (ft_prtchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_checker(list, str[i]);
		}
		else
			count += ft_prtchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "world";

	int	count = ft_printf("hel%%lo %d\n", 123);
	ft_printf("%d", count);

}
*/
