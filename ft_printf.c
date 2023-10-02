/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:22:58 by ting              #+#    #+#             */
/*   Updated: 2023/10/02 18:06:05 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_checker(va_list list, char format)
{
	if (format == 'c')
		ft_prtchar(va_arg(list, int));
	else if (format == 's')
		ft_prtstr(va_arg(list, char *));
	else if (format == 'd' || format == 'i')
		ft_prtnbr(va_arg(list, int));
	else if (format == 'u')
		ft_prtunnbr(va_arg(list, unsigned int));
	else if (format == 'X' || format == 'x' || format == 'p')
		ft_prthexe(va_arg(list, unsigned long long), format);
	else if (format == '%')
		ft_prtchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int	i;
	int	count;

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
