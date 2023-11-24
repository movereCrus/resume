/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:29:53 by dwarlock          #+#    #+#             */
/*   Updated: 2021/12/28 14:26:42 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ifeol(t_fdbuf *thrd, t_var v, int fd)
{
	char	*tmp;

	if (!v.str)
		v.str = "\0";
	tmp = v.str;
	v.str = ft_strjoin_n(v.str, &thrd->buf[fd][thrd->ind[fd]], v.i);
	if (*tmp)
		free(tmp);
	if (thrd->buf[fd][v.i + 1])
		thrd->ind[fd] = v.i + 1;
	else
	{
		thrd->ind[fd] = 0;
		*(thrd->buf[fd]) = 0;
	}
	return (v.str);
}

static ssize_t	ifeof(t_fdbuf *thrd, t_var *v, int fd)
{
	ssize_t	readres;
	char	*tmp;

	if (v->i)
	{
		if (!v->str)
			v->str = "\0";
		tmp = v->str;
		v->str = ft_strjoin(v->str, &thrd->buf[fd][thrd->ind[fd]]);
		if (*tmp)
			free(tmp);
	}
	*(thrd->buf[fd]) = 0;
	readres = read(fd, thrd->buf[fd], BUFFER_SIZE);
	thrd->buf[fd][readres] = '\0';
	thrd->ind[fd] = 0;
	return (readres);
}

static size_t	bytecalc(int fd, size_t i, t_fdbuf *thrd)
{
	i = thrd->ind[fd];
	while (thrd->buf[fd][i] != '\n' && thrd->buf[fd][i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static t_fdbuf	thrd;
	t_var			var;
	ssize_t			readres;

	var.str = NULL;
	while (fd >= 0 && fd <= OPEN_MAX)
	{
		var.i = bytecalc(fd, var.i, &thrd);
		if (thrd.buf[fd][var.i] == '\n')
		{
			var.str = ifeol(&thrd, var, fd);
			if (!var.str)
				return (NULL);
			fd = -1;
		}
		else
		{
			readres = ifeof(&thrd, &var, fd);
			if (readres <= 0)
				fd = -1;
		}
	}
	return (var.str);
}
