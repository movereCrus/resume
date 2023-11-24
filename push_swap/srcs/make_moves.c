/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:54:45 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 23:55:12 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_rotation_extension(t_stack **a_head, int c, char **res)
{
	while (c != 0)
	{
		if (c < 0)
		{
			moveset_a(3, a_head, res);
			c++;
		}
		else
		{
			moveset_a(1, a_head, res);
			c--;
		}
	}
}

void	final_rotation(t_stack	**a_head, int min, char **res)
{
	t_stack	*a_ptr;
	int		c;
	int		a_len;

	a_len = ft_stack_size(*a_head);
	c = 0;
	a_ptr = *a_head;
	while (a_ptr->value != min)
	{
		c++;
		a_ptr = a_ptr->next;
	}
	if (c > a_len / 2)
	{
		c = a_len - c;
		c *= -1;
	}
	final_rotation_extension(a_head, c, res);
}

static void	make_moves_extension(t_stack **op, t_stack **a_head, char **res)
{
	while ((*op)->a_score != 0)
	{
		if ((*op)->a_score < 0)
		{
			moveset_a(3, a_head, res);
			((*op)->a_score)++;
		}
		else
		{
			moveset_a(1, a_head, res);
			((*op)->a_score)--;
		}
	}
}

void	make_moves(t_stack *op, t_stack **a_head, t_stack **b_head, char **res)
{
	make_moves_extension(&op, a_head, res);
	while (op->b_score != 0)
	{
		if (op->b_score < 0)
		{
			moveset_a(4, b_head, res);
			(op->b_score)++;
		}
		else
		{
			moveset_a(2, b_head, res);
			(op->b_score)--;
		}
	}
	moveset_b(5, a_head, b_head, res);
}
