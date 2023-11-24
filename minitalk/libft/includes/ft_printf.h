/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:33:47 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 19:56:31 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

size_t		ft_putstr(char *s);
size_t		checkfmt(char *str, int c);
size_t		putnbr_p(size_t nb, char *l);
size_t		putnbr_d(long nb, char *l);
size_t		putnbr_uhex(unsigned int nb, char *l, int base);
int			ft_printf(const char *s, ...);

#endif