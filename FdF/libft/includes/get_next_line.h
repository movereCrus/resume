/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:30:37 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/26 15:16:15 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 50000

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fdbuf
{
	char	buf[BUFFER_SIZE];
	size_t	ind;
}	t_fdbuf;

typedef struct s_var
{
	char	*str;
	size_t	i;
}	t_var;

char	*ft_strjoin_n(char const *s1, char const *s2, size_t len);
char	*get_next_line(int fd, char **line);

#endif
