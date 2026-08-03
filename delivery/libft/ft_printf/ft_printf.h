/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:27:33 by masilva-          #+#    #+#             */
/*   Updated: 2026/06/27 20:27:33 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define S_HEX "0123456789abcdef"
# define B_HEX "0123456789ABCDEF"

# include <unistd.h> // write
# include <stdlib.h> // malloc
# include <stdarg.h> // va_
# include <stdio.h>  // printf
# include <limits.h> // macros
# include "../libft.h"

/* -R CheckForbiddenSourceHeader */

void	ft_convert(char c, va_list args);
int		ft_printf(const char *str, ...);

/* utils_char.c */
int		ft_count(int printed);
void	pf_putchar(char c);
void	pf_putstr(char *str);

/* utils_int.c */
void	pf_putnbr(int n);
void	ft_putunsigned(unsigned int nbr);
void	ft_puthex(unsigned long int nbr, int c);
void	ft_putptr(unsigned long int nbr);

#endif