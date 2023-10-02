/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:23:22 by ting              #+#    #+#             */
/*   Updated: 2023/10/02 21:13:50 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_prtchar(char c);
int	ft_prtstr(char *str);
int	ft_prtnbr(int nbr);
int	ft_prtunnbr(unsigned int nbr);
int	ft_prthexe(unsigned long n, char format);
int	ft_printf(const char *str, ...);
#endif
