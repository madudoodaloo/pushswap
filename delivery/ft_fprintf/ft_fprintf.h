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

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# define S_HEX "0123456789abcdef"
# define B_HEX "0123456789ABCDEF"

# include <unistd.h> // write
# include <stdlib.h> // malloc
# include <stdarg.h> // va_
# include <stdio.h>  // printf
# include <limits.h> // macros
# include "../libft/libft.h"

/* -R CheckForbiddenSourceHeader */

void	fpf_convert(int fd, char c, va_list args);
int		ft_fprintf(int fd, const char *str, ...);

/* utils_char.c */
int		fpf_count(int printed);
void	fpf_putchar(int fd, char c);
void	fpf_putstr(int fd, char *str);

/* utils_int.c */
void	fpf_putnbr(int fd, int n);
void	fpf_putunsigned(int fd, unsigned int nbr);
void	fpf_puthex(int fd, unsigned long int nbr, int c);
void	fpf_putptr(int fd, unsigned long int nbr);

#endif