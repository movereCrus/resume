/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:57:50 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 01:21:24 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_pa_pb_extension(int pa, int pb, int x, char **res)
{
	if (pa > pb)
	{
		x = pa - pb;
		while (x-- > 0)
			*res = add_operation(*res, "pa\n");
	}
	else
	{
		x = pb - pa;
		while (x-- > 0)
			*res = add_operation(*res, "pb\n");
	}
}

int	add_pa_pb(char **origin, char **res, int i)
{
	int		pa;
	int		pb;
	int		x;

	pa = 0;
	pb = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "pa")
			|| ft_strequ(origin[i], "pb")))
	{
		if (ft_strequ(origin[i], "pa"))
			pa++;
		if (ft_strequ(origin[i], "pb"))
			pb++;
		i++;
	}
	add_pa_pb_extension(pa, pb, x, res);
	return (i);
}

static void	free_memory(char **tmp, char **origin, char **res)
{
	int		i;

	i = 0;
	if (!tmp || !(*origin) || !(*res))
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	free(*origin);
	origin = NULL;
	free (*res);
	res = NULL;
}

static void	print_final_result_extension(char **tmp, char **res, int i)
{
	while (tmp[i])
	{
		if (tmp[i] && (ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")))
			i = add_pa_pb(tmp, res, i);
		if (tmp[i] && (ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb")))
			i = add_rr(tmp, res, i);
		if (tmp[i] && (ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
			i = add_rrr(tmp, res, i);
		if (tmp[i] && !(ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")
				|| ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb")
				|| ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
			i = add_others(tmp, res, i);
	}
}

void	print_final_result(char *origin)
{
	char	**tmp;
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("\0");
	tmp = ft_split(origin, '\n');
	if (!tmp || !res || !origin)
	{
		free_memory(tmp, &origin, &res);
		return ;
	}
	print_final_result_extension(tmp, &res, i);
	ft_printf("%s", res);
	free_memory(tmp, &origin, &res);
}
