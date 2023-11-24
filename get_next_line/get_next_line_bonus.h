/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:30:44 by dwarlock          #+#    #+#             */
/*   Updated: 2021/12/28 14:25:45 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 128

typedef struct s_fdbuf
{
	char	buf[OPEN_MAX + 1][BUFFER_SIZE];
	size_t	ind[OPEN_MAX + 1];
}	t_fdbuf;

typedef struct s_var
{
	char	*str;
	size_t	i;
}	t_var;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_n(char const *s1, char const *s2, size_t len);
char	*get_next_line(int fd);
#endif
