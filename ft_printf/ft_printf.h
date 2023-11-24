/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:13:47 by dwarlock          #+#    #+#             */
/*   Updated: 2022/01/03 18:13:56 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		checkfmt(char *str, int c);
int		putnbr_p(size_t nb, char *l);
int		putnbr_d(int nb, char *l);
int		putnbr_uhex(unsigned int nb, char *l, int base);
int		ft_printf(const char *s, ...);

#endif