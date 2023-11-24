/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:48:13 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 19:57:28 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_rr_extension(int ra, int rb, int rr, char **res)
{
	if (ra >= rb)
	{
		ra = ra - rb;
		rr = rb;
		while (ra-- > 0)
			*res = add_operation(*res, "ra\n");
	}
	else
	{
		rb = rb - ra;
		rr = ra;
		while (rb-- > 0)
			*res = add_operation(*res, "rb\n");
	}
	while (rr-- > 0)
		*res = add_operation(*res, "rr\n");
}

int	add_rr(char **origin, char **res, int i)
{
	int	ra;
	int	rb;
	int	rr;

	ra = 0;
	rb = 0;
	rr = 0;
	while (origin[i] && (ft_strequ(origin[i], "ra")
			|| ft_strequ(origin[i], "rb")))
	{
		if (ft_strequ(origin[i], "ra"))
			ra++;
		if (ft_strequ(origin[i], "rb"))
			rb++;
		i++;
	}
	add_rr_extension(ra, rb, rr, res);
	return (i);
}

static void	add_rrr_extension(int rra, int rrb, int rrr, char **res)
{
	if (rra >= rrb)
	{
		rra = rra - rrb;
		rrr = rrb;
		while (rra-- > 0)
			*res = add_operation(*res, "rra\n");
	}
	else
	{
		rrb = rrb - rra;
		rrr = rra;
		while (rrb-- > 0)
			*res = add_operation(*res, "rrb\n");
	}
	while (rrr-- > 0)
		*res = add_operation(*res, "rrr\n");
}

int	add_rrr(char **origin, char **res, int i)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = 0;
	rrb = 0;
	rrr = 0;
	while (origin[i] && (ft_strequ(origin[i], "rra")
			|| ft_strequ(origin[i], "rrb")))
	{
		if (ft_strequ(origin[i], "rra"))
			rra++;
		if (ft_strequ(origin[i], "rrb"))
			rrb++;
		i++;
	}
	add_rrr_extension(rra, rrb, rrr, res);
	return (i);
}

int	add_others(char **tmp, char **res, int i)
{
	while (tmp[i] && !(ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb")
			|| ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb")
			|| ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
	{
		*res = add_operation(*res, tmp[i]);
		*res = add_operation(*res, "\n");
		i++;
	}
	return (i);
}
