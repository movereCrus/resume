/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:31:15 by dwarlock          #+#    #+#             */
/*   Updated: 2022/05/31 19:56:17 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ifeol(t_fdbuf *thrd, t_var v)
{
	char	*tmp;

	if (!v.str)
	{
		v.str = "\0";
	}
	tmp = v.str;
	v.str = ft_strjoin_n(v.str, &thrd->buf[thrd->ind], v.i);
	if (*tmp)
		free(tmp);
	if (thrd->buf[v.i + 1])
		thrd->ind = v.i + 1;
	else
	{
		thrd->ind = 0;
		*(thrd->buf) = 0;
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
		v->str = ft_strjoin(v->str, &thrd->buf[thrd->ind]);
		if (*tmp)
			free(tmp);
	}
	*(thrd->buf) = 0;
	readres = read(fd, thrd->buf, BUFFER_SIZE);
	thrd->buf[readres] = '\0';
	thrd->ind = 0;
	return (readres);
}

static size_t	bytecalc(size_t i, t_fdbuf *thrd)
{
	i = thrd->ind;
	while (thrd->buf[i] != '\n' && thrd->buf[i])
		i++;
	return (i);
}

char	*get_next_line(int fd, char **line)
{
	static t_fdbuf	thrd;
	t_var			var;
	ssize_t			readres;

	var.str = NULL;
	while (fd >= 0)
	{
		var.i = bytecalc(var.i, &thrd);
		if (thrd.buf[var.i] == '\n')
		{
			var.str = ifeol(&thrd, var);
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
	*line = var.str;
	return (*line);
}
