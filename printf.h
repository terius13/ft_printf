/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:23:22 by ting              #+#    #+#             */
/*   Updated: 2023/10/02 17:11:07 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>


int	ft_prtchar(char c);
int	ft_prtstr(char *str);
int	ft_prtnbr(int nbr);
int	ft_prtunnbr(unsigned int nbr);
int     ft_prthexe(unsigned long long n, char format);

#endif
